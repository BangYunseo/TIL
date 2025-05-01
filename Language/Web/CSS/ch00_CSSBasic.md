# Chapter 0. CSS 기초

> 
> 1절. CSS 스타일 시트
>
> 2절. CSS 스타일 시트 생성
>
> 3절. 


## 1절. CSS 스타일 시트

### CSS(Cascading Style Sheet)

- HTML 문서의 색상 · 모양 등 외관을 꾸미는 언어
- 스타일 시트(Style Sheet) : CSS로 작성된 코드

### CSS3 : CSS Level 3

- 현재 CSS 버전 : CSS3
    - CSS1 -> CSS2 -> CSS3 -> CSS4(현재 표준화 작업 진행)

- CSS3 기능

|기능|
|:---:|
| 색상 · 배경|
|텍스트|
|폰트|
|박스 모델(Box Model)|
|비주얼 포맷 · 효과|
|리스트|
|테이블|
|사용자 인터페이스|

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
        /* CSS 스타일 시트 작성 */
        body {
            background-color: mistyrose;
        }

        h3 {
            color: purple;
        }

        hr {
            border: 5px solid yellowgreen;
        }

        span {
            color: blue;
            font-size: 20px;
        }
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

|구성 요소|설명|
|:---:|:---|
|셀렉터|CSS3 스타일 시트를 HTML 페이지에 적용하도록 만든 이름|
|프로퍼티|스타일 속성 이름<br>약 200개의 프로퍼티 존재|
|값|프로퍼티의 값|
|주석문|스타일 시트 내의 설명문<br>사용 방법 : /* ... */<br>여러 줄 · 아무 위치에 사용|
|대소문자 구분 X|body { background-color : mistyrose; } <br>== BODY { Background-Color : Mistyrose; }|

## 2절. CSS 스타일 시트 생성

### 1. <style></style> 태그에 스타일 시트 작성

```HTML
<head>
    <style>
        body {
            background-color: mistyrose;
        }

        h3 {
            color: purple;
        }
    </style>
    <style>
        hr {
            border: 5px solid yellowgreen;
        }

        span {
            color: blue;
            font-size: 20px;
        }
    </style>
</head>
```

- <style> 태그
  - <head> 태그 내에서만 사용 가능
  - 여러 번 작성 가능 : 스타일 시트들이 합쳐 사용
  - 스타일 시트는 웹 페이지 전체 적용


### 2. style 속성에 스타일 시트 작성
  
### 3. 스타일 시트를 별도 파일로 작성 : <link> 태그 · @import로 불러 사용
