#  Chapter 2. 연산자
> '혼자 공부하는 자바 - 신용권' 3장 1절 학습 내용
>
> [소스코드](https://github.com/BangYunseo/SelfStudyJava/tree/main/ch02_Operator)
> 
> 1절. 연산자와 종류
>
> 2절. 연산 방향과 우선순위
>
> 3절. 단항 | 이항 | 삼항 연산자

## 1절. 연산자와 종류
#### 연산자(Operator)와 관련 정의
* 연산자   
    * 연산에 사용되는 표시나 기호   
* 피연산자(operand)   
    * 연산자와 함께 연산되는 데이터   
* 연산식(expression)
    * 연산자와 피연산자를 사용한 연산 과정 기술

![expression](https://github.com/BangYunseo/TIL/blob/main/Language/Java/Image/ch02/expression.PNG)

#### JAVA 연산자
* 산출되는 값의 타입이 연산자별로 다름을 주의

![JavaExpression](https://github.com/BangYunseo/TIL/blob/main/Language/Java/Image/ch02/JavaExpression.PNG)

* 연산식은 반드시 하나의 값 산출
* 하나의 값이 오는 모든 자리에 연산식 사용 가능
* 변수에 연산식의 값 저장 가능  

```Java
int res = x + y;
```

* 다른 연산식의 피연산자 위치에 연산식 대입 가능

```Java
boolean result = (A + B) >= 5;
```

## 2절. 연산 방향과 우선순위
#### 연산 방향
* 우선순위에 따라 수행
    * 단항 -> 이항 -> 삼항
    * 산술 -> 비교 -> 논리 -> 대입

* 우선순위가 같은 연산자는 왼쪽에서 오른쪽 방향으로 수행

```Java
100 * 2 / 3 % 5
// 왼쪽부터 차례대로 수행
```

* 예외 : 대입 연산자
```Java
a = b = c = 10;
/* 예외의 경우 아래 순서로 실행
1) c = 10
2) b = c
3) a = b
*/
```

#### 연산 방향

![ExpressionDirection](https://github.com/BangYunseo/TIL/blob/main/Language/Java/Image/ch02/ExpressionDirection.PNG)

#### 괄호 사용
* 먼저 처리할 연산식을 괄호로 묶기

![ExpressionDirectionEX1](https://github.com/BangYunseo/TIL/blob/main/Language/Java/Image/ch02/ExpressionDirectionEX1.PNG)

#### 연산자 정리

|키워드|설명|
|:---:|:---|
|연산자|연산의 종류를 결정짓는 기호|
|피연산자|연산식에서 연산되는 데이터|
|연산 방향|연산자를 사용했을 시 연산되는 방향|
|연산 우선순위|연산자들이 복합적으로 구성되면 우선적으로 연산되는 연산자이며 순서를 임의로 정하고 싶을 경우 괄호 사용|

## 3절. 단항 | 이항 | 삼항 연산자
#### 피연산자 수에 따른 구분
|구분|종류|예시|
|:---|:---|:---|
|단항 연산자|부호, 증감 연산자|++x;|
|이항 연산자|산술, 비교, 논리 연산자|x + y;|
|삼항 연산자|조건 연산자|(sum > 90) ? "True" : "False";|

#### 부호 연산자
* boolean 타입과 char 타입을 제외한 기본 타입에 사용

![expression2](https://github.com/BangYunseo/TIL/blob/main/Language/Java/Image/ch02/expression2.PNG)

* 정수 및 실수 타입 변수 앞에 붙는 경우   

```Java
int x = -100;
int result1 = +x;
int result2 = -x;
```

* 부호 연산의 결과는 int
```Java
byte b = 100;
byte res = -b;
// 위와 같이 작성할 경우 컴파일 에러 발생
```

#### 증감 연산자
* booleaan 타입 외 모든 기본 타입 피연산자에 사용 가능

![ExpressionPlus](https://github.com/BangYunseo/TIL/blob/main/Language/Java/Image/ch02/ExpressionPlus.PNG)

* 증가 연산자(++)
    * 피연산자 값에 1을 더한 결과를 다시 피연산자에 저장

```Java
int num = 5;
++num;
// num = 6
```

* 감소 연산자(--)
    * 피연산자 값에 1을 뺀 결과를 다시 피연산자에 저장

```Java
int num = 5;
--num;
// num = 4
```

* 변수의 앞 뒤 어디에서든 사용 가능

```Java
++a; a++;
// 위는 모두 a = a + 1;로 동일

--a; a--;
// 위는 모두 a = a - 1;로 동일
```

* 다른 연산자와 함께 사용될 경우 증감 연산자 위치에 따라 결과가 달라질 수 있음을 주의

```Java
int x = 1;
int y = 1;
int res1 = ++x + 10;
int res2 = y++ + 10;
```

![ExpressionPlus2](https://github.com/BangYunseo/TIL/blob/main/Language/Java/Image/ch02/ExpressionPlus2.PNG)

#### 논리 부정 연산자
|키워드|설명|
|:---:|:---|
|System.out.println()|괄호에 주어진 매개값을 모니터로 출력 하고 개행 |
|System.out.print()|괄호에 주어진 매개값을 모니터로 출력만 하고 개행 X|
|System.out.printf()|괄호에 주어진 형식대로 출력|
|System.in.read()|키보드에서 입력된 키 코드를 읽음|
|Scanner|키보드로부터 입력된 내용을 통 문자열로 쉽게 읽기 위해서 Scanner 사용|
