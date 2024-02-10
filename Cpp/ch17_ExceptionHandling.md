#  Chapter 17. 예외 처리   
> '명품 C++Programming - 황기태' 13장 학습 내용
>
> [소스코드](https://github.com/BangYunseo/Basic_CPP/tree/main/ch17_ExceptionHandling)
> 
> 1절. 오류 처리
>
> 2절. 예외
>
> 3절. 


## 1절. 오류 처리
#### 오류
* 컴파일 오류
  * 문법에 맞지 않는 구문으로 인한 오류
* 실행 오류
  * 개발자의 논리 오류
  * 예외적으로 발생하는 입력이나 상황에 대한 대처가 없을 때 발생하는 오류
  * 실행 오류의 결과
    * 결과가 틀리거나 엉뚱한 코드 실행
    * 프로그램이 비정상적으로 종료

* 예제 1. 예외 상황에 대한 대처가 없는 프로그램 예제     
[SourceCodeChecking](https://github.com/BangYunseo/Basic_CPP/blob/main/ch17_ExceptionHandling/GetExp.cpp)

* 예제 2. if문과 리턴을 통한 오류 처리 예제     
[SourceCodeChecking](https://github.com/BangYunseo/Basic_CPP/blob/main/ch17_ExceptionHandling/IfReturn.cpp)

* 예제 3. 리턴 값과 참조 매개 변수를 통한 오류 처리 예제     
[SourceCodeChecking](https://github.com/BangYunseo/Basic_CPP/blob/main/ch17_ExceptionHandling/RRParameter.cpp)

## 2절. 예외
#### 예외
* 실행 중에 프로그램 오동작이나 결과에 영향을 미치는 상황이 발생하는 경우
  * ex) getExp() 함수에 예상치 못하게 사용자가 음수를 입력하여 2^-3을 1로 계산한 경우
 
#### 예외 처리기
* 예외 발생을 탐지하고 예외를 처리하는 코드
  * 잘못된 결과, 비정상적인 실행, 시스템에 의한 강제 종료를 방지
  * ex) 마이크로프로세서의 인터럽트와 비슷한 역할
 
#### 예외 처리 수준
* 운영 체제 수준 예외 처리
  * 운영체제가 예외의 발생을 탐지하여 응용프로그램에게 알려주어 예외에 대처하게 하는 방식
  * 운영체제마다 서로 다르므로 운영체제나 컴파일러 별로 예외 처리 라이브러리로 작성
  * Java의 경우, JVM 혹은 라이브러리에서 탐지한 예외를 자바응용프로그램에게 전달
  * 윈도우 운영체제는 탐지한 예외를 C/C++ 응용프로그램에게 알려줌
    * 운영체제와 컴파일러에 의존적인 C++ 문법 사용
* 응용프로그램 수준 예외 처리
  * 사용자의 잘못된 입력이나 없는 파일을 여는 등 응용프로그램 수준에서 발생하는 예외를 자체적으로 탐지하고 처리하는 방법
  * C++ 예외 처리
 
#### C++ 예외 처리
* C++ 표준의 예외 처리
* 응용프로그램 수준 예외 처리


#### 피자 자동 기계외 예외 처리개념

![pizza](https://github.com/BangYunseo/TIL/blob/main/Cpp/Image/ch17/pizza.PNG)

#### 예외 처리 기본 형식(여기부터 다시 작성)
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

## 4절. 텍스트 I/O와 바이너리 I/O
#### 텍스트 파일의 라인 단위 읽기
* 두 가지 방법
  * istream의 getline(char*line, int n) 함수 이용
  * getline(ifstream& fin, string& line) 함수 이용
* 라인 단위로 텍스트 파일을 읽는 코드 2가지
  * istream의 getline() 함수 이용
```CPP
char buf[81];
// 한 라인이 최대 80개의 문자로 구성된다고 가정

ifstream fin("c:\\windows\\system.ini");
while(fin.getline(buf, 81){ // 한 라인이 최대 80개의 문자로 구성되었으며 끝에 '\0' 문자 추가
 ...   // 읽은 라인(buf[])을 활용하는 코드
}
```
  * 전역 함수 getline(ifstream& fin, string& line) 함수 이용 
```CPP
string line;
ifstream fin("c:\\windows\\system.ini");
while(getline(fin, line){ // 한 라인을 읽어 line에 저장한 후 파일 끝까지 반복
 ...   // 읽은 라인(line)을 활용하는 코드
}
```


* 예제 4 참고 이미지              
![ex4](https://github.com/BangYunseo/TIL/blob/main/Cpp/Image/ch16/ex4.PNG)

* 예제 4. 텍스트 파일 연결 예제     
[SourceCodeChecking](https://github.com/BangYunseo/Basic_CPP/blob/main/ch16_FileIO/ConnectTextFile.cpp)

* 예제 5. istream의 getline()을 이용하여 텍스트 파일을 읽고 화면에 출력하는 예제     
[SourceCodeChecking](https://github.com/BangYunseo/Basic_CPP/blob/main/ch16_FileIO/GetlineIstream.cpp)

* 예제 6. getline(ifstream&, string&)으로 words.txt 파일을 읽고 단어 검색하는 예제     
[SourceCodeChecking](https://github.com/BangYunseo/Basic_CPP/blob/main/ch16_FileIO/GetlineWord.cpp)

#### 바이너리 I/O
* 바이너리 I/O 방식
  * 데이터의 바이너리 값을 그대로 파일에 저장
  * 파일의 바이너리 값을 그래도 읽어서 변수나 버퍼에 저장
  * 텍스트 파일이든 바이너리 파일이든 바이너리 I/O로 입출력 가능
* 바이너리 I/O 모드 열기
  * ios::binary가 설정되지 않으면 디폴트가 텍스트 I/O
```CPP
ifstream fin;
fin.open("desert.jpg", ios::in | ios::binary);
// 바이너리 I/O로 파일 읽기

ofstream fout("desert.jpg", ios::out | ios::binary);    // 바이너리 I/O로 파일 쓰기
fstream fsin("desert.jpg", ios::in | ios::binary);      // 바이너리 I/O로 파일 읽기
![readingline](https://github.com/BangYunseo/TIL/blob/main/Cpp/Image/ch15/readingline.PNG)
```

* 예제 7. 바이너리 I/O로 파일 복사 예제     
[SourceCodeChecking](https://github.com/BangYunseo/Basic_CPP/blob/main/ch16_FileIO/BinaryFileCopy.cpp)

#### read()/write()로 블록 단위 파일 입출력
* get() / put()
  * 문자 혹은 바이트 단위로 파일 입출력
* read() / write()
  * 블록 단위로 파일 입출력
```CPP
istream& read(char* s, int n);
// 파일에서 최대 n개의 바이트를 배열 s에 읽으며 파일의 끝을 만나면 읽기 중단

ostream& write(char* s, int n);
// 배열 s에 있는 처음 n개의 바이트를 파일에 저장

int gcount();
// 최근에 파일에서 읽은 바이트 수 리턴
```

* 예제 8. read()로 텍스트 파일을 바이너리 I/O로 읽는 예제     
[SourceCodeChecking](https://github.com/BangYunseo/Basic_CPP/blob/main/ch16_FileIO/FuncionRead.cpp)

* 예제 9. read()/write()로 이미지 파일 복사 예제     
[SourceCodeChecking](https://github.com/BangYunseo/Basic_CPP/blob/main/ch16_FileIO/ReadWriteTulips.cpp)

* 예제 10 참고 이미지              
![ex10](https://github.com/BangYunseo/TIL/blob/main/Cpp/Image/ch16/ex10.PNG)

* 예제 10. int 배열과 double 값을 바이너리 파일에 저장하고 읽는 예제     
[SourceCodeChecking](https://github.com/BangYunseo/Basic_CPP/blob/main/ch16_FileIO/IntDoubleBinary.cpp)

#### 텍스트 I/O와 바이너리 I/O의 확실한 파이점
* 파일의 끝을 처리하는 방법에는 차이가 없음
  * 텍스트 I/O든 바이너리 I/O든 파일의 끝을 만나면 EOF 리턴
* 개행 문자 '\n'를 읽고 쓸 때 서로 다르게 작동

![textbinary](https://github.com/BangYunseo/TIL/blob/main/Cpp/Image/ch16/textbinary.PNG)

#### 텍스트 I/O와 바이너리 I/O의 실행 결과 비교

![textbinary2](https://github.com/BangYunseo/TIL/blob/main/Cpp/Image/ch16/textbinary2.PNG)

## 5절. 스트림 상태
#### 스트림 상태 검사
* 스트림 상태
  * 파일 입출력이 진행되는 동안 스트림(열어 놓은 파일)에 관한 입출력 오류 저장
    * 스트림 상태를 저장하는 멤버 변수 이용

![streamstat](https://github.com/BangYunseo/TIL/blob/main/Cpp/Image/ch16/streamstat.PNG)

#### 스트림 상태를 나타내는 비트 정보

![streambit](https://github.com/BangYunseo/TIL/blob/main/Cpp/Image/ch16/streambit.PNG)

#### 스트림 상태를 검사하는 멤버 함수

![streammem](https://github.com/BangYunseo/TIL/blob/main/Cpp/Image/ch16/streammem.PNG)

* 예제 11. 스트림 상태 검사 예제     
[SourceCodeChecking](https://github.com/BangYunseo/Basic_CPP/blob/main/ch16_FileIO/StreamState.cpp)

## 6절. 파일 포인터
#### C++ 파일 입출력 방식
* 순차 접근
  * 읽은 다음 위치에서 읽고 쓴 다음 위치에 쓰는 방식
  * 디폴트 파일 입출력 방식
* 임의 접근
  * 파일 내의 임의의 위치로 옮겨 다니면서 읽고 쓸 수 있는 방식
  * 파일 포인터를 옮겨 파일 입출력
 
#### 파일 포인터
* 파일은 연속된 바이트의 집합
* 파일 포인터
  * 파일에서 다음에 읽거나 쓸 위치를 표시하는 특별한 마크
* C++는 알려진 파일마다 두 개의 파일 포인터 유지
  * get pointer : 파일 내 다음에 읽을 위치
  * put pointer : 파일 내 다음에 쓸 위치

#### 파일 모드와 파일 포인터

![FileMP](https://github.com/BangYunseo/TIL/blob/main/Cpp/Image/ch16/FileMP.PNG)

#### 임의의 접근 방법
* 파일 포인터 제어
  * 절대 위치로 이동시키는 방법과 상대 위치로 이동시키는 두 방법

```CPP
// istream의 두 방법
istream& seekg(streampos pos);
// 정수 값으로 주어진 절대 위치 pos로 get pointer를 옮김

istream& seekg(streamoff offset, ios::seekdir seekbase);
// seekbase를 기준으로 offset만큼 떨어진 위치로 get pointer를 옮김
```
```CPP
// ostream의 두 방법
ostream& seekp(streampos pos);
// 정수 값으로 주어진 절대 위치 pos로 put pointer를 옮김

ostream& seekp(streamoff offset, ios::seekdir seekbase);
// seekbase를 기준으로 offset만큼 떨어진 위치로 put pointer를 옮김
```

```CPP
// streampos의 두 방법
streampos tellg();
// 입력 스트림의 현재 get pointer의 값 리턴

streampos tellp();
// 출력 스트림의 현재 put pointer의 값 리턴
```

![seekbase](https://github.com/BangYunseo/TIL/blob/main/Cpp/Image/ch16/seekbase.PNG)

#### seekg()에 의한 get pointer의 이동 사례

![seekg](https://github.com/BangYunseo/TIL/blob/main/Cpp/Image/ch16/seekg.PNG)

* 예제 12 참고 이미지                 
![ex12](https://github.com/BangYunseo/TIL/blob/main/Cpp/Image/ch16/ex12.PNG)

* 예제 12. 파일 크기 알아내기 예제     
[SourceCodeChecking](https://github.com/BangYunseo/Basic_CPP/blob/main/ch16_FileIO/FileSize.cpp)
