#  Chapter 6. 복사 생성자   
> '명품 C++Programming - 황기태' 5장 학습 내용
>
> [소스코드](https://github.com/BangYunseo/Basic_CPP/tree/main/ch06_CopyConstructor)
> 
> 1절. 복사
> 
> 2절. 복사 생성자
>
> 3절. 디폴트 복사 생성자



## 1절. 복사
#### 얕은 복사와 깊은 복사
 
![copy](https://github.com/BangYunseo/TIL/blob/main/Cpp/Image/ch06/copy.PNG)


#### C++에서 얕은 복사와 깊은 복사(여기부터 작성)
* 얕은 복사(shallow copy)
  * 객체 복사 시, 객체의 멤버를 1대 1로 복사
  * 객체의 멤버 변수에 동적 메모리가 할당된 경우
    * 사본은 원본 객체가 할당받은 메모리를 공유하는 문제 발생
* 깊은 복사(deep copy)
  * 객체 복사 시, 객체의 멤버를 1대 1로 복사
  * 객체의 멤버 변수에 동적 메모리가 할당된 경우
    * 사본은 원본이 가진 메모리 크기 만큼 별도로 동적 할당
    * 원본의 동적 메모리에 있는 내용을 사본에 복사
  * 완전한 형태의 복사
    * 사본과 원본은 메모리를 공유하는 문제 없음


#### C++에서 객체의 복사
```CPP
// 예제로 사용한 클래스
class Person{
 int id;
 char *name;
................
};
```

![person](https://github.com/BangYunseo/TIL/blob/main/Cpp/Image/ch06/person.PNG)


## 2절. 복사 생성자
#### 복사 생성자
* 복사 생성자(copy constructor)란?
  * 객체의 복사 생성 시 호출되는 특별한 생성자
* 특징
  * 한 클래스에 오직 한 개만 선언 가능
  * 복사 생성자는 보통 생성자와 클래스 내에 중복 선언 가
  * 모양
    * 클래스에 대한 참조 매개 변수를 가지는 독특한 생성자
* 복사 생성자 선언
```CPP
class Circle{
.....................
 Circle(Circle& c);
 // 복사 생성자 선언
.....................
};

Circle::Circle(Circle& c){
// 복사 생성자 구현
}
```  

#### 복사 생성 과정

![copycon](https://github.com/BangYunseo/TIL/blob/main/Cpp/Image/ch06/copycon.PNG)


* 예제 1. Circle의 복사 생성자와 객체 복사 예제      
[SourceCodeChecking](https://github.com/BangYunseo/Basic_CPP/blob/main/ch06_CopyConstructor/CopyObject.cpp)


## 3절. 디폴트 복사 생성자
#### 디폴트 복사 생성자
* 복사 생성자가 선언되어 있지 않는 클래스
  * 컴파일러는 자동으로 디폴트 복사 생성자 삽입

(여기서부터 작성)
          
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

 
#### string 객체 생성 및 입출력
* 문자열 생성
```CPP
string str;
// 빈 문자열을 가진 스트링 객체

string address("서울특별시 성북구 삼선동 389");
// 문자열 리터럴로 초기화

string copyAddress(address);
// 위의 스트링 객체 address를 복사한 copyAddress 생성


// C-스트링(char[] 배열)으로부터 스트링 객체 생성
char text[] = {'L', 'O', 'V', 'E', ' ', 'C', '+', '+', '\0'};
string title(text);
// "LOVE C++"의 문자열을 가진 title 생성
```
* 문자열 출력 : cout과 << 연산자 사용
```CPP
cout << address << endl;
// "서울특별시 성북구 삼선동 389"가 출력

cout << title << endl;
// "LOVE C++" 출력
```
* 문자열 입력 : cin과 >> 연산자 사용
```CPP
string name;
cin >> name;
// 공백이 입력되면 하나의 문자열로 입력된 것으로 간주
```
* 문자열 숫자 변환 : stoi() 함수 이용 (2011 C++ 표준부터)
```CPP
string s = "123";
int n = stoi(s);
// n은 정수 123
```
   
#### string 객체의 동적 생성
* new / delete를 이용하여 문자열을 동적 생성 및 반환 가능

```CPP
string *p = new string("C++");
// 스트링 객체 동적 생성

cout << *p << endl;
// "C++" 출력

p->append(" Great!");
// p가 가리키는 스트링 : C++ Great!

cout << *p << endl;
// "C++ Great!" 출력

delete p;
// 스트링 객체 반환
```

* 예제 11. string Class 문자열 생성 및 출력 예제           
[SourceCodeChecking](https://github.com/BangYunseo/Basic_CPP/blob/main/ch04_ObjectPointer/StringClass.cpp)


* 예제 12. string 배열 선언 예제           
[SourceCodeChecking](https://github.com/BangYunseo/Basic_CPP/blob/main/ch04_ObjectPointer/ArrayString.cpp)



