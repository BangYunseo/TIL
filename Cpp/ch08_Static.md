#  Chapter 8. Static      
> '명품 C++Programming - 황기태' 6장 학습 내용
>
> [소스코드](https://github.com/BangYunseo/Basic_CPP/tree/main/ch10_Static)
> 
> 1절. Static과 Non-Static
> 
> 2절. Static
>

## 1절. Static과 Non-Static
#### static 멤버와 non-static 멤버

![Staticor](https://github.com/BangYunseo/TIL/blob/main/Cpp/Image/ch10/Staticor.PNG)

#### static 멤버와 non-static 멤버의 특성
* static
  * 변수와 함수에 대한 기억 부류의 한 종류
    * 생명 주기 - 프로그램이 시작될 때 생성, 프로그램 종료 시 소멸
    * 사용 범위 - 선언된 범위, 접근 지정에 따름
* 클래스의 멤버
  * static 멤버
    * 프로그램이 시작할 때 생성
    * 클래스 당 하나만 생성, 클래스 멤버라고 불림
    * 클래스의 모든 객체들이 공유하는 멤버
  * non-static 멤버
    * 객체가 생성될 때 함께 생성
    * 객체마다 객체 내에 생성
    * 인스턴스 멤버라고 불림


#### Static 멤버와 Non-static 멤버의 관계

![Staticor2](https://github.com/BangYunseo/TIL/blob/main/Cpp/Image/ch10/Staticor2.PNG)

* han, lee, park, choi 등 4개의 Person 객체 생성
* sharedMoney와 addShared() 함수는 하나만 생성되고 4개의 객체들에 의해 공유
* sharedMoney와 addShared() 함수는 han, lee, park, shoi 객체들의 멤버

#### Static 멤버와 Non-Static 멤버 비교

![Staticor3](https://github.com/BangYunseo/TIL/blob/main/Cpp/Image/ch10/Staticor3.PNG)

## 2절. Static
#### static 멤버 선언
* 멤버의 static 선언
```C++
class Person{
public:
  double money;                    // 개인 소유의 돈
  void addMoney(int money){
    this->money += money;
  }

  // 위는 non-static 멤버 선언에 대한 코드

  static int sharedMoney;          // static 멤버 변수 선언
  static void addShared(int n){    // static 멤버 함수 선언
    sharedMoney += n;
  }
};

int Person::sharedMoney = 10;      // sharedMoney를 10으로 초기화
// static 변수 공간 할당
// 프로그램 전역 공간에 선언
```
* static 멤버 변수 생성
  * 전역 변수로 생성
  * 전체 프로그램 내에 한 번만 생성

* static 멤버 변수에 대한 외부 선언이 없다면 아래와 같은 오류가 발생

![staticerror](https://github.com/BangYunseo/TIL/blob/main/Cpp/Image/ch10/staticerror.PNG)

#### static 멤버 사용 : 객체의 멤버로 접근
* static 멤버는 객체 이름이나 객체 포인터로 접근
  * 보통 멤버처럼 접근 가능
```C++
obj.staticMember
objpointer->staticMember
```
  * Person 타입의 객체 lee와 포인터 p를 이용하여 static 멤버를 접근하는 예시
```C++
Person lee;
lee.sharedMoney = 500;      // obj.staticMember 방식

Person *p;
p = &lee;
p->addShared(200);          // objpointer->staticMember 방식
```
* 그림으로 먼저 보기
![staticmember](https://github.com/BangYunseo/TIL/blob/main/Cpp/Image/ch10/staticmember.PNG)

* 예제 1. Static 멤버 사용 예제     
[SourceCodeChecking](https://github.com/BangYunseo/Basic_CPP/blob/main/ch10_Static/UsingStaticMember.cpp)

* han와 lee의 money는 각각 100, 350으로 값이 다르지만 han와 lee의 sharedMoney는 공통 400으로 같음

#### static 멤버 사용 : 클래스명과 범위 지정 연산자 (::)로 접근
* 클래스 이름과 범위 지정 연산자 (::)로 접근 가능
  * static 멤버는 클래스마다 오직 한 개만 생성되기 때문
```C++
classname::staticmember
```
![staticmember2](https://github.com/BangYunseo/TIL/blob/main/Cpp/Image/ch10/staticmember2.PNG)

 * non-static 멤버는 클래스 이름을 접근 불가
```C++
Person::money = 100;        // 컴파일 오류 : non-static 멤버는 클래스 명으로 접근 불가
Person::addMoney(200);      // 컴파일 오류 : non-static 멤버는 클래스 명으로 접근 불가
```
* 그림으로 먼저 보기
![staticmember3](https://github.com/BangYunseo/TIL/blob/main/Cpp/Image/ch10/staticmember3.PNG)

* 예제 2. Static 멤버 클래스 접근 예제     
[SourceCodeChecking](https://github.com/BangYunseo/Basic_CPP/blob/main/ch10_Static/AcessingStaticMember.cpp)

#### static 활용
* static의 주요 활용
  * 전역 변수나 전역 함수를 클래스에 캡슐화
    * 전역 변수나 전역 함수를 가능한 사용하지 않도록
    * 전역 변수나 전역 함수를 static으로 선언하여 클래스 멤버로 선언
  * 객체 사이에 공유 변수를 만들고자 할 때
    * static 멤버를 선언하여 모든 객체들이 공유

#### 특정한 목적을 가진 static 멤버
* 그림으로 먼저 보기
![Mathclass](https://github.com/BangYunseo/TIL/blob/main/Cpp/Image/ch10/Mathclass.PNG)

* 예제 3. static 멤버를 가진 Math 클래스 예제     
[SourceCodeChecking](https://github.com/BangYunseo/Basic_CPP/blob/main/ch10_Static/MathClass.cpp)

* 그림으로 먼저 보기
![Circleclass](https://github.com/BangYunseo/TIL/blob/main/Cpp/Image/ch10/Circleclass.PNG)

* 예제 4. 공유의 목적으로 static 멤버를 사용하는 예제     
[SourceCodeChecking](https://github.com/BangYunseo/Basic_CPP/blob/main/ch10_Static/CircleClass.cpp)

#### static 멤버 함수는 static 멤버만 접근 가능
* static 멤버 함수가 접근할 수 있는 것
  * static 멤버 함수
  * static 멤버 변수
  * 함수 내의 지역 변수
* static 멤버 함수는 non-static 멤버에 접근 불가
  * 객체가 생성되지 않은 시점에서 static 멤버 함수가 호출될 수 있기 때문 

#### static 멤버 함수의 오류
* static 멤버 함수 getMoney()가 non-static 멤버 변수 money를 접근하는 오류
![getArea](https://github.com/BangYunseo/TIL/blob/main/Cpp/Image/ch10/getArea.PNG)

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
