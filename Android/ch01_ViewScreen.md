# Chapter 1. 뷰를 이용한 화면 구성

> '깡샘의 안드로이드 앱 프로그래밍 with 코틀린' 6장 학습 내용
>
> [프로젝트 바로가기]()
>
> 1절. 화면을 구성하는 방법
>
> 2절. 뷰 클래스
> 
> 3절. 기본적인 뷰
>
> 4절. 뷰 바인딩
> 
> 5절. 카카오톡 비밀번호 확인 화면 프로젝트


## 1절. 화면을 구성하는 방법

### 액티비티-뷰 구조

- 액티비티 : 화면을 출력하는 컴포넌트
-화면에 내용을 표시할 경우 뷰 클래스 이용

<img src="https://github.com/BangYunseo/TIL/blob/main/Android/Image/ch01/ch01-01-viewScreen.PNG" width="70%" height="auto" />

<img src="https://github.com/BangYunseo/TIL/blob/main/Android/Image/ch01/ch01-02-viewScreen2.PNG" width="70%" height="auto" />

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

(여기부터 작성)
```xml
```