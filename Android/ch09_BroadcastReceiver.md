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
  - 컴포넌트이므로 AndroidManifest.xml에 등록
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
- registerReceiver() : 시스템에 등록할 경우 사용하는 함수
- unregisterReciever() : 시스템에서 해제할 경우 사용하는 함수

```kt
// 리시버 객체 생성

val receiver = object : BroudcastReceiver() {
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

## 3절. 배터리 정보 앱 구현 

### 1) 모듈 생성 & 빌드 그래들 설정 & 퍼미션 선언

### 2) 브로드캐스트 리시버 생성

### 3) 리소스 & 소스 파일 복사

### 4) 메인 액티비티 작성

### 5) 배터리 상태 변경

### 6) 앱 실행

[프로젝트 바로가기](https://github.com/BangYunseo/AndroidProject/tree/main/ch10)
