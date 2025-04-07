# Chapter 0. 코들린(Kotlin) 개요

> '깡샘의 안드로이드 앱 프로그래밍 with 코틀린' 3장 학습 내용
>
> 1절. 코틀린 등장 배경
>
> 2절. 변수와 함수
> 
> 3절. 조건문과 반복문

## 1절. 코틀린 등장 배경

### 배경


<img src="https://github.com/BangYunseo/TIL/blob/main/Android/Image/ch00/ch00-01-progress.PNG" width="50%" height="auto" />

- 젯브레인스(JetBrains)에서 오픈소스 그룹을 만들어 개발한 프로그래밍 언어
- 2017년 구글에서 안드로이드 공식 언어로 지정
- JVM에 기반을 둔 언어
- 코틀린 컴파일러(kotlinc)가 .kt 파일을 컴파일하면 자바 바이트 코드 생성

### 장점

1) 최신 언어 기법을 사용할 경우 훨씬 간결한 구문으로 프로그램 작성 가능

2) 널 안전성(Null Safety)를 지원하는 언어

3) 자바와 100% 호환하는 언어

4) 코루틴(corutines)이라는 기법을 이용할 경우 비동기 프로그래밍 간소화 가능

### 파일 구성

```kotlin
// 패키지
package com.example.test

// 임포트
import java.text.SimpleDateFormat
import java.util.*

// 변수
var data = 10

// 함수
fun formatDate(date: Date) : String {
    val sdformat = SimpleDateFormat("yyyy-mm-dd")
    return sdformat.format(date)
}

// 클래스
class User{
    var name = "방윤서"

    fun sayHello(){
        println("name : $name")
    }
}
```

- 패키지 경로의 차이
    - 패키지 경로를 다르게 작성하면 import 구문으로 불러와야 함

```kotlin
// 다른 패키지 경로
package ch00

// import 구문으로 불러온 구문들
import com.example.test.User
import com.example.test data
import com.example.test.formatDate

import java.util.*

fun main {
    data = 20
    formatDate(Date())
    User().sayHello()
}
```

### 코틀린 소스 테스트

- 테스트할 코틀린 소스 파일에 main() 함수가 있어야 함
- 실행 시 main() 함수 자동 실행 후 프로그램 종료

```kt
fun main {
    println("Say Hello!")
}
```

## 2절. 변수와 함수

### 변수 선언

- 변수는 val, var 키워드로 선언
    - val : value의 줄임말로 초깃값이 할당되면 변경 불가
    - var : variable의 줄임말로 초깃값 할당 이후에도 값 변경 가능 

```kt
// 변수 선언 형식

val data1 = 10
var data2 = 10

fun main {
    // data1 = 20 : 오류 발생
    data2 = 20
}
```

### 타입 지정 및 추론

- 변수명 뒤에 콜론(:)으로 타입 명시 가능
- 대입하는 값에 따라 타입을 유추(타입 추론)할 수 있는 경우 생략

```kt
// 변수 타입 지정과 타입 추론

val data1 : Int = 10
val data2 = 10
```

### 초깃값 할당

- 최상위에 선언한 변수나 클래스의 멤버 변수는 선언과 동시에 초깃값 할당 필요
- 함수 내부 선언 변수는 선언과 동시에 초깃값 할당 필요 X

```kt
// 초깃값 할당

// val data1: Int => 오류 발생 : 초깃값 미할당
val data2 = 10

fun someFun() {
    val data3: Int
    // println("Data3 : $data3") => 오류 발생 : 초깃값이 미할당된 변수 출력
    data3 = 10
    println("Data3 : $data3")
}

class User {
    // val data4: Int => 오류 발생
    val data5: Int = 10
}
```

### 초기화 미루기

- lateinit : 이후에 초깃값을 할당함을 명시적 선언하고 var 키워드로 선언한 변수에만 사용 가능
- Int, Long, Short, Double, Float, Boolean, Byte 타입에 사용 불가

```kt
// 초기화 미루기 1 - lateinit

// lateinit val data1: Int      => 오류 발생
// lateinit val data2: String   => 오류 발생
lateinit var data3: String
```

- by lazy {} 형식으로 선언 가능
- 소스에서 변수가 최초로 이용될 경우 중괄호로 묶은 부분이 자동 실행
- 그 결괏값이 변수 초깃값으로 할당
- lazy 문의 중괄호 부분을 여러 줄로 작성할 경우 마지막 줄의 실행 결과가 변수의 초깃값

```kt
// 초기화 미루기 2 - lazy

val data4: Int by lazy{
    println("I'm so lazy......")
    10
}

fun main(){
    println("in main function!")
    println(data4 + 10)
    println(data4 + 10)
}

// 실행 결과
// in main function!
// I'm so lazy......
// 20
// 20
```

### 데이터 타입

- 코틀린의 모든 변수는 객체
- Int 는 기초 데이터 타입(primitive type)이 아닌 클래스

```kt
// Int 타입에 Null 대입 및 메서드 이용

fun someFun() {
    var data1: Int = 10
    var data2: Int? = null      // null 대입 가능

    data1 = data1 + 10
    data1 = data1.plus(10)      // 객체 메서드 이용 가능
}
```

- 기초 타입 객체 : Int, Short, Long, Double, Float, Byte, Boolean
- 문자와 문자열 : Char, String
    - String 타입의 데이터는 문자열을 큰 따옴표(" ")나 삼중 따옴표(""" """)로 감싸 표현
    - 문자열 템플릿 : String 타입의 데이터에 변숫값이나 어떤 연산식의 결괏값을 표현할 때는 $ 기호 이용

```kt
// 문자 표현

val a: Charr = 'a'
if(a == 1) {}       // 오류 발생
```

```kt
// 기초 타입 객체

val a1: Byte = 0b00001011
val a2: Int = 123
val a3: Short = 123
val a4: Long = 10L
val a5: Double = 10.0
val a6: Float = 10.0f
val a7: Boolean = true
```

```kt
// 문자열 표현 - 큰 따옴표와 삼중 따옴표 차이

fun main()  {
    val str1 = "Hello \n World"
    val str2 = """
        Hello
        World
    """
    println("str1 : $str1")
    println("str2 : $str2")
}

// 실행 결과
// str1 : Hello 
/ World
//str2 : 
//        Hello
//        World
```


```kt
// 문자열 템플릿

fun main()  {
    fun sum(no: Int): Int {
        var sum = 0
        for(i in 1..no) { sum += i }
        return sum 
    }

    val name: String = "Bang Yunseo"
    println("name : $name, sum : ${sum(10)}, plus : ${10 + 20}")
}

// 실행 결과
// name : Bang Yunseo, sum : 55, plus : 30
```

- Any : 모든 타입 가능
- Unit : 반환문이 없는 함수

```kt
// Any 타입 예

val data1: Any = 10
val data2: Any = "Hello~!"

class User
val data3: Any = User()
```

```kt
// Unit 타입 예

val data1: Unit = Unit
```

```kt
// Unit 타입 예 : 반환문이 없는 함수

fun some(): Unit {
    println(10 + 20)
}
```

```kt
// 반환 타입 생략 예

fun some() {
    println(10 + 20)
}
```

- Nothing : NULL이나 예외를 반환하는 함수
- NULL 허용과 불허용
    - 타입 뒤 물음표가 있을 경우 NULL 허용
    - 타입 뒤 물음표가 없을 경우 NULL 불허용

```kt
// Nothing 사용 예
val data1: Nothing? = null
```

```kt
// NULL 반환 함수와 예외를 던지는 함수
fun some1(): Nothing? {
    return null
}
fun some2(): Nothing {
    throw Exception()
}
```

```kt
// NULL 허용과 불허용
var data1: Int = 10
// data1 = null : 오류 발생

var data2: Int? = 10
data2 = null
```

### 함수 선언

- 함수를 선언 : fun 키워드
    - 반환 타입을 선언 가능
    - 생략할 경우 자동 Unit 타입 적용
- 함수의 매개 변수
    - var이나 val 키워드 사용 불가
    - 자동으로 val 적용

```kt
// 반환 타입이 있는 함수 선언
fun some(data1: Int): Int{
    return data1 * 10
}
```

```kt
fun some(data1: Int) {
    // data1 = 20 : 오류 발생
}
```

- 함수의 매개 변수에 기본값 선언 가능
    - 매개 변수에 기본값 선언 시 호출할 때 인자(argument) 전달하지 않아도 됨
    - 선언문에 명시한 기본값 적용 가능

```kt
// 기본값 활용

fun main() {
    fun some(data1: Int, data2: Int = 10): Int{
        return data1 * data2
    }
    println(some(10))
    println(some(10, 20))
}

// 실행 결과
// 100
// 200
```

- 명명된 매개 변수 : 매개 변수 명을 지정하여 호출
- 함수 선언문의 매개 변수 순서에 맞춰 호출하지 않아도 작동

```kt
// 매개 변수 명 생략 : 매개 변수 순서대로 할당
fun some(data1: Int, data2: Int): Int{
    return data1 * data2
}
println(some(10, 20))
```
```kt
some(data2 = 20, data1 = 10)
```

### 컬렉션 타입

#### Array : 배열 표현

- 배열은 Array 클래스로 표현
- Array 클래스의 생성자
    - 첫 번째 매개 변수 : 배열의 크기
    - 두 번째 매개 변수 : 초깃값 지정 함수
- Array\<Int\>로 선언한 경우 : 정수 배열 의미
- Array\<String\>으로 선언한 경우 : 문자열 배열 의미
- 배열 데이터에 접근
    - 대괄호([])로 이용 가능
    - set(), get() 함수 이용 가능

```kt
// 배열의 데이터에 접근하는 예

fun main(){
    val data1: Array<Int> = Array(3, {0})
    data1[0] = 10
    data1[1] = 20
    data1.set(2, 30)
    // 배열 2번째 데이터를 30으로 설정

    println("""
    array size : ${data1.size}
    array data : ${data1[0]}, ${data1[1]}, ${data1.get(2)}
    """)
    // get() 함수를 통한 2번째 데이터 가져오기
}

// 실행 결과
//     array size : 3
//    array data : 10, 20, 30
```

- 기초 타입 배열
    - 기초 타입인 경우 Array를 사용하지 않고 클래스 이용
    - 클래스 예시 : BooleanArray, ByteArray, CharArray, DoubleArray, FloatArray, IntArray, LongArray, ShortArray 클래스 제공

```kt
// 기초 타입 배열 선언

val data1: IntArray = IntArray(3, { 0 })
val data2: BooleanArray(3, { false })
```

- arrayOf() : 배열 선언 시 값 할당 가능
    - 클래스 예시 : booleanArrayOf(), byteArrayOf(), charArrayOf(), doubleArrayOf(), floatArrayOf(), intArrayOf(), longArrayOf(), shortArrayOf() 함수 제공

```kt
// 기초 타입 arrayOf() 함수

val data1 = intArrayOf(10, 20, 30)
val data2 = booleanArrayOf(true, false, true)
```

```kt
// 배열 선언과 동시에 값 할당

fun main(){
    val data1 = arrayOf<Int>(10, 20, 30)
    // 크기가 3인 int 배열을 선언하고 각각 10, 20, 30 으로 할당

    println("""
    array size : ${data1.size}
    array data : ${data1[0]}, ${data1[1]}, ${data1.get(2)}
    """)
}

// 실행 결과
//  array size : 3
//  array data : 10, 20, 30
```

#### List, Set, Map

- List : 순서가 있는 데이터 집합으로 데이터 중복 허용
- Set : 순서가 없는 데이터 집합으로 데이터 중복 비허용
- Map : 키와 값으로 이루어진 데이터 집합으로 순서가 없으며 키의 중복 비허용

- Collection 타입의 클래스 : 가변 클래스 or 불변 클래스
    - 가변 클래스 : 초깃값 대입 이후 데이터를 추가하거나 변경 가능
    - 불변 클래스 : 초기에 데이터 대입 시 더 이상 변경 불가능한 타입

|구분|타입|함수|특징|
|:---:|:---|:---|:---:|
|List|1. List<br><br>2. MutableList|1. listOf()<br><br>2. mutableListOf()|1. 불변<br><br>2. 가변|
|Set|1. Set<br><br>2. MutableSet|1. setOf()<br><br>2. mutableSetOf()|1. 불변<br><br>2. 가변|
|Map|1. Map<br><br>2. MutableMap|1. mapOf()<br><br>2. mutableMapOf()|1. 불변<br><br>2. 가변|

```kt
// 리스트 사용 예

fun main(){
    var list = listOf<Int>(10, 20, 30)

    println("""
    list size : ${list.size}
    list data : ${list[0]}, ${list[1]}, ${list.get(2)}
    """)
}

// 실행 결과
//  list size : 3
//  list data : 10, 20, 30
```

```kt
// 가변 리스트 사용 예

fun main(){
    var mutableList = mutableListOf<Int>(10, 20, 30)
    mutableList.add(3, 40)
    mutableList.set(0, 50)
    println("""
    list size : ${mutableList.size}
    list data : ${mutableList[0]}, ${mutableList.get(1)},
                ${mutableList.get(2)}, ${mutableList.get(3)}
    """)
}

// 실행 결과
//  list size : 3
//  list data : 50, 20, 30, 40
```

    - Map 객체 : 키와 값으로 이루어진 데이터 집합
    - Map 객체의 키와 값은 Pair 객체를 이용할 수도 있고 '키 to 값'형태로 이용 가능


```kt
// 집합 사용 예

fun main() {
    var map = mapOf<String, String>(Pair("one", "hello"), "two" to "world")
    println("""
    map size : ${map.size}
    map data : ${map.get("one")}, ${map.get("two")}
    """)
}

// 실행 결과
//  map size : 2
//  map data : hello, world
```

## 3절. 조건문과 반복문

### 조건문 if ~ else와 표현식

- if문의 명시된 조건 만족 시 if문 실행, 그렇지 않으면 else 문 실행

```kt
// if ~ else 문의 조건이 여러 개 나열된 예

fun main(){
    var data = 10
    if(data > 10) { println("data > 10") }
    else if(data > 0 && data <= 10) { println("data > 0 && data <= 10") }
    else { println("data <= 0") }
}

// 실행 결과
// data > 0 && data <= 10
```

    - 코틀린에서 if~else는 표현식으로 사용 가능
    - 표현식 : 결괏값을 반환하는 계산식

```kt
// if ~ else 문의 조건이 여러 개 나열된 예

fun main(){
    var data = 10
    var res = if(data > 0){
        println("data > 0")
        true
    } else {
        println("data <= 0")
        false
    }
    println(res)
}

// 실행 결과
// data > 0
// true
```

### 조건문 when

```kt
// when문 사용 예시

fun main(){
    var data = 10
    when(data){
        10 -> println("data is 10")
        20 -> println("data is 20")
        else -> {
            println("data is not valid data")
        }
    }
}

// 실행 결과
// data is 10
```

    - when 문의 조건으로 정수가 아닌 다른 타입의 데이터 지정 가능

```kt
// 문자열 타입 조건 사용 예시

fun main(){
    var data = "hello"
    when(data){
        "hello" -> println("data is hello")
        "world" -> println("data is world")
        else -> {
            println("data is not valid data")
        }
    }
}

// 실행 결과
// data is hello
```

    - when 문에서는 조건을 데이터 타입, 범위 등으로 다양하게 명시 가능
    - is : 타입 확인 연산자
    - in : 범위 지정 연산자


```kt
// 다양한 유형의 조건 제시

fun main(){
    var data: Any = 10
    when(data){
        is String -> println("data is String")
        20, 30 -> println("data is 20 or 30")
        in 1..10 -> println("data is 1..10")
        else -> println("data is not valid")
    }
}

// 실행 결과
// data is 1..10
```

    - when은 if문과 마찬가지로 표현식으로도 사용 가능

```kt
// when 문을 표현식으로 사용

fun main(){
    var data = 10
    var res = when{
        data <= 0 -> "data is <= 0"
        data > 100 -> "data is > 100"
        else -> "data is valid"
    }
    println(res)
}

// 실행 결과
// data is valid
```

### 반복문 for과 while

- for문
    - 제어 변숫값을 증감하며 특정 조건이 참일 때까지 구문 반복 수행
    - 조건에는 주로 범위 연산자인 in 사용
        - for(i in 1..10) {...} : 1 ~ 10까지 1씩 증가
        - for(i in 1 until 10) {...} : 1 ~ 9까지 1씩 증가(10 미포함)
        - for(i in 2..10 step 2) {...} : 2 ~ 10까지 2씩 증가
        - for(i in 10 downTo 1) {...} : 10부터 1까지 1씩 감소

```kt
// for ~ in 반복문

fun main(){ 
    var sum: Int = 10
    for(i in 1..10) { sum += i }
    println(sum)
}

// 실행 결과
// 55
```

    - 컬렉션 타입의 데이터 개수만큼 반복
    - indices : 컬렉션 타입의 인덱스 값 의미
    - withIndex() : 인덱스와 실제 데이터를 함께 가져오는 함수

```kt
// 반복 조건에 컬렉션 타입 활용

fun main(){
    var data = arrayOf<Int>(10, 20, 30)
    for(i in data.indices){
        print(data[i])
        if(i !== data.size - 1) print(", ")
    }
}

// 실행 결과 
// 10, 20, 30
```

```kt
// 인덱스와 데이터를 가져오는 withIndex() 함수

fun main(){
    var data = arrayOf<Int>(10, 20, 30)
    for((index, value) in data.withIndex()){
        print(value)
        if(i !== data.size - 1) print(", ")
    }
}

// 실행 결과 
// 10, 20, 30
```

    - while문 : 조건이 참일 경우 중괄호({ })로 지정한 영역 반복 실행

```kt
fun main(args: Array<String>){
    var x = 0
    var sum = 0
    while(x < 10) { sum += ++x }
    println(sum)
}

// 실행 결과
// 55
```