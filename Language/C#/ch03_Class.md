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

(여기부터 작성 : pdf 7페이지)

<img src="https://github.com/BangYunseo/TIL/blob/main/Language/C%23/Image/ch03/3-1-.PNG" height="auto" />
