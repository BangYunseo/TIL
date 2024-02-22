#  Chapter 18. C 언어와의 링크 지정  
> '명품 C++Programming - 황기태' 13장 학습 내용
>
> [소스코드]는 존재하지 않습니다.
> 
> 1절. C 코드와의 링킹
>
> 2절. extern "c"


## 1절. C 코드와의 링킹
#### C++ 에서의 C 코드와 링킹
* 이름 규칙
  * 컴파일 후 목적 코드에 이름을 붙이는 규칙
    * 변수, 함수, 클래스 등의 이름
* C 언어의 이름 규칙
  * 이름 앞에 밑줄표시문자(_)를 붙임
    * int f(int x, int y)       -> _f
    * int main()                -> _main 
* C++의 이름 규칙
  * 함수의 매개 변수 타입과 개수, 리턴 타입에 따라 복잡한 이름
    * int f(int x, int y)        -> ?f@@YAHHH@Z
    * int f(int x)               -> ?f@@YAXH@Z
    * int f()                    -> ?f@@YAHXZ
    * int main()                 -> _main

#### C 언어 프로그램의 컴파일과 링킹

![linking](https://github.com/BangYunseo/TIL/blob/main/Language/Cpp/Image/ch18/linking.PNG)

#### C++ 소스의 컴파일과 링킹

![linking2](https://github.com/BangYunseo/TIL/blob/main/Language/Cpp/Image/ch18/linking2.PNG)

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
