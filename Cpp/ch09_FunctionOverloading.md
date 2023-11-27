#  Chapter 9. 함수 중복       
> '명품 C++Programming - 황기태' 6장 학습 내용
>
> [소스코드](https://github.com/BangYunseo/Basic_CPP/tree/main/ch09_FunctionOverloading)
> 
> 1절. 함수 중복
> 
> 2절. 생성자와 소멸자
>
> 3절. 디폴트 매개 변수
>
> 4절. 함수 중복 특성
>

## 1절. 함수 중복
#### 함수 중복이란?
* 동일한 이름의 함수가 공존하는 것
  * 다형성
  * C언어는 불가능
* Function Overloading
* 함수 중복이 가능한 범위
  * 보통 함수들 사이
  * 클래스의 멤버 함수들 사이
  * 상속 관계에 있는 기본 클래스와 파생 클래스의 멤버 함수들 사이

#### 함수 중복 성공 조건
* 중복된 함수들의 이름이 동일할 때
* 중복된 함수들의 매개 변수 타입이 다르거나 개수가 다를 때
* 리턴 타입이 함수 중복과 무관할 때

#### 함수 중복 성공 사례

![successoverloading](https://github.com/BangYunseo/TIL/blob/main/Cpp/Image/ch9/successoverloading.PNG)

#### 함수 중복 실패 사례

* 리턴 타입이 다르다고 함수 중복이 성공하지는 않음
![failoverloading](https://github.com/BangYunseo/TIL/blob/main/Cpp/Image/ch9/failoverloading.PNG)

#### 함수 중복의 편리함
* 동일한 이름을 사용하는 함수 중복
  * 함수의 이름을 구분하여 기억할 필요가 없음
    * ex) sum1, sum2, ...
  * 함수 호출을 잘못하여 발생되는 실수 감소

![comfortableoverloading](https://github.com/BangYunseo/TIL/blob/main/Cpp/Image/ch9/comfortableoverloading.PNG)

* 예제 1. big() 함수 중복 연습    
[SourceCodeChecking](https://github.com/BangYunseo/Basic_CPP/blob/main/ch9_FunctionOverloading/BigFunctionOverloading.cpp)

* 예제 2. sum() 함수 중복 연습     
[SourceCodeChecking](https://github.com/BangYunseo/Basic_CPP/blob/main/ch9_FunctionOverloading/SumFunctionOverloading.cpp)

## 2절. 생성자와 소멸자
#### 생성자 함수 중복
* 생성자 함수를 중복해서 사용 가능
  * 생성자 함수 중복의 목적?
    * 객체를 생성할 때 매개 변수를 통해 다양한 형태의 초깃값을 전달하기 위해

![defconstructor](https://github.com/BangYunseo/TIL/blob/main/Cpp/Image/ch9/defconstructor.PNG)

#### string 클래스의 생성자 중복 사례

![stringconstructor](https://github.com/BangYunseo/TIL/blob/main/Cpp/Image/ch9/stringconstructor.PNG)

#### 소멸자 함수 중복
* 소멸자 함수는 중복해서 사용 불가능
  * 소멸자는 매개 변수를 가지지 않음
  * 한 클래스 내에서 소멸자는 오직 하나만 존재

## 3절. 디폴트 매개 변수
#### 디폴트 매개 변수(default parameter)
* 매개 변수에 값이 넘어오지 않을 때 default 값을 받도록 선언된 매개 변수
  * "매개 변수 == default값"의 형태로 선언
* 디폴트 매개 변수 선언 사례

```C++
void star(int a = 5);
// a의 default 값을 5로 선언
```
* default 매개 변수를 가진 함수 호출

```C++
star();
// 매개 변수 a에 default 값 5 전달
// 즉, star(5); == star();

star(10);
// 매개 변수 a에 10 전달
```

#### 디폴트 매개 변수 사례

```C++
void msg(int id, string text = "Hello");
// text의 default 값은 "Hello"
```

```C++
msg(10);
// msg(10, "Hello"); 호출과 동일
// id에 10, text에 "Hello" 전달

msg(20, "Good Morning!");
// id에 20, text에 "Good Morning!" 전달

msg();
// 컴파일 오류 발생
// why? 첫 번째 매개 변수 id에 값이 전달되지 않음

msg("Hello");
// 컴파일 오류 발생
// why? 첫 번째 매개 변수 id에 값이 전달되지 않음
```

#### 디폴트 매개 변수에 관한 제약 조건
* 디폴트 매개 변수는 보통 매개 변수 앞에 선언될 수 없음
  * 디폴트 매개 변수는 끝 쪽에 몰려 선언되어야 함

```C++
void calc(int a, int b = 5, int c, int d = 0);
// 컴파일 오류 발생
// why? 디폴트 매개 변수가 끝쪽에 선언되지 않음

void sum(int a = 0, int b, int c);
// 컴파일 오류 발생
// why? 디폴트 매개 변수가 끝쪽에 선언되지 않음

void calc(int a, int b = 5, int c = 0, int d = 0);
// 컴파일 오류가 발생하지 않음
```

#### 매개 변수에 값을 정하는 규칙

![parameterrule](https://github.com/BangYunseo/TIL/blob/main/Cpp/Image/ch9/parameterrule.PNG)

#### 매개 변수에 값을 정하는 규칙 - 2

![parameterrule2](https://github.com/BangYunseo/TIL/blob/main/Cpp/Image/ch9/parameterrule2.PNG)

* 예제 3. 디폴트 매개 변수를 가진 함수 선언 및 호출 연습  
[SourceCodeChecking](https://github.com/BangYunseo/Basic_CPP/blob/main/ch9_FunctionOverloading/DefaultParameterEx1.cpp)

* 예제 4. 디폴트 매개 변수를 가진 함수 생성 연습   
[SourceCodeChecking](https://github.com/BangYunseo/Basic_CPP/blob/main/ch9_FunctionOverloading/DefaultParameterEx2.cpp)


## 4절. 함수 중복 특성
#### 함수 중복 간소화
* 디폴트 매개 변수의 장점
  * 함수 중복 간소화

![smalloverloading](https://github.com/BangYunseo/TIL/blob/main/Cpp/Image/ch9/smalloverloading.PNG)

* 중복 함수들과 다르게 디폴트 매개 변수를 가진 함수를 함께 사용 불가

![sameoverloading](https://github.com/BangYunseo/TIL/blob/main/Cpp/Image/ch9/sameoverloading.PNG)

* 예제 5. 디폴트 매개 변수를 이용한 중복 함수 간소화 연습  
[SourceCodeChecking](https://github.com/BangYunseo/Basic_CPP/blob/main/ch9_FunctionOverloading/DefaultParameterEx3.cpp)

* 예제 6. 생성자 함수 중복 간소화 연습  
[SourceCodeChecking](https://github.com/BangYunseo/Basic_CPP/blob/main/ch9_FunctionOverloading/ConstructorOverloading.cpp)

#### 함수 중복의 모호성
* 함수 중복이 모호하여 컴파일러가 어떤 함수를 호출하는지 판단하지 못하는 경우
  * 형 변환으로 인한 모호성
  * 참조 매개 변수로 인한 모호성
  * 디폴트 매개 변수로 인한 모호성

#### 형 변환으로 인한 모호성
* 매개 변수의 형 변환으로 인한 중복 함수 호출의 모호성

![typetrans](https://github.com/BangYunseo/TIL/blob/main/Cpp/Image/ch9/typetrans.PNG)

* 예제 7. 형 변환으로 인해 함수 중복이 모호한 경우 연습  
[SourceCodeChecking](https://github.com/BangYunseo/Basic_CPP/blob/main/ch9_FunctionOverloading/TypeConversion.cpp)

#### 참조 매개 변수로 인한 모호성

* 예제 8. 참조 매개 변수로 인해 함수 중복이 모호한 경우 연습  
[SourceCodeChecking](https://github.com/BangYunseo/Basic_CPP/blob/main/ch9_FunctionOverloading/ReferenceParameter.cpp)

#### 디폴트 매개 변수로 인한 모호성

* 예제 9. 디폴트 매개 변수로 인해 함수 중복이 모호한 경우 연습  
[SourceCodeChecking](https://github.com/BangYunseo/Basic_CPP/blob/main/ch9_FunctionOverloading/DefaultParameterEx4.cpp)
