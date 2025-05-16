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
- MenuItem : 함수 매개 변수이자 이벤트가 발생한 메뉴 객체

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

| 속성값 종류 | 설명                                                                 |
| :---------: | :------------------------------------------------------------------- |
| never(기본) | 항상 오버플로 메뉴로 출력                                            |
|   ifRoom    | 만약 액션바에 공간이 있다면 액션 아이템, 없다면 오버플로 메뉴로 출력 |
|   always    | 항상 액션 아이템으로 출력                                            |

```kt
// 액티비티 코드 메뉴 XML 적용

override fun onCreateOptionsMenu(menu: Menu?): Boolean{
    menuInflate.inflate(R.menu.menu_main, menu)
    return super.onCreateOptionsMenu(menu)
}
```

<img src="https://github.com/BangYunseo/TIL/blob/main/Android/Image/ch06/ch06-11-Menu4.PNG" height="auto" />

### 액션 뷰 이용

- 액션바에서 특별한 기능 제공
- androidx.appcompat.widget.SearchView

```xml
<!-- 서치 뷰 사용 -->

<item android:id="@+id/menu_search"
    android:title="search"
    app:showAsAction="always"
    app:actionViewClass="androidx.appcompat.widget.SearchView" />
```

<img src="https://github.com/BangYunseo/TIL/blob/main/Android/Image/ch06/ch06-12-SearchView.PNG" height="auto" />

### 서치 뷰 이용

- SearchView를 등록한 MenuItem 객체를 얻은 후 SeaarchView 객체 획득

```kt
// 서치 뷰 검색 기능 구현

override fun onCreateOptionsMenu(menu: Menu): Boolean{
    val inflater = menuInflater
    inflater.inflate(R.menu.menu_main, menu)

    val menuItem = menu?.findItem(R.id.menu_search)
    val searchView = menuItem?.actionView as SearchView

    searchView.setOnQueryTextListener(object: SearchView.OnQueryTextListener{
        override fun onQueryTextChanger(newText: String?): Boolean{
            // 검색어 변경 이벤트
            return true
        }
        override fun onQueryTextSubmit(query: String?): Boolean{
            // 키보드 검색 버튼 클릭한 순간의 이벤트
            return true
        }
    })
    return true
}
```

## 4절. 프래그먼트

### 프래그먼트

- 액티비티처럼 동작하는 뷰
- 액티비티에 구현되는 모든 내용을 프래그먼트 클래스에 작성 가능

<img src="https://github.com/BangYunseo/TIL/blob/main/Android/Image/ch06/ch06-13-Fragment.PNG" height="auto" />

### 프래그먼트 구현

- Fragment를 상속받아 작성하는 클래스
- onCreateView() : 최소한 작성 함수가 자동 호출되며 반환한 View 객체가 화면에 출력

```kt
// 프래그먼트 구현

// (...생략...)
import androidx.fragment.app.Fragment

class OneFragment : Fragment() {
    lateinit var binding: FragmentOneBinding
    override fun onCreateView(
        inflater: LayoutInflater, containtere: ViewGroup?,
        savedInstanceState: Bundle?
    ): View? {
        binding = FragmentOneBinding.inflatee(inflater, container, flase)
        return binding.root
    }
}
```

### 프래그먼트 출력

```xml
<!-- 프래그먼트 출력 -->

<fragment
    android:name="com.example.test11.OneFragment"
    android:id="@+id/fragmentView"
    android:layout_width="match_parent"
    android:layout_height="match_parent" />
```

- <fragment> 태그
  - 액티비티 레이아웃 XML에 등록
  - 액티비티 화면에 프래그먼트 출력
  - name 속성에 프래그먼트 클래스 지정
  - 액티비티 레이아웃 XML(activity_main.xml)에 등록
    - 프래그먼트 동적 제어(추가, 제거 등) 시 FragmentManager의 FragmentTransaction 클래스 함수 이용

|      FragmentTransaction 클래스 함수 종류       | 설명                          |
| :---------------------------------------------: | :---------------------------- |
|   add(int containerViewId, Fragment fragment)   | 새로운 프래그먼트 화면에 추가 |
| replace(int containerViewId, Fragment fragment) | 추가된 프래그먼트 대체        |
|            remove(Fragment fragment)            | 추가된 프래그먼트 제거        |
|                    commit()                     | 화면 적용                     |

```kt
// 프래그먼트 동적 제어

val fragmentManager: FraagmentManager = supportFragmentManager
val transaction: FragmentTransaction = fragmentManager.beginTransaction()
val fragment = OneFragment()

transaction.add(R.id.fragment_content, fragment)
transaction.commit()
```

### 프래그먼트 생명주기

- 액티비티의 생명주기 함수
  - 아래의 함수를 가지며 호출 시점도 액티비티와 동일

| 생명 주기 함수 종류 |
| :-----------------: |
|     onCreate()      |
|      onStart()      |
|     onResume()      |
|      onPause()      |
|      onStop()       |

<img src="https://github.com/BangYunseo/TIL/blob/main/Android/Image/ch06/ch06-14-SDLC.PNG" height="auto" />

|   생명 주기 단계    |
| :-----------------: |
| 초기화(initialized) |
|    생성(created)    |
|    시작(started)    |
|    재개(resumed)    |
|   소멸(destroyed)   |

### 백 스택

- 프래그먼트가 화면에 보이지 않는 순간 제거하지 않고 저장 후 다시 이용하는 기능
- 백 스택 미사용 : 프래그먼트 교체 시 기존의 프래그먼트는 onDestroy까지 호출 후 제거
- 백 스택 사용 : 프래그먼트가 제거되지 않고 onDestoryView 함수까지만 호출

```kt
// 백 스택 사용 설정

transaction.addToBackStack(null)
```

## 5절. 리사이클러 뷰

### 리사이클러 뷰

- 목록 화면 구성 뷰

<img src="https://github.com/BangYunseo/TIL/blob/main/Android/Image/ch06/ch06-15-RecyclerView.PNG" height="auto" />

|      구성 요소       | 설명                       |
| :------------------: | :------------------------- |
|   ViewHolder(필수)   | 항목에 필요한 뷰 객체 보유 |
|    Adapter(필수)     | 항목 구성                  |
| LayoutManager(필수)  | 항목 배치                  |
| ItemDecoration(옵션) | 항목 꾸미기                |

### 뷰 홀더 준비

- 각 항목에 해당하는 뷰 객체를 가지며 RecyclerView.ViewHolder를 상속받아 작성

```kt
// 뷰 홀더 준비

class MyViewHolder(val binding: ItemMainBinding): RecyclerView.ViewHolder(binding.root)
```

### 어댑터

- 각 항목 생성의 역할

|   어댑터 함수 종류   | 설명                                           |
| :------------------: | :--------------------------------------------- |
|    getItemCount()    | 항목 개수 판단을 위해 자동 호출                |
| onCreateViewHolder() | 항목 뷰를 가지는 뷰 홀더 준비를 위해 자동 호출 |
|  onBindViewHolder()  | 뷰 홀더 뷰에 데이터 출력을 위해 자동 호출      |

```kt
// 어댑터 준비

class MyAdapter(val datas: MutableList<String>):
    RecyclerView.Adapter<RecyclerView.ViewHolder>(){
        override fun getItemCount(): Int{
            TODO("Not yet implemented")
        }
        override fun onCreateViewHolder(parent: ViewGroup, viewType: Int):
        RecyclerView.ViewHolder{
            TODO("Not yet implemented")
        }
        override fun onBindViewHolder(holder: RecyclerView.ViewHolder, position: Int){
            TODO("Not yet implemented")
        }
    }
```

```kt
// 항목 개수 구하기

override fun getItemCount(): Int = datas.size
```

```kt
// 항목 구성에 필요한 뷰 홀더 객체 준비

override fun onCreateViewHolder(parent: ViewGroup, viewType: Int): RecyclerView.ViewHolder =
    MyViewHolder(ItemMainBinding.inflate(LayoutInflater.from(parent.context),
        parent, false))
```

```kt
// 뷰에 데이터 출력

override fun onBindViewHolder(holder: RecyclerView.ViewHolder, position: Int){
    Log.d("yunseo", "onBindViewHolder : $position")
    val binding = (holder as MyViewHolder).binding

    // 뷰에 데이터 출력
    binding.itemData.text = datas[position]

    // 뷰에 이벤트 추가
    binding.itemRoot.setOnClickListener {
        Log.d("yunseo", "item root click : $position")
    }
}
```

### 리사이클러 뷰 출력

```kt
// 리사이클러 뷰 액티비티(RecyclerViewActivity)

class RecyclerViewActivity : AppCompatActivity() {
    override fun onCreate(savedInstanceState: Bundle?){
        super.onCreate(savedInstanceState)
        val binding = ActivityRecyclerViewBinding.inflate(layoutInflater)
        setContentView(binding.root)

        val datas = mutableListOf<String>()
        for(i in 1..10){
            datas.add("Item $i")
        }

        binding.recyclerView.layoutManager = LinearLayoutManager(this)
        binding.recyclerView.adapter = MyAdapter(datas)
        binding.recyclerView.addItemDecoration(DividerItemDecoration(this,
        LinearLayout Manager.VERTICAL))
    }
}
```

### 항목 동적 추가·제거

- notifyDataSetChanged() : 항목 구성 데이터에 새로운 데이터를 추가·제거 후 호출

```kt
// 항목 추가

datas.add("new data")
adapter.notifyDataSetChanged()
```

### 레이아웃 매니저

- 어댑터로 만든 항목을 리사이클러 뷰에 배치

|         항목 종류          | 설명                               |
| :------------------------: | :--------------------------------- |
|    LinearLayoutManager     | 항목 가로·세로 방향 배치           |
|     GridLayoutManager      | 항목 그리드 배치                   |
| StaggeredGridLayoutManager | 항목을 높이가 불규칙한 그리드 배치 |

- LinearLayoutManager : 항목을 가로·세로 방향으로 배치
  - 가로 배치 : LinearLayoutManager.HORIZONTAL
  - 세로 배치 : LinearLayoutManager.VERTICAL or 생략

<img src="https://github.com/BangYunseo/TIL/blob/main/Android/Image/ch06/ch06-16-Vertical.PNG" height="auto" />

```kt
// 항목 세로 배치

binding.recyclerView.layoutManager = LinearLayoutManager(this)
```

<img src="https://github.com/BangYunseo/TIL/blob/main/Android/Image/ch06/ch06-17-Horizontal.PNG" height="auto" />

```kt
// 항목 가로 배치

val layoutManager = LinearLayoutManager(this)
layoutManager.orientation = LinearLayoutManager.HORIZONTAL
binding.recyclerView.layoutManager = layoutManager
```

### 그리드 배치

- GridLayoutManager 이용
- 생성자 숫자 : 그리드 열의 개수
- 방향 설정 가능

```kt
// 그리드 항목 배치

val layoutManager = GridLayoutManager(this, 2)
binding.recyclerView.layoutManager = layoutManager
```

<img src="https://github.com/BangYunseo/TIL/blob/main/Android/Image/ch06/ch06-18-Grid.PNG" height="auto" />

- 가로 설정 : 생성자에 GridLayoutManager.HORIZONTAL 지정

```kt
// 그리드 항목 가로 배치

val layoutManager = GridLayoutManager(this, 3,
GridLayoutManager.HORIZONTAL, false)
binding.recyclerView.layoutManager = layoutManager
```

<img src="https://github.com/BangYunseo/TIL/blob/main/Android/Image/ch06/ch06-19-GridH.PNG" height="auto" />

- GridLayoutManager 생성자 네 번째 매개변수 Boolean 값 : 왼쪽, 오른쪽 정렬

```kt
// 그리드 항목 오른쪽부터 배치

val layoutManager = GridLayoutManager(this, 3,
GridLayoutManager.HORIZONTAL, true)
binding.recyclerView.layoutManager = layoutManager
```

<img src="https://github.com/BangYunseo/TIL/blob/main/Android/Image/ch06/ch06-20-GridB.PNG" height="auto" />

- StaggeredGridLayoutManager : 뷰의 크기가 다를 경우 지그재그 형태 배치

```kt
// 지그재그 그리드 형태 배치

val layoutManager = StaggeredGridLayoutManager(2,
StaggeredGridLayoutManager.VERTICAL)
binding.recyclerView.layoutManager = layoutManager
```

<img src="https://github.com/BangYunseo/TIL/blob/main/Android/Image/ch06/ch06-21-GridS.PNG" height="auto" />

### 아이템 데커레이션

- 리사이클러 뷰를 다양하게 꾸밀 때 사용
- DividerItem Decoration : 항목의 구분선 출력
- ItemDecoration을 상속받는 개발자 클래스 생성 후 다양한 꾸미기 작업 수행

|    함수 종류     | 설명                   |
| :--------------: | :--------------------- |
|     onDraw()     | 항목 배치 전 호출      |
|   onDrawOver()   | 항목 모두 배치 후 호출 |
| getItemOffsets() | 개별 항목 꾸밀 때 호출 |

```kt
// 아이템 데커레이션 구현

class MyDecoration(val context: Context): RecyclerView.ItemDecoration(){
    override fun onDraw(c: Canvas, parent: RecyclerView, state: RecyclerView.State){
        super.onDraw(c, parent, state)
    }

    override fun onDrawOver(c: Canvas, parent: RecyclerView, state: RecyclerView.State){
        super.onDrawOver(c, parent, state)
    }

    override fun getItemOffsets(
        outRect: Rect,
        view: View,
        parent: RecyclerView,
        state: RecyclerView.State
    ) {
        super.getItemOffsets(outRect, view, parent, state)
    }
}
```

```kt
// 항목 배치 전 호출되는 onDraw()

override fun onDraw(c: Canvas, parent: RecyclerView, state: RecyclerView.State){
    super.onDraw(c, parent, state)
    c.drawBitmap(BitmapFactory.decodeResource(context.getResources(), R.drawable.stadium),
        0f, 0f, null)
}
```

```kt
// 모든 항목 배치 후 호출하는 onDrawOver()

override fun onDrawOver(c: Canvas, parent: RecyclerView, state: RecyclerView.State){
    super.onDrawOver(c, parent, state)

    // 뷰 크기 계산
    val width = parent.width
    val height = parent.height

    // 이미지 크기 계산
    val dr: Drawable? = ResourcesCompat.getDrawble(context.getResources(),
        R.drawable.kbo, null)
    val drWidth = dr?.intrinsicWidth
    val drHeight = dr?.intrinsicHeight

    // 이미지가 그려질 위치 계산
    val left = width / 2 - drWidth?.div(2) as Int
    val top = height / 2 - drHeight?.div(2) as Int
    c.drawBitmap(
        BitmapFactory.decodeResource(context, getResources(), R.drawable.kbo),
        left.toFloat(),
        top.toFloat(),
        null
    )
}
```

```kt
// 개별 항목 꾸미는 getItemOffsets()

override fun getItemOffsets(
    outRect: Rect,
    view: View,
    parent: RecyclerView,
    state: RecyclerView.State
){
    super.getItemOffsets(outRect, view, parent, state)
    val index = parent.getChildAdapterPosition(view) + 1

    if(index % 3 == 0) outRect.set(10, 10, 10, 60) // left, top, right, bottom
    else outRect.set(10, 10, 10, 0)

    view.setBackgroundColor(Color.LTGRAY)
    ViewCompat.setElevation(view, 20.0f)
}
```

- addItemDecoration() : 아이템 데커레이션 객체를 리사이클러 뷰에 적용하는 함수

<img src="https://github.com/BangYunseo/TIL/blob/main/Android/Image/ch06/ch06-22-ID.PNG" height="auto" />

```kt
// 리사이클러 뷰에 적용한 아이템 데커레이션

binding.recyclerView.addItemDecoration(MyDecoration(this))
```

## 6절. 뷰 페이저2

### 뷰 페이저2

<img src="https://github.com/BangYunseo/TIL/blob/main/Android/Image/ch06/ch06-23-ViewPager.PNG" height="auto" />

- 스와이프로 넘기는 화면 구성
- 기존의 viewpager 대신 2019년에 viewpager2를 제공
- 항목이 순서대로 나열되며 한 화면에 항목 하나 표현

|     어댑터 종류      |
| :------------------: |
| RecyclerView.Adapter |
| FragmentStateAdapter |

```kt
// 뷰 페이저2 구현 : 리사이클러 뷰 어댑터 이용

class MyPagerViewHolder(val binding: ItemPagerBinding) :
    RecyclerView.ViewHolder(binding.root)
class MyPagerAdapter(val datas: MutableList<String>) :
    RecyclerView.Adapter<RecyclerView.ViewHolder>(){
        override fun getItemCount(): Int{
            return datas.size
        }

        override fun onCreateViewHolder(parent: ViewGroup, viewType: Int):
            RecyclerView.ViewHolder =
                MyPagerViewHolder(ItemPagerBinding.inflate(LayoutInflater.from(
                    parent.context), parent, false))

        override fun onBindingViewHolder(holder: RecyclerView.ViewHolder, position: Int){
            val binding = (holder as MyPagerViewHolder).binding

            // 뷰에 데이터 출력
        binding.itemPagerTextView.text = datas[position]
            when (position % 3) {
                    0 -> binding.itemPagerTextView.setBackgroundColor(Color.RED)
                    1 -> binding.itemPagerTextView.setBackgroundColor(Color.BLUE)
                    2 -> binding.itemPagerTextView.setBackgroundColor(Color.GREEN)
            }
        }
    }
```

- FragmentStateAdapter로 뷰 페이저2 구현

```kt
(여기부터 작성 : 49p)
```

## 7절. 드로어 레이아웃

- 레이아웃 XML 파일에서 드로어 메뉴가 출력될 부분의 태그를 DrawerLayout으로 선언[cite: 38, 39].
- DrawerLayout 아래에 2개의 뷰 선언[cite: 39, 40].
  - 첫 번째 하위 태그: 액티비티 화면에 출력[cite: 39, 40].
  - 두 번째 하위 태그: 평소에는 안 보이다가 끌려 나옴[cite: 40].
- 툴바 영역에 토글(toggle) 버튼을 함께 제공[cite: 41].
- 토글 버튼은 ActionBarDrawerToggle 클래스에서 제공[cite: 41].

## 8장. 제트팩 화면 구성

### 1) 새 모듈 생성

- Ch11_JetPack 이름으로 새 모듈 생성[cite: 42].

### 2) 빌드 그래들 작성

- 뷰 바인딩 설정[cite: 42].

### 3) 문자열 리소스 생성

- res/values/strings.xml 파일에 ActionBarDrawerToggle 생성 시 지정할 문자열 리소스 추가[cite: 43].

### 4) 테마 추가

- res/values/themes.xml 파일을 열어 액티비티 윈도우를 출력할 때 액션바를 출력하지 않도록 설정[cite: 44].

### 5) 프래그먼트 생성

- New -> Fragment -> Fragment (Blank) 선택[cite: 45].
- OneFragment, TwoFragment, ThreeFragment 이름으로 빈 프래그먼트 3개 추가[cite: 45].

### 6) 파일 복사

- res/drawable/kbo.png 파일을 res/drawable에 복사[cite: 46].
- res/layout 디렉터리의 fragment_one.xml, fragment_two.xml, fragment_three.xml, item_recyclerview.xml 파일을 res/layout 디렉터리에 복사[cite: 46].
- OneFragment.kt, TwoFragment.kt, ThreeFragment.kt 파일을 소스 영역에 복사[cite: 46].

### 7) fragment_one.xml 파일 작성

- 리사이클러 뷰로 구성하기 위해 fragment_one.xml 파일 작성[cite: 47].
- OneFragment.kt 파일 작성[cite: 48].

### 8) 메뉴 리소스 생성

- New -> Android Resource Directory 선택[cite: 48].
- Resource type 에서 menu 선택 후 OK 클릭하여 menu 디렉터리 생성[cite: 49].
- New -> Menu Resource File 선택[cite: 49].
- File name 에 menu_main 입력 후 OK 클릭하여 메뉴 파일 생성[cite: 50].
- menu_main.xml 파일 열고 작성[cite: 50].

### 9) 메인 레이아웃 XML 작성

- activity_main.xml 파일 열고 드로어 레이아웃, 툴바, 뷰 페이저2 등 등록[cite: 51].

### 10) 메인 액티비티 작성

- MainActivity.kt 파일 열고 작성[cite: 52].

### 11) 앱 실행

```

```
