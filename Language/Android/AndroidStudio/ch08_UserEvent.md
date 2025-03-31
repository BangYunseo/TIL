# Chapter 8. 사용자 이벤트 처리

> 1절. 터치 이벤트
>
> 2절. 키 이벤트
>
> 3절.

## 1절. 터치 이벤트

### 터치 이벤트

- 터치 이벤트의 콜백 함수인 onTouchEvent()를 선언(OverRide : 오버라이드)
- 매개변수는 MotionEvent 객체
  - 터치의 종류와 발생 지점(좌푯값) 존재

```Kotlin
// 터치 이벤트 처리
class MainActivity : AppCompatActivity(){
  // (...생략)
  override fun onTouchEvent(event: MotionEvent?): Boolean {
    return super .onTouchEvent(event)
  }
}
```

#### 종류

- ACTION_DOWN: 화면을 손가락으로 누른 순간의 이벤트
- ACTION_UP: 화면에서 손가락을 떼는 순간의 이벤트
- ACTION_MOVE: 화면을 손가락으로 누른 채로 이동하는 순간의 이벤트

```Kotlin
// 터치 이벤트 처리
override fun onTouchEvent(event: MotionEvent?): Boolean {
  when(event?.action){
    MotionEvent.ACTION_DOWN -> {
      log.d("Yunseo", "Touch down event")
    }
    MotionEvent.ACTION_UP -> {
      log.d("Yunseo", "Touch up event")
    }
  }
  return super .onTouchEvent(event)
}
```

#### 발생 좌표 획득

- onTouchEvent() 함수의 매개변수인 MotionEvent 객체로 획득
  - x : 이벤트가 발생한 뷰의 X 좌표
  - y : 이벤트가 발생한 뷰의 Y 좌표
  - rawX : 화면의 X 좌표
  - rawY : 화면의 Y 좌표

  - 실제 화면 기준으로는 rawX, rawY값이 중요
 
```Kotlin
// 터치 이벤트 발생 좌표 획득
override fun onTouchEvent(event: MotionEvent?): Boolean {
  when(event?.action){
    MotionEvent.ACTION_DOWN -> {
      log.d("Yunseo",
           "Touch down event x : ${event.x}, rawX : ${event.rawX}")
    }
  }
  return super .onTouchEvent(event)
}
```

## 2절. 키 이벤트

### 키 이벤트

- 실제로는 볼륨 up, down, 되돌아가기 버튼만 사용
  - 왜? Android의 운영체제가 작동하기 때문. 즉, 앱 내부에서 사용 가능한 버튼들
- 사용자가 폰의 키를 누르는 순간에 발생
 콜백 함수
 onKeyDown: 키를 누른 순간의 이벤트
 onKeyUp: 키를 떼는 순간의 이벤트
 onKeyLongPress: 키를 오래 누르는 순간의 이벤트
첫 번째 매개변수는 키의 코드이며 이 값으로 사용자가 어떤 키를 눌렀는지 식별
API Level 33에서뒤로가기버튼이벤트처리함수인onBackPressed() 함수는deprecated(권장하지 않음)
androidx.activity.OnBackPressedCallback() 함수 이용을 권장

## 3절. 뷰 이벤트

### 처리 구조

- 이벤트 소스, 이벤트 핸들러 역할로의 분할
- 리스너로 연결해야 이벤트 처리 가능
  - 이벤트 소스 : 이벤트가 발생한 객체
  - 이벤트 핸들러 : 이벤트 발생 시 실행할 로직이 구현된 객체
  - 리스너 : 이벤트 소스와 이벤트 핸들러를 연결해 주는 함수


 - 버튼은 ClickEvent
- 체크박스는 CheckedChangeEvent
- 리스트는 ItemListEvent

### 클릭과 롱클릭 이벤트 처리

- ClickEvent, LongClickEvent는 뷰의 최상위 클래스인 View에 정의된 이벤트
  - open fun setOnClickListener(l: View.OnClickListener?): Unit
  - open fun setOnLongClickListener(l: View.OnLongClickListener?): Unit
