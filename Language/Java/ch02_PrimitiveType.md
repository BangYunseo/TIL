#  Chapter 2. 기본 타입
> '혼자 공부하는 자바 - 신용권' 2장 2절 학습 내용
>
> [소스코드](https://github.com/BangYunseo/SelfStudyJava/tree/main/ch02_PrimitiveType)
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

#### 리터럴(literal)
* 소스 코드에서 프로그래머에 의해 직접 입력된 값
* 아래의 경우 자바에서 정수로 인식

![Exchange](https://github.com/BangYunseo/TIL/blob/main/Language/Java/Image/ch02/Exchange.PNG)

* 예제 1. 10진수 변환 예제   
[SourceCodeChecking](https://github.com/BangYunseo/SelfStudyJava/blob/main/ch02_PrimitiveType/IntegerLiteralExample.java)

* 예제 2. byte 범위에 맞는 출력 예제   
[SourceCodeChecking](https://github.com/BangYunseo/SelfStudyJava/blob/main/ch02_PrimitiveType/ByteExample.java)

* 예제 3. long 범위에 맞는 출력 예제  
[SourceCodeChecking](https://github.com/BangYunseo/SelfStudyJava/blob/main/ch02_PrimitiveType/LongExample.java)

#### char 타입
* 하나의 문자를 저장하는 타입
  * ex) 'A', '한'
* 작은 따옴표로 감싼 문자 리터럴은 유니코드로 변환되어 저장
  * char 타입은 정수 타입
 
![char](https://github.com/BangYunseo/TIL/blob/main/Language/Java/Image/ch02/char.PNG)

* char는 정수 타입이므로 10진수 또는 16진수 형태의 유니코드 저장 가능

![char2](https://github.com/BangYunseo/TIL/blob/main/Language/Java/Image/ch02/char2.PNG)

* 예제 4. char 타입 예제   
[SourceCodeChecking](https://github.com/BangYunseo/SelfStudyJava/blob/main/ch02_PrimitiveType/CharExample.java)

#### 문자열
* 큰따옴표로 감싼 문자들
* 문자열은 char 타입이 아닌 String 타입에 저장

![string](https://github.com/BangYunseo/TIL/blob/main/Language/Java/Image/ch02/string.PNG)

* 예제 5. String 타입 예제   
[SourceCodeChecking](https://github.com/BangYunseo/SelfStudyJava/blob/main/ch02_PrimitiveType/StringExample.java)

#### 이스케이프 문자(escape)
* 문자열 내부의 '\'를 의미
* 이스케이프 문자를 통해 특정 문자를 포함시키거나, 문자열의 출력 제어 가능

* 예시 1) 문자열 내부에 " 문자 포함

![escape](https://github.com/BangYunseo/TIL/blob/main/Language/Java/Image/ch02/escape.PNG)

* 예시 2) 문자열 출력 제어

![escape2](https://github.com/BangYunseo/TIL/blob/main/Language/Java/Image/ch02/escape2.PNG)

#### 이스케이프 문자 종류

|이스케이프 문자|출력 용도|
|:---:|:---:|
|\t|탭만큼 띄움|
|\n|줄 바꿈(라인 피드)|
|\r|캐리지리턴|
|\"|" 출력|
|\'|' 출력|
|\u16진수|16진수 유니코드에 해당하는 문자 출력|
* '\\\\\' 을 통해 \를 출력 가능

## 3절. 실수 타입
#### 실수 타입

![fd](https://github.com/BangYunseo/TIL/blob/main/Language/Java/Image/ch02/fd.PNG)

#### 실수 리터럴
* 소스 코드에서 소수점 있는 리터럴은 10진수 실수로 인식
> 0.25, -3.14

* 알파벳 e 또는 E가 포함된 숫자 리터럴은 지수 및 가수로 표현된 소수점 있는 10진수 실수로 인식

![fd2](https://github.com/BangYunseo/TIL/blob/main/Language/Java/Image/ch02/fd2.PNG)

#### double 타입
* double 타입 변수에 저장
  * Java는 실수 리터럴을 기본적으로 double 타입으로 해석

![double](https://github.com/BangYunseo/TIL/blob/main/Language/Java/Image/ch02/double.PNG)

#### float 타입
* float 타입 변수에 저장
  * 리터럴 뒤 f 혹은 F를 붙여 float 타입 표시

![float](https://github.com/BangYunseo/TIL/blob/main/Language/Java/Image/ch02/float.PNG)

#### 실수 타입의 범위
* double 타입이 float 타입보다 2배 가량 정밀도 높아 정확한 데이터 저장 가능
  * float : 소수점 이하자리 약 7 (6 ~ 9)
    > 0.12345679
  * double : 소수점 이하자리 약 15 (15 ~ 18)
    > 0.1234567890123457

## 4절. 논리 타입
#### 논리 타입
* 참과 거짓에 해당하는 true와 false 리터럴을 저장하는 타입
```Java
boolean stop = true;
boolean state = false;
```
* 두 가지 상태값에 따라 제어문의 실행 흐름을 변경할 때 사용

## 5절. 정리
#### 핵심 포인트 확인하기

|키워드|설명|
|:---:|:---|
|정수 타입|정수를 저장할 수 있는 byte, short, int, long과 같은 타입|
|char 타입|작은따옴표(')로 감싼 하나의 문자 리터럴을 저장하는 타입|
|String 타입|큰따옴표(")로 감싼 문자열을 저장하는 타입|
|실수 타입|실수를 저장할 수 있는 float, double와 같은 타입|
|boolean 타입|참과 거짓을 의미하는 true와 false를 저장할 수 있는 타입|
