#  Chapter 2. C++ 기초   
> '명품 C++Programming - 황기태' 2장 학습 내용
>
> [소스코드](https://github.com/BangYunseo/Basic_CPP/tree/main/ch02_BasicC%2B%2B)
> 
> 1절. C++의 기본 요소
> 
> 2절. 입력
>
> 3절. 문자열

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
  * C++에서는 C언어에서 사용했던 printf()와 scanf()를 사용하지 않음
  * <iostream> 헤더 파일에 선언
  * C언어에서 사용했던 <stdio.h>는 사용하지 않음
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
  * 함수 호출 가능
```C++
 std::cout << "n + 5 = " << n + 5;
 std::cout << f();
```
* 다음 줄로 넘어가기
  * '\n'이나 'endl' 조작자 사용
```C++
 std::cout << "Hello" << '\n';
 std::cout << "Hello" << std::endl;
```

* 예제 1. cout과 << 연산자 활용 예제   
[SourceCodeChecking](https://github.com/BangYunseo/Basic_CPP/blob/main/ch02_BasicC%2B%2B/UsingcoutAnd%3C%3C.cpp)

#### namespace
* 이름 공간 생성 및 사용
```C++
 namespace ABC { // ABC라는 이름 공간 생성
// 이 곳에 선언된 모든 이름은 ABC 이름 공간에 생성된 이름
}
```
   * 이름 공간 사용
     * 이름 공간 :: 이름     

![functionf](https://github.com/BangYunseo/TIL/blob/main/Language/Cpp/Image/ch02/functionf.PNG)

#### std
* std:: 란?
  * C++ 표준에서 정의한 이름 공간(namespace) 중 하나
    * <iostream> 헤더 파일에 선언된 모든 이름 : std 이름 공간 안에 있음
    * cout, cin, endl 등
  * std 이름 공간에 선언된 이름을 접근하기 위해 std:: 접두어 사용
    * std::cout, std::cin, std::endl
* std:: 생략
  * using 지시어 사용
```C++
using namespace std;
// std 이름 공간에 선언된 모든 이름의 std::사용 생략
cout << "안녕하세요!" << endl;
// 위의 cout과 endl에 std가 생략된 모습을 볼 수 있음
```
* <iostream>이 std 이름 공간 내에 선언
  * 보통 아래와 같이 모두 선언함
```C++
#include <iostream>
using namespace std;
```

## 2절. 입력
#### cin과 >> 연산자
* cin
  * 표준 입력 장치인 키보드를 연결하는 C++ 입력 스트림 객체
* '>> 연산자'
  * 스트림 추출 연산자(stream extraction operator)
    * C++ 산술 시프트 연산자(>>)가 <iostream> 헤더 파일에 스트림 추출 연산자로 재정의됨
    * 입력 스트ㅡ림에서 값을 읽어 변수에 저장
  * 연속된 >> 연산자를 사용하여 여러 값 입력 가능
```C++
cout << "너비와 높이 입력 >> ";
cin >> width >> height;
cout << width << '\n' << height << '\n';

// 출력 예시
// 너비와 높이 입력 >>23 36
// 23(width 값)
// 36(height 값)
```

* 예제 2. 너비와 높이 입력받기 확장 예제    
[SourceCodeChecking](https://github.com/BangYunseo/Basic_CPP/blob/main/ch02_BasicC%2B%2B/InputWidthHeight.cpp)

* cin의 특징
  * 입력 버퍼를 내장
  * <Enter>키가 입력될 때까지 입력된 키를 입력 버퍼에 저장
    * 도중에 <Backspace> 키를 입력하면 입력된 키 삭제
* '>> 연산자'
  * <Enter> 키가 입력되면 cin의 입력 버퍼에서 키 값을 읽어 변수에 전달

* cin으로부터 키 입력받는 과정

![inputcin](https://github.com/BangYunseo/TIL/blob/main/Language/Cpp/Image/ch02/inputcin.PNG)

#### 실행문 중간에 변수 선언
* C++의 변수 선언
  * 변수 선언은 아무 곳이나 가능
```C++
int width;
cout << "너비 입력 >> ";
cin >> width;
// 키보드로부터 너비를 입력받음

cout << "높이 입력 >> ";
int height;
cin >> height;
// 키보드로부터 높이를 입력받음

int area = width * height;
cout << "면적은 " << area << endl;
// 면적을 출력한 후 한 줄 띄어씀
```
* C++ 변수 선언 방식의 장점
  * 변수를 사용하기 직전 선언함으로써 변수 이믈에 대한 타이핑 오류 줄임
* C++ 변수 선언 방식의 단점
  * 선언된 변수를 일괄적으로 보기 힘듦
  * 코드 사이에 있는 변수를 찾아야 됨


#### 타이핑 오류 가능성 해소
* 선언부에 모든 변수를 선언하는 경우, 타이핑 오류 가능
```C++
int time, timer;

timer = 5;
// time에 5를 저장하려다가 timer로 잘못 입력한 경우
// 컴파일 오류는 발생하지 않음
// 잘못된 실행 결과 발생

timer = 3;
```
* 변수 사용 전에 변수를 선언하면, 타이핑 오류 사전 발견
```C++
int time;

timer = 5;
// time에 5를 저장하려다가 timer로 잘못 입력한 경우
// 컴파일 오류 발생

int timer;
timer = 3;
```

## 3절. 문자열
#### C++ 문자열
* C++의 문자열 표현 방식 : 2가지
  * C-스트링 방식 - '\0'로 끝나는 문자 배열
```C++
char name1[6] = {'G', 'r', 'a', 'c', 'e', '\0'};
// name1은 문자열 "Grace"
char name2[5] = {'G', 'r', 'a', 'c', 'e'};
// name2는 문자열이 아닌 단순 문자 배열
```
![stringchar](https://github.com/BangYunseo/TIL/blob/main/Language/Cpp/Image/ch02/stringchar.PNG)

  * string 클래스 이용
    * <string> 헤더 파일에 선언
    * 다양한 멤버 함수 제공, 문자열 비교, 복사, 수정 등

#### C-스트링 방식으로 문자열 다루기
* C언어에서 사용한 함수 사용 가능
  * strcmp(), strlen(), strcpy() 등
* <cstring>이나 <string.h> 헤더 파일 #include 필요
```C++
#include <cstring> or #include <string.h>

int n = strlen("Hello!!");
```
* <cstring> 헤더 파일을 사용하는 것이 더 나음
  * C++ 표준 방식
 
#### cin을 이용한 문자열 입력
```C++
char name[6];
// 5개의 문자를 저장하는 char 배열
cin >> name;
// 키보드로부터 문자열을 읽어 name 배열에 저장
// 키 입력 : Grace
```

![grace](https://github.com/BangYunseo/TIL/blob/main/Language/Cpp/Image/ch02/grace.PNG)

* 예제 3. 문자열 입력받고 출력하는 예제      
[SourceCodeChecking](https://github.com/BangYunseo/Basic_CPP/blob/main/ch02_BasicC%2B%2B/InputChar.cpp)

* 예제 4. 암호를 입력받고 프로그램을 종료하는 예제      
[SourceCodeChecking](https://github.com/BangYunseo/Basic_CPP/blob/main/ch02_BasicC%2B%2B/InputPassword.cpp)

#### cin.getline()으로 공백이 낀 문자열 입력
* 공백이 있는 문자열 입력받는 방법
* cin.getline(char buf[], int size, char delimitChar)
  * buf에 최대 size-1개의 문자 입력 후 끝에 '\0' 붙임
  * delimitChar를 만나면 입력 중단 후 끝에 '\0' 붙임
    * delimitChar의 디폴트 값은 '\n'(<Enter> 키)
```C++
char address[100];
cin.getline(address, 100, '\n');
// 최대 99개의 문자를 읽어 address 배열에 저장
// 도중에 <Enter> 키를 만나면 입력 중단
```

![cingetline](https://github.com/BangYunseo/TIL/blob/main/Language/Cpp/Image/ch02/cingetline.PNG)

* 예제 5. cin.getline()을 이용한 문자열 입력 예제      
[SourceCodeChecking](https://github.com/BangYunseo/Basic_CPP/blob/main/ch02_BasicC%2B%2B/CinGetLine().cpp)

#### C++에서 문자열을 다루는 string 클래스
* string 클래스
  * C++에서 가장 추천하며 C++의 표준 클래스
  * 문자열의 크기에 따른 제약 없음
    * string 클래스가 스스로 문자열의 크기에 맞게 내부 버퍼 조절
  * 문자열 복사, 비교, 수정 등 다양한 함수와 연산자 제공
  * 객체 지향적
  * <string> 헤더 파일에 선언
    * #include <string>
  * C-스트링보다 다루기 쉬움

* 예제 6. string 클래스를 이용한 문자열 입력 예제      
[SourceCodeChecking](https://github.com/BangYunseo/Basic_CPP/blob/main/ch02_BasicC%2B%2B/UsingStringClass.cpp)
