# Chapter 0. 자바스크립트 소개

> 1절. 개요
>
> 2절. 활용
>
> 3절. node.js
>
> 4절. TypeScript

## 1절. 개요

### 자바스크립트(JavaScript)

- 웹 브라우저 내에서 가장 많이 사용하는 프로그래밍 언어
- 다른 응용 프로그램 내장 객체에 접근하는 기능 존재

### 사용 분야

- 서버 사이드 네트워크 프로그래밍
  - Node.js
- 페이지 스크립팅
  - DOM
- 구글 크롬 웹 브라우저 플러그인
- 구글 스크립트
- PDF
- 각종 데스크탑 위젯

### 역사

- 넷스케이프 사의 브랜든 아이히(Brendan Eich)에 의해 '모카'라는 이름으로 시작
- 모카 => 라이브 스크립트 이름 변경
- 넷스케이프 사가 썬 마이크로시스템과 함께 자바스크립트라는 이름을 붙이고 본격적으로 발전

### JQuery

- 자바 스크립트 라이브러리

## 2절. 활용

### 자바와 자바스크립트

- 문법 상 유사점

  - C언어 기반으로 발전한 언어

### 자바(Java)

- 객체지향 프로그래밍 언어
- 타 언어들과의 차이점
  - 컴파일된 코드가 플랫폼 독립적
- 1995년 썬 마이크로시스템즈에서 제임스 고슬링과 연구원들이 개발한 언어
- CPU, OS에 상관없이 어디서나 실행 가능

| 자바                              | 자바스크립트                              |
| :-------------------------------- | :---------------------------------------- |
| 컴파일 언어                       | 인터프리터 언어                           |
| 엄격한 타입 검사                  | 타입 명시 X                               |
| 클래스(Class) 기반 객체 지향 언어 | 프로토타입(Prototype) 기반 객체 지향 언어 |

### 웹에서 웹 어플리케이션으로

#### 초기의 웹

- 웹 : 하이퍼링크라는 매개체를 통해 웹 문서가 연결된 거대한 책
- 변화 없는 정적 글자들의 나열

#### 자바스크립트의 등장

- 웹 문서 내용을 동적으로 변환
- 마우스 클릭과 같은 이벤트 처리

#### 웹의 애플리케이션화

- 웹 문서 작성 도구
- 구글, 마이크로소프트
  - 웹 브라우저로 워드, 엑셀, 파워포인트 같은 애플리케이션 사용 가능
- 웹 애플리케이션은 웹 브라우저만 있으면 언제 어디서나 사용 가능

### 웹 어플리케이션

- 구글에서 제공하는 크롬 웹 스토어
  - 웹 스토어, 웹 브라우저 상에서 실행되는 웹 어플리케이션 거래

<img src="https://github.com/BangYunseo/TIL/blob/main/Language\Web\JavaScript\Image\ch00\ch00-01-CWA.PNG"  height="auto" />

### 웹 서버 어플리케이션
