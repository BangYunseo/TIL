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

|   함수 종류   | 설명                                      |
| :-----------: | :---------------------------------------- |
|  putExtra()   | 인텐트에 엑스트라 데이터를 추가하는 함수  |
| getIntExtra() | 데이터를 추가로 가져오는 인텐트 객체 함수 |

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

|     인텐트로 액티비티 시작하는 방법      |
| :--------------------------------------: |
| public void startActivity(Intent intent) |
|       ActivityResultLauncher(권장)       |

#### ActivityResultLauncher

<img src="https://github.com/BangYunseo/TIL/blob/main/Android/Image/ch06/ch08-04-ARL2.PNG" height="auto" />

- registerForActivityResult() 함수로 만드는 객체
- 함수의 매개 변수에 실제 작업자 Contract 객체와 결과를 처리하는 Callback 객체 등록

- Contract
  - ActivityResultLauncher로 실행될 요청을 처리하는 역할
  - ActivityResultContract를 상속받은 서브 클래스

|            종류            | 설명                                  |
| :------------------------: | :------------------------------------ |
|        PickContact         | 선택한 연락처 Uri 획득                |
|     RequestPermission      | 권한 요청 · 허락 여부 파악            |
| RequestMultiplePermissions | 여러 권한 동시 요청                   |
|   StartActivityForResult   | 인텐트 발생 · 액티비티 실행 결과 획득 |
|     TakePicturePreview     | 사진 촬영 후 비트맵 획득              |
|        TakePicture         | 사진 촬영·저장·비트맵 획득            |

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

| 태그 종류  | 설명                                 |
| :--------: | :----------------------------------- |
|  <action>  | 컴포넌트의 기능 표현 문자열          |
| <category> | 컴포넌트가 포함되는 범주 표현 문자열 |
|   <data>   | 컴포넌트에 필요한 데이터 정보        |

```xml
<!-- 자동 생성 메인 액티비티 -->

<activity android:name=".MainActivity"
  android:exported="true" >
  <intent-filter>
    <action android:name="android.intent.action.MAIN" />
    <category android:name="android.intent.category.LAUNCHER" />
  </intent-filter>
</activity>
```

```xml
<!-- 외부 앱과 연동하는 인텐트 필터 설정(메인 액티비티 X)-->

<activity
  android:name=".TwoActivity"
  android:exported="true" >
  <intent-filter>
    <action android:name="ACTION_EDIT" />
    <category android:name="android.intent.category.DEFAULT" />
    <data android:scheme="http" />
  </intent-filter>
</activity>
```

```kt
// 인텐트 프로퍼티 이용

val intent = Intent()
intent.action = "ACTION_EDIT"
intent.data = Uri.parse("http://www.google.com")
startActivity(intent)
```

```kt
// 인텐트 생성자 이용 방법

val intent = Intent("ACTION_EDIT", Uri.parse("http://www.google.com"))
startActivity(intent)
```

```xml
<!-- mineType 설정 -->

<activity android:name=".TwoActivity">
  <intent-filter>
    <action android:name="ACTION_EDIT" />
    <category android:name="android.intent.category.DEFAULT" />
    <data android:mineType="image/" />
  </intent-filter>
</activity>
```

```kt
// 타입 정보 설정

val intent = Intent("ACTION_EDIT")
intent.type = "image/*"
startActivity(intent)
```

- 실행할 컴포넌트 정보를 어떻게 설정하는가?

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

- 클래스 타입 레퍼런스 정보 활용 인텐트

<img src="https://github.com/BangYunseo/TIL/blob/main/Android/Image/ch06/ch08-05-EI.PNG" height="auto" />

#### 암시적 인텐트(Implicit Intent)

- 인텐트 필터 정보를 활용한 인텐트
- AndroidManifest.xml 파일에 선언된 인텐트 필터 사용

<img src="https://github.com/BangYunseo/TIL/blob/main/Android/Image/ch06/ch08-06-II.PNG" height="auto" />

### 액티비티 인텐트 동작 방식

| 액티비티 개수 | 시스템 처리                    |
| :-----------: | :----------------------------- |
|      0게      | 인텐트를 시작한 곳에 오류 발생 |
|      1개      | 문제없이 실행                  |
|      n개      | 사용자 선택으로 하나만 실행    |

```kt
// 해당 액티비티가 없는 경우 예외 처리
val intent = Intent("ACTION_HELLO")
try {
  startActivity(intent)
} catch (e: Exception) {
  Toast.makeText(this, "no application", Toast.LENGHT_SHORT).show()
}
```

```kt
// 액티비티가 여러 개인 경우

val intent = Intent(Intent.ACTION_VIEW, Uri.parse("geo:38.7749, 127.4194"))
startActivity(intent)
```

```kt
// 패키지 지정

val intent = Intent(Intent.ACTION_VIEW, Uri.parse("geo:37.7749, 127.4194"))
intent.setPackage("com.google.android.apps.maps")
startActivity(intent)
```

## 2절. 액티비티 생명주기

### 액티비티 상태

<img src="https://github.com/BangYunseo/TIL/blob/main/Android/Image/ch06/ch08-08-ALC.PNG" height="auto" />

- 생명 주기 : 액티비티의 생성 ~ 소멸 과정
- 액티비티 종료 : onDestroy()까지의 호출을 의미

<img src="https://github.com/BangYunseo/TIL/blob/main/Android/Image/ch06/ch08-09-ALC2.PNG" height="auto" />

#### 활성 상태

- 액티비티가 실행되어 화면에 나오고 사용자 이벤트 처리 가능 상태
- 처음 실행된 액티비티는 onCreate() → onStart() → onResume() 함수까지 호출

#### 일시 정지 상태

- 액티비티가 화면에 보이지만 포커스를 잃어 사용자 이벤트를 처리할 수 없는 상태
- onPause() 함수까지 호출된 상태

#### 비활성 상태

- 액티비티가 종료되지 않고 화면에만 보이지 않는 상태
- 활성 상태에서 비활성 상태가 되면 onPause() → onStop() 함수까지 호출

### 액티비티 상태 저장

<img src="https://github.com/BangYunseo/TIL/blob/main/Android/Image/ch06/ch08-10-ASS.PNG" height="auto" />

- 액티비티 종료 : 객체 소멸 -> 액티비티의 데이터 모두 소멸
- 상태 저장 : 액티비티 종료로 메모리 데이터가 사라져도 재실행 시 사용자가 저장한 데이터로 액티비티의 상태를 복원하겠다는 의미
- 화면 전환 : 액티비티 종료 후 출력 -> 즉, 액티비티의 데이터 초기화

#### Bundle

- 액티비티 종료 후 저장했다가 복원할 데이터가 있는 경우 이용하는 객체

```kt
// 번들 객체 사용 예시

override fun onCreate(savedInstanceState: Bundle?){
  super.onCreate(savedInstanceState)
}

override fun onRestoreInstanceState(savedInstanceState: Bundle){
  super.onRestoreInstanceState(savedInstanceState)
}

override fun onSavedInstanceState(outState: Bundle?){
  super.onSavedInstanceState(outState)
}
```

- Bundle에 데이터를 담으면 자동으로 데이터를 파일로 저장

```kt
// 번들에 데이터 저장

override fun onSaveInstanceState(outState: Bundle) {
  super.onSaveInstanceState(outState)
  outState.putSpring("data1", "hello")
  outState.putInt("data2", 10)
}
```

- 액티비티가 다시 생성되어 실행될 때 캐싱파일이 있으면 그 내용을 번들 객체에 담아 onCreate(), onRestoreInstanceState() 함수의 매개 변수로 전달

```kt
// 번들에 저장된 데이터 반환

override fun onRestoreInstanceState(savedInstanceSttate: Bundle){
  super.onRestoreInstanceState(savedInstanceSttate)
  val data1 = savedInstanceState.getString("data1")
  val data2 = savedInstanceState.getInt("data2")
}
```

## 3절. 액티비티 ANR 문제

### ANR 문제

<img src="https://github.com/BangYunseo/TIL/blob/main/Android/Image/ch06/ch08-11-Thread.PNG" height="auto" />

- 액티비티가 응답하지 않는 오류 상황
- 메인 스레드 : 시스템에서 액티비티를 실행하는 수행 흐름
- UI 스레드 : 화면을 출력하는 수행 흐름

### 해결 방법 (1) : 개발자 스레드 분리

- 액티비티를 실행한 메인 스레드 외의 실행 흐름(개발자 스레드)을 따로 생성 후 시간이 오래 걸리는 작업 담당
- 이 방법으로 대체할 경우 ANR 오류는 해결되지만 화면을 변경할 수 없다는 문제 발생

<img src="https://github.com/BangYunseo/TIL/blob/main/Android/Image/ch06/ch08-12-Thread2.PNG" height="auto" />

## 4절. 코루틴

### 해결 방법 (2) : 코루틴

#### 코루틴

- 비동기 경량 스레드
- 프로그래밍 언어에서 제공하는 기능

|              장점               |
| :-----------------------------: |
|              경량               |
|        적은 메모리 누수         |
|    취소 등 다양한 기능 지원     |
| 많은 제트팩 라이브러리에서 적용 |

### 안드로이드에서의 코루틴 이용

```kt
// 코루틴 등록

implementation("org.jetbrains.kotlin:kotlinx-coroutines-android:1.7.3")
```

### ANR 오류 발생 코드

```kt
// 오랜 시간 소모 작업 예시

var sum = 0L
var time = measureTimeMillis{
  for(i in 1..2_000_000_000){
    sum += i
  }
}

Log.d("Yunseo", "time : $time")
binding.resultView.text = "sum : $sum"
```

<img src="https://github.com/BangYunseo/TIL/blob/main/Android/Image/ch06/ch08-13-Kolutine.PNG" height="auto" />

- ANR 오류 해결을 위한 스레드-핸들러 구조

```kt
// 스레드 - 핸들러 구조 코드

val handler = object:Handler() {
  override fun handleMessage(msg: Message){
    super.handleMessage(msg)
    binding.resultView.text = "sum : ${msg.arg1}"
  }
}

thread{
  var sum = 0L
  var time = measureTimeMillis {
    for(i in 1..2_000_000_000) {
      sum += i
    }
    val message = Message()
    message.arg1 = sum.toInt()
    handler.sendMessage(message)
  }
  Log.d("Yunseo", "time : $time")
}
```

### 코드의 코루틴화

- 코루틴 구등을 위해서 스코프 준비
- 스코프에서 코루틴 구동

#### 코루틴 스코프

- CoroutineScope를 구현한 클래스 객체
- 직접 구현 가능
- 코틀린 언어 제공 스코프 이용

| 코틀린 제공 스코프 종류 |
| :---------------------: |
|       GlobalScope       |
|       ActorScope        |
|      ProducerScope      |

```kt
// 코루틴 코드

// 백그라운드에서 동작(시간이 오래 걸리는 작업)
val channel = Channel<Int>()
val backgroundScope = CoroutineScope(Dispatchers.Default + Job())
backgroundScope.launch {
  var sum = 0L
  var time = measureTimeMillis {
    for(i in 1..2_000_000_000) {
      sum += i
    }
  }

  Log.d("Yunseo", "time : $time")
  channel.send(sum.toInt())
}

// 메인 스레드에서 동작(화면에 결괏값 표시)
val mainScope = GlobalScope.launch(Dispatchers.Main) {
  channel.consumeEach {
    binding.resultView.text = "sum : $it"
  }
}
```

### Dispatcher

- 스코프에서 구동한 코루틴이 어디에서 동작해야 하는지 표시

|        종류         | 설명                                            |
| :-----------------: | :---------------------------------------------- |
|  Dispatchers.Main   | 액티비티의 메인 스레드에서 동작하는 코루틴 생성 |
|   Dispatchers.IO    | 파일에 읽기·쓰기 또는 네트워크 작업 등에 최적화 |
| Dispatchers.Default | CPU를 많이 사용하는 작업을 백그라운드에서 실행  |

## 5장. ToDoList 앱 구현

### 1) 모듈 생성 & 빌드 그래들 설정

- Ch13_Activity 모듈 생성
- 뷰 바인딩 사용 설정

```kts
viewBinding.isEnabled = true
```

### 2) 할 일 등록 액티비티 생성

- New → Activity → Empty Activity → 액티비티 이름에 AddActivity 입력

### 3) 리소스 & 소스 파일 복사

- res 디렉터리 아래에 drawable, layout, menu 디렉터리를 현재 모듈의 res 디렉터리로 복사
- 소스가 든 디렉터리에서 AddActivity.kt, Main Activity.kt, MyAdapter.kt 파일을 현재 모듈의 소스 영역에 복사

### 4) 할 일 등록 액티비티 작성

- AddActivity.kt 파일을 열어 내용을 추가

### 5) 메인 액티비티 작성

- MainActivity.kt 파일을 열고 내용을 추가

### 6) 앱 실행

[프로젝트 바로가기](https://github.com/BangYunseo/AndroidProject/tree/main/ch09)
