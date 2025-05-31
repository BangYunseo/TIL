# Chapter 9. 브로드캐스트 리시버

> '깡샘의 안드로이드 앱 프로그래밍 with 코틀린' 14장 학습 내용
>
> 1절. 브로드캐스트 리시버
>
> 2절. 시스템 상태 파악
>
> 3절. 배터리 정보 앱 구현  
> [프로젝트 바로가기](https://github.com/BangYunseo/AndroidProject/tree/main/ch10)

## 1절. 브로드캐스트 리시버

### 생성

- BroadcastReceiver
  - 상속받는 클래스 선언 필요
  - AndroidManifest.xml에 등록
- onReceive() : 생명주기 함수

```kt
// 브로드캐스트 리시버 생성

class MyReceiver : BroadcastReceiver() {
  override fun onReceive(context: Context, intent: Intent){
  }
}
```

```xml
<!-- 브로드캐스트 리시버 등록 -->

<receiver
  android:name=".MyReceiver"
  android:enabled="true"
  android:exported="true"></receiver>
```

### 동적 등록 및 해제

- 필요한 경우 동적 등록

|      함수 종류       | 설명           |
| :------------------: | :------------- |
|  registerReceiver()  | 동적 등록 함수 |
| unregisterReciever() | 해제 함수      |

```kt
// 리시버 객체 생성

val receiver = object : BroadcastReceiver() {
  override fun onReceive(context: Context?, intent: Intent?){
  }
}
```

```kt
// 등록
registerReceiver(receiver, IntentFilter("ACTION_RECEIVER"), RECEIVER_EXPORTED)

// 해제
unregisterReceiver(receiver)
```

### 실행

- 실행 시 인텐트 필요
- 리시버를 AndroidManifest.xml에 등록하고 \<intent-filter\> 태그 선언 시 암시적 인텐트로 실행 불가

|     함수 종류      | 설명                                      |
| :----------------: | :---------------------------------------- |
| registerReceiver() | 등록된 리시버는 암시적 인텐트로 실행 가능 |
|  sendBroadcast()   | 리시버를 실행하는 인텐트를 시스템에 전달  |

```kt
// 리시버 실행

val intent = Intent(this, MyReceiver::class.java)
sendBroadcast(intent)
```

<img src="https://github.com/BangYunseo/TIL/blob/main/Android/Image/ch09/ch09-01-Intent.PNG" height="auto" />

## 2절. 시스템 상태 파악

### 부팅 완료

- android.intent.action.BOOT_COMPLETED
  - 액션 문자열 포함 인텐트 발생

```XML
<!-- 브로드캐스트 리시버와 인텐트 필터 등록 -->

<receiver
    android:name=".MyReceiver"
    android:enabled="true"
    android:exported="true">
    <intent-filter>
        <action android:name="android.intent.action.BOOT_COMPLETED" />
    </intent-filter>
</receiver>
```

```XML
<!-- 권한 설정 -->

<uses-permission android:name="android.permission.RECEIVE_BOOT_COMPLETED" />
```

### 화면 키고 끄기

- 상황 감지 브로드캐스트 리시버는 AndroidManifest.xml에 등록할 경우 실행 X
- 액션 문자열 종류
  - android.intent.action.SCREEN_ON
  - android.intent.action.SCREEN_OFF

```kt
// 화면 켜짐/꺼짐 리시버

receiver = object : BroadcastReceiver() {
    override fun onReceive(context: Context?, intent: Intent?) {
        when (intent?.action) {
            Intent.ACTION_SCREEN_ON -> Log.d("kkang", "screen on")
            Intent.ACTION_SCREEN_OFF -> Log.d("kkang", "screen off")
        }
    }
}
```

```kt
// 리시버 등록

val filter = IntentFilter(Intent.ACTION_SCREEN_ON).apply {
    addAction(Intent.ACTION_SCREEN_OFF)
}
registerReceiver(receiver, filter)
```

### 배터리 상태

- 배터리 상태 변경 시 아래 액션 문자열로 인텐트 발생

|          인텐트           | 설명                               |
| :-----------------------: | :--------------------------------- |
|        BATTERY_LOW        | 배터리가 낮은 상태로 변경되는 순간 |
|       BATTERY_OKAY        | 배터리가 정상 상태로 변경되는 순간 |
|      BATTERY_CHANGED      | 충전 상태가 변경되는 순간          |
|  ACTION_POWER_CONNECTED   | 전원이 공급되기 시작한 순간        |
| ACTION_POWER_DISCONNECTED | 전원 공급을 끊은 순간              |

- 배터리 정보

```kt
// 배터리 상태 리시버

receiver = object : BroadcastReceiver() {
    override fun onReceive(context: Context?, intent: Intent?) {
        when (intent?.action) {
            Intent.ACTION_BATTERY_OKAY -> Log.d("kkang", "ACTION_BATTERY_OKAY")
            Intent.ACTION_BATTERY_LOW -> Log.d("kkang", "ACTION_BATTERY_LOW")
            Intent.ACTION_BATTERY_CHANGED -> Log.d("kkang", "ACTION_BATTERY_CHANGED")
            Intent.ACTION_POWER_CONNECTED -> Log.d("kkang", "ACTION_POWER_CONNECTED")
            Intent.ACTION_POWER_DISCONNECTED -> Log.d("kkang", "ACTION_POWER_DISCONNECTED")
        }
    }
}
```

```kt
// 시스템 인텐트 없이 배터리 상태 파악

val intentFilter = IntentFilter(Intent.ACTION_BATTERY_CHANGED)
val batteryStatus = registerReceiver(null, intentFilter)
```

```kt
// 인텐트 엑스트라를 통한 배터리 상태 파악

val status = batteryStatus!!.getIntExtra(BatteryManager.EXTRA_STATUS, -1)
if (status == BatteryManager.BATTERY_STATUS_CHARGING) {
    // 전원이 공급되고 있다면
    val chargePlug = batteryStatus.getIntExtra(BatteryManager.EXTRA_PLUGGED, -1)
    when (chargePlug) {
        BatteryManager.BATTERY_PLUGGED_USB -> Log.d("kkang", "usb charge")
        BatteryManager.BATTERY_PLUGGED_AC -> Log.d("kkang", "ac charge")
    }
} else {
    // 전원이 공급되고 있지 않다면
    Log.d("kkang", "not charging")
}
```

- 배터리 충전 여부 파악

```kt
// 배터리 충전량 퍼센트 출력

val level = batteryStatus.getIntExtra(BatteryManager.EXTRA_LEVEL, -1)
val scale = batteryStatus.getIntExtra(BatteryManager.EXTRA_SCALE, -1)
val batteryPct = level / scale.toFloat() * 100
Log.d("kkang", "batteryPct : $batteryPct")
```

## 3절. 배터리 정보 앱 구현

### 1) 모듈 생성 & 빌드 그래들 설정 & 퍼미션 선언

- Ch14_Receiver 새로운 모듈 생성
- 뷰 바인딩 사용 설정

```kts
viewBinding.isEnabled = true
```

- 퍼미션 설정

```XML
<uses-permission android:name="android.permission.POST_NOTIFICATIONS" />
```

### 2) 브로드캐스트 리시버 생성

- [New → Other → Broadcast Receiver]
- 클래스 이름 : MyReceiver

### 3) 리소스 & 소스 파일 복사

- drawable, layout 디렉토리 파일 복사
- MainActivity.kt, MyReceiver.kt 파일에 복사

### 4) 메인 액티비티 작성

- MainActivity.kt 파일 작성

### 5) 배터리 상태 변경

- 에뮬레이터 More 아이콘 클릭
- 왼쪽에서 [Battery]를 선택
- 충전량, 충전기, 배터리 상태 조절

### 6) 앱 실행

<img src="https://github.com/BangYunseo/TIL/blob/main/Android/Image/ch09/ch09-02-App.PNG" height="auto" />

[프로젝트 바로가기](https://github.com/BangYunseo/AndroidProject/tree/main/ch10)
