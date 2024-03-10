#  Chapter 10. 연산자 중복      
> '명품 C++Programming - 황기태' 7장 학습 내용
>
> [소스코드](https://github.com/BangYunseo/Basic_CPP/tree/main/ch10_OperatorOverloadingFunction)
> 
> 1절. 연산자 중복
> 
> 2절. 이항 연산자
>
> 3절. 단항 연산자

## 1절. 연산자 중복
#### C++의 연산자 중복
* C++ 언어에서 연산자 중복 가능
  * C++ 언어에 본래부터 있던 연산자에 새로운 의미 정의
  * 높은 프로그램 가독성
  * 간결한 의미 전달
  * 다형성

#### 연산자 중복의 사례
* 정수 덧셈
```CPP
int a = 2, b = 3, c;
c = a + b;

// 결과 5
// 정수가 피연산자일 때 2와 3의 덧셈
```
* 문자열 혼합
```CPP
string a = "C", c;
c = a + "++";

// 결과 C++
// 문자열이 피연산자일 때 두 개의 문자열 혼합
```
* 색깔 혼합
```CPP
Color a(BLUE), b(RED), c;
c = a + b;

// c = VIOLET
// a, b의 두 색을 섞은 새로운 Color 객체 c
```
* 배열 결합
```CPP
SortedArray a(2, 5, 9), b(3, 7, 10), c;
c = a + b;

// c = {2, 3, 5, 7, 9, 10}
// 정렬된 두 배열을 결합(merge)한 새로운 배열 생성
```

#### 연산자 중복의 특징
* C++에 본래 있는 연산자만 중복 가능
  * 컴파일 오류 발생 예시
    * 3 %% 5
    * 6 ## 7
* 피연산자 타입이 다른 새로운 연산 정의
* 연산자는 함수 형태로 구현 : 연산자 함수(operator funcion)
* 반드시 클래스와 관계를 가짐
* 피연산자의 개수를 바꿀 수 없음
* 연산의 우선 순위 변경 안됨
* 모든 연산자가 중복 가능하지 않음

* 중복 가능한 연산자          

![OverloadingOperator](https://github.com/BangYunseo/TIL/blob/main/Language/Cpp/Image/ch10/OverloadingOperator.PNG)

* 중복 불가능한 연산자

![NotOverloadingOperator](https://github.com/BangYunseo/TIL/blob/main/Language/Cpp/Image/ch10/NotOverloadingOperator.PNG)

#### 연산자 함수
* 연산자 함수 구현 방법 2가지
  * 클래스의 멤버 함수로 구현
  * 외부 함수로 구현하고 클래스에 프렌드 함수로 선언
* 연산자 함수 형식
```CPP
ReturnType(double, int, ...) Operator(ParameterList);
```


#### +와 == 연산자의 작성 사례
* 연산자 함수 작성이 필요한 코드
```CPP
Color a(BLUE), b(RED), c;

c = a + b;
// a와 b를 더하기 위한 + 연산자 작성 필요

if(a == b){
...
// a와 b를 비교하기 위한 == 연산자 작성 필요
```

* 외부 함수로 구현되고 클래스에 프렌드로 선언되는 경우
```CPP
Color operator+(Color op1, Color op2);
bool operator==(Color op1, Color op2);
// 외부 함수

class Color{
 ...
 friend Color operator+(Color op1, Color op2);
 friend bool operator==(Color op1, Color op2);
};
```

* 클래스의 멤버 함수로 작성되는 경우
```CPP
class Color{
 ...
 Color operator+(Color op2);
 bool operator==(Color op2);
};
```

#### 2절과 3절에 예시로 사용될 클래스
```CPP
class Power{
 int kick;
 int punch;
public:
 Power(int kick = 0, int punch = 0){
  this->kick = kick;
  this->punch = punch;
 }
};
```

## 2절. 이항 연산자
#### + 연산자 중복

![op+](https://github.com/BangYunseo/TIL/blob/main/Language/Cpp/Image/ch10/op+.PNG)

* 예제 1. + 연산자 예제     
[SourceCodeChecking](https://github.com/BangYunseo/Basic_CPP/blob/main/ch10_OperatorOverloadingFunction/Operator%2B.cpp)

#### == 연산자 중복

![op==](https://github.com/BangYunseo/TIL/blob/main/Language/Cpp/Image/ch10/op==.PNG)

* 예제 2. == 연산자 예제     
[SourceCodeChecking](https://github.com/BangYunseo/Basic_CPP/blob/main/ch10_OperatorOverloadingFunction/Operator%3D%3D.cpp)

#### += 연산자 중복

![op+=](https://github.com/BangYunseo/TIL/blob/main/Language/Cpp/Image/ch10/op+=.PNG)

* 예제 3. += 연산자 예제     
[SourceCodeChecking](https://github.com/BangYunseo/Basic_CPP/blob/main/ch10_OperatorOverloadingFunction/Operator%2B%3D.cpp)

#### + 연산자(정수형 매개 변수) 중복

* 예제 4. 정수형 매개 변수를 가진 + 연산자 예제     
[SourceCodeChecking](https://github.com/BangYunseo/Basic_CPP/blob/main/ch10_OperatorOverloadingFunction/OperatorInt%2B.cpp)


## 3절. 단항 연산자
#### 단항 연산자 중복
* 단항 연산자
  * 피연산자가 하나 뿐인 연산자
    * 연산자 중복 방식은 이항 연산자의 경우와 거의 유사
  * 단항 연산자 종류
    * 전위 연산자(prefix operator)
      * !op, ~op, ++op, --op
    * 후위 연산자(postfix operator)
      * op++, op--

#### 전위 ++ 연산자 중복

![++op](https://github.com/BangYunseo/TIL/blob/main/Language/Cpp/Image/ch10/++op.PNG)


* 예제 5. 전위 ++ 연산자 예제     
[SourceCodeChecking](https://github.com/BangYunseo/Basic_CPP/blob/main/ch10_OperatorOverloadingFunction/%2B%2BOperator.cpp)


#### !연산자 중복


* 예제 6. !연산자 예제     
[SourceCodeChecking](https://github.com/BangYunseo/Basic_CPP/blob/main/ch10_OperatorOverloadingFunction/!Operator.cpp)


#### 후위 ++ 연산자 중복

![op++](https://github.com/BangYunseo/TIL/blob/main/Language/Cpp/Image/ch10/op++.PNG)


* 예제 7. 후위 ++ 연산자 예제     
[SourceCodeChecking](https://github.com/BangYunseo/Basic_CPP/blob/main/ch10_OperatorOverloadingFunction/Operator%2B%2B.cpp)


#### 2 + a 덧셈을 위한 + 연산자 함수 작성

![intop+](https://github.com/BangYunseo/TIL/blob/main/Language/Cpp/Image/ch10/intop+.PNG)


* 예제 8. 정수형 매개 변수를 가진 + 연산자 프렌드 작성 예제     
[SourceCodeChecking](https://github.com/BangYunseo/Basic_CPP/blob/main/ch10_OperatorOverloadingFunction/OperatorInt+Friend.cpp)


#### + 연산자를 외부 프렌드 함수로 구현

![friendop+](https://github.com/BangYunseo/TIL/blob/main/Language/Cpp/Image/ch10/friendop+.PNG)


* 예제 9. 객체 끼리의 덧셈을 위한 + 연산자 프렌드 작성 예제     
[SourceCodeChecking](https://github.com/BangYunseo/Basic_CPP/blob/main/ch10_OperatorOverloadingFunction/Operator%2BFriend.cpp)


#### 단항 연산자 ++를 프렌드로 작성 
* 전위 연산자
![fop+](https://github.com/BangYunseo/TIL/blob/main/Language/Cpp/Image/ch10/fop+.PNG)

* 후위 연산자
![bop+](https://github.com/BangYunseo/TIL/blob/main/Language/Cpp/Image/ch10/bop+.PNG)


* 예제 10. ++ 연산자 프렌드 작성 예제     
[SourceCodeChecking](https://github.com/BangYunseo/Basic_CPP/blob/main/ch10_OperatorOverloadingFunction/Operator%2B%2BFriend.cpp)


* 예제 11. << 연산자 작성 예제     
[SourceCodeChecking](https://github.com/BangYunseo/Basic_CPP/blob/main/ch10_OperatorOverloadingFunction/Operator%3C%3C.cpp)
