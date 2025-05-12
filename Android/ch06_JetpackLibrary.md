# Chapter 6. 제트팩 라이브러리

> '깡샘의 안드로이드 앱 프로그래밍 with 코틀린' 11장 학습 내용
>
> 0절. ART
>
> 1절. 제트팩
>
> 2절. androidx
>
> 3절. appcompat 라이브러리
>
> 4절. 프래그먼트
>
> 5절. 리사이클러 뷰
>
> 6절. 뷰 페이저2
>
> 7절. 드로어 레이아웃
>
> 8장. 제트팩 화면 구성   
> [프로젝트 바로가기](https://github.com/BangYunseo/AndroidProject/tree/main/ch07)

## 0절. ART

### 플랫폼 API

- ART에서 제공하는 안드로이드 라이브러리

<img src="https://github.com/BangYunseo/TIL/blob/main/Android/Image/ch06/ch06-01-JavaAPI.PNG" height="auto" />

## 1절. 제트팩

### 제트팩(JetPack)

- 구글에서 안드로이드 앱 개발용으로 제공하는 다양한 라이브러리
- androidx로 시작하는 패키지명
  - 앱을 개발 시 필요 권장 아키텍처 제공
  - API 레벨 호환성 문제 해결
  - 플랫폼 API에서 제공하지 않는 다양한 기능 제공

## 2절. androidx

### androidx 라이브러리

- 화면 구성과 관련된 라이브러리

|    라이브러리 종류    | 설명                             |
| :-------------------: | :------------------------------- |
|  androidx.appcompat   | 앱 API 레벨 호환성 해결          |
| androidx.recyclerview | 목록 화면 구성                   |
|  androidx.viewpager2  | 스와이프로 넘기는 화면 구성      |
|   androidx.fragment   | 액티비티처럼 동작하는 뷰 제공    |
| androidx.drawerlayout | 옆에서 서랍처럼 열리는 화면 구성 |

## 3절. appcompat 라이브러리

### appcompat 라이브러리

- 안드로이드 앱 화면 구성 액티비티 생성
- API 레벨 호환성 문제 해결

```kt
// appcompat 라이브러리 선언

implementation(lib.androidx.appcompat)
```

```kt
// appcompat 라이브러리 사용

import androidx.appcompat.app.AppCompatActivity

class MainActivity : AppCompatActivity() {

}
```

### 문자열 출력 구성

| 타이틀 문자열 출력 부분 구성 방법 |
| :-------------------------------: |
|            액션바 이용            |
|             툴바 이용             |

<img src="https://github.com/BangYunseo/TIL/blob/main/Android/Image/ch06/ch06-02-ToolBar.PNG" height="auto" />

- 구성 방법은 액티비티에 적용되는 테마 설정에 의해 결정

<img src="https://github.com/BangYunseo/TIL/blob/main/Android/Image/ch06/ch06-03-Theme.PNG" height="auto" />

```xml
<!-- themes.xml 테마 스타일 선언 -->

<resources xmlns:tools="http://schemas.android.com/tools">
    <!-- 기본 테마 -->
    <style name="Base.Theme.AndroidLab" parent="Theme.Material3.DayNight.NoActionBar">
        <!-- light 테마 지정 -->
        <!-- <item name="colorPrimary">@color/my_light_primary</item> -->
    </style>

    <style name="Theme.AndroidLab" parent="Base.Theme.AndroidLab" />
</resources>
```

```xml
<!-- AndroidManifest.xml 적용 내용 확인 -->

<application
    android:allowBackup="true"
    android:icon="@mipmap/ic_launcher"
    android:label="@string/app_name"
    android:roundIcon="@mipmap/ic_launcher_round"
    android:supportsRtl="true"
    android:theme="@style/Theme.AndroidLab" >
    <!-- 생략 -->

</application>
```

### 툴바

- 레이아웃 XML에 androidx.appcompat.widtet.Toolbar 클래스 선언
- 코드에서 액션바의 내용이 툴바에 적용되도록 지정 필요

```xml
<!-- 레이아웃 XML에 툴바 적용 -->

<androidx.appcompat.widget.Toolbar
    android:id="@+id/toolbar"
    android:layout_width="match_parent"
    android:layout_height="?attr/actionBarSize"
    android:background="?attr/colorPrimary"
    android:elevation="4dp"
    android:theme="@style/ThemmeOverlay.AppCompat.ActionBar"
    app:titleTextColor="#FFFFFF" />
```

<img src="https://github.com/BangYunseo/TIL/blob/main/Android/Image/ch06/ch06-04-MatchToolBar.PNG" height="auto" />

```kt
// 액션바 내용 툴바 적용

setSupportActionBar(binding.toolbar)
```

|     구성 요소     |
| :---------------: |
|   타이틀 문자열   |
| 내비게이션 아이콘 |
|    액션 아이템    |
|   오버플로 메뉴   |

<img src="https://github.com/BangYunseo/TIL/blob/main/Android/Image/ch06/ch06-05-ActionBar.PNG" height="auto" />

#### 툴바 색상 설정

- 앱 적용 테마에 의한 결정

|      속성      |                   설명                    |
| :------------: | :---------------------------------------: |
|  colorPrimary  |            툴바 · 버튼 배경색             |
|  colorAccent   | 스위치 켬(on) 상황처럼 활성모드 상태 표현 |
| statusBarColor |               상태바 배경색               |

```xml
<!-- 테마 색상 지정 -->
<style name="Base.Theme.AndroidLab" parent="Theme.Material3.DayNight.NoActionBar">
    <item name="colorPrimary">#FF0000</item>
    <item name="android:statusBarColor">#CC0000</item>
    <item name="colorAccent">#00FF00</item>
</style>
```

<img src="https://github.com/BangYunseo/TIL/blob/main/Android/Image/ch06/ch06-06-ToolBarColor.PNG" height="auto" />

#### 업 버튼 설정

- 액션바 왼쪽에 이전 화면으로 되돌아가는 화살표 모양(←) 업 버튼

<img src="https://github.com/BangYunseo/TIL/blob/main/Android/Image/ch06/ch06-07-UpButton.PNG" height="auto" />

|                  등록 방법                   |
| :------------------------------------------: |
| 액티비티가 등록된 AndroidManifest.xml에 등록 |
|             액티비티 코드로 등록             |

```xml
<!-- AndroidManifest.xml에서 업버튼 설정 -->

<activity
    android:name=".test1.TwoActivity"
    android:exported="false"
    android:parentActivityName=".MainActivity"/>
```

```kt
// 툴바에 업버튼 설정

supportActionBar?.setDisplayHomeAsUpEnabled(true)
```

- onSupportNavigateUp() 함수 재정의
  - 업버튼 실행 시 특별한 로직 실행
  - AndroidManifest.xml 설정 없이 코드에서 업버튼 설정 희망

```kt
// 사용자가 업버튼 실행 시 함수 자동 호출되는 onSupportNavigateUp() 함수 재정의
override fun onSupportNavigateUp(): Boolean{
    Log.d("Yunseo", "onSupportNavigateUp")
    return super.onSupportNavigateUp()
}
```

### 메뉴 구성

- 메뉴
  - 툴바의 중요한 구성 요소
  - 액티비티 화면에서 사용자 이벤트 사용 허용

| 액티비티 메뉴 추가 함수 | 설명                                                                     |
| :---------------------: | :----------------------------------------------------------------------- |
|  onCreateOptionsMenu()  | 액티비티 첫 1회만 호출                                                   |
| onPrepareOptionsMenu()  | 액티비티 첫 실행 한 번 호출된 후 오버플로 메뉴가 나타날 때마다 반복 호출 |

<img src="https://github.com/BangYunseo/TIL/blob/main/Android/Image/ch06/ch06-08-Menu.PNG" height="auto" />

```kt
override fun onCreateOptionsMenu(menu: Menu?): Boolean{
    val menuItem1: MenuItem? = menu?,add(0, 0, 0, "menu1")
    val menuItem2: MenuItem? = menu?,add(0, 1, 0, "menu2")
    return super.onCreateOptionsMenu(menu)
}
```

<img src="https://github.com/BangYunseo/TIL/blob/main/Android/Image/ch06/ch06-09-Menu2.PNG" height="auto" />

### 이벤트 처리

- onOptionsItemSelected() : 사용자가 메뉴 선택 시 이벤트 처리
- 함수 매개 변수 : 이벤트가 발생한 메뉴 객체(MenuItem)

```kt
// 메뉴 선택 시 이벤트 처리

override fun onOptionsItemSelected(item: MenuItem): Boolean = when(item.itemId){
    0 -> {
        Log.d("Yunseo", "menu1 click")
        true
    }
    1 -> {
        Log.d("Yunseo", "menu2 click")
        true
    }
    else -> super.onOptionsItemSelected(item)
}
```

### 리소스 메뉴 구현

- 메뉴 구성 XML 파일은 res/menu 디렉터리에 생성

<img src="https://github.com/BangYunseo/TIL/blob/main/Android/Image/ch06/ch06-10-Menu3.PNG" height="auto" />

```xml
<!-- menu_main.xml -->

<menu xmlns:android="http://schemas.android.com/apk/res/android"
    xmlns:app="http://schemas.android.com/apk/res-auto">

    <item
        android:id="@+id/menu1"
        android:title="menu1" />

    <item
        android:id="@+id/menu2"
        android:icon="@android:drawable/ic_menu_add"
        android:title="menu2"
        app:showAsAction="always" />

    <item
        android:id="@+id/menu3"
        android:icon="@android:drawable/ic_menu_search"
        android:title="menu3"
        app:showAsAction="iffRoom" />

</menu>
```

#### showAsActions 속성

- 액션바 아이콘 출력

| 속성값 종류 | 설명 |
| :---------: | :--- |

|never(기본): 항상 오버플로 메뉴로 출력합니다.
 ifRoom: 만약 액션바에 공간이 있다면 액션 아이템으로, 없다면 오버플로 메뉴로 출력합니다.  always: 항상 액션 아이템으로 출력합니다.|

```kt
// 액티비티 코드 메뉴 XML 적용

override fun onCreateOptionsMenu(menu: Menu?): Boolean{
    menuInflate.inflate(R.menu.menu_main, menu)
    return super.onCreateOptionsMenu(menu)
}
```

<img src="https://github.com/BangYunseo/TIL/blob/main/Android/Image/ch06/ch06-11-Menu4.PNG" height="auto" />

### 액션 뷰 이용

(여기부터 작성 : 11장 18p)

## 4절. 프래그먼트

## 5절. 리사이클러 뷰

## 6절. 뷰 페이저2

## 7절. 드로어 레이아웃

## 8장. 제트팩 화면 구성

### 1) 새 모듈 생성

- Ch11_JetPack 이름의 새 모듈 생성

### 2) 빌드 그래들 작성

- 뷰 바인딩 설정

### 3) 문자열 리소스 생성

- res/values/strings.xml 파일에 ActionBarDrawerToggle 생성 시 지정할 문자열 리소스 추가

```xml

```
