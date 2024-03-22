#  Chapter 4. 변수와 시스템 입출력
> '혼자 공부하는 자바 - 신용권' 2장 4절 학습 내용
>
> [소스코드](https://github.com/BangYunseo/SelfStudyJava/tree/main/ch04_VariableSystemIO)
> 
> 1절. 변수 출력
>
> 2절. 변수 저장
>
> 3절. 정리

## 1절. 변수 출력
#### System.out
* 시스템의 표준 출력 장치로 출력
```Java
System.out.println("Hello, World!");
// 출력 예시
// Hello, World!
```

#### System.in
* 시스템의 표준 입력 장치에서 읽음
```Java
System.in.read();
```

#### println()
* 괄호 안의 문자열이나 변수를 출력하는 메소드

![println](https://github.com/BangYunseo/TIL/blob/main/Language/Java/Image/ch04/println.PNG)

#### 여러가지 출력 메소드
          
![print](https://github.com/BangYunseo/TIL/blob/main/Language/Java/Image/ch04/print.PNG)

#### printf()
* 형식화된 문자열(formal string) 출력
* 전체 출력 자릿수 및 소수 자릿수 제한

![printf](https://github.com/BangYunseo/TIL/blob/main/Language/Java/Image/ch04/printf.PNG)

* 형식 문자열에서 %와 conversion 외에는 모두 생략 가능
* conversion에는 제공되는 값의 타입에 따라 d(정수), f(실수), s(문자열) 입력

```Java
System.out.printf("이름 : %s\n", "방윤서");
System.out.printf("나이 : %d", 22);
// 출력 예시
// 이름 : 방윤서
// 나이 : 22
```

* 형식 문자열에 포함될 값이 2개 이상인 경우 순번표시
```Java
System.out.printf("이름 : %1$s, 나이 : %2$d", "방윤서", 22);
// 출력 예시
// 이름 : 방윤서, 나이 : 22
```

* 다양한 형식 문자열

![print2](https://github.com/BangYunseo/TIL/blob/main/Language/Java/Image/ch04/print2.PNG)

* 예제 1. printf 예제      
[SourceCodeChecking](https://github.com/BangYunseo/SelfStudyJava/blob/main/ch04_VariableSystemIO/PrintfExample.java)

## 2절. 변수 저장
#### 키 코드(Key Code) 
* 키보드에서 키를 입력할 때 프로그램에서 숫자로 된 키 코드를 읽음
* System.in의 read() 사용
* 얻은 키코드는 대입 연산자 사용하여 int 변수에 저장

![keycode](https://github.com/BangYunseo/TIL/blob/main/Language/Java/Image/ch04/keycode.PNG)

(여기부터 다시 작성!)

## 3절. 정리
#### 핵심 포인트 확인하기

|키워드|설명|
|:---:|:---|
|System.out.println()|괄호에 주어진 매개값을 모니터로 출력 하고 개행 |
|System.out.print()|괄호에 주어진 매개값을 모니터로 출력만 하고 개행 X|
|System.out.printf()|괄호에 주어진 형식대로 출력|
|System.in.read()|키보드에서 입력된 키 코드를 읽음|
|Scanner|키보드로부터 입력된 내용을 통 문자열로 쉽게 읽기 위해서 Scanner 사용|
