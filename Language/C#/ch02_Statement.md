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

(여기부터 작성)

## 4절. 제어문

## 5절. 오버플로우 검사문

## 6절. 표준 입출력

## 7절. 요약
