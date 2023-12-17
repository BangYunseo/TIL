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
* cout 객체
  * 스크린 출력 장치에 연결된 표준 C++ 출력 스트림 객체
  * <iostream> 헤더 파일에 선언
  * std 이름 공간에 선언 : std::cout 으로 사용
* << 연산자
  * 스트림 삽입 연산자(stream insertion operator)
    * C++ 기본 산술 시프트 연산자(<<)가 스트림 삽입 연산자로 재정의
    * ostream 클래스에 구현
    * 오른쪽 피연산자를 왼쪽 스트림 객체에 삽입
    * cout 객체에 연결된 화면에 출력
  * 여러 개의 << 연산자로 여러 값 출력


#### << 연산자 활용
* 문자열 및 기본 타입의 데이터 출력
  * bool, char, short, int, long, float, double 타입 값 출력
```C++
 int n = 3;
 char c = '#';
 std::cout << c << 5.5 << '-' << n << "hello" << true;
// 출력 예시
// #5.5-3hello1
```

[데이터타입참고용 표넣기](https://offbyone.tistory.com/115)
  * 함수 호출 가능
```C++
 std::cout << "n + 5 = " << n + 5;
 std::cout << f();
```
