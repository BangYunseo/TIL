# Chapter 5. 관계 데이터 모델

> 1절. 관계 데이터 모델 개념
>
> 2절. 관계 데이터 모델의 제약

## 1절. 관계 데이터 모델의 개념

### 관계 데이터 모델
- 개념적 구조를 논리적 구조로 표현하는 논리적 데이터 모델
- 하나의 개체에 대한 데이터를 하나의 릴레이션에 저장

<img src="https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch05/ch05-01-Relation.PNG" width="100%" height="auto" />

- 고객 릴레이션
  - 차수(Degree) : 6
  - 카디널리티(Cardinality) : 4

### 기본 용어

#### 1) 릴레이션(Relation)

  - 하나의 개체에 관한 데이터를 2차원 테이블의 구조로 저장
  - 행과 열로 구성된 테이블
  - 파일 관리 시스템 관점에서 파일(file)에 대응
  - 릴레이션 내에서 생성되는 관계 : 릴레이션 내 데이터들의 관계

<img src="https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch05/ch05-02-DataTable.PNG" width="70%" height="auto" />

  - 릴레이션 간에 생성되는 관계 : 릴레이션 간의 관계

<img src="https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch05/ch05-03-RR.PNG" width="70%" height="auto" />

#### 2) 속성(Attribute)

  - 릴레이션의 열
  - 파일 관리 시스템 관점에서 필드(field)에 대응

#### 3) 튜플(Tuple)

  - 릴레이션의 행
  - 파일 관리 시스템 관점에서 레코드(record)에 대응

#### 4) 도메인(Domain)

  - 하나의 속성이 가질 수 있는 모든 값의 집합
  - 속성값을 입력 및 수정할 때 적합성 판단의 기준
  - 일반적으로 속성의 특성을 고려한 데이터 타입으로 정의

#### 5) 널(NULL)

  - 속성값을 아직 모르거나 해당되는 값이 없음

#### 6) 차수(Degree)

  - 하나의 릴레이션에서 속성의 전체 개수

#### 7) 카디널리트(Cardinality)

  - 하나의 릴레이션에서 튜플의 전체 개수

- 예시

<img src="https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch05/ch05-04-RelationEX.PNG" width="100%" height="auto" />

### 릴레이션 구성

<img src="https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch05/ch05-05-SchemaInstance.PNG" width="100%" height="auto" />

#### 1) 릴레이션 스키마(Relation Schema)

  - 릴레이션의 논리적 구조
    - 속성(Attribute) : 릴레이션 스키마 열
    - 도메인(Domain) : 속성이 가질 수 있는 값의 집합
    - 차수(Degree) : 속성의 개수
 
  - 릴레이션의 이름과 릴레이션에 포함된 모든 속성 이름으로 정의
    - ex) 고객(고객아이디, 고객이름, 나이, 등급, 직업, 적립금)
  - 릴레이션 내포(Relation Intension)라고도 함
  - 정적인 특징

#### 2) 릴레이션 인스턴스(Relation Instance)
  - 어느 한 시점에 릴레이션에 존재하는 튜플들의 집합
    - 튜플(Tuple) : 릴레이션의 행
    - 카디널리티(Cardinality) : 튜플의 수
 
  - 릴레이션의 외연(Relation Extension)이라고도 함
  - 동적인 특징

#### 다중 값 속성, 동일한 튜플

##### 1) 다중 값 속성을 포함하는 릴레이션

<img src="https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch05/ch05-06-ManyValues.PNG" width="100%" height="auto" />

  - 다중 값을 가지는 직업 속성 포함
  - 관계 데이터 모델의 릴레이션으로 적합하지 않음


##### 2) 동일한 튜플이 중복되는 릴레이션

<img src="https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch05/ch05-07-SameTuple.PNG" width="100%" height="auto" />

  - 동일한 튜플이 중복될 수 없음
  - 속성의 값은 단일값이어야 함

#### 릴레이션 특성

1) 튜플의 유일성
   - 하나의 릴레이션에는 동일한 튜플 존재 불가
  
2) 튜플의 무순서
   - 하나의 릴레이션에서 튜플 사이의 순서는 무의미
  
3) 속성의 무순서
   - 하나의 릴레이션에서 속성 사이의 순서는 무의미
  
4) 속성의 원자성
   - 속성값으로 원자값만 사용 가능

### 데이터베이스 구성

<img src="https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch05/ch05-08-DBSchemaInstance.PNG" width="100%" height="auto" />

#### 1) 데이터베이스 스키마(DataBase Schema)

   - 데이터베이스 전체 구조
   - 데이터베이스를 구성하는 릴레이션 스키마 모음
  
#### 2) 데이터베이스 인스턴스(DataBase Instance)

   - 데이터베이스를 구성하는 릴레이션 인스턴스의 모음

### 키(Key)

- 릴레이션에서 특정 튜플들을 유일하게 식별하는 속성 or 속성의 집합
- 키가 되는 속성(혹은 속성의 집합)은 반드시 값이 달라서 튜플들을 서로 구별 가능해야 함
- 릴레이션 간의 관계를 맺을 때 사용

#### 특성

1) 유일성(Uniqueness)
   - 하나의 릴레이션에서 모든 튜플은 서로 다른 키 값을 가짐
  
2) 최소성(Minimality)
   - 꼭 필요한 최소한의 속성들로만 키 구성
  
### 데이터베이스 릴레이션 예시

<img src="https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch05/ch05-09-DBR.PNG" width="100%" height="auto" />

#### 종류 

<img src="https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch05/ch05-10-Key.PNG" width="80%" height="auto" />

1) 수퍼키(Super Key)
   - 유일성을 만족하는 속성 또는 속성의 집합
   - ex) 고객 릴레이션의 슈퍼키 : 고객아이디, (고객아이디, 고객이름), (고객이름, 주소) 등

   - 고객 릴레이션에서의 예시
     - 고객번호 : 고객별로 유일한 값 부여 => 튜플 식별 가능
     - 이름 : 동명이인이 있을 경우 튜플 식별 불가능
     - 주민번호 : 개인별로 유일한 값 부여 => 튜플 식별 가능
     - 주소 : 가족끼리는 동일한 정보를 사용하기에 튜플 식별 불가능
     - 핸드폰 : 한 사람이 여러 개의 핸드폰 사용 가능, 사용하지 않는 사람이 존재할 수 있으므로 튜플 식별 불가능
    
2) 후보키(Candidate Key)
   - 유일성과 최소성을 만족하는 속성 또는 속성의 집합
   - ex) 고객 릴레이션의 후보키 : 고객아이디, (고객이름, 주소) 등
  
   - 주문 릴레이션의 예시
     - 고객번호 : 한 명의 고객이 여러 권의 도서 구입 가능하므로 튜플 식별 불가능
     - 도서번호 : 도서번호가 같더라도 여러 번의 주문 기록이 있을 수 있으므로 튜플 식별 불가능
    
3) 기본키(Primary Key)
   - 후보키 중 기본적으로 사용하기 위한 키
   - ex) 고객 릴레이션의 기본키 : 고객아이디

   - 기본키 선정 고려사항
     - 릴레이션 내 튜플 식별 가능한 고유한 값 필요
     - NULL 값은 허용하지 않음
     - 키 값의 변동이 발생하지 않음
     - 최대한 적은 수의 속성을 가져야 함
   - 릴레이션 스키마 표현 시 기본키는 밑줄로 표시
     - 릴레이션 이름(<U>속성 1</U>, 속성 2, ..., 속성 N)
    
4) 대체키(Alternate Key)
   - 기본키로 선택되지 못한 후보키
   - ex) 고객 릴레이션의 대체키 : (고객이름, 주소)
  
5) 외래키(Foreign Key)

<img src="https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch05/ch05-11-FK.PNG" width="80%" height="auto" />

   - 다른 릴레이션의 기본키를 참조하는 속성 또는 속성의 집합
   - 릴레이션들 간의 관계 표현
     - 참조하는 릴레이션 : 외래키를 가진 릴레이션
     - 참조되는 릴레이션 : 외래키가 참조하는 기본키를 가진 릴레이션
   - 외래키 속성과 그것이 참조하는 기본키 속성의 이름은 달라도 되지만 도메인은 같아야 함

<img src="https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch05/ch05-12-FK2.PNG" width="80%" height="auto" />

  - 하나의 릴레이션에는 외래키가 여러 개 존재 가능
  - 외래키를 기본키로 사용 가능

<img src="https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch05/ch05-13-FK3.PNG" width="80%" height="auto" />

  - 같은 릴레이션의 기본키를 참조하는 외래키 정의 가능
  - 외래키는 NULL 값을 가질 수 있음

#### 릴레이션 간 참조 관계 예시

<img src="https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch05/ch05-14-RR.PNG" width="80%" height="auto" />

### 키 정리

- 특성

|특성|설명|
|:--:|:--|
|유일성|한 릴레이션에서 모든 튜플은 서로 다른 키 값 보유|
|최소성|꼭 필요한 최소한의 속성들로만 키 구성|

- 종류

|종류|설명|
|:---:|:---|
|수퍼키|유일성을 만족하는 속성 또는 속성의 집합|
|후보키|유일성과 최소성을 만족하는 속성 또는 속성의 집합|
|기본키|후보키 중 기본적으로 사용하기 위해 선택한 키|
|대체키|기본키로 선택되지 못한 후보키|
|외래키|다른 릴레이션의 기본키를 참조하는 속성 또는 속성의 집합|

## 2절. 관계 데이터 모델의 제약

### 무결성 제약조건(Integrity Constraint)

- 데이터의 무결성을 보장하고 일관된 상태를 유지하기 위한 규칙
- 무결성 : 데이터를 결함이 없는 상태, 정확하고 유효하게 유지

<img src="https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch05/ch05-15-IntegrityConstraint.PNG" width="80%" height="auto" />

#### 1) 도메인 무결성 제약조건

- 도메인 제약(Domain Constraint)
- 릴레이션 내의 튜플들이 각 속성의 도메인에 지정된 값만을 가지는 조건
- SQL 문에서 데이터 형식(type), 널(NULL / NOT NULL), 기본값(default), 체크(check) 등을 통해 지정

#### 2) 개체 무결성 제약조건

- 기본키 제약(Primary Key Constraint)
- 릴레이션은 기본키를 지정하고 기본키는 NULL 값을 가져서는 안된다는 조건
- 릴레이션 내에 오직 하나의 값만 존재해야 한다는 조건

#### 3) 참조 무결성 제약조건

- 외래키 제약(Foreign Key Constraint)
- 릴레이션 간 참조 관계 선언
- 자식 릴레이션의 외래키는 부모 릴레이션의 기본키와 도메인이 동일
- 자식 릴레이션의 값이 변경 시 부모 릴레이션의 제약을 받음

### 개체 무결성 제약조건(Entity Integrity Constraint) 삽입 / 수정 / 삭제

<img src="https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch05/ch05-16-EIC.PNG" width="80%" height="auto" />

- 삽입 : 기본키 값이 같으면 삽입 금지
- 수정 : 기본키 값이 같거나 NULL로도 수정 불가
- 삭제 : 특별한 확인이 불필요하며 즉시 수행

### 참조 무결성 제약조건(Referential Integrity Constraint)

- 외래키는 참조할 수 없는 값은 가질 수 없다는 규칙

<img src="https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch05/ch05-17-RIC.PNG" width="80%" height="auto" />

- 외래키 속성이 NULL 값을 가진다고 해서 참조 무결성 제약조건을 위반한 것은 아님

<img src="https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch05/ch05-18-RIC2.PNG" width="80%" height="auto" />

#### 예제로 이해하기

<img src="https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch05/ch05-19-RIC3.PNG" width="80%" height="auto" />

- 삽입
  - 학과(부모 릴레이션) : 튜플 삽입 후 수행 시 정상적으로 진행
  - 학생(자식 릴레이션) : 참조 받는 테이블에 외래키 값이 없다면 삽입 금지
 
- 삭제
  - 학과(부모 릴레이션) : 참조하는 테이블을 같이 삭제할 가능성이 있어 금지하거나 다른 추가 작업(제약조건 등)의 필요
  - 학생(자식 릴레이션) : 바로 삭제 가능

- 수정
  - 삭제와 삽입 명령 연속 수행
  - 부모 릴레이션의 수정이 발생할 경우 삭제 옵션에 따라 처리된 후 문제가 없으면 다시 삽입 제약 조건에 따라 처리
 
#### 참조 무결성 제약조건의 옵션(부모 릴레이션에서의 튜플 삭제)

<img src="https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch05/ch05-20-RIC4.PNG" width="80%" height="auto" />

|명령어|의미|예시|
|:---:|:---|:---|
|RESTRICTED|자식 릴레이션에서 참조하고 있는 경우 부모 릴레이션의 삭제 작업 요청 거부 및 중지(에러처리)|학과 릴레이션의 튜플 삭제 거부|
|CASCADE|자식 릴레이션의 관련 튜플을 같이 연쇄적으로 삭제|학생 릴레이션의 관련 튜플 삭제|
|DEFAULT|자식 릴레이션의 관련 튜플을 미리 설정한 값으로 변환|학생 리레이션의 학과가 다른 학과로 자동 배정|
|NULL|자식 릴레이션의 관련 튜플을 NULL 값으로 설정(NULL 값을 허가한 경우)|학과 릴레이션의 학과가 NULL 값으로 변경|
