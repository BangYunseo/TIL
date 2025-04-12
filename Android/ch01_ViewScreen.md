# Chapter 1. 뷰를 이용한 화면 구성

> '깡샘의 안드로이드 앱 프로그래밍 with 코틀린' 6장 학습 내용
>
> 1절. 화면 구성
>
> 2절. 뷰 클래스
> 
> 3절. 기본적인 뷰
>
> 4절. 뷰 바인딩
> 
> 5절. 카카오톡 비밀번호 확인 화면 프로젝트   
> [프로젝트 바로가기](https://github.com/BangYunseo/TIL/tree/main/Android/androidProject/ch01/)


## 1절. 화면을 구성하는 방법

### 액티비티-뷰 구조

- 액티비티 : 화면을 출력하는 컴포넌트
- 화면에 내용을 표시할 경우 뷰 클래스 이용

<img src="https://github.com/BangYunseo/TIL/blob/main/Android/Image/ch01/ch01-01-viewScreen.PNG" width="auto" height="auto" /> | <img src="https://github.com/BangYunseo/TIL/blob/main/Android/Image/ch01/ch01-02-viewScreen2.PNG" width="auto" height="auto" />
---|---|


```kt
class MainActivity : AppCompatActivity() {
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        enableEdgeToEdge()

        // 이름 문자열 출력 TextView 생성
        val name = TextView(this).apply {
            typeface = Typeface.DEFAULT_BOLD
            text = "Lake Louise"
        }

        // 이미지 출력 ImageView 생성
        val image = ImageView(this).also {
            it.setImageDrawable(ContextCompat.getDrawable(this, R.drawable.lake_1))
        }

        // 주소 문자열 출력 TextView 생성
        val address = TextView(this).apply {
            typeface = Typeface.DEFAULT_BOLD
            text = "Lake Louse, AB, 캐나다"
        }
        val layout = LinearLayout(this).apply {
            orientation = LinearLayout.VERTICAL
            gravity = Gravity.CENTER
            addView(name, WRAP_CONTENT, WRAP_CONTENT)
            addView(image, WRAP_CONTENT, WRAP_CONTENT)
            addView(address, WRAP_CONTENT, WRAP_CONTENT)
        }
        setContentView(layout)

        ViewCompat.setOnApplyWindowInsetsListener(layout) { v, insets ->
            val systemBars = insets.getInsets(WindowInsetsCompat.Type.systemBars())
            v.setPadding(systemBars.left, systemBars.top, systemBars.right, systemBars.bottom)
            insets
        }
    }
}
```

### 레이아웃 XML로 화면 구성

- 뷰를 XML의 태그로 명시해 화면 구성

```kt
// 액티비티에 레이아웃 XML 명시

class MainActivity : AppCompatActivity() {
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)

        // 화면 출력 XML 명시
        setContentView(R.layout.activity_main)
    }
}
```

```XML
<!--> 레이아웃 XML에서 화면 구성(activity_main.xml)<!-->

<?xml version="1.0" encoding="utf-8"?>
<LinearLayout xmlns:android="http://schemas.android.com/apk/res/android"
    android:layout_width="match_parent"
    android:layout_height="match_parent"
    android:orientation="vertical"
    android:gravity="center">

    <TextView
        android:layout_width="wrap_content"
        android:layout_height="wrap_content"
        android:text="Lake Louise"
        android:textStyle="bold"/>
    <ImageView
        android:layout_width="wrap_content"
        android:layout_height="wrap_content"
        android:src="@drawable/lake_1" />
    <TextView
        android:layout_width="wrap_content"
        android:layout_height="wrap_content"
        android:textStyle="bold"
        android:text="Lake Louise, AB, 캐나다"/>
</LinearLayout>
```

## 2절. 뷰 클래스

### 뷰 클래스 기본 구조

- 뷰 객체의 계층 구조

<img src="https://github.com/BangYunseo/TIL/blob/main/Android/Image/ch01/ch01-03-viewStructure.PNG" width="70%" height="auto" />

    - View : 모든 뷰 클래스의 최상위 클래스로 액티비티는 View의 서브 클래스만 화면에 출력
    - ViewGroup : 자체 UI 없이 다른 뷰 여러 개를 묶어 제어할 목적으로 사용
    - TextView : 특정 UI를 출력할 목적으로 사용하는 클래스

- ViewGroup 클래스의 하위인 레이아웃 클래스는 화면 자체가 목적이 아닌 다른 뷰(TextView, ImageView 등) 객체 여러 개를 담아서 한꺼번에 제어할 목적으로 사용

```xml
<!--> 레이아웃 클래스에 뷰 포함<!-->

<?xml version="1.0" encoding="utf-8"?>
<LinearLayout xmlns:android="http://schemas.android.com/apk/res/android"
    android:layout_width="match_parent"
    android:layout_height="match_parent"
    android:orientation="vertical">

    <Button
        android:layout_width="wrap_content"
        android:layout_height="wrap_content"
        android:text="BUTTON1"/>
    <Button
        android:layout_width="wrap_content"
        android:layout_height="wrap_content"
        android:text="BUTTON2"/>

</LinearLayout>
```

<img src="https://github.com/BangYunseo/TIL/blob/main/Android/Image/ch01/ch01-04-LinearLayout.PNG" width="20%" height="auto" />

- 레이아웃 중첩
    - 뷰의 계층 구조 : 레이아웃 객체로 중첩해서 복잡한 구성 가능

<img src="https://github.com/BangYunseo/TIL/blob/main/Android/Image/ch01/ch01-05-LinearLayout2.PNG" width="60%" height="auto" />  

```xml
<!--> 레이아웃 중첩<!-->

<?xml version="1.0" encoding="utf-8"?>
<LinearLayout xmlns:android="http://schemas.android.com/apk/res/android"
    android:layout_width="match_parent"
    android:layout_height="match_parent"
    android:orientation="vertical">
    <Button
        android:layout_width="wrap_content"
        android:layout_height="wrap_content"
        android:text="BUTTON1"/>
    <Button
        android:layout_width="wrap_content"
        android:layout_height="wrap_content"
        android:text="BUTTON2"/>
    
    <LinearLayout
        android:layout_width="wrap_content"
        android:layout_height="wrap_content"
        android:orientation="horizontal">
        <Button
            android:layout_width="wrap_content"
            android:layout_height="wrap_content"
            android:text="BUTTON3"/>
        <Button
            android:layout_width="wrap_content"
            android:layout_height="wrap_content"
            android:text="BUTTON4"/>
    </LinearLayout>
</LinearLayout>
```

### 레이아웃 XML의 뷰를 코드에서 사용

- id : 객체 식별을 위한 식별자 값을 지정한 속성 
    - XML에 id 속성을 추가 : 자동으로 R.java 파일에 상수 변수로 추가 
    - 코드에서 findViewById() 함수를 이용해 객체 획득

```xml
<!-->id 속성 부여<!-->

    <TextView
        android:id="@+id/text1"
        android:layout_width="wrap_content"
        android:layout_height="wrap_content"
        android:text="Hello!"/>
```

```kt
// 코드에서 XML에 입력한 객체 사용법

// XML 화면 출력 (activity_main.xml)
setContentView(R.layout.activity_main)

// id 값으로 뷰 객체 획득 (기본)
val textView1: TextView = findViewById(R.id.text1)

// id 값으로 뷰 객체 획득 (제네릭)
val textView1 = findViewById<TextView>(R.id.text1)
```

### 뷰의 크기 지정

- 뷰가 화면에 나올 때 어떤 크기로 보여야 하는지 설정하는 필수 정보
- 크기 설정 속성 : layout_width, layout_height
    - 수치
    - match_parent
    - wrap_content

```xml
<!-->크기 지정 예<!-->

<?xml version="1.0" encoding="utf-8"?>
<LinearLayout xmlns:android="http://schemas.android.com/apk/res/android"
    android:layout_width="match_parent"
    android:layout_height="match_parent"
    android:orientation="vertical"
    android:background="#ffff00">
    <Button
        android:layout_width="wrap_content"
        android:layout_height="wrap_content"
        android:text="BUTTON1"
        android:backgroundTint="#0000ff"/>
    <Button
        android:layout_width="match_parent"
        android:layout_height="wrap_content"
        android:text="BUTTON2"
        android:backgroundTint="#ff0000"/>
</LinearLayout>
```

### 뷰의 간격 설정

<img src="https://github.com/BangYunseo/TIL/blob/main/Android/Image/ch01/ch01-06-MarginPadding.PNG" width="30%" height="auto" />  

-  margin, padding 속성
    - 4 방향이 모두 같은 크기로 설정 가능
    - padding : paddingLeft, paddingRight, paddingTop, paddingBottom
    - layout : layout_marginLeft, layout_margin Right, layout_marginTop, layout_marginBottom

```xml
<!-->뷰의 간격 설정<!-->

<?xml version="1.0" encoding="utf-8"?>
<LinearLayout xmlns:android="http://schemas.android.com/apk/res/android"
    android:layout_width="match_parent"
    android:layout_height="match_parent"
    android:orientation="horizontal">
    <Button
        android:layout_width="wrap_content"
        android:layout_height="wrap_content"
        android:text="BUTTON1"
        android:backgroundTint="#0000ff"
        android:padding="30dp"/>
    <Button
        android:layout_width="match_parent"
        android:layout_height="wrap_content"
        android:text="BUTTON2"
        android:backgroundTint="#ff0000"
        android:paddingBottom="50dp"
        android:layout_marginLeft="50dp"/>
</LinearLayout>
```

### 뷰 표시 여부 설정

- visibility 속성 : 뷰가 화면에 출력되어야 하는지 설정 
    - visible, invisible, gone
    - invisible : 뷰가 화면에 보이지 않지만 자리는 차지 
    - gone : 자리조차 차지하지 않음

<img src="https://github.com/BangYunseo/TIL/blob/main/Android/Image/ch01/ch01-07-visibility.PNG" width="70%" height="auto" />  


```xml
<!-->invisible 속성 사용<!-->

<Button
    android:layout_width="wrap_content"
    android:layout_height="wrap_content"
    android:text="BUTTON1"
    android:backgroundTint="#0000ff"
    android:visibility="invisible"/>
```

- 코틀린 코드에서 뷰의 visibility 속성 조정
    - 뷰의 visibility 속성값을 View.VISIBLE이나 View.INVISIBLE로 설정

```kt
// visibility 속성값 변경

visibleBtn.setOnClickListener{
    targetBiew.visibility = View.VISIBLE
}
invisibleBtn.setOnClickListener{
    targetBiew.visibility = View.INVISIBLE
}
```

## 3절. 기본적인 뷰

### 텍스트 뷰 (TextView)

- 문자열을 화면에 출력하는 뷰

    - android:text 속성 : TextView에 출력할 문자열 지정
        - android:text="Hello, world!"     
        - android:text="@string/hello"
    - android:textColor 속성 : 문자열 색상 지정
        - android:textColor="#FF0000"
    - android:textSize 속성 : 문자열의 크기를 지정
        - android:textSize="20sp"
    - android:textStyle 속성 : 문자열의 스타일을 지정
        - android:textStyle="bold"
        - bold, italic, normal 중 선택

```xml
<!-->TextView 속성 사용<!-->

<TextView
    android:layout_width="match_parent"
    android:layout_height="wrap_content"
    android:text="HelloWorld!"
    android:backgroundTint="#ff0000"
    android:textSize="20sp"
    android:textStyle="bold"/>
```

<img src="https://github.com/BangYunseo/TIL/blob/main/Android/Image/ch01/ch01-08-TextView.PNG" width="70%" height="auto" />  


- android:autoLink 속성 : 출력할 문자열 분석 후 특정 형태의 문자열에 자동 링크 추가
    - android:autoLink="web"
    - web, phone, email 등을 사용

```xml
<!-->자동 링크 속성 사용<!-->

<TextView
    android:layout_width="match_parent"
    android:layout_height="wrap_content"
    android:text="방윤서 블로그 -
                깃허브 : http://github.com/BangYunseo,
                전화 : 010-0000-0000,
                이메일 : email@gmail.com"
    android:autoLink="web|email|phone"/>
```

<img src="https://github.com/BangYunseo/TIL/blob/main/Android/Image/ch01/ch01-09-autoLink.PNG" width="50%" height="auto" /> 

- android:maxLines 속성 : 문자열이 특정 줄까지만 출력하는 속성
    - android:maxLines="3"
- android:ellipsize 속성 : 문자열이 더 있다는 것을 표시하기 위한 줄임표(...) 추가
    - end, middle, start 값 지정

```xml
<!-->문자열 출력 속성 사용<!-->

<TextView
    android:layout_width="match_parent"
    android:layout_height="wrap_content"
    android:text="@string/long_text"
    android:singleLine="true"
    android:ellipsize="middle"/>
<View
    android:layout_width="match_parent"
    android:layout_height="2dp"
    android:background="#000000">
<TextView
    android:layout_width="match_parent"
    android:layout_height="wrap_content"
    android:text="@string/long_text"
    android:maxLines="3"
    android:ellipsize="end"/>
```

<img src="https://github.com/BangYunseo/TIL/blob/main/Android/Image/ch01/ch01-10-Lines.PNG" width="70%" height="auto" /> 

### 이미지 뷰

- 이미지를 화면에 출력하는 뷰
- android:src 속성 : 출력할 이미지 설정
    - android:src="@drawable/lake_1"
- android:maxWidth, android:maxHeight, android:adjustViewBounds 속성 
    - 이미지의 최대 크기 지정 
    - maxWidth, maxHeight 속성은 android:adjustViewBounds 속성과 함께 사용
    - true로 설정하면 이미지의 가로세로 길이와 비례해 뷰의 크기를 맞춤

```xml
<!-->이미지 크기에 뷰 맞추기<!-->

<ImageView
    android:layout_width="wrap_content"
    android:layout_height="wrap_content"
    android:maxWidth="100dp"
    android:maxHeight="100dp"
    android:adjustViewBounds="true"
    android:src="@drawable/lake_1"
    android:background="#0000ff"/>
```

<img src="https://github.com/BangYunseo/TIL/blob/main/Android/Image/ch01/ch01-11-Lake.PNG" width="60%" height="auto" /> 

### 체크박스, 라디오 버튼

- Button : 사용자 이벤트를 처리
- CheckBox : 다중 선택 제공 뷰
- RadioButton : 단일 선택 제공 뷰
    - RadioGroup과 함께 사용
    - 그룹으로 묶은 라디오 버튼 중 하나만 선택할 수 있게 설정

```xml
<!-->버튼 예시 사용<!-->

<Button
        android:layout_width="wrap_content"
        android:layout_height="wrap_content"
        android:text="BUTTON1"/>
    <CheckBox
        android:layout_width="wrap_content"
        android:layout_height="wrap_content"
        android:text="check1" />
    <CheckBox
        android:layout_width="wrap_content"
        android:layout_height="wrap_content"
        android:text="check2"/>
    <RadioGroup
        android:layout_width="wrap_content"
        android:layout_height="wrap_content">
        <RadioButton
            android:layout_width="wrap_content"
            android:layout_height="wrap_content"
            android:text="radio1"/>
        <RadioButton
            android:layout_width="wrap_content"
            android:layout_height="wrap_content"
            android:text="radio2"/>
    </RadioGroup>
```

<img src="https://github.com/BangYunseo/TIL/blob/main/Android/Image/ch01/ch01-12-Buttons.PNG" width="50%" height="auto" /> 


### 에디트 텍스트

- 글을 입력할 수 있는 뷰
    - android:lines : 처음부터 여러 줄 입력 크기로 나오게 하는 속성
    - android:maxLines : 처음에는 한 줄 입력 크기로 출력, 이후 지정 크기로 늘어나는 속성
    - android:inputType 속성
        - 글을 입력할 때 올라오는 키보드를 지정하는 속성
            - android:inputType="phone"

```xml
<!-->키보드 지정 속성 사용<!-->

<EditText
    android:layout_width="match_parent"
    android:layout_height="wrap_content"
    android:inputType="phone" />
```

<img src="https://github.com/BangYunseo/TIL/blob/main/Android/Image/ch01/ch01-13-keyboards.PNG" width="60%" height="auto" /> 

|속성값|설명|
|:---|:----|
|none|입력 유형을 지정하지 않은 상태<br>모든 문자 입력 가능하며 줄바꿈 가능|
|text|문자열 한 줄 입력|
|textCaoCharacters|대문자 입력 모드|
|textCapWords|각 단어의 첫 글자 입력 시 키보드가 자동 대문자 입력 모드|
|textCaoSentences|각 문단의 첫 글자 입력 시 키보드가 자동 대문자 입력 모드|
|textMultiLine|여러 줄 입력 가능|
|textNoSuggestions|단어 입력 시 키보드의 추천 단어를 보여주지 않음|
|textUri|URL 입력 모드|
|textEmailAddress|이메일 주소 입력 모드|
|textPassword|비밀번호 입력 모드로 입력한 문자 점으로 표시<br>키보드는 영문자와 숫자, 특수 키만 표시|
|textVisiblePassword|textPassword와 같으며 입력한 문자 표시|
|number|숫자 입력 모드|
|numberSigned|number와 같으며 부호 키인 마이너스(-) 입력 가능|
|numberDecimal|number와 같으며 소숫점 입력 가능|
|numberPassword|숫자 키만 입력 가능<br>입력한 문자는 점으로 표시|
|phone|전화번호 입력 모드|

## 4절. 뷰 바인딩

### 뷰 바인딩
- 레이아웃 XML 파일에 선언한 뷰 객체를 코드에서 쉽게 이용하는 방법
- 액티비티에서 findViewById() 함수를 이용하지 않고 레이아웃 XML 파일에 등록된 뷰 객체를 쉽게 사용할 수는 방법 제공

```kt
// 그래들 파일에 뷰 바인딩 설정

android{
    // (..생략)
    viewBinding.isEnabled = true
}
```

- 레이아웃 XML 파일에 등록된 뷰 객체를 포함하는 클래스 자동 생성
- 자동으로 만들어지는 클래스의 이름은 레이아웃 XML 파일명
- 글자는 대문자, 밑줄(_)은 제외, 뒤에 오는 단어를 대문자로 만든 후 'Binding' 추가
    - activity_main.xml → ActivityMainBinding
    - item_main.xml → ItemMainBinding
- inflate() 함수 : 자동으로 만들어진 클래스에서 호출 시 바인딩 객체 획득 가능   
- setContentView() 함수 : 액티비티 화면 출력을 위해 binding.root를 전달

## 5절. 카카오톡 비밀번호 확인 화면 만들기

### 1단계) 새 모듈 생성

- [File → New → New Module] 메뉴
- Application/Library name 부분 Ch6_View 입력

<img src="https://github.com/BangYunseo/TIL/blob/main/Android/Image/ch01/ch01-14-modules.PNG" width="70%" height="auto" /> 

### 2단계) 문자열 리소스 등록

- res/values/strings.xml 파일 수정

<img src="https://github.com/BangYunseo/TIL/blob/main/Android/Image/ch01/ch01-15-strings.PNG" width="70%" height="auto" /> 

### 3단계) 레이아웃 XML 파일 작성

- activity_main.xml 파일 수정

<img src="https://github.com/BangYunseo/TIL/blob/main/Android/Image/ch01/ch01-15-strings.PNG" width="70%" height="auto" /> 

```xml
<!-->activity_main.xml 파일 수정<!-->

<?xml version="1.0" encoding="utf-8"?>
<LinearLayout xmlns:android="http://schemas.android.com/apk/res/android"
    xmlns:app="http://schemas.android.com/apk/res-auto"
    xmlns:tools="http://schemas.android.com/tools"
    android:id="@+id/main"
    android:layout_width="match_parent"
    android:layout_height="match_parent"
    tools:context=".MainActivity"
    android:orientation="vertical"
    android:padding="16dp">

    <TextView
        android:layout_width="match_parent"
        android:layout_height="wrap_content"
        android:text="@string/main_desc"
        android:textSize="17dp" />

    <TextView
        android:layout_width="match_parent"
        android:layout_height="wrap_content"
        android:text="Honggildong@gmail.com"
        android:layout_marginTop="10dp"
        android:textColor="#CFCFCE" />

    <View
        android:layout_width="match_parent"
        android:layout_height="1dp"
        android:layout_marginTop="10dp"
        android:background="#D4D4D3" />

    <EditText
        android:layout_width="match_parent"
        android:layout_height="wrap_content"
        android:hint="password"
        android:inputType="textPassword" />

    <TextView
        android:layout_width="match_parent"
        android:layout_height="wrap_content"
        android:layout_marginTop="10dp"
        android:text="@string/password_txt" />

    <Button
        android:layout_width="match_parent"
        android:layout_height="wrap_content"
        android:layout_marginTop="16dp"
        android:text="확인"  />

</LinearLayout>
```

### 4단계) 실행

<img src="https://github.com/BangYunseo/TIL/blob/main/Android/Image/ch01/ch01-16-excution.PNG" width="70%" height="auto" /> 

