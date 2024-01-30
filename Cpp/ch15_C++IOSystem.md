#  Chapter 15. C++ 입출력 시스템      
> '명품 C++Programming - 황기태' 11장 학습 내용
>
> [소스코드](https://github.com/BangYunseo/Basic_CPP/tree/main/ch15_C++IOSystem)
> 
> 1절. 스트림
> 
> 2절. 스트림 객체
>
> 3절. 


## 1절. 스트림
#### 스트림(stream)
* 데이터의 흐름
* 데이터를 전송하는 소프트웨어 모듈
  * 흐르는 시내와 유사한 개념
* 스트림의 양 끝에는 프로그램과 장치 연결
  * 보낸 순서대로 데이터 전달
  * 입출력 기본 단위 : 바이트(byte)
* 스트림 종류
  * 입력 스트림
    * 입력 장치, 네트워크, 파일로부터 데이터를 프로그램으로 전달하는 스트림
  * 출력 스트림
    * 프로그램에서 출력되는 데이터를 출력 장치, 네트워크, 파일로 전달하는 스트림

#### C++ 입출력 스트림

![IOstream](https://github.com/BangYunseo/TIL/blob/main/Cpp/Image/ch15/IOstream.PNG)

#### C++ 입출력 스트림 버퍼
* C++ 입출력 스트림은 버퍼를 가짐
* 키 입력 스트림의 버퍼
  * 목적
    * 입력장치로부터 입력된 데이터를 프로그램으로 전달하기 전에 일시 저장
    * 키 입력 도중 수정 가능
      * <Backspace> 키가 입력되면 이전 입력된 키를 버퍼에서 지움
  * 프로그램은 사용자의 키 입력이 끝난 시점에서 읽음
    * <Enter> 키 : 키 입력의 끝
    * <Enter> 키가 입력된 시점부터 키 입력 버퍼에서 프로그램이 읽기 시작
* 스크린 출력 스트림 버퍼
  * 목적
    * 프로그램에서 출력된 데이터를 출력 장치로 보내기 전에 일시 저장
    * 출력 장치를 반복적으로 사용하는 비효율성 개선
  * 버퍼가 꽉 차거나 강제 출력 명령 시에 출력 장치에 출력

#### 키 입력 스트림과 버퍼의 역할

![Istream](https://github.com/BangYunseo/TIL/blob/main/Cpp/Image/ch15/Istream.PNG)

#### 스크린 출력 스트림과 버퍼의 역할

![Ostream](https://github.com/BangYunseo/TIL/blob/main/Cpp/Image/ch15/Ostream.PNG)

#### C++ 표준 : 스트림 입출력만 지원
* 입출력 방식 2가지
  * 스트림 입출력 방식(stream I/O)
    * 슽트림 버퍼를 이용한 입출력 방식
    * 입력된 키는 버퍼에 저장
      * <Enter> 키가 입력되면 프로그램이 버퍼에서 읽어가는 방식
    * 출력되는 데이터는 일차적으로 스트림 버퍼에 저장
      * 특정한 경우에만 버퍼가 출력 장치에 출력
        * 버퍼가 꽉 찼을 경우
        * '\n'을 만난 경우
        * 강제 출력 명령의 경우
  * 저 수준 입출력 방식(raw lever console I/O)
    * 키가 입력되는 즉시 프로그램에게 키 값 전달
      * <Backspace> 키 그 자체도 프로그램에 바로 전달
      * 게임 등 키 입력이 즉각적으로 필요한 곳에 사용
    * 프로그램이 출력하는 즉시 출력 장치에 출력
    * 컴파일러마다 다른 라이브러리나 API 지원
      * C++ 프로그램의 호환성 낮음
* C++ 표준은 스트림 방식만 지원
  * 스트림 입출력은 모든 표준 C++ 컴파일러에 의해 컴파일
  * 높은 호환성
 
#### 2003년 이전의 C++ 입출력 라이브러리 약점
* 대표적인 구 표준(C++03) 입출력 라이브러리 클래스
  * ios, istream, ostream, iostream, ifstream, ofstream, fstream
* 문자를 한 바이트의 char로 처리
  * cin >> 로 문자를 읽을 때, 한글 문자 읽기 불가능
    * 영어나 기호 : 1 바이트
    * 한글 문자 : 2 바이트
```CPP
char ch;
cin >> ch;
// 키보드로 문자 입력
// 한글 문자는 읽을 수 없음
```
* 현재도 cin은 한글을 문자 단위로 읽을 수 없음

#### 새 표준 C++ 입출력 라이브러리
* 다양한 크기의 다국어 문자를 수용하기 위해 입출력 라이브러리를 템플릿으로 작성

![IOlib](https://github.com/BangYunseo/TIL/blob/main/Cpp/Image/ch15/IOlib.PNG)

#### typedef로 선언된 ios, istream, ostream, iostream 클래스

![typedef](https://github.com/BangYunseo/TIL/blob/main/Cpp/Image/ch15/typedef.PNG)

#### 입출력 클래스 소개

![IOclass](https://github.com/BangYunseo/TIL/blob/main/Cpp/Image/ch15/IOclass.PNG)

## 2절. 스트림 객체
#### 표준 입출력 스트림 객체
* C++ 프로그램이 실행될 때 자동으로 생겨나는 스트림
  * cin
    * istream 타입의 스트림 객체
    * 키보드 장치와 연결
  * cout
    * ostream 타입의 스트림 객체
    * 스크린 장치와 연결
  * cerr
    * ostream 타입의 스트림 객체
    * 스크린 장치와 연결
    * 오류 메시지를 출력할 목적
    * 스트림 내부 버퍼 거치지 않고 출력
  * clog
    * ostream 타입의 스트림 객체
    * 스크린 장치와 연결
    * 오류 메시지를 출력할 목적
    * 스트림 내부 버퍼 거치지 않고 출력

#### <iostream>에 선언된 스트림 객체

![iostream2](https://github.com/BangYunseo/TIL/blob/main/Cpp/Image/ch15/iostream2.PNG)

(여기서부터 작성)
#### ostream 멤버 함수

![vector](https://github.com/BangYunseo/TIL/blob/main/Cpp/Image/ch14/vector.PNG)

* 예제 1. vector 컨테이너 활용 예제     
[SourceCodeChecking](https://github.com/BangYunseo/Basic_CPP/blob/main/ch14_StandardTemplateLibrary/VectorContainer.cpp)

* 예제 2. 문자열을 저장하는 벡터 생성 예제     
[SourceCodeChecking](https://github.com/BangYunseo/Basic_CPP/blob/main/ch14_StandardTemplateLibrary/SavingString.cpp)


## 3절. Iterator
#### iterator 사용
* iterator란 ?
  * 반복자라고도 부름
  * 컨테이너의 원소를 가리키는 포인터
* iterator 변수 선언
  * 구체적인 컨테이너를 지정하여 반복자 변수 생성

![iterator](https://github.com/BangYunseo/TIL/blob/main/Cpp/Image/ch14/iterator.PNG)

* 예제 3. iterator를 사용하여 vector의 모든 원소에 2를 곱하는 예제     
[SourceCodeChecking](https://github.com/BangYunseo/Basic_CPP/blob/main/ch14_StandardTemplateLibrary/IteratorToVector.cpp)

## 4절. Map
#### map 컨테이너
* 특징
  * ('키', '값')의 쌍을 원소로 저장하는 제네릭 컨테이너
    * 동일한 '키'를 가진 원소가 중복 저장되면 오류 발생
  * '키'로 '값' 검색
  * 많은 응용에 필요
  * #include <map> 필요
* 맵 컨테이너 생성 예시
  * 영한 사전을 저장하기 위한 맵 컨테이너 생성 및 활용
    * 영어 단어와 한글 단어를 쌍으로 저장하고 영어 단어로 검색

```CPP
// 맵 생성
Map<string, string> dic;               // 키는 영어 단어, 값은 한글 단어

// 원소 저장
dic.insert(make_pair("love", "사랑"));  // ("love", "사랑") 저장
dec["love"] = "사랑";                   // ("love", "사랑") 저장

// 원소 검색
string kor = dic["love"];               // kor은 "사랑"
string kor = dic.at("love");            // kor은 "사랑"
```

* 예제 4. map으로 만든 영한 사전 예제     
[SourceCodeChecking](https://github.com/BangYunseo/Basic_CPP/blob/main/ch14_StandardTemplateLibrary/MapDictionary.cpp)


## 5절. STL 알고리즘
#### STL 알고리즘 사용
* 알고리즘 함수
  * 템플릿 함수
  * 전역 함수
    * STL 컨테이너 클래스의 멤버 함수가 아님
  * iterator와 함께 작동
* sort() 함수 사례
  * 두 개의 매개 변수
    * 첫 번째 매개 변수 : sorting을 시작한 원소의 주소
    * 두 번째 매개 변수 : sorting 범위의 마지막 원소 다음 주소
```CPP
vector<int> v;
...
sort(v.begin(), v.begin() + 3);
// v.begin()에서 v.begin() + 2까지 : 처음 3개 원소 정렬

sort(v.begin() + 2, v.begin() + 5);
// v.begin() + 2에서 v.begin() + 4까지 : 벡터의 세 번째 원소에서 3개 원소 정렬

sort(v.begin(), v.end());
// 벡터 전체 정렬
```

* 예제 5. sort() 함수를 이용한 vector Sorting 예제     
[SourceCodeChecking](https://github.com/BangYunseo/Basic_CPP/blob/main/ch14_StandardTemplateLibrary/VectorSorting.cpp)

## 6절. Auto
#### auto를 이용한 쉬운 변수 선언
* auto
  * 기능
    * C++11부터 auto 선언 의미 수정 : 컴파일러에게 변수선언문에서 추론하여 타입을 자동 선언하도록 지시
    * C++11이전 : 스택에 할당되는 지역 변수를 선언하는 키워드
  * 장점
    * 복잡한 변수 선언을 간소하게, 긴 타입 선언 시 오타 줄임
* auto의 기본 사용 사례

```CPP
auto pi = 3.14;
// 3.14는 실수이므로 pi는 double 타입으로 선언

auto n = 3;
// 3이 정수이므로 n은 int 타입으로 선언

auto *p = &n;
// 변수 p는 int* 타입으로 추론
```

```CPP
int n = 10;
int &ref = n;
// ref는 int에 대한 참조 변수

auto ref2 = ref;
// ref2는 int& 변수로 자동 선언
```

#### auto의 다른 활용 사례
* 함수의 리턴 타입으로부터 추론하여 변수 타입 선언
```CPP
int square(int x){ return x * x; }
...
auto ret = square(3);
// 변수 ret는 int 타입으로 추론
```
* STL 템플릿에 활용
  * vector<int>iterator 타입의 변수 it를 auto를 이용하여 간단히 선언

![auto](https://github.com/BangYunseo/TIL/blob/main/Cpp/Image/ch14/auto.PNG)

* 예제 6. auto 변수 예제     
[SourceCodeChecking](https://github.com/BangYunseo/Basic_CPP/blob/main/ch14_StandardTemplateLibrary/AutoVariable.cpp)

## 7절. 람다
#### 람다
* 람다 대수와 람다식
  * 람다 대수에서 람다식은 수학 함수를 단순하게 표현하는 기법

![lambda](https://github.com/BangYunseo/TIL/blob/main/Cpp/Image/ch14/lambda.PNG)

* C++ 람다
  * 익명의 함수 만드는 기능으로 C++11에서 도입
    * 람다식, 람다 함수로도 불림
    * C#, Java, 파이썬, 자바스크립트 등 많은 언어들이 도입

#### 람다식 선언
* 람다식의 구성
  * 4부분으로 구성
    * 캡쳐 리스트 : 람다식에서 사용하고자 하는 함수 바깥의 변수 목록
    * 매개 변수 리스트 : 보통 함수의 매개 변수 리스트와 동일
    * 라턴 타입
    * 함수 바디 : 람다 식의 함수 코드

![lambda2](https://github.com/BangYunseo/TIL/blob/main/Cpp/Image/ch14/lambda2.PNG)


* 예제 7. 매개 변수 x, y의 합을 출력하는 람다식 생성 예제     
[SourceCodeChecking](https://github.com/BangYunseo/Basic_CPP/blob/main/ch14_StandardTemplateLibrary/MakingLambda.cpp)

* 예제 8. auto로 람다식 저장 및 호출 예제     
[SourceCodeChecking](https://github.com/BangYunseo/Basic_CPP/blob/main/ch14_StandardTemplateLibrary/AutoLambda.cpp)

* 예제 9. 캡쳐 리스트와 리턴 타입을 가지는 람다식 예제     
[SourceCodeChecking](https://github.com/BangYunseo/Basic_CPP/blob/main/ch14_StandardTemplateLibrary/PiLambda.cpp)

* 예제 10. 캡쳐 리스트에 참조를 활용하는 람다식 예제     
[SourceCodeChecking](https://github.com/BangYunseo/Basic_CPP/blob/main/ch14_StandardTemplateLibrary/SumLambda.cpp)

* 예제 11. STL for-each() 함수를 이용하여 벡터의 모든 원소를 출력하는 예제     
[SourceCodeChecking](https://github.com/BangYunseo/Basic_CPP/blob/main/ch14_StandardTemplateLibrary/STLVectorLambda.cpp)

* 예제 12. STL 템플릿에 람다식 활용 예제     
[SourceCodeChecking](https://github.com/BangYunseo/Basic_CPP/blob/main/ch14_StandardTemplateLibrary/STLLambda.cpp)
