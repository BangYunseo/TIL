# Chapter 6. 제트팩 라이브러리

> '깡샘의 안드로이드 앱 프로그래밍 with 코틀린' 11장 학습 내용
>
> 0절. ART
>
> 1절. 제트팩
>
> 2절. androidx
>
> 3절. appcompat 라이브러리
>
> 4절. 프래그먼트
>
> 5절. 리사이클러 뷰
>
> 6절. 뷰 페이저2
>
> 7절. 드로어 레이아웃
>
> 8장. 제트팩 화면 구성
> [프로젝트 바로가기](https://github.com/BangYunseo/AndroidProject/tree/main/ch07)

## 0절. ART

### 플랫폼 API

- ART에서 제공하는 안드로이드 라이브러리

<img src="https://github.com/BangYunseo/TIL/blob/main/Android/Image/ch06/ch06-01-JavaAPI.PNG" height="auto" />

## 1절. 제트팩

### 제트팩(JetPack)

- 구글에서 안드로이드 앱 개발용으로 제공하는 다양한 라이브러리
- androidx로 시작하는 패키지명
  - 앱을 개발 시 필요 권장 아키텍처 제공
  - API 레벨 호환성 문제 해결
  - 플랫폼 API에서 제공하지 않는 다양한 기능 제공

## 2절. androidx

### androidx 라이브러리

- 화면 구성과 관련된 라이브러리

|    라이브러리 종류    | 설명                             |
| :-------------------: | :------------------------------- |
|  androidx.appcompat   | 앱 API 레벨 호환성 해결          |
| androidx.recyclerview | 목록 화면 구성                   |
|  androidx.viewpager2  | 스와이프로 넘기는 화면 구성      |
|   androidx.fragment   | 액티비티처럼 동작하는 뷰 제공    |
| androidx.drawerlayout | 옆에서 서랍처럼 열리는 화면 구성 |

## 3절. appcompat 라이브러리

### appcompat 라이브러리

- 안드로이드 앱 화면 구성 액티비티 생성
- API 레벨 호환성 문제 해결

```kt
// appcompat 라이브러리 선언
implementation(lib.androidx.appcompat)

```

## 4절. 프래그먼트

## 5절. 리사이클러 뷰

## 6절. 뷰 페이저2

## 7절. 드로어 레이아웃

## 8장. 제트팩 화면 구성

### 1) 새 모듈 생성

- Ch11_JetPack 이름의 새 모듈 생성

### 2) 빌드 그래들 작성

- 뷰 바인딩 설정

### 3) 문자열 리소스 생성

- res/values/strings.xml 파일에 ActionBarDrawerToggle 생성 시 지정할 문자열 리소스 추가

```xml

```
