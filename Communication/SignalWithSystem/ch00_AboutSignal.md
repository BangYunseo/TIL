#  Chapter 0. 신호
> 1절. 디지털 신호 처리(DSP)
>
> 2절. 퓨리에(Fourier)
>
> 3절. 정현파

## 1절. 디지털 신호 처리(DSP)
#### 디지털 신호 처리란?
* Digital Signal Processing(DSP)
* 디지털화된 신호를 원하는 방향으로 정보 신호를 수정하거나 개선할 목적으로 알고리즘에 의해 수치적으로 처리
* 일반적으로 아날로그 신호를 디지털화하는 과정에서 이산 신호가 되며 수치화

#### 목적
* 연속적인 실세계 아날로그 측정 후 걸러내고 압축

#### 사용 이유
* 디지털 기기의 대표적 예시 중 하나인 컴퓨터가 상용화되었기 때문
* 수학적 추상화를 통해 일반화 및 새로운 처리 기술 발견을 위해
* 컴퓨터로의 구현이 유연하기 때문
* 애플리케이션은 물리적인 내용, 글을 제공하기 때문(디스플레이)

## 2절. 퓨리에(Fourier)
#### 퓨리에(Fourier)의 사용처
* 통신
* 소리, 음악(CD ROM, 영상)
* 퓨리에 광학
* X-ray 결정학(프로틴 구조, DNA)
* 컴퓨터화 단층 촬영(CT)
* 자기공명영상(MRI)
* 전파천문학

#### 퓨리에(Fourier) 사용 이유
* 주파수를 분리해서 표현하기 위해
    * 즉, Time Domain으로 구성된 그래프를 Frequency Domain에 따른 그래프로 변환하기 위해

![TimeFrequency]()

##### 주파수를 분리해서 표현해야 하는 이유
* Time Domain 그래프에서는 어느 수준의 주파수가 높게 출력되는지 확인 불가
* 하지만, Fourier를 통해 변환한 Frequency Domain 그래프에서는 어느 수준의 주파수가 높게 출력되는지 확인 가능

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
