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

- 클래스와 객체
- 객체 자료형(클래스)
- 클래스 멤버
- 개체 속성(필드) 및 행위(메소드) 결정

#### C# 구현

```C#
// CoffeeMaker.cs : CoffeeMaker 클래스 구조 프로그램

class CoffeeMaker
{
    public bool onState;
    // 속성(Property)

    public void StartCoffeeMaker(){
        if(onState == true)
        {
            Console.WriteLine("커피메이커 ON");
        }
        else
        {
            onState = true;
        }
        Console.WriteLine("커피메이커 전원을 켰습니다.");
    }
    // 행위(Method)
}
```

### 속성(Property)

- 클래스 private 필드를 형식적으로 다루는 일종의 메소드

|    종류    | 호출                      |
| :--------: | :------------------------ |
| set 접근자 | 배정문 왼쪽에서 사용 시   |
| get 접근자 | 배정문 오른쪽에서 사용 시 |

#### C# 구현

```C#
// Hello.cs : Hello의 get, set 접근자 구현 프로그램
using System;
using System.Text;
// 한국어 인코딩 라이브러리

class Hello
{
    private string hello;
    // 속성(Property) : private

    public string helloPrinter
    {
        get { return hello; }
        // get 접근자

        set { hello = value; }
        // set 접근자 : value 키워드 사용
    }

    public static void Main()
    {
        Console.OutputEncoding = Encoding.UTF8;
        // 한국어 인코딩(UTF8)

        var greet = new Hello();

        greet.helloPrinter = "안녕하세요, 반갑습니다!";
        // set 접근자 사용

        Console.WriteLine(greet.helloPrinter);
        // get 접근자 사용
    }
    // 행위(Method)
}
```

### 연산자 중복(Operator OverLoading)

- 시스템 제공 연산자 재정의
- 클래스만을 위한 연산자
- 자료 추상화 가능
- 문법적 규칙 변경 불가
  - 연산 순위
  - 결합 법칙

#### C# 구현

```C#
// User.cs : User의 연산자 중복 구현 프로그램
using System;

class User
{
    public string name { get; set; }
    public int age { get; set; }
    // 클래스 속성

    public User(string name, int age)
    {
        this.name = name;
        this.age = age;
    }
    // 생성자

    static public bool operator ==(User u1, User u2)
    {
        return u1.name == u2.name && u1.age == u2.age;
    }
    // == 연산자 오버로딩

    static public bool operator !=(User u1, User u2)
    {
        return u1.name != u2.name || u1.age != u2.age;
    }
    // != 연산자 오버로딩

    static public int operator +(User u1, User u2)
    {
        return u1.age + u2.age;
    }
    // + 연산자 오버로딩

    static void Main()
    {
        User u1 = new User("Bang", 23);
        User u2 = new User("Lee", 27);
        User u3 = new User("Kim", 64);
        User u4 = new User("Lee", 27);
        // 클래스 u1, u2, u3, u4 생성

        Console.WriteLine(u1 == u3);
        // False 출력

        Console.WriteLine(u2 == u4);
        // True 출력

        Console.WriteLine(u1 + u2);
        // 50 출력
    }
}
```

(여기부터 작성)

### 델리게이트(Delegate)

- 메소드 참조 기법
- 객체지향적 특징 반영 메소드 포인터
- 클래스 만을 위한 연산자
- 자료 추상화 가능
- 문법적 규칙 변경 불가
  - 연산 순위
  - 결합 법칙

### 이벤트(Event)

### 스레드(Thread)

### 제네릭(Generic)

## 3절. C# 구조

### 어휘

- 프로그램 구성 기본 소자
- 토큰(Tokennn)
- 문법적으로 의미있는 최소 단위
