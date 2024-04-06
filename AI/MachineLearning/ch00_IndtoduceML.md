#  Chapter 0. 기계학습 소개   
> '기계학습 - 오일석' 1장 학습 내용
>
> [소스코드]는 존재하지 않습니다.
> 
> 1절. 기계학습의 개념
>
> 2절. 특징 공간
>
> 3절. 데이터
>
> 4절. 기계 학습 예시
>
> 5절. 모델 선택
> 
> 6절. 규제
>
> 7절. 기계 학습 유형

## 1절. 기계학습의 개념
#### 인공지능, 머신러닝, 딥러닝
* 인공지능
  * 사고나 학습 등 인간이 가진 지적 능력을 컴퓨터를 통해 구현하는 기술
  * 인간 혹은 인간 이상의 지식 상태 구현 목적
* 머신러닝
  * 컴퓨터가 스스로 학습하여 인공지능의 성능을 향상시키는 기술 방법
  * 여러 가지 경우를 학습하여 그와 비슷한 경우의 문제 해결
* 딥러닝
  * 인간의 뉴런과 비슷한 인공신경망 방식으로 정보 처리
  * 상황에 적합한 학습 경험 이용

#### 기계 학습의 정의
* 학습이란? <표준국어대사전>
> " 경험의 결과로 나타나는. 비교적 지속적인 행동의 변화나 그 잠재력의 변화 또는 지식을 습득하는 과정. [국립국어원, 2017] "

* 기계학습이란?
  * 인공지능 초창기 사무엘의 정의
> " Programming computers to learn from experience should eventually eliminate the need for much of this detailed programming effort."     
> " 컴퓨터가 경험을 통해 학습할 수 있도록 프로그래밍할 수 있다면 세세하게 프로그래밍해야 하는 번거로움에서 벗어날 수 있다. [Samuel, 1959] "

  * 현대적 정의
> " A computer program is said to learn from experience E with respect to some class of tasks T and performance measure P, if its performance at tasks in T, as measured by P. improves with experience E."     
> " 어떤 컴퓨터 프로그램이 T라는 작업을 수행한다. 이 프로그램의 성능을 P라는 척도로 평가했을 때 경험 E를 통해 성능이 개선된다면 이 프로그램은 학습을 한다고 말할 수 있다. [Mitchell, 1997(2page)] "

> " Programming computers to optimize a performance criterion using example data or past experience. "     
> "사례 데이터. 즉 과거 경험을 이용하여 성능 기준을 최적화하도록 프로그래밍하는 작업. [Alpaydin, 2010] "

> " Computational methods using experience to improve performance or to make accurate predictions."     
> "성능을 개선하거나 정확하게 예측하기 위해 경험을 이용하는 계산학 방법들. [Mohri, 2012] "

#### 지식 기반 방식에서 기계학습으로의 전환
* 인공지능의 탄생
  * 컴퓨터의 뛰어난 능력
  * 컴퓨터에 대한 기대감
  * -> 이를 통한 지식 기반 방식 사용
* 인공지능의 주도권 전환
  * 점차 지식 기반 방식에서 기계학습 방식으로 전환
  * 기계 학습 : 데이터 중심 접근 방식
    * 데이터를 기반으로 인간처럼 응용 가능하도록 학습


#### 기계학습 이해
* 간단한 기계학습 예제
  * 가로축은 시간, 세로축은 이동체의 위치
  * 관측된 4개의 점은 데이터
  * 간단한 회귀 문제     

![exampleML](https://github.com/BangYunseo/TIL/blob/main/AI/MachineLearning/Image/ch00/exampleML.PNG)

* 예측(prediction) 예제
  * 임의의 시간이 주어졌을 때 이동체의 위치 예측
  * 회귀(regression) 문제와 분류(classification) 문제로 나눠짐
    * 회귀(regression)
      * 실수의 목표값을 가짐
    * 분류(classification)
      * 부류값으로 분류

* 훈련집합
  * 가로축은 특징, 세로축은 목표치
  * 관측한 4개의 점이 훈련집합 구성

![TrainingData](https://github.com/BangYunseo/TIL/blob/main/AI/MachineLearning/Image/ch00/TrainingData.PNG)  

#### 데이터 모델링 방법
* 데이터가 직선을 이루므로 직선을 모델로 선택
* 직선 모델의 수식
  * 2개의 매개 변수 w와 b
    * 1차원 : $y = wx + b$   
    * 2차원 : $y = w_1x^2 + w_2x + b$  

#### 기계학습의 목적    
* 가장 정확하게 예측할 수 있는 최적의 매개 변수를 찾는 작업
* 처음에는 최적값을 모르는 상태이므로 임의의 값에서 학습 시작한 후, 점차 성능을 개선하여 최적에 도달
  * 그림[1 - 4] 예시 참
    * $f_1$에서 시작하여 $f_1$ -> $f_2$ -> $f_3$ 까지 성능을 개선했으며 최적인 $f_3$은 $w=0.5$와 $b=2.0$
* 기계학습의 궁극적 목표
  * 훈련 집합에 없는 새로운 샘플(테스트 샘플)에 대한 오류 최소화
  * 새로운 샘플에 대한 높은 성능 일반화(generalization) 능력 탑재

#### 기계학습 단순 비교

![HumanAndMachine](https://github.com/BangYunseo/TIL/blob/main/AI/MachineLearning/Image/ch00/HumanAndMachine.PNG)  

## 2절. 특징 공간
#### 차원 별 특징 공간
* 1차원 특징 공간

![dimension1](https://github.com/BangYunseo/TIL/blob/main/AI/MachineLearning/Image/ch00/dimension1.PNG) 

* 2차원 특징 공간   
  * 특징 벡터 표기
    * $x=(x_1, y_1)^T$
  * 예시 
    * $x = 특징$, $y = 목표값$
      * $x=(몸무게, 키)^T$, $y=bmi$
      * $x=(체온, 두통)^T$, $y=감기 여부$

![dimension2](https://github.com/BangYunseo/TIL/blob/main/AI/MachineLearning/Image/ch00/dimension2.PNG) 

#### 다차원 특징 공간 개념
* $d$-차원 데이터
  * 특징 벡터 표기
    * $x = (x_1, x_2, ..., x_d)^T$
* $d$-차원 데이터를 위한 학습 모델
  * 직선 모델을 사용하는 경우 매개 변수의 수 = $d+1$

  $y = w_1x_1 + w_2x_2 + ... + w_dx_d + b$

  * 2차 곡선 모델을 사용하는 경우 매개 변수의 수 크게 증가
    * 매개 변수 수 = $d^2 + d + 1$
      * 예시
        * Iris 데이터 : $d = 4$이므로 21개의 매개 변수
        * MNIST 데이터 : $d = 784$ 이므로 615,441개의 매개 변수     
 
 $y = w_1x^2_1 + w_2x^2_2 + ... + w_dx^2_d + w_{d+1}x_1x_2 + ... + w_{d^2}x_{d-1}x_d+w_{{d^2}+1}x_1+...+w_{{d^2}+d}x_d+b$

#### 다차원 특징 공간 예제
* 특징이 너무 많으면 목표값에 대한 정확도 감소
* 올바른 학습 발생 불가

![dimensionN](https://github.com/BangYunseo/TIL/blob/main/AI/MachineLearning/Image/ch00/dimensionN.PNG) 

## 3절. 데이터
#### 데이터에 대한 이해 
* 객체가 자식 클래스의 멤버와 부모 클래스에 선언된 모양 그대로 멤버들을 가지고 탄생
      
![HumanAndMachine](https://github.com/BangYunseo/TIL/blob/main/AI/MachineLearning/Image/ch00/HumanAndMachine.PNG) 
      
 
#### 객체 지향 특성 3 - 다형성(Polymorphism)
* 하나의 기능이 경우에 따라 다르게 보이거나 다르게 작동하는 현상
* 연산자 중복, 함수 중복, 함수 재정의(overriding)

![Polymorphism](https://github.com/BangYunseo/TIL/blob/main/Language/Cpp/Image/ch01/Polymorphism.PNG)

#### C++ 언어에서 객체 지향을 도입한 목적
* 소프트웨어 생산성 향상
  * 소프트웨어의 생명 주기 단축 문제 해결 필요
  * 기 작성된 코드의 재사용 필요
  * C++ 클래스 상속 및 객체 재사용으로 해결
* 실세계에 대한 쉬운 모델링
  * 과거의 소프트웨어
    * 수학 연산이나 통계 처리에 편리한 절차 지향 언어 적함
  * 현대의 소프트웨어
    * 물체 혹은 객체의 상호 작용에 대한 묘사 필요
    * 실세계는 객체로 구성된 세계
    * 객체를 중심으로 하는 객체 지향 언어 적합

#### 절차 지향 프로그래밍과 객체 지향 프로그래밍
![Programming2](https://github.com/BangYunseo/TIL/blob/main/Language/Cpp/Image/ch01/Programming2.PNG)


## 3절. 추가 설명
#### 제네릭 프로그래밍
* 제네릭 함수와 제네릭 클래스
  * 제네릭 함수(Generic Function)
    * 동일한 프로그램 코드에 다양한 데이터 타입을 적용할 수 있게 일반화시킨 함수
  * 제네릭 클래스(Generic Class)
    * 동일화 프로그램 크도에 다양한 데이터 타입을 적용할 수 있게 일반화시킨 클래스
  * template 키워드로 선언
    * 템플릿 함수 혹은 템플릿 클래스라고 불림
  * Java, C# 등 다른 언어에도 동일한 개념 존재
* 제네릭 프로그래밍(Generic Programming)
  * 제네릭 함수와 제네릭 클래스를 활용하여 프로그램을 작성하는 새로운 프로그램 패러다임

#### 링킹
* 목적 파일끼리 합쳐 실행 파일을 만드는 과정
  * 목적 파일은 바로 실행할 수 없음
* 목적 파일과 C++ 표준 라이브러리의 함수 연결
* 실행 파일을 만드는 과정

![Linking](https://github.com/BangYunseo/TIL/blob/main/Language/Cpp/Image/ch01/Linking.PNG)

#### C++ 표준 라이브러리
* C++ 표준 라이브러리는 3개의 그룹으로 구분
  * C 라이브러리
    * 기존 C 표준 라이브러리를 수용
    * C++에서 사용할 수 있게 한 함수들
    * 이름이 c로 시작하는 헤더파일에 선언됨
  * C++ 입출력 라이브러리
    * 콘솔 및 파일 입출력을 위한 라이브러리
  * C++ STL 라이브러리
    * 제네릭 프로그래밍을 지원하기 위한 템플릿 라이브러리

![Library](https://github.com/BangYunseo/TIL/blob/main/Language/Cpp/Image/ch01/Library.PNG)
