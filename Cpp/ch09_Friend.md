#  Chapter 9. Friend      
> '명품 C++Programming - 황기태' 7장 학습 내용
>
> [소스코드](https://github.com/BangYunseo/Basic_CPP/tree/main/ch09_Friend)
> 
> 1절. Friend

## 1절. Friend
#### C++ 프렌드
* 프렌드 함수
  * 클래스의 멤버 함수가 아닌 외부 함수
    * 전역 함수
    * 다른 클래스의 멤버 함수
  * friend 키워드로 클래스 내에 선언된 함수
    * 클래스의 모든 멤버를 접근할 수 있는 권한 부여
    * 프렌드 함수라고 부름
  * 프렌드 선언의 필요성
    * 클래스의 멤버로 선언하기에는 무리가 있고, 클래스의 모든 멤버를 자유롭게 접근할 수 있는 일부 외부 함수 작성 시에 필요


|항목|세상의 친구|프렌드 함수|
|:----:|:----------|:----------|
|존재|가족이 아니며 외부인|클래스 외부에 작성된 함수이며 멤버가 아님|
|자격|가족의 구성원으로 인정받으며 가족의 모든 살림살이에 접근 허용|클래스의 멤버 자격 부여. 클래스의 모든 멤버에 대해 접근 가능|
|선언|친구라고 소개|클래스 내에 friend 키워드로 선언|
|개수|친구의 명수에 제한 없음|프렌드 함수 개수에 제한 없음|

#### 프렌드 함수가 되는 3가지 유형
* 전역 함수
  * 클래스 외부에 선언된 전역 함수
* 다른 클래스의 멤버 함수
  * 다른 클래스의 특정 멤버 함수
* 다른 클래스 전체
  * 다른 클래스의 모든 멤버 함수

![becomefriend](https://github.com/BangYunseo/TIL/blob/main/Cpp/Image/ch09/becomefriend.PNG)

#### 프렌드 선언 3 종류
* 외부 함수 equals()를 Rect 클래스에 프렌드로 선언
```CPP
class Rect{// Rect 클래스 선언
 ...
 friend bool equals(Rect r, Rect s);
};
```
* RectManager 클래스의 equals() 멤버 함수를 Rect 클래스에 프렌드로 선언
```CPP
class Rect{// Rect 클래스 선언
 ...
 friend bool RectManager::equals(Rect r, Rect s);
};
```
* RectManager 클래스의 모든 멤버 함수를 Rect 클래스에 프렌드로 선언
```CPP
class Rect{// Rect 클래스 선언
 ...
 friend RectManager;
};
```


(여기부터 작성하기) 
* 예제 1. 프렌드 함수 예제     
[SourceCodeChecking](https://github.com/BangYunseo/Basic_CPP/blob/main/ch08_Static/UsingStaticMember.cpp)



* 예제 2. 다른 클래스의 멤버 함수를 프렌드로 선언 예제     
[SourceCodeChecking](https://github.com/BangYunseo/Basic_CPP/blob/main/ch08_Static/UsingStaticMember.cpp)



* 예제 3. 다른 클래스 전체를 프렌드로 선언 예제     
[SourceCodeChecking](https://github.com/BangYunseo/Basic_CPP/blob/main/ch08_Static/UsingStaticMember.cpp)


