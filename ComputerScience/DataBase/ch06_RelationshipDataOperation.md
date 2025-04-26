# Chapter 6. 관계 데이터 연산(Relationship Data Operation)

> 1절. 관계 데이터 연산 개념
>
> 2절. 관계 대수
>
> 3절. 관계 해석

## 1절. 관계 데이터 연산 개념

### 데이터 모델(Data Model)

- 데이터 모델링 결과물 표현 도구

|        종류        | 설명                                                                                       | 예시                                      |
| :----------------: | :----------------------------------------------------------------------------------------- | :---------------------------------------- |
| 개념적 데이터 모델 | 사람의 머리로 이해하도록 현실 세계를 모델링하여 데이터베이스의 개념적 구조로 표현하는 도구 | 개체-관계 모델(Entity-Relationship Model) |
| 논리적 데이터 모델 | 개념적 구조를 논리적 모델링하여 데이터베이스의 논리적 구조로 표현하는 도구                 | 관계 데이터 모델                          |

### 데이터 모델 구성

<img src="https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch06/ch06-01-DataModel.PNG" width="70%" height="auto" />

| 데이터 구조 종류 | 설명                                                                            |
| :--------------: | :------------------------------------------------------------------------------ |
|   개념적 구조    | 현실 세계를 개념 세계로 추상화 시 어떤 요소로 구성되었는지 표현하는 개념적 구조 |
|   논리적 구조    | 데이터를 어떤 모습으로 저장할지 표현하는 논리적 구조                            |

### 관계 데이터 연산(Relational Data Operation)

- 관계 데이터 모델 연산
- 원하는 데이터를 얻기 위해 릴레이션에 필요한 처리 요구 수행

|   종류    |
| :-------: |
| 관계 대수 |
| 관계 해석 |

<img src="https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch06/ch06-02-TypeOfRDO.PNG" width="70%" height="auto" />

### 관계 대수와 관계 해석 역할

- 데이터 언어 유용성 검증 기준
- 관계 대수·관계 해석으로 기술 가능한 모든 질의를 기술하는 데이터 언어 : 관계적으로 완전함(relationally complete)
- 질의(query) : 데이터에 대한 처리 요구

## 2절. 관계 대수

### 관계 대수 연산자(Relational Algebra Operator)

<img src="https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch06/ch06-03-RA.PNG" height="auto" />

- 절차적 언어(Procedural Language)
- 원하는 결과를 위해 릴레이션 처리 과정을 순서대로 기술하는 언어
- 릴레이션을 처리하는 연산자들(8개) 모임
  - 일반 집합 연산자
  - 순수 관계 연산자
- 폐쇄적 특성(closure property)
  - 피연산자·연산의 결과 모두 릴레이션

### 일반 집합 연산자(Set Operation)

- 릴레이션이 튜플의 집합인 개념을 이용하는 연산자

| 연산자          | 기호 | 표현  | 의미                                                                             |
| :-------------- | :--: | :---- | :------------------------------------------------------------------------------- |
| 합집합          |  ∪   | R ∪ S | 릴레이션 R과 S의 합집합 반환                                                     |
| 교집합          |  ∩   | R ∩ S | 릴레이션 R과 S의 교집합 반환                                                     |
| 차집합          |  -   | R - S | 릴레이션 R과 S의 차집합 반환                                                     |
| 카티션 프로덕트 |  ✕   | R ✕ S | 릴레이션 R의 각 튜플과 릴레이션 S의 각 튜플을 모두 연결 후 만든 새로운 튜플 반환 |

<img src="https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch06/ch06-04-NSO.PNG" width="70%" height="auto" />

| 특성                             | 조건                          |
| :------------------------------- | :---------------------------- |
| 2개의 피연산자                   | 2개의 릴레이션 대상 연산 수행 |
| 피연산자 두 릴레이션의 합병 필요 | 합집합·교집합·차집합의 경우   |

| 합병 가능 (union-compatible) 조건              |
| :--------------------------------------------- |
| 두 릴레이션의 동등한 차수                      |
| 두 릴레이션에서 서로 대응되는 속성 도메인 일치 |

<img src="https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch06/ch06-05-UnionCompatible.PNG" width="70%" height="auto" />

#### 합집합(Union) : R ∪ S

- 합병 가능한 두 릴레이션 R과 S의 합집합

| 결과 릴레이션 튜플 조건 |
| :---------------------: |
|    릴레이션 R에 속함    |
|    릴레이션 S에 속함    |

|   결과 릴레이션 특징    | 설명                         |
| :---------------------: | :--------------------------- |
|      차수(Degree)       | 릴레이션 R과 S의 차수와 동일 |
| 카디널리티(Cardinality) | R ∪ S 카디널리티 >= R or S   |
|       교환적 특징       | R ∪ S = S ∪ R                |
|       결합적 특징       | (R ∪ S) ∪ T = R ∪ (S ∪ T)    |

<img src="https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch06/ch06-06-UnionEX.PNG" width="70%" height="auto" />

#### 2. 교집합(Intersection) : R ∩ S

- 합병 가능한 두 릴레이션 R과 S의 교집합

|        결과 릴레이션 튜플 조건        |
| :-----------------------------------: |
| 릴레이션 R과 S에 공통으로 속하는 튜플 |

|   결과 릴레이션 특징    | 설명                         |
| :---------------------: | :--------------------------- |
|      차수(Degree)       | 릴레이션 R과 S의 차수와 동일 |
| 카디널리티(Cardinality) | R ∪ S 카디널리티 <= R or S   |
|       교환적 특징       | R ∩ S = S ∩ R                |
|       결합적 특징       | (R ∩ S) ∩ T = R ∩ (S ∩ T)    |

<img src="https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch06/ch06-07-IntersectionEX.PNG" height="auto" />

#### 3. 차집합(Difference) : R - S

- 합병 가능한 두 릴레이션 R과 S의 차집합

|                   결과 릴레이션 튜플 조건                   |
| :---------------------------------------------------------: |
| 릴레이션 R에는 존재하지만 릴레이션 S에는 존재하지 않는 튜플 |

|   결과 릴레이션 특징    | 설명                                           |
| :---------------------: | :--------------------------------------------- |
|      차수(Degree)       | 릴레이션 R과 S의 차수와 동일                   |
| 카디널리티(Cardinality) | R - S 카디널리티 or S - R 카디널리티 <= R or S |
|       교환적 특징       | 없음                                           |
|       결합적 특징       | 없음                                           |

<img src="https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch06/ch06-08-DifferenceEX.PNG" height="auto" />

#### 4. 카티션 프로덕트(Cartesian Product) : R ✕ S

- 두 릴레이션 R과 S의 카티션 프로덕트

|                                  결과 릴레이션 튜플 조건                                   |
| :----------------------------------------------------------------------------------------: |
| 릴레이션 R에 속한 각 튜플과 릴레이션 S에 속한 각 튜플을 모두 연결하여 만들어진 새로운 튜플 |

|   결과 릴레이션 특징    | 설명                                            |
| :---------------------: | :---------------------------------------------- |
|      차수(Degree)       | 릴레이션 R과 S의 차수를 더한 것과 동일          |
| 카디널리티(Cardinality) | R ✕ S 카디널리티 == R 카디널리티 ✕ S 카디널리티 |
|       교환적 특징       | R ✕ S · S ✕ R                                   |
|       결합적 특징       | (R ✕ S) ✕ T = R ✕ (S ✕ T)                       |

<img src="https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch06/ch06-09-CartesianProduct.PNG" height="auto" />

### 순수 관계 연산자(Relational Operation)

- 릴레이션의 구조와 특성을 이용하는 연산자

| 연산자   | 기호 | 표현                | 의미                                                                     |
| :------- | :--: | :------------------ | :----------------------------------------------------------------------- |
| 셀렉트   |  σ   | $σ_{조건식}(R)$     | 릴레이션 R에서 조건을 만족하는 튜플들 반환                               |
| 프로젝트 |  π   | $π_{속성리스트}(R)$ | 릴레이션 R에서 주어진 속성들의 값으로만 구성된 튜플들 반환               |
| 조인     |  -   | R ▷◁ S              | 공통 속성으로 릴레이션 R과 S의 튜플들을 연결하여 만든 새로운 튜플들 반환 |
| 디비전   |  ÷   | R ÷ S               | 릴레이션 S의 모든 튜플과 관련이 있는 릴레이션 R의 튜플들 반환            |

<img src="https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch06/ch06-10-RO.PNG" width="70%" height="auto" />

#### 1. 셀렉트(Select) · 셀렉션(Selection)

|   결과 릴레이션 튜플 조건   |
| :-------------------------: |
| 조건을 만족하는 튜플만 선택 |

|  결과 릴레이션 특징  | 설명                                                                                                        |
| :------------------: | :---------------------------------------------------------------------------------------------------------- |
|     단항 연산자      | 하나의 릴레이션 대상 연산                                                                                   |
|    수학적 표현법     | $σ_{조건식}(릴레이션)$                                                                                      |
| 데이터 언어적 표현법 | 릴레이션 WHERE 조건식                                                                                       |
|    결과 릴레이션     | 연산 대상 릴레이션의 수평적 부분 집합                                                                       |
|     교환적 특징      | $σ_{조건식1}(σ_{조건식2}(릴레이션)) = σ_{조건식2}(σ_{조건식1}(릴레이션)) = σ_{조건식1 ∧ 조건식2}(릴레이션)$ |

- 조건(Predicate : 조건)식
  - 비교식 · 프레디킷
  - 속성이나 상수의 비교 · 속성들 간 비교로 표현
  - 비교 연산자(> · ≥ · < · ≤ · = · ≠)
  - 논리 연산자(∧(and), ∨(or), ¬(not))

<img src="https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch06/ch06-14-OperationRelation.PNG" width="70%" height="auto" />

#### 고객 릴레이션의 셀렉션 연산

- 고객 릴레이션

<img src="https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch06/ch06-11-CustomRelation.PNG" width="70%" height="auto" />

| ex 1 : 등급이 gold인 튜플 검색 | <img src="https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch06/ch06-12-SelectEX1.PNG" width="70%" height="auto" /> |
| ------------------------------ | --------------------------------------------------------------------------------------------------------------------------------------------- |

| ex 2 : 등급이 gold이고 적립금이 2000 이상인 튜플 검색 | <img src="https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch06/ch06-13-SelectEX2.PNG" width="70%" height="auto" /> |
| ----------------------------------------------------- | --------------------------------------------------------------------------------------------------------------------------------------------- |

### 2. 프로젝트(Project) 또는 프로젝션(Projection)

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

### 3. 조인(Join)

- 두 릴레이션을 조합하여 결과 릴레이션 구성
- 조인 속성의 값이 같은 튜플만 연결하여 생성된 투플을 결과 릴레이션에 포함
  - 조인 속성 : 두 릴레이션의 공통 속성
- 수학적 표현법 : 릴레이션1 ⋈ 릴레이션2
- 동등 조인(equi-join)이라고도 함

- 조인 예시 (조인 속성 : 고객 릴레이션의 고객아이디, 주문 릴레이션의 주문 고객)

<img src="https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch06/ch06-19-JoinEX.PNG" width="70%" height="auto" />

> 정소화 고객이 주문한제품을 검색하고자 할 경우 조인 연산 필요

<img src="https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch06/ch06-20-JoinEX2.PNG" width="70%" height="auto" />

<img src="https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch06/ch06-21-JoinEX3.PNG" width="70%" height="auto" />

> 어느 릴레이션 소속인지 구분을 위해 '릴레이션.속성이름'형식의 표기

### 조인 종류

#### 세타 조인(theta-join, θ-join)

- 동등 조인에 비해 더 일반화
- 주어진 조인 조건을 만족하는 두 릴레이션의 모든 튜플을 연결하여 생성된 새로운 튜플로 결과 릴레이션 구성
- 결과 릴레이션의 차수(Degree) = 두 릴레이션 차수의 합
- 수학적 표현법 : 릴레이션1 $⋈_{A θ B}$ 릴레이션2
  - θ : 비교 연산자($>, ≥, <, ≤, =, ≠$)

#### 동등 조인(equi-join)

- θ 연산자가 "=" 인 세타 조인을 의미
- 수학적 표현법 : 릴레이션1 $⋈_{A = B}$ 릴레이션2
  - ex) 고객 $⋈_{고객.고객아이디 = 주문.주문아이디}$ 주문

#### 자연 조인(Natural Join)

- 동등 조인의 결과 릴레이션에서 조인 속성이 한 번만 나타나게 하는 연산
- 수학적 표현법 : 릴레이션1 $⋈_N$ 릴레이션2

<img src="https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch06/ch06-22-Join.PNG" width="70%" height="auto" />

##### 자연 조인 예시

1. 고객과 주문 릴레이션

<img src="https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch06/ch06-23-NJex.PNG" width="70%" height="auto" />

2. 2개의 속성으로 이루어진 조인 속성 이용

<img src="https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch06/ch06-24-NJex2.PNG" width="70%" height="auto" />

### 4. 디비전(Division)

- 수학적 표현법 : 릴레이션1 ÷ 릴레이션2
- 릴레이션 2의 모든 튜플과 관련이 있는 릴레이션 1의 튜플로 결과 릴레이션 구성
  - 단, 릴레이션 1이 릴레이션 2의 모든 속성을 포함해야 연산 가능
  - 도메인이 같아야 함
- 릴레이션의 속성 값 집합으로 연산 수행 : R ÷ S

<img src="https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch06/ch06-25-Division.PNG" width="70%" height="auto" />

##### 디비전 예시

1. 고객과 우수등급 릴레이션

<img src="https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch06/ch06-26-DivisionEx1.PNG" width="70%" height="auto" />

2. 주문내역, 제품1, 제품2 릴레이션

<img src="https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch06/ch06-27-DivisionEx2.PNG" width="70%" height="auto" />

### 관계 대수를 이용한 질의 표현 예시

1. 고객과 주문 릴레이션

<img src="https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch06/ch06-28-JoinEx1.PNG" width="70%" height="auto" />

2. 등급이 gold인 고객의 이름과 나이

<img src="https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch06/ch06-29-JoinEx2.PNG" width="70%" height="auto" />

3. 고객이름이 원유선인 고객의 등급과 원유선 고객이 주문한 주문제품, 수량

<img src="https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch06/ch06-30-JoinEx3.PNG" width="70%" height="auto" />

<img src="https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch06/ch06-31-JoinEx3Res.PNG" width="70%" height="auto" />

4. 주문 수량이 10개 미만인 주문 내역을 제외한 검색

<img src="https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch06/ch06-32-JoinEx4.PNG" width="70%" height="auto" />

<img src="https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch06/ch06-33-JoinEx4Res.PNG" width="70%" height="auto" />

#### 세미 조인(Semi Join)

- 프로젝트 연산을 수행한 릴레이션을 이용하는 조인
- 수학적 표현법 : 릴레이션 1 ⋉ 릴레이션 2
- 릴레이션 2를 조인 속성으로 프로젝트 연산 후, 릴레이션 1에 자연 조인하여 결과 릴레이션 구성
- 불필요한 속성을 미리 제거하여 조인 연산 비용을 줄이는 장점
- 교환적 특징이 없음
  - R ⋉ S ≠ S ⋉ R

##### 세미 조인 예시

1. 고객과 주문 릴레이션의 세미 조인

<img src="https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch06/ch06-34-SemiJoinEx1.PNG" width="70%" height="auto" />

2. 왼쪽이 닫힌 세미 조인

<img src="https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch06/ch06-35-SemiJoinEx2.PNG" width="70%" height="auto" />

## 수정이필요해요ㅛㅛㅛㅛㅛㅛㅛㅛㅛㅛㅛㅛ

#### 외부 조인(Outer Join)

- 자연 조인 연산에서 제외되는 투플도 결과 릴레이션에 포함시키는 조인
  • 두 릴레이션에 있는 모든 투플을 결과 릴레이션에 포함시킴
  § 표현법 : 릴레이션1 ⋈+ 릴레이션2
  § 자연조인 시 조인에 실패한 투플을 모두 보여주되 값이 없는 대응 속성에는 NULL 값을 채워서 반환
  § 모든 속성을 보여주는 기준 릴레이션 위치에 따라 왼쪽(left) 외부조인, 오른쪽(right) 외부조인, 완전(full, 양
  쪽) 외부조인으로 나뉨
  § 형식 : 왼쪽(left) 외부조인 – R (r, s) S (릴레이션1 ⋈+ 릴레이션2)
  완전(full) 외부조인 – R (r, s) S
  오른쪽(right) 외부조인 - R (r, s) S
