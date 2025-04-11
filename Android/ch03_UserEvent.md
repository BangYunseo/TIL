# Chapter 2. 뷰 배치 레이아웃

> '깡샘의 안드로이드 앱 프로그래밍 with 코틀린' 7장 학습 내용
>
> 1절. 터치 이벤트
>
> 2절. 키 이벤트
> 
> 3절. 뷰 이벤트
>
> 4절. 시계 앱 스톱워치 기능 만들기    
> [프로젝트 바로가기](https://github.com/BangYunseo/TIL/tree/main/Android/androidProject/ch03/)

## 1절. 터치 이벤트

### 터치 이벤트

- onTouchEvent() : 터치 이벤트의 콜백 함수로 선언
- 매개변수는 MotionEvent 객체이며
    - 객체에 터치의 종류와 발생 지점(좌푯값) 포함

```Kotlin
// 터치 이벤트 처리

class MainActivity : AppCompatActivity() {
    // (.. 생략)
    override fun onTouchEvent(event: MotionEvent?): Boolean{
        return super.onTouchEvent(event)
    }
}
```

### 터치 이벤트 종류

- ACTION_DOWN : 화면을 손가락으로 누른 순간의 이벤트 
- ACTION_UP : 화면에서 손가락을 떼는 순간의 이벤트
- ACTION_MOVE : 화면을 손가락으로 누른 채로 이동하는 순간의 이벤트

```Kotlin
// 터치 이벤트 처리

override fun onTouchEvent(event: MotionEvent?): Boolean{
    when (event?.action){
        MotionEvent.ACTION_DOWN -> {
            Log.d("Yunseo", "Touch Down Event")
        }
        MotionEvent.ACTION_UP -> {
            Log.d("Yunseo", "Touch Up Event")
        }
    }
    return super.onTouchEvent(event)
}
```

### 좌표 얻기

- onTouchEvent() 함수의 매개변수인 MotionEvent 객체로 획득 
    - x : 이벤트가 발생한 뷰의 X 좌표
    - y : 이벤트가 발생한 뷰의 Y 좌표 
    - rawX : 화면의 X 좌표
    - rawY : 화면의 Y 좌표

```Kotlin
// 터치 이벤트 발생 좌표 얻기

override fun onTouchEvent(event: MotionEvent?): Boolean{
    when (event?.action){
        MotionEvent.ACTION_DOWN -> {
            Log.d("Yunseo", 
                  "Touch Down Event x : ${event.x}, rawX : ${event.rawX}")
        }
    }
    return super.onTouchEvent(event)
}
```

<img src="https://github.com/BangYunseo/TIL/blob/main/Android/Image/ch03/ch03-01-MotionEvent.PNG" width="70%" height="auto" />

## 2절. 키 이벤트

### 키 이벤트

- 사용자가 폰의 키를 누르는 순간에 발생 
- 콜백 함수
    - onKeyDown : 키를 누른 순간의 이벤트
    - onKeyUp : 키를 떼는 순간의 이벤트
    - onKeyLongPress : 키를 오래 누르는 순간의 이벤트


```Kotlin
// 키 이벤트 처리

class MainActivity : AppCompatActivity(){
    // (..생략)
    override fun onKeyDown(keyCode: Int, event: KeyEvent?): Boolean{
        Log.d("Yunseo", "onKeyDown")
        return super.onKeyDown(keyCode, event)
    }
    override fun onKeyUp(keyCode: Int, event: KeyEvent?): Boolean{
        Log.d("Yunseo", "onKeyUp")
        return super.onKeyUp(keyCode, event)
    }
}
```

- keyCode : 첫 번째 매개 변수이자 사용자가 어떤 키를 눌렀는지 식별

```Kotlin
// 키 식별

override fun onKeyDown(keyCode: Int, event: KeyEvent?): Boolean{
    when(keyCode){
        KeyEvent.KEYCODE_0 -> Log.d("Yunseo", "0 키가 눌림")
        KeyEvent.KEYCODE_A -> Log.d("Yunseo", "A 키가 눌림")
    }
    return super.onKeyDown(keyCode, event)
}
```

- 키 이벤트 발생 키 : 폰에서 제공하는 소프트 키보드의 키가 아님
- 안드로이드 시스템 버튼도 키로 취급하므로 이 버튼의 이벤트를 처리
- 뒤로가기 버튼 이벤트
    - onKeyDown(), onKeyUp(), onBackPressed() 함수 사용

<img src="https://github.com/BangYunseo/TIL/blob/main/Android/Image/ch03/ch03-02-KeyButton.PNG" width="70%" height="auto" />

```Kotlin
// 뒤로 가기 버튼과 볼륨 조절 버튼 이벤트 처리

override fun onKeyDown(keyCode: Int, event: KeyEvent?): Boolean{
    when(keyCode){
        KeyEvent.KEYCODE_BACK -> Log.d("Yunseo", "BACK Button이 눌림")
        KeyEvent.KEYCODE_VOLUME_UP -> Log.d("Yunseo", "Volume Up 키가 눌림")
        KeyEvent.KEYCODE_VOLUME_DOWN -> Log.d("Yunseo", "Volume Down 키가 눌림")
    }
    return super.onKeyDown(keyCode, event)
}
```

```Kotlin
// 뒤로 가기 버튼 이벤트 처리

override fun onBackPressed(){
    Log.d("Yunseo", "Back Button이 눌림")
}
```

- onBackPressed() : API Level 33에서 더 이상 권장하지 않는 함
- androidx.activity.OnBackPressedCallback() 함수 이용

```Kotlin
// 뒤로 가기 버튼 이벤트 처리
val callback = object : OnBackPressedCallback(true) {
    override fun handleOnBackPressed() {
        Log.d("Yunseo", "뒤로가기 눌림!!")
    }
}
onBackPressedDispatcher.addCallback(this, callback)
```

## 3절. 뷰 이벤트

### 뷰 이벤트 처리 구조

- 이벤트 소스와 이벤트 핸들러로 역할 분할
- 둘을 리스너로 연결 시 이벤트 처리 가능
    - 이벤트 소스 : 이벤트 발생 객체
    - 이벤트 핸들러 : 이벤트 발생 시 실행할 로직이 구현된 객체 
    - 리스너 : 이벤트 소스와 이벤트 핸들러를 연결해 주는 함수

<img src="https://github.com/BangYunseo/TIL/blob/main/Android/Image/ch03/ch03-03-ViewConnection.PNG" width="70%" height="auto" />

```Kotlin
// 체크박스 이벤트 처리

binding.checkbox.setOnCheckedChangeListener
(object : CompoundButton.OnCheckedChangeListener {
    override fun onCheckedCHanged(p0: CompoundButton?, p1: Boolean){
        Log.d("Yunseo", "체크박스 클릭")
    }
})
```

<img src="https://github.com/BangYunseo/TIL/blob/main/Android/Image/ch03/ch03-04-CheckBox.PNG" width="70%" height="auto" />

```Kotlin
// 액티비티에서 인터페이스 구현 예시

class MainActivity : AppCompatActivity(), CompoundButton.OnCheckedChangeListener{
    override fun onCreate(savedInstanceState: Bundle?){
        super.onCreate(savedInstanceState)
        val binding = ActivityMainBinding.inflate(layoutInflater)
        setContentView(binding.root)
        binding.checkbox.setOnCheckedChangeListener(this)
    }
    override fun onCheckedChanged(p0: CompoundButton?, p1: Boolean){
        Log.d("Yunseo", "체크박스 클릭")
    }
}
```

```Kotlin
// 이벤트 핸들러를 별도의 클래스로 생성한 예시

class MyEventHandler : CompoundButton.OnCheckedChangeListener{
    override fun onCheckedChanged(p0: CompoundButton?, p1: Boolean){
        Log.d("Yunseo", "체크박스 클릭")
    }
}
class MainActivity : AppCompatActivity() {
    override fun onCreate(savedInstanceState: Bundle?){
        super.onCreate(savedInstanceState)
        val binding = ActivityMainBinding.inflate(layoutInflater)
        setContentView(binding.root)

        binding.checkbox.setOnCheckedChangeListener(MyEventHandler())
    }
}
```

```Kotlin
// SAM 기법으로 구현한 예시

class MainActivity : AppCompatActivity() {
    override fun onCreate(savedInstanceState: Bundle?){
        super.onCreate(savedInstanceState)

        val binding = ActivityMainBinding.inflate(layoutInflater)
        setContentView(binding.root)

        binding.checkbox.setOnCheckedChangeListener{
            compoundButton, b -> Log.d("Yunseo", "체크박스 클릭")
        }
    }
}
```

### 클릭과 롱클릭 이벤트 처리

- ClickEvent, LongClickEvent는 뷰의 최상위 클래스인 View에 정의된 이벤트 
    - open fun setOnClickListener(l: View.OnClickListener?) : Unit
    - open fun setOnLongClickListener(l: View.OnLongClickListener?) : Unit

```Kotlin
// 버튼의 클릭, 롱클릭 이벤트 처리

binding.button.setOnClickListener{
    Log.d("Yunseo", "클릭 이벤트")
}
binding.button.setOnLongClickListener{
    Log.d("Yunseo", "롱클릭 이벤트")
    true
}
```

## 4절. 시계 앱 스톱워치 기능 만들기

### 1단계) 새로운 모듈 생성

- Ch08_Event 모듈 생성

### 2단계) 그래들 설정

```Kotlin
// build.gradle.kts(Module : ch08_event)

android{
    viewBinding.isEnabled = true
}
```

### 3단계) 앱 화면 구성

```XML
<!-->activity_main.xml 파일<!-->

<?xml version="1.0" encoding="utf-8"?>
<RelativeLayout xmlns:android="http://schemas.android.com/apk/res/android"
    xmlns:app="http://schemas.android.com/apk/res-auto"
    xmlns:tools="http://schemas.android.com/tools"
    android:layout_width="match_parent"
    android:layout_height="match_parent"
    tools:context=".MainActivity">

    <Chronometer
        android:id="@+id/chronometer"
        android:layout_width="match_parent"
        android:layout_height="wrap_content"
        android:layout_marginTop="100dp"
        android:gravity="center_horizontal"
        android:textSize="60dp"/>

    <LinearLayout
        android:layout_width="match_parent"
        android:layout_height="wrap_content"
        android:layout_alignParentBottom="true"
        android:layout_marginBottom="70dp"
        android:gravity="center_horizontal"
        android:orientation="horizontal">

        <Button
            android:id="@+id/startButton"
            android:layout_width="100dp"
            android:layout_height="wrap_content"
            android:text="START"
            android:textColor="#FFFFFF"
            android:textStyle="bold" />
        <Button
            android:id="@+id/stopButton"
            android:layout_width="100dp"
            android:layout_height="wrap_content"
            android:layout_marginLeft="25dp"
            android:enabled="false"
            android:text="STOP"
            android:textColor="#FFFFFF"
            android:textStyle="bold" />
        <Button
            android:id="@+id/resetButton"
            android:layout_width="100dp"
            android:layout_height="wrap_content"
            android:layout_marginLeft="25dp"
            android:enabled="false"
            android:text="STOP"
            android:textColor="#FFFFFF"
            android:textStyle="bold" />
    </LinearLayout>
</RelativeLayout>
```

### 4단계) 메인 액티비티 구성

```Kotlin
// MainActivity.kt 구현

package com.yunseo_33.ch08_event

import android.os.Bundle
import android.os.SystemClock
import android.view.KeyEvent
import android.widget.Toast
import androidx.appcompat.app.AppCompatActivity
import com.yunseo_33.ch08_event.databinding.ActivityMainBinding

class MainActivity : AppCompatActivity() {
    var initTime = 0L
    var pauseTime = 0L

    override fun onCreate(savedInstanceState: Bundle?){
        super.onCreate(savedInstanceState)

        val binding = ActivityMainBinding.inflate(layoutInflater)
        setContentView(binding.root)

        binding.startButton.setOnClickListener{
            binding.chronometer.base = SystemClock.elapsedRealtime() + pauseTime
            binding.chronometer.start()

            binding.stopButton.isEnabled = true
            binding.resetButton.isEnabled = true
            binding.startButton.isEnabled = false
        }

        binding.stopButton.setOnClickListener{
            pauseTime = binding.chronometer.base - SystemClock.elapsedRealtime()
            binding.chronometer.stop()

            binding.stopButton.isEnabled = false
            binding.resetButton.isEnabled = true
            binding.startButton.isEnabled = true
        }

        binding.resetButton.setOnClickListener{
            pauseTime = 0L
            binding.chronometer.base = SystemClock.elapsedRealtime()
            binding.chronometer.stop()

            binding.stopButton.isEnabled = false
            binding.resetButton.isEnabled = false
            binding.startButton.isEnabled = true
        }
    }

    override fun onKeyDown(keyCode: Int, event: KeyEvent?): Boolean {
        if(keyCode == KeyEvent.KEYCODE_BACK){
            if(System.currentTimeMillis() - initTime > 3000){
                Toast.makeText(this, "종료하려면 한 번 더 누르세요", Toast.LENGTH_SHORT)
                    .show()
                initTime = System.currentTimeMillis()
                return true
            }

        }
        return super.onKeyDown(keyCode, event)
    }
}
```

### 5단계) 앱 실행

<img src="https://github.com/BangYunseo/TIL/blob/main/Android/Image/ch03/ch03-05-ex.PNG" width="70%" height="auto" />