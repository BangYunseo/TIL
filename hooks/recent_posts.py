"""홈 화면의 글 목록을 git 이력에서 생성한다.

index.md 안의 <!-- posts --> 자리에 카드 형태의 문서 목록을 끼워 넣는다.
날짜는 각 파일의 마지막 커밋 날짜다.
"""

import html
import re
import subprocess
from urllib.parse import quote
from pathlib import Path

MARKER = "<!-- posts -->"
LIMIT = 30
EXCERPT_LEN = 200
SKIP_NAMES = {"README.md", "index.md"}
SKIP_TOP = {"site", ".venv", "venv", "hooks", "javascripts", "stylesheets", ".github", ".claude"}

FENCE = re.compile(r"^(```|~~~)")
# 목차용 블록인용(>)과 소제목(#)은 요약에서 제외한다. 본문만 남긴다.
NOISE = re.compile(r"^(<|\||!\[|---|===|\[!|:{3}|>|#)")
LINK = re.compile(r"\[([^\]]*)\]\([^)]*\)")
LEADING = re.compile(r"^[#>\-*+\s]+")

ICON_DATE = "M19,19H5V8H19M16,1V3H8V1H6V3H5C3.89,3 3,3.89 3,5V19A2,2 0 0,0 5,21H19A2,2 0 0,0 21,19V5C21,3.89 20.1,3 19,3H18V1"
ICON_CATEGORY = "M20,18H4V8H20M20,6H12L10,4H4C2.89,4 2,4.89 2,6V18A2,2 0 0,0 4,20H20A2,2 0 0,0 22,18V8C22,6.89 21.1,6 20,6Z"


def _git_dates(root):
    """파일별 최초 커밋 날짜(작성일). git log 한 번으로 전부 수집.

    로그는 최신순이므로 같은 경로를 계속 덮어쓰면 마지막에 가장 오래된 날짜가 남는다.
    폴더 이름을 바꾼 이력이 있는 문서는 그 시점이 작성일로 잡힌다.
    """
    out = subprocess.run(
        ["git", "-c", "core.quotepath=false", "log", "--name-only", "--no-merges",
         "--date=short", "--format=%x00%ad"],
        cwd=str(root), capture_output=True, text=True,
        encoding="utf-8", errors="replace",
    ).stdout
    dates, current = {}, ""
    for line in out.splitlines():
        if line.startswith("\x00"):
            current = line[1:]
        elif line:
            dates[line] = current
    return dates


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


def _icon(path_data):
    return (f'<svg class="post-card__icon" viewBox="0 0 24 24" aria-hidden="true">'
            f'<path d="{path_data}"/></svg>')


def _url(rel, directory_urls):
    """생 HTML은 MkDocs가 경로를 고쳐주지 않으므로 직접 최종 URL을 만든다."""
    base = rel[:-3] if rel.endswith(".md") else rel
    return quote(base + "/" if directory_urls else base + ".html")


def _card(link, title, excerpt, date, category):
    return (
        f'<a class="post-card" href="{html.escape(link)}">'
        f'<h2 class="post-card__title">{html.escape(title)}</h2>'
        + (f'<p class="post-card__excerpt">{html.escape(excerpt)}</p>' if excerpt else "")
        +
        f'<div class="post-card__meta">'
        f'<span>{_icon(ICON_DATE)}{html.escape(date or "-")}</span>'
        f'<span>{_icon(ICON_CATEGORY)}{html.escape(category)}</span>'
        f'</div></a>'
    )


def _render(root, directory_urls):
    dates = _git_dates(root)
    rows = []
    for path in root.rglob("*.md"):
        rel = path.relative_to(root).as_posix()
        parts = rel.split("/")
        if len(parts) < 2 or parts[0] in SKIP_TOP or path.name in SKIP_NAMES:
            continue
        rows.append((dates.get(rel, ""), rel, path))

    rows.sort(key=lambda row: row[0], reverse=True)

    cards = []
    for date, rel, path in rows[:LIMIT]:
        title, excerpt = _meta(path)
        cards.append(_card(_url(rel, directory_urls), title, excerpt, date,
                           " · ".join(rel.split("/")[:-1])))

    if not cards:
        return "<p>아직 글이 없습니다.</p>"
    return '<div class="post-list">' + "".join(cards) + "</div>"


def on_page_markdown(markdown, page, config, files):
    if page.file.src_uri != "index.md" or MARKER not in markdown:
        return markdown
    return markdown.replace(
        MARKER, _render(Path(config.docs_dir).resolve(), config.use_directory_urls)
    )
