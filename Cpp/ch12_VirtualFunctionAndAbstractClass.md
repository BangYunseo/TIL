#  Chapter 12. 가상 함수와 추상 클래스      
> '명품 C++Programming - 황기태' 9장 학습 내용
>
> [소스코드](https://github.com/BangYunseo/Basic_CPP/tree/main/ch12_VirtualFunctionAndAbstractClass)
> 
> 1절. 가상 함수
> 
> 2절. 오버라이딩
>
> 3절. 동적 바인딩
>
> 4절. 가상 소멸자
>
> 5절. 추상 클래스

## 1절. 가상 함수
#### 가상 함수

![vf](https://github.com/BangYunseo/TIL/blob/main/Cpp/Image/ch12/vf.PNG)            

* 예제 1. 파생 클래스에서 함수를 재정의하는 사례 예제     
[SourceCodeChecking](https://github.com/BangYunseo/Basic_CPP/blob/main/ch12_VirtualFunctionAndAbstractClass/FunctionRedefine.cpp)

* 가상 함수(virtual function)
  * virtual 키워드로 선언된 멤버 함수
  * virtual 키워드의 의미
    * 동적 바인딩 지시어
    * 컴파일러에게 함수에 대한 호출 바인딩을 실행 시간까지 미루도록 지시
```CPP
class Base{
public:
 virtual void f();
 // f()는 가상 함수
};
``` 

## 2절. 오버라이딩
#### 오버라이딩

![overriding](https://github.com/BangYunseo/TIL/blob/main/Cpp/Image/ch12/overriding.PNG)

* 함수 오버라이딩(function overriding)
  * 파생 클래스에서 기본 클래스의 가상 함수와 동일한 이름의 함수 선언
    * 기본 클래스 가상 함수의 존재감 상실
    * 파생 클래스에서 오버라이딩한 함수가 호출되도록 동적 바인딩
    * 함수 재정의
    * 다형성의 한 종류

#### 함수 재정의와 오버라이딩 사례 비교
![fror](https://github.com/BangYunseo/TIL/blob/main/Cpp/Image/ch12/fror.PNG)


#### 함수 재정의와 오버라이딩
* 가상 함수를 재정의하는 경우 : 오버라이딩
  * 동적 바인딩 발생
* 가상 함수를 재정의하지 않는 경우 : 함수 재정의
  * 컴파일 시간에 결정된 함수 단순 호출(정적 바인딩 발생)
* Java는 무조건 동적 바인딩이 일어나는 언어

![orvf](https://github.com/BangYunseo/TIL/blob/main/Cpp/Image/ch12/orvf.PNG)            

* 예제 2. 오버라이딩과 가상 함수 호출 예제     
[SourceCodeChecking](https://github.com/BangYunseo/Basic_CPP/blob/main/ch12_VirtualFunctionAndAbstractClass/OverridingVirtualFunction.cpp)


#### 오바리이딩의 목적
* 파생 클래스에서 구현할 함수 인터페이스 제공
  * 파생 클래스의 다형성
![draw](https://github.com/BangYunseo/TIL/blob/main/Cpp/Image/ch12/draw.PNG)            

* 다형성의 실현
  * draw() 가상 함수를 가진 기본 클래스 Shape
  * 오버라이딩을 통해 Circle, Rect, Line 클래스에서 자신만의 draw() 구현

## 3절. 동적 바인딩
#### 동적 바인딩
* 파생 클래스에 대해
* 기본 클래스에 대한 포인터로 가상 함수를 호출하는 경우
* 객체 내에 오버라이딩한 파생 클래스의 함수를 찾아 실행
  * 실행 중에 이루어짐
    * 실행시간 바인딩, 런타임 바인딩, 늦은 바인디

![db](https://github.com/BangYunseo/TIL/blob/main/Cpp/Image/ch12/db.PNG)

#### 오버라이딩된 함수를 호출하는 동적 바인딩

![db](https://github.com/BangYunseo/TIL/blob/main/Cpp/Image/ch12/db.PNG)

* 예제 2. == 연산자 예제     
[SourceCodeChecking](https://github.com/BangYunseo/Basic_CPP/blob/main/ch10_OperatorOverloadingFunction/Operator%3D%3D.cpp)

#### += 연산자 중복

![op+=](https://github.com/BangYunseo/TIL/blob/main/Cpp/Image/ch10/op+=.PNG)

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

![++op](https://github.com/BangYunseo/TIL/blob/main/Cpp/Image/ch10/++op.PNG)


* 예제 5. 전위 ++ 연산자 예제     
[SourceCodeChecking](https://github.com/BangYunseo/Basic_CPP/blob/main/ch10_OperatorOverloadingFunction/%2B%2BOperator.cpp)


#### !연산자 중복


* 예제 6. !연산자 예제     
[SourceCodeChecking](https://github.com/BangYunseo/Basic_CPP/blob/main/ch10_OperatorOverloadingFunction/!Operator.cpp)


#### 후위 ++ 연산자 중복

![op++](https://github.com/BangYunseo/TIL/blob/main/Cpp/Image/ch10/op++.PNG)


* 예제 7. 후위 ++ 연산자 예제     
[SourceCodeChecking](https://github.com/BangYunseo/Basic_CPP/blob/main/ch10_OperatorOverloadingFunction/Operator%2B%2B.cpp)


#### 2 + a 덧셈을 위한 + 연산자 함수 작성

![intop+](https://github.com/BangYunseo/TIL/blob/main/Cpp/Image/ch10/intop+.PNG)


* 예제 8. 정수형 매개 변수를 가진 + 연산자 프렌드 작성 예제     
[SourceCodeChecking](https://github.com/BangYunseo/Basic_CPP/blob/main/ch10_OperatorOverloadingFunction/OperatorInt+Friend.cpp)


#### + 연산자를 외부 프렌드 함수로 구현

![friendop+](https://github.com/BangYunseo/TIL/blob/main/Cpp/Image/ch10/friendop+.PNG)


* 예제 9. 객체 끼리의 덧셈을 위한 + 연산자 프렌드 작성 예제     
[SourceCodeChecking](https://github.com/BangYunseo/Basic_CPP/blob/main/ch10_OperatorOverloadingFunction/Operator%2BFriend.cpp)


#### 단항 연산자 ++를 프렌드로 작성 
* 전위 연산자
![fop+](https://github.com/BangYunseo/TIL/blob/main/Cpp/Image/ch10/fop+.PNG)

* 후위 연산자
![bop+](https://github.com/BangYunseo/TIL/blob/main/Cpp/Image/ch10/bop+.PNG)


* 예제 10. ++ 연산자 프렌드 작성 예제     
[SourceCodeChecking](https://github.com/BangYunseo/Basic_CPP/blob/main/ch10_OperatorOverloadingFunction/Operator%2B%2BFriend.cpp)


* 예제 11. << 연산자 작성 예제     
[SourceCodeChecking](https://github.com/BangYunseo/Basic_CPP/blob/main/ch10_OperatorOverloadingFunction/Operator%3C%3C.cpp)
