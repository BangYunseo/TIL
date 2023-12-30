#  Chapter 4. 객체 포인터   
> '명품 C++Programming - 황기태' 4장 학습 내용
>
> [소스코드](https://github.com/BangYunseo/Basic_CPP/tree/main/ch04_ObjectPointer)
> 
> 1절. 객체
> 
> 2절. 동적 할당
>
> 3절. 배열의 동적 할당
>
> 4절. this
>
> 5절. string


## 1절. 객체
#### 객체 포인터
* 객체에 대한 포인터
  * C언어의 포인터와 동일
  * 객체의 주소값을 가지는 변수
* 포인터로 멤버를 접근할 때
  * 객체 포인터 -> 멤버
 
```CPP
Circle donut;
double area = donut.getArea();

Circle *p;
// (1) 객체에 대한 포인터 선언

p = &donut;
// (2) 포인터에 객체 주소 저장

d = p->getArea();
// (3) 멤버 함수 호출
```  
![Pointer](https://github.com/BangYunseo/TIL/blob/main/Cpp/Image/ch4/Pointer.PNG)

* 예제 1. 객체 포인터 선언 및 활용 예제       
[SourceCodeChecking](https://github.com/BangYunseo/Basic_CPP/blob/main/ch04_ObjectPointer/ObjectPointer.cpp)

#### 객체 배열 생성 및 소멸
* 객체 배열 선언 가능
  * 기본 타입 배열 선언과 형식 동일
    * int n[3];      // 정수형 배열 선언
    * Circle c[3];   // Circle 클래스 타입 배열 선언
* 객체 배열 선언
  * (1) 객체 배열을 위한 공간 할당
  * (2) 배열의 각 원소 객체마다 생성자 실행
    * c[0]의 생성자, c[1]의 생성자, c[2]의 생성자 실행
    * 매개 변수 없는 생성자 호출
  * 매개 변수 있는 생성자를 호출할 수 없음
    * Circle circleArray[3] (5);      // 오류 발생
* 배열 소멸
  * 배열의 각 객체마다 소멸자 호출
  * 생성의 반대 순으로 소멸
    * c[2]의 소멸자, c[1]의 소멸자. c[0]의 소멸자 실행


* 예제 2. Circle 클래스 배열 선언 예제           
[SourceCodeChecking](https://github.com/BangYunseo/Basic_CPP/blob/main/ch04_ObjectPointer/CircleClassArray.cpp)

* 예제 2의 설명      
![ex4_2](https://github.com/BangYunseo/TIL/blob/main/Cpp/Image/ch4/ex4_2.PNG)


#### 객체 배열 생성 시 기본 생성자 호출      

![obcon](https://github.com/BangYunseo/TIL/blob/main/Cpp/Image/ch4/obcon.PNG)


#### 객체 배열 초기화
* 객체 배열 초기화 방법
  * 배열의 각 원소 객체 당 생성사 지정하는 방법
```CPP
Circle circleArray[3] = { Circle(10), Circle(20), Circle() };
```
  * circleArray[0] 객체가 생성될 때, 생성자 Circle(10) 호출
  * circleArray[1] 객체가 생성될 때, 생성자 Circle(20) 호출
  * circleArray[2] 객체가 생성될 때, 생성자 Circle() 호출

* 예제 3. 객체 배열 초기화 예제            
[SourceCodeChecking](https://github.com/BangYunseo/Basic_CPP/blob/main/ch04_ObjectPointer/ResetCircleClassArray.cpp)


#### 2차원 배열
* 2차원 배열 선언     
![arr2_1](https://github.com/BangYunseo/TIL/blob/main/Cpp/Image/ch4/arr2_1.PNG)

* 2차원 배열 선언과 초기화      
![arr2_2](https://github.com/BangYunseo/TIL/blob/main/Cpp/Image/ch4/arr2_2.PNG)

* 2차원 배열을 초기화하는 다른 방식     
![arr2_3](https://github.com/BangYunseo/TIL/blob/main/Cpp/Image/ch4/arr2_3.PNG)     

* 예제 4. Circle 클래스 2차원 배열 선언 예제      
[SourceCodeChecking](https://github.com/BangYunseo/Basic_CPP/blob/main/ch04_ObjectPointer/Circle2DimentionArray.cpp)

## 2절. 동적 할당
#### 동적 메모리 할당 및 변환
* 정적 할당
  * 변수 선언을 통해 필요한 메모리만 할당
    * 많은 양의 메모리는 배열 선언을 통해 할당
* 동적 할당
  * 필요한 양이 예측되지 않는 경우
  * 프로그램 작성 시 할당받을 수 없음
  * 실행 중 운영체제로부터 할당
    * 힙(heap)으로부터 할당
      * 힙은 운영체제가 소유하고 관리하는 메모리
      * 모든 프로세스가 공유할 수 있는 메모리
        * [힙에 관해 더 궁금하면 ?](https://github.com/BangYunseo/TIL/blob/main/CS/Data%20Structure/ch6_Heap.md)
* C 언어의 동적 메모리 할당
  * malloc() / free() 라이브러리 함수 사용
* C++의 동적 메모리 할당 및 반환
  * new 연산자
    * 기본 타입 메모리 할당, 배열 할당, 객체 할당, 객체 배열 할당
    * 객체의 동적 생성
      * 힙 메모리로부터 객체를 위한 메모리 할당 요청
    * 객체 할당 시 생성자 호출
  * delete 연산자
    * new로 할당받은 메모리 반환
    * 객체의 동적 소멸
      * 소멸자 호출 뒤 객체를 힙에 반환
     
          
#### new와 delete 연산자     
* C++의 기본 연산자
* new 연산자의 사용 형식
```CPP
DataType *pointervalue = new DataType;
```
* delete 연산자의 사용 형식
```CPP
delete pointervalue;
```
* new와 delete 연산자의 사용 예시
```CPP
int *pInt = new int;
// int 타입의 메모리 동적 할당

char *pChar = new char;
// char 타입의 메모리 동적 할당

Circle *pCircle = new Circle;
// Circle 타입의 메모리 동적 할당



delete pInt;
// 할당 받은 정수 공간 반환

delete pInt;
// 할당 받은 문자 공간 반환

delete pInt;
// 할당 받은 객체 공간 반환
```


#### 기본 탕비의 메모리 동적 할당 및 반환

![pointermemory](https://github.com/BangYunseo/TIL/blob/main/Cpp/Image/ch4/pointermemory.PNG)     

* 예제 5. 정수형 공간의 동적 할당 및 반환 예제      
[SourceCodeChecking](https://github.com/BangYunseo/Basic_CPP/blob/main/ch04_ObjectPointer/DynamicMemory.cpp)

#### delete 연산자 주의 사항
* 적절치 못한 포인터로 delete 하면 실행시간 오류 발생
  * 동적으로 할당받지 않는 메모리 반환 (Error)
```CPP
int n;
int *p = &n;
delete p;
// 실행 시간 오류 발생

// why ? >> 포인터 p가 가리키는 메모리는 동적으로 할당 받은 것이 아님
// 복사 생성자를 사용한 것(5장 참조)
```

 * 동일한 메모리 두 번 반환 (Error)
```CPP
int *p = new int;
delete p;       // 정상적인 메모리 반환
delete p;       // 실행 시간 오류 발생
// why ? >> 이미 반환한 메모리는 중복 반환 불가능
```


## 3절. 배열의 동적 할당
#### 배열의 동적 할당 및 반환
* new와 delete 연산자의 사용 형식
```CPP
DataType *pointervalue = new DataType[ArrayLength];
// 동적 배열 할당

delete [] pointervalue;
// 배열 반환
```

* 그림으로 이해하기
![arrpointermemory](https://github.com/BangYunseo/TIL/blob/main/Cpp/Image/ch4/arrpointermemory.PNG)     


* 예제 6. 정수형 배열의 동적 할당 및 반환 예제           
[SourceCodeChecking](https://github.com/BangYunseo/Basic_CPP/blob/main/ch04_ObjectPointer/ArrayDynamicMemory.cpp)

#### 동적 할당 메모리 초기화 유의 사항
* 동적 할당 메모리 초기화
  * 동적 할당 시 초기화
```CPP
DataType *pointervalue = new DataType(InitialValue);
```
```CPP
int *pInt = new int(20);
// 20으로 초기화된 int 타입 할당

char *pChar = new char('a');
// 'a'로 초기화된 char 타입 할당
```
  * 배열은 동적 할당 시 초기화 불가능
```CPP
int *pArray = new int[10](20);
int *pArray = new int(20)[10];
// 동적 할당하면서 초기화는 불가능하기 때문에 컴파일 오류 발생
```

* delete시 [] 생략
  * 컴파일 오류는 아니지만 비정상적인 반환
```CPP
int *p = new int[10];
delete p;
// 비정상적인 반환
// delete [] p; 가 올바른 코드

int *q = new int;
delete [] q;
// 비정상적인 반환
// delete q; 가 올바른 코드
```


#### 객체의 동적 생성 및 반환
```CPP
ClassName *pointervalue = new ClassName;
ClassName *pointervalue = new ClassName(ConstructorArgumentList);
delete pointervalue;
```

* 그림으로 이해하기
![returnobject](https://github.com/BangYunseo/TIL/blob/main/Cpp/Image/ch4/returnobject.PNG)     



* 예제 7. Circle 객체 동적 생성 및 반환 예제           
[SourceCodeChecking](https://github.com/BangYunseo/Basic_CPP/blob/main/ch04_ObjectPointer/DynamicCircle.cpp)



* 예제 8. 예제 7 응용 예제           
[SourceCodeChecking](https://github.com/BangYunseo/Basic_CPP/blob/main/ch04_ObjectPointer/DynamicCirclePlus.cpp)


#### 객체 배열의 동적 생성 및 반환
```CPP
ClassName *pointervalue = new ClassName[ArrayLength];
delete [] pointervalue;
// 포인터 변수가 가리키는 객체 배열 반환
```

* 그림으로 이해하기
![returnarrayobject](https://github.com/BangYunseo/TIL/blob/main/Cpp/Image/ch4/returnarrayobject.PNG)     


#### 객체 배열의 사용 및 배열의 반환과 소멸자
* 동적으로 생성된 배열도 보통 배열처럼 사용
```CPP
Circle *pArray = new Circle[3];
// 3개의 Circle 객체 배열 동적 생성

pArray[0].setRadius(10);
pArray[1].setRadius(20);
pArray[2].setRadius(30);
// 각각 배열 객체의 setRadius() 멤버 함수를 통해 초기화

for(int i = 0; i < 3; i++)
 cout << pArray[i].getArea() << endl;
// 배열의 i 번째 객체 getArea() 멤버 함수를 차례로 호출
```

* 포인터로 배열 접근
```CPP
pArray->setRadius(10);
// pArray는 pArray 배열의 첫 번째 주소값으로, pArray[0]과 같음

(pArray + 1)->setRadius(20);
(pArray + 2)->setRadius(30);
// 각각 배열 객체의 setRadius() 멤버 함수를 통해 초기화

for(int i = 0; i < 3; i++)
 cout << (pArray + i)->getArea() << endl;
// 배열의 i 번째 객체 getArea() 멤버 함수를 차례로 호출
```

* 배열 소멸
```CPP
delete [] pArray;
// 객체의 소멸자 실행
// 각 원소 객체의 소멸자를 별도로 실행하며 생성의 반대 순서로 소멸됨

// 출력 예시
// pArray[2] 객체의 소멸자 실행       (1)
// pArray[1] 객체의 소멸자 실행       (2)
// pArray[0] 객체의 소멸자 실행       (3)
```


* 예제 9. Circle 배열의 동적 생성 및 반환 예제           
[SourceCodeChecking](https://github.com/BangYunseo/Basic_CPP/blob/main/ch04_ObjectPointer/DynamicCirclePlus2.cpp)



* 예제 10. 예제 9 응용 예제           
[SourceCodeChecking](https://github.com/BangYunseo/Basic_CPP/blob/main/ch04_ObjectPointer/DynamicCirclePlus2%2B.cpp)



#### 메모리 할당과 메모리 누수

![memory](https://github.com/BangYunseo/TIL/blob/main/Cpp/Image/ch4/memory.PNG)     
 

## 4절. this
#### this 포인터
* this
  * 포인터의 한 종류
  * 객체 자신 포인터
  * 클래스의 멤버 함수 내에서만 사용
  * 개발자가 선언하는 변수가 아님
  * 컴파일러가 선언하는 변수
    * 멤버 함수의 컴파일러에 의해 묵시적으로 삽입 선언되는 매개 변수
```CPP
class Circle{
 int radius;
public:
 Circle() { this->radius = 1; }
 Circle(int radius) { this->radius = radius; }
 void setRadius(int radius) { this->radius = radius; }
 ...
};
```

#### this와 객체

![this](https://github.com/BangYunseo/TIL/blob/main/Cpp/Image/ch4/this.PNG)     
 

#### this가 필요한 경우
* 매개 변수의 이름과 멤버 변수의 이름이 같은 경우
![this2](https://github.com/BangYunseo/TIL/blob/main/Cpp/Image/ch4/this2.PNG)     

* 멤버 함수가 객체 자신의 주소를 리턴할 때
  * 연산자 중복 시에 필요
![this3](https://github.com/BangYunseo/TIL/blob/main/Cpp/Image/ch4/this3.PNG)     





#### this의 제약 사항
* 멤버 함수가 아닌 함수에서 this 사용 불가
  * 객체와의 관련성이 없기 때문
* static 멤버 함수에서 this 사용 불가
  * 객체가 생기기 전에 static 함수 호출이 있을 수 있기 때문


#### this 포인터의 실체
* 컴파일러에서 처리
![thiscom](https://github.com/BangYunseo/TIL/blob/main/Cpp/Image/ch4/this3com.PNG)     






## 5절. string
#### string 클래스를 이용한 문자열
* C++ 문자열
  * C-스트링
  * C++ string 클래스의 객체
* string 클래스
  * C++ 표준 라이브러리
  * <string> 헤더 파일에 선언
```CPP
#include <string>

using namespace std;
...
```
  * 가변 크기의 문자열
```CPP
string str = "I love ";
// str은 'I', ' ', 'l', 'o', 'v', 'e', ' '의 7개 문자로 구성
// 공백도 포함하는 모습 확인 가능

str.append("C++.");
// str은 "I love C++."의 문자열이 됨
// 11개의 문자
...
```
  
  * 다양한 문자열 연산을 실행하는 연산자와 멤버 함수 포함
    * 문자열 복사, 문자열 비교, 문자열 길이 등
  * 문자열, 스트링, 문자열 객체, string 객체 등으로 혼용

 
#### string 객체 생성 및 입출력(여기서부터 다시 작성)
* 문자열 생성
```CPP
#include <string>

using namespace std;
...
```
  * 가변 크기의 문자열
```CPP
string str = "I love ";
// str은 'I', ' ', 'l', 'o', 'v', 'e', ' '의 7개 문자로 구성
// 공백도 포함하는 모습 확인 가능

str.append("C++.");
// str은 "I love C++."의 문자열이 됨
// 11개의 문자
...
```
* 문자열 출력
```CPP
#include <string>

using namespace std;
...
```
  * 가변 크기의 문자열
```CPP
string str = "I love ";
// str은 'I', ' ', 'l', 'o', 'v', 'e', ' '의 7개 문자로 구성
// 공백도 포함하는 모습 확인 가능

str.append("C++.");
// str은 "I love C++."의 문자열이 됨
// 11개의 문자
...
```
* 문자열 입력
```CPP
#include <string>

using namespace std;
...
```
  * 가변 크기의 문자열
```CPP
string str = "I love ";
// str은 'I', ' ', 'l', 'o', 'v', 'e', ' '의 7개 문자로 구성
// 공백도 포함하는 모습 확인 가능

str.append("C++.");
// str은 "I love C++."의 문자열이 됨
// 11개의 문자
...
```
* 문자열 숫자 변환
```CPP
#include <string>

using namespace std;
...
```
  * 가변 크기의 문자열
```CPP
string str = "I love ";
// str은 'I', ' ', 'l', 'o', 'v', 'e', ' '의 7개 문자로 구성
// 공백도 포함하는 모습 확인 가능

str.append("C++.");
// str은 "I love C++."의 문자열이 됨
// 11개의 문자
...
```

   
#### 자동 인라인 함수

![inline2](https://github.com/BangYunseo/TIL/blob/main/Cpp/Image/ch3/inline2.PNG)      

* 클래스 선언부에 구현된 멤버 함수
  * inline으로 선언할 필요 없음
  * 컴파일러에 의해 자동으로 인라인 처리
  * 생성자 포함 모든 함수를 자동 인라인 함수로 사용 가능

## 7절. 구조체
#### C++의 구조체
* 구조체
  * 상속, 멤버, 접근 지정 등 모든 것이 클래스와 동일
  * 클래스와 유일하게 다른 점
    * 구조체의 디폴트 접근 지정 : public
    * 클래스의 디폴트 접근 지정 : private
* C++에서 구조체를 수용한 이유?
  * C 언어와의 호환성을 위해
    * C의 구조체 100% 호환하며 수용
    * C 소스를 그대로 가져다 쓰기 위해
* 구조체 객체 생성
  * struct 키워드 생략
```CPP
struct StructName{
private:
// private 멤버 선언
protected:
// protected 멤버 선언
public:
// public 멤버 선언
};
```
```CPP
structName stObj;
// C++ 구조체 객체 생성
struct stObj;
// C 구조체 객체 생성
```

#### 구조체와 클래스의 디폴트 접근 지정 비교
* 구조체는 public, 클래스는 private
![pubpri](https://github.com/BangYunseo/TIL/blob/main/Cpp/Image/ch3/pubpri.PNG)   

* 예제 8. 구조체 Circle Class 예제                
[SourceCodeChecking](https://github.com/BangYunseo/Basic_CPP/blob/main/ch03_ClassAndObject/StructCircleClass.cpp)


## 8절. 헤더
#### 올바른 C++ 클래스 작성법
* 클래스를 헤더 파일과 cpp 파일로 분리
  * 클래스마다 분리 저장
  * 클래스 선언부
    * 헤더 파일(.h)에 저장
  * 클래스 구현부
    * cpp 파일에 저장
    * 클래스가 선언된 헤더 파일 include
  * main() 등 전역 함수나 변수는 다른 cpp 파일에 분산 저장
    * 필요하면 클래스가 선언된 헤더 파일 include 
* 목적
  * 클래스 재사용
* 헤더 파일 분리 사례     

![seph](https://github.com/BangYunseo/TIL/blob/main/Cpp/Image/ch3/seph.PNG)

#### 헤더 파일의 중복 include 문제
* 중복 include를 할 때 생기는 문제     

![errorseph](https://github.com/BangYunseo/TIL/blob/main/Cpp/Image/ch3/errorseph.PNG)

* 헤더 파일의 중복 include로 인해 생기는 문제를 조건 컴파일로 해결     

![errorseph1](https://github.com/BangYunseo/TIL/blob/main/Cpp/Image/ch3/errorseph1.PNG)
![errorseph2](https://github.com/BangYunseo/TIL/blob/main/Cpp/Image/ch3/errorseph2.PNG)

* 예제 9. 헤더 파일 분리 예제                
[SourceCodeChecking](https://github.com/BangYunseo/Basic_CPP/tree/main/ch03_ClassAndObject/ExCalculator)






