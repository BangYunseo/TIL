/* 홈 목록 페이지 나누기, 사이드바 배치 조정.
   navigation.instant가 켜져 있어 페이지 전환마다 다시 실행해야 한다. */

function paginatePosts() {
  const list = document.querySelector(".post-list");
  const pager = document.querySelector(".post-pager");
  if (!list || !pager) return;

  const cards = Array.from(list.children);
  const size = parseInt(list.dataset.pageSize, 10) || 12;
  const pages = Math.ceil(cards.length / size);
  if (pages <= 1) return;

  function show(page, scroll) {
    cards.forEach((card, index) => {
      card.hidden = Math.floor(index / size) !== page - 1;
    });
    pager.querySelectorAll("button").forEach((button) => {
      button.classList.toggle("is-current", Number(button.dataset.page) === page);
    });
    if (scroll) window.scrollTo({ top: 0, behavior: "smooth" });
  }

  pager.replaceChildren();
  for (let page = 1; page <= pages; page += 1) {
    const button = document.createElement("button");
    button.type = "button";
    button.textContent = String(page);
    button.dataset.page = String(page);
    button.addEventListener("click", () => show(page, true));
    pager.appendChild(button);
  }
  show(1, false);
}

/* 푸터의 GitHub 등 소셜 링크를 좌측 사이드바 아래로 옮긴다. */
function moveSocialToSidebar() {
  const social = document.querySelector(".md-footer-meta .md-social");
  const sidebar = document.querySelector(".md-sidebar--primary .md-sidebar__inner");
  if (!social || !sidebar || sidebar.querySelector(".md-social")) return;
  sidebar.appendChild(social);
}

/* 홈에서 생성한 '최근 수정' 패널을 우측 사이드바로 옮긴다. */
function moveRecentPanel() {
  const template = document.getElementById("recent-panel");
  const sidebar = document.querySelector(".md-sidebar--secondary .md-sidebar__inner");
  if (!template || !sidebar || sidebar.querySelector(".recent-panel")) return;
  sidebar.appendChild(template.content.cloneNode(true));
}

document$.subscribe(function () {
  paginatePosts();
  moveSocialToSidebar();
  moveRecentPanel();
});
