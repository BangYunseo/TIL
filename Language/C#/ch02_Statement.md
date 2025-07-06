# Chapter 2. 문장(Statement)

> 'C# 프로그래밍' 2장 학습 내용
>
> 1절. 문장 종류
>
> 2절. 배정문
>
> 3절. 혼합문
>
> 4절. 제어문
>
> 5절. 오버플로우 검사문
>
> 6절. 표준 입출력
>
> 7절. 요약

## 1절. 문장 종류

### C# 문장(Statement)

<img src="https://github.com/BangYunseo/TIL/blob/main/Language/C%23/Image/ch02/2-1-StatementType.PNG" height="auto" />

## 2절. 배정문

### 정의

- 값을 변수에 저장할 경우 사용

### 형태

```C#
// 변수 할당 예시

remainder = dividend % divisor;
i = j = k = 0;
var op = exp;
```

1. <변수> = <식>;

   - C언어와 동일한 형태

2. a = b = exp;

   - 좌측 부분이 여러 번 할당될 경우 exp 먼저 연산
   - 그 후 b에 할당하고 다시 b 값이 a에 할당

3. 초깃값 할당
   - 변수 초깃값 할당 시 유용

### 형 변환

```C#
// Program.cs : Program의 형 변환 구현 프로그램

using System;

namespace App {
    class Program {
        static void Main(string[] args) {
            short s;
            int i;
            float f;
            double d;

            s = 526;
            d = f = i = s;

            Console.WriteLine("s = " + s + " i = " + i);
            Console.WriteLine("f = " + f + " d = " + d);
        }
    }
}

```

1. 묵시적 형 변환

   - 컴파일러에 의해 자동 변환

2. 명시적 형 변환
   - 프로그래머가 캐스트(Cast) 연산자 사용 후 변형

## 3절. 혼합문

### 정의

- 여러 문장을 묶어 하나의 문장으로 표현할 경우 사용
- 문장의 범위 표현

### 형태

- {<선언> or <문장>}

```C#
// Program.cs : Program의 혼합문 구현 프로그램

using System;

class Program {
   static int x;
   // 지역 변수 선언

   static void Main() {
      int x = (Program.x = 2) * 2;
      // 클래스 지역변수 선언과 연산 동시 실행

      Console.WriteLine("static x = " + Program.x);
      Console.WriteLine("local x = " + x);
   }
}

// 출력 결과
// static x = 2
// local x = 4
```

### 지역 변수(Local Variable)

- 블록 내부에서 선언된 변수
- 선언된 블록 안에서만 참조 가능

## 4절. 제어문

### 정의

- 프로그램 실행 순서 변경 시 사용

### 실행 순서 제어 방법

1. 조건문

   - if 문
   - switch 문

2. 반복문

   - for 문
   - while 문
   - do-while 문
   - foreach 문

3. 분기문

   - break 문
   - continue 문
   - return 문
   - goto 문

### 조건문

- 주어진 조건에 따라 수행되는 부분이 다를 경우 사용

#### if 문

```C#
if(조건식)
{
   <문장 1>
}
else if(조건식)
{
   <문장 2>
}
else
{
   <문장 3>
}
```

#### switch 문

```C#
switch(식)
{
   case <상수식 1> :
      <문장 1>
      break;
   case <상수식 2> :
      <문장 2>
      break;
   // ...(생략)

   case <상수식 n> :
      <문장 n>
      break;
   default :
      <문장>
      break;
}
```

- default == otherwise
  - 즉, 상수식에 해당하지 않을 경우 무조건 실행
- 반드시 <strong>break</strong> 문을 사용해 탈출
  - 단, C / C++은 상관 X

#### if 문 vs switch 문

|   종류    | 실행                                                                  |
| :-------: | :-------------------------------------------------------------------- |
|   if 문   | 조건식의 결과에 따라 참일 때 실행할 부분과 거짓일 때 실행할 부분 존재 |
| switch 문 | 조건에 따라 여러 경우로 나누어 각각을 처리하는 부분 존재              |

### 반복문

- 프로그램의 일정 부분을 주어진 조건이 만족할 때까지 반복 후 실행

#### for 문

- 정해진 횟수만큼 일련의 문장을 반복 실행
  - 가장 대중적인 사용

<img src="https://github.com/BangYunseo/TIL/blob/main/Language/C%23/Image/ch02/2-2-ForProcess.PNG" height="auto" />

```C#
for(식 1; 식 2; 식 3)
{
   <문장 1>
}
```

> 식 1 : 제어 변수 초기화  
> 식 2 : 제어 변수 검사 조건식  
> 식 3 : 제어 변수 값 수정  
> 문장 : 루프의 몸체이며 식 2의 조건식이 참인 동안 반복 실행

#### 무한 루프 for 문

```C#
for ( ; ; )
{
   문장
}
```

- 루프 종료
  - break 문
  - return ans

#### 내포된 for 문

```C#
for(int i = 0; i < N; i++)
{
   for(int j = 0; j < M; j++)
   {
      matrix[i, j] = 0;
   }
}
```

- for 문 안에 for 문 형태
  - 다차원 배열 취급 시 사용

### while 문

- 주어진 조건식이 참인 경우에만 프로그램의 일정 부분 반복 실행

<img src="https://github.com/BangYunseo/TIL/blob/main/Language/C%23/Image/ch02/2-3-WhileProcess.PNG" height="auto" />

```C#
while(조건식)
{
   문장
}
```

#### for 문 vs while 문

```C#
// for 문 : 주어진 횟수
for(int i = 0; i < N; i++)
{
   s += i;
}
```

```C#
// while 문 : 주어진 조건
int i = 0;
while(i < N)
{
   s += i;
   i++;
}
```

### do-while 문

- 반복 문장 먼저 한 번 실행 후 조건식 검사

  - 참일 경우 계속 반복
  - 거짓일 경우 반복 종료

- 조건식이 거짓이라도 <\문장> 부분은 적어도 한 번 실행

```C#
do
   <문장>
while(조건식);
```

- precondition check => for 문, while 문
- postcondition check => do-while 문

#### foreach 문

- 조건식을 검사하는 반복문과 달리 데이터 집합에 대한 반복 수행
- 데이터 집합 구성 원소를 순차적으로 처리할 때 사용

```C#
foreach (string s in color)
{
   Console.WriteLine(s);
}
```

### 분기문

- 지정된 곳으로 제어를 옮기는 역할

#### break 문

- 반복문에서 현재 실행을 멈추고 블록 밖으로 제어를 옮기는 역할

```C#
int i = 1;
while(true)
{
   if(i == 3)
   {
      break;
   }
   Console.WriteLine("This is a " + i + " iteration.");
   ++i;
}
```

#### continue 문

- 다음 반복이 시작되는 곳으로 제어 위치 변환

```C#
for(int i = 0; i <= 5; i++)
{
   if(i % 2 == 0)
   {
      continue;
   }
   Console.WriteLine("This is a " + i + " iteration.");
}
```

#### goto 문

- 지정 위치로 제어 흐름 변경

```C#
goto label;
// 레이블(label)
// : 지정된 위치를 나타내기 위한 방법 명칭 형태

goto case constant-expression;
goto default;
```

- goto 문이 분기할 수 없는 경우
  - 외부에서 복합문 안으로 분기
  - 메소드 내에서 외부로 분기
  - finally 블록에서 블록 밖으로 분기

#### return 문

- 메소드 실행 종료 후 호출한 메소드(caller)에게 제어를 넘기는 형태

```C#
return ;
// 제어만 넘겨준 형태

return <식>;
// 반환값과 함께 제어를 넘겨준 형태
```

## 5절. 오버플로우 검사문

### 오버플로우

- 정수식 연산 결과가 정수형 표현 범위를 넘은 경우
- 잘못된 계산 결과 초래 가능성 존재
- 정수식에서 오버플로우 발생을 명시적으로 검사 후 처리

#### checkeed 문

- 오버플로우 명시적 검사 문장
  - System 네임스페이스의 OverflowException 예외 발생

```C#
checked
{
   // 오버플로우 발생 확인 문장
}
// 일반적인 checked 문

checked (오버플로우 발생 확인 수식)
// 수식인 checked 문
```

#### unchecked 문

- 오버플로우를 의도적으로 검사하지 않는 경우

```C#
unchecked
{
   // 오버플로우를 의도적으로 검사하지 않는 문장
}
```

## 6절. 표준 입출력

### 입출력

- 입력과 출력

| 종류 | 설명                                                 |
| :--: | :--------------------------------------------------- |
| 입력 | 외부 입력 장치로부터 데이터를 프로그램으로 읽는 행위 |
| 출력 | 프로그램 상의 어떤 값을 출력 장치로 내보내는 행위    |

### 입출력문

- 입출력 장치가 미리 정해진 입출력 의미
- C# 언어의 기본 네임스페이스인 system 으로부터 제공

#### 표준 입력 메소드

- Console.Read()

  - 키보드에서 한 개의 문자 읽기
  - 문자 코드값을 정수형으로 반환

- Console.ReadLine()

  - 한 라인을 읽어 string 형으로 반환
  - 정수 숫자값으로 변경할 경우 int.Parse() 메소드 사용

#### 표준 출력 메소드

- Console.Write()

  - 화면에 매개 변수의 값 출력

- Console.WriteLine()

  - 화면에 매개 변수 값 출력 후 다음 라인으로 출력 위치 이동

### 입출력문 C# 구현

```C#
// ReadLineApp.cs : ReadLineApp의 입출력문 구현 프로그램

using System;
using System.Text;
// 한국어 인코딩 라이브러리

class ReadLineApp {
   public static void Main() {
      Console.OutputEncoding = Encoding.UTF8;
        // 한국어 출력 설정

      int time;
      int H, M, S;

      Console.WriteLine("*** 시간을 입력해주세요 : ");
      time = int.Parse(Console.ReadLine());
      // 시간 입력

      H = time / 10000;
      M = time / 100 % 100;
      S = time % 100;
      // 시간 계산

      Console.WriteLine("*** 현재 시각은 " + H + ":" + M + ":" + S ":" + "입니다.");
   }
}

// 출력 결과
// *** 시간을 입력해주세요 : 102030
// 현재 시각은 10:20:30 입니다.
```

### 형식화 출력

- 출력하려는 값에 형식을 명시해 원하는 형태로 출력

```C#
{N[,W][:formatCharacter]}
```

> N : 매개 변수를 위치적으로 지칭하는 정수(0부터 시작)  
> W : 출력 자릿수의 폭을 나타내며 선택적 명시 / '-' 기호를 붙일 경우 좌측 정렬로 출력  
> formatCharacter : 한 문자로 이루어진 형식 지정 문자

- 형식 지정 스트링
  - 매개 변수 개수와 일치하는 출력 포맷

#### 표준 형식 지정 문자

| 형식 지정자 | 설명                                                                     |
| :---------: | :----------------------------------------------------------------------- |
|  C 또는 c   | 통화 표시                                                                |
|  D 또는 d   | 10진수 형태(정수형만 가능)                                               |
|  E 또는 e   | 지수 형태                                                                |
|  F 또는 f   | 고정 소수점 형태                                                         |
|  G 또는 g   | 고정 소수점 또는 지수 형태 중 간략한 형태 선택                           |
|  N 또는 n   | 10진수(자릿수 구분을 위한 ',' 포함)                                      |
|  P 또는 p   | 백분율('%' 포함)                                                         |
|  R 또는 r   | 결과 스트링을 다시 읽었을 때, 원 값과 동일함 보장 (부동소수점 수만 가능) |
|  X 또는 x   | 16진수(정수형만 가능)                                                    |

#### C# 구현

```C#
// FormattedOutputApp.cs : FormattedOutputApp의 형식화된 출력 구현 프로그램

using System;

class FormattedOutputApp {
   public static void Main() {
      Console.WriteLine(" 1) {0, -5}, {1, 5}, {2, 5}", 1.2, 1.2, 123.45);

      double d = Math.PI;
      // 변수 d에 PI 값 저장

      Console.WriteLine(" 2) {0}", d);
      Console.WriteLine(" 3) {0:C}", d);
      Console.WriteLine(" 4) {0:E}", d);
      Console.WriteLine(" 5) {0:F}", d);
      Console.WriteLine(" 6) {0:G}", d);
      Console.WriteLine(" 7) {0:P}", d);
      Console.WriteLine(" 8) {0:R}", d);
      Console.WriteLine(" 9) {0:X}", 255);
   }
}

// 출력 결과
//  1) 1.2  ,   1.2, 123.45
//  2) 3.14159265358979
//  3) ?3.14
//  4) 3.141593E+000
//  5) 3.14
//  6) 3.14159265358979
//  7) 314.16 %
//  8) 3.1415926535897931
//  9) FF
```

## 7절. 요약

### 문장 종류

- 배정문
- 혼합문
- 제어문
- 오버플로우 검사문
- 표준 입출력문
- 리소스문
- 동기화문
- 예외처리문

### 배정문

- 가장 기본적인 문장
- 새롭게 계산된 값을 변수에 저장할 때 사용

### 혼합문

- 여러 문장을 묶어 하나의 문장으로 나타낼 때 사용

### 제어문

- 프로그램 실행 순서 전환 시 사용
- 실행 순서 제어 방법
  - 조건문
  - 반복문
  - 분기문

#### 조건문

- 주어진 조건에 따라 수행되는 내용이 다를 때 사용
- 종류
  - if 문
  - switch 문

#### 반복문

- 정해진 횟수만큼 또는 주어진 조건이 만족하는 동안 반복해서 실행할 때 사용
- 종류
  - for 문
  - while 문
  - do-while 문
  - foreach 문

#### 분기문

- 제어를 지정된 곳으로 옮길 때 사용
- 종류
  - break 문
  - continue 문
  - return 문
  - goto 문

### 오버플로우

- 정수식 연산 결과가 정수형의 표현 가능 범위를 넘어선 경우

### 오버플로우 검사문

- 오버플로우를 명시적으로 검사하는 문장

### 입출력문

- 입출력 장치가 미리 정해진 문장
- C# 언어의 기본 네임 스페이스, System으로부터 제공

### 표준 입력 메소드

- Console.Read()
- Console.ReadLine()

### 표준 출력 메소드

- Console.Write()
- Console.WriteLine()
