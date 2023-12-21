#  Chapter 3. 클래스와 객체   
> '명품 C++Programming - 황기태' 3장 학습 내용
>
> [소스코드](https://github.com/BangYunseo/Basic_CPP/tree/main/ch03_ClassAndObject)
> 
> 1절. 클래스와 객체
> 
> 2절. 클래스
>
> 3절. 생성자

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

* 예제 2. Rectangle 클래스 예제       
[SourceCodeChecking](https://github.com/BangYunseo/Basic_CPP/blob/main/ch03_ClassAndObject/RectangleClass.cpp)

## 3절. 생성자
#### 생성자(constructor)
* 객체가 생성되는 시점에서 자동으로 호출되는 멤버 함수
* 클래스 이름과 동일한 멤버 함수
![constructor](https://github.com/BangYunseo/TIL/blob/main/Cpp/Image/ch3/constructor.PNG)

#### 생성자 함수의 특징
* 생성자의 목적
  * 객체가 생성될 때 객체가 필요한 초기화를 위해 만듦
    * ex) 멤버 변수 값 초기화, 메모리 할당, 파일 열기, 네트워크 연결 등
* 생성자 이름
  * 반드시 클래스 이름과 동일
* 생성자는 리턴 타입을 선언하지 않음
  * 리턴 타입 없음
  * void 타입 안됨
* 객체 생성 시 오직 한 번만 호출
  * 자동으로 호출되므로 임의로 호출 불가능
  * 각 객체마다 생성자 실행
* 생성자는 중복 가능
  * 생성자는 한 클래스 내에 여러 개 가능
  * 중복된 생성자 중 하나만 실행
* 생성자가 선언되어 있지 않으면 기본 생성자는 자동으로 생성
  * 기본 생성자 : 매개 변수 없는 생성자
  * 컴파일러에 의해 자동 생성

* 예제 3. 2개의 생성자를 가진 Circle 클래스 예제              
[SourceCodeChecking](https://github.com/BangYunseo/Basic_CPP/blob/main/ch03_ClassAndObject/CircleClass2con.cpp)

* 그림으로 이해하기
![make2con](https://github.com/BangYunseo/TIL/blob/main/Cpp/Image/ch3/make2con.PNG)

#### 객체 생성 및 활용
* 객체 이름 및 객체 생성
```C++
Circle donut;
// 이름이 donut인 Circle 타입의 객체 생성
```
* 객체의 멤버 변수 접근
```C++
donut.radius = 3;
// donut 객체의 radius 멤버 값을 3으로 설정
```
* 객체의 멤버 함수 접근
```C++
double area = donut.getArea()
// donut 객체의 면적 설정
```

![ObjectMaker](https://github.com/BangYunseo/TIL/blob/main/Cpp/Image/ch3/[ObjectMaker.PNG)

* 예제 2. Rectangle 클래스 예제     (여기부터 작성 15p)
[SourceCodeChecking](https://github.com/BangYunseo/Basic_CPP/blob/main/ch03_ClassAndObject/RectangleClass.cpp)

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
