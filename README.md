# 개발 저장고

> 개발과 컴퓨터공학 학습 내용을 분야별로 정리한 저장소입니다.

<p align="center">
  <a href="https://bangyunseo.github.io/TIL/">
    <img src="https://img.shields.io/badge/웹에서_보기-BangYunseo-4051B5?style=for-the-badge&logo=jekyll&logoColor=white" alt="웹에서 보기" />
  </a>
</p>

🔗 **웹사이트** : <https://bangyunseo.github.io/TIL/>

## 학습 분야

### 🧠 AI &nbsp; [🔗 링크](https://bangyunseo.github.io/TIL/posts/AI-Index/)

- 딥러닝
- 기계학습

### 🤖 Android &nbsp; [🔗 링크](https://bangyunseo.github.io/TIL/posts/Android-Index/)

- 모바일 앱 개발

### 💻 Language &nbsp; [🔗 링크](https://bangyunseo.github.io/TIL/posts/Language-Index/)

- C
- C++
- C#
- Java
- Python
- Kotlin
- Web

### 🖥️ Computer Science &nbsp; [🔗 링크](https://bangyunseo.github.io/TIL/posts/ComputerScience-Index/)

- 자료구조
- 알고리즘
- 데이터베이스
- 운영체제
- 소프트웨어공학

### 🌐 Communication &nbsp; [🔗 링크](https://bangyunseo.github.io/TIL/posts/Communication-Index/)

- 데이터 통신
- 네트워크
- 시리얼 통신

### 🎮 Game Engine &nbsp; [🔗 링크](https://bangyunseo.github.io/TIL/categories/gameengine/)

- Unity
- Unreal

### 🔒 Security &nbsp; [🔗 링크](https://bangyunseo.github.io/TIL/posts/InformationSecurity-Index/)

- 정보보안
- 암호학

### 📷 Machine Vision &nbsp; [🔗 링크](https://bangyunseo.github.io/TIL/posts/MachineVision-Index/)

- 머신비전
- 검사 시스템

## 작성 규칙

### 문서 위치

- 글은 `_posts/<분야>/<세부 분야>/` 아래에 둔다
- 파일명은 `YYYY-MM-DD-제목.md` (날짜가 없으면 Jekyll이 글로 인식하지 않는다)
- 제목 부분이 그대로 주소가 된다 (`_posts/AI/2026-01-01-MCP.md` -> `/TIL/posts/MCP/`)
- 아직 내용이 없는 글은 `_drafts/` 에 두면 사이트에 나오지 않는다

### 머리말(front matter)

```yaml
---
title: "문서 제목"
date: 2026-01-01 09:00:00 +0900
categories: [분야, 세부분야]   # 2단계까지만
tags: [태그]                   # 없으면 생략
math: true                     # 수식을 쓰면 추가
---
```

### 이미지

- 이미지는 예전처럼 `<분야>/<세부 분야>/Image/chXX/` 에 둔다 (`_posts` 밖)
- 문서에서는 저장소 루트 기준 경로로 적는다

```markdown
![Example](/AI/DeepLearning/Image/ch00/Example.PNG)
```

- 이미지 파일명은 의미 있는 영문 PascalCase로 작성 (예: `MergeSort.PNG`)

### 문서 사이 링크

```markdown
[다른 글]({{ site.baseurl }}/posts/ch01_Numpy/)
```

### Git Commit Type

| Type | 설명 |
| :--- | :--- |
| feat | 새로운 기능 추가 |
| fix | 버그 수정 |
| docs | 문서 수정 |
| style | 코드 스타일 변경 (포매팅, 세미콜론 등) |
| design | 사용자 UI 디자인 변경 |
| test | 테스트 코드, 리팩토링 |
| refactor | 리팩토링 |
| build | 빌드 파일 수정 |
| ci | CI 설정 파일 수정 |
| perf | 성능 개선 |
| chore | 자잘한 수정이나 빌드 업데이트 |
| rename | 파일 혹은 폴더명 수정만 한 경우 |
| remove | 파일을 삭제만 한 경우 |

### 참고 자료

- [마크다운 작성 양식](https://gist.github.com/ihoneymon/652be052a0727ad59601)
- [README.md 작성법](https://lsh424.tistory.com/37)
