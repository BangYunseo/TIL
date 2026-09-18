"""문서 목록 페이지들을 git 이력에서 생성한다.

마크다운 안의 자리표시자를 만나면 그 자리에 목록을 끼워 넣는다.

  <!-- posts -->       홈: 전체 글 카드 목록 (페이지 나누기는 blog.js가 담당)
  <!-- categories -->  폴더별 문서 목록
  <!-- recent -->      최근 수정 문서 (blog.js가 우측 패널로 옮긴다)

작성일은 최초 커밋일, 수정일은 마지막 커밋일이다.
"""

import html
import re
import subprocess
from collections import defaultdict
from pathlib import Path
from urllib.parse import quote

LIMIT_RECENT = 5
EXCERPT_LEN = 50
SKIP_NAMES = {"README.md", "index.md"}
SKIP_TOP = {"site", ".venv", "venv", "hooks", "javascripts", "stylesheets", ".github", ".claude"}

FENCE = re.compile(r"^(```|~~~)")
# 목차용 블록인용(>)과 소제목(#)은 요약에서 제외한다. 본문만 남긴다.
NOISE = re.compile(r"^(<|\||!\[|---|===|\[!|:{3}|>|#)")
LINK = re.compile(r"\[([^\]]*)\]\([^)]*\)")
LEADING = re.compile(r"^[#>\-*+\s]+")

ICON_DATE = "M19,19H5V8H19M16,1V3H8V1H6V3H5C3.89,3 3,3.89 3,5V19A2,2 0 0,0 5,21H19A2,2 0 0,0 21,19V5C21,3.89 20.1,3 19,3H18V1"
ICON_CATEGORY = "M20,18H4V8H20M20,6H12L10,4H4C2.89,4 2,4.89 2,6V18A2,2 0 0,0 4,20H20A2,2 0 0,0 22,18V8C22,6.89 21.1,6 20,6Z"

_cache = {}


def _git_dates(root):
    """파일별 (최초 커밋일, 마지막 커밋일). git log 한 번으로 전부 수집.

    로그는 최신순이다. 첫 등장이 마지막 수정일, 마지막 등장이 작성일이다.
    폴더 이름을 바꾼 이력이 있는 문서는 그 시점이 작성일로 잡힌다.
    """
    out = subprocess.run(
        ["git", "-c", "core.quotepath=false", "log", "--name-only", "--no-merges",
         "--date=short", "--format=%x00%ad"],
        cwd=str(root), capture_output=True, text=True,
        encoding="utf-8", errors="replace",
    ).stdout
    created, modified, current = {}, {}, ""
    for line in out.splitlines():
        if line.startswith("\x00"):
            current = line[1:]
        elif line:
            created[line] = current
            modified.setdefault(line, current)
    return created, modified


def _clean(text):
    text = LINK.sub(r"\1", text)
    text = LEADING.sub("", text)
    return text.replace("**", "").replace("`", "").strip()


def _meta(path):
    """문서에서 제목(첫 h1)과 본문 앞부분 요약을 뽑는다."""
    try:
        lines = path.read_text(encoding="utf-8", errors="replace").splitlines()
    except OSError:
        return path.stem, ""

    title, start = path.stem, 0
    for index, raw in enumerate(lines):
        if raw.strip().startswith("# "):
            title, start = _clean(raw), index + 1
            break

    parts, in_fence, total = [], False, 0
    for raw in lines[start:]:
        line = raw.strip()
        if FENCE.match(line):
            in_fence = not in_fence
            continue
        if in_fence or not line or NOISE.match(line):
            continue
        cleaned = _clean(line)
        if not cleaned:
            continue
        parts.append(cleaned)
        total += len(cleaned) + 1
        if total > EXCERPT_LEN:
            break

    excerpt = " ".join(parts)
    if len(excerpt) > EXCERPT_LEN:
        excerpt = excerpt[:EXCERPT_LEN].rstrip() + "…"
    return title, excerpt


def _url(rel, directory_urls):
    """생 HTML은 MkDocs가 경로를 고쳐주지 않으므로 직접 최종 URL을 만든다."""
    base = rel[:-3] if rel.endswith(".md") else rel
    return quote(base + "/" if directory_urls else base + ".html")


def _collect(root, directory_urls):
    key = (str(root), directory_urls)
    if key in _cache:
        return _cache[key]

    created, modified = _git_dates(root)
    docs = []
    for path in root.rglob("*.md"):
        rel = path.relative_to(root).as_posix()
        parts = rel.split("/")
        if len(parts) < 2 or parts[0] in SKIP_TOP or path.name in SKIP_NAMES:
            continue
        title, excerpt = _meta(path)
        docs.append({
            "url": _url(rel, directory_urls),
            "title": title,
            "excerpt": excerpt,
            "created": created.get(rel, ""),
            "modified": modified.get(rel, ""),
            "folders": parts[:-1],
        })

    docs.sort(key=lambda doc: doc["created"], reverse=True)
    _cache[key] = docs
    return docs


def _icon(path_data):
    return (f'<svg class="post-card__icon" viewBox="0 0 24 24" aria-hidden="true">'
            f'<path d="{path_data}"/></svg>')


def _card(doc):
    excerpt = doc["excerpt"]
    return (
        f'<a class="post-card" href="{html.escape(doc["url"])}">'
        f'<h2 class="post-card__title">{html.escape(doc["title"])}</h2>'
        + (f'<p class="post-card__excerpt">{html.escape(excerpt)}</p>' if excerpt else "")
        + f'<div class="post-card__meta">'
        f'<span>{_icon(ICON_DATE)}{html.escape(doc["created"] or "-")}</span>'
        f'<span>{_icon(ICON_CATEGORY)}{html.escape(" · ".join(doc["folders"]))}</span>'
        f'</div></a>'
    )


def _render_posts(docs):
    if not docs:
        return "<p>아직 글이 없습니다.</p>"
    cards = "".join(_card(doc) for doc in docs)
    return (f'<div class="post-list" data-page-size="12">{cards}</div>'
            f'<nav class="post-pager" aria-label="페이지 이동"></nav>')


def _render_grouped(groups, heading_level="##"):
    """{그룹명: [문서]} 를 소제목 + 목록으로 펼친다."""
    out = []
    for name, items in groups:
        out.append(f'{heading_level} {name} <small>({len(items)})</small>')
        out.append("")
        for doc in items:
            date = doc["created"] or "-"
            out.append(f'- `{date}` [{doc["title"]}]({doc["url"]})')
        out.append("")
    return "\n".join(out) if out else "_문서가 없습니다._"


def _render_categories(docs):
    groups = defaultdict(list)
    for doc in docs:
        groups[" · ".join(doc["folders"])].append(doc)
    return _render_grouped(sorted(groups.items()))



def _render_recent(docs):
    latest = sorted(docs, key=lambda doc: doc["modified"], reverse=True)[:LIMIT_RECENT]
    items = "".join(
        f'<li><a href="{html.escape(doc["url"])}">{html.escape(doc["title"])}</a>'
        f'<span>{html.escape(doc["modified"] or "-")}</span></li>'
        for doc in latest
    )
    return (f'<template id="recent-panel"><section class="recent-panel">'
            f'<h3>최근 수정</h3><ul>{items}</ul></section></template>')


RENDERERS = {
    "<!-- posts -->": _render_posts,
    "<!-- categories -->": _render_categories,
    "<!-- recent -->": _render_recent,
}


def on_config(config):
    _cache.clear()
    return config


def on_page_markdown(markdown, page, config, files):
    if not any(marker in markdown for marker in RENDERERS):
        return markdown
    docs = _collect(Path(config.docs_dir).resolve(), config.use_directory_urls)
    for marker, render in RENDERERS.items():
        if marker in markdown:
            markdown = markdown.replace(marker, render(docs))
    return markdown
