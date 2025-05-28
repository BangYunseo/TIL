# Chapter 12. 저장소 데이터 보관

> '깡샘의 안드로이드 앱 프로그래밍 with 코틀린' 17장 학습 내용
>
> 1절. 데이터베이스 보관
>
> 2절. 파일 보관
>
> 3절. 공유된 프리퍼런스 보관
>
> 4절. 연동 앱 구현  
> [프로젝트 바로가기](https://github.com/BangYunseo/AndroidProject/tree/main/ch12)

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

|매개 변수 종류|설명|
|:---:|:---|
|table|조회할 테이블 명|
|columns|가져올 값이 담긴 열 이름을 배열로 지정|
|selection|select 문의 where 절 뒤에 들어갈 문자열|
|selectionArgs|질의문에서 ?에 들어갈 데이터 배열|
|groupBy|select 문의 group by 절 뒤에 들어갈 문자열|
|having|select 문의 having 조건|
|orderBy|select 문의 order by 조건|

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

(여기부터 작성)

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

