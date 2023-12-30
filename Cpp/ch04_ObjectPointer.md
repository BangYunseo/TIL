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
> 5절.
>
> 6절.
>
> 7절.

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
ClassName *pointervalue = new ClassName[ArrayLength];
delete [] pointervalue;
// 포인터 변수가 가리키는 객체 배열 반환
```

* 포인터로 배열 접근
```CPP
ClassName *pointervalue = new ClassName[ArrayLength];
delete [] pointervalue;
// 포인터 변수가 가리키는 객체 배열 반환
```

* 배열 소멸
```CPP
ClassName *pointervalue = new ClassName[ArrayLength];
delete [] pointervalue;
// 포인터 변수가 가리키는 객체 배열 반환
```


#### 생성자와 소멸자의 실행 순서
* 객체가 선언된 위치에 따른 분류
  * 지역 객체
    * 함수 내에 선언된 객체
    * 함수가 종료되면 소멸
  * 전역 객체
    * 함수의 바깥에 선언된 객체
    * 프로그램이 종료할 때 소멸
* 객체 생성 순서
  * 지역 객체
    * 함수가 호출되는 순간에 순서대로 생성
  * 전역 객체
    * 프로그램에 선언된 순서로 생성
* 객체 소멸 순서
  * 함수가 종료되면 지역 객체가 생성된 순서의 역순으로 소멸
  * 프로그램이 종료되면 전역 객체가 생성된 순서의 역순으로 소멸
* new를 이용하여 동적으로 생성된 객체의 경우
  * new를 실행하는 순간 객체 생성
  * delete 연산자를 실행할 때 객체 소멸     



* 예제 7. 지역 객체와 전역 객체의 생성 및 소멸 순서 예제                
[SourceCodeChecking](https://github.com/BangYunseo/Basic_CPP/blob/main/ch03_ClassAndObject/ObjectConDes.cpp)


#### 예제 7 설명
![ex7](https://github.com/BangYunseo/TIL/blob/main/Cpp/Image/ch3/ex7.PNG)

## 5절. 접근 지정자
#### 접근 지정자
* 캡슐화의 목적
  * 객체 보호 및 보안
  * C++에서 객체의 캡슐화 전략
    * 객체의 상태를 나타내는 데이터 멤버(멤버 변수)에 대한 보호
    * 중요한 멤버는 다른 클래스나 객체에서 접근할 수 없도록 보호
    * 외부와의 인터페이스를 위해서 일부 멤버는 외부에 접근 허용
* 멤버에 대한 접근 지정자 3개
  * private
    * 동일한 클래스의 멤버 함수에만 제한
  * protected
    * 클래스 자신과 상속받은 자식 클래스에만 허용
  * public
    * 모든 다른 클래스에 허용


```CPP
class Sample{
private:
// private 멤버 선언
protected:
// protected 멤버 선언
public
// public 멤버 선언
};
```

#### 중복 접근 지정과 디폴트 접근 지정
* 접근 지정의 중복       
![AM](https://github.com/BangYunseo/TIL/blob/main/Cpp/Image/ch3/AM.PNG)
* 디폴트 접근 지정 private             
![AM2](https://github.com/BangYunseo/TIL/blob/main/Cpp/Image/ch3/AM2.PNG)
* 멤버 변수의 private 지정                
![AM3](https://github.com/BangYunseo/TIL/blob/main/Cpp/Image/ch3/AM3.PNG)

* 컴파일 오류 판정해보기                 
![QuestionAM1](https://github.com/BangYunseo/TIL/blob/main/Cpp/Image/ch3/QAM1.PNG)              
![QuestionAM2](https://github.com/BangYunseo/TIL/blob/main/Cpp/Image/ch3/QAM2.PNG)

* 정답
  * (9) 생성자 PrivateAccessError()는 private의 접근 지정자로 선언되어 있으므로 main()에서 호출이 불가능
  * (11) a는 PrivateAccessError 클래스의 private 멤버이므로 main()에서 접근 불가능
  * (13) f()는 PrivateAccessError 클래스의 private 멤버이므로 main()에서 호출 불가능
* 생성자도 private로 선언할 수 있음
* 생성자를 private로 선언하는 경우 한 클래스에서 오직 하나의 객체만 생성할 수 있도록 하기 위한 것
* [singleton 패턴 이해하기](https://boycoding.tistory.com/109)

#### 함수 호출에 따른 시간 오버헤드
![function1](https://github.com/BangYunseo/TIL/blob/main/Cpp/Image/ch3/function1.PNG)
* 작은 크기의 함수를 호출하면 함수 실행 시간에 비해 호출을 위해 소요되는 부가적인 시간 오버헤드가 상대적으로 큼     

* 오버헤드의 심각한 사례
```CPP
#include <iostream>

using namespace std;

int odd(int x) {return (x % 2);}
int main(){
 int sum = 0;
 // 1에서 10000까지 홀수의 합을 계산하는 for문
 for(int i = 0; i <= 10000; i++)
  if(odd(i)) sum += i;
 cout << sum;
}

// 출력 예시
// 25000000
```
 * 위의 사례에서 odd() 함수의 코드 x%2를 계산하는 시간보다 odd() 함수 호출에 따른 오버헤드가 더 큼
 * 심지어 루프를 돌게 되면 오버헤드가 가중됨


## 6절. 인라인 함수
#### 인라인 함수
* 인라인 함수 ?
  * inline 키워드로 선언된 함수
* 인라인 함수에 대한 처리
  * 인라인 함수를 호출하는 곳에 인라인 함수 코드를 확장 삽입
    * 매크로와 유사
    * 코드 확장 후 인라인 함수는 사라짐
  * 인라인 함수 호출
    * 함수 호출에 따른 오버헤드 존재하지 않음
    * 프로그램의 실행 속도 개선
  * 컴파일러에 의해 이루어짐
* 인라인 함수의 목적
  * C++ 프로그램의 실행 속도 향상
    * 자주 호출되는 짧은 코드의 함수 호출에 대한 시간 소모 감소
    * C++에 짧은 코드의 멤버 함수가 많기 때문
   
#### 인라인 함수의 사례     

![inline1](https://github.com/BangYunseo/TIL/blob/main/Cpp/Image/ch3/inline1.PNG)      

* 인라인 제약 사항
  * inline은 컴파일러에게 주는 요구 메시지
  * 컴파일러가 판단하여 inline 요구를 수용할 지 결정
  * recursion, 긴 함수, static, 반복문, goto 문 등을 가진 함수는 수용 X
 
#### 인라인 함수 장단점 및 자동 인라인
* 장점
  * 프로그램의 실행 시간이 빨라짐
 
* 단점
  * 인라인 함수 코드의 삽입으로 컴파일된 전체 코드 크기 증가
    * 통계적으로 최대 30% 증가
    * 짧은 코드의 함수를 인라인으로 선언하는 것을 권장
   
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






