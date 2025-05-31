# Chapter 7. 머터리얼 라이브러리

> '깡샘의 안드로이드 앱 프로그래밍 with 코틀린' 12장 학습 내용
>
> 1절. 앱바
>
> 2절. 탭 레이아웃
>
> 3절. 내비게이션 뷰
>
> 4절. 확장 플로팅 액션 버튼
>
> 5절. 머터리얼 화면 구성  
> [프로젝트 바로가기](https://github.com/BangYunseo/AndroidProject/tree/main/ch08)

## 1절. 앱바

### 머터리얼(Material) 라이브러리

- 구글의 "머터리얼 디자인"
- 모바일, 데스크톱, 다양한 장치 등을 아우르는 일관된 애플리케이션 디자인 지침

```kt
// 머터리얼 라이브러리 선언

implementation(libs.material)
```

### 앱바 레이아웃

- 앱바 : 화면 위쪽의 꾸밀 수 있는 영역
- 화면 위쪽 영역 꾸미기

<img src="https://github.com/BangYunseo/TIL/blob/main/Android/Image/ch07/ch07-01-AppBar.PNG" height="auto" />

#### 툴바 포함

```xml
<com.google.android.material.appbar.AppBarLayout
    android:id="@+id/appbar"
    android:layout_width="match_parent"
    android:layout_height="wrap_content"
    android:theme="@style.ThemeOverlay.AppCompat.ActionBar">
    <androidx.appcompat.widget.Toolbar
        (...생략...)
    />
</com.google.android.material.appbar.AppBarLayout>
```

<img src="https://github.com/BangYunseo/TIL/blob/main/Android/Image/ch07/ch07-02-ToolBar.PNG" height="auto" />

#### 크기 확장

```xml
<com.google.android.material.appbar.AppBarLayout
    (...생략...)
    android:layout_height="242dp">
</com.google.android.material.appbar.AppBarLayout>
```

<img src="https://github.com/BangYunseo/TIL/blob/main/Android/Image/ch07/ch07-03-Height.PNG" height="auto" />

#### 이미지 삽입

```xml
<com.google.android.material.appbar.AppBarLayout ...생략... >
    <androidx.appcompat.widget.Toolbar ...생략.../>
    <ImageView ...생략... />
</com.google.android.material.appbar.AppBarLayout>
```

<img src="https://github.com/BangYunseo/TIL/blob/main/Android/Image/ch07/ch07-04-Image.PNG" height="auto" />

### 코디네이터 레이아웃

- 뷰끼리 상호 작용

#### 스크롤 연동

- 레이아웃 : 뷰끼리 상호작용 시 사용
- 뷰에서 발생한 스크롤 정보를 코디네이터 레이아웃이 전달받아 다른 뷰에 전달

<img src="https://github.com/BangYunseo/TIL/blob/main/Android/Image/ch07/ch07-05-Scroll.PNG" height="auto" />

#### 중첩 스크롤 뷰

- 코디네이터 레이아웃에 중첩 스크롤 뷰(NestedScrollView) 포함
  - 추가로 텍스트 뷰 OR 이미지 뷰를 삽입한 경우
- 뷰에서 발생하는 스크롤 정보를 코디네이터 레아이웃에 전달

```XML
<!-- 중첩 스크롤 뷰 -->

<androidx.coordinatorlayout.widget.CoordinatorLayout ...생략 ... >

    <com.google.android.material.appbar.AppBarLayout ...생략 ... >
        <androidx.appcompat.widget.Toolbar
            app:layout_scrollFlags="scroll|enterAlways" />
        <ImageView
            app:layout_scrollFlags="scroll|enterAlways" />
    </com.google.android.material.appbar.AppBarLayout>

    <androidx.core.widget.NestedScrollView ...생략 ... >
        <TextView
            app:layout_behavior="@string/appbar_scrolling_view_behavior" />
    </androidx.core.widget.NestedScrollView>

</androidx.coordinatorlayout.widget.CoordinatorLayout>
```

<img src="https://github.com/BangYunseo/TIL/blob/main/Android/Image/ch07/ch07-06-NScroll.PNG" height="auto" />

### 컬랩싱 툴바 레이아웃(CollapsingToolbarLayout)

- 앱바 접히는 형태를 설정한 뷰
- 앱바 레이아웃 하위에 선언

|           속성            | 설명                                         |
| :-----------------------: | :------------------------------------------- |
|           title           | 앱바 제목 설정                               |
| expandedTitleMarginStart  | 앱바가 접히지 않은 경우 제목 위치 설정(위)   |
| expandedTitleMarginBottom | 앱바가 접히지 않은 경우 제목 위치 설정(아래) |
|       contentScrin        | 지정 색상 앱바 출력                          |

```XML
<!-- 컬랩싱 툴바 레이아웃 등록 -->

<androidx.coordinatorlayout.widget.CoordinatorLayout ...생략 ... >

    <com.google.android.material.appbar.AppBarLayout ...생략 ... >
        <com.google.android.material.appbar.CollapsingToolbarLayout ...생략 ...
            app:contentScrim="?attr/colorPrimary"
            app:expandedTitleMarginBottom="50dp"
            app:expandedTitleMarginStart="48dp"
            app:layout_scrollFlags="scroll|exitUntilCollapsed"
            app:title="AppBar Title">
            <ImageView ...생략 ...
                app:layout_collapseMode="parallax" />
            <androidx.appcompat.widget.Toolbar ...생략 ...
                app:layout_collapseMode="pin" />
        </com.google.android.material.appbar.CollapsingToolbarLayout>
    </com.google.android.material.appbar.AppBarLayout>

    <androidx.recyclerview.widget.RecyclerView ...생략 ...
        app:layout_behavior="@string/appbar_scrolling_view_behavior" />

</androidx.coordinatorlayout.widget.CoordinatorLayout>
```

<img src="https://github.com/BangYunseo/TIL/blob/main/Android/Image/ch07/ch07-07-CTL.PNG" height="auto" />

### 스크롤 설정

- layout_scrollFlags
- 앱바의 스크롤 여부 설정

<img src="https://github.com/BangYunseo/TIL/blob/main/Android/Image/ch07/ch07-08-scrollFlags.PNG" height="auto" />

|   layout_scrollFlags 속성값    | 설명                                                                                                               |
| :----------------------------: | :----------------------------------------------------------------------------------------------------------------- |
|     scroll \| enterAlways      | 스크롤 시 완전히 사라졌다가 거꾸로 스크롤 시 처음부터 다시 나타남                                                  |
| scroll \| enterAlwaysCollapsed | 스크롤 시 완전히 사라졌다가 거꾸로 스크롤 시 처음부터 나타나지 않고 메인 콘텐츠 부분이 끝까지 스크롤된 후에 나타남 |
|  scroll \| exitUntilCollapsed  | 스크롤 시 모두 사라지지 않고 툴바를 출력할 정도의 한 줄만 남을 때까지 스크롤                                       |

```XML
<!-- scroll | enterAlways 속성값 -->

app:layout_scrollFlags="scroll|enterAlways"
```

<img src="https://github.com/BangYunseo/TIL/blob/main/Android/Image/ch07/ch07-08-eA.PNG" height="auto" />

```XML
<!-- scroll | enterAlwaysCollapsed 속성값 -->

app:layout_scrollFlags="scroll|enterAlwaysCollapsed"
```

<img src="https://github.com/BangYunseo/TIL/blob/main/Android/Image/ch07/ch07-09-eAC.PNG" height="auto" />

```XML
<!-- scroll | exitUntilCollapsed 속성값 -->

app:layout_scrollFlags="scroll|exitUntilCollapsed"
```

<img src="https://github.com/BangYunseo/TIL/blob/main/Android/Image/ch07/ch07-10-eUC.PNG" height="auto" />

### 개별 뷰 스크롤 설정

- layout_collapseMode
- 하위 뷰마다 스크롤 설정

|   속성   | 설명             |
| :------: | :--------------- |
|   pin    | 고정 후 스크롤 X |
| parallax | 함께 스크롤      |

```XML
<!-- 개별 뷰 스크롤 설정 -->

<com.google.android.material.appbar.CollapsingToolbarLayout ...생략 ... >
    <ImageView ...생략 ...
        app:layout_collapseMode="parallax" />
    <androidx.appcompat.widget.Toolbar ...생략 ...
        app:layout_collapseMode="pin" />
</com.google.android.material.appbar.CollapsingToolbarLayout>
```

<img src="https://github.com/BangYunseo/TIL/blob/main/Android/Image/ch07/ch07-11-lcM.PNG" height="auto" />

## 2절. 탭 레이아웃

### 탭 레이아웃

- 탭(tab)으로 구분하는 화면에서 탭 버튼을 배치하는 레이아웃

<img src="https://github.com/BangYunseo/TIL/blob/main/Android/Image/ch07/ch07-12-TL.PNG" height="auto" />

```XML
<!-- 탭 레이아웃 등록 -->

<LinearLayout xmlns:android="http://schemas.android.com/apk/res/android"
    android:layout_width="match_parent"
    android:layout_height="match_parent"
    android:orientation="vertical">
    <com.google.android.material.tabs.TabLayout
        android:id="@+id/tabs"
        android:layout_width="match_parent"
        android:layout_height="wrap_content" />
    <FrameLayout
        android:id="@+id/tabContent"
        android:layout_width="match_parent"
        android:layout_height="match_parent" />
</LinearLayout>
```

```kt
// 탭 버튼 정의

binding.tabs.run {
    val tab1: TabLayout.Tab = newTab()
    tab1.text = "Tab1"
    addTab(tab1)

    val tab2: TabLayout.Tab = newTab()
    tab2.text = "Tab2"
    addTab(tab2)

    val tab3: TabLayout.Tab = newTab()
    tab3.text = "Tab3"
    addTab(tab3)
}
```

- 탭 버튼 정의 없이 activity.xml 파일의 TabItem으로 정의

```XML
<!-- XMl 파일에서 탭 버튼 정의 -->

<com.google.android.material.tabs.TabLayout
    android:id="@+id/tabs"
    android:layout_width="match_parent"
    android:layout_height="wrap_content">
    <com.google.android.material.tabs.TabItem
        android:layout_width="wrap_content"
        android:layout_height="wrap_content"
        android:text="Tab1" />
    <com.google.android.material.tabs.TabItem
        android:layout_width="wrap_content"
        android:layout_height="wrap_content"
        android:text="Tab2" />
    <com.google.android.material.tabs.TabItem
        android:layout_width="wrap_content"
        android:layout_height="wrap_content"
        android:text="Tab3" />
</com.google.android.material.tabs.TabLayout>
```

### 탭 버튼 이벤트 핸들러

<img src="https://github.com/BangYunseo/TIL/blob/main/Android/Image/ch07/ch07-13-TEH.PNG" height="auto" />

```kt
// 탭 버튼 이벤트 처리

binding.tabs.addOnTabSelectedListener(object: TabLayout.OnTabSelectedListener {
    // 탭 버튼을 선택할 때 이벤트
    override fun onTabSelected(tab: TabLayout.Tab?) {
        val transaction = supportFragmentManager.beginTransaction()
        when (tab?.text) {
            "Tab1"-> transaction.replace(R.id.tabContent, OneFragment())
            "Tab2"-> transaction.replace(R.id.tabContent, TwoFragment())
            "Tab3"-> transaction.replace(R.id.tabContent, ThreeFragment())
        }
        transaction.commit()
    }

    // 선택된 탭 버튼을 다시 선택할 때 이벤트
    override fun onTabReselected(tab: TabLayout.Tab?) {
    }

    // 다른 탭 버튼을 눌러 선택된 탭 버튼이 해제될 때 이벤트
    override fun onTabUnselected(tab: TabLayout.Tab?) {
    }
})
```

### 탭 버튼 정렬

- tabGravity : 탭 버튼 정렬 속성

<img src="https://github.com/BangYunseo/TIL/blob/main/Android/Image/ch07/ch07-14-tG.PNG" height="auto" />

### 스크롤 설정

<img src="https://github.com/BangYunseo/TIL/blob/main/Android/Image/ch07/ch07-15-sA.PNG" height="auto" />

|    속성    | 설명                                                                 |
| :--------: | :------------------------------------------------------------------- |
|  tabMode   | 탭 버튼 스크롤 여부 설정                                             |
|   fixed    | 스크롤을 지원 X 설정                                                 |
| scrollable | 탭 버튼이 왼쪽부터 나열<br>모두 출력 불가능 한 경우 자동 가로 스크롤 |

### 뷰 페이저 연동

<img src="https://github.com/BangYunseo/TIL/blob/main/Android/Image/ch07/ch07-16-vp.PNG" height="auto" />

- TabLayout과 ViewPager2 등록 후 코드에서 TabLayoutMediator로 연동

```XML
<!-- 탭 레이아웃과 뷰 페이저 등록 -->

<LinearLayout xmlns:android="http://schemas.android.com/apk/res/android"
    android:layout_width="match_parent"
    android:layout_height="match_parent"
    xmlns:app="http://schemas.android.com/apk/res-auto"
    android:orientation="vertical">
    <com.google.android.material.tabs.TabLayout
        android:id="@+id/tabs"
        android:layout_width="match_parent"
        android:layout_height="wrap_content"
        app:tabMode="scrollable" >
    </com.google.android.material.tabs.TabLayout>
    <androidx.viewpager2.widget.ViewPager2
        android:id="@+id/viewpager"
        android:layout_width="match_parent"
        android:layout_height="match_parent" />
</LinearLayout>
```

```kt
// 탭 레이아웃과 뷰 페이저 연동

TabLayoutMediator(tabLayout, viewPager) { tab, position ->
    tab.text = "Tab$((position + 1))"
}.attach()
```

## 3절. 내비게이션 뷰

### 네비게이션 뷰

- 드로어 화면 구성
  - 위쪽 : 아이콘, 문자열 등
  - 아래쪽 : 메뉴 항목

<img src="https://github.com/BangYunseo/TIL/blob/main/Android/Image/ch07/ch07-17-Ds.PNG" height="auto" />

```XML
<!-- 네비게이션 뷰 등록 -->

<androidx.drawerlayout.widget.DrawerLayout ...생략 ... >
    <LinearLayout ...생략 ... >
        (... 생략 ...)
    </LinearLayout>

    <com.google.android.material.navigation.NavigationView
        android:id="@+id/main_drawer_view"
        android:layout_width="wrap_content"
        android:layout_height="match_parent"
        android:layout_gravity="start"
        app:headerLayout="@layout/navigation_header"
        app:menu="@menu/menu_navigation" />

</androidx.drawerlayout.widget.DrawerLayout>
```

<img src="https://github.com/BangYunseo/TIL/blob/main/Android/Image/ch07/ch07-18-DsEx.PNG" height="auto" />

- 메뉴 구성 XML 파일을 menu 속성에 지정
  - 위의 결과처럼 항목 자동 출력
- setNavigationItemSelectedListener()
  - 항목 선택 이벤트 핸들러 지정
  - DrawerLayout 클래스

```kt
// 항목 선택 이벤트 핸들러

binding.mainDrawerView.setNavigationItemSelectedListener {
    Log.d("kkang", "navigation item click... ${it.title}")
    true
}
```

## 4절. 확장 플로팅 액션 버튼

### 플로팅 액션 버튼

- 화면에 떠있는 버튼

```XML
<!-- 확장 플로팅 액션 버튼 -->

<com.google.android.material.floatingactionbutton.ExtendedFloatingActionButton
    (... 생략 ...)
    android:text="extended FAB"
    app:icon="@android:drawable/ic_input_add" />
```

```kt
// 확장 플로팅 액션 버튼 조절

binding.extendedFab.setOnClickListener {
    when (binding.extendedFab.isExtended) {
        true -> binding.extendedFab.shrink() // 아이콘만 표시
        false -> binding.extendedFab.extend() // 아이콘과 문자열 함께 표시
    }
}
```

<img src="https://github.com/BangYunseo/TIL/blob/main/Android/Image/ch07/ch07-19-FBEx.PNG" height="auto" />

## 5절. 머터리얼 화면 구성

### 1) 새 모듈 생성 & 그래들 설정

- Ch12_Material 새 모듈 생성
- 뷰 바인딩 기법 추가

```kts
viewBinding.isEnabled = true
```

### 2) 파일 복사

- drawable, layout, menu, values 디렉터리를 현재 모듈의 res 디렉터리에 복사
- 소스가 존재하는 디렉토리 kt 파일을 소스 영역에 복사

### 3) 레이아웃 XML 파일 작성

- activity_main.xml 파일 작성

### 4) 메인 액티비티 파일 작성

- MainActivity.kt 파일 onCreate() 함수 코드 추가

### 5) 앱 실행

<img src="https://github.com/BangYunseo/TIL/blob/main/Android/Image/ch07/ch07-20-App.PNG" height="auto" />

[프로젝트 바로가기](https://github.com/BangYunseo/AndroidProject/tree/main/ch08)
