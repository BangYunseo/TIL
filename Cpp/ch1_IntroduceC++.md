#  Chapter 1. C++소개   
> '명품 C++Programming - 황기태' 1장 학습 내용
>
> [소스코드]는 존재하지 않습니다.
> 
> 1절. C++
> 
> 2절. 객체
>
> 3절. 추가 설명

## 1절. C++
#### C++ 언어의 주요 설계 목적
* C 언어와의 호환성
  * C 언어의 문법 체계 계승
    * 소스 레벨 호환성 : 기존에 작성된 C 프로그램을 그대로 사용 가능
    * 링크 레벨 호환성 : C 목적 파일과 라이브러리를 C++ 프로그램에서 링크 가능
* 객체 지향 개념 도입
  * 캡슐화, 상속, 다형성
  * 소프트웨어의 재사용을 통해 생산성 향상
  * 복잡하고 큰 규모의 소프트웨어 작성, 관리, 유지보수에 용이
* 엄격한 타입 체크
  * 실행 시간 오류의 가능성을 줄임
  * 디버깅 편리
* 실행 시간 효율성 저하 최소화
  * 실행 시간을 저하시키는 요소와 해결
    * 작은 크기의 멤버 함수 잦은 호출 가능성 -> 인라인 함수로 실행 시간 저하 해소

#### C++ 언어에 추가된 기능
* 함수 중복(Function Overloading)
  * 매개 변수의 개수나 타입이 다른 동일한 이름의 함수들 선언
* 디폴트 매개 변수(Default Parameter)
  * 매개 변수에 디폴트 값이 전달되도록 함수 선언
* 참조와 참조 변수(Reference)
  * 하나의 변수에 별명을 사용하는 참조 변수 도입
* 참조에 의한 호출(Call-By-Reference)
  * 함수 호출 시 참조 전달
* New / Delete 연산자
  * 동적 메모리 할당/해제를 위해 new와 delete 연산자 도입
* 연산자 재정의
  * 기존 C++ 연산자에 새로운 연산 정의
* 제네릭 함수와 클래스
  * 데이터 타입에 의존하지 않고 일반화시킨 함수나 클래스 작성 가능

## 2절. 객체
#### 객체(Object)
* 데이터의 분산을 막기 위해 데이터와 기능을 하나로 묶은 그룹
 
#### 객체 지향 언어(Object-oriented Language)  
* 컴퓨터 프로그래밍의 한 가지 기법으로 객체를 만들고 객체를 사용하는 프로그래밍 언어
* 프로그램을 데이터와 처리 방법으로 나누는 것이 아님
* 프로그램을 다수의 "객체"로 만들고, 이들을 상호작용해서 만들어지는 방식
      
#### 객체 지향 특성 1 - 캡슐화
* 데이터를 캡슐로 싸서 외부의 접근으로부터 보호     
* C++에서 클래스(class 키워드)로 캡슐을 표현      

![class](https://github.com/BangYunseo/TIL/blob/main/Cpp/Image/ch1/class.PNG)

#### 클래스와 객체     
* 클래스 : 객체를 만드는 틀     
* 객체 : 클래스라는 틀에서 생겨난 실체      
* 객체(object), 실체(instance)는 같은 뜻     
      
![instance](https://github.com/BangYunseo/TIL/blob/main/Cpp/Image/ch1/instance.PNG)

```C++
// 원을 추상화한 클래스 Circle
class Circle{
private :
      int radius;      // 반지름 값
public :
      Circle(int r){ radius = r; }
      double getArea(){ return 3.14 * radius * radius }
};    
```

#### 객체 지향 특성 2 - 상속성(Inheritance)     
* 자식이 부모의 유전자를 물려 받는 것과 유사

#### C++ 상속  
* 객체가 자식 클래스의 멤버와 부모 클래스에 선언된 모양 그대로 멤버들을 가지고 탄생
      
![Inheritance](https://github.com/BangYunseo/TIL/blob/main/Cpp/Image/ch1/Inheritance.PNG)
      
 
#### 객체 지향 특성 3 - 다형성(Polymorphism)
* 하나의 기능이 경우에 따라 다르게 보이거나 다르게 작동하는 현상
* 연산자 중복, 함수 중복, 함수 재정의(overriding)

![Polymorphism](https://github.com/BangYunseo/TIL/blob/main/Cpp/Image/ch1/Polymorphism.PNG)

#### C++ 언어에서 객체 지향을 도입한 목적
* 소프트웨어 생산성 향상
  * 소프트웨어의 생명 주기 단축 문제 해결 필요
  * 기 작성된 코드의 재사용 필요
  * C++ 클래스 상속 및 객체 재사용으로 해결
* 실세계에 대한 쉬운 모델링
  * 과거의 소프트웨어
    * 수학 연산이나 통계 처리에 편리한 절차 지향 언어 적함
  * 현대의 소프트웨어
    * 물체 혹은 객체의 상호 작용에 대한 묘사 필요
    * 실세계는 객체로 구성된 세계
    * 객체를 중심으로 하는 객체 지향 언어 적합

#### 절차 지향 프로그래밍과 객체 지향 프로그래밍
![Programming2](https://github.com/BangYunseo/TIL/blob/main/Cpp/Image/ch1/Programming2.PNG)


## 3절. 추가 설명
#### 제네릭 프로그래밍
* 제네릭 함수와 제네릭 클래스
  * 제네릭 함수(Generic Function)
    * 동일한 프로그램 코드에 다양한 데이터 타입을 적용할 수 있게 일반화시킨 함수
  * 제네릭 클래스(Generic Class)
    * 동일화 프로그램 크도에 다양한 데이터 타입을 적용할 수 있게 일반화시킨 클래스
  * template 키워드로 선언
    * 템플릿 함수 혹은 템플릿 클래스라고 불림
  * Java, C# 등 다른 언어에도 동일한 개념 존재
* 제네릭 프로그래밍(Generic Programming)
  * 제네릭 함수와 제네릭 클래스를 활용하여 프로그램을 작성하는 새로운 프로그램 패러다임

#### 링킹
* 목적 파일끼리 합쳐 실행 파일을 만드는 과정
  * 목적 파일은 바로 실행할 수 없음
* 목적 파일과 C++ 표준 라이브러리의 함수 연결
* 실행 파일을 만드는 과정

![Linking](https://github.com/BangYunseo/TIL/blob/main/Cpp/Image/ch1/Linking.PNG)

#### C++ 표준 라이브러리
* C++ 표준 라이브러리는 3개의 그룹으로 구분
  * C 라이브러리
    * 기존 C 표준 라이브러리를 수용
    * C++에서 사용할 수 있게 한 함수들
    * 이름이 c로 시작하는 헤더파일에 선언됨
  * C++ 입출력 라이브러리
    * 콘솔 및 파일 입출력을 위한 라이브러리
  * C++ STL 라이브러리
    * 제네릭 프로그래밍을 지원하기 위한 템플릿 라이브러리

![Library](https://github.com/BangYunseo/TIL/blob/main/Cpp/Image/ch1/Library.PNG)
