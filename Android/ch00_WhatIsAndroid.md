# Chapter 0. Android 개요

> '깡샘의 안드로이드 앱 프로그래밍 with 코틀린' 1 ~ 2장 학습 내용
>
> 1절. 프로젝트 생성
>
> 2절. 안드로이드
>
> 3절. 안드로이드 앱 구성 파일 분석


## 1절. 프로젝트 생성

### 초기 화면 설정

<img src="https://github.com/BangYunseo/TIL/blob/main/Android/Image/ch00/ch00-01-startPage.PNG" width="100%" height="auto" />

1) Name : 프로젝트 명

2) Package name : 패키지명, 프로젝트 명
    - 앱의 식별값

3) Save location : 저장 위치
    - 프로젝트의 파일들이 저장되는 루트 디렉토리

4) Language : 사용 언어
    - 개발할 안드로이드의 사용 언어
        - Kotlin
        - Java

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

## 2절. 안드로이드

### 특징

- 공개 운영체제 리눅스 기반 개발
- Kotlin이나 Java 언어를 통한 개발
- 운영체제의 주요 부분과 라이브러리, 구글에서 만든 앱 등의 코드는 대부분 공개
- 안드로이드 스마트폰은 구글 뿐만 아니라 여러 제조업체에서 생산 가능
- 앱은 구글의 플레이 스토어 뿐만 아니라 다양한 방법으로 사용자에게 배포 가능
- 플랫폼에서는 모든 응용 프로그램이 평등하다는 사상 탑재
- 모바일에 기본으로 탑재된 앱과 개발자가 만든 앱이 똑같은 환경에서 같은 API 이용

### 구조

<img src="https://github.com/BangYunseo/TIL/blob/main/Android/Image/ch00/ch00-03-androidStructure.PNG" width="100%" height="auto" />

- 리눅스 커널(Linux Kernel) : 안드로이드는 리눅스에 기반을 둔 오픈소스 소프트웨어 스택
- 안드로이드 런타임(Android Runtime) : ART라고 불리며 앱 실행 역할
- 자바 API 프레임워크 : 앱 개발 시 사용하는 자바 API 

### 실행 과정

<img src="https://github.com/BangYunseo/TIL/blob/main/Android/Image/ch00/ch00-04-dex.PNG" width="100%" height="auto" />

- 안드로이드는 자바 클래스를 런타임 때 그대로 실행 X
- DEX 파일로 컴파일
- DEX 파일을 해석하는 ARTAndroid Runtime에서 실행

### 안드로이드 버전

- 안드로이드 버전 : 13.0, 14.0과 같이 운영체제 버전 의미
- 앱 개발 시 사용하는 버전 : API 레벨(SDK 버전)

|버전|코드명|API 레벨|출시 연도|
|:---|:---:|:---:|:---:|
|Android 5.X|Lollipop|21 ~ 22|2014|
|Android 6.X|Marshmallow|23|2015|
|Android 7.X|Nougat|24 ~ 25|2016|
|Android 8.X|Oreo|26 ~ 27| 2017|
|Android 9.0|Pie|28|2018|
|Android 10.0|-|29|2019|
|Android 11.0|-|30|2020|
|Android 12.0|-|31|2021|
|Android 13.0|Tiramisu|33|2022|
|Android 14.0|UpsideDownCake|34|2023|

### 안드로이드의 컴포넌트

<img src="https://github.com/BangYunseo/TIL/blob/main/Android/Image/ch00/ch00-05-component.PNG" width="100%" height="auto" />

- 컴포넌트는 애플리케이션의 구성 요소
- 안드로이드 개발 진행 시 클래스로 컴포넌트 개발

#### 컴포넌트 종류

1) Activity(액티비티) : 화면 구성 컴포넌트
2) Service(서비스) : 백그라운드 작업 컴포넌트
3) ContentProvider(콘텐츠 프로바이더) : 앱의 데이터 공유 컴포넌트
4) BroadcastReceiver(브로드캐스트 리시버) : System Event 발생 시 실행 컴포넌트

#### 컴포넌트 구분 방법

- 개발자가 컴포넌트 클래스 생성 시 지정된 클래스를 상속받음 : 상위 클래스로 구분
- 종류의 영문으로 된 클래스를 상속


#### 앱 개발의 컴포넌트 특징

1) 앱의 기능, 화면 등을 고려해 필요한 만큼 구성

<img src="https://github.com/BangYunseo/TIL/blob/main/Android/Image/ch00/ch00-07-howComponent.PNG" width="100%" height="auto" />

2) 컴포넌트는 앱 안에서 독립된 실행 단위

<img src="https://github.com/BangYunseo/TIL/blob/main/Android/Image/ch00/ch00-08-componentSeparate.PNG" width="100%" height="auto" />

    - 컴포넌트끼리 서로 종속되지 않아 코드 결합 발생 X

3) 앱 실행 시점의 다양성

<img src="https://github.com/BangYunseo/TIL/blob/main/Android/Image/ch00/ch00-09-manyView.PNG" width="100%" height="auto" />

    - 컴포넌트가 앱 내에서 독립해서 실행되는 특징으로 실행 시점이 다양
    - 안드로이드 앱에는 <bold>메인 함수(main function)</bold>의 개념이 존재 X

4) 애플리케이션 라이브러리 사용 가능

<img src="https://github.com/BangYunseo/TIL/blob/main/Android/Image/ch00/ch00-10-appLibrary.PNG" width="100%" height="auto" />

    - 다른 애플리케이션을 라이브러리처럼 이용 가능

### 안드로이드 앱의 클래스

<img src="https://github.com/BangYunseo/TIL/blob/main/Android/Image/ch00/ch00-06-classComponent.PNG" width="100%" height="auto" />

- 앱은 컴포넌트 클래스와 일반 클래스로 구분
    - 일반 클래스 : 클래스의 객체 생성 ~ 소멸까지 생명 주기 관리를 개발자 코드에서 진행
    - 컴포넌트 클래스 : 생명 주기를 안드로이드 시스템에서 관리

### 리소스 활용 개발

- Resource(리소스) : 코드에서 정적인 값을 분리한 것
- 문자열 이외에 색상, 크기, 레이아웃, 이미지, 메뉴 등 많은 요소 활용 가능
- 이미지 등을 제외하면 대부분의 리소스는 XML 파일로 작성

```xml
<string name = "mytxt">
    동해 물과 백두산이 마르고 닳도록
    하느님이 보우하사 우리나라 만세!
    무궁화 삼천리 화려 강산
    대한 사람, 대한으로 길이 보전하세
</string>
```

```kotlin
textView.text = resources.getString(R.string.mytxt)
```

## 3절. 안드로이드 앱 구성 파일 분석

### 프로젝트 폴더 구성

<img src="https://github.com/BangYunseo/TIL/blob/main/Android/Image/ch00/ch00-11-projectFolder.PNG" width="100%" height="auto" />

- 프로젝트 폴더 : [모듈명 -> src -> main]

### 모듈 폴더 구성

|이름|설명|
|:---|:---|
|build.gradle.kts|빌드 설정 파일|
|AndroidManifest.xml|앱의 메인 환경 파일|
|res|리소스 폴더|
|activity_main.xml|레이아웃 XML 파일|
|MainActivity.kt|메인 액티비티 파일|

1) gradle(그래들) 빌드 설정 파일

    - 안드로이드 앱의 빌드 도구
    - gradle 설정 파일 : build.gradle.kts
        - 프로젝트 수준의 build.gradle.kts(Project : AndroidLab)
        - 모듈 수준의 build.gradle.kts(Module : AndroidLab.app)

```kts
// 플러그인 선언
plugins {
    alias(libs.plugins.androidApplication)
    alias(libs.plugins.jetbrainKotlinAndroid)
}
```

```kts
// 앱의 식별자 설정
applicationId = "com.example.androidlab"
```
    
- targetSdk : 개발할 때 적용되는 SDK 버전
- minSdk : 앱을 설치할 수 있는 기기의 최소 SDK 버전

```kts
// SDK 버전 설정
minSdk = 24
targetSdk = 34
```

```kts
// 앱의 버전 설정
versionCode = 1
versionName = "1.0"
```

- targetSdkk에 명시한 안드로이드 SDK는 기본으로 적용
- 개발자가 추가하는 오픈소스 라이브러리나 androidx 라이브러리 등 SDK 라이브러리가 아닌 것들은 모두 dependencies에 선언

```kts
// 라이브러리 설정
dependencies {
    implementation(libs.androidx.core.ktx)
    implementation(libs.androidx.appcompat)
    implementation(libs.material)
    implementation(libs.androidx.activity)
    implementation(libs.androidx.constraintlayout)
    testImplementation(libs.junit)
    androidTestImplementation(libs.androidx.junit)
    androidTestImplementation(libs.androidx.espresso.core)
}
```

2) 메인 환경 파일

    - 안드로이드 앱의 메인 환경 파일 : AndroidManifest.xml
    - URL이 http://schemas.android.com/apk/res/android 로 선언되었다면 안드로이드 표준 네임 스페이스

```xml
<!--> 네임 스페이스 선언<!-->
<manifest xmlns:android="http://schemas.android.com/apk/res/android"
    xmlns:tools="http://schemas.android.com/tools">
```

    - <application> 태그는 앱 전체를 대상으로 한 설정
    - icon 속성 : 지정한 이미지가 앱을 설치한 사용자의 폰에 보이는 실행 아이콘
    - lable 속성 : 앱의 이름 등록
    - theme 속성 : 앱에 적용하는 테마 설정

```xml
<!-->네임 스페이스 선언<!-->
<application
    android:allowBackup="true"
    android:dataExtractionRules="@xml/data_extraction_rules"
    android:fullBackupContent="@xml/backup_rules"
    android:icon="@mipmap/ic_launcher"
    android:label="@string/app_name"
    android:roundIcon="@mipmap/ic_launcher_round"
    android:supportsRtl="true"
    android:theme="@style/Theme.Ch00_firstApplication"
    tools:targetApi="31">
    <!--> ...생략... <!-->
</application>
```

- 액티비티 : <activity> 태그
- 서비스 : <service> 태그
- 브로드캐스트 리시버 : <receiver> 태그
- 콘텐츠 프로바이더 : <provider> 태그
- name 속성 : 클래스 이름 등록
    
- <intent-filter> 가 선언되고 안에 <action> 태그의 name 속성값이 android.intent.action.MAIN 문자열로, <category> 태그의 name 속성값이 android.intent.category.LAUNCHER로 선언되었으므로 이 액티비티는 앱 아이콘 클릭 시 실행되는 액티비티


```xml
<!-->네임 스페이스 선언<!-->
<activity
    android:name=".MainActivity"
    android:exported="true">
    <intent-filter>
        <action android:name="android.intent.action.MAIN" />
        <category android:name="android.intent.category.LAUNCHER" />
    </intent-filter>
</activity>
```

3) 리소스 폴더

<img src="https://github.com/BangYunseo/TIL/blob/main/Android/Image/ch00/ch00-12-res.PNG" width="100%" height="auto" />

- drawble : 이미지 리소스
- layout : UI 구성에 필요한 XML 리소스
- mipmap : 앱 아이콘 이미지
- values : 문자열 등의 값으로 이용되는 리소스

 - 리소스를 식별하기 위한 int형 변수가 R.java 파일에 등록
- res/layout/test.xml 파일인 경우, R.layout.test

- res 하위의 폴더명은 지정된 폴더명 사용 필수
- 각 리소스 폴더에 다시 하위 폴더 정의 불가
- 리소스 파일명
    - 자바의 이름 규칙 위배 불가
    - 알파벳 대문자 이용 불가 

4) 레이아웃 XML 파일

    - 화면을 구성하는 레이아웃 XML 파일

```XML
<!-->레이아웃 XML 파일<!-->
<?xml version="1.0" encoding="utf-8"?>
<androidx.constraintlayout.widget.ConstraintLayout xmlns:android="http://schemas.android.com/apk/res/android"
    xmlns:app="http://schemas.android.com/apk/res-auto"
    xmlns:tools="http://schemas.android.com/tools"
    android:id="@+id/main"
    android:layout_width="match_parent"
    android:layout_height="match_parent"
    tools:context=".MainActivity">

    <TextView
        android:layout_width="wrap_content"
        android:layout_height="wrap_content"
        android:text="Hello World!"
        app:layout_constraintBottom_toBottomOf="parent"
        app:layout_constraintEnd_toEndOf="parent"
        app:layout_constraintStart_toStartOf="parent"
        app:layout_constraintTop_toTopOf="parent" />

</androidx.constraintlayout.widget.ConstraintLayout>
```

5) 메인 액티비티 파일

    - setContentView() 함수 : 매개 변수에 지정한 내용을 액티비티 화면에 출력
    - R.layout.activity_main 지정 : res/layout/activity_main.xml 파일의 구성 내용 화면에 출력
    - enableEdgeToEdge() : 액티비티 화면이 상단의 배터리 표시가 있는 영역(Status Bar)과 하단의 안드로이드 버튼이 있는 영역(Navigation Bar)까지 나오게 하는 설정
    - setOnApplyWindowInsetsListener() : 액티비티에 출력되는 내용이 Navigation Bar 등과 겹치지 않게 하기 위한 설정

```kotlin
class MainActivity : AppCompatActivity() {
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        enableEdgeToEdge()
        setContentView(R.layout.activity_main)
        ViewCompat.setOnApplyWindowInsetsListener(findViewById(R.id.main)) { v, insets ->
            val systemBars = insets.getInsets(WindowInsetsCompat.Type.systemBars())
            v.setPadding(systemBars.left, systemBars.top, systemBars.right, systemBars.bottom)
            insets
        }
    }
}
```