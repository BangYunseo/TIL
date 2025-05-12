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

```xml
<!-- MainActivity의 DetailActivity 등록 -->

<activity
  android:name=".DetailActivity"
  android:exported="true" />
<activity
  android:name="MainActivity"
  android:exported="true" >
  <intent-filter>
    <action android:name="android.intent.action.MAIN" />
    <category android:name="android.intent.category.LAUNCHER" />
  </intent-filter>
</activity>
```

```kt
// 인텐트를 시스템에 전달

val intent: Intent = Intent(this, DetailActivity::class.java)
startActivity(intent)
```

### 인텐트 엑스트라 데이터

<img src="https://github.com/BangYunseo/TIL/blob/main/Android/Image/ch06/ch08-02-IntentExtraData.PNG" height="auto" />

- 인텐트에 담는 부가 정보
- 인텐트에 컴포넌트 실행 요청 시 데이터를 함께 전송하려고 할 경우 이용

|함수 종류|설명|
|:---:|:--|
|putExtra()|인텐트에 엑스트라 데이터를 추가하는 함수|
|getIntExtra()|데이터를 추가로 가져오는 인텐트 객체 함수|

```kt
// 엑스트라 데이터 추가

val intent: Intent = Intent(this, DetailActivity::class.java)
intent.putExtra("data1", "hello")
intent.putExtra("data2", 10)
startActivity(intent)
```

```kt
// 엑스트라 데이터 반환

val data1 = intent.getStringExtra("data1")
val data2 = intent.getIntExtra("data2", 0)
```

### 액티비티 화면 전환

<img src="https://github.com/BangYunseo/TIL/blob/main/Android/Image/ch06/ch08-03-ARL.PNG" height="auto" />

|인텐트로 액티비티 시작하는 방법|
|:---:|
|public void startActivity(Intent intent)|
|ActivityResultLauncher(권장)|

#### ActivityResultLauncher

<img src="https://github.com/BangYunseo/TIL/blob/main/Android/Image/ch06/ch08-04-ARL2.PNG" height="auto" />

- registerForActivityResult() 함수로 만드는 객체
- 함수의 매개 변수에 실제 작업자 Contract 객체와 결과를 처리하는 Callback 객체 등록

- Contract
  - ActivityResultLauncher로 실행될 요청을 처리하는 역할
  - ActivityResultContract를 상속받은 서브 클래스
 
|종류|설명|
|:---:|:---|
|PickContact|선택한 연락처 Uri 획득|
|RequestPermission|권한 요청 · 허락 여부 파악|
|RequestMultiplePermissions|여러 권한 동시 요청|
|StartActivityForResult|인텐트 발생 · 액티비티 실행 결과 획득|
|TakePicturePreview|사진 촬영 후 비트맵 획득|
|TakePicture|사진 촬영·저장·비트맵 획득|

- launch
  - 함수 호출 시 ActivityResultLauncher에 등록된 Contract 객체 실행
 
```kt
// ActivityResultLauncher 생성

val requestLauncher: ActivityResultLauncher<Intent> = registerForActivityResult(
  ActivityResultContracts.StartActivityForResult())
  // Contract
  {
    // Callback
    val resultData = it.data?.getStringExtra("result")
    binding.mainResultView.text = "result : $resultData"
  }
```

```kt
// ActivityResultLauncher 실행

val intent: Intent = Intent(this, DetailActivity::class.java)
requestLauncher.launch(intent)
```

- finish() : 자동 화면(결과) 전환할 경우 이용하는 함수

```kt
// 결과 · 화면 전환

intent.putExtra("resultData", "world")
setResult(RESULT_OK, intent)
finish()
```

### 인텐트 필터

- 하위 태그 정보 설정

<img src="https://github.com/BangYunseo/TIL/blob/main/Android/Image/ch06/ch08-07-BF.PNG" height="auto" />

|태그 종류|설명|
|:---:|:---|
|<action>|컴포넌트의 기능 표현 문자열|
|<category>|컴포넌트가 포함되는 범주 표현 문자열|
|<data>|컴포넌트에 필요한 데이터 정보|

```xml
<!-- 자동 생성 메인 액티비티 -->

<activity android:name=".MainActivity" />
  android:exported="true" >
  <intent-filter>
    <action android:name="android.intent.action.MAIN" />
    <category android:name="android.intent.category.LAUNCHER" />
  </intent-filter>
</activity>
```

(여기에 코드삽입 필요)

- 실행할 컴포넌트 정보를 어떻게 설정하는가?

|종류|설명|
|:---:|:---|
|명시적 인텐트|클래스 타입 레퍼런스 정보 활용 인텐트|
|암시적 인텐트|인텐트 필터 정보를 활용한 인텐트<br>AndroidManifest.xml 파일에 선언된 인텐트 필터 사용|

```xml
<!-- 암시적·명시적 인텐트 -->

<activity android:name=".OneActivity" />
<activity
  android:name=".TwoActivity"
  android:exported="true" >
  <intent-filter>
    <action android:name="ACTION_EDIT" />
    <category android:name="android.intent.category.DEFAULT" />
  </intent-filter>
</activity>
```

#### 명시적 인텐트(Explicit Intent)

<img src="https://github.com/BangYunseo/TIL/blob/main/Android/Image/ch06/ch08-05-EI.PNG" height="auto" />

#### 암시적 인텐트(Implicit Intent)

<img src="https://github.com/BangYunseo/TIL/blob/main/Android/Image/ch06/ch08-06-II.PNG" height="auto" />

## 2절. 액티비티 생명주기

## 3절. 액티비티 ANR 문제

## 4절. 코루틴

## 5장. ToDoList 앱 구현

### 1) 모듈 생성 & 빌드 그래들 설정

[프로젝트 바로가기](https://github.com/BangYunseo/AndroidProject/tree/main/ch09)
