# Chapter 0. 데이터베이스란?

> [참고 강의](http://www.youtube.com/playlist?list=PLcXyemr8ZeoREWGhhZi5FZs6cvymjIBVe)
>
> 1절. 기본 개념
>
> 2절. 

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
