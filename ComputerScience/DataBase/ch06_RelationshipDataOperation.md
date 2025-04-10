# Chapter 6. 관계 데이터 연산(Relationship Data Operation)

> 1절. 관계 데이터 연산 개념
>
> 2절. 관계 대수
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
|카티션 프로덕트|✕|R ✕ S|릴레이션 R의 각 튜플과 릴레이션 S의 각 튜플을 모두 연결하여 만든 새로운 튜플 반환|

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
- 결과 릴레이션 특징
   - 차수는 릴레이션 R과 S의 차수와 같음
   - R–S의 카디널리티는 릴레이션 R의 카디널리티와 같거나 적음
   - S–R의 카디널리티는 릴레이션 S의 카디널리티와 같거나 적음
- 교환적, 결합적 특징 없음

<img src="https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch06/ch06-08-DifferenceEX.PNG" width="70%" height="auto" />

4) 카티션 프로덕트(Cartesian Product)

: R✕S
- 두 릴레이션 R과 S의 카티션 프로덕트
  - 릴레이션 R에 속한 각 튜플과 릴레이션 S에 속한 각 튜플을 모두 연결하여 만들어진 새로운 튜플로 결과 릴레이션 구성
- 결과 릴레이션 특징
  - 차수는 릴레이션 R과 S의 차수를 더한 것과 동일
  - 카디널리티는 릴레이션 R과 S의 카디널리티를 곱한 것과 동일
- 교환적 특징 : R✕S, S✕R
- 결합적 특징 : (R✕S)✕T = R✕(S✕T)

<img src="https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch06/ch06-09-CartesianProduct.PNG" width="70%" height="auto" />

#### 순수 관계 연산자(Relational Operation)

- 릴레이션의 구조와 특성을 이용하는 연산자

|연산자|기호|표현|의미|
|:---|:---:|:--|:---|
|셀렉트|σ|$σ_{조건식}(R)$|릴레이션 R에서 조건을 만족하는 튜플들 반환|
|프로젝트|π|$π_{속성리스트}(R)$|릴레이션 R에서 주어진 속성들의 값으로만 구성된 튜플들을 반환|
|조인|-|R ▷◁ S|공통 속성을 이용해 릴레이션 R과 S의 튜플들을 연결하여 만든 새로운 튜플들 반환|
|디비전|÷|R ÷ S|릴레이션 S의 모든 튜플과 관련이 있는 릴레이션 R의 튜플들 반환|

<img src="https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch06/ch06-10-RO.PNG" width="70%" height="auto" />

1) 셀렉트(Select) 또는 셀렉션(Selection)

- 릴레이션에서 조건을 만족하는 튜플만 선택하여 결과 릴레이션 구성
- 하나의 릴레이션을 대상으로 연산 수행 : 단항 연산자
- 수학적 표현법 : $σ_{조건식}(릴레이션)$
- 데이터 언어적 표현법 : 릴레이션 where 조건식
- 조건식
  - 비교식, 프레디킷(predicate : 조건)
  - 속성과 상수의 비교나 속성들 간의 비교로 표현
  - 비교 연산자(>, ≥, <, ≤, =, ≠)와 논리 연산자(∧(and), ∨(or), ¬(not))를 이용해 작성
- 결과 릴레이션은 연산 대상 릴레이션의 수평적 부분 집합

<img src="https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch06/ch06-14-OperationRelation.PNG" width="70%" height="auto" />

- 교환적 특징 : $σ_{조건식1}(σ_{조건식2}(릴레이션)) = σ_{조건식2}(σ_{조건식1}(릴레이션)) = σ_{조건식1 ∧조건식2}(릴레이션)$
- ex) 도서 릴레이션에서 가격이 8,000원 이하이고 도서번호가 3 이상인 책 검색
  - σ_{가격 <= 8000 ∧ 도서번호 >= 3}(도서)

#### 고객 릴레이션에서 셀렉션 연산 예제

- 고객 릴레이션

<img src="https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch06/ch06-11-CustomRelation.PNG" width="70%" height="auto" />

- ex 1) 등급이 gold인 튜플 검색

<img src="https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch06/ch06-12-SelectEX1.PNG" width="70%" height="auto" />

- ex 2) 등급이 gold이고 적립금이 2000 이상인 튜플 검색

<img src="https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch06/ch06-13-SelectEX2.PNG" width="70%" height="auto" />

2) 프로젝트(Project) 또는 프로젝션(Projection)

- 릴레이션에서 선택한 속성 값으로 결과 릴레이션 구성
  - 수직적 연산자 : 결과 릴레이션은 연산 대상 릴레이션의 수직적 부분집합
- 하나의 릴레이션 대상 연산 수행 : 단항 연산자
- 수학적 표현법 : $π_{속성리스트}(릴레이션)$
- 데이터 언어적 표현법 : 릴레이션\[속성리스트\]

- 프로젝션 예시
<img src="https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch06/ch06-15-ProjectionEX.PNG" width="70%" height="auto" />

- 결과 릴레이션은 연산 대상 릴레이션의 수직적 부분 집합
 
<img src="https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch06/ch06-18-ProjectionVertical.PNG" width="70%" height="auto" />

#### 고객 릴레이션에서 프로젝션 연산 예제

- 고객 릴레이션

<img src="https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch06/ch06-11-CustomRelation.PNG" width="70%" height="auto" />

- ex 1) 고객이름, 등급, 적립금 검색

<img src="https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch06/ch06-16-ProjectionEX2.PNG" width="70%" height="auto" />

- ex 2) 등급 검색

<img src="https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch06/ch06-17-ProjectionEX3.PNG" width="70%" height="auto" />

> 동일한 튜플은 중복 없이 한 번만 출력

3) 조인(Join)

- 두 릴레이션을 조합하여 결과 릴레이션 구성
- 조인 속성의 값이 같은 튜플만 연결하여 생성된 투플을 결과 릴레이션에 포함
  - 조인 속성 : 두 릴레이션의 공통 속성
- 수학적 표현법 : 릴레이션1 ⋈ 릴레이션2
- 동등 조인(equi-join)이라고도 함

- 조인 예시 (조인 속성 : 고객 릴레이션의 고객아이디, 주문 릴레이션의 주문 고객)

> 정소화 고객이 주문한제품을 검색하고자 할 경우 조인 연산 필요

<img src="https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch06/ch06-19-JoinEX.PNG" width="70%" height="auto" />

## 여기부터 수정 필요!!!

- 결과 릴레이션은 연산 대상 릴레이션의 수직적 부분 집합
 
<img src="https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch06/ch06-17-ProjectionVertical.PNG" width="70%" height="auto" />

#### 고객 릴레이션에서 프로젝션 연산 예제

- 고객 릴레이션

<img src="https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch06/ch06-11-CustomRelation.PNG" width="70%" height="auto" />

- ex 1) 고객이름, 등급, 적립금 검색

<img src="https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch06/ch06-15-ProjectionEX2.PNG" width="70%" height="auto" />

- ex 2) 등급 검색

<img src="https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch06/ch06-16-ProjectionEX3.PNG" width="70%" height="auto" />

> 동일한 튜플은 중복 없이 한 번만 출력
> 
(수정필요)
