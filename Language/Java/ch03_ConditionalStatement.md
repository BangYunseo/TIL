#  Chapter 3. 조건문
> '혼자 공부하는 자바 - 신용권' 4장 학습 내용
>
> [소스코드](https://github.com/BangYunseo/SelfStudyJava/tree/main/ch03_ConditionalStatement)
> 
> 1절. if
>
> 2절. switch
>
> 3절. for
>
> 4절. while
>
> 5절. break
>
> 6절. continue

## 1절. if
#### 조건문
* 조건식에 따라 다른 실행을 하기 위해 사용
* if문 : 조건식 결과의 true / false 여부에 따라 실행문 결정
* switch문 : 변수 값에 따라 실행문 결정

![conditional](https://github.com/BangYunseo/TIL/blob/main/Language/Java/Image/ch03/conditional.PNG)

#### if문
* 조건식 결과에 따라 블록 실행 여부 결정
* 조건식에 올 수 있는 요소
    * true / false 값 산출 연산식
    * boolean 타입 변수
* 중괄호 블록은 조건식이 true일 경우에만 실행
    * 실행할 문장이 하나뿐인 경우 생략 가능

![if1](https://github.com/BangYunseo/TIL/blob/main/Language/Java/Image/ch03/if1.PNG)

#### if - else문
* if문을 else 블록과 함께 사용
* 조건식의 결과에 따라 실행 블록 선택

* if문 조건식 여부     

|boolean|실행 블록|
|:---:|:---|
|true|if문 블록 실행|
|false|else문 블록 실행|


![ifelse](https://github.com/BangYunseo/TIL/blob/main/Language/Java/Image/ch03/ifelse.PNG)


#### if - else if - else문
* 조건식이 여러 개인 if문
* 처음 if문의 조건식이 false일 경우 다른 조건식의 결과에 따라 실행 블록 선택
    * if 블록 끝에 else if문 추가ㅣ
    * else if문 개수에는 제한 X

![elif](https://github.com/BangYunseo/TIL/blob/main/Language/Java/Image/ch03/elif.PNG)

#### if문 정리

|키워드|형태|설명|
|:---:|:---|:---|
|if문|if(조건식) {}|조건식이 true가 되면 중괄호 내부 실행|
|if - else문|if(조건식) {} else {}|조건식이 true일 경우 if 중괄호 내부, false일 경우 else 중괄호 내부 실행|
|if - else if - else문|if(조건식1) {} else if(조건식2) {} else {}|조건식1이 true일 경우 if 중괄호 내부, 조건식2가 true일 경우 else if 중괄호 내부, 조건식1과 조건식2 모두 false일 경우 else 중괄호 내부 실행|

## 2절. switch
#### switch문
* 변수가 어떤 값을 갖는지에 따라 실행문 선택
* 같은 기능의 if문보다 코드 간결

![switch](https://github.com/BangYunseo/TIL/blob/main/Language/Java/Image/ch03/switch.PNG)

#### switch문 정리

|키워드|형태|설명|
|:---:|:---|:---|
|switch문|switch(변수) {case 값1: ... case 값2: ... default ...}|변수의 값이 값1일 경우 첫 번째 case 블록, 변수의 값이 값2일 경우 두 번째 case 블록, 값1과 값2 모두 아닐 경우 default 블록 실행|

* 예제 1. 조건문 예제    
[SourceCodeChecking](https://github.com/BangYunseo/SelfStudyJava/blob/main/ch03_ConditionalStatement/WhatIsConditional.java)

## 3절. for
#### 반복문
* 어떤 작업을 반복적으로 실행할 경우 사용

![loop](https://github.com/BangYunseo/TIL/blob/main/Language/Java/Image/ch03/loop.PNG)

#### for, while, do - while
* for문
    * 반복 횟수를 주로 알고 있을 경우 사용
* while문
    * 조건에 따라 반복할 경우 사용
* do - while문
    * while문과 유사하나 조건을 나중에 검사

#### for문
* 주어진 횟수만큼 반복하고 싶을 경우 사용

![for](https://github.com/BangYunseo/TIL/blob/main/Language/Java/Image/ch03/for.PNG)

## 4절. while
#### while문
* 조건식에 따라 반복 여부를 결정할 경우
    * true일 경우 계속 반복
    * false일 경우 반복 종료
* 조건식에서는 주로 비교 연산식, 논리 연산식

![while](https://github.com/BangYunseo/TIL/blob/main/Language/Java/Image/ch03/while.PNG)

#### do - while문
* 조건식에 의해 반복 실행하는 점에서 while문과 동일
* 블록 내부 실행문을 우선 실행하고 그 결과에 따라 반복 실행 여부 결정

![dowhile](https://github.com/BangYunseo/TIL/blob/main/Language/Java/Image/ch03/dowhile.PNG)

## 5절. break
#### break문
* for, while, do - while, switch문의 실행을 종료할 경우 사용
* 주로 if문과 함께 사용

![break1](https://github.com/BangYunseo/TIL/blob/main/Language/Java/Image/ch03/break1.PNG)

* 반복문이 중첩된 경우
    * Label을 통해 바깥 반복문 탈출

![break2](https://github.com/BangYunseo/TIL/blob/main/Language/Java/Image/ch03/break2.PNG)

## 6절. continue
#### continue문
* for, while, do - while 문에서만 사용
* for문의 증감식이나 while, do - while문의 조건식 이동
* 주로 if문과 사용

![continue](https://github.com/BangYunseo/TIL/blob/main/Language/Java/Image/ch03/continue.PNG)

#### 반복문 정리
|키워드|형태|설명|
|:---:|:---|:---|
|for문|for(초기화식; 조건식; 증감식) {}|지정한 횟수만큼 반복|
|while문|while(조건식) {}|조건식이 true가 될 때까지 반복|
|do - while문|do {} while(조건식) {}|while문과 동일하나 조건식이 뒤에 위치|
|break문|break;|for문, while문, do - while문의 반복 종료 시 사용|
|continue문|continue;|for문, while문, do - while문의 증감식 또는 조건식|
