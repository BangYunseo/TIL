# Chapter 5. 다이얼로그와 알림

> '깡샘의 안드로이드 앱 프로그래밍 with 코틀린' 10장 학습 내용
>
> 1절. API 레벨 호환성 고려
>
> 2절. Permission 설정
>
> 3절. 다양한 다이얼로그
>
> 4절. 소리와 진동 알림
>
> 5절. 알림 띄우기
>
> 6절. 카카오톡 알림 만들기

(사진은 전부 다시 올리기)

## 1절. API 레벨 호환성 고려

### API 레벨 호환성

- 앱은 34 버전의 API로 개발
- 24 버전 기기에서도 오류가 발생하지 않고 동작해야 함
  - minSdk 설정값보다 상위 버전에서 제공하는 API를 사용할 경우 호환성을 고려

<img src="https://github.com/BangYunseo/TIL/blob/main/Android/Image/ch09/ch09-01-package.PNG" width="100%" height="auto" />

<img src="https://github.com/BangYunseo/TIL/blob/main/Android/Image/ch09/ch09-01-package.PNG" width="100%" height="auto" />

<img src="https://github.com/BangYunseo/TIL/blob/main/Android/Image/ch09/ch09-01-package.PNG" width="100%" height="auto" />

- @RequiresApi 애너테이션, @TargetApi 애너테이션을 이용
  - 안드로이드 스튜디오에서 오류를 무시 설정
  - 단순히 무시만 하는 것이므로 코드로의 설정 필요
 
- API 레벨 호환성 문제를 막으려면 직접 코드로 처리

```kt
// API 레벨 30 이상에서만 addCallback() 함수 실행

if(Build.VERSION.SDK_INT >= Build.VERSION_CODES.S){
  val builder: Notification.Builder = Notification.Builder(this, "1")
    .setStyle(
      Notification.CallStyle.forIncomingCall(caller, delineIntent, answerIntent)
    )
} else {
  // 이전 버전 그대로 처리한다는 코드 필요
}
```

## 2절. Permission 설정

### 퍼미션 설정과 사용 설정

- A 앱의 컴포넌트를 B 앱에서 사용하는 상황
  - 만약 A 앱의 컴포넌트에 Permission 설정 시 B 앱에서 연동할 때 문제 발생
 
<img src="https://github.com/BangYunseo/TIL/blob/main/Android/Image/ch09/ch09-01-package.PNG" width="100%" height="auto" />

- <permission> 태그 : 기능을 보호하려는 앱의 매니페스트 파일에 설정
- <uses-permission> 태그 : 퍼미션으로 보호된 기능을 사용하려는 앱의 매니페스트 파일에 설정

<img src="https://github.com/BangYunseo/TIL/blob/main/Android/Image/ch09/ch09-01-package.PNG" width="100%" height="auto" />

#### <permission> 속성

- name : permission의 이름
- label, description : permission 설명
- protectionLevel : 보호 수준

|보호 수준 종류|보호 수준 설명|
|:---:|:---|
|normal|낮은 수준의 보호<br>사용자에게 권한 허용을 요청할 필요 X|
|dangerous|높은 수준의 보호<br>사용자에게 권한 허용을 요청 필요|
|signature|같은 키로 인증한 앱만 실행|
|signatureOrSystem|안드로이드 시스템 앱이거나 같은 키로 인증한 앱만 실행|

```xml
<!-->퍼미션 설정<!-->

<permission android:name="com.example.permission.TEST_PERMISSION"
  android:lavel="Permission 테스트 중 입니다"
  android:description="testing!!"
  android:protextionLevel="dangerous" />
```

- <uses-permission>을 2개 설정했다고 가정

```xml
<!-->퍼미션 사용 설정<!-->

<uses-permission android:name="com.example.permission.ACCESS_NETWORK_STATE" />
<uses-permission android:name="com.example.permission.ACCESS_FINE_LOCATION" />
```

<img src="https://github.com/BangYunseo/TIL/blob/main/Android/Image/ch09/ch09-01-package.PNG" width="100%" height="auto" />

- <permission> 설정 후 보호할 컴포넌트에 적용

```xml
<!-->컴포넌트에 퍼미션 적용<!-->

<activity android:name=".MainActivity" android:permission="com.example.permission.TEST_PERMISSION"
            android:exported="true">
            <intent-filter>
                <action android:name="android.intent.action.MAIN" />
                <category android:name="android.intent.category.LAUNCHER" />
            </intent-filter>
        </activity>
```

- 컴포넌트를 이용하는 곳에서 Manifest 파일에 <uses-permission>을 선언해야 정상적 실행 가능

|종류|설명|
|:---:|:---|
|ACCESS_FINE_LOCATION|위치 정보 접근|
|ACCESS_NETWORK_STATE|네트워크 정보 접근|
|ACCESS_WIFI_STATE|와이파이 네트워크 정보 접근|
|BATTERY_STATS|배터리 정보 접근|
|BLUETOOTH|블루투스 장치에 연결|
|BLUETOOTH_ADMIN|블루투스 장치를 검색하고 페어링|
|CAMERA|카메라 장치에 접근|
|INTERNET|네트워크 연결|
|READ_EXTERNAL_STORAGE|외부 저장소에서 파일 읽기|
|WRITE_EXTERNAL_STORAGE|외부 저장소에 파일 쓰기|
|READ_PHONE_STATE| 전화기 정보 접근|
|SEND_SMS|문자 메시지 발신|
|RECEIVE_SMS|문자 메시지 수신|
|RECEIVE_BOOT_COMPLETED|부팅 완료 시 실행|
|VIBRATE|진동 울리기|

### 퍼미션 허용 확인

- API 레벨 23 버전부터 허가제로 변경
- <uses-permission>으로 선언했더라도 사용자가 권한 화면에서 거부 가능
- 앱을 실행할 때 사용자가 퍼미션을 거부했는지 확인
- 거부했으면 다시 퍼미션을 허용해 달라고 요청

<img src="https://github.com/BangYunseo/TIL/blob/main/Android/Image/ch09/ch09-01-package.PNG" width="100%" height="auto" />

- checkSelfPer mission() 함수 : permission 허용 여부 확인
- 결괏값은 하나의 상수로 전달
  - PackageManager.PERMISSION_GRANTED : 권한을 허용한 경우
  - PackageManager.PERMISSION_DENIED: 권한을 거부한 경우
 
```kt
// 퍼미션 허용 확인 예시

val status = ContextCompat.checkSelfPermission(this, "android.permission.ACCESS_FINE_LOCATION")
if(status == PackageManager.PERMISSION_GRANTED) { log.d("Yunseo", "permission granted") }
else { log.d("Yunseo", "permission denied") }
```

- 거부한 상태라면 사용자에게 해당 퍼미션 허용 요청
- ActivityResultLauncher 객체 : registerForActivityResult() 함수를 호출해서 생성
  - 첫 번째 매개변수 : 어떤 요청인지를 나타내는 ActivityResultContract 타입 객체
  - 두 번째 매개변수 : 결과를 받았을 때 호출되는 콜백
- ActivityResultLauncher 객체의 launch() 함수를 호출하여 요청을 실행

<img src="https://github.com/BangYunseo/TIL/blob/main/Android/Image/ch09/ch09-01-package.PNG" width="100%" height="auto" />

```kt
// 퍼미션 허용 요청 확인

val requestPermissionLauncher = registerForActivityResult(
            ActivityResultContracts.RequestPermission()
        ) { isGranted -> if(isGranted) { Log.d("Yunseo", "callback, granted...") }
            else { Log.d("Yunseo", "callback, denied...") }
        }
```

```kt
// 퍼미션 허용 요청 실행

val requestPermissionLauncher = launch("android.permission.ACCESS_FINE_LOCATION")
```

(4/9)

## 3절. 다양한 다이얼로그

### 토스트 메시지 띄우기
