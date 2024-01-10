#  Chapter 10. 연산자 중복      
> '명품 C++Programming - 황기태' 7장 학습 내용
>
> [소스코드](https://github.com/BangYunseo/Basic_CPP/tree/main/ch10_OperatorOverloadingFunction)
> 
> 1절. 연산자 중복
> 
> 2절. 이항 연산자 중복
>
> 3절. 단항 연산자 중복

## 1절. 연산자 중복
#### C++의 연산자 중복
* C++ 언어에서 연산자 중복 가능
  * C++ 언어에 본래부터 있던 연산자에 새로운 의미 정의
  * 높은 프로그램 가독성
  * 간결한 의미 전달
  * 다형성

#### 연산자 중복의 사례
* 정수 덧셈
```CPP
int a = 2, b = 3, c;
c = a + b;

// 결과 5
// 정수가 피연산자일 때 2와 3의 덧셈
```
* 문자열 혼합
```CPP
string a = "C", c;
c = a + "++";

// 결과 C++
// 문자열이 피연산자일 때 두 개의 문자열 혼합
```
* 색깔 혼합
```CPP
Color a(BLUE), b(RED), c;
c = a + b;

// c = VIOLET
// a, b의 두 색을 섞은 새로운 Color 객체 c
```
* 배열 결합
```CPP
SortedArray a(2, 5, 9), b(3, 7, 10), c;
c = a + b;

// c = {2, 3, 5, 7, 9, 10}
// 정렬된 두 배열을 결합(merge)한 새로운 배열 생성
```

#### 연산자 중복의 특징
* C++에 본래 있는 연산자만 중복 가능
  * 컴파일 오류 발생 예시
    * 3 %% 5
    * 6 ## 7
* 피연산자 타입이 다른 새로운 연산 정의
* 연산자는 함수 형태로 구현 : 연산자 함수(operator funcion)
* 반드시 클래스와 관계를 가짐
* 피연산자의 개수를 바꿀 수 없음
* 연산의 우선 순위 변경 안됨
* 모든 연산자가 중복 가능하지 않음

* 중복 가능한 연산자          

![OverloadingOperator](https://github.com/BangYunseo/TIL/blob/main/Cpp/Image/ch10/OverloadingOperator.PNG)


* 중복 불가능한 연산자

![NotOverloadingOperator](https://github.com/BangYunseo/TIL/blob/main/Cpp/Image/ch10/NotOverloadingOperator.PNG)

#### 연산자 함수
* 연산자 함수 구현 방법 2가지
  * 클래스의 멤버 함수로 구현
  * 외부 함수로 구현하고 클래스에 프렌드 함수로 선언
* 연산자 함수 형식
```CPP
ReturnType(double, int, ...) Operator(ParameterList);
```


#### +와 == 연산자의 작성 사례
* 연산자 함수 작성이 필요한 코드
```CPP
Color a(BLUE), b(RED), c;

c = a + b;
// a와 b를 더하기 위한 + 연산자 작성 필요

if(a == b){
...
// a와 b를 비교하기 위한 == 연산자 작성 필요
```

* 외부 함수로 구현되고 클래스에 프렌드로 선언되는 경우
```CPP
Color operator+(Color op1, Color op2);
bool operator==(Color op1, Color op2);
// 외부 함수

class Color{
 ...
 friend Color operator+(Color op1, Color op2);
 friend bool operator==(Color op1, Color op2);
};
```

* 클래스의 멤버 함수로 작성되는 경우
```CPP
class Color{
 ...
 Color operator+(Color op2);
 bool operator==(Color op2);
};
```

#### 2절과 3절에 예시로 사용될 클래스
```CPP
class Power{
 int kick;
 int punch;
public:
 Power(int kick = 0, int punch = 0){
  this->kick = kick;
  this->punch = punch;
 }
};
```

## 2절. 이항 연산자 중복
#### + 연산자 (여기부터 작성)


#### static 멤버 사용 : 클래스명과 범위 지정 연산자 (::)로 접근
* 클래스 이름과 범위 지정 연산자 (::)로 접근 가능
  * static 멤버는 클래스마다 오직 한 개만 생성되기 때문
```C++
classname::staticmember
```
![staticmember2](https://github.com/BangYunseo/TIL/blob/main/Cpp/Image/ch08/staticmember2.PNG)

 * non-static 멤버는 클래스 이름을 접근 불가
```C++
Person::money = 100;        // 컴파일 오류 : non-static 멤버는 클래스 명으로 접근 불가
Person::addMoney(200);      // 컴파일 오류 : non-static 멤버는 클래스 명으로 접근 불가
```
* 그림으로 먼저 보기
![staticmember3](https://github.com/BangYunseo/TIL/blob/main/Cpp/Image/ch08/staticmember3.PNG)

* 예제 2. Static 멤버 클래스 접근 예제     
[SourceCodeChecking](https://github.com/BangYunseo/Basic_CPP/blob/main/ch08_Static/AcessingStaticMember.cpp)

#### static 활용
* static의 주요 활용
  * 전역 변수나 전역 함수를 클래스에 캡슐화
    * 전역 변수나 전역 함수를 가능한 사용하지 않도록
    * 전역 변수나 전역 함수를 static으로 선언하여 클래스 멤버로 선언
  * 객체 사이에 공유 변수를 만들고자 할 때
    * static 멤버를 선언하여 모든 객체들이 공유

#### 특정한 목적을 가진 static 멤버
* 그림으로 먼저 보기
![Mathclass](https://github.com/BangYunseo/TIL/blob/main/Cpp/Image/ch08/Mathclass.PNG)

* 예제 3. static 멤버를 가진 Math 클래스 예제     
[SourceCodeChecking](https://github.com/BangYunseo/Basic_CPP/blob/main/ch08_Static/MathClass.cpp)

* 그림으로 먼저 보기
![Circleclass](https://github.com/BangYunseo/TIL/blob/main/Cpp/Image/ch08/Circleclass.PNG)

* 예제 4. 공유의 목적으로 static 멤버를 사용하는 예제     
[SourceCodeChecking](https://github.com/BangYunseo/Basic_CPP/blob/main/ch08_Static/CircleClass.cpp)

#### static 멤버 함수는 static 멤버만 접근 가능
* static 멤버 함수가 접근할 수 있는 것
  * static 멤버 함수
  * static 멤버 변수
  * 함수 내의 지역 변수
* static 멤버 함수는 non-static 멤버에 접근 불가
  * 객체가 생성되지 않은 시점에서 static 멤버 함수가 호출될 수 있기 때문 

#### static 멤버 함수의 오류
* static 멤버 함수 getMoney()가 non-static 멤버 변수 money를 접근하는 오류
![getArea](https://github.com/BangYunseo/TIL/blob/main/Cpp/Image/ch08/getArea.PNG)

#### non-static 멤버 함수는 static에 접근 가능
```C++
class Person{
public:
 double money;             // 개인 돈
 static int sharedMoney;   // 공유 돈

// ...

 int total() { return money + sharedMoney; }
// non-static 함수는 non-static이나 static 멤버에 모두 접근 가능
};
```
#### static 멤버 함수의 this
* static 멤버 함수는 객체가 생기기 전부터 호출 가능
  * static 멤버 함수에서 this 사용 불가
```C++
class Person{
public:
 double money;             // 개인 돈
 static int sharedMoney;   // 공유 돈

// ...

 static void addShared(int n) { this->sharedMoney += n; }
 // static 함수에서는 this 사용 불가
 // this를 사용하므로 컴파일 오류 발생
 // sharedMoney += n; 으로 설정하면 정상 컴파일
};
``` 


