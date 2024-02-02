#  Chapter 15. C++ 입출력 시스템      
> '명품 C++Programming - 황기태' 11장 학습 내용
>
> [소스코드](https://github.com/BangYunseo/Basic_CPP/tree/main/ch15_C++IOSystem)
> 
> 1절. 스트림
> 
> 2절. 스트림 객체
>
> 3절. 포맷
>
> 4절. 조작자
>
> 5절. 연산자


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

#### ostream 멤버 함수
```CPP
ostream& put(char ch);
// ch의 문자를 스트림에 출력

ostream& write(char *str, int n)
// str 배열에 있는 n개의 문자를 스트림에 출력

ostream& flush()
// 현재 스트림 버퍼에 있는 내용 강제 출력
```

* 예제 1. ostream 멤버 함수를 이용한 문자 출력 예제     
[SourceCodeChecking](https://github.com/BangYunseo/Basic_CPP/blob/main/ch15_C%2B%2BIOSystem/OstreamStringPrint.cpp)

#### istream 멤버 함수 : 문자 입력, get() 함수
```CPP
int get()
// 입력 스트림에서 문자를 읽어 리턴
// 오류나 EOF를 만나면 -1(EOF) 리턴

istream& get(char& ch)
// 입력 스트림에서 문자를 읽어 ch에 저장
// 현재 입력 스트림 객체(*this)의 참조 리턴
// 오류나 EOF를 만나면 스트림 내부의 오류 플래그(failbit) 세팅 - (16장 참고)
```
* int get()을 이용하여 한 라인의 문자들을 읽는 코드
```CPP
int ch;
while((ch = cin/get()) != EOF{
// EOF = -1 : 입력 스트림의 끝인지 비교
 cout.put(ch);
 // 읽은 문자 출력
 if(ch == '\n') break;
 // <Enter> 키가 입력되면 읽기 중단
```
* istream& get(char& ch)을 이용하여 한 라인의 문자들을 읽는 코드
```CPP
char ch;
while(true){
 cin.get(ch);
 // 입력된 키를 ch에 저장하여 리턴
 if(cin.eof()) break;
 // EOF를 만나면 읽기 종료 : 입력 스트림의 끝인지 비교
 cout.put(ch);
 // ch의 문자 출력
 if(ch == '\n') break;
 // <Enter> 키가 입력되면 읽기 중단
}
```
#### ch = cin.get()의 실행 사례

![cinget](https://github.com/BangYunseo/TIL/blob/main/Cpp/Image/ch15/cinget.PNG)

* 예제 2. get()과 get(char&)을 이용한 한 줄의 문자를 읽는 예제     
[SourceCodeChecking](https://github.com/BangYunseo/Basic_CPP/blob/main/ch15_C%2B%2BIOSystem/FunctionGet.cpp)

#### 문자열 입력
```CPP
istream& get(char *s, int n);
// 입력 스트림으로부터 n-1개의 문자를 읽어 배열 s에 저장
// 마지막에 '\0' 문자 삽입
// 입력 도중 '\n'을 만나면 '\0'을 삽입하고 리턴
```
* 사용 예시
```CPP
char str[10];
cin.get(str, 10);
// 최대 9개의 문자를 읽고 끝에 '\0'을 붙여 str 배열에 저장

cout << str;
// str을 화면에 출력
```

* 입력 도중 <Enter> 키('\n')을 만날 때
  * 읽기를 중단하고 리턴
  * <Enter> 키('\n')를 스트림 버퍼에 남김
    * 다시 get()으로 문자열 읽기를 시도하면 입력 스트림에 남은 '\n'키를 읽게 되어 무한 루프에 빠짐
    * cin.get()이나 cin.ignore(1);를 통해 문자 1개('\n')를 스트림에서 읽어야 함

* 예제 3. get(char*, int)을 이용한 문자열 입력 예제     
[SourceCodeChecking](https://github.com/BangYunseo/Basic_CPP/blob/main/ch15_C%2B%2BIOSystem/FunctionGet*.cpp)

#### 한 줄 읽기
```CPP
istream& get(char *s, int n, char delim = '\n');
// 입력 스트림으로부터 최대 n-1개의 문자를 읽어 배열 s에 저장
// 마지막에 '\0' 문자 삽입
// 입력 도중 delim에 지정된 구분 문자를 만나면 지금까지 읽은 문자를 배열 s에 저장하고 리턴

istream& getline(char *s, int n, char delim = '\n');
// get()과 동일하지만 delim에 저장된 구분 문자를 스트림에서 제거
```

![readingline](https://github.com/BangYunseo/TIL/blob/main/Cpp/Image/ch15/readingline.PNG)

* 예제 4. getline()으로 한 줄 단위 문장 읽는 예제     
[SourceCodeChecking](https://github.com/BangYunseo/Basic_CPP/blob/main/ch15_C%2B%2BIOSystem/ReadingGetLine.cpp)

#### 입력 문자 건너뛰기와 문자 개수 알아내기
```CPP
istream& ignore(int n = 1, int delime = EOF);
// 입력 스트림에서 n개 문자 제거
// 도중 delim 문자를 만나면 delim 문자를 제거하고 리턴

int gcount();
// 최근 입력 스트림에서 읽은 바이트 수(문자의 개수) 리턴
// <Enter> 키도 개수에 포함
```
* 입력 스트림에서 문자 건너뛰기
```CPP
cin.ignore(10);
// 입력 스트림에 입력된 문자 중 10개 제거

cin.ignore(10, ';');
// 입력 스트림에서 10개의 문자 제거
// 제거 도중 ';' 을 만나면 종료
```

* 최근에 읽은 문자 개수 리턴
```CPP
char line[80];
cin.getline(line, 80);
int n = cin.gcount();
// 최근 실행한 getline() 함수에서 읽은 문자의 개수 리턴
```

## 3절. 포맷
#### 포맷 입출력
* 입출력 시 포맷 지정 가능
  * C언어의 printf()와 유사
* 포맷 입출력 방법 3가지
  * 포맷 플래그
  * 포맷 함수
  * 조작자

#### 포맷 플래그
* 입출력 스트림에서 입출력 형식을 지정하기 위한 플래그

![ios](https://github.com/BangYunseo/TIL/blob/main/Cpp/Image/ch15/ios.PNG)

#### ios 클래스에 정의된 포맷 플래그

![iosflag](https://github.com/BangYunseo/TIL/blob/main/Cpp/Image/ch15/iosflag.PNG)

#### 포맷 플래그를 세팅하는 멤버 함수
```CPP
long setf(long flags);
// flags를 스트림의 포맷 플래그로 설정하고 이전 플래그 리턴

long unsetf(long flags);
// flags에 설정된 비트 값에 따라 스트림의 포맷 플래그를 해체하고 이전 플래그 리턴
```

* 10진수를 16진수로 출력 예시
```CPP
cout.unsetf(iost::dec);
// 10진수 해제

cout.setf(ios::hex);
// 16진수 설정

cout << 30 << endl;
// 1e 출력
```

* 사용 예시 2
```CPP
cout.setf(ios::dec | ios::showpoint);
// 10진수 표현, 실수에 소숫점 이하 나머지는 0으로 출력 설정

cout << 23.5 << endl;
// 23.5000으로 출력
```

* 예제 5. setf(), unsetf() 사용한 포맷 출력 예제     
[SourceCodeChecking](https://github.com/BangYunseo/Basic_CPP/blob/main/ch15_C%2B%2BIOSystem/SetfUnsetf.cpp)

#### 포맷 함수 활용
```CPP
int width(int minWidth);
// 출력되는 필드의 최소 너비를 minWidth로 설정
//- 이전에 설정된 너비 값 리턴

char fill(char cFill);
// 필드의 빈칸을 cFill 문자로 채우도록 지정하고 이전 문자 값 리턴

int precision(int np);
// 출력되는 수의 유효 숫자 자리 수를 np개로 설정
// 정수 부분과 소수점 이하의 수의 자리를 모두 포함하고 소수점(.) 제외
```
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
