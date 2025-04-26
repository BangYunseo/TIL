/ 1# Chapter 2. 뷰 배치 레이아웃

> '깡샘의 안드로이드 앱 프로그래밍 with 코틀린' 8장 학습 내용
>
> 1절. LinearLayout : 선형 배치
>
> 2절. RelativeLayout : 상대 위치 배치
>
> 3절. FrameLayout : 겹쳐서 배치
>
> 4절. GridLayout : 표 형태 배치
>
> 5절. ConstraintLayout : 계층 구조 배치
>
> 6절. 전화 앱 키배드 화면 만들기  
> [프로젝트 바로가기](https://github.com/BangYunseo/AndroidProject/tree/main/ch02)

## 1절. LinearLayout : 선형 배치

### LinearLayout 배치 규칙

- 뷰를 가로나 세로 방향으로 나열하는 레이아웃
- orientation 속성 : horizontal / vertical 값으로 방향 지정

```XML
<!-->LinearLayout의 방향 속성 설정<!-->

<LinearLayout xmlns:android="http://schemas.android.com/apk/res/android"
    android:id="@+id/main"
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

<img src="https://github.com/BangYunseo/TIL/blob/main/Android/Image/ch02/ch02-01-Buttons.PNG" width="30%" height="auto" />

- LinearLayout 중첩
- 레이아웃 클래스도 뷰이므로 다른 레이아웃 클래스에 포함 가능

| <img src="https://github.com/BangYunseo/TIL/blob/main/Android/Image/ch02/ch02-02-LinearLayouts.PNG" height="auto" /> | <img src="https://github.com/BangYunseo/TIL/blob/main/Android/Image/ch02/ch02-03-LinearLayouts2.PNG" height="auto" /> |
| -------------------------------------------------------------------------------------------------------------------- | --------------------------------------------------------------------------------------------------------------------- |

### 여백을 채우는 layout_weight 속성

- 여백을 뷰로 채우고자 할 경우 사용 : 뷰 1개로 전체 여백 채우기

```XML
<!-->여백 없이 채우는 weight 속성<!-->

<LinearLayout xmlns:android="http://schemas.android.com/apk/res/android"
    android:layout_width="match_parent"
    android:layout_height="match_parent"
    android:orientation="horizontal">
    <Button
        android:layout_width="wrap_content"
        android:layout_height="wrap_content"
        android:text="BUTTON1"
        android:layout_weight="1"/>
    <Button
        android:layout_width="wrap_content"
        android:layout_height="wrap_content"
        android:text="BUTTON2"/>
</LinearLayout>
```

<img src="https://github.com/BangYunseo/TIL/blob/main/Android/Image/ch02/ch02-04-Layoutweight.PNG" width="40%" height="auto" />

- 뷰 여러 개로 여백 나누어 채우기
  - layout_weight 속성에 지정한 숫자 : 가중치

```XML
<!-->layout_weight값을 각각 1과 3으로 선언<!-->
<!-->가로 여백을 각각 1/4만큼, 3/4만큼 나누어 차지<!-->

    <Button
        android:layout_width="wrap_content"
        android:layout_height="wrap_content"
        android:text="BUTTON1"
        android:layout_weight="1"/>
    <Button
        android:layout_width="wrap_content"
        android:layout_height="wrap_content"
        android:text="BUTTON2"
        android:layout_weight="3"/>
```

<img src="https://github.com/BangYunseo/TIL/blob/main/Android/Image/ch02/ch02-05-Layoutweight2.PNG" width="70%" height="auto" />

- 중첩된 레이아웃에서 여백 채우기

| <img src="https://github.com/BangYunseo/TIL/blob/main/Android/Image/ch02/ch02-06-Layoutweight3.PNG" height="40%" /> | <img src="https://github.com/BangYunseo/TIL/blob/main/Android/Image/ch02/ch02-07-Layoutweight4.PNG" height="20%" /> |
| ------------------------------------------------------------------------------------------------------------------- | ------------------------------------------------------------------------------------------------------------------- |

```XML
<!-->중첩된 레이아웃에서 여백 채우기<!-->

<LinearLayout xmlns:android="http://schemas.android.com/apk/res/android"
    android:layout_width="match_parent"
    android:layout_height="match_parent"
    android:orientation="vertical">
    <LinearLayout
        android:layout_width="match_parent"
        android:layout_height="wrap_content"
        android:orientation="horizontal">
        <Button
            android:layout_width="wrap_content"
            android:layout_height="wrap_content"
            android:text="BUTTON1"
            android:layout_weight="1"/>
        <Button
            android:layout_width="wrap_content"
            android:layout_height="wrap_content"
            android:text="BUTTON2"
            android:layout_weight="3"/>
    </LinearLayout>
    <Button
        android:layout_width="match_parent"
        android:layout_height="wrap_content"
        android:text="BUTTON3"
        android:layout_weight="1"/>
    <Button
        android:layout_width="match_parent"
        android:layout_height="wrap_content"
        android:text="BUTTON4" />
</LinearLayout>
```

- 여백 채우기로 뷰의 크기 설정

<img src="https://github.com/BangYunseo/TIL/blob/main/Android/Image/ch02/ch02-08-Layoutweight5.PNG" width="30%" height="auto" />

```XML
<!-->layout_weight값으로 뷰의 크기 설정<!-->

<LinearLayout xmlns:android="http://schemas.android.com/apk/res/android"
    android:layout_width="match_parent"
    android:layout_height="match_parent"
    android:orientation="vertical">
    <Button
        android:layout_width="match_parent"
        android:layout_height="0dp"
        android:text="BUTTON1"
        android:layout_weight="1"/>
    <Button
        android:layout_width="match_parent"
        android:layout_height="0dp"
        android:text="BUTTON2"
        android:layout_weight="1"/>
    <Button
        android:layout_width="match_parent"
        android:layout_height="0dp"
        android:text="BUTTON3"
        android:layout_weight="1" />
</LinearLayout>
```

### 뷰를 정렬하는 gravity, layout_gravity 속성

- 뷰에 gravity와 layout_gravity 속성 적용
  - gravity 속성 : 정렬 대상은 콘텐츠
  - layout_gravity : 뷰 자체를 정렬하는 속성

<img src="https://github.com/BangYunseo/TIL/blob/main/Android/Image/ch02/ch02-09-gravity.PNG" width="30%" height="auto" />

```XML
<!-->뷰 정렬<!-->

<LinearLayout xmlns:android="http://schemas.android.com/apk/res/android"
    android:layout_width="match_parent"
    android:layout_height="match_parent"
    android:orientation="vertical">
    <TextView
        android:layout_width="150dp"
        android:layout_height="150dp"
        android:background="#FF0000"
        android:textSize="15dp"
        android:textStyle="bold"
        android:textColor="#FFFFFF"
        android:text="Hello, World"
        android:gravity="right|bottom"
        android:layout_gravity="center_horizontal" />
</LinearLayout>
```

- 레이아웃에 gravity 속성 적용

```XML
<!-->화면 가운데 정렬<!-->

<LinearLayout xmlns:android="http://schemas.android.com/apk/res/android"
    android:layout_width="match_parent"
    android:layout_height="match_parent"
    android:orientation="vertical"
    android:gravity="center">
    <TextView
        android:layout_width="150dp"
        android:layout_height="150dp"
        android:background="#FF0000"
        android:textSize="15dp"
        android:textStyle="bold"
        android:textColor="#FFFFFF"
        android:text="Hello, World"
        android:gravity="right|bottom"
        android:layout_gravity="center_horizontal" />
</LinearLayout>
```

<img src="https://github.com/BangYunseo/TIL/blob/main/Android/Image/ch02/ch02-10-gravity2.PNG" width="30%" height="auto" />

## 2절. RelativeLayout : 상대 위치 배치

### RelativeLayout 배치 규칙

- 상대 뷰의 위치를 기준으로 정렬하는 레이아웃
  - android:layout_above : 기준 뷰의 위쪽에 배치
  - android:layout_below : 기준 뷰의 아래쪽에 배치
  - android:layout_toLeftOf : 기준 뷰의 왼쪽에 배치
  - android:layout_toRightOf : 기준 뷰의 오른쪽에 배치

```xml
<!-->상대 뷰의 오른쪽에 배치<!-->

<RelativeLayout xmlns:android="http://schemas.android.com/apk/res/android"
    android:layout_width="match_parent"
    android:layout_height="match_parent">
    <ImageView
        android:id="@+id/testImage"
        android:layout_width="wrap_content"
        android:layout_height="wrap_content"
        android:src="@mipmap/ic_launcher" />
    <Button
        android:layout_width="wrap_content"
        android:layout_height="wrap_content"
        android:text="Hello!"
        android:layout_toRightOf="@id/testImage" />
</RelativeLayout>
```

<img src="https://github.com/BangYunseo/TIL/blob/main/Android/Image/ch02/ch02-11-toRightOf.PNG" width="30%" height="auto" />

### align 속성

- 상대 뷰의 어느 쪽에 맞춰서 정렬할지를 정하는 속성
  - android:layout_alignTop : 기준 뷰와 위쪽을 맞춤
  - android:layout_alignBottom : 기준 뷰와 아래쪽을 맞춤
  - android:layout_alignLeft : 기준 뷰와 왼쪽을 맞춤
  - android:layout_alignRight : 기준 뷰와 오른쪽을 맞춤
  - android:layout_alignBaseline : 기준 뷰와 텍스트 기준선을 맞춤

```xml
<!-->기준 뷰와 아래쪽을 맞춰 정렬<!-->

<RelativeLayout xmlns:android="http://schemas.android.com/apk/res/android"
    android:layout_width="match_parent"
    android:layout_height="match_parent">
    <ImageView
        android:id="@+id/testImage"
        android:layout_width="wrap_content"
        android:layout_height="wrap_content"
        android:src="@mipmap/ic_launcher" />
    <Button
        android:layout_width="wrap_content"
        android:layout_height="wrap_content"
        android:text="Hello!"
        android:layout_toRightOf="@id/testImage"
        android:layout_alignBottom="@id/testImage" />
</RelativeLayout>
```

<img src="https://github.com/BangYunseo/TIL/blob/main/Android/Image/ch02/ch02-12-alignbottom.PNG" width="30%" height="auto" />

### Parent / Center

- 상위 레이아웃을 기준으로 맞춤 정렬하는 속성
  - android:layout_alignParentTop : 부모의 위쪽에 맞춤
  - android:layout_alignParentBottom : 부모의 아래쪽에 맞춤
  - android:layout_alignParentLeft : 부모의 왼쪽에 맞춤
  - android:layout_alignParentRight : 부모의 오른쪽에 맞춤
  - android:layout_centerHorizontal : 부모의 가로 방향 중앙에 맞춤
  - android:layout_centerVertical : 부모의 세로 방향 중앙에 맞춤
  - android:layout_centerInParent : 부모의 가로·세로 중앙에 맞춤

```xml
<!-->부모의 오른쪽에 맞춰 정렬<!-->

<RelativeLayout xmlns:android="http://schemas.android.com/apk/res/android"
    android:layout_width="match_parent"
    android:layout_height="match_parent">
    <ImageView
        android:id="@+id/testImage"
        android:layout_width="wrap_content"
        android:layout_height="wrap_content"
        android:src="@mipmap/ic_launcher" />
    <Button
        android:layout_width="wrap_content"
        android:layout_height="wrap_content"
        android:text="Hello!"
        android:layout_alignBottom="@id/testImage"
        android:layout_alignParentRight="true" />
</RelativeLayout>
```

<img src="https://github.com/BangYunseo/TIL/blob/main/Android/Image/ch02/ch02-13-parentright.PNG" width="30%" height="auto" />

## 3절. FrameLayout : 겹쳐서 배치

### FrameLayout

- 카드를 쌓듯이 뷰를 추가한 순서대로 위에 겹쳐서 계속 출력하는 레이아웃
- visibility 속성 : 대부분 뷰의 표시 여부를 설정

```xml
<!-->FrameLayout에 버튼과 이미지 추가<!-->

<FrameLayout xmlns:android="http://schemas.android.com/apk/res/android"
    android:layout_width="match_parent"
    android:layout_height="match_parent">
    <Button
        android:layout_width="match_parent"
        android:layout_height="wrap_content"
        android:text="BUTTON1" />
    <ImageView
        android:layout_width="wrap_content"
        android:layout_height="wrap_content"
        android:src="@mipmap/ic_launcher" />
</FrameLayout>
```

<img src="https://github.com/BangYunseo/TIL/blob/main/Android/Image/ch02/ch02-14-framelayout.PNG" width="30%" height="auto" />

```kt
// visibility 속성값을 바꾸는 액티비티 코드
class MainActivity : AppCompatActivity() {
    override fun onCreate(savedInstanceState: Bundle?){
        super.onCreate(savedInstanceState)

        val binding = ActivityMainBinding.inflate(layoutInflater)
        setContentView(binding.root)

        binding.button.setOnClickListener{
            binding.button.visibility = View.INVISIBLE
            binding.imageView.visibility = View.VISIBLE
            // 버튼은 숨기고 이미지는 보이도록 설정
        }
        binding.imageView.setOnClickListener{
            binding.button.visibility = View.VISIBLE
            binding.imageView.visibility = View.INVISIBLE
            // 버튼은 보이고 이미지는 숨기도록 설정
        }
    }
}
```

## 4절. GridLayout : 표 형태 배치

### GridLayout 배치 규칙

- 테이블 화면을 만드는 레이아웃이며 줄바꿈 자동 설정
  - orientation : 가로나 세로 방향으로 뷰를 나열 설정
  - rowCount : 세로로 나열할 뷰 개수
  - columnCount : 가로로 나열할 뷰 개수

<img src="https://github.com/BangYunseo/TIL/blob/main/Android/Image/ch02/ch02-15-gridlayout.PNG" width="30%" height="auto" />

```xml
<!-->열 개수 지정<!-->

<GridLayout xmlns:android="http://schemas.android.com/apk/res/android"
    android:layout_width="match_parent"
    android:layout_height="match_parent"
    android:orientation="horizontal"
    android:columnCount="3" >
    <Button android:text="A" />
    <Button android:text="B" />
    <Button android:text="C" />
    <Button android:text="D" />
    <Button android:text="E" />
</GridLayout>
```

<img src="https://github.com/BangYunseo/TIL/blob/main/Android/Image/ch02/ch02-16-gridlayout2.PNG" width="30%" height="auto" />

```xml
<!-->행 개수 지정<!-->

<GridLayout xmlns:android="http://schemas.android.com/apk/res/android"
    android:layout_width="match_parent"
    android:layout_height="match_parent"
    android:orientation="vertical"
    android:rowCount="3" >
    <Button android:text="A" />
    <Button android:text="B" />
    <Button android:text="C" />
    <Button android:text="D" />
    <Button android:text="E" />
</GridLayout>
```

### GridLayout 속성

- 특정 뷰의 위치 조정
  - layout_row : 뷰가 위치하는 세로 방향 인덱스
  - layout_column : 뷰가 위치하는 가로 방향 인덱스

```xml
<!-->뷰 위치 조정<!-->

<GridLayout xmlns:android="http://schemas.android.com/apk/res/android"
    android:layout_width="match_parent"
    android:layout_height="match_parent"
    android:orientation="hotizontal"
    android:columnCount="3" >
    <Button android:text="A" />
    <Button android:text="B" />
    <Button android:text="C"
        android:layout_row="1"
        android:layout_column="1" />
    <Button android:text="D" />
    <Button android:text="E" />
</GridLayout>
```

<img src="https://github.com/BangYunseo/TIL/blob/main/Android/Image/ch02/ch02-17-gridlayout3.PNG" width="30%" height="auto" />

- layout_gravity 속성 : 특정 뷰의 크기 확장

```xml
<!-->뷰 위치 조정<!-->

<GridLayout xmlns:android="http://schemas.android.com/apk/res/android"
    android:layout_width="match_parent"
    android:layout_height="match_parent"
    android:orientation="hotizontal"
    android:columnCount="3" >
    <Button android:text="A" />
    <Button android:text="HELLO, WORLD! HELLO, WORLD!" />
    <Button android:text="C" />
    <Button android:text="D" />
    <Button android:text="E"
        android:layout_gravity="fill_horizontal"/>
    <Button android:text="F" />
</GridLayout>
```

<img src="https://github.com/BangYunseo/TIL/blob/main/Android/Image/ch02/ch02-18-gridlayout4.PNG" width="30%" height="auto" />

- 한 칸에 여러 뷰 표시

```xml
<!-->여백에 다음 뷰 넣기<!-->

<GridLayout xmlns:android="http://schemas.android.com/apk/res/android"
    android:layout_width="match_parent"
    android:layout_height="match_parent"
    android:orientation="hotizontal"
    android:columnCount="3" >
    <Button android:text="A" />
    <Button android:text="HELLO, WORLD! HELLO, WORLD!" />
    <Button android:text="C" />
    <Button android:text="D" />
    <Button android:text="E" />
    <Button android:text="F"
        android:layout_row="1"
        android:layout_column="1"
        android:layout_gravity="right" />
</GridLayout>
```

<img src="https://github.com/BangYunseo/TIL/blob/main/Android/Image/ch02/ch02-19-gridlayout5.PNG" width="30%" height="auto" />

- 열이나 행 병합
  - layout_columnSpan : 가로로 열 병합
  - layout_rowSpan : 세로로 행 병합

```xml
<!-->여백에 다음 뷰 넣기<!-->

<GridLayout xmlns:android="http://schemas.android.com/apk/res/android"
    android:layout_width="match_parent"
    android:layout_height="match_parent"
    android:orientation="hotizontal"
    android:columnCount="3" >
    <Button android:text="A"
        android:layout_columnSpan="2"
        android:layout_rowSpan="2"
        android:layout_gravity="fill" />
    <Button android:text="B" />
    <Button android:text="C" />
    <Button android:text="D" />
    <Button android:text="E" />
    <Button android:text="F" />
</GridLayout>
```

<img src="https://github.com/BangYunseo/TIL/blob/main/Android/Image/ch02/ch02-20-gridlayout6.PNG" width="40%" height="auto" />

## 5절. ConstraintLayout : 계층 구조 배치

- androidx에서 제공하는 라이브러리

```kt
constraintlayout 사용을 위한 빌드 설정

implemetation(Libs.androidx.constraintlayout)
```

### 레이아웃 편집기에서 레이아웃 구성

- 상대 위치로 배치하는 RelativeLayout과 비슷하지만 더 많은 속성을 제공

<img src="https://github.com/BangYunseo/TIL/blob/main/Android/Image/ch02/ch02-21-constraint.PNG" width="70%" height="auto" />

1. 팔레트(Palette)
2. 컴포넌트 트리(Component Tree)
3. 툴바(Toolbar)
4. 디자인 편집기(Design editor)
5. 속성(Attributes)
6. 보기 모드(View mode)

- 이미지 추가

| <img src="https://github.com/BangYunseo/TIL/blob/main/Android/Image/ch02/ch02-22-Image.PNG" height="auto" /> | <img src="https://github.com/BangYunseo/TIL/blob/main/Android/Image/ch02/ch02-23-Image2.PNG" height="auto" /> |
| ------------------------------------------------------------------------------------------------------------ | ------------------------------------------------------------------------------------------------------------- |

## 6절. 전화 앱 키배드 화면 만들기

### 1단계) 새로운 모듈 생성

- Ch07_Layout 모듈 생성

### 2단계) 실습 파일 복사

- add.png, back.png, call.png, video.png 파일을 res/drawable 디렉터리에 복사

<img src="https://github.com/BangYunseo/TIL/blob/main/Android/Image/ch02/ch02-24-drawable.PNG" width="40%" height="auto" />

### 3단계) 메인 액티비티 작성

```XML
<!-->activity_main.xml 파일 작성<!-->

<?xml version="1.0" encoding="utf-8"?>
<LinearLayout xmlns:android="http://schemas.android.com/apk/res/android"
    xmlns:app="http://schemas.android.com/apk/res-auto"
    xmlns:tools="http://schemas.android.com/tools"
    android:layout_width="match_parent"
    android:layout_height="match_parent"
    tools:context=".MainActivity"
    android:id="@+id/main"
    android:orientation="vertical"
    android:gravity="center_horizontal">

    <LinearLayout
        android:layout_width="wrap_content"
        android:layout_height="wrap_content"
        android:orientation="horizontal"
        android:layout_marginTop="20dp">

        <ImageView
            android:layout_width="15dp"
            android:layout_height="15dp"
            android:src="@drawable/add"
            app:tint="#00FF00" />

        <TextView
            android:layout_width="wrap_content"
            android:layout_height="wrap_content"
            android:text="연락처 추가"
            android:textColor="#00FF00"
            android:textStyle="bold"/>
    </LinearLayout>

    <TextView
        android:layout_width="wrap_content"
        android:layout_height="wrap_content"
        android:layout_marginTop="100dp"
        android:text="02-120"
        android:textSize="40dp"/>

    <GridLayout
        android:layout_width="wrap_content"
        android:layout_height="wrap_content"
        android:layout_marginTop="10dp"
        android:columnCount="3"
        android:orientation="horizontal">
        <TextView
            android:paddingLeft="40dp"
            android:paddingBottom="10dp"
            android:paddingTop="10dp"
            android:paddingRight="40dp"
            android:text="1"
            android:textStyle="bold"
            android:textSize="30dp"/>
        <TextView
            android:paddingLeft="40dp"
            android:paddingBottom="10dp"
            android:paddingTop="10dp"
            android:paddingRight="40dp"
            android:text="2"
            android:textStyle="bold"
            android:textSize="30dp"/>
        <TextView
            android:paddingLeft="40dp"
            android:paddingBottom="10dp"
            android:paddingTop="10dp"
            android:paddingRight="40dp"
            android:text="3"
            android:textStyle="bold"
            android:textSize="30dp"/>
        <TextView
            android:paddingLeft="40dp"
            android:paddingBottom="10dp"
            android:paddingTop="10dp"
            android:paddingRight="40dp"
            android:text="4"
            android:textStyle="bold"
            android:textSize="30dp"/>
        <TextView
            android:paddingLeft="40dp"
            android:paddingBottom="10dp"
            android:paddingTop="10dp"
            android:paddingRight="40dp"
            android:text="5"
            android:textStyle="bold"
            android:textSize="30dp"/>
        <TextView
            android:paddingLeft="40dp"
            android:paddingBottom="10dp"
            android:paddingTop="10dp"
            android:paddingRight="40dp"
            android:text="6"
            android:textStyle="bold"
            android:textSize="30dp"/>
        <TextView
            android:paddingLeft="40dp"
            android:paddingBottom="10dp"
            android:paddingTop="10dp"
            android:paddingRight="40dp"
            android:text="7"
            android:textStyle="bold"
            android:textSize="30dp"/>
        <TextView
            android:paddingLeft="40dp"
            android:paddingBottom="10dp"
            android:paddingTop="10dp"
            android:paddingRight="40dp"
            android:text="8"
            android:textStyle="bold"
            android:textSize="30dp"/>
        <TextView
            android:paddingLeft="40dp"
            android:paddingBottom="10dp"
            android:paddingTop="10dp"
            android:paddingRight="40dp"
            android:text="9"
            android:textStyle="bold"
            android:textSize="30dp"/>
        <TextView
            android:paddingLeft="40dp"
            android:paddingBottom="10dp"
            android:paddingTop="10dp"
            android:paddingRight="40dp"
            android:text="*"
            android:textStyle="bold"
            android:textSize="30dp"/>
        <TextView
            android:paddingLeft="40dp"
            android:paddingBottom="10dp"
            android:paddingTop="10dp"
            android:paddingRight="40dp"
            android:text="0"
            android:textStyle="bold"
            android:textSize="30dp"/>
        <TextView
            android:paddingLeft="40dp"
            android:paddingBottom="10dp"
            android:paddingTop="10dp"
            android:paddingRight="40dp"
            android:text="#"
            android:textStyle="bold"
            android:textSize="30dp"/>
    </GridLayout>

    <RelativeLayout
        android:layout_width="wrap_content"
        android:layout_height="wrap_content"
        android:layout_marginTop="20dp">
        <ImageView
            android:layout_width="50dp"
            android:layout_height="50dp"
            android:id="@+id/icon_video"
            android:layout_marginRight="30dp"
            android:src="@drawable/video"/>
        <ImageView
            android:layout_width="50dp"
            android:layout_height="50dp"
            android:id="@+id/icon_call"
            android:layout_toRightOf="@+id/icon_video"
            android:src="@drawable/call"/>
        <ImageView
            android:layout_width="50dp"
            android:layout_height="50dp"
            android:layout_marginLeft="30dp"
            android:layout_toRightOf="@+id/icon_call"
            android:src="@drawable/back"/>
    </RelativeLayout>
</LinearLayout>
```

### 4단계) 앱 실행

<img src="https://github.com/BangYunseo/TIL/blob/main/Android/Image/ch02/ch02-25-ex.PNG" width="70%" height="auto" />
