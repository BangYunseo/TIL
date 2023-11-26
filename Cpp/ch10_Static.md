#  Chapter 10. Static      
> '명품 C++Programming - 황기태' 6장 학습 내용
>
> [소스코드](https://github.com/BangYunseo/Basic_CPP/tree/main/ch10_)
> 
> 1절. Static과 Non-Static
> 
> 2절. Static
>
> 3절. 디폴트 매개 변수
>
> 4절. 함수 중복 특성
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

예제 1. Static 멤버 사용 예제

