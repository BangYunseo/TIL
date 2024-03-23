# Chapter 0. 데이터베이스란?

> [참고 강의](http://www.youtube.com/playlist?list=PLcXyemr8ZeoREWGhhZi5FZs6cvymjIBVe)
>
> 1절. DB, DBMS, DB System
>
> 2절. Data Models
>
> 3절. DB schema & state
>
> 4절. DB Language(DDL, DML, etc.)

## 1절. 기본 개념
#### 데이터베이스(DB)의 개념
* 데이터베이스 : DataBase
* 전자적으로 저장되고 사용되는 관련있는 데이터들의 조직화된 집합
  * 관련있는 데이터들
    * 같은 목적으로 서비스되거나 같은 출처를 가진 데이터들
  * 조직화된 집합
    * 데이터 탐색 및 중복 데이터를 걸러낼 때 효율적
    * 데이터 불일치 해결 가능

#### 데이터베이스 관리 시스템(DBMS)의 개념
* 데이터베이스 관리 시스템 : DataBase Management Systems
* 사용자에게 DB를 정의하고 만들며 관리하는 기능을 제공하는 소프트웨어 시스템
* 대표적인 DBMS의 예시
  * PostgreSQL
  * MySQL
  * ORACLE
  * SQL Server

#### 메타데이터(metadata)의 개념
* data-about-data : 데이터를 설명하기 위한 데이터
* DBMS에서 DB를 정의하거나 기술하는 부가적인 데이터
* DBMS를 통해 저장, 관리
* 다른 명칭 : catalog
* 대표적인 metadata 사용 예시
  * 데이터 유형, 구조, 제약 조건, 보안, 저장, 인덱스, 사용자 그룹 등

#### 데이터베이스 시스템(DataBase System)의 개념
* DataBase + DBMS + 연관된 어플리케이션들
* 데이터베이스 시스템을 DataBase라고 부르기도 함
* DataBase와 DataBase System의 차이점
  * DataBase
    * 순수하게 조직화된 데이터의 집합
  * DataBase System
    * 여러 데이터베이스 및 타 시스템의 집합

![database](https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch01/database.PNG)

## 2절. Data Models
#### 데이터 모델(Data Models)의 개념
* DB의 구조(structure)를 기술하는데 사용될 수 있는 개념들이 모인 집합
* DB의 구조를 추상화해서 표현할 수 있는 수단 제공
* Data Model은 여러 종류 존재
  * 추상화 수준과 DB 구조화 방식에 차이 존재
* DB에서 읽고 쓰기 위한 기본적인 동작들(operations)도 포함
* DB의 구조 : 데이터 유형, 데이터 관계(relationship), 제약 사항(constraints) 등

#### Data Models 분류
* 개념적 데이터 모델
  * conceptual(or high-level) data models
* 논리적 데이터 모델
  * logical(or representational) data models
* 물리적 데이터 모델
  * physical(or low-level) data models

#### 개념적 데이터 모델(conceptual(or high-level) data models)
* 일반 사용자들이 쉽게 이해할 수 있는 개념들로 이루어진 모델
* 가장 높은 추상화 수준
* 비즈니스 요구사항을 추상화하여 기술할 때 사용

![concept](https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch01/concept.PNG)

#### 논리적 데이터 모델(logical(or representational) data models)
* 이해하기 어렵지 않으면서도 디테일하게 DB를 구조화할 수 있는 개념들 제공
* 데이터가 컴퓨터에 저장될 때 구조와 크게 다르지 않게 DB 구조화 가능
* 특정 DBMS나 storage에 종속되지 않는 수준에서 DB를 구조화할 수 있는 모델
* 백엔드 개발자가 가장 많이 사용하는 데이터 모델
* 테이블형 데이터 모델

![logical](https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch01/logical.PNG)

#### 논리적 데이터 모델의 종류
* 관계형 데이터 모델(relational data model)
  * 데이터를 테이블로 구성하고, 테이블 간의 관계를 통해 데이터를 표현하는 방식
  * 테이블은 행과 열로 구성
  * 각 행은 레코드(또는 튜플)를, 각 열은 속성(또는 필드)를 표현
  * 테이블들을 관리하고, SQL(Structured Query Language)을 사용하여 데이터를 조작하고 조회
  * ex) ORACLE, MySQL, MSSQL

* 객체 데이터 모델(object data model)
  * 객체 지향 프로그래밍의 개념을 기반으로 데이터를 모델링하는 방식
  * 데이터를 객체로 표현
  * 객체는 속성과 메서드(행위)를 보유
  * 객체 간에는 상속, 다형성, 캡슐화와 같은 객체 지향적인 특징을 이용하여 관계를 정의
  * 주로 객체 지향 프로그래밍 언어와 함께 사용
  * 객체 지향 데이터베이스 시스템에서 데이터를 관리

* 객체-관계형 데이터 모델(object-relational data model)
  * 관계형 데이터 모델과 객체 데이터 모델의 특징을 결합한 형태
  * 관계형 데이터베이스의 테이블과 객체 지향적인 데이터 모델의 객체를 함께 사용하여 데이터를 표현
  * 객체-관계형 매핑(Object-Relational Mapping, ORM)기술로 객체와 테이블 간의 변환과 관계를 정의
  * 객체 지향적인 특징을 관계형 데이터베이스에 반영
  * 객체 지향 언어와 관계형 데이터베이스 사이의 간극을 감소시킴
  * 객체 지향적인 설계와 관계형 데이터베이스의 성능을 모두 충족시키는데 사용
  * ex) PostgreSQL

#### 물리적 데이터 모델(physical(or low-level) data models)
* 컴퓨터에 데이터가 어떻게 파일 형태로 저장되는지 기술하는 수단 제
* ex) data format, data orderings, acess path 등
  * access path : 데이터 검색을 빠르게 하기 위한 구조체
    * ex) index

## 3절. DB schema & state
#### 데이터베이스 스키마(DB schema)
* Data Model을 바탕으로 DB의 구조를 기술한 것
* schema는 DB를 설계할 때 정해짐
* 한 번 정해진 후 자주 바뀌지 않음

* 관계형 데이터 모델에서의 schema

![schema](https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch01/schema.PNG)

#### 데이터베이스 상태(DB state)
* DB에 있는 실제 데이터는 자주 바뀔 가능성 존재
* 특정 시점에 DB에 있는 데이터를 DB state 혹은 snapshot이라고 함
* DB에 있는 현재 instances의 집합이라고 함

#### 3단계-스키마 구조(three-schema architecture)
* DB system을 구축하는 architecture 중의 하나
* user application으로부터 물리적인(physical) DB를 분리시키는 목적
* 세 가지 level이 존재하며 각각의 level마다 schema가 정의
* 각 레벨을 독립시켜 어느 레벨에서의 변화가 상위 레벨에 영향을 주지 않기 위함
  * 하지만 오늘날 대부분의 DBMS가 three level을 완벽하게 혹은 명시적으로 나누지는 않음
* 데이터가 존재하는 곳은 internal level

#### 3단계-스키마 구조(three-schema architecture) 종류
* 외부 수준의 외부 스키마
  * external schemas(or user views) at external(or view) level
* 개념 수준의 개념 스키마
  * conceptual schemas at conceptual level
* 내부 수준의 내부 스키마
  * internal schemas at internal level

![threeschema](https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch01/threeschema.PNG)

#### 외부 스키마(external schemas)
* 실제 사용자가 바라보는 schemas
* enternal views, user views 라고도 불림
* 특정 사용자들이 필요로하는 데이터만 표현
* 그 외 알려줄 필요가 없는 데이터는 숨김
* logical data model을 통한 표현

#### 개념 스키마(conceptual schemas)
* 전체 DB에 대한 구조 기술
* 물리적인 저장 구조에 관한 내용은 숨김
* entities, data types, relationships, user operations, constraints에 집중
* logical data model을 통한 기술

#### 내부 스키마(internal schemas)
* 물리적으로 데이터가 어떻게 저장되는지 physical data model을 통해 표현
* data storage, data structure, acess path 등 실체가 있는 내용 기술

## 4절. DB Language(DDL, DML, etc.)
#### 데이터 정의 언어(Data Definition Language - DDL)
* 개념 스키마를 정의하기 위해 사용되는 언어
* internal schema까지 정의할 수 있는 경우도 존재

#### 스토리지 정의 언어(Storage Definition Language - SDL)
* 내부 스키마를 정의하는 용도로 사용되는 언어
* 요즘은 특히 relational DBMS에서는 SDL이 거의 없고 파라미터 등의 설정으로 대체

#### 뷰 정의 언어(View Definition Language - VDL)
* 외부 스키마를 정의하기 위해 사용되는 언어
* 대부분의 DBMS에서는 DDL이 VDL의 역할 수행

#### 데이터 조작 언어(Data Manipulation Language - DML)
* DB에 있는 데이터를 활용하기 위한 언어
* 데이터 추가, 삭제, 수정, 검색 등의 기능 제공

#### 관계형 데이터베이스 언어(relational database language - SQL)
* 오늘날의 DBMS는 DML, VDL, DDL이 따로 존재하지 않고 통합된 언어로 존재
* 통합적 언어의 대표적인 예시
