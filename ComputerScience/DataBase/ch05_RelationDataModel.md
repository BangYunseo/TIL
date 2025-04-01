# Chapter 5. 관계 데이터 모델

> 1절. 관계 데이터 모델 개념
>
> 2절. 개체
>
> 3절. 속성
>
> 4절. 관계

## 1절. 관계 데이터 모델의 개념

### 관계 데이터 모델
- 개념적 구조를 논리적 구조로 표현하는 논리적 데이터 모델
- 하나의 개체에 대한 데이터를 하나의 릴레이션에 저장

<img src="https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch05/ch05-01-Relation.PNG" width="100%" height="auto" />

- 고객 릴레이션
  - 차수(Degree) : 6
  - 카디널리티(Cardinality) : 4

### 기본 용어

1) 릴레이션(Relation)

  - 하나의 개체에 관한 데이터를 2차원 테이블의 구조로 저장
  - 행과 열로 구성된 테이블
  - 파일 관리 시스템 관점에서 파일(file)에 대응
  - 릴레이션 내에서 생성되는 관계 : 릴레이션 내 데이터들의 관계

<img src="https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch05/ch05-02-DataTable.PNG" width="70%" height="auto" />

  - 릴레이션 간에 생성되는 관계 : 릴레이션 간의 관계

<img src="https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch05/ch05-03-RR.PNG" width="70%" height="auto" />

2) 속성(Attribute)

  - 릴레이션의 열
  - 파일 관리 시스템 관점에서 필드(field)에 대응

3) 튜플(Tuple)

  - 릴레이션의 행
  - 파일 관리 시스템 관점에서 레코드(record)에 대응

4) 도메인(Domain)

  - 하나의 속성이 가질 수 있는 모든 값의 집합
  - 속성값을 입력 및 수정할 때 적합성 판단의 기준
  - 일반적으로 속성의 특성을 고려한 데이터 타입으로 정의

5) 널(NULL)

  - 속성값을 아직 모르거나 해당되는 값이 없음

6) 차수(Degree)

  - 하나의 릴레이션에서 속성의 전체 개수

7) 카디널리트(Cardinality)

  - 하나의 릴레이션에서 튜플의 전체 개수

- 예시

<img src="https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch05/ch05-04-RelationEX.PNG" width="100%" height="auto" />

### 릴레이션 구성

<img src="https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch05/ch05-05-SchemaInstance.PNG" width="100%" height="auto" />

1) 릴레이션 스키마(Relation Schema)

  - 릴레이션의 논리적 구조
    - 속성(Attribute) : 릴레이션 스키마 열
    - 도메인(Domain) : 속성이 가질 수 있는 값의 집합
    - 차수(Degree) : 속성의 개수
 
  - 릴레이션의 이름과 릴레이션에 포함된 모든 속성 이름으로 정의
    - ex) 고객(고객아이디, 고객이름, 나이, 등급, 직업, 적립금)
  - 릴레이션 내포(Relation Intension)라고도 함
  - 정적인 특징

2) 릴레이션 인스턴스(Relation Instance)
  - 어느 한 시점에 릴레이션에 존재하는 튜플들의 집합
    - 튜플(Tuple) : 릴레이션의 행
    - 카디널리티(Cardinality) : 튜플의 수
 
  - 릴레이션의 외연(Relation Extension)이라고도 함
  - 동적인 특징

#### 다중 값 속성, 동일한 튜플

1) 다중 값 속성을 포함하는 릴레이션

<img src="https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch05/ch05-06-ManyValues.PNG" width="100%" height="auto" />

  - 다중 값을 가지는 직업 속성 포함
  - 관계 데이터 모델의 릴레이션으로 적합하지 않음


2) 동일한 튜플이 중복되는 릴레이션

<img src="https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch05/ch05-07-SameTuple.PNG" width="100%" height="auto" />

  - 동일한 튜플이 중복될 수 없음
  - 속성의 값은 단일값이어야 함

#### 릴레이션 특성

(여기부터 작성)

### 데이터베이스 구성

<img src="https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch05/ch05-08-DBSchemaInstance.PNG" width="100%" height="auto" />

1) 데이터베이스 스키마(DataBase Schema)

   - 데이터베이스 전체 구조
   - 데이터베이스를 구성하는 릴레이션 스키마 모음
  
2) 데이터베이스 인스턴스(DataBase Instance)

   - 데이터베이스를 구성하는 릴레이션 인스턴스의 모음

