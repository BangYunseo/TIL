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
> 4절. 접근 상속 지정
>
> 5절. 생성자와 소멸자
>
> 6절. 다중 상속
>
> 7절. 가상 상속

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

![upcasting](https://github.com/BangYunseo/TIL/blob/main/Cpp/Image/ch11/upcasting.PNG)

```CPP
int main() {
 ColorPoint cp;
 ColorPoint *pDER = &cp;
 Point* pBase = pDer;
 // 업캐스팅

 pDer->set(3, 4);
 pBase->showPoint();
 pDer->setColor("Red");
 pDer->showColorPoint();
 pBase->showColorPoint();    // 컴파일 오류
}
// 출력 예시
// (3, 4)
// Red(3, 4)
```

#### 상속과 객체 포인터 : 다운 캐스팅
* 다운 캐스팅(down - casting)
  * 기본 클래스의 포인터가 파생 클래스의 포인터에 치환되는 것

![downcasting](https://github.com/BangYunseo/TIL/blob/main/Cpp/Image/ch11/downcasting.PNG)

```CPP
int main(){
 ColorPoint cp;
 ColorPoint *PDer;
 Point* pBase = &cp;
 // 업캐스팅

 pBase->set(3, 4);
 pBase->showPoint();

 pDer = (ColorPoint *)pBase;
 // 다운 캐스팅
 // 강제 타입 변환이 반드시 필요

 pDer->setColor("Red");
 pDer->showColorPoint();
 // 둘 다 정상 컴파일
}
// 출력 예시
// (3, 4)
// Red(3, 4)
```

[업 캐스팅과 다운 캐스팅 이해하기](https://lesslate.github.io/cpp/%EC%97%85-%EC%BA%90%EC%8A%A4%ED%8C%85-%EB%8B%A4%EC%9A%B4-%EC%BA%90%EC%8A%A4%ED%8C%85/)

## 4절. 접근 상속 지정
#### 접근 지정자
* private 멤버
  * 선언된 클래스 내에서만 접근 가능
  * 파생 클래스에서도 기본 클래스의 private 멤버 직접 접근 불가
* public 멤버
  * 선언된 클래스나 외부 어떤 클래스, 모든 외부 함수에 접근 허용
  * 파생 클래스에서 기본 클래스의 public 멤버 접근 가능
* protected 멤버
  * 선언된 클래스에서 접근 가능
  * 파생된 클래스에서만 접근 허용
    * 파생 클래스가 아닌 다른 클래스, 혹은 외부 함수에서는 protected 멤버 접근 불가

#### 멤버의 접근 지정에 따른 접근성

![am](https://github.com/BangYunseo/TIL/blob/main/Cpp/Image/ch11/am.PNG)

* 예제 2. protected 멤버에 대한 접근 예제     
[SourceCodeChecking](https://github.com/BangYunseo/Basic_CPP/blob/main/ch11_Inheritance/AcessProtected.cpp)


#### 상속 지정
* 상속 선언 시 public, private, protected의 3가지 중 하나 지정
* 기본 클래스 멤버의 접근 속성을 어떻게 계승할 것인지 지정
  * public : 기본 클래스의 protected, public 멤버 속성을 그대로 계승
  * private : 기본 클래스의 protected, public 멤버를 private로 계승
  * protected : 기본 클래스의 protected, public 멤버를 protected로 계승
 

#### 상속 시 접근 지정에 따른 멤버의 접근 지정 속성 변화

![ppp](https://github.com/BangYunseo/TIL/blob/main/Cpp/Image/ch11/ppp.PNG)


> 컴파일 오류 탐색 예제 3, 4, 5
(여기부터 다시 작성)
* 예제 3. private 상속 사례 예제     
[SourceCodeChecking](https://github.com/BangYunseo/Basic_CPP/blob/main/ch11_Inheritance/AcessProtected.cpp)


* 예제 4. protected 상속 사례 예제     
[SourceCodeChecking](https://github.com/BangYunseo/Basic_CPP/blob/main/ch11_Inheritance/AcessProtected.cpp)


* 예제 5. 상속이 중첨될 때 접근 지정 사례 예제     
[SourceCodeChecking](https://github.com/BangYunseo/Basic_CPP/blob/main/ch11_Inheritance/AcessProtected.cpp)


## 5절. 생성자와 소멸자
#### 상속 관계의 생성자와 소멸자
* 파생 클래스의 객체가 생성될 때
   * 파생 클래스의 생성자와 기본 클래스의 생성자가 모두 실행
   * 기본 클래스의 생성자가 먼저 실행된 후 파생 클래스의 생성자 실행  


#### 생성자 호출 관계 및 실행 순서

![con1](https://github.com/BangYunseo/TIL/blob/main/Cpp/Image/ch11/con1.PNG)


#### 소멸자의 실행 순서
* 파생 클래스의 객체가 생성될 때
  * 파생 클래스의 소멸자 먼저 실행
  * 기본 클래스의 소멸자가 나중에 실행

#### 컴파일러에 의해 묵시적으로 기본 클래스의 생성자를 선택하는 경우
* 파생 클래스의 생성자에서 기본 클래스의 기본 생성자 호출      

![basiccon](https://github.com/BangYunseo/TIL/blob/main/Cpp/Image/ch11/basiccon.PNG)


#### 기본 클래스에 기본 생성자가 없는 경우 : 컴파일 오류

![errorcon](https://github.com/BangYunseo/TIL/blob/main/Cpp/Image/ch11/errorcon.PNG)


#### 매개 변수를 가진 파생 클래스의 생성자는 묵시적으로 기본 클래스의 기본 생성자 선택
* 파생 클래스의 매개 변수를 가진 생성자가 기본 클래스의 기본 생성자를 호출               

![basiccon2](https://github.com/BangYunseo/TIL/blob/main/Cpp/Image/ch11/basiccon2.PNG)

#### 파생 클래스의 생성자에서 명시적으로 기본 클래스의 생성자 선택

![basiccon3](https://github.com/BangYunseo/TIL/blob/main/Cpp/Image/ch11/basiccon3.PNG)


#### 컴파일러의 기본 생성자 호출 코드 삽입

![con2](https://github.com/BangYunseo/TIL/blob/main/Cpp/Image/ch11/con2.PNG)


* 예제 6. TV, WideTV, SmartTV 생성자 매개 변수 전달 예제     
[SourceCodeChecking](https://github.com/BangYunseo/Basic_CPP/blob/main/ch11_Inheritance/TV.cpp)


## 6절. 다중 상속
#### 
