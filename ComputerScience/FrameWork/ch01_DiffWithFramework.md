# chapter 1. Framework와의 차이점(API, 라이브러리).md

> [참고자료](https://velog.io/@bcl0206/API-vs-%EB%9D%BC%EC%9D%B4%EB%B8%8C%EB%9F%AC%EB%A6%AC-%ED%92%80%EB%A6%AC%EC%A7%80-%EC%95%8A%EB%8A%94-%EB%AF%B8%EC%8A%A4%ED%84%B0%EB%A6%AC%EC%97%90-%EA%B4%80%ED%95%98%EC%97%AC)
>
> 1절. 개념 비교
>
> 2절. 예시 비교
>
> 3절. 프레임워크 종류 및 동작 방식

## 1절. 개념 비교

### API(Application Programming Interface)

- 두 개 이상의 Software Component 사이에서 상호작용할 수 있도록 정의된 Interface
- 일반적으로 Method, Protocol, Class로 구성
- 다른 소프트웨어 개발자들이 이를 통해 특정 서비스 또는 기능 구현 가능
  
### 라이브러리(Library)

- 개발자들이 자주 사용하는 코드 집합
- 여러 기능 제공
- 복잡한 기능을 더 쉽게 구현 가능
- 여러 개발자가 공유하여 사용할 수 있는 소프트웨어 코드 집합

### Framework

- 개발자들이 Application 개발 시 사용되는 구조 제공
- 일련의 규칙과 구조 정의
- 개발자가 Application 작성 시 규칙과 구조를 따라야 함
- 여러 컴포넌트와 라이브러리 포함
- 특정 기능 구현을 위해 조합하여 사용

### 정리

|API|라이브러리|Framework|
|:---:|:---:|:----:|
|Software Component 간의 인터페이스 정의|개발자들이 자주 사용하는 코드 집합|Application 개발 시 사용되는 구조 제공|


## 2절. 예시 비교

### API 예시

|종류|설명|
|:--:|:---|
|Twitter API|트위터에서 제공하는 API|
|Google Maps API|구글에서 제공하는 지도 API|
|YouTube API|유튜브에서 제공하는 API|
|OpenWeather API|날씨 정보 API|
|GitHub API|깃허브에서 제공하는 API|
|Kakao API|카카오에서 제공하는 API|
|Stripe API|결제 API|
|Twilio API|SMS 및 음성 API|
|AWS API Gateway|아마존 웹 서비스에서 제공하는 API 관리 서비스|
|Google Cloud Vision API|구글에서 제공하는 이미지 분석 API|

### 라이브러리 예시

|종류|설명|
|:--:|:---|
|Lodash|자바스크립트 유틸리티 라이브러리|
|jQuery|자바스크립트 DOM 조작 라이브러리|
|React Transition Group|React 애니메이션 라이브러리|
|Moment.js|자바스크립트 날짜 라이브러리|
|Chart.js|자바스크립트 차트 라이브러리|
|Axios|자바스크립트 HTTP 클라이언트 라이브러리|
|NumPy|파이썬 수치 계산 라이브러리|
|Pandas|파이썬 데이터 분석 라이브러리|
|Matplotlib|파이썬 시각화 라이브러리|
|BeautifulSoup|파이썬 웹 스크래핑 라이브러리|

### Framework 예시

|종류|설명|
|:--:|:---|
|React|자바스크립트 UI 프레임워크 (공식사이트에서는 라이브러리 라고 말함)|
|Angular|자바스크립트 프레임워크|
|Vue.js|자바스크립트 프론트엔드 프레임워크|
|Django|파이썬 백엔드 웹 프레임워크|
|Ruby on Rails|루비 웹 프레임워크|
|Spring|자바 백엔드 프레임워크|
|Express.js|Node.js 웹 프레임워크|
|Flask|파이썬 백엔드 웹 프레임워크|
|Laravel|PHP 웹 프레임워크|
|ASP.NET|마이크로소프트 웹 프레임워크

## 3절. 패키지와 모듈

### 모듈(Module)

- 소프트웨어의 작은 부분
- 특정 기능을 수행하는 코드 집합
- 파일 하나에 작성 가능
- 다른 모듈에서 재사용 가능
- 라이브러리 or Framework는 모듈들의 집합으로 구성

### 패키지

- 관련된 모듈들을 그룹핑하는 방법
- 소프트웨어에서는 기능별로 모듈을 작성하고 모듈들을 관련된 패키지에 포함
- 패키지 사용 시 모듈들을 조직적으로 관리 가능
- 다른 개발자들과의 코드 공유에 용이
