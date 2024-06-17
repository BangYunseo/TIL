# Chapter 1. 데이터베이스 관리 시스템(DBMS)

> 1절. DBMS의 개념
>
> 2절. DBMS의 발전 배경
>
> 3절. DBMS의 필수 기능과 장단점
>
> 4절. DBMS의 역사

## 1절. DBMS의 개념
#### 데이터베이스 관리 시스템(DBMS)이란?
* DBMS(DataBase Management System)
* 데이터베이스 관리 시스템

![DBMS](https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch01/DBMS.PNG)

* DB의 정의와 조작, 제어 기능 제공
* 여러 사용자와 응용 프로그램이 DB를 공용할 수 있도록 관리

#### DBMS의 목적
* 응용 프로그램이 데이터에 종속되지 않는 데이터 독립성(Data Independency)의 제공
  * 데이터 독립성 : 응용 프로그램에 영향을 주지 않고 DB의 구조 변경
* DB의 구조를 변경해도 응용프로그램에 영향이 없도록 설계
* 응용 프로그램을 변경해도 DB에 영향이 없도록 설계

## 2절. DBMS의 발전 배경
#### 사회적 요구

![SocialDBMS](https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch01/SocialDBMS.PNG)

#### 기술적 발전
* 저렴한 고속 자기디스크(Magnetic Disk)의 실용화
* 대량 정보 저장 및 빠른 검색 지원 가능
* 데이터 통신 기술의 발전으로 빠른 정보 전송 가능
* 데이터의 동시 공유 가능

#### 파일 처리 시스템이란?
* 각 응용 프로그램이 자신의 데이터를 별도의 파일 형태로 관리하는 파일 중심의 데이터 처리 시스템

![FMS](https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch01/FMS.PNG)

#### 파일 처리 시스템의 특징
* 응용 프로그램과 데이터 간의 상호 의존성
* 대부분 응용 프로그램과 데이터 파일이 일대일 대응
* 이로 인해 데이터 종속성과 데이터 중복성 유발

|종류|영어|개념|
|:---:|:---:|:---|
|데이터 종속성|Data Denpendency|데이터 파일의 구성 방법이나 접근 방법을 변경하면 관련 응용 프로그램도 변경해야 하는 성질|
|데이터 중복성|Data Redundanty|내용이 같은 데이터가 한 시스템 내에 중복해서 저장 및 관리되는 성질|

#### 파일 처리 시스템의 단점
* 일관성(Consistency) 유지의 어려움
  * 데이터의 중복으로 인해 데이터의 동일성 유지 어려움
  * 중복된 데이터의 변경 시점에 따라 동일한 데이터의 값이 일치하지 않을 가능성 존재

* 보안(Security) 유지의 어려움
  * 데이터의 중복 관리로 인해 동일한 수준의 보안 유지 어려움

* 경제성 저하
  * 중복된 저장 및 갱신 작업으로 인해 저장 공간 및 갱신 비용 상승

* 데이터 무결성(Integrity) 유지의 어려움
  * 중복 저장에 따른 관리 분산으로 데이터의 정확성 유지 어려움

* 동시 공용(Concurrent Sharing)의 어려움
  * 하나의 데이터 파일을 여러 응용 프로그램이 공용하더라도 한 프로그램이 데이터 파일을 사용하는 동안 다른 응용 프로그램이 그 데이터 파일에 접근 불가능


## 3절. DBMS의 필수 기능과 장단점
#### DBMS의 필수 기능
* 데이터 정의(Definition) 기능
  * 다양한 응용 프로그램과 DB가 서로 인터페이스할 수 있는 수단 제공
  * 하나의 저장된 DB를 기초로 여러 사용자와 응용 프로그램의 다양한 데이터 요구를 지원할 수 있도록 DB 구조를 정의하는 기능 제공

* 데이터 조작(Manipulation) 기능
  * 사용자와 DB간의 인터페이스를 위한 수단 제공
  * DB에 저장된 데이터의 검색, 삽입, 삭제, 갱신 등과 같은 DB 연산을 처리하는 기능 제공

* 데이터 제어(Control) 기능
  * 공용으로 관리되는 DB의 내용을 정확하고 안전하게 유지할 수 있도록 3가지 제어기능 제공
    * 데이터의 무결성 및 일관성 유지 기능
    * 접근 권한 검사 기능
    * 동시성(Concurrency) 제어 기능

#### DBMS의 장단점
## 4절. DBMS의 역사
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
