#  Chapter 5. 함수와 참조   
> '명품 C++Programming - 황기태' 5장 학습 내용
>
> [소스코드](https://github.com/BangYunseo/Basic_CPP/tree/main/ch05_FunctionAndReference)
>
> 0절. 함수
> 
> 1절. 호출
> 
> 2절. 값에 의한 호출
>
> 3절. 주소에 의한 호출
>
> 4절. 객체
>
> 5절. 참조


## 0절. 함수
#### 함수의 인자 전달 방식 리뷰
* 인자 전달 방식
  * 값에 의한 호출 : call by value
    * 함수가 호출되면 매개 변수가 스택에 생성
    * 호출하는 코드에서 값을 넘겨줌
    * 호출하는 코드에서 넘어온 값이 매개 변수에 복사
  * 주소에 의한 호출 : call by address
    * 함수의 매개 변수는 포인터 타입
      * 함수가 호출되면 포인터 타입의 매개 변수가 스택에 생성
    * 호출하는 코드에서는 명시적으로 주소를 넘겨줌
      * 기본 타입 변수나 객체의 경우, 주소 전달
      * 배열의 경우, 배열의 이름
    * 호출하는 코드에서 넘어온 주소값이 매개 변수에 저장
   

## 1절. 호출
#### 값에 의한 호출과 주소에 의한 호출

![call](https://github.com/BangYunseo/TIL/blob/main/Cpp/Image/ch05/call.PNG)

#### 코드로 비교
* 값에 의한 호출

![callvalue](https://github.com/BangYunseo/TIL/blob/main/Cpp/Image/ch05/callvalue.PNG)

```CPP
void swap(int a, int b){
 int tmp;

 tmp = a;
 a = b;
 b = tmp;
}

int main(){
 int m = 2;
 int n = 9;
 swap(m, n);
 cout << m << ' ' << n;
}
// 출력 예시
// 2 9
```

* 주소에 의한 호출

![calladdress](https://github.com/BangYunseo/TIL/blob/main/Cpp/Image/ch05/calladdress.PNG)

```CPP
void swap(int *a, int *b){
 int tmp;

 tmp = *a;
 *a = *b;
 *b = tmp;
}

int main(){
 int m = 2;
 int n = 9;
 swap(&m, &n);
 cout << m << ' ' << n;
}
// 출력 예시
// 9 2
```

## 2절. 값에 의한 호출
#### '값에 의한 호출'로 객체 전달
* 함수를 호출하는 쪽에서 객체 전달
  * 객체 이름만 사용
* 함수의 매개 변수 객체 생성
  * 매개 변수 객체의 공간이 스택에 할당
  * 호출하는 쪽의 객체가 매개 변수 객체에 그대로 복사
  * 매개 변수 객체의 생성자는 호출 X
* 함수 종료
  * 매개 변수 객체의 소멸자 호출
> 매개 변수 객체의 생성자 소멸자의 비대칭 실행 구조를 가짐
* 값에 의한 호출 시 매개 변수 객체의 생성자가 실행되지 않는 이유
  * 호출되는 순간 실인자 객체 상태를 매개 변수 객체에 그대로 전달하기 때문
 

#### '값에 의한 호출' 방식으로 함수가 호출되는 과정(increase(Circle c))

![increasevalue](https://github.com/BangYunseo/TIL/blob/main/Cpp/Image/ch05/increasevalue.PNG)
 
* 예제 1. 값에 의한 호출에서 매개 변수의 생성자가 실행되지 않는 예제 예제      
[SourceCodeChecking](https://github.com/BangYunseo/Basic_CPP/blob/main/ch05_FunctionAndReference/CallValue.cpp)

#### 값에 의한 호출에서 생성자와 소멸자의 비대칭 실행

![callvalue2](https://github.com/BangYunseo/TIL/blob/main/Cpp/Image/ch05/callvalue2.PNG)

## 3절. 주소에 의한 호출
#### 함수에 객체 전달 : 주소에 의한 호출
* 함수 호출 시 객체의 주소만 전달
  * 함수의 매개 변수는 객체에 대한 포인터 변수로 선언
  * 함수 호출 시 생성자 소멸자가 실행되지 않는 구조
 
#### '주소에 의한 호출' 방식으로 함수가 호출되는 과정(increase(Circle c))

![increaseaddress](https://github.com/BangYunseo/TIL/blob/main/Cpp/Image/ch05/increaseaddress.PNG)
 
## 4절. 객체
#### 객체 치환 및 객체 리턴
* 객체 치환
  * 동일한 클래스 타입의 객체끼리 치환 가능
  * 객체의 모든 데이터가 비트 단위로 복사
  * 치환된 두 객체는 현재 내용물만 같고 독립적인 공간을 유지
```CPP
Circle c1(5);
Circle c2(30);
c1 = c2;
// c2 객체를 c1 객체에 비트 단위 복사를 진행하여 c1의 반지름이 30이 됨
```
* 객체 리턴
```CPP
Circle getCircle() {
 Circle tmp(30);
 return tmp;
 // 객체 tmp 리턴
}
Circle c;
// 현재 c는 기본 생성자를 사용하며 반지름이 1인 상태
c = getCircle();
// tmp 객체의 복사본이 c1에 치환
// 따라서 c의 반지름은 30이 됨
```

* 예제 2. 객체 리턴 예제           
[SourceCodeChecking](https://github.com/BangYunseo/Basic_CPP/blob/main/ch05_FunctionAndReference/ReturnObject.cpp)

## 5절. 참조
#### 참조란?
* 참조(reference)
  * 가리킨다는 뜻
  * 이미 존재하는 객체나 변수에 대한 별명
* 참조 활용
  * 참조 변수
  * 참조에 의한 호출
  * 참조 리턴

#### 참조 변수
* 참조 변수 선언
  * 참조자 '&' 도입
  * 이미 존재하는 변수에 대한 다른 이름(별명)을 선언
    * 참조 변수는 이름만 생성
    * 참조 변수에 새로운 공간은 할당되지 않음
    * 초기화로 지정된 기존 변수 공유
   
```CPP
int n = 2;
int &refn = n;
// 참조 변수 refn 선언
// refn은 n에 대한 별명

Circle circle;
Circle &refc = circle;
// 참조 변수 refc 선언
// refn은 circle에 대한 별명
```

#### 참조 변수 선언 및 사용 사례(여기부터 작성)

![callref](https://github.com/BangYunseo/TIL/blob/main/Cpp/Image/ch05/callref.PNG)


* 예제 3. 기본 타입 변수에 대한 참조 예제           
[SourceCodeChecking](https://github.com/BangYunseo/Basic_CPP/blob/main/ch05_FunctionAndReference/BasicTypeValueRef.cpp)


* 예제 4. 객체에 대한 참조 예제           
[SourceCodeChecking](https://github.com/BangYunseo/Basic_CPP/blob/main/ch05_FunctionAndReference/ObjectRef.cpp)


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


