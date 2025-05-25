# WAS(Web Application Server)

> 1절. WS vs WAS

## 1절. WS vs WAS

### Web Server vs Web Application Server

<img src="https://github.com/BangYunseo/TIL/blob/main/Language/Web/Image/WAS/WSWAS.PNG" height="auto" />

### Web Server : Static Pages

<img src="https://github.com/BangYunseo/TIL/blob/main/Language/Web/Image/WAS/WS.PNG" height="auto" />

- 파일 경로 이름을 받아 경로와 일치하는 file contents 반환
- 항상 동일한 페이지 반환
- 컴퓨터에 저장되어 있는 파일들
  - image
  - html
  - css
  - javascript

### Web Application Server : Dynamic Pages

<img src="https://github.com/BangYunseo/TIL/blob/main/Language/Web/Image/WAS/WAS.PNG" height="auto" />

- 인자 내용에 맞는 동적인 contents 반환
- 웹 서버에 의해 실행된 프로그램으로 만들어진 결과물
- Servlet
  - WAS 위에서 돌아가는 Java Program
  - 개발자는 Servlet의 doGet() 구현

### Web Server 사용 이유

- 정적인 파일들을 Application Server까지 가지 않고 빠르게 전송
- 정적 컨텐츠만 처리하도록 기능을 분배
- 서버 부담 감소

### Web Application Server 사용 이유

- 요청에 맞는 데이터를 DB에서 가져와서 비즈니스 로직에 맞게 결과 제공
- 자원의 효율적 분배

### Web Server Architecture

<img src="https://github.com/BangYunseo/TIL/blob/main/Language/Web/Image/WAS/WSA.PNG" height="auto" />

### FE & BE

<img src="https://github.com/BangYunseo/TIL/blob/main/Language/Web/Image/WAS/FB.PNG" height="auto" />

### Web Framework(WF)

- 웹 프레임워크(WF) or 웹 애플리케이션 프레임워크(WAF)
- 개발 표준 가이드를 정의한 스크립트 모음
  - 명명 규칙
  - 스크립트 작성 규칙
  - 디렉토리 구조
- 프레임워크의 일종
  - 동적인 웹 페이지
  - 웹 애플리케이션
  - 웹 서비스 개발 보조용 애플리케이션

#### 목적

- 웹 페이지 개발 과정에서 겪는 어려움을 줄이는 것

#### 기능

- 통상 데이터베이스 연동
- 템플릿 형태 표준
- 세션 관리
- 코드 재사용

#### Flask : Micro Framework (==Django Rest Framework)

- 최소한의 기능
- 추가 기능 설치
- 거의 모든 것을 설정 및 세팅
- 자유로운 커스터마징
- 약 27,000줄 밖에 안되는 가벼운 프레임워크
- 프로젝트마다 1개의 어플리케이션을 개발

#### Django - Full-stack Framework

- 많은 부분 포함
- 추가 기능 설치 가능
- 한 프로젝트 내 다양한 어플리케이션 존재

### 자바스크립트(JavaScript)

- 객체(object) 기반 스크립트 언어
- 웹 동작 구현
- 주로 웹 브라우저에서 사용
- Node.js
  - 서버 측 프로그래밍에서도 사용가능
- 대부분의 웹 브라우저에는 자바스크립트 인터프리터 내장
