# Chapter 9. 리소스 퐐용하기

> '깡샘의 안드로이드 앱 프로그래밍 with 코틀린' 9장 학습 내용
>
> 1절. 리소스 종류와 특징
>
> 2절. 리소스 조건 설정
>
> 3절. 폰 크기의 호환성
>
> 4절. 메신저 앱 인트로 화면


## 1절. 리소스 종류와 특징

### 앱 리소스 활용

- 리소스 디렉토리명 : 고정
- 리소스 파일명 : values에 추가하는 파일 제외 자바의 이름 작성 규칙 준수
- 알파벳 대문자 사용 불가

|디렉토리 명|리소스 종류|
|:---:|:---|
|animator|속성 애니메이션 XML|
|anim|트윈 애니메이션 XML|
|color|색상 상태 목록 정의 XML|
|drawble|이미지 리소스|
|mipmap|앱 실행 아이콘 리소스|
|layout|레이아웃 XML|
|menu|메뉴 구성 XML|
|raw|원시 형태로 이용되는 리소스 파일|
|values|단순 값으로 이용되는 리소스|
|xml|특정 디렉토리가 정의되지 않은 나머지 XML 파일|
|font|글꼴 리소스|

- layout 디렉토리 : 레이아웃 리소스
- drawble 디렉토리 : 이미지 리소스
  - 이미지 : PNG, JPG, GIF, 9.PNG
  - XML 작성 이미지도 가능

```xml
<--!>XML로 작성한 이미지<!-->

<shape xmlns:android="http://schemas.android.com/apk/res/android"
  android:shape="rectangle">
  <gradient
    android:startColor="#FFFF0000"
    android:endColor="#80FF00FF"
    android:angle="45" />
  <corners android:radius="8dp"/>
</shape>
```

```xml
<--!>XML 이미지를 사용하는 예시<!-->

<ImageView
  android:layout_width="300dp"
  android:layout_height="300dp"
  android:src="@drawble/gradient_box"/>
```

|태그|설명|
|:---:|:---|
|<shape>|도형을 의미<br><br>android:shape="rectangle"처럼 shape 속성을 이용해 도형의 타입 지정<br><br>shape 값은 rectangle, oval, line, ring 중 선택 가능|
|<corners>|둥근 모서리를 그릴 경우 사용하며 shape 값이 rectangle인 경우에만 적용|
|<gradient>|그라데이션 색상 지정|
|<size>|도형의 크기 지정|
|<solid>|도형의 색상 지정|
|<stroke>|도형의 윤곽선 지정|

- mipmap 디렉토리 : 실행 아이콘 리소스
- valus 디렉토리 : 값 리소스
- 문자열 색상, 크기, 스타일, 배열 등의 값 XML로 저장
- values 디렉토리의 리소스 파일은 파일명이 R인 파일에 식별자로 등록되지 않고 리소스 파일에 값을 지정한 태그의 name 속성값이 등록

```xml
<--!>문자열 리소스 등록<!-->

<resources>
  <string name="app_name">TestCh09</string>
  <string name="text_data1">Hello!</string>
  <string name="text_data2">World</string>
</resources>
```

```xml
<--!>XML에서 문자열 리소스 사용<!-->

<TextView
  android:id="@+id/textView"
  android:layout_width="wrap_content"
  android:layout_height="wrap_content"
  android:text="@string/text_data1"/>
```

```kt
// 코드에서 문자열 리소스 사용

binding.textView.text = getString(R.string.text_data2)
```

```xml
<--!>색상 리소스 등록<!-->

<resources>
  <color name="text_color">#FFFF00</color>
  <color name="text_bg_color">#FF0000</color>
</resources>
```

```xml
<--!>크기 리소스 등록<!-->

<resources>
  <dimen name="text_size">20sp</dimen>
</resources>
```

```xml
<--!>XML에서 색상, 크기 리소스 사용<!-->

<TextView
  android:id="@+id/textView"
  android:layout_width="wrap_content"
  android:layout_height="wrap_content"
  android:text="@string/text_data1"
  android:textColor="@color/text_color"
  android:background="@color/text_bg_color"
  android:textSize="@dimen/text_size"/>
```

```kt
// 코드에서 색상과 크기 리소스 사용

binding.textView.text = getString(R.string.text_data2)
binding.textView.setTextColor(ResourcesCompat.getColor(resources, R.color.text_color, null))
binding.textView.textSize = resources.getDimension(R.dimen.text_size)
```

- style 태그 : 스타일 리소스
   - 뷰에 설정되는 여러 속성을 스타일에 적용하여 한꺼번에 적용

```xml
<--!>스타일 등록<!-->

<resources>
  <style name="MyTextStyle">
    <item name="android:textSize">@dimen/text_size</item>
    <item name="android:textColor">@color/text_color</item>
  </style>
  <style name="MyTextStyleSub" parent="MyTextStyle">
    <item name="android:textColor">#0000FF</item>
    <item name="android:background">@color/text_bg_color</item>
  </style>
</resources>
```

```xml
<--!>스타일 리소스 사용<!-->

<TextView
  android:layout_width="match_parent"
  android:layout_height="wrap_content"
  android:style="@style/MyTextStyleSub"
  android:text="Hello, world!" />
```

- color 디렉토리 : 색상 리소스
  - 특정 뷰의 상태를 표현하고 그 상태에 적용되는 색상을 등록
 
```xml
<--!>색상 리소스 등록<!-->

<?xml version="1.0" encoding="utf-8"?>
<selector xmlns:android="http://schemas.android.com/apk/res/android>
  <item android:state_pressed="true"
        android:color="#ffff0000" />
  <item android:state_focused="true"
        android:color="#ff0000ff" />
  <item android:color="#ff000000" />
</selector>
```

```xml
<--!>색상 리소스 사용<!-->

<Button
  android:layout_width="match_parent"
  android:layout_height="wrap_content"
  android:text="Click Me!!"
  android:textColor="@color/button_text" />
```

- font 디렉토리 : 글꼴 리소스

```xml
<--!>글꼴 리소스 사용<!-->

<TextView
  android:layout_width="wrap_content"
  android:layout_height="wrap_content"
  android:text="Hello, World"
  android:textSize="20dp"
  android:fontFamily="@font/pacifico" />
```

### 플랫폼 리소스 사용

<img src="https://github.com/BangYunseo/TIL/blob/main/Android/Image/ch09/ch09-01-package.PNG" width="100%" height="auto" />

- 안드로이드 플랫폼이 제공하는 리소스
- android.R이라는 플랫폼 라이브러리의 R 파일에 등록



## 2절. 리소스 조건 설정

### 리소스 조건 설정

<img src="https://github.com/BangYunseo/TIL/blob/main/Android/Image/ch09/ch09-02-icon1.PNG" width="100%" height="auto" />

- 리소스를 특정 환경에서만 적용되도록 설정
- 기기 별 실행 아이콘 크기
  
|화면 밀도|크기|
|:---:|:---|
|XXXHDPI|192 * 192|
|XXHDPI|144 * 144|
|XHDPI|96 * 96|
|HDPI|72 * 72|
|MDPI|48 * 48|

<img src="https://github.com/BangYunseo/TIL/blob/main/Android/Image/ch09/ch09-03-icon2.PNG" width="100%" height="auto" />

- 리소스 디렉터리 이름에서 붙임표(-) 뒤의 단어가 리소스의 조건
- mipmap-mdpi 디렉터리 : mdpi 조건

|조건|예시|설명|
|:---:|:---|:---|
|MCC 및 MNC|mcc310<br>mcc310-mnc004|이동통신 국가 코드(MCC)와 선택적으로 이동통신 네트워크 코드(MNC) 추가 가능<br>mcc310은 미국이며 mcc310-mnc004는 버라이즌을 이용하는 미국을 의미|
|언어 및 지역|en<br>ko-rKR|ISO639-1 언어 코드이며 선택적으로 뒤에 소문자 r을 추가해 ISO3166-1-alpha-2의 지역코드가 나올 수 있음|
|레이아웃 방향|ldrtl<br>ldltr|히브리어처럼 오른쪽에서 왼쪽으로 쓰는 언어의 레이아웃에서 유용하게 이용 가능<br>ldrtl은 오른쪽 -> 왼쪽<br>ldltr은 왼쪽 -> 오른쪽 방향 레이아웃|
|더 작은 쪽|sw320dp|화면 크기 중 더 작은 쪽에 대한 조건<br>화면 방향과 상관없이 화면의 높이와 너비 중 작은 쪽에 대한 조건 의미<br>sw320dp이면 너비든 높이든 상관없이 작은 쪽의 치수가 320dp인 경우 의미|
|이용 가능 너비|w720dp|화면 너비에 대한 조건<br>w720dp일 경우 너비가 720인 기기|
|이용 가능 높이|h720dp|화면 높이에 대한 조건<br>h720dp일 경우 높이가 720인 기기|
|화면 크기|small, normal, large, xlarge|화면 크기를 small, normal, large, xlarge로 판단해 조건 명시<br>small은 320 * 428, normal은 320 * 470, large는 480 * 640, xlarge는 720 * 960 정도의 크기|
|화면 비율|long, notlong|화면의 종횡비 조건<br>long은 WQVGA, WVGA, FWVGA 등 긴 화면, notlong은 QVGA, HVGA, VGA 등 길지 않은 화면|
|원형 화면|round, notround|원형화면인지 판단

(여기부터 작성)

### scope 함수

: 범위 함수
- 라이브러리가 제공하는 클래스 or 프로그래머가 생성한 클래스의 매개 변수나 안의
1) apply & also : 객체 자체 return
2) run(==with)& let : 실행 결과 return

a.run {}
// 람다함수 형태

with(a)

it 사용

