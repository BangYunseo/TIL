# Chapter 6. 관계 데이터 연산(Relationship Data Operation)

> 1절. 관계 데이터 연산 개념
>
> 2절. 
>
> 3절. 
>
> 4절. 

## 1절. 관계 데이터 연산 개념

### 데이터 모델(Data Model)

- 데이터 모델링의 결과물을 표현하는 도구
- 개념적 데이터 모델 
  - 사람의 머리로 이해 가능하도록 현실 세계를 모델링하여 데이터베이스의 개념적 구조로 표현하는 도구
  - ex ) 개체-관계 모델(Entity-Relationship Model)
 
- 논리적 데이터 모델
  - 개념적 구조를 논리적 모델링하여 데이터베이스의 논리적 구조로 표현하는 도구
  - ex ) 관계 데이터 모델

### 데이터 모델 = 데이터 구조 + 연산 + 제약조건

<img src="https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch06/ch06-01-DataModel.PNG" width="70%" height="auto" />

1) 개념적 구조 : 현실세계를 개념 세계로 추상화 했을 때 어떤 요소로 이루어 있는지 표현하는 개념적구조

2) 논리적 구조 : 데이터를 어떤 모습으로 저장할 것인지 표현하는 구조
   
### 관계 데이터 연산(Relational Data Operation)

- 관계 데이터 모델의 연산
- 원하는 데이터를 얻기 위해 릴레이션에 필요한 처리 요구 수행
- 관계 대수, 관계 해석
   - 기능과 표현력 측면에서 동등한 능력
 
<img src="https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch06/ch06-02-TypeOfRDO.PNG" width="70%" height="auto" />

### 관계 대수와 관계 해석 역할

- 데이터 언어의 유용성 검증 기준
- 관계 대수나 관계 해석으로 기술 가능한 모든 질의를 기술하는 데이터 언어를 관계적으로 완전(relationally complete)하다고 판단
  - 질의(query) : 데이터에 대한 처리 요구
 
## 2절. 관계 대수

### 관계 대수(Relational Algebra) 개념

- 원하는 결과를 얻기 위해 릴레이션의 처리 과정을 순서대로 기술하는 언어
   - 절차 언어(procedural language)
- 릴레이션을 처리하는 연산자들의 모임
   - 대표 연산자 8개
   - 일반 집합 연산자와 순수 관계 연산자로 분류
- 폐쇄 특성(closure property) 존재
   - 피연산자도 연산의 결과도 모두 릴레이션
 

### 관계 대수 연산자

<img src="https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch06/ch06-03-RA.PNG" width="70%" height="auto" />

#### 일반 집합 연산자(Set Operation)

- 릴레이션이 튜플의 집합이라는 개념을 이용하는 연산자

|연산자|기호|표현|의미|
|:---|:---:|:--|:---|
|합집합|∪|R ∪ S|릴레이션 R과 S의 합집합 반환|
|교집합|∩|R ∩ S|릴레이션 R과 S의 교집합 반환|
|차집합|-|R - S|릴레이션 R과 S의 차집합 반환|
|카티션 프로덕트|||릴레이션 R의 각 튜플과 릴레이션 S의 각 튜플을 모두 연결하여 만든 새로운 튜플 반환|

<img src="https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch06/ch06-04-NSO.PNG" width="70%" height="auto" />

- 특성
  - 2개의 피연산자 필요 : 2개의 릴레이션을 대상으로 연산 수행
  - 합집합, 교집합, 차집합은 피연산자인 두 릴레이션이 합병 가능해야 함
    - 합병 가능 (union-compatible) 조건
      - 두 릴레이션의 동등한 차수
      - 두 릴레이션에서 서로 대응되는 속성의 도메인 일치
     
<img src="https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch06/ch06-05-UnionCompatible.PNG" width="70%" height="auto" />

1) 합집합(Union)

: R∪S
- 합병 가능한 두 릴레이션 R과 S의 합집합
   - 릴레이션 R에 속하거나 릴레이션 S에 속하는 모든 튜플들로 결과 릴레이션 구성
- 결과 릴레이션 특징
   - 차수는 릴레이션 R과 S의 차수와 동일
   - 카디널리티는 릴레이션 R과 S의 카디널리티를 더한 것과 같거나 적음
- 교환적 특징 : R∪S = S∪R
- 결합적 특징 : (R∪S)∪T = R∪(S∪T)

<img src="https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch06/ch06-06-UnionEX.PNG" width="70%" height="auto" />

2) 교집합(Intersection)

: R∩S
- 합병 가능한 두 릴레이션 R과 S의 교집합
   - 릴레이션 R과 S에 공통으로 속하는 튜플로 결과 릴레이션 구성
- 결과 릴레이션 특징
   - 차수는 릴레이션 R과 S의 차수와 동일
   - 카디널리티는 릴레이션 R과 S의 어떤 카디널리티보다 크지 않음
- 교환적 특징 : R∩S = S∩R
- 결합적 특징 : (R∩S)∩T = R∩(S∩T)

<img src="https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch06/ch06-07-IntersectionEX.PNG" width="70%" height="auto" />

3) 차집합(Difference)

: R-S
- 합병 가능한 두 릴레이션 R과 S의 차집합
   - 릴레이션 R에는 존재하지만 릴레이션 S에는 존재하지 않는 튜플로 결과 릴레이션 구성
- 결과 릴레이션 특성
   - 차수는 릴레이션 R과 S의 차수와 같음
   - R–S의 카디널리티는 릴레이션 R의 카디널리티와 같거나 적음
   - S–R의 카디널리티는 릴레이션 S의 카디널리티와 같거나 적음
- 교환적, 결합적 특징 없음

<img src="https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch06/ch06-08-DifferenceEX.PNG" width="70%" height="auto" />

(pdf 18쪽)
