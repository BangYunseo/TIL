#  Chapter 2. 기본 타입
> '혼자 공부하는 자바 - 신용권' 2장 1절 학습 내용
>
> [소스코드](https://github.com/BangYunseo/SelfStudyJava/tree/main/ch01_Variable)
> 
> 1절. 기본 타입
>
> 2절. 정수 타입
>
> 3절. 실수 타입
>
> 4절. 논리 타입
>
> 5절. 정리

## 1절. 기본 타입
#### 타입
* 변수 타입에 따라 변수에 저장할 수 있는 값의 종류와 허용 범위 변화

#### 기본 타입(Primitive Type)
* 자바 언어는 정수, 실수, 논리값을 저장하는 총 8개의 기본 타입

![PrimitiveType](https://github.com/BangYunseo/TIL/blob/main/Language/Java/Image/ch02/PrimitiveType.PNG)

## 2절. 정수 타입
#### 정수 타입
* 메모리 사용 크기와 저장되는 값의 허용 범위는 각기 다름
      
![IntType](https://github.com/BangYunseo/TIL/blob/main/Language/Java/Image/ch02/IntType.PNG)

* 메모리

![Memory](https://github.com/BangYunseo/TIL/blob/main/Language/Java/Image/ch02/Memory.PNG)

## 2절. 변수 선언
#### 변수 선언  
* 변수 사용을 위해서 변수를 선언
  * 어떤 타입의 데이터를 저장하는가?
  * 변수 이름은 무엇인가?
         
![variable1](https://github.com/BangYunseo/TIL/blob/main/Language/Java/Image/ch01/variable1.PNG)

* 같은 타입의 변수는 콤마를 이용해 한꺼번에 선언

![variable2](https://github.com/BangYunseo/TIL/blob/main/Language/Java/Image/ch01/variable2.PNG)

#### 변수 이름
* Java에서 정한 작성 규칙

![variablename](https://github.com/BangYunseo/TIL/blob/main/Language/Java/Image/ch01/variablename.PNG)

#### 예약어
* Java에서 의미를 가지고 사용되는 단어
* 변수 이름으로 사용할 경우 컴파일 에러 발생

![variablename1](https://github.com/BangYunseo/TIL/blob/main/Language/Java/Image/ch01/variablename1.PNG)

## 3절. 변수 저장
#### 저장
* 값을 저장할 경우 대입 연산자 (=) 사용
  * 변수 선언 후 대입 연산자를 통해 오른쪽의 값을 왼쪽 변수에 저장

![variablesave](https://github.com/BangYunseo/TIL/blob/main/Language/Java/Image/ch01/variablesave.PNG)

#### 변수 초기화     
* 변수에 최초로 값이 저장될 때 메모리에 변수가 생성
  * 생성되는 변수 : 초기화
  * 생성되는 변수의 값 : 초기값

![variablereset](https://github.com/BangYunseo/TIL/blob/main/Language/Java/Image/ch01/variablereset.PNG)

* 초기화를 하지 않은 변수는 메모리에서 값을 읽을 수 없음

![variableresetno](https://github.com/BangYunseo/TIL/blob/main/Language/Java/Image/ch01/variableresetno.PNG)

* 예제 1. 변수 선언 및 초기화 예제   
[SourceCodeChecking](https://github.com/BangYunseo/SelfStudyJava/blob/main/ch01_Variable/VariableInitializationExample.java)

## 4절. 변수 사용
#### 변수 사용 
* 변수의 값을 이용해서 출력문이나 연산식을 수행

![usevariable](https://github.com/BangYunseo/TIL/blob/main/Language/Java/Image/ch01/usevariable.PNG)

* 예제 2. 변수 사용 예제   
[SourceCodeChecking](https://github.com/BangYunseo/SelfStudyJava/blob/main/ch01_Variable/VariableUseExample.java)

#### 변수 값 복사
* 변수의 값을 다른 변수에 저장

![copyvariable](https://github.com/BangYunseo/TIL/blob/main/Language/Java/Image/ch01/copyvariable.PNG)

* 예제 3. 변수 교환 예제   
[SourceCodeChecking](https://github.com/BangYunseo/SelfStudyJava/blob/main/ch01_Variable/VariableExchangeExample.java)

#### 변수 사용 범위
* 지역 변수(Local Variable)
  * 메소드 블록 내에서 선언된 변수
  * 메소드 블록 내에서만 사용되고 실행이 끝나면 자동으로 삭제
  
![localvariable](https://github.com/BangYunseo/TIL/blob/main/Language/Java/Image/ch01/localvariable.PNG)

* 지역 변수는 해당 중괄호 블록 내에서만 사용 가능

![localvariable1](https://github.com/BangYunseo/TIL/blob/main/Language/Java/Image/ch01/localvariable1.PNG)

#### 지역 변수 사용 범위 주의할 점
* 변수가 어떤 범위에서 사용될 것인지 고려하여 선언 위치를 결정
* 메소드 블록 전체에서 사용하려는 경우 메소드 블록 첫머리에 선언
* 특정 블록 내부에서만 사용하려는 경우 해당 블록 내에 선언

* 예제 4. 변수 교환 예제   
[SourceCodeChecking](https://github.com/BangYunseo/SelfStudyJava/blob/main/ch01_Variable/VariableScopeExample.java)

## 5절. 정리
#### 핵심 포인트 확인하기

|키워드|설명|
|:---:|:---|
|변수|값을 저장할 수 있는 메모리 번지에 붙인 이름으로 프로그램은 변수를 통해 메모리 번지에 값을 저장하고 읽음|
|변수 선언|변수에 어떤 타입의 데이터를 저장할 지, 변수의 이름이 무엇인지를 결정|
|변수 사용|변수의 값을 읽거나 변경하는 것으로 출력문이나 연산식 내부에서 사용되며 변수에 저장된 값을 출력하거나 연산에 사용|
|변수 사용 범위|변수는 자신이 선언된 위치에서 자신이 속한 블록 내부까지만 사용 가능|
