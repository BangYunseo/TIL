#  Chapter 2. C++ 기초   
> '명품 C++Programming - 황기태' 2장 학습 내용
>
> [소스코드]()
> 
> 1절. C++의 기본 요소
> 
> 2절. 
>
> 3절. 추가 설명

## 1절. C++의 기본 요소
#### 주석문과 main 함수
* 주석문
  * 개발자가 자유롭게 붙인 특이 사항의 메모
  * 프로그램에 대한 설명
  * C언어의 주석문과 동일
    * 여러 줄 주석문과 한 줄 주석문
```C++
/* 이 것은 주석문입니다.
여러 줄 주석문 입니다. */

// 이 것은 주석문입니다.
// 한 줄 주석문 입니다.
```
* main() 함수
  * C++ 프로그램의 실행을 시작하는 함수
    * main() 함수가 종료하면 C++ 프로그램 종료
  * main() 함수의 C++ 표준 모양
```C++
int main(){

  // return 0;
}
```

#### #include
* #include <iostream>
  * 전처리기(C++ Preprocessor)에게 내리는 지시
    * <iostream> 헤더 파일을 컴파일 전에 소스에 확장하도록 지시
  * <iostream> 헤더 파일
    * 표준 입출력을 위한 클래스와 객체, 변수 등을 선언
      * ios, istream, ostream, iostream 클래스 선언
      * cout, cin, <<, >> 등 연산자 선언
```C++
#include <iostream>
int main(){
  std::cout << "Hello!" << endl;
}
```

#### 화면 출력
* cout과 << 연산자 이용
```C++
#include <iostream>
int main(){
  std::cout << "Hello!" << endl;
}
```
