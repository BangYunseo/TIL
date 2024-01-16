#  Chapter 11. 상속     
> '명품 C++Programming - 황기태' 8장 학습 내용
>
> [소스코드](https://github.com/BangYunseo/Basic_CPP/tree/main/ch11_Inheritance)
> 
> 1절. 상속
> 
> 2절. 파생 클래스
>
> 3절. 업 캐스팅과 다운 캐스팅
>
> 4절. 접근 지정 상속
>
> 5절. 다중 상속
>
> 6절. 가상 상속

## 1절. 상속
#### C++의 상속
* 클래스 사이에서 상속 관계 정의
  * 객체 사이에는 상속 관계 없음
* 기본 클래스의 속성과 기능을 파생 클래스에 물려줌
  * 기본 클래스(base class)
    * 상속해주는 클래스
    * 부모 클래스
  * 파생 클래스(derived class)
    * 상속받는 클래스
    * 자식 클래스
      * 기본 클래스의 속성과 기능을 물려받음
      * 자신만의 속성과 기능을 추가하여 작성
* 기본 클래스에서 파생 클래스로 갈수록 클래스의 개념이 구체화
* 다중 상속을 통한 클래스의 재활용성 증가

#### 상속의 표현

![inim](https://github.com/BangYunseo/TIL/blob/main/Cpp/Image/ch11/inim.PNG)

#### 상속의 목적 및 장점
* 간결한 클래스 작성
  * 기본 클래스의 기능을 물려받아 파생 클래스를 간결하게 작성
* 클래스 간의 계층적 분류 및 관리의 용이
  * 상속은 클래스들의 구조적 관계 파악 용이
* 클래스 재사용과 확장을 통한 소프트웨어 생산성 향상
  * 빠른 소프트웨어 생산 필요
  * 기존에 작성한 클래스의 재사용 : 상속
    * 상속받아 새로운 기능을 확장
  * 앞으로 있을 상속에 대비한 클래스의 객체 지향적 설계 필요

#### 상속 관계로 클래스의 간결화 사례 예시

![inclass](https://github.com/BangYunseo/TIL/blob/main/Cpp/Image/ch11/inclass.PNG)

#### 상속 선언

![instudent](https://github.com/BangYunseo/TIL/blob/main/Cpp/Image/ch11/inclass.PNG)

* Student 클래스는 Person 클래스의 멤버를 물려받음
* StudentWorker 클래스는 Student의 멤버를 물려받음
  * Student가 물려받은 Person의 멤버도 함께 물려받음

 
* 예제 1. Point 클래스를 상속받는 ColorPoint 클래스 예제     
[SourceCodeChecking](https://github.com/BangYunseo/Basic_CPP/blob/main/ch11_Inheritance/ColorPoint.cpp)


## 2절. 파생 클래스
#### 파생 클래스의 객체 구성

![po](https://github.com/BangYunseo/TIL/blob/main/Cpp/Image/ch11/po.PNG)
![cpo](https://github.com/BangYunseo/TIL/blob/main/Cpp/Image/ch11/cpo.PNG)

#### 파생 클래스에서 기본 클래스 멤버 접근

![cpo2](https://github.com/BangYunseo/TIL/blob/main/Cpp/Image/ch11/cpo2.PNG)

#### 외부에서 파생 클래스 객체에 대한 접근

![cpo3](https://github.com/BangYunseo/TIL/blob/main/Cpp/Image/ch11/cpo3.PNG)

## 3절. 업 캐스팅과 다운 캐스팅
#### 상속과 객체 포인터 : 업 캐스팅
* 업 캐스팅(up - casting)
  * 파생 클래스 포인터가 기본 클래스 포인터에 치환
    * ex) 사람을 동물로 보는 것(사람은 동물 안에 속함)

(여기서부터 작성)

```CPP
int main() {
 ColorPoint cp;
}
```
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
