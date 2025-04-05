# Chapter 0. Android 개요

> 1절. 프로젝트 생성
 

## 1절. 프로젝트 생성

### 초기 화면 설정

<img src="https://github.com/BangYunseo/TIL/blob/main/Android/Image/ch00/ch00-01-startPage.PNG" width="100%" height="auto" />

1) Name : 프로젝트 명

2) Package name : 패키지명, 프로젝트 명
- 앱의 식별값

3) Save location : 저장 위치
- 프로젝트의 파일들이 저장되는 루트 디렉토리

4) Language : 사용 언어
- 개발할 안드로이드의 사용 언어(Kotlin / Java 2가지 지원)

5) Minimum SDK : 최소 SDK
- 앱이 설치되는 최소 SDK 버전

6) Build configuration Language : 빌드 파일 종류
- build.gradle 파일의 타입 선택 부분
- 안드로이드 앱은 Gradle 툴에 의해 빌드
- 오랫동안 사용했던 build.gradle로 생성 가능
- Kotlin 형태인 build.gradle.kits로 생성 가능(권장)

### 화면 구성

<img src="https://github.com/BangYunseo/TIL/blob/main/Android/Image/ch00/ch00-02-logCat.PNG" width="100%" height="auto" />

1) 로그캣(Logcat)
- 앱이 실행중일 때 발생하는 로그 출력
- 앱에서 출력한 로그나 오류 메시지 등을 확인할 때 이용

### SDK 설정

|이름|용도|설치 여부|
|:---:|:---|:---|
|Android SDK Build-Tools 34|앱 빌드 시 필요 도구|필수 설치|
|Android Emulator|앱 실행 시 필요 도구|필수 설치|
|Android ASK Platform-Tools|안드로이드 플랫폼과 연동되는 adb, fastboot, systrace와 같은 도구 모음|필수 설치|
|Android Emulator hypervisor driver(installer)|AMD용 하이퍼바이저 드라이버|AMD CPU일 경우 설치|
|Intel x86 Emulator Accelerator(HAXM installer)|인텔 에뮬레이터 가속기|인텔 CPU라면 설치|

- AMD의 하이퍼바이저 드라이버나 인텔의 가속기인 HAXM 설치를 위해서 CPU가 가상화 기술을 지원하고 이를 활성화(BIOS)할 필요 존재

