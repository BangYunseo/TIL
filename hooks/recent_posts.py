"""홈 화면의 글 목록을 git 이력에서 생성한다.

index.md 안의 <!-- posts --> 자리에 최근 수정된 문서 목록을 끼워 넣는다.
날짜는 각 파일의 마지막 커밋 날짜다.
"""

import subprocess
from pathlib import Path

MARKER = "<!-- posts -->"
LIMIT = 30
SKIP_NAMES = {"README.md", "index.md"}
SKIP_TOP = {"site", ".venv", "venv", "hooks", "javascripts", ".github", ".claude"}
SKIP_PREFIX = (">", "#", "<", "|", "```", "![", "---", "===")


def _git_dates(root):
    """파일별 마지막 커밋 날짜. git log 한 번으로 전부 수집."""
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
        elif line and line not in dates:
            dates[line] = current
    return dates


def _clean(text):
    for token in ("**", "`", "*"):
        text = text.replace(token, "")
    return text.strip()


def _meta(path):
    """문서에서 제목(첫 h1)과 요약(첫 본문 줄)을 뽑는다."""
    title, excerpt = path.stem, ""
    try:
        lines = path.read_text(encoding="utf-8", errors="replace").splitlines()
    except OSError:
        return title, excerpt
    seen_title = False
    for raw in lines:
        line = raw.strip()
        if not line:
            continue
        if not seen_title:
            if line.startswith("# "):
                title, seen_title = _clean(line[2:]), True
            continue
        if line.startswith(SKIP_PREFIX):
            continue
        excerpt = _clean(line.lstrip("-*+ "))
        break
    if len(excerpt) > 90:
        excerpt = excerpt[:90].rstrip() + "…"
    return title, excerpt


def _render(root):
    dates = _git_dates(root)
    rows = []
    for path in root.rglob("*.md"):
        rel = path.relative_to(root).as_posix()
        parts = rel.split("/")
        if len(parts) < 2 or parts[0] in SKIP_TOP or path.name in SKIP_NAMES:
            continue
        rows.append((dates.get(rel, ""), rel, path))

    rows.sort(key=lambda row: row[0], reverse=True)

    out = []
    for date, rel, path in rows[:LIMIT]:
        title, excerpt = _meta(path)
        category = " · ".join(rel.split("/")[:-1])
        line = f"- **[{title}]({rel})** &nbsp;`{date or '-'}` · {category}"
        if excerpt:
            line += f"<br>{excerpt}"
        out.append(line)
    return "\n".join(out) if out else "_아직 글이 없습니다._"


def on_page_markdown(markdown, page, config, files):
    if page.file.src_uri != "index.md" or MARKER not in markdown:
        return markdown
    return markdown.replace(MARKER, _render(Path(config.docs_dir).resolve()))
