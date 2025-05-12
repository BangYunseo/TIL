# Chapter 8. 액티비티 컴포넌트

> '깡샘의 안드로이드 앱 프로그래밍 with 코틀린' 13장 학습 내용
>
> 1절. 인텐트
>
> 2절. 액티비티 생명주기
>
> 3절. 액티비티 ANR 문제
>
> 4절. 코루틴
>
> 5장. ToDoList 앱 구현
> [프로젝트 바로가기](https://github.com/BangYunseo/AndroidProject/tree/main/ch09)

## 1절. 인텐트

### 개념

- 컴포넌트 실행을 위해 시스템에 전달하는 메시지
- Android 컴포넌트 클래스
  - 개발자가 코드에서 직접 생성 후 실행 불가
  - 시스템에서 인텐트 정보 분석 후 맞춤형 컴포넌트 실행
  - 외부 앱 컴포넌트와 연동할 경우에도 마찬가지

<img src="https://github.com/BangYunseo/TIL/blob/main/Android/Image/ch06/ch08-01-Intent.PNG" height="auto" />

- startActivity() : 인텐트를 시스템에 전달
- Intent 생성자 매개변수 : 클래스 타입 레퍼런스 정보

(여기부터 작성 : pdf 13장 4p 코드부터 작성)

```xml
<!-- MainActivity의 DetailActivity 등록 -->

```

```kt
// 인텐트를 시스템에 전달

```

## 2절. 액티비티 생명주기

## 3절. 액티비티 ANR 문제

## 4절. 코루틴

## 5장. ToDoList 앱 구현

### 1) 모듈 생성 & 빌드 그래들 설정

[프로젝트 바로가기](https://github.com/BangYunseo/AndroidProject/tree/main/ch09)
