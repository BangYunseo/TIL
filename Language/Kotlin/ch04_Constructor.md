# Chapter 4. 클래스와 생성자

> '깡샘의 안드로이드 앱 프로그래밍 with 코틀린' 4장 학습 내용
>
> [소스코드]()
>
> 1절. 클래스와 생성자
>
> 2절. 클래스를 재사용하는 상속
>
> 3절. 클래스 종류

(미완 : 복습 및 필기 필요)

## 1절. 클래스와 생성자

#### 클래스 선언

- 클래스는 class 키워드로 선언
- 본문에 입력하는 내용이 없을 경우 {} 생략
- 멤버 구성 : 생성자, 변수, 함수, 클래스
- constructor의 키워드로 선언

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
- 주 생성자의 본문 : init 영역
  - init 키워드를 통해 주 생성자의 본문 구현
  - init 키워드로 지정한 영역은 객체 생성 시 자동 실행
 
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

#### 보조 생성자
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

- 보조 생성자에 주 생성자 연결
  - 보조 생성자로 객체를 생성할 시 클래스 내에 주 생성자가 있다면 this() 구문을 이용해 주 생성자 호출
 
```Kotlin
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

  - 주 생성자가 있는 상태에서 보조 생성자를 여러 개 선언할 시 보조 생성자에서 this()로 다른 보조 생성자 호출 가능
  - 보조 생성자로 객체를 생성할 경우 어떤 식으로든 주 생성자 호출은 필수

```Kotlin
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

#### 상속과 생성자

- 코틀린에서 클래스를 상속받으려면 선언부에 콜론(:)과 함께 상속받을 클래스 이름 입력
- 코틀린의 클래스는 기본적으로 다른 클래스가 상속 불가
- 다른 클래스에서의 상속은 open키워드 사용 후 선언을 통해 상속 가능
- 상위 클래스를 상속받은 하위 클래스의 생성자에서는 상위 클래스의 생성자 호출 필요

```Kotlin
open class Super(name: String){
}
class Sub(name: String): Super(name){
}
```

- 하위 클래스에 보조 생성자만 있는 경우 상위 클래스의 생성자 호출

```Kotlin
open class Super(name: String){
}
class Sub: Super{
  constructor(name: String): super(name){
    // 소문자 super는 this와 비슷한 역할(오버라이딩)
  }
}
```

#### 오버라이딩 : 재정의
- 상속이 주는 최고의 이점
  - 상위 클래스에 정의된 멤버(변수, 함수)를 하위 클래스에서 자신의 멤버처럼 사용
  - 상위 클래스에 선언된 변수나 함수를 같은 이름으로 하위 클래스에서 다시 선언하는 것
  
```Kotlin
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

#### 접근 제한자
- 클래스의 멤버를 외부의 어느 범위까지 이용하게 할 것인지 결정하는 키워드

|접근 제한자|최상위에서 이용|클래스 멤버에서 이용|
|:---:|:---:|:---:|
|public|모든 파일에서 가능|모든 클래스에서 가능|
|internal|같은 모듈 내에서 가능|같은 모듈 내에서 가능|
|protected|사용 불가|상속 관계의 하위 클래스에서만 가능|
|private|파일 내부에서만 이용|클래스 내부에서만 이용|

```Kotlin
class Point{
 int x, y;
public:
 Point();
 Point(int a, int b);
};
```

## 3절. 클래스 종류

#### 데이터 클래스

- data 키워드로 선언
- VO 클래스를 편리하게 이용할 수 있는 방법 제공

```kotlin
class NonDataClass(val name: String, val email: String, val age: Int)

data class DataClass(val name: String, val email: String, val age: Int)
```

##### equals() 함수

- 객체의 데이터 비교

```kotlin
fun main(){
  val non1 = NonDataClass("Bang", "yunseobang33@gmail.com", 22)
  val non2 = NonDataClass("Bang", "yunseobang33@gmail.com", 22)
}
```

- 주 생성자에 선언한 멤버 변수의 데이터만 비교 대상 한정

```Kotlin
data class DataClass(val name: String, val email: String, val age: Int){
  lateinit var address: String
  constructor(name: String, email: String, age: Int, address: String):
    this(name, email, age){}
    this.address = address
  }
```

##### totring() 함수


#### 오브젝트 클래스

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

- 타입은 object 뒤에 콜론(:)을 입력하고 그 뒤에 클래스의 상위 또는 인터페이스 입력

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
    println("I am super some() : $data")
  }
}

fun main(){
  obj.data = 20    // 성공
  obj.some()       // 성공
}
```


#### 컴패니언 클래스

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
```
