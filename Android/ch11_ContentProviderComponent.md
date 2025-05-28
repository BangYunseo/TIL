# Chapter 11. 콘텐츠 프로바이더 컴포넌트

> '깡샘의 안드로이드 앱 프로그래밍 with 코틀린' 16장 학습 내용
>
> 1절. 콘텐츠 프로바이더
>
> 2절. 안드로이드 앱 연동
>
> 3절. 연동 앱 구현  
> [프로젝트 바로가기](https://github.com/BangYunseo/AndroidProject/tree/main/ch11)

## 1절. 콘텐츠 프로바이더

### 개념

<img src="https://github.com/BangYunseo/TIL/blob/main/Android/Image/ch10/ch11-01-CPC.PNG" height="auto" />

- 앱끼리 데이터 연동하는 컴포넌트

### 콘텐츠 프로바이더 작성

- ContentProvider 클래스 상속
- 재정의 함수 종류

  - onCreate()
  - getType()
  - query()
  - insert()
  - update()
  - delete()

  ```kt
  // 콘텐츠 프로바이더 작성

  class MyContentProvider : ContentProvider(){
    override fun delete(uri: Uri, selection: String?, selectionArgs: Array<String>?): Int {
        return 0
    }

    override fun getType(uri: Uri): String? {
        return null
    }

    override fun insert(uri: Uri, values: ContentValues?): Uri? {
        return null
    }

    override fun onCreate(): Boolean{
        return false
    }

    override fun query(uri: Uri, projection: Array<String>?, selection: String?, selectionArgs: Array<String>?, sortOrder: String?): Cursor?{
        return null
    }

    override fun update(uri: Uri, values: ContentValues?, selection: String?, selectionArgs: Array<String>?): Int{
        return 0
    }
  }
  ```

### 매니페스트

- 안드로이드 컴포넌트이므로 AndroidManifest.xml에 등록
- name 속성, authorities 속성 반드시 선언
  - authorities 속성 : 외부에서 콘텐츠 프로바이더 이용 시 식별값

```XML
<provider
    android:name=".MyContentProvider"
    android:authorities="com.example.test_provider"
    android:enabled="true"
    android:exported="true"></provider>
```

### 콘텐츠 프로바이더 이용

- 인텐트와 상관 X
- 외부 앱에서 콘텐츠 프로바이더 사용 시 먼저 매니페스트에 해당 앱 패키지 공개 설정 필요
- ContentResolver 객체 사용
  - 위에 정의된 함수들과 동일
  - public final int delete(Uri url, String where, String[] selectionArgs)
  - public final Uri insert(Uri url, ContentValues values)
  - public final Cursor query(Uri uri, String[] projection, String selection,String[] selectionArgs, String sortOrder)
  - public final int update(Uri uri, ContentValues values, String where,String[] selectionArgs)

```XML
<!-- 패키지 공개 설정 -->

<queries>
    <package android:name="com.example.test_outer">
</queries>
```

```kt
// 시스템 콘텐츠 프로바이더 사용

contentResolver.query(
    Uri.parse("content://com.example.test_provider"),
    null, null, null, null)
```

### authorities

<img src="https://github.com/BangYunseo/TIL/blob/main/Android/Image/ch10/ch11-02-AT.PNG" height="auto" />

- Uri 객체의 URL 문자열 구조
  - 프로토콜 명
  - 콘텐츠 프로바이더 식별자

## 2절. 안드로이드 앱 연동

### 주소록 앱 연동

- 퍼미션 설정

```XML
<!-- 주소록 앱 사용 퍼미션 설정 -->

<uses-permission android:name="android.permission.READ_CONTACTS" />
```

- 주소록 목록 화면
  - ContactsContract.Contacts.CONTENT_URI: 모든 사람의 데이터
  - ContactsContract.CommonDataKinds.Phone.CONTENT_URI: 전화번호가 존재하는 사람의 데이터
  - ContactsContract.CommonDataKinds.Email.CONTENT_URI: 이메일이 존재하는 사람의 데이터

```kt
// 주소록 목록 출력

val intent = Intent(Intent.ACTION_PICK, ContactsContract.CommonDataKinds.Phone.CONTENT_URI)
requestContactsLaunch.launch(intent)
```

### ActivityResultCallback

- 목록에서 한 사람 선택 후 돌아오면 onActivityResult() 함수 자동 실행

```kt
// 주소록에서 사용자 한 사람 선택 시 실행

requestContactsLauncher = registerForActivityResult(
    ActivityResultContracts.StartActivityForResult())
{
    if(it.resultCode == RESULT_OK){
        Log.d("yunseo", "${it.data?.data}")
    }
}
```

- 주소록 앱 전달 문자열

<img src="https://github.com/BangYunseo/TIL/blob/main/Android/Image/ch10/ch11-03-StringEx.PNG" height="auto" />

### 구체적 요청

- 식별값 조건으로 주소록 앱에 필요 데이터 재요청

```kt
// 콘텐츠 프로바이더로 필요 데이터 요청

requestContactsLauncher = registerForActivityResult(
    ActivityResultContracts.StartActivityForResult())
{
    if(it.resultCode == RESULT_OK){
        val cursor = contentResolver.query(
            it!!.data!!.data!!,
            arrayOf<String>(
                ContactsContract.CommonDataKinds.Phone.DISPLAY_NAME,
                ContactsContract.CommonDataKinds.Phone.NUMBER
            ),
            null,
            null,
            null
        )
        Log.d("yunseo", "cursor size : ${cursor?.count}")
        if(cursor!!.moveToFirst()){
            val name = cursor?.getString(0)
            val phone = cursor?.getString(1)
            binding.resultContact.text = "name : $name, phone : $phone"
        }
    }
}
```

### 갤러리 앱 연동

- 인텐트로 갤러리 앱 목록 화면 표시
- 콘텐츠 프로바이터로 데이터 가져오기

### 갤러리 작업 고려 사항

- 안드로이드 이미지 : Drawable이나 Bitmap 객체 표현
- Bitmap 객체 : BitmapFactory로 생성
- BitmapFactory로 이미지를 생성할 때는 OOM 오류 고려
- Glide나 Picasso 같은 이미지 처리 라이브러리로 효율적 이용

#### OOM 오류

- 앱의 메모리 부족 시 발생하는 오류
- 용량이 큰 이미지 불러올 경우 발생
- 이미지 크기 줄이기
  - BitmapFactory.Option 객체의 inSampleSize 속성

```kt
// 옵션 지정 후 비트맵 생성

val option = BitmapFactory.Options()
option.inSampleSize = 4
val bitmap = BitmapFactory.decodeStream(inputStream, null, option)
```

- inSampleSize 값 계산 : calculateInSampleSize

```kt
// 적절한 비율의 이미지 크기 감소

private fun calculateInSampleSize(fileUri: Uri, reqWidth: Int, reqHeight: Int): Int{
    val options = BitmapFactory.Options()
    options.inJustDecodeBounds = true
    // 옵션만 설정하고자 true 지정

    try{
        var inputStream = contentResolver.openInputStream(fileUri)
        BitmapFactory.decodeStream(inputStream, null, options)
        // 각종 이미지 정보가 옵션에 설정

        inputStream!!.close()
        inputStream = null
    } catch(e : Exception){
        e.printStackTrace()
    }

    val (height: Int, width: Int) = options.run { outHeight to outWidth}
    var inSampleSize = 1

    if(height > reqHeight || width > reqWidth){
        val halfHeight: Int = height / 2
        val halfWidth: Int = width / 2
        while(halfHeight / inSampleSize >= reqHeight &&
              halfWidth / inSampleSize >= reqWidth){
                inSampleSize *= 2
        }
    }
    return inSampleSize
}
```

- 이미지 불러오기

```kt
// 이미지 불러오기 코드

requestGalleryLauncher = registerForActivityResult(
    ActivityResultContracts.StartActivityForResult())
{
    try{
        // inSampleSize 비율 계산 및 지정
        val calRatio = calculateInSampleSize(it!!.data!!.data!!,
            resources.getDimensionPixelSize(R.dimen.imgSize),
            resources.getDimensionPixelSize(R.dimen.imgSize))
        val option = BitmapFactory.Options()
        option.inSampleSize = calRatio

        // 이미지 로딩
        var inputStream = contentResolver.openInputStream(it!!.data!!.data!!)
        val bitmap = BitmapFactory.decodeStream(inputStream, null, option)
        inputStream!!.close()
        inputStream = null
        bitmap?. let{
            binding.galleryResult.setImageBitmap(bitmap)
        } ?: let{
            Log.d("yunseo", "bitmap null")
        }
    } catch(e: Exception){
        e.printStackTrace()
    }
}
```

### Bitmap 이미지

- BitmapFactory 클래스의 'decode'로 시작하는 아래 함수 생성
  - BitmapFactory.decodeByteArray() : byte[] 배열의 데이터로 비트맵 생성
  - BitmapFactory.decodeFile() : 파일 경로를 매개변수로 지정하면 그 파일에서 데이터를 읽을 수 있는 FileInputStream 생성 후 decodeStream() 함수 사용
  - BitmapFactory.decodeResource(): 리소스 이미지로 비트맵 생성
  - BitmapFactory.decodeStream(): InputStream으로 읽은 데이터로 비트맵 생성

### 갤러리 앱 연동 방법

- 앱 사진 목록 출력 코드

```kt
// 사진 목록 출력

val intent = Intent(Intent.ACTION_PICK, MediaStore.Images.Media.EXTERNAL_CONTENT_URI)
intent.type = "image/*"
requestGalleryLauncher.launch(intent)
```

### 카메라 앱 연동

#### 1. 사진 데이터 가져오기

- 인텐트로 카메라 앱의 사진 촬영 액티비티 실행

```kt
// 사진 촬영 액티비티 실행

val intent = Intent(MediaStore.ACTION_IMAGE_CAPTURE)
requestCameraThubnailLauncher.launch(intent)
```

- ActivityResultCallback에서 획득한 사진 데이터

```kt
// 사진 데이터 가져오기

requestCameraThubnailLauncher = registerForActivityResult(
    ActivityResultContracts.StartActivityForResult())
{
    val bitmap = it?.data?.extras?.get("data") as Bitmap
}
```

#### 2. 사진 파일 공유

1. 앱에서 사진을 저장할 파일 생성
2. 사진 파일 정보를 포함한 인텐트를 전달해 카메라 앱 실행
3. 카메라 앱으로 사진을 촬영하여 공유된 파일에 저장
4. 카메라 앱을 종료하면서 성공 또는 실패 반환
5. 카메라 앱이 저장한 사진 파일을 앱에서 이용

- 앱끼리 파일 공유 시 content:// 프로토콜 이용
  - 해당 URI에 임시 접근 권한 부여

```XML
<!-- 파일 프로바이더 -->

<path xmlns:android="http://schemas.android.com/apk/res/android">
    <external-path name="myfiles" path="Android/data/com.example.test16/files/Pictures" />
</path>
```

- FileProvider 클래스
  - androidx 라이브러리에서 제공
  - XML 설정 기반으로 content:// 프로토콜로 구성된 URI 생성

```XML
<!-- AndroidManifest.XML 에 적용할 파일 프로바이더 -->

<provider
    android:name="androidx.core.content.FileProvider"
    android:authorities="com.example.test16.fileprovider"
    android:grantUriPermissions="true"
    android:exported="false"></provider>
    <meta-data
        android:name="android.support.FILE_PROVIDER_PATHS"
        android:resource="@xml/file_paths"></meta-data>
</provider>
```

(여기부터 작성 필요)

- 파일 생성

```kt
// 파일 생성

```

- FileProvider로 Uri객체 생성 후 인텐트 엑스트라 데이터 설정

## 3절. 연동 앱 구현

### 1) 모듈 생성 & 빌드 그래들 작성

- Ch16_Provider 모듈 생성
- 뷰 바인딩 기법 사용 설정

```kts
// 빌드 그래들 작성

viewBinding.isEnabled = true
```

### 2) 실습 파일 복사

- res의 drawable, layout 디렉터리를 Ch15_Service 모듈의 같은 위치에 복사
- 코틀린 파일이 있는 디렉터리에서 MainActivity.kt 파일 복사 후 Ch15_Service 모듈의 소스 영역에 덮어쓰기

### 3) 재생 음원 파일 준비

- res/raw 디렉터리를 Ch15_outer 모듈 res 에 복사

### 4) AIDL 서비스 작성

- 파일이 있는 패키지에서 마우스 오른쪽 버튼 클릭
- [New - AIDL - AIDL File - 파일 명 입력 - finish]
- 자동으로 패키지까지 잡혀서 aidl 파일 생성

### 5) AndroidManifest.xml에 패키지 공개 등록

###

### 6) 앱 실행
