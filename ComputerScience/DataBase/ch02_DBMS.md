# Chapter 2. 데이터베이스 관리 시스템(DBMS)

> 0절. DBS 구조
>
> 1절. DBMS 등장 배경
>
> 2절. DBMS 정의
>
> 3절. 파일 시스템 vs DBMS
>
> 4절. DBMS 기능
>
> 5절. 데이터 모델
>
> 6절. 데이터베이스 관리 시스템 발전 과정

## 0절. DBS 구조

<img src="https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch02/ch02-00-DBS.PNG"  width="70%" height="70%"/>

|                 종류                 | 설명                                                                    |
| :----------------------------------: | :---------------------------------------------------------------------- |
| JDBC<br>(Java Database Connectivity) | 자바에서 데이터베이스에 접근할 수 있도록 하는 자바 API                  |
| ODBC<br>(Open Database Connectivity) | 마이크로소프트가 만든 데이터베이스에 접근하기 위한 소프트웨어 표준 규격 |

## 1절. DBMS 등장 배경

### 파일 시스템(File System)

- 데이터를 파일로 관리하기 위한 시스템
- 파일 생성·삭제·수정·검색 기능을 제공하는 소프트웨어
- 응용 프로그램마다 필요한 데이터 별도 관리

<img src="https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch02/ch02-01-FS.PNG"  width="70%" height="70%"/>

### 파일 시스템 문제점

#### 데이터 중복성

- 같은 내용 데이터가 여러 파일에 중복 저장
  - 저장 공간 낭비, 데이터 일관성·무결성 유지에 어려움
  - ex) 여러 파일 중 한 파일의 속성만 수정할 경우 일관성 불일치

<img src="https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch02/ch02-02-Sol1.PNG"  width="40%" height="40%"/>

#### 데이터 종속성

- 응용 프로그램이 데이터 파일에 종속적
  - 데이터 구성 방법·물리적인 저장 구조에 맞는 저장 필요
  - 사용하는 파일의 구조 변경 시 응용 프로그램도 함께 변경
  - ex) 두 고객 파일 처리 시 다른 방식으로 처리

<img src="https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch02/ch02-03-Sol2.PNG"  width="100%" height="100%"/>

#### 동시 공유·보안·회복 기능

- 데이터 파일 동시 공유·보안·회복 기능 부족
  - 데이터 중복 가능성 문제 위험
  - 파일 수정 중 장애 발생 시 회복 불가능
  - 파일 단위 읽기·쓰기·실행 권한의 데이터 접근 통제

#### 응용 프로그램 개발

- 응용 프로그램 개발에 어려움
  - 새로운 응용 프로그램 개발 시 파일에서 데이터 읽기·삽입·삭제 등의 데이터 관리 기능 포함 필요

## 2절. DBMS 정의

### 데이터베이스 관리 시스템(DBMS : DataBase Management System)

- 파일 시스템 문제 해결을 위해 제시된 소프트웨어
- 조직에 필요한 데이터를 데이터베이스에 통합·저장·관리하는 시스템
- 데이터 중복 감소·표준화하여 무결성 유지

### 서버와 클라이언트

|        종류        | 설명                                                                                 |
| :----------------: | :----------------------------------------------------------------------------------- |
|    서버(Server)    | DBMS가 설치되어 데이터 보유<br> 데이터 일관성 유지· 복구·동시 접근 제어 등 기능 수행 |
| 클라이언트(Client) | 외부에서 데이터를 요청                                                               |

### DBMS에서의 데이터 관리

<img src="https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch02/ch02-04-DBMS.PNG"  width="40%" height="40%"/>

### DBMS의 주요 기능

|   기능    | 내용                                 |
| :-------: | :----------------------------------- |
| 정의 기능 | 데이터베이스 구조 정의·수정          |
| 조작 기능 | 데이터 삽입·삭제·수정·검색 연산 수행 |
| 제어 기능 | 데이터 항상 정확·안전 유지           |

## 3절. 파일 시스템 vs DBMS

### 파일 시스템 vs DBMS

<img src="https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch02/ch02-05-FIDBMS.PNG"  width="100%" height="auto"/>

|       구분       | 파일 시스템                                              | DBMS                                             |
| :--------------: | :------------------------------------------------------- | :----------------------------------------------- |
| 데이터 정의·저장 | 데이터 정의 : 응용 프로그램<br>데이터 저장 : 파일 시스템 | 데이터 정의 : DBMS<br>데이터 저장 : 데이터베이스 |
| 데이터 접근 방법 | 응용 프로그램이 직접 접근                                | 응용 프로그램이 DBMS에 파일 접근 요청            |
|    사용 언어     | Java, C, C++ 등                                          | Java, C, C++, SQL 등                             |
| CPU / 주기억장치 | 사용 적음                                                | 사용 많음                                        |

### DBMS 장점

|     구분      | 파일 시스템                                   | DBMS                                                  |
| :-----------: | :-------------------------------------------- | :---------------------------------------------------- |
|  데이터 중복  | 데이터 파일 단위 저장으로 중복 가능           | DBMS로 데이터를 공유해서 중복 가능성 낮음             |
| 데이터 일관성 | 데이터의 중복 저장으로 일관성 결여            | 중복 제거로 데이터의 일관성 유지                      |
| 데이터 독립성 | 데이터 정의·프로그램 독립성 유지 불가능       | 데이터 정의·프로그램 독립성 유지 가능                 |
|     관리      | 보통                                          | 데이터 복구·보안·동시성 제어·데이터 관리 기능 등 수행 |
|  개발 생산성  | 나쁨                                          | 짧은 시간에 프로그램을 개발 가능                      |
|   기타 장점   | 운영체제 지원으로 별도 소프트웨어 설치 불필요 | 데이터 무결성 유지, 데이터 표준 준수 용이             |

### DBMS 단점

| 단점                              | 내용                                                                                                                              |
| :-------------------------------- | :-------------------------------------------------------------------------------------------------------------------------------- |
| 높은 수준의 비용                  | 1. 운영체제와 함께 설치<br>2. 데이터베이스 관리 시스템 설치로 인한 구매 비용 증가<br>3. 동시 접속자 허용 수에 따른 제품 가격 증가 |
| 백업 및 회복 복잡                 | 1. 데이터 양이 많아 구조 복잡<br>2. 여러 사용자의 동시 공유로 장애 발생 시 원인 파악 불가<br>3. 백업 요구                         |
| 중앙 집중 관리로 인한 취약점 존재 | 1. 모든 데이터가 데이터베이스에 통합<br>2. 데이터베이스 관리 시스템에 집중                                                        |

## 4절. DBMS 기능

### 데이터베이스 시스템 구성

<img src="https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch02/ch02-06-DBS.PNG"  width="70%" height="70%"/>

| 종류                                             | 특징                                                                                                                                                                                                                     |
| :----------------------------------------------- | :----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| 일반 사용자                                      | 1. 은행의 창구 혹은 관공서 민원 접수처 등에서 데이터를 다루는 업무를 진행하는 사람<br>2. 프로그래머가 개발한 프로그램으로 데이터베이스에 접근한 일반인                                                                   |
| 응용 프로그래머                                  | 1. 일반 사용자가 사용할 수 있도록 프로그래밍하는 프로그래머<br>2. 자바, C, JSP 등 프로그래밍 언어와 SQL을 통해 일반 사용자를 위한 사용자 인터페이스 및 데이터를 관리하는 응용 로직 개발                                  |
| SQL 사용자                                       | 1. SQL을 통해 업무를 처리하는 IT 부서의 담당자<br>2. 응용 프로그램으로 구현되어 있지 않은 업무를 SQL을 통해 처리                                                                                                         |
| 데이터베이스 관리자(DBA, Database Administrator) | 1. 데이터베이스 운영 조직의 데이터베이스 시스템 총괄자<br>2. 데이터 설계·구현·유지보수 전 과정 담당<br><br>3. 데이터베이스 사용자 통제·보안·성능 모니터링·데이터 전체 파악 및 관리·데이터 이동 및 복사 등 제반 업무 수행 |

### SQL

|     종류      |               영문               |
| :-----------: | :------------------------------: |
| 데이터 정의어 |  DDL : Data Definition Language  |
| 데이터 조작어 | DML : Data Manipulation Language |
| 데이터 제어어 |   DCL : Data Control Language    |

### DBMS 기능

|           기능            | 설명                                                                                        |
| :-----------------------: | :------------------------------------------------------------------------------------------ |
|  데이터 정의(Definition)  | 데이터의 구조를 정의·삭제·변경 기능 수행                                                    |
| 데이터 조작(Manipulation) | 데이터 조작 소프트웨어(응용 프로그램)가 요청하는 데이터 삽입·수정·삭제 작업                 |
|  데이터 추출(Retrieval)   | 사용자가 조회하는 데이터·응용 프로그램의 데이터 추출                                        |
|   데이터 제어(Control)    | 데이터베이스 사용자를 생성하고 모니터링하며 접근 제어<br>백업·회복·동시성 제어 등 기능 지원 |

## 5절. 데이터 모델

### 데이터 모델 종류

|                          종류                           | 비고                                            |
| :-----------------------------------------------------: | :---------------------------------------------- |
|      계층 데이터 모델<br>(Hierarchical Data Model)      | .                                               |
|      네트워크 데이터 모델<br>(Network Data Model)       | .                                               |
|         객체 데이터 모델<br>(Object Data Model)         | .                                               |
|       관계 데이터 모델<br>(Relational Data Model)       | 가장 많이 사용되는 모델                         |
| 객체-관계 데이터 모델<br>(Object-Relational Data Model) | 관계 데이터 모델과 객체 데이터 모델의 장점 결합 |

#### 1. 포인터 사용

| <img src="https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch02/ch02-07-UsingPointer.PNG"  width="auto" height="auto"/> | <img src="https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch02/ch02-10-UsingInModel.PNG"  width="auto" height="auto"/> |
| ------------------------------------------------------------------------------------------------------------------------------------------------- | ------------------------------------------------------------------------------------------------------------------------------------------------- |

#### 2. 속성 값 사용

| <img src="https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch02/ch02-08-UsingAttribute.PNG"  width="auto" height="auto"/> | <img src="https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch02/ch02-11-UsingInRModel.PNG"  width="auto" height="auto"/> |
| --------------------------------------------------------------------------------------------------------------------------------------------------- | -------------------------------------------------------------------------------------------------------------------------------------------------- |

#### 3. 객체 식별자 사용

| <img src="https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch02/ch02-09-UsingOI.PNG"  width="auto" height="auto"/> | <img src="https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch02/ch02-12-UsingInOModel.PNG"  width="auto" height="auto"/> |
| -------------------------------------------------------------------------------------------------------------------------------------------- | -------------------------------------------------------------------------------------------------------------------------------------------------- |

## 6절. 데이터베이스 관리 시스템 발전 과정

(여기부터 다시 공부 및 작성)

### 1세대 : 네트워크·계층 DBMS

- 네트워크 DBMS : 데이터베이스를 그래프 형태로 구성
  - ex) IDS(Integrated Data Store)

<img src="https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch02/ch02-13-NDBMS.PNG"  width="50%" height="50%"/>

- 계층 DBMS : 데이터베이스를 트리 형태로 구성
  - ex) IMS(Information Management System)

<img src="https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch02/ch02-14-HDBMS.PNG"  width="50%" height="50%"/>

### 2세대 : 관계 DBMS

- 관계 DBMS : 데이터베이스를 테이블 형태로 구성
  - ex) 오라클(Oracle), MSSQL 서버, 엑세스(Access), 인포믹스(Informix), MySQL

<img src="https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch02/ch02-15-RDBMS.PNG"  width="70%" height="70%"/>

### 3세대 : 객체지향 DBMS, 객체관계 DBMS

- 객체지향 DBMS : 객체를 이용해 데이터베이스를 구성

  - ex) 오투(O2), 온투스(ONTOS), 젬스톤(GemStone)

- 객체관계 DBMS : 객체지향 DBMS + 관계 DBMS
  - ex) 관계 DBMS 제품들이 객체지향 기능을 지원하면서 객체관계 DBMS로 분류되기도 함(예시 : 오라클(Oracle))

 <img src="https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch02/ch02-16-ORD.PNG"  width="60%" height="60%"/>

#### 객체 지향 Data VS 관계 Data

 <img src="https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch02/ch02-17-RvsOODM.PNG"  width="60%" height="auto"/>  
 
 <img src="https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch02/ch02-18-RvsOODM.PNG"  width="60%" height="auto"/>

### 4세대 : NoSQL / NewSQL DBMS

- NoSQL DBMS : 비정형 데이터를 처리하는데 적합하고 확장성이 뛰어남

  - 안정성과 일관성 유지를 위한 복잡한 기능 포기
  - 데이터 구조를 미리 정해두지 않는 유연성을 가짐
  - 여러 대의 컴퓨터에 데이터를 분산하여 저장하고 처리하는 환경에서 주로 사용
  - ex) 몽고디비(MongoDB), H베이스(HBase), 카산드라(Cassandra), 레디스(Redis), 네오포제이(Neo4j), 오리엔트DB(OrientDB) 등

- NewSQL DBMS: 관계 DBMS의 장점 + NoSQL의 확장성 및 유연성
  - 정형 및 비정형 데이터를 안정적이고 빠르게 처리 가능
  - ex) 구글 스패너(Spanner), 볼트DB(VoltDB), 누오DB(NuoDB) 등

#### SQL vs NoSQL

- NoSQL은 확장성이 뛰어나 여러 대의 서버 컴퓨터에 데이터를 분산하여 저장하고 처리하는 환경에서 주로 사용

 <img src="https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch02/ch02-19-NoSQL.PNG"  width="60%" height="auto"/>  
 
#### NoSQL 성능

- 유연성

  - NoSQL 데이터베이스는 일반적으로 유연한 스키마를 제공하여 보다 빠르고 반복적인 개발을 가능하게 해줌
  - 이같은 유연한 데이터 모델은 NoSQL 데이터베이스를 반정형 및 비정형 데이터에 이상적으로 만듦

- 확장성

  - NoSQL 데이터베이스는 일반적으로 고가의 강력한 서버를 추가하는 대신 분산형 하드웨어 클러스터를 이용해 확장하도록 설계
  - 일부 클라우드 제공자들은 완전관리형 서비스로서 이런 운영 작업을 보이지 않게 처리

- 고성능

  - NoSQL 데이터베이스는 특정 데이터 모델 및 액세스 패턴에 대해 최적화
  - 관계형 데이터베이스를 통해 유사한 기능을 충족하려 할 때보다 뛰어난 성능

- 고기능성
  - NoSQL 데이터베이스는 각 데이터 모델에 맞춰 특별히 구축된 뛰어난 기능의 API와 데이터 유형을 제공

### 발전 과정의 총 정리

 <img src="https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch02/ch02-20-SQL.PNG"  width="100%" height="auto"/>
