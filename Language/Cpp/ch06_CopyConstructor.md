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
 
![copy](https://github.com/BangYunseo/TIL/blob/main/Language/Cpp/Image/ch06/copy.PNG)


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

![person](https://github.com/BangYunseo/TIL/blob/main/Language/Cpp/Image/ch06/person.PNG)


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

![copycon](https://github.com/BangYunseo/TIL/blob/main/Language/Cpp/Image/ch06/copycon.PNG)


* 예제 1. Circle의 복사 생성자와 객체 복사 예제      
[SourceCodeChecking](https://github.com/BangYunseo/Basic_CPP/blob/main/ch06_CopyConstructor/CopyObject.cpp)


## 3절. 디폴트 복사 생성자
#### 디폴트 복사 생성자
* 복사 생성자가 선언되어 있지 않는 클래스
  * 컴파일러는 자동으로 디폴트 복사 생성자 삽입

![circle2](https://github.com/BangYunseo/TIL/blob/main/Language/Cpp/Image/ch06/circle2.PNG)

        
#### 디폴트 복사 생성자 사례

![exdefault](https://github.com/BangYunseo/TIL/blob/main/Language/Cpp/Image/ch06/exdefault.PNG)


* 예제 2. 얕은 복사 생성자의 프로그램의 오류를 가진 Person Class 예제           
[SourceCodeChecking](https://github.com/BangYunseo/Basic_CPP/blob/main/ch06_CopyConstructor/PersonClass.cpp)

#### 예제 2의 실행과정

![howex2](https://github.com/BangYunseo/TIL/blob/main/Language/Cpp/Image/ch06/howex2.PNG)

![howex3](https://github.com/BangYunseo/TIL/blob/main/Language/Cpp/Image/ch06/howex3.PNG)


* 예제 3. 깊은 복사 생성자를 가진 Person Class 예제          
[SourceCodeChecking](https://github.com/BangYunseo/Basic_CPP/blob/main/ch06_CopyConstructor/DeepPersonClass.cpp)


#### 예제 3의 실행과정

![howex2](https://github.com/BangYunseo/TIL/blob/main/Language/Cpp/Image/ch06/howex2.PNG)

![howex3](https://github.com/BangYunseo/TIL/blob/main/Language/Cpp/Image/ch06/howex3.PNG)



* 예제 4. 깊은 복사 생성자를 가진 Person Class 예제           
[SourceCodeChecking](https://github.com/BangYunseo/Basic_CPP/blob/main/ch06_CopyConstructor/CallCopyConstructor.cpp)

