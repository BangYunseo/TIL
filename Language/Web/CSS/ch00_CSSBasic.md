# Chapter 0. CSS 기초

> 1절. CSS 개요
>
> 2절. 셀렉터
>
> 3절. 색, 텍스트, 폰트
>
> 4절. Box

## 1절. CSS 개요

### CSS(Cascading Style Sheet)

- HTML 문서의 색상 · 모양 등 외관을 꾸미는 언어
- 스타일 시트(Style Sheet)
  - CSS로 작성된 코드

### CSS3 : CSS Level 3

- 현재 CSS 버전 : CSS3

|       CSS 기능       |
| :------------------: |
|     색상 · 배경      |
|        텍스트        |
|         폰트         |
| 박스 모델(Box Model) |
|  비주얼 포맷 · 효과  |
|        리스트        |
|        테이블        |
|  사용자 인터페이스   |

### 웹 페이지 비교

- HTML 태그로만 작성한 웹 페이지

```HTML
<!DOCTYPE html>
<html>

<head>
    <meta charset="utf-8">
    <title>스타일 없는 웹 페이지</title>
</head>

<body>
    <h3>CSS 스타일 맛보기</h3>
    <hr>
    <p>나는 <span>웹 프로그래밍</span>을 좋아합니다.</p>
</body>

</html>
```

<img src="https://github.com/BangYunseo/TIL/blob/main/Language/Web/CSS/Image/ch00/ch00-01-HtmlWeb.PNG" width="auto"/>

- 스타일 시트로 꾸민 웹 페이지

```HTML
<!DOCTYPE html>
<html>

<head>
    <meta charset="utf-8">
    <title>스타일을 가진 웹 페이지</title>
    <style>
        /* CSS 스타일 시트 */
        body { background-color: mistyrose; }
        h3 { color: purple; }
        hr { border: 5px solid yellowgreen; }
        span { color: blue; font-size: 20px; }
    </style>
</head>

<body>
    <h3>CSS 스타일 맛보기</h3>
    <hr>
    <p>나는 <span>웹 프로그래밍</span>을 좋아합니다.</p>
</body>

</html>
```

<img src="https://github.com/BangYunseo/TIL/blob/main/Language/Web/CSS/Image/ch00/ch00-02-StyleSheetWeb.PNG" width="auto"/>

### CSS3 스타일 시트 구성

- ex) <span> 텍스트를 20px blue로 출력하는 CSS3 StyleSheet

<img src="https://github.com/BangYunseo/TIL/blob/main/Language/Web/CSS/Image/ch00/ch00-03-StyleSheet.PNG" width="auto"/>

|    구성 요소    | 설명                                                                                 |
| :-------------: | :----------------------------------------------------------------------------------- |
|     셀렉터      | CSS 스타일 시트를 HTML 페이지에 적용하도록 만든 이름                                 |
|    프로퍼티     | 스타일 속성 이름<br>약 200개의 프로퍼티 존재                                         |
|       값        | 프로퍼티의 값                                                                        |
|     주석문      | 스타일 시트 내의 설명문<br>사용 방법 : /_ ... _/<br>여러 줄 · 아무 위치에 사용       |
| 대소문자 구분 X | body { background-color : mistyrose; } <br>== BODY { Background-Color : Mistyrose; } |

### HTML 문서 CSS 스타일 시트 생성 방법

### 1. \<style\>\</style\> 태그에 스타일 시트 작성

```HTML
<head>
    <style>
        body { background-color: mistyrose; }
        h3 { color: purple; }
    </style>
    <style>
        hr { border: 5px solid yellowgreen; }
        span { color: blue; font-size: 20px; }
    </style>
</head>
```

- \<style\> 태그
  - \<head\> 태그 내에서만 사용 가능
  - 여러 번 작성 가능
    - 스타일 시트 통합 사용
  - 웹 페이지 전체 적용

#### 1 : 사용 예시(1)

<img src="https://github.com/BangYunseo/TIL/blob/main/Language/Web/CSS/Image/ch00/ch00-04-html1.PNG" width="auto"/>

```HTML
<!DOCTYPE html>
<html>

<head>
    <meta charset="utf-8">
    <title>&lt;style&gt; 태그로 스타일 만들기</title>
    <style>
        body {
            background-color: linen;
            color: blueviolet;
            margin-left: 30px;
            margin-right: 30px;
        }

        h3 {
            text-align: center;
            color: darkred;
        }
    </style>
</head>

<body>
    <h3>소연재</h3>
    <hr>
    <p>저는 체조 선수 소연재입니다.
        음악을 들으면서 책읽기를 좋아합니다.
        김치 찌개와 막국수 무척 좋아합니다.
    </p>
</body>

</html>
```

#### 1 : 사용 예시(2)

<img src="https://github.com/BangYunseo/TIL/blob/main/Language/Web/CSS/Image/ch00/ch00-05-html2.PNG" width="auto"/>

- 해당 태그에만 스타일 적용

- 코드 예시

```HTML
<!DOCTYPE html>
<html>

<head>
    <meta charset="utf-8">
    <title>&lt;style&gt; 속성에 스타일 만들기</title>
    <style>
        p {
            color: red;
            font-size: 15px;
        }
    </style>
</head>

<body>
    <h3>손 홍 민</h3>
    <hr>
    <p>오페라를 좋아하고</p>
    <p>엘비스 프레슬리를 좋아하고</p>
    <p style="color:blue">김치부침개를 좋아하고</p>
    <p style="color:magenta; font-size:30px">축구를 좋아합니다.</p>
</body>

</html>
```

<img src="https://github.com/BangYunseo/TIL/blob/main/Language/Web/CSS/Image/ch00/ch00-06-html3.PNG" width="auto"/>

### 2. 스타일 시트 별도 파일 작성 : <link> 태그 · @import

- 외부 스타일 시트 파일(.css) 불러오기

  - 동일 스타일 시트를 웹 페이지마다 중복 작성 해소
  - 웹 사이트 전체 웹 페이지 모양 일관성 확보

1. \<link\> 태그

```HTML
<head>
    <link href="mystyle.css" type="text/css" rel="stylesheet">
</head>
```

2. @import

```HTML
<style>
    @import url(mystyle.css);
    /* @import url("mystyle.css"); */
    /* @import "mystyle.css"; */
</style>
```

#### 2 : 사용 예시(1)

- CSS 스타일 시트를 mystyle.css 파일로 저장
- \<link\> 태그로 불러서 사용

```CSS
/* mystyle.css */

body {
    background - color: linen;
    color: blueviolet;
    margin - left: 30 px;
    margin - right: 30 px;
}
h3 {
    text - align: center;
    color: darkred;
}
```

```HTML
<!DOCTYPE html>
<html>

<head>
    <meta charset="utf-8">
    <title>&lt;link&gt; 태그로 스타일 파일 불러오기</title>
    <link type="text/css" rel="stylesheet" href="mystyle.css">
</head>

<body>
    <h3>소연재</h3>
    <hr>
    <p>저는 체조 선수 소연재입니다. 음악을 들으면서 책읽기를 좋아 합니다. 김치 찌개와 막국수 무척 좋아합니다.</p>
</body>

</html>
```

#### 2 : 사용 예시(2)

- CSS 스타일 시트를 mystyle.css 파일로 저장
- @import 로 불러서 사용

```CSS
/* mystyle.css */

body {
    background - color: linen;
    color: blueviolet;
    margin - left: 30 px;
    margin - right: 30 px;
}
h3 {
    text - align: center;
    color: darkred;
}
```

```HTML
<!DOCTYPE html>
<html>

<head>
    <meta charset="utf-8">
    <title>&lt;link&gt; 태그로 스타일 파일 불러오기</title>
    <style>
        @import url(mystyle.css);
    </style>
</head>

<body>
    <h3>소연재</h3>
    <hr>
    <p>저는 체조 선수 소연재입니다. 음악을 들으면서 책읽기를 좋아 합니다. 김치 찌개와 막국수 무척 좋아합니다.</p>
</body>

</html>
```

### CSS 규칙 : 스타일 상속

- 부모 태그(부모 요소)

  - 자신을 둘러싸는 태그
  - 상속 주체

- 상속 예시

```HTML
<!DOCTYPE html>
<html>

<head>
    <meta charset="utf-8">
    <title>부모 스타일 상속</title>
</head>

<body>
    <h3>부모 스타일 상속</h3>
    <hr>
    <p style="color:green">
        자식 태그는 부모의 스타일을<em style="font-size:25px">상속</em>받는다.
    </p>
</body>

</html>
```

<img src="https://github.com/BangYunseo/TIL/blob/main/Language/Web/CSS/Image/ch00/ch00-07-html4.PNG" width="auto"/>

- \<p\> 태그 : \<em\> 태그의 부모
- \<em\> 태그 출력
  - 글자 크기 : 25px
  - 글자 색 : 부모 \<p\> 태그를 상속받아 green

### 스타일 합치기 & 오버라이딩

<img src="https://github.com/BangYunseo/TIL/blob/main/Language/Web/CSS/Image/ch00/ch00-08-OverRiding.PNG" width="auto"/>

## 2절. 셀렉터

### 셀렉터(Selector)

<img src="https://github.com/BangYunseo/TIL/blob/main/Language/Web/CSS/Image/ch00/ch00-09-Selector.PNG" width="auto"/>

- HTML 태그의 모양을 꾸밀 스타일 시트 선택 기능
  - 여러 유형 존재
  - ex) 웹 페이지 모든 \<h3\> 태그에 color: brown 스타일 적용

### 태그 이름 셀렉터

<img src="https://github.com/BangYunseo/TIL/blob/main/Language/Web/CSS/Image/ch00/ch00-10-TagSelector.PNG" width="auto"/>

- 태그 이름이 셀렉터로 사용되는 유형
- 셀렉터와 같은 이름의 모든 태그에 스타일 시트 적용

### 클래스 셀렉터

<img src="https://github.com/BangYunseo/TIL/blob/main/Language/Web/CSS/Image/ch00/ch00-11-ClassSelector.PNG" width="auto"/>

- 점(.)으로 시작하는 셀렉터
- HTML의 class 속성으로 지정

  - class 속성이 같은 모든 태그 적용

```CSS
body.main {
    background : aliceblue;
}
```

- \<body class="main"\> 태그에만 적용

### ID 셀렉터

<img src="https://github.com/BangYunseo/TIL/blob/main/Language/Web/CSS/Image/ch00/ch00-12-IdSelector.PNG" width="auto"/>

- #로 시작하는 셀렉터
- HTML의 id 속성으로 지정

  - id 속성이 같은 모든 태그 적용

```CSS
div#etc {
    background : mistyrose;
}
```

- 다음 사용 불가능
- \<p id="etc"\>안녕하세요\</p\>
  - id="etc" 사용 불가

### Class 셀렉터 VS ID 셀렉터

- Class 셀렉터

  - 여러 태그를 하나의 그룹으로 묶음
  - 단체로 동일한 CSS 스타일 적용
  - Class 속성값이 같은 태그에 모두 CSS 스타일 적용
  - 태그 종류 관계 없이 Class 셀렉터 활용

- ID 셀렉터
  - 각 태그를 유일하게 구분
  - 동일한 ID 속성이 같지 않도록 HTML 파일 작성
  - JS 코드에서 id 값을 가진 태그 객체 탐색 시 문제
  - 여러 태그 중 특정 태그에만 CSS 스타일 적용 시 사용

### 셀렉터 조합

1. 2개 이상의 셀렉터 조합
   - 조합에 적합한 HTML 태그에만 적용
2. 자식 셀렉터(Child Selector)

   - 부모 자식 관계의 두 셀렉터를 '>' 기호로 조합

```CSS
div > strong {
    color: dodgerblue;
}
```

- \<div\>의 직계 자식인 \<strong\>에 적용되는 스타일 시트

3. 자손 셀렉터(Descendent Selector)
   - 자손 관계인 2개 이상의 태그 나열
     - 자손 : 자식 및 그 후손 모두 포함

```CSS
ul strong {
    color: dodgerblue;
}
```

- \<ul\>의 자손 \<strong\>에 적용되는 스타일 시트

#### 자식 & 자손 셀렉터

<img src="https://github.com/BangYunseo/TIL/blob/main/Language/Web/CSS/Image/ch00/ch00-13-Childs.PNG" width="auto"/>

### 전체 셀렉터(Universal Selector)

- 와일드 문자(\*)를 사용해 모든 태그에 적용시키는 셀렉터

```CSS
*{
    color: green;
}
```

- 웹 페이지 모든 태그 적용
- 텍스트 색을 green으로 변환

### 속성 셀렉터(Attribute Selector)

- HTML 태그의 특정 속성(Attribute)에 대해 값이 일치하는 태그에만 스타일 적용

```CSS
input[type=text]{
    color: red;
}
```

- type 속성값이 "text"인 \<input\> 태그에 적용
- \<input type="text"\>

### 가상 클래스(Pseudo-Class) 셀렉터

- 어떤 조건이나 상황에서 적용
- 40개 이상의 유형 존재

<img src="https://github.com/BangYunseo/TIL/blob/main/Language/Web/CSS/Image/ch00/ch00-14-PCS.PNG" width="auto"/>

```CSS
a: visited {
    color: green;
}
```

- 방문한 \<a\> 링크 텍스트 색을 green으로 출력

```CSS
li: hover {
    background: yellowgreen;
}
```

- \<li\> 태그에 마우스가 올라오면 yellowgreen을 배경색으로 출력, 내려가면 복귀

#### 가상 클래스 셀렉터 활용 예시

<img src="https://github.com/BangYunseo/TIL/blob/main/Language/Web/CSS/Image/ch00/ch00-15-PCSex.PNG" width="auto"/>

### 셀렉터 활용 예시

<img src="https://github.com/BangYunseo/TIL/blob/main/Language/Web/CSS/Image/ch00/ch00-16-PCSex2.PNG" width="auto"/>

```HTML
<!DOCTYPE html>
<html>

<head>
    <meta charset="utf-8">
    <title>셀렉터 만들기</title>
    <style>
        h3,
        li {
            /* 태그 이름 셀렉터 */
            color: brown;
        }

        div>div>strong {
            /* 자식 셀렉터 */
            background: yellow;
        }

        ul strong {
            /* 자손 셀렉터 */
            color: dodgerblue;
        }

        .warning {
            /* class 셀렉터 */
            color: red;
        }

        body.main {
            /* class 셀렉터 */
            background: aliceblue;
        }

        #list {
            /* id 셀렉터 */
            background: mistyrose;
        }

        #list span {
            /* 자손 셀렉터 */
            color: forestgreen;
        }

        h3:first-letter {
            /* 가상 클래스 셀렉터 */
            color: red;
        }

        li:hover {
            /* 가상 클래스 셀렉터 */
            background: yellowgreen;
        }
    </style>
</head>

<body class="main">
    <h3>Web Programming</h3>
    <hr>
    <div>
        <div>2학기 <strong>학습 내용</strong>입니다.</div>
        <ul id="list">
            <li><span>HTML5</span></li>
            <li><strong>CSS</strong></li>
            <li>JAVASCRIPT</li>
        </ul>
        <div class="warning">60점 이하는 F</div>
    </div>
</body>

</html>
```

## 3절. 색, 텍스트, 폰트

### 색 스타일 시트

#### 1. 16진수 코드 표현

<img src="https://github.com/BangYunseo/TIL/blob/main/Language/Web/CSS/Image/ch00/ch00-17-Color16.PNG" width="auto"/>

- 보라색(blueviolet)의 혼합된 색
  - 빨간색(r) 성분 : 0x8A(138)
  - 초록색(g) 성분 : 0x2B(43)
  - 파란색(b) 성분 : 0xE2(226)

```CSS
div {
    color: #8A2BE2;
}
```

#### 2. 10진수 코드 & RGB 표현

<img src="https://github.com/BangYunseo/TIL/blob/main/Language/Web/CSS/Image/ch00/ch00-18-Color10.PNG" width="auto"/>

- 보라색(blueviolet)의 혼합된 색
  - 빨간색(r) 성분 : 138
  - 초록색(g) 성분 : 43
  - 파란색(b) 성분 : 226

```CSS
div {
    color: rgb(138, 43, 226);
}
```

#### 3. 색 이름 표현

- CSS 표준
  - 140개의 색 이름 표준 존재

<img src="https://github.com/BangYunseo/TIL/blob/main/Language/Web/CSS/Image/ch00/ch00-19-ColorS.PNG" width="auto"/>

```CSS
div {
    color: blueviolet;
}
```

#### 색 속성

```CSS
/* 텍스트 글자 색 */
color : 색;

/* 배경 색 */
background-color : 색;

/* 테두리 색 */
border-color : 색;
```

### 텍스트 스타일 시트

#### 텍스트 속성

```CSS
/* 들여쓰기 */
text-indent : <length>|<percentage>;

/* 정렬 */
text-align : left|right|center|justify;

/* 텍스트 꾸미기 */
text-decoration : none|underline|overline|line-through;
```

#### 텍스트 요소 사용 예시(1)

- 하이퍼링크 밑줄 제거

```HTML
<a href="http://www.naver.com" style="text-decoration : none">네이버</a>
```

#### 텍스트 요소 사용 예시(2)

<img src="https://github.com/BangYunseo/TIL/blob/main/Language/Web/CSS/Image/ch00/ch00-20-Textex.PNG" width="auto"/>

```HTML
<!DOCTYPE html>
<html>

<head>
    <meta charset="utf-8">
    <title>텍스트 꾸미기</title>
    <style>
        h3 {
            text-align: right;
            /* 오른쪽 정렬 */
        }

        span {
            text-decoration: line-through;
            /* 중간 줄 */
        }

        strong {
            text-decoration: overline;
            /* 윗줄 */
        }

        .p1 {
            text-indent: 3em;
            /* 3 글자 들여쓰기 */
            text-align: justify;
            /* 양쪽 정렬 */
        }

        .p2 {
            text-indent: 1em;
            /* 1 글자 들여쓰기 */
            text-align: center;
            /* 중앙 정렬 */
        }
    </style>
</head>

<body>
    <h3>텍스트 꾸미기</h3>
    <hr>
    <p class="p1">HTML의 태그만으로 기존의
        워드 프로세서와 같이 들여쓰기, 정렬, 공백, 간격 등과 세밀한 <span>텍스트 제어</span>를 할 수 없다. </p>
    <p class="p2">그러나,
        <strong>스타일 시트</strong>는 이를 가능하게 한다. 들여쓰기, 정렬에 대해서 알아본다
    </p>
    <a href="http://www.naver.com" style="text-decoration : none">
        밑줄이 없는 네이버 링크</a>
</body>

</html>
```

### CSS 표준 단위

| 단위 | 의미                            | 사용 예시                                            |
| :--: | :------------------------------ | :--------------------------------------------------- |
|  em  | 배수                            | font-size: 3em;<br>현재 폰트의 3배 크기              |
|  %   | 퍼센트                          | font-size: 500%;<br>현재 폰트의 500% 크기            |
|  px  | 픽셀 수                         | font-size: 10px;<br>10px 크기                        |
|  cm  | 센티미터                        | margin-left: 5cm;<br>왼쪽 여백 5cm                   |
|  mm  | 밀리미터                        | margin-left: 10mm;<br>왼쪽 여백 10mm                 |
|  in  | 인치(1 in = 2.54 cm = 96 px)    | margin-left: 2in;<br>왼쪽 여백 2인치                 |
|  pt  | 포인터(1 pt = 1 in의 1/72 크기) | margin-left: 20pt;<br>왼쪽 여백 20포인트             |
|  pc  | 피카소(picas), (1 pc = 12 pt)   | font-size: 1pc;<br>1pc 크기 폰트                     |
| deg  | 각도                            | transform: rotate(20deg);<br>시계 방향으로 20도 회전 |

- HTML5에서 단위 미사용 시 CSS 스타일 오류

```CSS
/* 오류 */
font-size: 3;

/* 정상 */
font-size: 3px;
```

### 폰트 스타일 시트

#### 폰트 속성

```CSS
/* 폰트 형 */
font-family: Arial, "Times New Roman", Serif;

/* 폰트 크기 */
font-size: 40px|medium|1.6em;

/* 폰트 스타일 */
font-style: italic;

/* 폰트 굵기 */
font-weight: 100~900|bold;
```

#### font 지정 속성

```CSS
font: font-style font-weight font-size font-family
```

#### font 지정 속성 사용 예시

- 20px 이탤릭 스타일 bold 굵기 consolas 체의 폰트 지정

```CSS
font : italic bold 20px consolas sans-serif;
```

#### 폰트 요소 사용 예시

<img src="https://github.com/BangYunseo/TIL/blob/main/Language/Web/CSS/Image/ch00/ch00-21-Fontex.PNG" width="auto"/>

```HTML
<!DOCTYPE html>
<html>

<head>
    <meta charset="utf-8">
    <title>폰트</title>
    <style>
        body {
            font-family: "Times New Roman", Serif;
            font-size: large;
        }

        h3 {
            font: italic bold 40px consolas, sans-serif;
        }
    </style>
</head>

<body>
    <h3>Consolas font</h3>
    <hr>
    <p style="font-weight:900">font-weight 900</p>
    <p style="font-weight:100">font-weight 100</p>
    <p style="font-style:italic">Italic Style</p>
    <p style="font-style:oblique">Oblique Style</p>
    <p>현재 크기의
        <span style="font-size:1.5em">1.5배</span> 크기로</p>
</body>

</html>
```

## 4절. Box

(CSS3의 박스모델 부터 다시 작성!)
