# Chapter 1. 객체지향 프로그래밍

> '깡샘의 안드로이드 앱 프로그래밍 with 코틀린' 4장 학습 내용
>
> [소스코드]()
>
> 1절. 클래스와 생성자
>
> 2절. 클래스를 재사용하는 상속
>
> 3절. 클래스 종류


## 1절. 클래스와 생성자

#### 클래스 선언

- class 
  - constructor 키워드로 클래스 선언
  - 본문에 입력하는 내용이 없을 경우 {} 생략
  - 멤버 구성 : 생성자, 변수, 함수, 클래스

```Kotlin
class User {
  var name = "Bang"
  constructor(name: String){
    this.name = name
  }

  fun someFun(){
    println("name : $name")
  }

  class SomeClass {}
}
```

  - 객체를 생성해 사용하며 객체로 클래스의 멤버에 접근
  - new 키워드 미사용

```kt
// 객체 생성과 멤버 접근

val user = User("Yunseo")
user.someFun()
```

### 주 생성자

- constructor 키워드로 클래스 선언부에 선언
- 주 생성자 선언은 필수가 아니며 한 클래스에 하나만 가능
- constructor 키워드 생략 가능

```kt
// 주 생성자 선언

class User constructor(){

}
```
  
```kt
// constructor 키워드 생략

class User() {

}
```

```kt
// 매개 변수가 없는 주 생성자 자동 선언
class User{

}
```

- 주 생성자 본문 : init 영역
  - init : 주 생성자의 본문을 구현하며 지정한 영역은 객체 생성 시 자동 실행
 
```Kotlin
class User(name: String, count: Int){
  init {
    println("i am init!!")
  }
}

fun main(){
  var user = User("Bang", 22)
}

// 실행 결과
// i am init!!
```

- 생성자의 매개변수를 클래스의 멤버 변수로 선언하는 방법
    - 생성자의 매개 변수는 기본적으로 생성자에서만 사용할 수 있는 지역 변수
    - 매개 변수를 var이나 val 키워드로 선언하여 클래스의 멤버 변수로 활용

```Kotlin
class User(name: String, count: Int){
  init{
    println("name : $name, count : $count")
  }
  fun someFun(){
    println("name : $name, count : $count")
    // 오류 발생
  }
}
```

- 매개 변수를 var이나 val 키워드로 선언하여 클래스의 멤버 변수로 활용

```kt
class User(val name: String, val count: Int){
  fun someFun(){
    println("name : $name, count : $count")
  }
}

fun main(){
  val user = User("Bang", 22)
  user.someFun()
}

// 실행 결과
// name = Bang, count = 22
```

### 보조 생성자

- 클래스의 본문에 constructor 키워드로 선언하는 함수
- 여러 개 추가 가능

```Kotlin
class User {
  constructor(name: String){
    println("constructor(name: String) call...")
  }
  constructor(name: String, count: Int){
    println("constructor(name: String, count: Int) call...")
  }
}

fun main(){
  val user1 = User("Bang")
  val user2 = User("Bang", 22)
}
```

### 보조 생성자에 주 생성자 연결

- 보조 생성자로 객체 생성 시 클래스 내에 주 생성자가 있다면 this() 구문을 이용해 주 생성자 호출
 
```Kotlin
// 보조 생성자에서 주 생성자 호출
class User(name: String) {
  constructor(name: String, count: Int) : this(name){
    // 보조 생성자가 주 생성자를 실행시켜야 하는 경우
    // 즉, class User의 name: String을 실행시킨 후
    // constructor의 보조 생성자가 실행되어야 함
  }
}

fun main(){
  val user = User("Bang", 22)
}
```

- 주 생성자가 있는 상태에서 보조 생성자를 여러 개 선언
  - 보조 생성자에서 this()로 다른 보조 생성자 호출 가능

- 보조 생성자로 객체를 생성
  - 어떤 식으로든 주 생성자 호출은 필수

```Kotlin
// 보조 생성자가 여럿인 경우 생성자 연결

class User(name: String) {
  constructor(name: String, count: Int) : this(name){
    // ...
  }
  constructor(name: String, count: Int, email: String) : this(name, count){
    // ...
  }
}

fun main(){
  val user = User("Bang", 22, "yunseobang33@gmail.com")
}
```

## 2절. 클래스를 재사용하는 상속

### 상속과 생성자

- 클래스 상속 : 선언부에 콜론(:)과 함께 상속받을 클래스 이름 입력
- 기본적으로 다른 클래스가 상속 불가
- 다른 클래스에서의 상속은 open키워드 사용 후 선언을 통해 상속 가능
- 상위 클래스를 상속받은 하위 클래스의 생성자에서는 상위 클래스의 생성자 호출 필요

```Kotlin
// 매개 변수가 있는 상위 클래스의 생성자 호출
open class Super(name: String){
}
class Sub(name: String): Super(name){
}
```

```Kotlin
// 하위 클래스에 보조 생성자만 있는 경우 상위 클래스의 생성자 호출
open class Super(name: String){
}
class Sub: Super{
  constructor(name: String): super(name){
  }
}
```

### 오버라이딩 - 재정의

- 상위 클래스에 선언된 변수나 함수를 같은 이름으로 하위 클래스에서 다시 선언하는 것
- 상위 클래스에 정의된 멤버(변수, 함수)를 하위 클래스에서 자신의 멤버처럼 사용
- 상속이 주는 최고의 이점
  
```Kotlin
// 상속 관계인 두 클래스

open class Super{
  var superData = 10
  fun superFun(){
    println("i am superFun : $superData")
  }
}
class Sub: Super()
fun main() {
  val obj = Sub()
  obj.superData = 20
  obj.superFun()
}
```

```kt
// 오버라이딩 예
open class Super{
  open var someData = 10
  open fun someFun(){
    println("I am super class function : $someData")
  }
}

class Sub: Super(){
  override var someData = 20
  override fun someFun() {
    println("I am sub class function : $someData")
  }
}

fun main(){
  val obj = Sub()
  obj.someFun()
}

// 실행 결과
// I am sub class function : 20
```

### 접근 제한자

- 클래스의 멤버를 외부의 어느 범위까지 이용하게 할 것인지 결정하는 키워드

|접근 제한자|최상위에서 이용|클래스 멤버에서 이용|
|:---:|:---:|:---:|
|public|모든 파일에서 가능|모든 클래스에서 가능|
|internal|같은 모듈 내에서 가능|같은 모듈 내에서 가능|
|protected|사용 불가|상속 관계의 하위 클래스에서만 가능|
|private|파일 내부에서만 이용|클래스 내부에서만 이용|

```Kotlin
// 접근 제한자 사용 예시
open class Super{
  var publicData = 10
  protected var protectedData = 20
  private var privateData = 30
}

class Sub: Super(){
  fun subFun(){
    publicData++
    protectedData++
    // privateData++ -> 오류 발생
  }
}

fun main(){
  val obj = Super()
  obj.publicData++
  // obj.protectedData++ -> 오류 발생
  // obj.privateData++ -> 오류 발생
}
```

## 3절. 클래스 종류

### 데이터 클래스

- data 키워드로 선언
- VO 클래스를 편리하게 이용할 수 있는 방법 제공

```kotlin
class NonDataClass(val name: String, val email: String, val age: Int)

data class DataClass(val name: String, val email: String, val age: Int)
```

### equals() 함수

- 객체의 데이터 비교

```kotlin
fun main(){
  val non1 = NonDataClass("Bang", "yunseobang33@gmail.com", 22)
  val non2 = NonDataClass("Bang", "yunseobang33@gmail.com", 22)

  val data1 = DataClass("Bang", "yunseobang33@gmail.com", 22)
  val data2 = DataClass("Bang", "yunseobang33@gmail.com", 22)

  println("non data class equals : ${non1.equals(non2)}")
  println("data class equals : ${data1.equals(data2)}")
}

// 실행 결과
// non data class equals : false
// data class equals : true
```

- equals() 함수는 주 생성자에 선언한 멤버 변수의 데이터만 비교 대상

```Kotlin
data class DataClass(val name: String, val email: String, val age: Int){
  lateinit var address: String
  constructor(name: String, email: String, age: Int, address: String):
    this(name, email, age){
    this.address = address
  }
}

fun main(){
  val obj1 = DataClass("Bang", "yunseo@gmail.com", 23, "Incheon")
  val obj2 = DataClass("Bang", "yunseo@gmail.com", 23, "Seoul")
  println("obj1.equals(obj2) : ${obj1.equals(obj2)}")
}

// 실행 결과
// obj1.equals(obj2) : true
```

### toString() 함수

- 데이터 클래스를 사용하면서 객체가 가지는 값을 확인할 때 이용

(여기부터 작성) 

```Kotlin
fun main(){
  class NonDataClass(val name: String, val email: String, val age: Int)
  data class DataClass(val name: String, val email: String, val age: Int)
  val non = NonDataClass("Bang", "yunseobang33@gmail.com", 23)
  val data = DataClass("Bang", "yunseobang33@gmail.com", 23)
  println("non data class toString : ${non.toString()}")
  println("data class toString : ${data.toString()}")
}

// 실행 결과
// non data class toString : com.example.test.ch2.TestKt$main$NonDataClass@61bbe9ba
// data class toString : DataClass(name=Bang, email=yunseobang33@gmail.com, age=23)
```

### 오브젝트 클래스

- 익명 클래스를 만들 목적으로 사용
- 선언과 동시에 객체를 생성한다는 의미
- object 키워드 사용
- 한 번 사용 후 버릴 클래스

```Kotlin
val obj = object{
  var data = 10
  fun some(){
    println("data : $data")
  }
}

fun main(){
  obj.data = 20    // 오류 발생
  obj.some()       // 오류 발생
}
```

-object 뒤에 콜론(:)을 입력하고 그 뒤에 클래스의 상위 또는 인터페이스 입력

```Kotlin
open class Super{
  open var data = 10
  open fun some(){
    println("I am super some() : $data")
  }
}

val obj = object: Super(){
  override var data = 10
  override fun some(){
    println("I am object some() : $data")
  }
}

fun main(){
  obj.data = 30    // 성공
  obj.some()       // 성공
}

// 실행 결과
// I am object some() : 30
```


### 컴패니언 클래스

- 멤버 변수나 함수를 클래스 이름으로 접근하고자 할 경우 사용
- companion의 키워드로 선언

```Kotiln
class MyClass {
  companion object {
    var data = 10
    fun some() {
      println(data)
    }
  }
}

fun main(){
  MyClass.data = 20
  MyClass.some()
}

// 실행 결과
// 20
```
