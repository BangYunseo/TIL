# Chapter 3. 클래스(Class)

> 'C# 프로그래밍' 3장 학습 내용
>
> 1절. 클래스
>
> 2절. 객체
>
> 3절. 필드
>
> 4절. 메소드
>
> 5절. 프로퍼티
>
> 6절. 인덱서
>
> 7절. 델리게이트
>
> 8절. 이벤트
>
> 9절. 연산자 중복
>
> 10절. 구조체
>
> 11절. 요약

## 1절. 클래스

### 클래스(Class)

- C# 프로그래밍의 기본 단위

  - 재사용성(Reuseability)
  - 이식성(Portability)
  - 유연성(Flexibility) 증가

- 객체를 정의하는 템플릿

  - 객체 구조 및 행위를 정의하는 방법

- 자료 추상화(Data Abstraction) 방법

### 클래스 구조

- 필수

  - 속성(Field : 필드)
  - 행위(Method : 메소드)

- 선택
  - 상수
  - 프로퍼티
  - 인덱서
  - 연산자 중복
  - 자료형
    - 이벤트 클래스 형
    - 델리게이트 형

#### 필드 vs 프로퍼티

- 필드 : 프로퍼티의 실제 값
- 프로퍼티 : 객체 상태와 같은 속성

### 클래스 선언

- 필드 계통
- 메소드 계통

```C#
[class-modifier] class ClassName {
    // member declarations
}
```

> class-modifier : public, internal, abstract, static, sealed  
> member declarations : 필드, 메소드, 프로퍼티, 인덱서, 연산자 중복, 이벤트

### 수정자

- 부가적 속성 명시 방법

|       수정자       | 설명                                                                                            |
| :----------------: | :---------------------------------------------------------------------------------------------- |
|       public       | - 다른 프로그램에서 사용 가능                                                                   |
|      internal      | - 같은 프로그램에서만 사용 가능<br>- 수정자가 생략된 경우                                       |
|       static       | - 정적 클래스, 클래스의 모든 멤버가 정적 멤버<br>- 객체 단위로 존재하지 않고 클래스 단위로 존재 |
|      partial       | - 부분 클래스<br>- 여러 파일에 나누어서 같은 이름의 클래스를 정의                               |
|  abstract, sealed  | - <strong>파생 클래스에서 설명</strong>                                                         |
| protected, private | - 친구 외에 참조 불가 (외부 참조 불가)                                                          |
|        new         | - 중첩 클래스에서 사용<br>- 베이스 클래스의 멤버를 숨김                                         |

#### C# 구현

```C#
// Fraction.cs : Fraction의 분수 클래스 선언 구현 프로그램

class Fraction {
    int numerator;
    // 분자 필드

    int denominator;
    // 분모 필드

    public Fraction Add(Fraction f)
    {
        /* ... */
    }
    // 덧셈 메소드

    public static Fraction operator + (Fraction f1, Fraction f2)
    {
        /* ... */
    }
    // 덧셈 연산자

    public void PrintFraction()
    {
        /* ... */
    }
    // 출력 메소드

}
```

## 2절. 객체

### 객체 선언

- 클래스 형의 변수 선언

#### 객체 선언 방법

- 클래스 이름 작성 후 해당 객체들 나열
  - 일반적인 변수 선언과 동일

```C#
Fraction f1, f2;
// f1, f2 객체를 참조(Reference)하는 변수 선언
```

### 객체 생성

- new 연산자와 함께 생성자를 명시하는 형태

```C#
f1 = new Fraction();
Fraction f1 = new Fraction();
```

### 생성자

- 객체 생성 시 객체 초기화를 위해 자동으로 호출되는 루틴
- 클래스와 동일한 이름의 메소드
- 객체 생성 시 필요한 초깃값이 매개 변수로 존재

### 객체 멤버 창조

- 점 연산자(Dot Operator)
  - 객체 이름과 멤버 사이의 멤버 접근 연산자

```C#
f1.numerator
// 필드 참조

f1.Add(f2)
// 메소드 참조
```

## 3절. 필드

### 필드 (Field)

- 클래스 형태에서 객체 구조를 기술하는 자료 부분
- 변수 선언으로 구성

```C#
[field-modifier] DataType fieldNames;
// 필드 선언 형태

int anInterger, anotherInteger;
// 정수형 필드 선언

public string usage;
// 문자형 필드 선언(public)

static long idNum = 0;
// 실수형 필드 선언(static)

public static readonly double earthWeight = 5.97e24;
```

- 필드 이름은 소문자로 시작

### 접근 수정자 (Access Notifier)

- 다른 클래스에서 필드의 접근 허용 정도를 나타내는 속성

| 접근 수정자        | 동일 클래스 | 파생 클래스 | 네임 스페이스 | 모든 클래스 |
| :----------------- | :---------: | :---------: | :-----------: | :---------- |
| private            |      O      |      X      |       X       | X           |
| protected          |      O      |      O      |       X       | X           |
| internal           |      O      |      X      |       O       | X           |
| protected internal |      O      |      O      |       O       | X           |
| public             |      O      |      O      |       O       | O           |

#### 접근 수정자 선언 예시

```C#
private int privateField;
int noAccessModifier;
// private

protected int protectedField;
// protected

internal int internalField;
// internal

protected internal int piField;
// protected internal

public int publicField;
// public
```

#### Private

- 정의된 클래스 내에서만 필드 접근 허용
- 접근 수정자가 생략된 경우

```C#
// Private 접근 수정자 실행 예시

class PrivateAccess {
  private int iamPrivate;
  int iamAlsoPrivate;
  //...
}

class AnotherClass {
  void AccessMethod() {
    PrivateAccess pa = new PrivateAccess();

    pa.iamPrivate = 10;
    // 에러 발생

    pa.iamAlsoPrivate = 10;
    // 에러 발생
  }
}
```

#### Public

- 모든 클래스 및 네임 스페이스에서 자유로운 접근 가능

```C#
// Public 접근 수정자 실행 예시

class PublicAccess {
  public int iamPublic;
  //...
}

class AnotherClass {
  void AccessMethod() {
    PublicAccess pa = new PublicAccess();

    pa.iamPublic = 10;
    // 정상 실행
  }
}
```

#### Internal

- 같은 네임 스페이스 내에서 자유로운 접근 가능

#### Protected

- 파생 클래스에서만 참조 가능

#### Protected Internal & Internal Protected

- 파생 클래스와 동일 네임 스페이스 내에서도 자유로운 접근 가능

### new 수정자

- 상속 계층에서 상위 클래스에 선언된 멤버를 하위 클래스에서 새롭게 재정의하기 위해 사용

### static 수정자

- 정적 필드(static field)
- 클래스 단위로 존재
- 생성 객체가 없는 경우에도 존재하는 변수

```C#
ClassName.staticField
// 정적 필드 참조 형태
```

### readonly 수정자

- 읽기 전용 필드
- 불변 속성
- 실행 중 값 결정

### const 수정자

- 불변 속성
- 컴파일 시간에 값 결정

```C#
[const-modifiers] const DataType constNames;
// 상수 멤버 선언 형태
```

## 4절. 메소드

### 메소드(Method)

- 객체의 행위를 기술하는 방법
- 객체 상태를 검색하고 변경하는 작업
- 특정 행동을 처리하는 프로그램 코드를 포함한 함수 형태

```C#
class MethodExample {
  int SimpleMethod() {
    // ...
  }

  public void EmptyMethod() {}
}
```

### 메소드 수정자

- 총 11개

#### 접근 수정자

- public
- protected
- internal
- private

#### Static

- 정적 메소드
- 전역 함수와 동일한 역할
- 정적 메소드는 해당 클래스의 정적 필드 또는 정적 메소드만 참조 가능

```C#
ClassName.MethodName();
```

#### abstract / extern

- 메소드 몸체 대신 세미콜론(;)으로 표현

- abstract
  - 메소드가 하위 클래스에 정의
- extern
  - 메소드가 외부에 정의

#### 그 외의 메소드 수정자

- new
- virtual
- override
- sealed

### 매개 변수

- 메소드 내에서만 참조 가능한 지역 변수

#### 매개 변수 종류

|               종류               | 설명                              |
| :------------------------------: | :-------------------------------- |
| 형식 매개 변수(Formal Parameter) | 메소드 정의 시 사용하는 매개 변수 |
|  실 매개 변수(Actual Parameter)  | 메소드 호출 시 사용하는 매개 변수 |

#### 매개 변수 자료형

- 기본형
- 참조형

```C#
void parameterPass(int i, Fractioon f)
{
  // ...
}
```

#### this 지정어

- 자기 자신의 객체를 가리키는 특별한 포인터
- 클래스 필드와 매개 변수 구별 용도

```C#
class Fraction {
  int numerator, denominator;
  // 필드로 선언된 numerator과 denominator

  public Fraction(int numerator, int denominator) {
    this.numerator = numerator;
    this.denominator = denominator;
    // this를 사용한 값 할당
  }
}
```

- 메소드 안의 모든 필드와 메소드 이름 앞에는 내부적으로 this 사용

### 매개 변수 전달

- 메소드 호출 시 실 매개 변수가 형식 매개 변수로 전달
- 전달될 실 매개 변수가 호출된 메소드 내에서 사용

#### (1) 값 호출 : Call by Value

- 실 매개 변수의 값이 형식 매개 변수로 전달

#### (2) 참조 호출 : Call by Reference

- 주소 호출 (Call by Address)
- 실 매개 변수의 주소가 형식 매개 변수로 전달
- C# 제공 방법
  - 매개 변수 수정자 이용
  - 객체 참조를 매개 변수로 사용

#### 매개 변수 수정자

- ref
  - 매개 변수 전달 시 반드시 초기화
- out
  - 매개 변수 전달 시 초기화 선택

```C#
using System;
class SwapMethod {
  static void Swap(int x, int y)
  {
    int temp;

    temp = x;
    x = y;
    y = temp;
    // 값 Swap 형태

  Console.WriteLine("Swap : x = {0}, y = {1}", x, y);
  }

  public static void Main()
  {
    int x = 1;
    int y = 2;

    Console.WriteLine("Before : x = {0}, y = {1}", x, y);
    // 초깃값 출력

    Swap(x, y);
    // Swap 함수 적용

    Console.WriteLine("Before : x = {0}, y = {1}", x, y);
    // Swap 함수 적용 후 결괏값 출력
    // 초깃값 그대로 유지
  }
}

// 결과 출력
// Before : x = 1, y = 2;
// Swap : x = 2, y = 1;
// After : x = 1, y = 2;
```

### 매개 변수 배열 (Parameter Array)

- 실 매개 변수의 개수가 상황에 따라 가변적인 경우
- 메소드 정의 시 형식 매개 변수 결정 불가

```C#
using System;
class ParaArray {
  void ParameterArray(params object[] obj)
  {
    for(int i = 0; i < obj.Length; i++)
  }

  public static void Main()
  {
    ParameterArray(123, "Hello", true, 'A');
  }
}

// 출력 결과
// 123
// Hello
// True
// A
```

### 메인 메소드

- C# 응용 프로그램의 시발점

```C#
using System;
class CommandLineArgsApp{
  public static void Main(strings[] args)
  {
    for(int i = 0; i < args.Length; i++)
    {
      Console.WriteLine("Arg[{0}] = {1}", i, args[i]);
    }
  }
}

// 실행 방법
// C:\> CommandLineArgsApp 122 Medusa 5.26

// 출력 결과
// Arg[0] = 12
// Arg[1] = Medusa
// Arg[2] = 5.26
```

- 매개 변수 -> 명령어 라인으로부터 스트링 전달

#### 명령어 라인 스트링 전달

> C:\> 실행 파일명 인수1 인수2 ... 인수n

- args[0] = 인수1, args[1] = 인수2, args[n - 1] = 인수n
- 인덱스는 0부터 시작

### 메소드 중복 (Method Overloading)

- 메소드 이름은 같은 채로 매개 변수 개수와 형태가 다른 경우
- 호출 시 컴파일러에 의해 메소드 구별

```C#
using System;
class MethodOverloadingApp{
  void SomeMethod()
  {
    ConsoleWriteLine("SomeMethod() Calling");
  }
  // 첫 번째 형태

  void SomeMethod(int i)
  {
    ConsoleWriteLine("SomeMethod(int) Calling");
  }
  // 두 번째 형태

  void SomeMethod(int i, int j)
  {
    ConsoleWriteLine("SomeMethod(int, int) Calling");
  }
  // 두 번째 형태

  void SomeMethod(double d)
  {
    ConsoleWriteLine("SomeMethod(double) Calling");
  }
  // 두 번째 형태

  public static void Main()
  {
    MethodOverloadingApp obj = new MethodOverloadingApp();

    obj.SomeMethod();
    obj.SomeMethod(526);
    obj.SomeMethod(65, 674);
    obj.SomeMethod(5.26);
  }
}

// 출력 결과
// SomeMethod() Calling
// SomeMethod(int) Calling
// SomeMethod(int, int) Calling
// SomeMethod(double) Calling
```

#### 시그니처 (Signature)

- 메소드 구별 시 쓰이는 정보

  - 메소드 이름
  - 매개 변수 개수
  - 매개 변수 자료형
  - <strong>메소드 반환형 제외</strong>

### 생성자 (Constructor)

- 객체 생성 시 자동 호출되는 메소드
- 클래스 이름과 동일
- 반환형 미존재
- 객체 초기화 작업에 사용
- 중복 생성자 존재 가능

```C#
class Fraction{
  public Fraction(int a, int b)
  // 생성자
  {
    numerator = a;
    denominator = b;
  }
}

//...
Fraction f = new Fraction(1, 2);
```

#### 정적 생성자 (Static Constructor)

- 수정자가 static으로 선언된 생성자
- 매개 변수와 접근 수정자 존재 불가
- 클래스 정적 필드 초기화 시 사용
- Main() 메소드보다 먼저 실행

```C#
using System;
class StaticConstructor{
  static int a = 100;
  static int b;

  static Constructor()
  {
    b = a + 100;
  }
  // 매개 변수와 접근 수정자를 가질 수 없음

  public static void PrintStatic()
  {
    Console.WriteLine("field 1 = {0}, field 2 = {1}", a, b);
  }
}

class StaticConstructorApp{
  public static void Main()
  {
    StaticConstructor.PrintStatic();
  }
}

// 출력 결과
// field 1 = 100, field 2 = 200
```

#### 정적 필드 초기화 방법

- 정적 필드 선언과 동시에 초기화
- 정적 생성자 이용

### 소멸자 (Destructor)

- 클래스 객체 소멸 시 필요한 행위가 기술ㄹ된 메소드
- 소멸자 명은 생성자와 동일
- 이름 앞에 '~'(tilde) 존재

#### Finalize()

- 컴파일 시 소멸자를 Finalize() 메소드로 변환 후 컴파일
- Finalize() 메소드 재정의 불가
- 객체가 더 이상 참조되지 않을 때 GC(Garbage Colletion)에 의한 호출

#### Dispose()

- CLR에서 관리되지 않은 자원을 직접 해제할 때 사용
- 자원이 범위를 벗어나면 시스템에 의해 즉시 호출

## 5절. 프로퍼티

### 프로퍼티 (Property)

- 클래스 private 필드를 형식적으로 다루는 일종의 메소드

(여기부터 수정!)

## 6절. 인덱서

## 7절. 델리게이트

## 8절. 이벤트

## 9절. 연산자 중복

## 10절. 구조체

## 11절. 요약

<img src="https://github.com/BangYunseo/TIL/blob/main/Language/C%23/Image/ch03/3-1-.PNG" height="auto" />
