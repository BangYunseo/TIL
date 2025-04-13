# Chapter 4. 리소스 활용

> '깡샘의 안드로이드 앱 프로그래밍 with 코틀린' 9장 학습 내용
>
> 1절. 리소스 종류와 특징
>
> 2절. 리소스 조건 설정
>
> 3절. 폰 크기의 호환성
>
> 4절. 메신저 앱 인트로 화면   
> [프로젝트 바로가기](https://github.com/BangYunseo/TIL/tree/main/Android/androidProject/ch04/)

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
<!-->XML로 작성한 이미지<!-->

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
<!-->XML 이미지를 사용하는 예시<!-->

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
<!-->문자열 리소스 등록<!-->

<resources>
  <string name="app_name">TestCh09</string>
  <string name="text_data1">Hello!</string>
  <string name="text_data2">World</string>
</resources>
```

```xml
<!-->XML에서 문자열 리소스 사용<!-->

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
<!-->색상 리소스 등록<!-->

<resources>
  <color name="text_color">#FFFF00</color>
  <color name="text_bg_color">#FF0000</color>
</resources>
```

```xml
<!-->크기 리소스 등록<!-->

<resources>
  <dimen name="text_size">20sp</dimen>
</resources>
```

```xml
<!-->XML에서 색상, 크기 리소스 사용<!-->

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
<!-->스타일 등록<!-->

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
<!-->스타일 리소스 사용<!-->

<TextView
  android:layout_width="match_parent"
  android:layout_height="wrap_content"
  android:style="@style/MyTextStyleSub"
  android:text="Hello, world!" />
```

- color 디렉토리 : 색상 리소스
  - 특정 뷰의 상태를 표현하고 그 상태에 적용되는 색상을 등록
 
```xml
<!-->색상 리소스 등록<!-->

<?xml version="1.0" encoding="utf-8"?>
<selector xmlns:android="http://schemas.android.com/apk/res/android">
  <item android:state_pressed="true"
        android:color="#ffff0000" />
  <item android:state_focused="true"
        android:color="#ff0000ff" />
  <item android:color="#ff000000" />
</selector>
```

```xml
<!-->색상 리소스 사용<!-->

<Button
  android:layout_width="match_parent"
  android:layout_height="wrap_content"
  android:text="Click Me!!"
  android:textColor="@color/button_text" />
```

- font 디렉토리 : 글꼴 리소스

```xml
<!-->글꼴 리소스 사용<!-->

<TextView
  android:layout_width="wrap_content"
  android:layout_height="wrap_content"
  android:text="Hello, World"
  android:textSize="20dp"
  android:fontFamily="@font/pacifico" />
```

### 플랫폼 리소스 사용

<img src="https://github.com/BangYunseo/TIL/blob/main/Android/Image/ch04/ch04-01-package.PNG" width="100%" height="auto" />

- 안드로이드 플랫폼이 제공하는 리소스
- android.R이라는 플랫폼 라이브러리의 R 파일에 등록



## 2절. 리소스 조건 설정

### 리소스 조건 설정

<img src="https://github.com/BangYunseo/TIL/blob/main/Android/Image/ch04/ch04-02-icon1.PNG" width="100%" height="auto" />

- 리소스를 특정 환경에서만 적용되도록 설정
- 기기 별 실행 아이콘 크기
  
|화면 밀도|크기|
|:---:|:---|
|XXXHDPI|192 * 192|
|XXHDPI|144 * 144|
|XHDPI|96 * 96|
|HDPI|72 * 72|
|MDPI|48 * 48|

<img src="https://github.com/BangYunseo/TIL/blob/main/Android/Image/ch04/ch04-03-icon2.PNG" width="100%" height="auto" />

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
|원형 화면|round, notround|원형화면인지 판단<br>round는 웨어러블 기기처럼 둥근 화면을 가지는 기기<br>notround는 폰이나 태블릿처럼 사각형  화면의 기기|
|화면 방향|port, land|화면의 방향에 대한 조건<br>port는 세로 방향, land는 가로 방향|
|UI 모드|car, dest, television, application, watch, vrheadset|기기가 도크에 삽입되거나 제거될 때 대응하기 위한 조건<br>car는 자동차, desk는 데스크, television은 TV, application은 표시되지 않은 제품|
|야간 모드|night, notnight|야간 모드에 대응하기 위한 조건<br>night는 야간, notnight는 주간|
|화면 픽셀 밀도|ldpi, mdpi, hdpi, xhdpi, xxhdpi, xxxhdpi, nodpi, tvdpi, anydpi, nnndpi|화면 밀도에 대한 조건<br>ldpi는 120dpi, mdpi는 160dpi, hdpi는 240dpi, xhdpi는 320dpi, xhdpi는 320dpi, xxhdpi는 480dpi, xxxdpi는 640dpi, nodpi는 크기를 조정하지 않을 리소스에 사용|
|터치 스크린 유형|notouch, finger|터치 스크린을 제공하는지 판단<br>notouch는 터치 스크린이 없는 기기|
|키보드 가용성|keysexposed, keyshidden, keyssoft|키보드의 유형<br>keyssoft는 소프트 키보드, keysexposed는 키보드가 노출되어 있는 기기, keyshidden은 키보드가 있으나 숨길 수 있는 기기|
|기본 텍스트 입력방법|nokeys, qwerty, 12key|nokeys는 하드웨어 키보드가 없는 경우, qwerty는 하드웨어 쿼티 키보드가 있는 경우, 12key는 하드웨어 12키가 있는 경우|
|탐색 키 가용성|navexposed, navhidden|탐색 키 사용 가능 조건<br>navexposed는 탐색 키 사용 가능, navhidden은 탐색 키 사용 불가|
|기본 비터치 탐색 방법|nanav, dpad, trackball, wheel|터치하지 않고 탐색이 가능한 기기가 있는지 판단|
|플랫폼 버전|v21|기기의 API 레벨|

### 화면 회전에 대응

- 방향에 따라 화면을 다르게 제공 (land)
- 리소스 조건으로 설정하여 처리

### 국제 언어 제공

- 리소스 문자열을 각국 언어로 제공
- 파일을 여러 개 생성하여 각 언어에 맞는 리소스 문자열을 담고 어느 XML 파일을 적용해야 하는지 리소스 디렉토리명으로 지정

<img src="https://github.com/BangYunseo/TIL/blob/main/Android/Image/ch04/ch04-04-languageResources.PNG" width="100%" height="auto" />

```xml
<!-->영어 문자열 리소스 예시<!-->

<resources>
  <string name="app_name">test9</string>
  <string name="intro">Hello</string>
</resources>
```

```xml
<!-->한국어 문자열 리소스 예시<!-->

<resources>
  <string name="app_name">테스트9</string>
  <string name="intro">안녕!</string>
</resources>
```

## 3절. 폰 크기의 호환성

### 논리적인 단위

- dpi (dots per inch의 줄임말)
  - 1인치 안에 있는 도트의 개수
  - 크기 지정에 사용할 수 있는 단위

- dp (dip : density-independent pixels)  : 스크린의 물리적 밀도에 기반을 둔 단위
- sp (sip : scale-independent pixels) : dp와 유사하며 글꼴 크기에 적용
- pt (points) : 스크린 크기의 1 / 72을 1pt로 함
- px : 픽셀 (물리적 밀도와 관계 X)
- mm : 밀리미터
- in : 인치

|크기|설명|
|:---:|:---|
|ldpi|저밀도 화면<br>~120dpi|
|mdpi|중밀도 화면<br>~160dpi|
|hdpi|고밀도 화면<br>~240dpi|
|xhdpi|초고밀도 화면<br>~320dpi|
|xxhdpi|초초고밀도 화면<br>~480dpi|
|xxxhdpi|초초초고밀도 화면<br>~640dpi|

- mdpi 폰에서 1dp = 1px
- xxhdpi 폰은 개발자가 지정한 크기보다 3배 크게 출력

|크기|배율|
|:---:|:---:|
|ldpi|0.75|
|mdpi|1.0|
|hdpi|1.5|
|xhdpi|2.0|
|xxhdpi|3.0|
|xxxhdpi|4.0|

### 화면 정보 가져오기

- 30 이전 버전에서는 DisplayMetrics로 크기 정보 활용
- 30 버전부터는 (deprecation), WindowMetrics 활용

```kotlin
// 기기의 가로, 세로 크기 가져오기

if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.R){
  val windowMetrics: WindowMetrics = windowManager.currentWindowMetrics
  binding.textView.text = "width : ${windowMetrics.bounds.width()}, 
                          height : ${windowMetrics.bounds.height()}"
} else {
  val display = windowManager.defaultDisplay
  val displayMetrics = DisplayMetrics()
  display?.getRealMetrics(displayMetrics)
  binding.textView.text = "width : ${displayMetrics.widthPixels},
                          height : ${displayMetrics.heightPixels}"
}
```

### scope 함수

: 범위 함수
- 라이브러리가 제공하는 클래스 or 프로그래머가 생성한 클래스의 매개 변수
1) apply & also : 객체 자체 return
2) run(==with)& let : 실행 결과 return

```kt
// scope 함수 사용 예시

package com.yunseo_33.ch09

fun main(){
    // 1) 만들 때부터 할인 중임을 알리며 가격을 깎은 경우
    var a = Book("걸리버의 모험", 10000).apply{
        name = "[폭탄 세일 중!]" + name
        discount()
    }
    // => apply 함수 : 생성과 동시에 클래스의 매개 변수 값을 바꾸고자 할 때 사용
    // println("상품명 : ${a.name}, 가격 : ${a.price}")

    // 2) 객체를 활용하여 마지막 값(price + 2000)만 리턴할 경우
    var bookCost = a.run {
        println("상품명 : ${name}, 가격 : ${price}")
        price + 2000
    }

    // => run 함수 : 마지막 값을 통해 매개 변수 값을 바꾸고자 할 때 사용
    println("원가 : $bookCost ")

    // 3) 객체를 활용하여 마지막 값(price + 2000)만 리턴할 경우
    var bookCost2 = with(a) {
        println("상품명 : ${name}, 가격 : ${price}")
        price + 2000
    }

    // => with 함수 : 마지막 값을 통해 매개 변수 값을 바꾸고자 할 때 사용
    // run 함수와 리턴이 같으며 함수 꼴로 표현하는 점만 다름
    println("원가 : $bookCost2 ")

    // 4) 같은 변수가 함수 안에서 충돌이 날 경우 사용
    var price = 999999999

    a.let {
        println("상품명 : ${it.name}, 가격 : ${it.price}")
    }
    // let 함수 안에 멤버 변수를 활용할 경우 it을 사용하여 안의 멤버 변수 지정
    // this와 같은 사용법
}

class Book(var name: String, var price: Int){
    fun discount() {
        price -= 2000
    }
}
```

## 4절. 메신저 앱 인트로 화면 만들기

### 1) 새 모듈 생성

- Ch09_resource 모듈 생성

### 2) 리소스 파일 준비

- round_button.xml 파일과 intro.png 파일 drawable 디렉터리에 복사

<img src="https://github.com/BangYunseo/TIL/blob/main/Android/Image/ch04/ch04-05-drawable.PNG" width="100%" height="auto" />

### 3) 언어 별 문자열 리소스 작성

- strings.xml 파일 작성

```XML
<!-->strings.xml<!-->

<resources>
    <string name="app_name">Ch09_resource</string>
    <string name="intro_main">
        Find your phone contacts on Messenger.
    </string>
    <string name="intro_detail">
        Continuously uploading your contacts helps Facebook and Messenger
        suggest connections and provide and improve ads for you and others,
        and offer a better service.
    </string>
    <string name="intro_more">Learn More ?</string>
    <string name="intro_button">TURN ON</string>
    <string name="intro_delay">NOT NOW</string>
</resources>
```

- values-ko-rKR/strings.xml 파일 생성 후 작성

```XML
<!-->strings.xml<!-->

<resources>
    <string name = "app_name">ch09</string>
    <string name="intro_main">
        메신저에서 휴대폰 연락처에 있는 사람들을 찾아보세요.
    </string>
    <string name = "intro_detail">
        연락처를 계속 업로드하면 Facebook 및 Messenger에서 연결된 연락처를 추천하고 회원님과 다른 사람들에게 더욱 관련성 높은 광고를 표시하여 더 나은 서비스를 제공하는데 도움이 됩니다.
    </string>
    <string name = "intro_more">더 알아볼까요 ?</string>
    <string name = "intro_button">설정</string>
    <string name = "intro_delay">나중에 하기</string>
</resources>
```

<img src="https://github.com/BangYunseo/TIL/blob/main/Android/Image/ch04/ch04-06-values.PNG" width="100%" height="auto" />


### 4) 세로 방향 화면 구성

- activity_main.xml 파일 작성

```XML
<!-->activity_main.xml<!-->

<?xml version="1.0" encoding="utf-8"?>
<RelativeLayout xmlns:android="http://schemas.android.com/apk/res/android"
    xmlns:app="http://schemas.android.com/apk/res-auto"
    xmlns:tools="http://schemas.android.com/tools"
    android:id="@+id/main"
    android:layout_width="match_parent"
    android:layout_height="match_parent"
    android:padding="20dp">

    <ImageView
        android:id="@+id/imageView"
        android:layout_width="wrap_content"
        android:layout_height="wrap_content"
        android:layout_centerHorizontal="true"
        android:src="@drawable/intro" />

    <TextView
        android:id="@+id/mainTextView"
        android:layout_width="match_parent"
        android:layout_height="wrap_content"
        android:layout_below="@+id/imageView"
        android:layout_centerHorizontal="true"
        android:layout_marginTop="20dp"
        android:gravity="center_horizontal"
        android:text="@string/intro_main"
        android:textStyle="bold"
        android:textSize="20dp" />

    <TextView
        android:id="@+id/detailTextView"
        android:layout_width="match_parent"
        android:layout_height="wrap_content"
        android:layout_below="@+id/mainTextView"
        android:layout_centerHorizontal="true"
        android:layout_marginTop="20dp"
        android:gravity="center_horizontal"
        android:text="@string/intro_detail" />

    <TextView
        android:id="@+id/delayTextView"
        android:layout_width="match_parent"
        android:layout_height="wrap_content"
        android:layout_alignParentBottom="true"
        android:layout_centerHorizontal="true"
        android:layout_marginTop="20dp"
        android:gravity="center_horizontal"
        android:text="@string/intro_delay" />

    <Button
        android:layout_width="match_parent"
        android:layout_height="wrap_content"
        android:layout_above="@+id/delayTextView"
        android:layout_centerHorizontal="true"
        android:layout_marginBottom="20dp"
        android:text="@string/intro_button"
        android:textColor="#FFFFFF"
        android:background="@drawable/round_button"
        android:padding="10dp"/>

</RelativeLayout>
```

<img src="https://github.com/BangYunseo/TIL/blob/main/Android/Image/ch04/ch04-07-landout.PNG" width="100%" height="auto" />


### 5) 가로 방향 화면 구성

- layout-land/activity_main.xml 파일 생성 후 작성

```XML
<!-->layout-land/activity_main.xml<!-->

<?xml version="1.0" encoding="utf-8"?>
<RelativeLayout xmlns:android="http://schemas.android.com/apk/res/android"
    xmlns:app="http://schemas.android.com/apk/res-auto"
    xmlns:tools="http://schemas.android.com/tools"
    android:id="@+id/main"
    android:layout_width="match_parent"
    android:layout_height="match_parent"
    android:padding="20dp">

    <TextView
        android:id="@+id/mainTextView"
        android:layout_width="match_parent"
        android:layout_height="wrap_content"
        android:layout_centerHorizontal="true"
        android:layout_marginTop="20dp"
        android:gravity="center_horizontal"
        android:text="@string/intro_main"
        android:textStyle="bold"
        android:textSize="20dp" />

    <TextView
        android:id="@+id/detailTextView"
        android:layout_width="match_parent"
        android:layout_height="wrap_content"
        android:layout_below="@+id/mainTextView"
        android:layout_centerHorizontal="true"
        android:layout_marginTop="20dp"
        android:gravity="center_horizontal"
        android:text="@string/intro_detail" />

    <TextView
        android:id="@+id/delayTextView"
        android:layout_width="match_parent"
        android:layout_height="wrap_content"
        android:layout_alignParentBottom="true"
        android:layout_centerHorizontal="true"
        android:layout_marginTop="20dp"
        android:gravity="center_horizontal"
        android:text="@string/intro_delay" />

    <Button
        android:layout_width="match_parent"
        android:layout_height="wrap_content"
        android:layout_above="@+id/delayTextView"
        android:layout_centerHorizontal="true"
        android:layout_marginBottom="20dp"
        android:text="@string/intro_button"
        android:textColor="#FFFFFF"
        android:background="@drawable/round_button" />

</RelativeLayout>
```

<img src="https://github.com/BangYunseo/TIL/blob/main/Android/Image/ch04/ch04-08-land.PNG" width="100%" height="auto" />
