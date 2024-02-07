#  Chapter 16. C++ 파일 입출력     
> '명품 C++Programming - 황기태' 12장 학습 내용
>
> [소스코드](https://github.com/BangYunseo/Basic_CPP/tree/main/ch16_FileIO)
> 
> 1절. 텍스트 파일과 바이너리 파일
> 
> 2절. C++ 파일 입출력
>
> 3절. 파일 모드
>
> 4절. 텍스트 I/O와 바이너리 I/O
>
> 5절. 스트림 상태
>
> 6절. 임의 접근과 파일 포인터


## 1절. 텍스트 파일과 바이너리 파일
#### 텍스트 파일
* 사람들이 사용하는 글자 혹은 문자들로만 구성되는 파일
  * 알파벳, 한글, 숫자, % # @ < ? 등의 기호 문자
* '\n', '\t' 등의 특수 문자도 포함
* 각 문자마다 문자 코드(이진수) 할당
  * 아스키 코드, 유니 코드
* 텍스트 파일의 종류
  * txt 파일, HTML 파일, XML 파일, C++ 소스 파일, C 소스 파일, 자바 소스 파일
* 텍스트 파일과 <Enter> 키
  * <Enter>키를 입력하면 텍스트 파일에 '\r', '\n'의 두 코드가 기록
* 아스키 코드 표 샘플

![asciicode](https://github.com/BangYunseo/TIL/blob/main/Cpp/Image/ch16/asciicode.PNG)

#### 텍스트 파일의 내부

![elvis](https://github.com/BangYunseo/TIL/blob/main/Cpp/Image/ch16/elvis.PNG)
![elvis2](https://github.com/BangYunseo/TIL/blob/main/Cpp/Image/ch16/elvis2.PNG)

#### 바이너리 파일
* 문자로 표현되지 않는 바이너리 데이터가 기록된 파일
  * 이미지, 오디오, 그래픽, 컴파일된 코드는 문자로 표현되지 않음
* 텍스트 파일의 각 바이트 -> 문자로 해석
* 바이너리 파일의 각 바이트 -> 문자로 해석되지 않는 것도 존재
  * 각 바이트의 의미는 파일을 만든 응용프로그램만이 해석 가능
* 바이너리 파일의 종류
  * jpeg, bmp 등의 이미지 파일
  * mp3 등의 오디오 파일
  * hwp, doc, ppt 등의 확장자를 가진 멀티미디어 문서 파일
  * obj, exe 등의 확장자를 가진 컴파일된 코드나 실행 파일 

#### 바이너리 파일의 내부

![uisee](https://github.com/BangYunseo/TIL/blob/main/Cpp/Image/ch16/uisee.PNG)

#### hwp 파일은 바이너리 파일
* 텍스트 정보 포함
  * 한글, 영어 문자 포함
* 바이너리 정보 포함
  * 글자 색이나 서체 등의 문자 포맷 정보
  * 비트맵 이미지
  * 표
  * 선, 원 등의 그래픽 정보
  * 왼쪽 마진, 오른쪽 마진 등 문서 포맷 정보

## 2절. C++ 파일 입출력
#### C++ 표준 파일 입출력 라이브러리
* 스트림 입출력 방식 지원
![stream](https://github.com/BangYunseo/TIL/blob/main/Cpp/Image/ch16/stream.PNG)

#### 템플릿에 char 타입으로 구체화한 클래스

![typedef](https://github.com/BangYunseo/TIL/blob/main/Cpp/Image/ch16/typedef.PNG)

#### 파일과 프로그램을 연결하는 파일 입출력 스트림

![iostream](https://github.com/BangYunseo/TIL/blob/main/Cpp/Image/ch16/iostream.PNG)

* >> 연산자와 istream의 get(), read() 함수
  * 연결된 장치로부터 읽는 함수
  * 키보드에 연결되면 키 입력을, 파일에 연결되면 파일에서 입력
* << 연산자와 ostream의 put(), write() 함수
  * 연결된 장치에 쓰는 함수
  * 스크린에 연결되면 화면에, 파일에 연결되면 파일에 출력

#### 헤더 파일과 namespace
* C++ 파일 입출력 라이브러리 사용
  * fstream 헤더 파일과 std 이름 공간의 선언 필요
```CPP
#include <fstream>

using namespace std;
```

#### 파일 입출력 모드 : 텍스트 I / O와 바이너리 I / O
* 파일 입출력 방식
  * 텍스트 I / O와 바이너라 I / O의 두 방식
    * C++ 파일 입출력 클래스(ifstream, ofstream, fstream)는 두 방식 지원
* 텍스트 I / O
  * 문자 단위로 파일에 쓰기, 파일에서 읽기
    * 문자를 기록하고, 읽은 바이트를 문자로 해석
  * 텍스트 파일에만 적용
* 바이너리 I / O
  * 바이트 단위로 파일에 쓰기, 파일에서 읽기
    * 데이터를 문자로 해석하지 말고 그대로 기록하거나 읽음
  * 텍스트 파일과 바이너리 파일 모두 입출력 가능
* 텍스트 I / O와 바이너리 I / O 입출력 시 차이점
  * 개형 문자('\n')를 다루는데 차이점 존재

#### << 연산자를 이용한 간단한 파일 출력
```CPP
ofstream fout;
// 파일 쓰기를 위한 스트림 생성

fout.open("song.txt");
// song.txt 파일 열기
// ofstream fout("song.txt"); 한 줄로 줄여 쓰기 가능

if(!fout){
 // fout 스트림의 파일 열기가 실패한 경우 파일 열기 실패를 처리하는 코드
 // 파일 열기 성공 검사로, operator !() 실행
 // if(!fout.is_open())과 동일
}

 int age = 21;
 char singer[] = "Kim";
 char song[] = "Yesterday";

 // 파일 쓰기 예시
 fout << age << "\n";
 // 파일에 21과 '\n'을 기록

 fout << singer << endl;
 // 파일에 "Kim"과 '\n'을 덧붙여 기록

 fout << song << endl;
 // 파일에 "Yesterday"와 '\n'을 덧붙여 기록
 fout.close();
 // 파일 닫기
```

![song](https://github.com/BangYunseo/TIL/blob/main/Cpp/Image/ch16/song.PNG)

* 예제 1. 키보드로 입력받은 텍스트 파일 저장 예제     
[SourceCodeChecking](https://github.com/BangYunseo/Basic_CPP/blob/main/ch16_FileIO/SavingTextFile.cpp)

* 예제 2. ifstream과 >> 연산자로 텍스트 파일 읽기 예제     
[SourceCodeChecking](https://github.com/BangYunseo/Basic_CPP/blob/main/ch16_FileIO/Ifstream%3E%3E.cpp)

## 3절. 파일 모드
#### 파일 모드(file mode)
* 파일 입출력에 대한 구체적인 작업 형태에 대한 지정
* 사례
  * 파일에서 읽을 작업을 할 것인지, 쓰기 작업을 할 것인지
  * 기존 파이르이 데이터를 모두 지우고 쓸 것인지, 파일의 끝 부분에 쓸 것인지
  * 텍스트 I / O 방식인지 바이너리 I / O 방식인지
 
#### 파일 모드 지정 : 파일 열 때
* open("파일 이름", 파일 모드)
* ifstream("파일 이름", 파일 모드)
* ofstream("파일 이름", 파일 모드)

![filemode](https://github.com/BangYunseo/TIL/blob/main/Cpp/Image/ch16/filemode.PNG)

#### 파일 모드 설정
```CPP
void open(const char* filename, ios::openmode mode);
// mode로 지정된 파일 모드로 filename의 파일을 열고 파일 모드 지정
```

* student.txt 파일에서 처음부터 읽고자 하는 경우
```CPP
// case 1
ifstream fin;
fin.open("student.txt");
```
```CPP
// case 2
ifstream fin;
fin.open("student.txt", ios::in);
```
* student.txt 파일의 끝에 데이터를 저장하는 경우
```CPP
ofstream fout;
fout.open("student.txt", ios::out | ios::app);
fout << "tel:01044447777";
// 기존의 stduent.txt 끝에 "tel:01044447777"을 추가하여 저장
```
* 바이너리 I / O로 data.bin 파일을 기록하는 경우
```CPP
fstream fbinout;
fbinout.open("data.bin", ios::out | ios:: binary);
char buf[128];
...
fbinout.write(buf, 128);
// buf에 있는 128 바이트를 파일에 기록
```

* 예제 3. get()을 이용한 텍스트 파일 읽기 예제     
[SourceCodeChecking](https://github.com/BangYunseo/Basic_CPP/blob/main/ch16_FileIO/GetFunction.cpp)

#### get()과 EOF
* 파일의 끝에서 읽기를 시도하면 get()은 EOF(-1값)를 리턴

![EOFget](https://github.com/BangYunseo/TIL/blob/main/Cpp/Image/ch16/EOFget.PNG)

#### get()으로 파일의 끝을 인지하는 방법
* 방법 1
```CPP
// case 1
while(true){
 int c = fin.get();
 // 파일에서 문자(바이트)를 읽음
 if(c == EOF){
  ...  // 파일의 끝을 만난 경우 이에 대응하는 코드 작성
  break;
  // while 루프문 탈출
 }
 else{
  // 읽은 문자(바이트) c 처리
 }
}
```
* 방법 2
```CPP
// case 2
while((c = fin.get()) != EOF){// 파일의 끝을 만나면 루프 종료
 ... // 파일에서 읽은 값 c를 처리하는 코드
}
```

#### 파일의 끝을 잘못 인지하는 코드
* EOF 값을 c에 읽어 사용한 후 다음 루프의 while 조건문에서 EOF에 도달한 사실을 알게 되기 때문에 잘못된 코드
```CPP
while(!fin.eof()){
 int c = fin.get();
 // 마지막 읽은 EOF(-1) 값이 c에 리턴
 ...  // 읽은 값 c를 처리하는 코드
}
```


* 예제 4. 텍스트 파일 연결 예제     
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

![ios](https://github.com/BangYunseo/TIL/blob/main/Cpp/Image/ch15/ios.png)

#### ios 클래스에 정의된 포맷 플래그

![iosflag](https://github.com/BangYunseo/TIL/blob/main/Cpp/Image/ch15/iosflag.png)

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

* 너비 설정 예제 1
```CPP
cout.width(10);
// 다음에 출력되는 "hello"를 10칸으로 지정

cout << "hello" << endl;
// 빈칸 5 + hello 5문자 출력

cout.width(5);
// 다음에 출력되는 12를 5칸으로 지정

cout << 12 << endl;
// 빈칸 3 + 12 2문자 출력

// 출력 예시
//      hello
//    12
```
* 너비 설정 예제 2
```CPP
cout << '%';
cout.width(10);
// 다음에 출력되는 "Korea/"만 10칸으로 지정
cout << "Korea/" << "Seoul/" << "City" << endl;

// 출력 예시
// %   Korea/Seoul/City
```
* 빈칸 채우기 예제
```CPP
cout.fill('^');
cout.width(10);
cout << "Hello" << endl;

// 출력 예시
// ^^^^^Hello
```
* 유효 숫자 자리 수 예제
```CPP
cout.precision(5);
cout << 11./3.;

// 출력 예시
// 3.6667
```

* 예제 5. width(), fill(), precision() 사용한 포맷 출력 예제     
[SourceCodeChecking](https://github.com/BangYunseo/Basic_CPP/blob/main/ch15_C%2B%2BIOSystem/WidthFillPrecision.cpp)

## 4절. 조작자
#### 조작자
* manipulator
* 스트림 조작자(stream manipulator)
* 조작자는 함수
  * C++ 표준 라이브러리에 구현된 조작자 : 입출력 포맷 지정 목적
  * 개발자만의 조작자 작성 가능 : 다양한 목적
  * 매개 변수 없는 조작자와 매개 변수를 가진 조작자로 구분
* 조작자는 항상 << 나 >> 연산자와 함께 사용

#### 조작자의 종류
* 매개 변수 없는 조작자
```CPP
cout << hex << showbase << 30 << endl;
cout << dex << showpos << 100 << endl;

// 출력 예시
// 0x1e
// +100
```
* 매개 변수 있는 조작자
  * #include <iomanip> 필요
```CPP
cout << setw(10) << setfill('^') << "Hello" << endl;

// 출력 예시
// ^^^^^Hello
```

#### 매개 변수 없는 조작자

![nohavemani](https://github.com/BangYunseo/TIL/blob/main/Cpp/Image/ch15/nohavemani.PNG)

#### 매개 변수 있는 조작자

![havemani](https://github.com/BangYunseo/TIL/blob/main/Cpp/Image/ch15/havemani.PNG)

* 예제 7. 매개 변수 없는 조작자 사용 예제     
[SourceCodeChecking](https://github.com/BangYunseo/Basic_CPP/blob/main/ch15_C%2B%2BIOSystem/NoParameterMani.cpp)

* 예제 8. 매개 변수 있는 조작자 사용 예제     
[SourceCodeChecking](https://github.com/BangYunseo/Basic_CPP/blob/main/ch15_C%2B%2BIOSystem/ParameterMani.cpp)

#### 조작자 실행 과정

![usingmani](https://github.com/BangYunseo/TIL/blob/main/Cpp/Image/ch15/usingmani.PNG)

#### 사용자 정의 조작자 함수 원형
* 매개 변수 없는 조작자
```CPP
istream& manipulatorFuncion(istream& ins);
// 입력 스트림에 사용되는 조작자 원형

ostream& maniupularFunction(ostream& outs);
// 출력 스트림에 사용되는 조작자 원형
```

* 예제 9. 사용자 정의 조작자 예제 1    
[SourceCodeChecking](https://github.com/BangYunseo/Basic_CPP/blob/main/ch15_C%2B%2BIOSystem/UserMani1.cpp)

* 예제 10. 사용자 정의 조작자 예제 2    
[SourceCodeChecking](https://github.com/BangYunseo/Basic_CPP/blob/main/ch15_C%2B%2BIOSystem/UserMani2.cpp)

## 5절. 연산자
#### 삽입 연산자(<<)
* insertion operator
* 삽입자라고 불림
  * << 연산자는 C++의 기본 연산자 : 정수 shift 연산자
* ostream 클래스에 중복 작성

```CPP
class ostream: virtual public ios{
...
public:
 ostream& operator << (int n);
 // 정수를 출력하는 << 연산자
 ostream& operator << (char c);
 // 문자를 출력하는 << 연산자
 ostream& operator << (const char* s);
 // 문자열를 출력하는 << 연산자
...
};
```

#### 삽입 연산자의 실행 과정

![usingio](https://github.com/BangYunseo/TIL/blob/main/Cpp/Image/ch15/usingio.PNG)

#### 사용자 삽입 연산자 만들기
* 개발자가 작성한 클래스의 객체에 << 연산자 출력 예제
```CPP
#include <iostream>

using namespace std;

class Point{
 int x, y;
public:
 Point(int x = 0, int y = 0){ this->x = x; this->y = y; }
 friend ostream& operator <<(ostream& stream, Point a);
};

ostream& operator <<(ostream& stream, Point a){
 stream << "(" << a.x << ", " << a.y << ")";
 return stream;
}

int main(){
 Point p(3, 4);
 // Point 객체 생성
 cout << p << endl;
 // Point 객체 화면 출력

 Point q(1, 100), r(2, 200);
 // Point 객체 생성
 cout << q << r << endl;
 // Point 객체 화면 출력
}

// 출력 예시
// (3, 4)
// (1, 100)(2, 200)
```

#### cout << p;를 위한 << 연산자 만들기

![userio](https://github.com/BangYunseo/TIL/blob/main/Cpp/Image/ch15/userio.PNG)

* 예제 11. Book 클래스 예제    
[SourceCodeChecking](https://github.com/BangYunseo/Basic_CPP/blob/main/ch15_C%2B%2BIOSystem/Book.cpp)

#### 추출 연산자(>>)
* extraction operator
  * >> 연산자는 C++의 기본 연산자 : 정수 shift 연산자
* ostream 클래스에 중복 작성
```CPP
class istream : virtual public ios{
...
public:
 istream& operator >> (int& n);
 // 정수를 입력하는 >> 연산자
 istream& operator >> (char& c);
 // 문자를 입력하는 >> 연산자
 istream& operator >> (const char* s);
 // 문자열를 입력하는 >> 연산자
...
};
```
* 추출 연산자의 실행 과정
  * 삽입 연산자의 실행 과정과 유사

#### 사용자 추출 연산자 만들기
* 개발자가 작성한 클래스의 객체에 >> 연산자 입력
```CPP
#include <iostream> 

using namespace std;

class Point { // 한 점을 표현하는 클래스 
    int x, y; // private 멤버
public:
    Point(int x = 0, int y = 0) { this->x = x; this->y = y; }
    friend istream& operator >> (istream& ins, Point &a); // friend 선언 
    friend ostream& operator << (ostream& stream, Point a); // friend 선언
};

istream& operator >> (istream& ins, Point &a){ // >> 연산자 함수
    cout << "x 좌표 >> "; 
    ins >> a.x;
    cout << "y 좌표 >> "; 
    ins >> a.y;
    return ins;
}
ostream& operator << (ostream& stream, Point a){
    stream << "(" << a.x << ", " << a.y << ")";
    return stream; 
}
int main() {
    Point p; 
    // Point 객체 생성
    cin >> p;  // >> 연산자 호출하여 x 좌표와 y 좌표를 
    cout << p;  // << 연산자 호출하여 객체 p 출력
}

// 출력 예시
// x 좌표 >> 100
// y 좌표 >> 200 
// (100,200)

// 첫 줄부터 cin >> p, cout << p 실행
```

#### cin >> p;를 위한 >> 연산자 만들기

![usereo](https://github.com/BangYunseo/TIL/blob/main/Cpp/Image/ch15/usereo.PNG)
