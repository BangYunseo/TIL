#  Chapter 3. 클래스와 객체   
> '명품 C++Programming - 황기태' 3장 학습 내용
>
> [소스코드](https://github.com/BangYunseo/Basic_CPP/tree/main/ch02_BasicC%2B%2B)
> 
> 1절. 클래스와 객체
> 
> 2절. 클래스
>
> 3절. 문자열

## 1절. 클래스와 객체
#### 캡슐화
* 객체의 캡슐화(encapsulation)
  * 객체의 본질적인 특성
  * 객체를 캡슐로 싸서 그 내부를 보호하고 볼 수 없도록 만듦
    * 캡슐에 든 약은 어떤 색인지 어떤 성분인지 보이지 않고, 외부로부터 안전
  * 캡슐화의 목적
    * 객체 내 데이터에 대한 보안, 보호, 외부 접근 제한
  * 캡슐화의 사례(TV 객체)

![TVclass](https://github.com/BangYunseo/TIL/blob/main/Cpp/Image/ch3/TVclass.PNG)

#### C++에서의 클래스와 객체
* 클래스
  * 객체를 만들어내기 위해 정의된 설계도, 틀
  * 클래스 != 객체
  * 클래스는 실체가 아님
  * 멤버 변수와 멤버 함수 선언
* 객체
  * 객체는 생성될 때 클래스의 모양을 가짐
  * 멤버 변수와 멤버 함수로 구성
  * 메모리에 생성
  * 실체(instance)라고도 부름
  * 하나의 클래스 틀에서 찍어낸 여러 개의 객체 생성 가능
  * 객체들은 상호 별도의 공간에 생성
* 클래스와 객체의 관계

![ClassObject](https://github.com/BangYunseo/TIL/blob/main/Cpp/Image/ch3/ClassObject.PNG)

## 2절. 클래스
#### 클래스 작성의 기본
* 클래스 작성
  * 멤버 변수, 멤버 함수로 구성
  * 클래스 선언부, 클래스 구현부로 구성
* 클래스 선언부(Class Declaration)
  * class 키워드를 이용하여 클래스 선언
  * 멤버 변수와 멤버 함수 선언
    * 멤버 변수는 클래스 선언 내에서 초기화 불가
    * 멤버 함수는 원형(prototype) 형태로 선언
  * 멤버에 대한 접근 지정
    * private, public, protected 중 하나
    * default는 private
    * public : 다른 모든 클래스나 객체에서 멤버의 접근이 가능함
* 클래스 구현부(Class Implementation)
  * 클래스에 정의된 모든 멤버 함수 구현
* 그림으로 클래스 작성 확인하기 
![MakeClass](https://github.com/BangYunseo/TIL/blob/main/Cpp/Image/ch3/MakeClass.PNG)

* 예제 1. Circle 클래스 예제  
[SourceCodeChecking](https://github.com/BangYunseo/Basic_CPP/blob/main/ch03_BasicC%2B%2B/InputWidthHeight.cpp)

* cin의 특징
  * 입력 버퍼를 내장
  * <Enter>키가 입력될 때까지 입력된 키를 입력 버퍼에 저장
    * 도중에 <Backspace> 키를 입력하면 입력된 키 삭제
* '>> 연산자'
  * <Enter> 키가 입력되면 cin의 입력 버퍼에서 키 값을 읽어 변수에 전달

* cin으로부터 키 입력받는 과정

![inputcin](https://github.com/BangYunseo/TIL/blob/main/Cpp/Image/ch2/inputcin.PNG)

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
![stringchar](https://github.com/BangYunseo/TIL/blob/main/Cpp/Image/ch2/stringchar.PNG)

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

![grace](https://github.com/BangYunseo/TIL/blob/main/Cpp/Image/ch2/grace.PNG)

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

![cingetline](https://github.com/BangYunseo/TIL/blob/main/Cpp/Image/ch2/cingetline.PNG)

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
