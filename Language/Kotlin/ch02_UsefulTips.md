# Chapter 2. 유용한 기법

> '깡샘의 안드로이드 앱 프로그래밍 with 코틀린' 5장 학습 내용
>
> 1절. 람다 함수와 고차 함수
>
> 2절. 널 안전성

## 1절. 람다 함수와 고차 함수

#### 람다 함수

- 익명 함수 정의 기법
- 선언 및 호출
  - fun 키워드를 이용하지 않음
  - 함수 이름이 존재하지 않음
  - {}로 표현
  - {}안에 화살표(->)가 있으며 화살표 왼쪽은 매개 변수, 오른쪽은 함수 본문
  - 함수의 반환값은 함수 본문의 마지막 표현식

 
```Kotlin
//  람다 함수 선언
val sum = {no1: Int, no2: Int -> no1 + no2}

// 일반 함수 선언
fun sum(no1: Int, no2: Int): Int{
  return no1 + no2;
}
```

- 매개 변수 없는 람다 함수
  - 화살표 왼쪽이 매개 변수를 정의하는 부분
  - 매개 변수가 없을 경우 비워두거나 화살표 생략
 
```Kotlin
// 매개 변수가 없는 람다 함수
{-> println("function call")}

// 화살표가 생략된 람다 함수
{println("function call")}
```

- it 키워드 : 매개 변수가 1개인 람다 함수 
  - 매개 변수를 선언하지 않아도 매개 변수 이용 가능
  - it을 이용한 매개 변수의 사용은 해당 매개 변수의 타입을 식별할 수 있는 경우만 사용 가능
 
```Kotlin
// 기본 람다 함수

fun main(){
  val some = {no: Int -> println(no)}
  some(10)
}

// 실행 결과
// 10
```

```kt
// it 키워드가 사용된 람다 함수

fun main(){
  val some: (Int) -> Unit = {println(it)}
  some(10)
}

// 실행 결과
// 10
```

```Kotlin
// 타입 식별
val some = {println(it)}                   // 오류
val some: (Int) -> Unit = {println(it)}    // 성공
```

- 람다 함수의 반환
  - return문의 사용 불가
  - 반환값은 본문 마지막 줄의 실행 결과
 
```Kotlin
fun main(){
  val some = {no1: Int, no2: Int ->
       println("In lambda function")
       no1 * no2
  }
  println("res : ${some(10, 20)}")
}

// 실행 결과
// In lambda function
// res : 200
```

### 함수 타입과 고차 함수

- 함수 타입 선언
  - 함수 타입 : 함수를 선언할 때 나타내는 매개 변수와 반환 타입
 
```Kotlin
val some: (Int, Int) -> Int = {no1: Int, no2: Int -> no1 + no2}
//              함수 타입                  함수 내용
```

- typealias : 타입 별칭 선언 키워드

```Kotlin
typealias MyInt = Int
fun main(){
  val data1: Int = 10
  val data2: MyInt = 10
}

typealias MyFunType = (Int, Int) -> Boolean

fun main(){
  val someFun: MyFunType = {no1: Int, no2: Int ->
    no1 > no2
  }
  println(someFun(10, 20))
  println(someFun(20, 10))
}

// 실행 결과
// false
// true
```

- 매개 변수 타입 생략
  - 매개 변수의 타입을 유추할 수 있다면 타입 선언 생략 가능

```kt
// 매개변수 타입을 생략한 함수 선언

typealias MyFunType = (Int, Int) -> Boolean
val someFun: MyFunType = {no1, no2 ->
  no1 > no2
}
```

```kt
// 매개변수 타입 선언 생략

val someFun: (Int, Int) -> Boolean = {no1, no2 ->
  no1 > no2
}
```

```kt
// 변수 선언 시 타입 생략

val someFun = {no1: Int, no2: Int ->
  no1 > no2
}
```

- 고차 함수
  - 함수를 매개 변수로 전달받거나 반환하는 함수
 
```Kotlin
// 고차 함수

fun hofFun(arg: (Int) -> Boolean): () -> String{
  val res = if(arg(10)){
    "valid"
  } else {
    "invalid"
  }
  return {"hofFun res : $res"}
}

fun main(){
  val res = hofFun({no -> no > 0})
  println(res())  
}

// 실행 결과
// hofFun res : valid
```


## 2절. 널 안전성

### 널 안전성

- 널 포인트 예외가 발생하지 않도록 코드를 작성하는 것
- NULL : 객체가 선언됐지만 초기화되지 않은 상태
- NULL인 상태의 객체를 이용할 경우 널 포인트 예외(NullPointException) 발생


```Kotiln
// NULL 안전성을 개발자가 고려한 코드

fun main(){
  var data: String? = null
  var length = if(data == null){
    0
  } else {
    data.length
  }
  println("data length : $length")
}
```

- 프로그래밍 언어의 널 안전성 지원
  - 객체가 NULL인 상황에서 널 포인터 예외가 발생하지 않도록 연산자를 비롯해 여러 기법 제공
 
```Kotlin
// 코틀린이 제공하는 널 안전성 연산자를 이용

fun main(){
  var data: String? = null
  println("data length : ${data?.length ?: 0}")
}
// null일 경우 뒤의 값(0)으로, null이 아닐 경우 length로 출력


// 실행 결과
// data length : 0
```

### 널 안전성 연산자

#### ? 연산자

- NULL 허용
- 변수 타입을 NULL 허용과 NULL 불허용으로 구분

```kt
// NULL 허용과 NULL 불허

var data1: String = "bang"
data1 = null
// 오류 발생

var data2: String? = "yunseo"
data2 = null
// 성공
```

- NULL 안전성 호출
- NULL 허용으로 선언한 변수의 멤버에 접근할 때는 반드시 ? 연산자 이용

```kt
// NULL 포인트 예외 오류

var data1: String? = "bang"
var len1 = data1.length
// 오류 발생

var data2: String? = "yunseo"
var len2 = data2?.length
// 성공
```

#### ?: 연산자

- 엘비스
- NULL일 때 대입해야 하는 값이나 실행해야 하는 구문이 있을 경우 이용

```kt
// 엘비스 연산자 사용

fun main(){
  var data: String? = "yunseo"
  println("data = $data : ${data?.length ?: -1}")
  data = null
  println("data = $data : ${data?.length ?: -1}")
}

// 실행 결과
// data = kkang : 5
// data = null : -1
```

#### !! 연산자

- 예외 발생
- 객체가 널일 때 예외를 일으키는 연산자

```kt
// 예외 발생 연산자

fun some(data: String?): Int{
  return data!!.length
}

fun main(){
  println(some("yunseo"))
  println(some(null))
}

// 실행 결과
// 5
// Exception in thread "main" java.lang.NullPointerException
```