# Chapter 1. C# 개요

> 'C# 프로그래밍' 1장 학습 내용
>
> 0절. 과거의 C#
>
> 1절. C# 개요
>
> 2절. C# 특징
>
> 3절. C# 구조
>
> 4절. 요약

## 0절. 과거의 C#

### Visual Basic

- 쉽고 빠른 프로그래밍 가능
- 문제점
  - 완벽한 객체 지향 지원 X
  - 다른 언어와의 호환성 지원에 미흡

### .NET(닷넷)

- 모든 것을 포괄하는 이상적인 개발 환경
- 개발에 필요한 개발 언어, 툴, 라이브러리, 기술 등 제공
- 해당 환경 별 통일 사항

|   환경    | 특성                                                                                    |
| :-------: | :-------------------------------------------------------------------------------------- |
| 개발 환경 | 다양한 언어로 개발                                                                      |
| 실행 환경 | 다양한 언어로 개발된 프로그램을 하나의 방식으로 번역한 후 닷넷에서 하나의 방식으로 동작 |

### .NET Framework(닷넷 프레임워크)

- CLS(Common Language Specification : 공통 언어 스펙) 규칙을 따르는 언어로 작성된 애플리케이션은 닷넷 프레임워크에서 동작 가능

<img src="https://github.com/BangYunseo/TIL/blob/main/Language/C%23/Image/ch01/ch01-01-.NETFramework.PNG" height="auto" />

### .NET 특징

#### 1. 플랫폼 독립성(Platform Independent)

- 닷넷 프레임워크만 설치되어 있다면 어떤 운영체제에서도 닷넷 애플리케이션 동작 가능

#### 2. 다양한 언어 지원

- 개발자는 다양한 언어로 개발 가능
- 닷넷에서 하나의 방식으로 동작 가능
- CLS(Common Language Specification)
  - 닷넷 프레임워크에서의 동작을 위해 언어들이 지켜야 하는 표준 스펙

#### 3. 상호 운용성(Interoperability)

- 서로 다른 언어끼리의 호환성
  - C#에서 COM 사용
  - C#에서 Win32 API 사용

### 중간 언어(Intermediate Language)

<img src="https://github.com/BangYunseo/TIL/blob/main/Language/C%23/Image/ch01/ch01-02-MidLanguage.PNG" height="auto" />

- 기계어로 변환하기 쉬운 상태인 중간 단계 언어
- 닷넷에서 번역되고 실행하기 위해서는 중간 언어 형태로 컴파일 필수

#### 중간 언어 장점

- 중간 언어를 기계어로 번역하는 번역기만 제공된다면 어떤 플랫폼에서도 실행 가능

#### 중간 언어 단점

- 완전한 기계어가 아니므로 언젠가는 완전한 기계어로의 번역 필요
- 느린 속도

### CLR

- 아래의 단계가 동적으로 실행
  - 중간 언어로 컴파일된 파일 로딩
  - CLR 내의 JIT 컴파일러가 기계어로 컴파일

<img src="https://github.com/BangYunseo/TIL/blob/main/Language/C%23/Image/ch01/ch01-03-CLR.PNG" height="auto" />

|            개념            | 정의                                             |
| :------------------------: | :----------------------------------------------- |
|         중간 언어          | C# 최종 결과물(컴파일한 결과 파일)               |
|          재컴파일          | 중간 언어는 완벽한 기계어로 컴파일해야 실행 가능 |
| JIT(Just In Time Compiler) | 중간 언어를 동적으로 컴파일하는 컴파일러         |

### .NET 컴파일

- 중간 언어(IL) 형태로 변환

### .NET 실행

- .NET 환경의 CLR은 IL 형태의 언어를 JIT가 재컴파일한 후 실행

### C# 어셈블리

- 중간 언어 형태의 .exe or .dll 파일들을 C#에서는 어셈블리(Assembly)라고 명칭

#### 어셈블리(Assembly) 종류

|     종류      | 특성                                                                                                                                                                           |
| :-----------: | :----------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| 사설 어셈블리 | - Copy & Paste 개념의 프로그램<br>- 복사 후 붙여넣기로 사용                                                                                                                    |
| 공용 어셈블리 | - 레지스터 개념에서 발전된 형태<br>- 공용 어셈블리로 등록하는 것은 레지스터와 동일<br>- 버전 별 독립적으로 관리하며 복사된 버전 보관<br>- CLSID 대신 디지털 서명 방식으로 관리 |

## 1절. C# 개요

### C#

- .NET(닷넷)의 대표 언어

### C# 라이브러리

- XML.NET
- ADO.NET
- ASP.NET
- XML Web Services

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

<img src="https://github.com/BangYunseo/TIL/blob/main/Language/C%23/Image/ch01/ch01-04-Schematic.PNG" height="auto" />

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

<img src="https://github.com/BangYunseo/TIL/blob/main/Language/C%23/Image/ch01/ch01-05-Process.PNG" height="auto" />

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

### 델리게이트(Delegate)

- 메소드 참조 기법
- 객체지향적 특징이 반영된 메소드 포인터
- 클래스 만을 위한 연산자
- 자료 추상화 가능
- 문법적 규칙 변경 불가
  - 연산 순위
  - 결합 법칙
- 이벤트 및 스레드 처리를 위한 방법론

#### C# 구현

```C#
// Program.cs : Program의 델리게이트 구현 프로그램

using System;
using System.Text;
// 한국어 인코딩 라이브러리

class Program
{
    delegate void OnClicked();
    // 델리게이트 OnClicked 선언

    static void ButtonPressed(OnClicked clickFunction)
    {
        Console.WriteLine("버튼을 눌렀습니다.");
        clickFunction();
    }

    static void test1()
    {
        Console.WriteLine("TEST DELEGATE 1");
    }

    static void test2()
    {
        Console.WriteLine("TEST DELEGATE 2");
    }

    static void Main()
    {
        Console.OutputEncoding = Encoding.UTF8;
        // 한국어 출력 설정

        OnClicked click = new OnClicked(test1);
        click += test2;
        // 델리게이트 체이닝 형태

        ButtonPressed(test1);
        // 델리게이트 1 사용

        ButtonPressed(test2);
        // 델리게이트 2 사용

        click();
        // 델리게이트 3 사용
    }
}
```

### 이벤트(Event)

- 사용자 행동에 의해 발생한 사건
- 사건의 발생을 알리기 위해 보내는 메시지
- 델리게이트를 통해 이벤트 처리

#### 이벤트 주도 프로그래밍

- 이벤트와 이벤트 처리기를 통한 객체에 발생한 사건
  - 다른 객체에 통지하고 그에 대한 행위를 처리하도록 시키는 구조
- 각 이벤트에 따른 작업을 독립적으로 기술
- 프로그램 구조가 체계적 & 구조적
- 복잡도 감소

### 스레드(Thread)

- 순차 프로글램과 유사하게 시작, 실행, 종료 순서
- 실행되는 동안 한 시점에서 단일 실행점 보유
- 프로그램 내에서만 실행 가능

#### 멀티스레드 시스템

- 스레드가 하나의 프로그램 내에 여러 개 존재
- 응용 프로그램의 병행 처리를 위해 스레드 개념 지원
- 스레드 생성 후 실행 및 제어 방법 제공
- 델리게이트를 통한 처리

### 제네릭(Generic)

- 자료형을 매개 변수로 취급
- C++ 템플릿과 유사

#### 단위

- 클래스
- 구조체
- 인터페이스
- 메소드

#### C# 구현

```C#
// BoxProgram.cs : BoxProgram의 제네릭 구현 프로그램

using System;
using System.Text;
// 한국어 인코딩 라이브러리

class Box<T>
{
    private T content;

    public Box(T _content)
    {
        content = _content;
    }

    public T GetContent()
    {
        return content;
    }

    public void PrintContent()
    {
        Console.WriteLine($"상자 내용 : {content}");
        Console.WriteLine($"상자 내용 타입 : {content.GetType().Name}");
    }
}

class BoxProgram
{
    static void Main()
    {
        Console.OutputEncoding = Encoding.UTF8;
        // 한국어 출력 설정

        Box<int> intBox = new Box<int>(7);
        // int 타입을 T로 사용하는 7을 담은 정수 Box 인스턴스 생성

        intBox.PrintContent();
        // intBox 내용 출력

        int boxValue = intBox.GetContent();
        Console.WriteLine($"꺼낸 정수 : {boxValue}\n");
        // intBox 안의 정수 값 꺼내기



        Box<string> strBox = new Box<string>("Hello, World!");
        // string 타입을 T로 사용하는 "Hello, World!"를 담은 문자열 Box 인스턴스 생성

        strBox.PrintContent();
        // strBox 내용 출력

        string boxString = strBox.GetContent();
        Console.WriteLine($"꺼낸 문자열 : {boxString}");
    }
}
```

## 3절. C# 구조

### 어휘

- 프로그램 구성 기본 소자
- 토큰(Token)
- 문법적으로 의미있는 최소 단위

#### 토근 종류

<img src="https://github.com/BangYunseo/TIL/blob/main/Language/C%23/Image/ch01/ch01-06-TokenType.PNG" height="auto" />

#### 지정어

- 프로그래밍 언어 설계 시 기능과 용도가 이미 정의된 단어
- 사용자가 임의로 결정하는 변수 명 혹은 메소드 명 등으로 사용 불가

#### C# 지정어

- 77개
- C# Language Specification(ECMA TC39 / TG2)

### 명칭

- 자료 항목 식별을 위해 붙이는 이름
  - 변수
  - 상수
  - 배열
  - 클래스
  - 메소드
  - 레이블

#### 명칭의 형태

- 문자 시작
- 길이 제한 없음
- 대소문자 구분
- @기호 사용 시 명칭 사용 가능

| 옳은 명칭 예시 | 틀린 명칭 예시 |
| :------------: | :------------: |
|      sum       |      1sum      |
|      sum1      |      sum!      |
|   money_sum    |      $sum      |
|    moneySum    |      #sum      |
|      @int      |   Money Sum    |
|      변수      |    virtual     |

### 리터럴

- 자신의 표기법이 곧 자신의 값이 되는 상수
- ex) "12" : 값이 12인 정수를 나타내는 경우

#### 리터럴 종류

<img src="https://github.com/BangYunseo/TIL/blob/main/Language/C%23/Image/ch01/ch01-07-LiteralType.PNG" height="auto" />

#### 객체참조 리터럴(Object Reference)

- 널(NULL)
  - 아무 객체도 가리키지 않는 상태
  - 부적합하거나 객체 생성 불가한 경우 초기화ㅏ에 사용

### 주석

- 프로그램 설명을 위한 문장
- 프로그램 실행과 무관
- 프로그램 유지보수(리팩토링) 시 중요

#### 주석 종류

1. // comment

   - // 부터 새로운 줄 전까지 주석으로 간주
   - 사용 예시

   ```C#
       int size = 100;
       // size를 100으로 초기화
   ```

2. /\* comment \*/

   - /\* 와 다음 \*/ 사이의 모든 문자들을 주석으로 간주
   - 주석문 안의 또 다른 주석 포함 불가
   - C# 언어에서 여러 줄의 주석을 위해 현재 주석 형태 지원

3. /// comment

   - /// 문자들 부터 주석으로 간주
   - C# 프로그램에 대한 웹 보고서 작성 시 사용하는 방법
   - XML 태그를 통해 기술
   - 사용 예시

### 자료형

- 자료 객체가 갖는 형태
- 구조 및 개념, 값의 범위, 연산 등 정의

#### 자료형 종류

<img src="https://github.com/BangYunseo/TIL/blob/main/Language/C%23/Image/ch01/ch01-08-ValueableType.PNG" height="auto" />

#### 값형

1. 숫자형

   - 값 표현 방법과 연산 방식에 따라 상이
     - 정수형
     - 실수형

2. 문자형

   - 16비트 유니코드 사용

3. 부울형

   - 다른 자료형으로 변환 불가
     - true
     - false
     - 숫자값 불가능

4. 열거형

   - 서로 관련 있는 상수들의 모음을 상징있는 명칭의 집합으로 정의
     - 기호 상수 : 집합의 원소로 기술된 명칭
     - 순서값 : 집합에 명시된 순서에 따라 0부터 부여된 값

5. 구조체형

   - 클래스처럼 고유 필드, 메서드, 생성자 존재
   - 참조 형식이 아닌 형식
   - 기본 생성자 선언 불가능

#### 참조형

1. 배열형

   - 같은 형의 여러 값 저장 시 사용
   - 순서가 있는 원소들의 모임
   - 배열을 하나의 객체로 취급
   - 사용 예시

   ```C#
    // 배열 선언 예시

    int[] vector;
    // 1차원 배열

    short[, ] matrix;
    // 2차원 배열

    object[] myArray;

    int[] initArray = {0, 1, 2,3 , 4, 5};
    // 선언과 동시에 초깃값 부여
   ```

   ```C#
   // 배열 구현 예시

   vector = new int[100];
   matrix = new short[10, 100];
   myArray = new Point[3];
   ```

<img src="https://github.com/BangYunseo/TIL/blob/main/Language/C%23/Image/ch01/ch01-09-Array.PNG" height="auto" />

2. 참조형(스트링형)

   - 문자열 표현을 위한 자료형
   - System.String 클래스형과 동일

3. StringBuilder 클래스

   - 효율적인 스트링 취급을 위한 클래스
   - 객체에 저장된 내용을 임의로 변경 가능
   - 스트링 중간에 삽입, 추가 등의 다양한 메서드 존재
   - 같은 형의 여러 값 저장 시 사용
   - 순서 있는 원소들의 모임
   - 배열을 하나의 객체로 취급

### 연산자

- 식

  - 문장에서 값 계산 시 사용

- 연산자
  - 식의 의미 결정
  - 피연산자가 어떻게 계산될 지 표현하는 기호

#### 연산자 종류

<img src="https://github.com/BangYunseo/TIL/blob/main/Language/C%23/Image/ch01/ch01-10-OperatorType.PNG" height="auto" />

### 형변환

- 피연산자의 자료형이 상이할 경우 일정 규칙에 따라 피연산자의 자료형을 일치시키는 것
- 연산 시 모든 피연산자는 자료형이 일치해야 함

#### 묵시적 형 변환

- 컴파일러에 의하 자동으로 수행되는 형 변환
- 작은 크기 자료형 => 큰 크기 자료형

#### 명시적 형 변환

- 프로그래머가 캐스트 연산자를 사용하여 수행하는 형 변환
- 형태 : (자료형) 식
- 큰 크기 자료형 => 작은 크기 자료형
  - 정밀도 상실

#### C# 구현

```C#
// PrecisionApp.cs : PrecisionApp의 형변환 구현 프로그램

using System;
using System.Text;
// 한국어 인코딩 라이브러리

class PrecisionApp
{
    public static void Main()
    {
        Console.OutputEncoding = Encoding.UTF8;
        // 한국어 출력 설정

        int big = 1234567890;
        float approx;
        approx = (float)big;
        Console.WriteLine("차이 : " + (big - (int)approx));
    }
}

// 실행 결과
// 차이 : -46
```

### 박싱(Boxing)

- 값(Value) 형식의 데이터를 참조 형식으로 변환
- 컴파일러에 의해 묵시적으로 실행

#### 박싱(Boxing) 과정

<img src="https://github.com/BangYunseo/TIL/blob/main/Language/C%23/Image/ch01/ch01-11-Boxing.PNG" height="auto" />

### 언박싱(UnBoxing)

- 참조형의 데이터를 값형으로 변환
- 반드시 캐스팅으로 명시적 수행
- 박싱될 경우 형으로 언박싱 필수

#### C# 구현

```C#
// BoxingUnboxingApp.cs : BoxingUnboxingApp의 박싱 및 언박싱 구현 프로그램

using System;
using System.Text;
// 한국어 인코딩 라이브러리

class BoxingUnboxingApp
{
    public static void Main()
    {
        Console.OutputEncoding = Encoding.UTF8;
        // 한국어 출력 설정

        int foo = 526;
        object bar = foo;
        // foo를 bar로 박싱
        // 내부적 int

        Console.WriteLine(bar);
        // 박싱 bar 출력

        try
        {
            int unboxedInt = (int)bar;

            Console.WriteLine(unboxedInt);
            // int 자료형으로 직접 언박싱 시도
            // 정상적인 언박싱 - 원래 타입과 일치

            double d = (short)bar;

            Console.WriteLine(d);
            // short 자료형으로 직접 언박싱 시도
            // 에러 발생
        }
        catch(InvalidCastException e)
        {
            Console.WriteLine(e + "Error");
        }
    }
}
```

## 4절. 요약

### C#

- 마이크로소프트사, 랜더스 헬스버그에 의해 고안된 언어
- C 언어 계열에 속하는 범용 프로그래밍 언어

### C# 개발 환경

- Visual Studio와 같은 통합 개발 환경 사용
- .Net 프레임워크에서 지원하는 개발도구(SDK)를 직접 사용

### C# 특징

- 클래스(Class)
- 속성(Property)
- 연산자 중복(Operator Overloading)
- 델리게이트(Delegate)
- 이벤트(Event)
- 제네릭(Generic)
- 스레드(Thread)

### 토큰

- 프로그램을 구성하는 문법적으로 의미 있는 최소의 단위
- == 어휘

### 지정어

- 프로그래밍 언어 설계 시 기능과 용도가 이미 정의된 다ㅏㄴ어

### 명칭

- 자료의 항목 식별을 위해 붙이는 이름
- 항목 종류
  - 변수
  - 상수
  - 배열
  - 클래스
  - 메소드
  - 레이블

### 주석

- 프로그램이 무엇을 하는가 설명하기 위해 소스 프로그램 내에 기술하는 문장

### 자료형

- 자료 객체가 갖는 형
- 자료형 정의 항목
  - 구조
  - 개념
  - 값의 범위
  - 연산

### 연산자

- 식의 의미

### 형 변환

- 피연산자의 자료형이 상이할 경우 일정 규칙에 맞게 피연산자의 자료형을 일치시키는 행위
