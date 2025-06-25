# Chapter 1. C# 개요

> 'C# 프로그래밍' 1장 학습 내용
>
> 1절. C# 개요
>
> 2절. C# 특징
>
> 3절. C# 구조

## 1절. C# 개요

### C 계열

- C++, Java로부터 영향
  - 연산자
  - 문장
  - 객체지향 속성
  - 예외처리
  - 스레드

### C# 계통도

- 언어의 뿌리 : ALGOL
- 파생 계열
  - Pascal
  - C

<img src="https://github.com/BangYunseo/TIL/blob/main/Language/C#/Image/ch01/ch01-01-Schematic.PNG" height="auto" />

### 개발 환경

#### 1. 콘솔/윈폼 어플리케이션

- 문자기반 명령어 프롬프트 환경에서 실행
- 키보드로 입력, 화면 문자로 출력

[WinForm Console 띄우기](https://maloveforme.tistory.com/286)

#### 2. C# 개발 환경

- SDK 이용
  - 편집기
  - 컴파일러
  - 실행 엔진
  - 클래스 라이브러리
- 통합개발 환경(IDE)

### C# 어플리케이션

```C#
// HelloWorld.cs : Hello, World 출력 프로그램

using System;
// 네임스페이스 : C++의 using namespace std; 와 동일

class HelloWorld
{
    public static void Main()
    {
        Console.WriteLine("Hello, World!");
        // 출력 메소드
    }
}

// 실행 결과
// Hello, World!
```

### 실행 과정

<img src="https://github.com/BangYunseo/TIL/blob/main/Language/C#/Image/ch01/ch01-02-Process.PNG" height="auto" />

#### 1. 컴파일 과정

- csc : C# 컴파일러

#### 2. 실행 시스템

- CLR(Common Language Runtime)

## 2절. C# 특징

### 클래스(Class)

### 속성(Property)

### 연산자 중복

### 델리게이트(Deligate)

### 이벤트(Event)

### 스레드(Thread)

### 제네릭(Generic)
