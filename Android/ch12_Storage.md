# Chapter 12. 저장소 데이터 보관

> '깡샘의 안드로이드 앱 프로그래밍 with 코틀린' 17장 학습 내용
>
> 1절. 데이터베이스 보관
>
> 2절. 파일 보관
>
> 3절. 공유된 프리퍼런스 보관
>
> 4절. 개선된 할 일 목록 앱 구현  
> [프로젝트 바로가기](https://github.com/BangYunseo/AndroidProject/tree/main/ch13)

## 1절. 데이터베이스 보관

### 질의문 작성

- SQLite로 사용할 경우 SQLiteDatabase API 이용
  - 다만, AndroidStudio로 개발할 경우 firebase 권장
- SQLiteDatabase 객체 : openOrCreateDatabase() 함수 호출

```kt
// 데이터베이스 객체 생성

val db = openOrCreateDatabase("testdb", Context.MODE_PRIVATE, null)
```

### 질의문

- SQLiteDatabase 객체에 정의된 아래 함수를 이용하여 질의문 실행
  - public void execSQL(String sql, Object[] bindArgs)
  - public Cursor rawQuery(String sql, String[] selectionArgs)

```kt
// 테이블 생성(create 문)

db.execSQL("create table USER_TB(" +
           "_id integer primary key autoincrement," +
           "name not null," +
           "phone)")
```

```kt
// 데이터 삽입(insert 문)

db.execSQL("insert into USER_TB(name, phone) values (?, ?)",
           arrayOf<String>("yunseo", "0101111"))
```

```kt
// 데이터 조회(select 문)

val cursor = db.rawQuery("select * from USER_TB", null)
```

#### rawQuery()

- 함수 반환값 : Cursor
- Cursor 객체로 행 선택

  - public abstract boolean moveToFirst() : 첫 번째 행 선택
  - public abstract boolean moveToLast() : 마지막 행 선택
  - public abstract boolean moveToNext() : 다음 행 선택
  - public abstract boolean moveToPosition(int position) : 매개변수로 지정한 위치 행 선택
  - public abstract boolean moveToPrevious(): 이전 행 선택

- 행의 열 데이터를 가져오는 타입 별 함수
  - public abstract String getString(int columnIndex)
  - public abstract int getInt(int columnIndex)
  - public abstract double getDouble(int columnIndex)

```kt
// 선택한 행의 값 가져오기

while(cursor.moveToNext()){
  val name = cursor.getString(0)
  val phone = cursor.getString(1)
}
```

#### 사용 함수

- public long insert(String table, String nullColumnHack, ContentValues values)
- public int update(String table, ContentValues values, String whereClause, String[] whereArgs)
- public int delete(String table, String whereClause, String[] whereArgs)
- public Cursor query(String table, String[] columns, String selection, String[] selectionArgs, String groupBy, String having, String orderBy)

```kt
// insert() 함수 사용

val values = ContentValues()
values.put("name", "yunseo")
values.put("phone", "0101112")
db.insert("USER_TB", null, values)
```

#### query() 함수 매개 변수

| 매개 변수 종류 | 설명                                       |
| :------------: | :----------------------------------------- |
|     table      | 조회할 테이블 명                           |
|    columns     | 가져올 값이 담긴 열 이름을 배열로 지정     |
|   selection    | select 문의 where 절 뒤에 들어갈 문자열    |
| selectionArgs  | 질의문에서 ?에 들어갈 데이터 배열          |
|    groupBy     | select 문의 group by 절 뒤에 들어갈 문자열 |
|     having     | select 문의 having 조건                    |
|    orderBy     | select 문의 order by 조건                  |

```kt
// query() 함수 사용

val cursor = db.query("USER_TB", arrayOf<String>("name", "phone"). "phone = ?",
             arrayOf<String>("0101112"), null, null, null)
```

### 데이터베이스 관리

- SQLiteOpenHelper
  - 추상 클래스
  - 상속 받아 하위 클래스 작성
    - onCreate() : 앱 설치 후 SQLiteOpenHelper 클래스가 이용되는 순간 한 번 호출
    - onUpgrade() : 생성자에 지정한 DB 버전 정보 변경 시마다 호출

```kt
// SQLiteOpenHelper 하위 클래스 작성

class DBHelper(context: Context): SQLiteOpenHelper(context, "testdb", null, 1){
    override fun onCreate(db: SQLiteDatabase?){
    }
    override fun onUpgrade(db: SQLiteDatabase?, oldVersion: Int, newVersion: Int){
    }
}
```

```kt
// SQL 데이터베이스 객체 생성

val db: SQLiteDatabase = DBHelper(this).writeDatabase
```

## 2절. 파일 보관

### java.io

- 안드로이드 앱에서 파일 보관 시 java.io 패키지에서 제공하는 클래스 이용
  - File : 파일 및 디렉토리 지칭 클래스
  - FileInputStream / FileOutputStream : 파일에서 바이트 스트림으로 데이터를 읽거나 쓰는 클래스
  - FileReader / FileWriter : 파일에서 문자열 스트림으로 데이터를 읽거나 쓰는 클래스

<img src="https://github.com/BangYunseo/TIL/blob/main/Android/Image/ch12/ch12-01-file.PNG" height="auto" />

### 내장 메모리 파일 이용

- 앱의 패키지 명으로 디렉토리 생성
  - 해당 디렉토리 == 앱의 내장 메모리 공간
- 파일을 내장 메모리에 적용할 경우 java.io의 File 클래스 이용

```kt
// 파일 객체 생성 후 데이터 쓰기

val file = File(filesDir, "test.txt")
val writeStream: OutputStreamWriter = file.writer()
writeStream.write("hello, World!")
writeStream.flush()
```

```kt
// 파일 데이터 읽기

val readStream: BufferedReader = file.reader().buffered()
readStream.forEachLine{
    Log.d("yunseo", "$it")
}
```

```kt
// Context 객체 함수 사용

openFileOutput("test.txt", Context.MODE_PRIVATE).use{
    it.write("hello, World!".toByteArray())
}
openFileInput("test.txt").bufferedReader().forEachLine {
    Log.d("yunseo", "$it")
}
```

### 외장 메모리 파일 이용

```kt
// 외장 메모리 사용 가능 여부 판단

if(Environment.getExternalStorageState() == Environment.MEDIZ_MOUNTED){
    Log.d("yunseo", "ExternalStorageState MOUNTED")
} else {
    Log.d("yunseo", "ExternalStorageState UNMOUNTED")
}
```

### 앱 별 저장소 이용

- 개별 앱에 할당된 공간
- 파일을 외부 앱에서 접근하기 위해 파일 프로바이더로 공개
- getExternalFilesDir() 함수 사용

```kt
// 앱 별 저장소 접근

val file: File? = getExternalFilesDir(null)
Log.d("yunseo", "$(file?.absolutePath)")
```

### getExternalFilesDir()

- 매개 변수는 파일의 종류 표현
- 아래의 Environment 상태 전달

(여기부터 작성)

| 상태 종류 |
| :-------: |

|

### 공용 저장소 이용

- 모든 앱이 이용할 수 있는 저장소
   안드로이드12(API Level 32)까지는공용공간을이용하기위해서는android.permission.READ_EXTERNAL_STORAGE와
  android.permission.WRITE_EXTERNAL_STORAGE를퍼미션으로추가장소
   안드로이드13(API Level 33)부터는공용공간의파일타입을구분해서이용하므로미디어파일도이미지인지비디오인지에따라다르
  게퍼미션을설정
   안드로이드14부터는사용자에게앱에서미디어파일에대한접근을다시선택할수있게하기위한
  android.permission.READ_MEDIA_VISUAL_USER_SELECTED 퍼미션이추가

```xml
<!-- AndroidManifest.xml 퍼미션 설정 -->
```

## 3절. 공유된 프리퍼런스 보관

### 공유된 프리퍼런스

- 플랫폼 API에서 제공하는 클래스
- 데이터를 키:값 형태로 저장
- SharedPreferences 객체 획득 방법
  - Activity.getPreferences(int mode)
  - Context.getSharedPreferences(String name, int mode)

### Activity.getPreferences(int mode)

- 액티비티 단위로의 데이터 저장 시 사용

```kt
// 액티비티 데이터 저장

val sharedPref = getPreferences(Context.MODE_PRIVATE)
```

### Context.getSharedPreferences(String name, int mode)

- 앱 전체 데이터를 키:값 형태로 저장 후 SharedPreferences 객체 이용

```kt
// 앱 전체 데이터 저장

val sharedPref = getSharedPreferences("my_prefs", Context.MODE_PRIVATE)
```

### SharedPreferences.Editor 클래스 put 함수

- 데이터 저장 시 이용
- Default 값 지정 필요

|               함수 종류               |
| :-----------------------------------: |
| putBoolean(String key, boolean value) |
|     putInt(String key, int value)     |
|   putFloat(String key, float value)   |
|    putLong(String key, long value)    |
|  putString(String key, String value)  |

```kt
// 프리퍼런스 데이터 저장

sharedPref.edit().run{
  putString("data1", "hello")
  putInt("data2", 10)
  commit()
}
```

### SharedPreferences.Editor 클래스 get 함수

- 저장된 데이터 로드 시 사용

|                함수 종류                 |
| :--------------------------------------: |
| getBoolean(String key, boolean defValue) |
|   getFloat(String key, float defValue)   |
|     getInt(String key, int defValue)     |
|    getLong(String key, long defValue)    |
|  getString(String key, String defValue)  |

```kt
// 프리퍼런스 데이터 로드

val data1 = sharedPref.getString("data1", "world")
val data2 = sharedPref.getInt("data2", 10)
```

### 앱 설정 화면 생성

- AndroidX Preference를 이용

```kts
// AndroidX 프리퍼런스 사용 선언

implementation("androidx.preference:preference-ktx:1.2.1")
```

### 프리퍼런스 이용 방법

- res/xml 디렉토리에 설정 관련 XML 파일 생성
- 루트 태그 : \<PreferenceScreen\>
- 하위 태그 : \<SwitchPreferenceCompat\>, \<Preference\> 등
  - 설정 항목 준비

```XML
<!-- 설정 XML 파일-->

<PreferenceScreen xmlns:app="http://schemas.android.com/apk/res-auto">
    <SwitchPreferenceCompat
        app:key="notifications"
        app:title="Enable message notifications" />
    <Preference
        app:key="feedback"
        app:title="Send feedback"
        app:summary="Report technical issues or suggest new features" />
</PreferenceScreen>
```

| 속성  | 설명             |
| :---: | :--------------- |
|  key  | 데이터의 키      |
| title | 화면 출력 문자열 |

### PreferenceFragmentCompat 클래스

- XML 파일 코드에 적용 시 이용
- 클래스를 상속받은 후 프래그먼트 클래스에서 onCreatePreferences() 함수 재정의 후 작성

```kt
// 설정 XML 파일 적용

class MySettingFragment : PreferenceFragmentCompat() {
    override fun onCreatePreferences(savedInstanceState: Bundle?, rootKey: String?) {
        setPreferencesFromResource(R.xml.settings, rootKey)
    }
}
```

```XML
<!-- 액티비티 프래그먼트 출력 -->

<fragment xmlns:android="http://schemas.android.com/apk/res/android"
    android:layout_width="match_parent"
    android:layout_height="match_parent"
    class="com.example.test17.MySettingFragment" />
```

- 실행 결과

<img src="https://github.com/BangYunseo/TIL/blob/main/Android/Image/ch12/ch12-02-Fragment.PNG" height="auto" />

### 설정 화면 구성

- \<PreferenceCategory\> 태그로 한 화면에 보이는 항목끼리 구분

```XML
<!-- 설정 항목끼리 묶기 -->

<PreferenceScreen xmlns:app="http://schemas.android.com/apk/res-auto">
    <PreferenceCategory
        app:key="a_category"
        app:title="A Setting">
        <SwitchPreferenceCompat
            app:key="a1"
            app:title="A - 1 Setting" />
        <SwitchPreferenceCompat
            app:key="a2"
            app:title="A - 2 Setting" />
    </PreferenceCategory>
    <PreferenceCategory
        app:key="B_category"
        app:title="B Setting">
        <SwitchPreferenceCompat
            app:key="b1"
            app:title="B - 1 Setting" />
    </PreferenceCategory>
</PreferenceScreen>
```

- 실행 결과

<img src="https://github.com/BangYunseo/TIL/blob/main/Android/Image/ch12/ch12-03-PC.PNG" height="auto" />

#### \<Preference\> 태그

- 설정 항목이 다수인 경우 화면 여러 개 분리
- XML에서 각 설정 화면은 \<Preference\> 태그로 지정

```XML
<!-- 두 화면 포함 설정 화면 -->

<PreferenceScreen xmlns:app="http://schemas.android.com/apk/res-auto">
    <Preference
        app:key="a"
        app:summary="A Setting summary"
        app:title="A Setting"
        app:fragment="com.example.test17.ASettingFragment" />
    <Preference
        app:key="b"
        app:summary="B Setting summary"
        app:title="B Setting"
        app:fragment="com.example.test17.BSettingFragment" />
</PreferenceScreen>
```

- 실행 결과

<img src="https://github.com/BangYunseo/TIL/blob/main/Android/Image/ch12/ch12-04-P.PNG" height="auto" />

#### onPreferenceStartFragment()

- \<Preference\> 태그로 설정 화면 분할 후 액티비티에서 PreferenceFragmentCompat.OnPreferenceStartFragmentCallback 인터페이스를 구현하고 onPreferenceStartFragment() 함수 재정의
- onPreferenceStartFragment() : 설정 화면 전환 시 호출 함수

```kt
// 분할 설정 화면을 보여주는 액티비티

class SettingActivity : AppCompatActivity(),
    PreferenceFragmentCompat.OnPreferenceStartFragmentCallback {
    // (... 생략 ...)
    override fun onPreferenceStartFragment(caller: PreferenceFragmentCompat,
                                           pref: Preference
    ): Boolean {
        // 새로운 프래그먼트 인스턴스화
        val args = pref.extras
        val fragment = supportFragmentManager.fragmentFactory.instantiate(
            classLoader,
            pref.fragment as String
        )
        fragment.arguments = args
        supportFragmentManager.beginTransaction()
            .replace(R.id.setting_content, fragment)
            .addToBackStack(null)
            .commit()
        return true
    }
}
```

### \<intent\> 인텐트 태그

- 메인 설정 화면에서 인텐트를 통해 하위 설정 화면 띄우기

```XML
<!-- 인텐트 설정 화면 -->

<Preference
    app:key="activity"
    app:title="Launch activity">
    <intent
        android:targetClass="com.example.test17.SomeActivity"
        android:targetPackage="com.example.test17" />
</Preference>
```

### \<extra\> 엑스트라 태그

- \<intent\> 태그 하위에 \<extra\> 태그로 인텐트에 포함
- 전달 엑스트라 데이터 설정
- 명시적 인텐트 정보 + 암시적 인텐트 정보 설정 가능

```XML
<!-- 인텐트 엑스트라 데이터 포함 -->

<intent
    android:targetClass="com.example.test17.SomeActivity"
    android:targetPackage="com.example.test17">
    <extra
        android:name="example_key"
        android:value="example_value" />
</intent>
```

```XML
<!-- 암시적 인텐트 사용 -->

<intent
    android:action="android.intent.action.VIEW"
    android:data="http://www.google.com" />
```

### 설정 제어

- 사용자가 설정 항목을 클릭한 순간 이벤트 처리 or 설정값을 설정 항목 옆에 표시
- findPreference() 함수 : 설정 항목 해당 객체 얻기

```XML
<!-- 글 입력 설정 -->

<EditTextPreference
    app:key="id"
    app:title="ID 설정"
    app:isPreferenceVisible="false" />
```

```kt
// 설정값 코드에서 변경

override fun onCreatePreferences(savedInstanceState: Bundle?, rootKey: String?) {
    setPreferencesFromResource(R.xml.settings, rootKey)
    val idPreference: EditTextPreference? = findPreference("id")
    idPreference?.isVisible = true

    idPreference?.summary = "code summary"
    idPreference?.title = "code title"
}
```

- XML : 설정값을 summary 속성에 자동 지정
  - \<EditTextPreference\>
  - \<ListPreference\> : 제시한 목록에서 선택
- Kotlin
  - SimpleSummaryProvider

```XML
<!-- 설정 XML 예시 -->

<EditTextPreference
    app:key="id"
    app:title="ID 설정" />

<ListPreference
    app:key="color"
    app:title="색상 선택"
    android:entries="@array/my_color"
    app:entryValues="@array/my_color_values" />
```

```kt
// 설정값 자동 적용

val idPreference: EditTextPreference? = findPreference("id")
val colorPreference: ListPreference? = findPreference("color")

idPreference?.summaryProvider =
    EditTextPreference.SimpleSummaryProvider.getInstance()
colorPreference?.summaryProvider =
    ListPreference.SimpleSummaryProvider.getInstance()
```

#### SimpleSummaryProvider

- 하위 클래스 생성 후 코드에서 원하는 대로 summary 지정 가능

```kt
// 코드에 설정값 표시

idPreference?.summaryProvider =
    Preference.SummaryProvider<EditTextPreference> { preference ->
        val text = preference.text
        if (TextUtils.isEmpty(text)) {
            "설정이 되지 않았습니다."
        } else {
            "설정된 ID 값은 : $text 입니다."
        }
    }
```

- 실행 결과

<img src="https://github.com/BangYunseo/TIL/blob/main/Android/Image/ch12/ch12-05-SettingValue.PNG" height="auto" />

#### 이벤트 핸들러

- 설정 항목에 이벤트 추가

```kt
// 이벤트 핸들러 지정

idPreference?.setOnPreferenceClickListener { preference ->
    Log.d("Yunseo", "preference key : ${preference.key}")
    true
}
```

### 설정값 로드

- PreferenceManager.getDefaultSharedPreferences() 함수

```kt
// 설정값 가져오기

val sharedPreferences = PreferenceManager.getDefaultSharedPreferences(activity)
val id = sharedPreferences.getString("id", "")
```

### 설정 변경 순간 감지

#### Preference.OnPreferenceChangeListener

- 프리퍼런스 객체마다 이벤트 핸들러를 직접 지정
- 객체의 설정 내용이 변경되면 이벤트를 처리

```kt
// 프리퍼런스를 통한 이벤트 처리

idPreference?.setOnPreferenceChangeListener { preference, newValue ->
    Log.d("Yunseo", "preference key : ${preference.key}, newValue : $newValue")
    true
}
```

#### SharedPreferences.OnSharedPreferenceChangeListener

- 설정 객체의 변경을 하나의 이벤트 핸들러에서 처리

```kt
// 공유된 프리퍼런스를 이용한 이벤트 처리

class MySettingFragment : PreferenceFragmentCompat(), SharedPreferences.
    OnSharedPreferenceChangeListener {
    // (... 생략 ...)
    override fun onSharedPreferenceChanged(sharedPreferences:
                                               SharedPreferences?, key: String?) {
        if (key == "id") {
            Log.i("Yunseo", "newValue : " + sharedPreferences?.getString("id", ""))
        }
    }

    override fun onResume() {
        super.onResume()
        preferenceManager.sharedPreferences
            ?.registerOnSharedPreferenceChangeListener(this)
    }

    override fun onPause() {
        super.onPause()
        preferenceManager.sharedPreferences
            ?.unregisterOnSharedPreferenceChangeListener(this)
    }
}
```

## 4절. 개선된 할 일 목록 앱 구현

### 1) 새 모듈 생성 & 그래들 설정

- Ch17_Database 새 모듈 생성
- AndroidX Preference 라이브러리 추가
- 뷰 바인딩 기법 추가

```kts
// 뷰 바인딩 기법
viewBinding.isEnabled = true

// AndroidX Preference 라이브러리
implementation(libs.androidx.preference.ktx)
```

### 2) 액티비티 생성 후 파일 복사

- AddActivity, SettingActivity라는 빈 액티비티 추가
- res 디렉토리의 drawable, layout, menu, values, xml 파일 복사
- AddActivity.kt, MainActivity.kt, MyAdapter.kt, SettingActivity.kt 파일 복사

### 3) 설정 XML 파일 작성

- settings.xml 파일 작성

### 4) 설정 프래그먼트 작성

- MySettingFragment 프래그먼트 생성 후 작성

### 5) 설정 화면 XML 작성

- activity_setting.xml 작성
  - 화면에 출력할 프래그먼트 클래스 작성

### 6) 데이터베이스 헬퍼 작성

- DBHelper라는 코틀린 클래스 파일 생성 후 작성

### 7) 할 일 저장 액티비티 & 메인 액티비티 작성

- AddActivity.kt 파일, MainActivity.kt 파일 작성

### 8) 앱 실행

<img src="https://github.com/BangYunseo/TIL/blob/main/Android/Image/ch12/ch12-06-App.PNG" height="auto" />
    
[프로젝트 바로가기](https://github.com/BangYunseo/AndroidProject/tree/main/ch13)
