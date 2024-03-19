#  Chapter 3. 타입 변환
> '혼자 공부하는 자바 - 신용권' 2장 3절 학습 내용
>
> [소스코드](https://github.com/BangYunseo/SelfStudyJava/tree/main/ch03_TypeCasting)
> 
> 1절. 타입 변환
>
> 2절. 자동 타입 변환
>
> 3절. 강제 타입 변환
>
> 4절. 정리

## 1절. 타입 변환
#### 타입 변환
* 데이터 타입을 다른 데이터 타입으로 변환하는 것
* 변수 값을 다른 타입의 변수에 저장할 때 발생
```Java
byte a = 10;
// byte 타입 변수 a에 10 저장

int b = a;
// byte 타입 변수 a에 저장된 10을 int 타입 변수 b에 복사 후 저장
```

#### 자동 타입 변환(promotion)
* 값의 허용 범위가 작은 타입이 큰 타입으로 저장될 경우

![promotion](https://github.com/BangYunseo/TIL/blob/main/Language/Java/Image/ch03/promotion.PNG)

* 기본 타입의 허용 범위 순서
* byte < short < int < long < float < double
```Java
byte byteVal = 10;
int intVal = byteVal;
// 자동 타입 변환

long longVal = 5000000000L;
float floatVal = longVal;            // 5.0E9f로 저장
double doubleVal = longVal;          // 5.0E9로 저장
```

* char 타입의 경우
  * int 타입으로 자동변환되면 유니코드 값이 int 타입에 저장
```Java
char charVal = 'A';
int intVal = charVal;
// 65가 저장

byte byteVal = 65;
char charVal = byteVal;
// 컴파일 에러 발생
// Why? byte에서 char로의 변환은 손실이 있는 변환
```

* 예제 1. 자동 타입 변환 예제
[SourceCodeChecking](https://github.com/BangYunseo/SelfStudyJava/blob/main/ch03_TypeCasting/PromotionExample.java)

#### 강제 타입 변환(casting)
* 큰 허용 범위 타입을 작은 허용 범위 타입으로 강제로 나누어 한 조각만 저장

![casting](https://github.com/BangYunseo/TIL/blob/main/Language/Java/Image/ch03/casting.PNG)

* 캐스팅 연산자 괄호 () 사용
  * 괄호 안이 나누는 단위

```Java
int intVal = 10;
byte byteVal = (byte) intVal;
```

* ex 1) int 타입을 char 타입으로 강제 변환
  * 문자 출력 목적

```Java
int intVal = 65;
char charVal = (char) intVal;
System.out.println(charVal);
// 'A' 가 출력
```

* ex 2) 실수 타입을 정수 타입으로 강제 변환
  * 소수점 이하 부분은 버려지며 정수 부분만 저장

```Java
double doubleVal = 3.14;
int intVal = (int) doubleVal;
// intVal은 정수 부분 3만 저장
```

* 예제 2. 강제 타입 변환 예제
[SourceCodeChecking](https://github.com/BangYunseo/SelfStudyJava/blob/main/ch03_TypeCasting/CastingExample.java)

## 2절. 자동 타입 변환
#### 정수 타입 변수
* 정수 타입 변수가 산술 연산식에서 피연산자로 사용되는 경우
  * byte, char, short 타입 변수는 int 타입으로 자동 변환
  * 특별한 경우가 아니라면 정수 연산에 사용하는 변수는 int 타입으로 선언

![inttype](https://github.com/BangYunseo/TIL/blob/main/Language/Java/Image/ch03/inttype.PNG)

  * 피연산자 중 하나가 long 타입이면 다른 피연산자는 long 타입으로 자동 변환

![longtype](https://github.com/BangYunseo/TIL/blob/main/Language/Java/Image/ch03/longtype.PNG)

#### 실수 타입 변수
* 피연산자 중 하나가 double 타입일 경우 다른 피연산자는 double 타입으로 자동 변환

```Java
int intVal = 10;
double doubleVal = 5.5;
double res = intVal + doubleVal;            // res에 15.5가 저장
// res, intVal, doubleVal은 모두 double 값으로 변환

int intVal2 = 10;
double doubleVal2 = 5.5;
int res2 = intVal2 + (int) doubleVal2;      // res2에 15가 저장
// doubleVal2를 int형으로 강제 타입 변환
```

* 실수 리터럴 연산
```Java
double res = 1.5 + 2.3;
// double형 연산

float res2 = 1.5f + 2.3f;
// float형 연산
```

#### 정수 연산의 결과를 실수로 저장할 때 주의할 점
* 정수 연산의 결과는 정수
```Java
int x = 5;
int y = 2;
double res = x / y;
System.out.println(res);

// 출력 예시
// 2.0
// 5 / 2 는 2.5로 나타낼 수 있음에도 정수끼리의 연산 결과는 정수가 나옴
 ```

* 실수 결과를 얻으려면 실수 연산으로의 변환 필요
  * 하나의 정수 혹은 둘 모두를 (double)을 이용해서 강제 타입 변환 진행

![doubletype](https://github.com/BangYunseo/TIL/blob/main/Language/Java/Image/ch03/doubletype.PNG)

#### + 연산
* 피연산자가 모두 숫자일 경우 덧셈 연산
* 피연산자 중 하나가 문자열일 경우 나머지 피연산자도 문자열로 자동 변환
* 그 후 문자열 결합 연산

![type+](https://github.com/BangYunseo/TIL/blob/main/Language/Java/Image/ch03/type+.PNG)

* '+ 연산'은 앞에서부터 순차적으로 수행
  * 먼저 수행된 연산이 결합 연산인 경우 이후 모든 연산은 결합 연산

![type+2](https://github.com/BangYunseo/TIL/blob/main/Language/Java/Image/ch03/type+2.PNG)

## 3절. 강제 타입 변환
#### 기본 타입
* 문자열을 기본 타입으로 강제 변환

![Casting2](https://github.com/BangYunseo/TIL/blob/main/Language/Java/Image/ch03/Casting2.PNG)

* 숫자 형식 예외 발생
  * 숫자 타입 변환 시도할 경우
  * 문자열이 숫자 외 요소를 포함할 경우
 
```Java
String str = "1a";
int Val = Integer.parseInt(str);
// NumberFormatException 발생
```

* String.valueOf() 메소드를 사용하여 기본 타입을 문자열로 변환

```Java
String str = String.valueOf(3);
```

## 4절. 정리
#### 핵심 포인트 확인하기

|키워드|설명|
|:---:|:---|
|자동 타입 변환|자동으로 타입이 변환되는 것으로 값의 허용 범위가 작은 타입이 허용 범위가 큰 타입으로 저장될 때 발생|
|강제 타입 변환|강제로 타입을 변환하는 것으로 값의 허용 범위가 큰 타입을 허용 범위가 작은 타입으로 쪼개서 저장할 때 발생|
|문자열 결합 연산|문자열과 + 연산을 하면 다른 피연산자도 문자열로 변환되어 문자열 결합 발생|
|Integer.parseInt()|문자열을 정수 int 타입으로 변환|
|Double.parseDouble()|문자열을 실수 double 타입으로 변환|
