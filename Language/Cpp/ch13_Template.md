# Chapter 13. 템플릿

> '명품 C++Programming - 황기태' 10장 학습 내용
>
> [소스코드](https://github.com/BangYunseo/Basic_CPP/tree/main/ch13_Template)
>
> 1절. 템플릿
>
> 2절. 구체화
>
> 3절. 제네릭 프로그래밍

## 1절. 템플릿

#### 함수 중복의 약점 : 중복 함수의 코드 중복

```CPP
#include <iostream>

using namespace std;

void myswap(int& a, int& b){
 int tmp;
 tmp = a;
 a = b;
 b = tmp;
}

void myswap(double& a, double& b){
 double tmp;
 tmp = a;
 a = b;
 b = tmp;
}

// 위의 두 함수는 매개 변수만 다르고 나머지 코드가 동일
// 즉, 동일한 코드를 중복 작성하는 약점 발생

int main(){
 int a = 4, b = 5;
 myswap(a, b);
 // myswap(int& a, int& b) 호출

 cout << a << '\t' << b << endl;

 double c = 0.3, d = 12.5
 myswap(a, b);
 // myswap(double& a, double& b) 호출

 cout << a << '\t' << b << endl;
}

// 출력 예시
// 5          4
// 12.5       0.3
```

#### 일반화와 템플릿

- 제네릭(generic) 또는 일반화
  - 함수나 클래스를 일반화시키고 매개 변수 타입을 지정하여 틀에서 찍어 내듯이 함수나 클래스 코드를 생산하는 기법
- 템플릿
  - 함수나 클래스를 일반화하는 C++ 도구
  - template 키워드로 함수나 클래스 선언
    - 변수나 매개 변수의 타입만 다르고 코드 부분이 동일한 함수를 일반화
  - 제네릭 타입 : 일반화를 위한 타입
- 템플릿 선언

```CPP
template <class T>
template <typename T>

// 3개의 제네릭 타입을 가진 템플릿 선언
template <class T1, class T2, class T3>
```

![myswap](https://github.com/BangYunseo/TIL/blob/main/Language/Cpp/Image/ch13/myswap.PNG)

#### 중복 함수들로부터 템플릿 만들기 사례

![myswap2](https://github.com/BangYunseo/TIL/blob/main/Language/Cpp/Image/ch13/myswap2.PNG)

## 2절. 구체화

#### 템플릿으로부터의 구체화

- 구체화(specialization)
  - 템플릿의 제네릭 타입에 구체적인 타입 지정
    - 템플릿 함수로부터 구체화된 함수의 소스 코드 생성

![intT](https://github.com/BangYunseo/TIL/blob/main/Language/Cpp/Image/ch13/intT.PNG)

#### 제네릭 함수로부터 구체화된 함수 생성 사례

![special](https://github.com/BangYunseo/TIL/blob/main/Language/Cpp/Image/ch13/special.PNG)

- 예제 1. 제네릭 myswap() 함수 생성 예제  
  [SourceCodeChecking](https://github.com/BangYunseo/Basic_CPP/blob/main/ch13_Template/GenericMyswap.cpp)

#### 구체화 오류

- 제네릭 타입에 구체적인 타입 지정 시 주의

![errorspecial](https://github.com/BangYunseo/TIL/blob/main/Language/Cpp/Image/ch13/errorspecial.PNG)

#### 템플릿의 장단점

- 장점
  - 함수 코드의 재사용
    - 높은 소프트웨어의 생산성과 유용성
- 단점
  - 포팅에 취약
    - 컴파일러에 따라 지원하지 않을 가능성 존재
  - 컴파일 오류 메시지 빈약
  - 디버깅에 많은 어려움

## 3절. 제네릭 프로그래밍

#### 제네릭 프로그래밍

- Generic Programming
  - 일반화 프로그래밍
  - 제네릭 함수나 제네릭 클래스를 활용하는 프로그래밍 기법
  - C++에서 STL(Standard Template Library) 제공 및 활용
- 보편화 추세

  - Java, C# 등 많은 언어에서 활용

- 예제 2. 큰 값 리턴하는 bigger() 함수 예제  
  [SourceCodeChecking](https://github.com/BangYunseo/Basic_CPP/blob/main/ch13_Template/BiggerFunction.cpp)

- 예제 3. 배열의 함을 리턴하는 add() 함수 예제  
  [SourceCodeChecking](https://github.com/BangYunseo/Basic_CPP/blob/main/ch13_Template/AddFunction.cpp)

- 예제 4. 배열을 복사하는 mcopy() 함수 예제  
  [SourceCodeChecking](https://github.com/BangYunseo/Basic_CPP/blob/main/ch13_Template/MCopyFunction.cpp)

#### 배열을 출력하는 print() 템플릿 함수의 문제점

![charspec](https://github.com/BangYunseo/TIL/blob/main/Language/Cpp/Image/ch13/charspec.PNG)

- 예제 5. 템플릿 함수보다 중복 함수가 우선인 예제  
  [SourceCodeChecking](https://github.com/BangYunseo/Basic_CPP/blob/main/ch13_Template/PrintFunction.cpp)

#### 제네릭 클래스 만들기

- 제네릭 클래스 선언

```CPP
template <class T>
class MyStack {
  int tos;
  T data [100]; // T 타입의 배열
public:
  MyStack();
  void push(T element);
  T pop();
};
```

- 제네릭 클래스 구현

```CPP
template <class T>
void MyStack<T>::push(T element){
  ...
}

template <class T>
T MyStack<T>::pop(){
  ...
}
```

- 클래스 구체화 및 활용

```CPP
MyStack<int> iStack;        // int 타입을 다루는 스택 객체 생성
MyStack<double> dStack;     // double 타입을 다루는 스택 객체 생성

iStack.push(3);
int n = iStack.pop();

dStack.push(3.5);
double d = dStack.pop();
```

- 예제 6. 제네릭 스택 클래스 만들기 예제  
  [SourceCodeChecking](https://github.com/BangYunseo/Basic_CPP/blob/main/ch13_Template/GenericStackClass.cpp)

- 예제 7. 제네릭 포인터 클래스 예제  
  [SourceCodeChecking](https://github.com/BangYunseo/Basic_CPP/blob/main/ch13_Template/GenericPointerClass.cpp)

#### cout << a << b << c; 의 실행 순서

![coutabc1](https://github.com/BangYunseo/TIL/blob/main/Language/Cpp/Image/ch13/coutabc1.PNG)

- 예제 7의 라인 39 ~ 40을 다음과 같이 연결하면 잘못된 결과가 나오며 이유는 아래와 같음
  ![coutabc2](https://github.com/BangYunseo/TIL/blob/main/Cpp/Image/ch13/coutabc2.PNG)

- 예제 8. 두 개의 제네릭 타입 클래스 예제  
  [SourceCodeChecking](https://github.com/BangYunseo/Basic_CPP/blob/main/ch13_Template/GenericClass2.cpp)
