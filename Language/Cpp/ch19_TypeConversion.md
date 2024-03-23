#  Chapter 19. 형변환  
> [참고자료](https://wikidocs.net/143100)
>
> [소스코드]는 존재하지 않습니다.
> 
> 1절. 형변환
>
> 2절. static_cast
>
> 3절. const_cast
>
> 4절. reinterpret_cast
>
> 5절. dynamic_cast

## 1절. 형변환
#### 형변환이란?
* 형변환(type conversion)
* 캐스팅(casting)이라고도 함
* 명시적(explicit) 또는 묵시적(implicit)으로 자료의 형식을 변환하는 것

#### 형변환 구문
* ( new_type ) expression     
* new_type ( expression )     
* new_type ( arg1, arg2, ... )
* new_type ( )
* new_type { arg1, arg2, ...(optional) } // (since C++11)
* template-name ( arg1, arg2, ...(optional) ) // (since C++17)

#### C의 형변환
```C
double d = 3.141592;
int n = (int)d;
// double형인 변수 d를 강제로 int형으로 변환
```

#### 형변환 종류
```cpp
static_cast<new_type>(value);
// 형변환 방법을 컴파일러가 아는 경우

const_cast<new_type>(value);
// 일시적으로 const 지정 또는 해제

reinterpret_cast<new_type>(value);
// 자료를 재해석하여 형변환하는 것으로 주로 포인터형에 사용

dynamic_cast<new_type>(value);
// 상속 관계 중 다형성을 사용할 수 있는 경우 up, down 형변환
```

* 형변환의 반환형은 new_type
* 대상에 따라 변환 할 수 없는 것 존재
  * 사용자 정의 자료형에 형변환 연산자(user-defined type conversion function)를 정의하지 않으면
    * 형변환 방법에 따라 다른 자료형으로 형변환 할 때 문제 발생

#### 스마트 포인터 std::shared_ptr<T>로 형변환 
```cpp
std::static_pointer_cast<new_type>(ptr);
std::dynamic_pointer_cast<new_type>(ptr);
std::const_pointer_cast<new_type>(ptr);
std::reinterpret_pointer_cast<new_type>(ptr);
```

#### std::shared_ptr<T>의 T로 형변환
* 멤버 함수인 get()을 이용하여 일반적인 형변환 형식 사용

```cpp
static_cast<new_type*>(ptr.get());
reinterpret_cast<new_type*>(ptr.get());
dynamic_cast<new_type*>(ptr.get());
```

## 2절. static_cast
#### static_cast란?
* 대부분의 객체 형변환에 사용
* 컴파일러가 형변환 방법을 아는 경우 사용
* 기본 자료형은 명시적, 묵시적으로 형변환 가능
* 사용자 정의 자료형은 사용자 정의 형변환 연산자(user-defined type conversion function)를 정의

#### 기본자료형 형변환
```cpp
#include <iostream>
using namespace std;
int main()
{
    double dValue = 3.141592;
    int nValue = 0;
    nValue = static_cast<int>(dValue);

    printf("%lf\n", dValue);
    printf("%d\n", nValue);

    size_t unValue = 0x0102030405060708;
    short sValue = 0;
    sValue = static_cast<short>(unValue);

    printf("%016lx\n", unValue);
    printf("%x\n", sValue);
    return EXIT_SUCCESS;
}

// 출력 예시
// 3.141592
// 3
// 0102030405060708
// 708
```

* double형 자료를 int로 변환하면 정수부 값만 int형으로 변환
* 
#### C++에서 C 언어 함수 호출 시 링크 오류 발생 

![C++C](https://github.com/BangYunseo/TIL/blob/main/Language/Cpp/Image/ch18/C++C.PNG)

#### Visual C++ 에서의 링크 오류 메시지

![errorC++](https://github.com/BangYunseo/TIL/blob/main/Language/Cpp/Image/ch18/errorC++.PNG)

## 2절. extern "c"
#### extern "c"
* extern "c"
  * C 컴파일러로 컴파일할 것을 지시
    * C 이름 규칙으로 목적 코드를 생성할 것을 지시
* 사용법
  * 함수 하나만 선언
```CPP
extern "C" int f(int x, int y);
```
  * 여러 함수들 선언
```CPP
extern "C"{
 int f(int x, int y);
 void g();
 char s(int []);
}
```
  * 헤더 파일 통째로 선언  
```CPP
extern "C"{
 #include "myfunction.h"
}
```

#### extern "C"를 이용한 링크 성공

![linkingC](https://github.com/BangYunseo/TIL/blob/main/Language/Cpp/Image/ch18/linkingC.PNG)
