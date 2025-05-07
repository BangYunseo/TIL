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
> 5절. 알림
>
> 6절. 카카오톡 알림
> [프로젝트 바로가기](https://github.com/BangYunseo/AndroidProject/tree/main/ch05)

## 1절. API 레벨 호환성 고려

### API 레벨 호환성

- 34 버전의 API에서 개발 시 24 버전 기기에서도 오류가 발생하지 않는 동작 필요
- minSdk 설정값보다 상위 버전에서 제공하는 API를 사용 시 호환성 고려

<img src="https://github.com/BangYunseo/TIL/blob/main/Android/Image/ch05/ch05-01-API.PNG" height="auto" />

- @RequiresApi · @TargetApi 애너테이션 이용
- 안드로이드 스튜디오에서 오류 무시 설정

```kt
@RequiresApi(Build.VERSION_CODES.S)
fun noti() {
  // (... 생략 ...)
  val builder: Notification.Builder = Notification.Builder(this, "1")
    .setStyle(
      Notification.CallStyle.forIncomingCall(caller, declineIntent, answerIntent)
    )
  // (... 생략 ...)
}
```

- API 레벨 호환성 문제 방지를 위한 코드 처리

```kt
// API 레벨 >= 30인 경우에 실행되는 addCallback() 함수

if(Build.VERSION.SDK_INT >= Build.VERSION_CODES.S){
  val builder: Notification.Builder = Notification.Builder(this, "1")
    .setStyle(
      Notification.CallStyle.forIncomingCall(caller, delineIntent, answerIntent)
    )
} else {
  // 이전 버전 그대로 처리 코드 필요
}
```

## 2절. Permission 설정

### 퍼미션 설정과 사용 설정

- A 앱의 컴포넌트를 B 앱에서 사용
- 만약 A 앱의 컴포넌트에 Permission 설정 시 B 앱 연동에서 문제 발생

<img src="https://github.com/BangYunseo/TIL/blob/main/Android/Image/ch05/ch05-02-Permission.PNG" height="auto" />

- <permission> 태그 : 기능을 보호하려는 앱의 매니페스트(AndroidManifest.xml) 파일에 설정
- <uses-permission> 태그 : 퍼미션으로 보호된 기능을 사용하려는 앱의 매니페스트(AndroidManifest.xml) 파일에 설정

<img src="https://github.com/BangYunseo/TIL/blob/main/Android/Image/ch05/ch05-03-Permission2.PNG" height="auto" />

### <permission> 태그 · 속성

|        속성         | 설명            |
| :-----------------: | :-------------- |
|        name         | permission 이름 |
| label · description | permission 설명 |
|   protectionLevel   | 보호 수준       |

### Protection Level 속성값

- 보호 수준

|       종류        | 설명                                              |
| :---------------: | :------------------------------------------------ |
|      normal       | 낮은 수준 보호<br>사용자에게 권한 허용 요청 X     |
|     dangerous     | 높은 수준 보호<br>사용자에게 권한 허용 요청 필요  |
|     signature     | 같은 키로 인증한 앱만 실행                        |
| signatureOrSystem | 안드로이드 시스템 앱 · 같은 키로 인증한 앱만 실행 |

```xml
<!-->퍼미션 설정<!-->

<permission android:name="com.example.permission.TEST_PERMISSION"
  android:lavel="Permission TESTING"
  android:description="@string/permission_desc"
  android:protextionLevel="dangerous" />
```

### permission 설정 과정

- <uses-permission> 2개 설정

```xml
<!-->퍼미션 사용 설정<!-->

<uses-permission android:name="com.example.permission.ACCESS_NETWORK_STATE" />
<uses-permission android:name="com.example.permission.ACCESS_FINE_LOCATION" />
```

<img src="https://github.com/BangYunseo/TIL/blob/main/Android/Image/ch05/ch05-04-Permission3.PNG" height="auto" />

- <permission> 설정 후 보호할 컴포넌트에 적용

(여기부터 확인)

```xml
<!--컴포넌트에 퍼미션 적용-->

<activity android:name="OneActivity"
          android:permission="com.example.TEST_PERMISSION">
  <intent-filter>
    <action android:name="android.intent.action.PICK" />
  </intent-filter>
</activity>
```

- 컴포넌트 이용 Manifest 파일에 <uses-permission>을 선언

```xml
<!-- 퍼미션 사용 설정 -->

<uses-permission android:name="com.example.permission.TEST_PERMISSION" />
```

### 퍼미션 사용 설정 종류

|          종류          | 설명                         |
| :--------------------: | :--------------------------- |
|  ACCESS_FINE_LOCATION  | 위치 정보 접근               |
|  ACCESS_NETWORK_STATE  | 네트워크 정보 접근           |
|   ACCESS_WIFI_STATE    | 와이파이 네트워크 정보 접근  |
|     BATTERY_STATS      | 배터리 정보 접근             |
|       BLUETOOTH        | 블루투스 장치 연결           |
|    BLUETOOTH_ADMIN     | 블루투스 장치 검색 후 페어링 |
|         CAMERA         | 카메라 장치 접근             |
|        INTERNET        | 네트워크 연결                |
| READ_EXTERNAL_STORAGE  | 외부 저장소 파일 읽기        |
| WRITE_EXTERNAL_STORAGE | 외부 저장소 파일 쓰기        |
|    READ_PHONE_STATE    | 전화기 정보 접근             |
|        SEND_SMS        | 문자 메시지 발신             |
|      RECEIVE_SMS       | 문자 메시지 수신             |
| RECEIVE_BOOT_COMPLETED | 부팅 완료 시 실행            |
|        VIBRATE         | 진동 울리기                  |

### 퍼미션 허용 확인

- API 레벨 23 버전부터 허가제로 변경
- <uses-permission> 선언 후 사용자 권한 화면에서 거부 가능
- 앱 실행 시 사용자 퍼미션 거부 여부 확인
  - 거부한 경우 다시 퍼미션 허용 요청

<img src="https://github.com/BangYunseo/TIL/blob/main/Android/Image/ch05/ch05-05-PermissionAcception.PNG" height="auto" />

- checkSelfPer mission() 함수 : permission 허용 여부 확인
- 결괏값 : 하나의 상수

|               함수                | 설명      |
| :-------------------------------: | :-------- |
| PackageManager.PERMISSION_GRANTED | 권한 허용 |
| PackageManager.PERMISSION_DENIED  | 권한 거부 |

```kt
// 퍼미션 허용 확인 예시

val status = ContextCompat.checkSelfPermission(this,
            "android.permission.ACCESS_FINE_LOCATION")

if(status == PackageManager.PERMISSION_GRANTED) {
  log.d("Yunseo", "permission granted")
} else {
  log.d("Yunseo", "permission denied")
}
```

### 퍼미션 요청

- 거부 상태 : 사용자에게 해당 퍼미션 허용 요청
- ActivityResultLauncher 객체
  - registerForActivityResult() 함수 호출 후 생성
  - 첫 번째 매개변수 : 어떤 요청인지를 나타내는 ActivityResultContract 타입 객체
  - 두 번째 매개변수 : 결과를 받았을 때 호출되는 콜백
- ActivityResultLauncher 객체 launch() 함수 호출 후 요청 실행

<img src="https://github.com/BangYunseo/TIL/blob/main/Android/Image/ch05/ch05-06-PermissionRequest.PNG" height="auto" />

```kt
// 퍼미션 허용 요청 확인

val requestPermissionLauncher = registerForActivityResult(
ActivityResultContracts.RequestPermission()
) { isGranted ->
  if(isGranted) {
    Log.d("Yunseo", "callback, granted...")
  }
  else {
    Log.d("Yunseo", "callback, denied...")
  }
}
```

```kt
// 퍼미션 허용 요청 실행

val requestPermissionLauncher = launch("android.permission.ACCESS_FINE_LOCATION")
```

## 3절. 다양한 다이얼로그

### 토스트 메시지

- 토스트 : 화면 아래쪽에 잠깐 보였다가 사라지는 문자열(일시적)
- Toast의 makeText() 함수

  - open static fun makeText(context: Context!, text: CharSequence!, duration: Int): Toast!
  - open static fun makeText(context: Context!, resId: Int, duration: Int): Toast!

- 세 번째 매개변수 : 토스트가 화면에 출력되는 시간

  - val LENGTH_LONG: Int
  - val LENGTH_SHORT: Int

```kt
// 토스트 출력 예시

val toast = Toast.makeTest(this, "종료하려면 한 번 더 누르세요", Toast.LENGTH_SHORT)
toast.show()
```

<img src="https://github.com/BangYunseo/TIL/blob/main/Android/Image/ch05/ch05-07-Toast.PNG" height="auto" />

### 토스트 로직

- 토스트가 화면에 보이거나 사라지는 순간을 콜백으로 감지 후 특정 로직 수행
- 콜백 기능 : API 레벨 30버전

```kt
// 콜백 기능

@RequiresApi(Build.VERSION_CODES.R)
fun showToast(){
  val toast = Toast.makeText(this, "종료하려면 한 번 더 누르세요", Toast.LENGTH_SHORT)
  toast.addCallback(
    object : Toast.Callback(){
      override fun onToastHidden() {
        super.onToastHidden()
        Log.d("yunseo", "toast hidden")
      }

      override fun onToastShown() {
        super.onToastShown()
        Log.d("yunseo", "toast shown")
      }
    })
  toast.show()
}
```

### 날짜 · 시간 입력받기

- DatePickerDialog : 날짜 입력
- TimerPickerDialog : 시간 입력
- 콜백 함수 : 사용자가 설정한 날짜 반환

```kt
// 데이트 피커 다이얼로그 사용

DatePickerDialog(this, object: DatePickerDialog.OnDateSetListener{
  override fun onDateSet(p0: DatePicker?, p1: Int, p2: Int, p3: Int){
    Log.d("yunseo", "year : $p1, month : ${p2 + 1}, dayOfMonth : $p3")
  }
}, 2024, 4, 6).show()
```

<img src="https://github.com/BangYunseo/TIL/blob/main/Android/Image/ch05/ch05-08-DatePicker.PNG" height="auto" />

```kt
// 타임 피커 다이얼로그 사용

TimePickerDialog(this, object: TimePickerDialog.OnTimeSetListener{
  override fun onTimeSet(p0: TimePicker?, p1: Int, p2: Int, p3: Int){
    Log.d("yunseo", "year : $p1, month : ${p2 + 1}, dayOfMonth : $p3")
  }
}, 2024, 4, 6).show()
```

### 다중 선택을 위한 체크박스

```kt
setMultiChoiceItems(items, booleanArrayOf(true, false, true, false),
object : DialogInterface.OnMultiChoiceClickListener {
  override fun onClick(dialog: DialogInterface?, which: Int, isChecked: Boolean) {
    Log.d("Yunseo", "${items[which]} 이 ${if(isChecked) " 선택되었습니다." else "선택 해제되었습니다."}")
  }
})
```

### 단일 선택을 위한 라디오 버튼

```kt
setSingleChoiceItems(items, 1, object : DialogInterface.OnClickListener{
  override fun onClick(dialog: DialogInterface?, which: Int) {
    Log.d("Yunseo", "${items[which]} 이 선택되었습니다.")
  }
})
```

### setCancelable() / setCanceledOnTouchOutside() 함수

- setCancelable() : 사용자가 기기의 뒤로가기 버튼을 눌렀을 경우
- setCanceledOnTouchOutside() : 알림 바깥 영역을 터치했을 경우

| bool 값 |     행동     |
| :-----: | :----------: |
|  true   |   창 닫기    |
|  false  | 창 닫지 않기 |

```kt
// 알림 창을 닫는 설정(뒤로가기, 바깥 영역 터치)

AlertDialog.Builder(this).run {
  setTitle("item test")
  setIcon(android.R.drawable.ic_dialog_info)
  setItems(items, object : DialogInterface.OnClickListener{
    override fun onClick(dialog: DialogInterface?, which: Int) {
      Log.d("Yunseo", "${items[which]} 이 선택되었습니다.")
    }
  })
  setCancelable(false)
  setPositiveButton("OK", eventHandler)
  setNegativeButton("Cancel", eventHandler)
  setNeutralButton("More", null)
  show()
}.setCanceledOnTouchOutside(false)
```

## 4절. 소리와 진동 알림

### 소리 알림 : RingtonManager

- 알림(Notification), 알람(Alarm), 벨소리(Ringtone) 등

```kt
// 소리 얻기

val notification: Uri = RingtoneManager.getDefaultUri(RingtoneManager.TYPE_NOTIFICATION)
val ringtone = RingtoneManager.getRingtone(applicationContext, notification)
ringtone.play()
```

- 앱 자체 음원 준비 후 재생
- 음원 리소스 디렉토리 : res/raw

```kt
// 음원 재생

val player: MediaPlayer = MediaPlayer.create(this, R.raw.fallbackring)
player.start()
```

### 진동 알림 : VibratorManager

- Manifest 파일에 <uses-permission>의 퍼미션 선언
- 진동은 Vibrator 클래스 이용
- 버전 별 이용 방법

|     버전     | 이용 방법                                                                                             |
| :----------: | :---------------------------------------------------------------------------------------------------- |
| 31 이전 버전 | VIBRATOR_SERVICE로 식별되는 시스템 서비스 이용                                                        |
| 31 이후 버전 | VIBRATOR_MANAGER_SERVICE로 식별되는 VibratorManager 시스템 서비스 획득 후 이 서비스에서 Vibrator 이용 |

```kt
// 진동 객체 얻기

val vibrator = if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.S){
  val vibratorManager = this.getSystemService(Context.VIBRATOR_MANAGER_SERVICE)
                        as VibratorManager
  vibratorManager.defaultVibrator;
} else {
  getSystemService(VIBRATOR_SERVICE) as Vibrator
}
```

### 시간과 배턴 지정

| API 레벨 1부터 제공                                      |
| :------------------------------------------------------- |
| open fun vibrate(milliseconds: Long): Unit               |
| open fun vibrate(pattern: LongArray!, repeat: Int): Unit |

### 진동의 세기 지정 후 진동

| API 레벨 26부터 제공                                                                | 설명                                                                    |
| :---------------------------------------------------------------------------------- | :---------------------------------------------------------------------- |
| open fun vibrate(vibe: VibrationEffect!): Unit                                      | VibrationEffect 객체로는 진동이 울리는 시간 이외에 진동의 세기까지 제어 |
| open static fun createOneShot(milliseconds: Long, amplitude: Int): VibrationEffect! |                                                                         |

```kt
// 기본 세기로 진동

if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.O){
  vibrator.vibrate(
    VibrationEffect.createOneShot(500,
    VibrationEffect.DEFAULT_AMPLITUDE))
} else {
  vibrator.vibrate(500)
}
```

```kt
// 패턴대로 반복 진동

if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.O){
  vibrator.vibrate(VibrationEffect.createWaveform(longArrayOf(500, 1000, 500, 2000),
  intArrayOf(0, 50, 0, 200), -1))
} else {
  vibrator.vibrate(longArrayOf(500, 1000, 500, 2000), -1)
}
```

## 5절. 알림

### 알림 채널

- 알림(notification) : 상태 바에 앱의 정보를 출력하는 것
- API 레벨 33버전부터는 앱에서 알림을 띄우기 위해 사용자에게 퍼미션(허가) 요청 필요

```kt
// Manifest 파일

<uses-permission android:name="android.permission.POST_NOTIFICATIONS"/>
```

- Notification : NotificationCompatBuilder 필요
- 앱의 알림을 채널로 구분
- 버전 별 이용 방법

|    버전     | 이용 방법                                                                                   |
| :---------: | :------------------------------------------------------------------------------------------ |
| 26버전 이전 | 빌더 생성 시 NotificationChannel 정보 필요 X                                                |
| 26버전 이후 | 빌더 생성 시 NotificationChannel 생성 후 채널의 식별값을 빌더의 생성자 매개변수에 지정 필요 |

- 알림의 중요도(구글찾아서써보기```kt
  // 음원 재생

val player: MediaPlayer = MediaPlayer.create(this, R.raw.fallbackring)
player.start()

````

### 진동 알림 : VibratorManager

- Manifest 파일에 <uses-permission>의 퍼미션 선언
- 진동은 Vibrator 클래스 이용
- 버전 별 이용 방법

|버전|이용 방법|
|:--:|:----|
|31 이전 버전|VIBRATOR_SERVICE로 식별되는 시스템 서비스 이용|
|31 이후 버전|VIBRATOR_MANAGER_SERVICE로 식별되는 VibratorManager 시스템 서비스 획득 후 이 서비스에서 Vibrator 이용|

```kt
// 진동 객체 얻기

val vibrator = if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.S){
  val vibratorManager = this.getSystemService(Context.VIBRATOR_MANAGER_SERVICE)
                        as VibratorManager
  vibratorManager.defaultVibrator;
} else {
  getSystemService(VIBRATOR_SERVICE) as Vibrator
}
````

### 시간과 배턴 지정

| API 레벨 1부터 제공                                      |
| :------------------------------------------------------- |
| open fun vibrate(milliseconds: Long): Unit               |
| open fun vibrate(pattern: LongArray!, repeat: Int): Unit |

### 진동의 세기 지정 후 진동

| API 레벨 26부터 제공                                                                | 설명                                                                    |
| :---------------------------------------------------------------------------------- | :---------------------------------------------------------------------- |
| open fun vibrate(vibe: VibrationEffect!): Unit                                      | VibrationEffect 객체로는 진동이 울리는 시간 이외에 진동의 세기까지 제어 |
| open static fun createOneShot(milliseconds: Long, amplitude: Int): VibrationEffect! |                                                                         |

```kt
// 기본 세기로 진동

if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.O){
  vibrator.vibrate(
    VibrationEffect.createOneShot(500,
    VibrationEffect.DEFAULT_AMPLITUDE))
} else {
  vibrator.vibrate(500)
}
```

```kt
// 패턴대로 반복 진동

if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.O){
  vibrator.vibrate(VibrationEffect.createWaveform(longArrayOf(500, 1000, 500, 2000),
  intArrayOf(0, 50, 0, 200), -1))
} else {
  vibrator.vibrate(longArrayOf(500, 1000, 500, 2000), -1)
}
```

## 5절. 알림

### 알림 채널

- 알림(notification) : 상태 바에 앱의 정보를 출력하는 것
- API 레벨 33버전부터는 앱에서 알림을 띄우기 위해 사용자에게 퍼미션(허가) 요청 필요

```kt
// Manifest 파일

<uses-permission android:name="android.permission.POST_NOTIFICATIONS"/>
```

- Notification : NotificationCompatBuilder 필요
- 앱의 알림을 채널로 구분
- 버전 별 이용 방법

|    버전     | 이용 방법                                                                                   |
| :---------: | :------------------------------------------------------------------------------------------ |
| 26버전 이전 | 빌더 생성 시 NotificationChannel 정보 필요 X                                                |
| 26버전 이후 | 빌더 생성 시 NotificationChannel 생성 후 채널의 식별값을 빌더의 생성자 매개변수에 지정 필요 |

- 알림의 중요도(구글찾아서써보기)
- 함수 별 설명

| 함수(function)                                                     | 설명                                     |
| :----------------------------------------------------------------- | :--------------------------------------- |
| fun setDescription(description: String!): Unit                     | 채널의 설명 문자열                       |
| fun setShowBadge(showBadge: Boolean): Unit                         | 홈 화면의 아이콘에 배지 아이콘 출력 여부 |
| fun setSound(sound: Uri!, audioAttributes: AudioAttributes!): Unit | 알림음 재생                              |
| fun enableLights(lights: Boolean): Unit                            | 불빛 표시 여부                           |
| fun setLightColor(argb: Int): Unit                                 | 불빛이 표시된다면 불빛의 색상            |
| fun enableVibration(vibration: Boolean): Unit                      | 진동을 울릴지 여부                       |
| fun setVibrationPattern(vibrationPattern: LongArray!): Unit        | 진동을 울린다면 진동의 패턴              |

```kt
// 알림 빌더 작성

val manager:NotificationManager = getSystemService(NOTIFICATION_SERVICE) as NotificationManager
val builder: NotificationCompat.Builder

if(Build.VERSION.SDK_INT >= Build.VERSION_CODES.O){
  val channelId = "one-channel"
  val channelName = "My Channel One"
  val channel = NotificationChannel(
      channelId,
      channelName,
      NotificationManager.IMPORTANCE_HIGH
  )

  channel.description = "My Channel One Description!"
  channel.setShowBadge(true)
  val uri: Uri = RingtoneManager.getDefaultUri(RingtoneManager.TYPE_NOTIFICATION)
  val audioAttributes = AudioAttributes.Builder()
        .setContentType(AudioAttributes.CONTENT_TYPE_SONIFICATION)
        .setUsage(AudioAttributes.USAGE_ALARM)
        .build()

  channel.setSound(uri, audioAttributes)
  channel.enableLights(true)
  channel.lightColor = Color.RED
  channel.enableVibration(true)
  channel.vibrationPattern = longArrayOf(100, 200, 100, 200)

  manager.createNotificationChannel(channel)
  // 채널을 NotificationManager 에 등록

  builder = NotificationCompat.Builder(this, channelId)
  // 채널을 이용해 빌더 생성
} else {
  builder = NotificationCompat.Builder(this)
}
```

### 알림 객체

```kt
// 알림 객체 설정

builder.run{
  setSmallIcon(android.R.drawable.ic_notification_overlay)
  setWhen(System.currentTimeMillis())
  setContentTitle("Content Title")
  setContentText("Content Message")
}
```

```kt
// 알림 발생

manager.notify(11, builder.build())
```

```kt
// 알림 취소

manager.cancel(11)
```

```kt
// 알림 취소 방지

builder.run{
  setAutoCancel(false)
  setOngoing(true)
}
```

### 알림 구성

- 알림 터치 이벤트 : 인텐트 준비 후 Notification 객체에 담고 이벤트 발생 시 인텐트 실행을 시스템에 의뢰
  - 인텐트(Intent) : 액티비티가 있을 경우
  - static fun getActivity(context: Context!, requestCode: Int, intent: Intent!, flags: Int): PendingIntent!
  - static fun getBroadcast(context: Context!, requestCode: Int, intent: Intent!, flags: Int): PendingIntent!
  - static fun getService(context: Context!, requestCode: Int, intent: Intent, flags: Int): PendingIntent!

```kt
// 알림 객체에 액티비티 실행 정보 등록

// DetailActivity 클래스 파일 MainActivity가 있는 폴더에 생성
val intent = Intent(this, DetailActivity::class.java)
val pendingIntent = Pending.getActivity(this, 10, intent, PendingIntent.FLAG_IMMUTABLE)

// 터치 이벤트 등록
builder.setContentIntent(PendingIntent)
```

### 액션

- 최대 3개까지 추가

```kt
// 액션 등록

// DetailActivity가 아닌 OneReceiver 클래스 생성
val actionIntent = Intent(this, OneReceiver::class.java)

val actionPendingIntent = PendingIntent.getBroadcast(this, 20, actionIntent,
  PendingIntent.FLAG_IMMUTABLE)
builder.addAction(
  NotificationCompat.Action.Builder(
      android.R.drawable.stat_notify_more,
      "Action",
      actionPendingIntent
  ).build()
)
```

### 원격 입력

- 알림에서 사용자 입력을 직접 받는 기법
- PendingIntent 준비 필요

```kt
// 원격 입력

val KEY_TEXT_REPLY = "key_text_reply"
```

## 6절. 카카오톡 알림
