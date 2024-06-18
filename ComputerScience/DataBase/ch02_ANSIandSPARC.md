# Chapter 1. ANSI/SPARC 구조와 데이터 독립성

> 1절. ANSI/SPARC 구조 이해
>
> 2절. ANSI/SPARC 3단계 구조의 구성
>
> 3절. ANSI/SPARC 구조와 스키마
>
> 4절. 데이터 독립성

## 1절. ANSI/SPARC 구조 이해
#### ANSI/SPARC 정의
* ANSI
    * American National Standards Insitute
* SPARC
    * Standards Planning And Requirements Committee

* 미국의 컴퓨터 및 정보 처리에 관한 표준화 위원회

#### ANSI/SPARC 구조의 정의
* DBMS의 구현을 위한 추상적인 설계 표준
* 1975년 ANSI/SPARC에 처음 제안

![ANSISPARC](https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch02/ANSISPARC.PNG)

#### ANSI/SPARC 3단계 구조

![Schema](https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch02/Schema.PNG)

[사진출처](https://velog.io/@yyeongjin/%EB%8D%B0%EC%9D%B4%ED%84%B0-%EB%B2%A0%EC%9D%B4%EC%8A%A4-ANSISPARC-%EA%B5%AC%EC%A1%B0)

* 물리 단계(Physical level)
    * DBMS의 지시에 따라 운영체제가 관리
    * 디스크와 같은 저장장치에 데이터를 실제로 저장하는 기법

#### ANSI/SPARC 구조의 목적

![DBstructure](https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch02/DBstructure.PNG)

* 응용 프로그램과 데이터 간의 독립성 제공

|관점|특징|
|:---:|:---|
|사용자|DB의 내부 구조에 대해 알지 못해도 DB 사용 가능|
|DB 관리자|응용 프로그램에 영향을 주지 않고 DB 구조 변경|

#### 외부 단계(External Level)
* DB에 관한 개별 사용자의 관점
* 각 사용자나 응용프로그래머가 생각하는 개인적 DB 구조
* Example
    * 은행 DB에 접근하는 개인 고객이나 창구의 직원
    * 신용카드 회사 직원은 각자 전체 DB의 일부분에만 관심을 가짐
    * 사람이 생각하는 DB 구조의 차이

* 외부 단계에서 각 사용자가 생각하는 DB의 구조

![EL](https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch02/EL.PNG)

#### 외부 스키마(External Schema)
* 외부 단계에서 당야한 개별 사용자나 응용 프로그램이 필요로하는 데이터 구조의 정의
* 여러 개로 존재 가능

#### 개념 단계(Conceptual Level)
* DB에 관한 사용자 공동체의 관점
* 한 조직 전체를 위한 DB의 논리적 구조

#### 개념 스키마(Conceptual Schema)
* 개념 단계의 범 기관적 입장에서의 전체 DB를 정의
* 단 하나만 존재

#### 내부 단계(Internal Level)
* DB에 관한 물리적 저장 장치 관점
* DB에 어떤 데이터가 어떻게 저장되는지를 표현한 저장 구조
* Example
    * 실제로 저장된 내부 레코드의 형식
    * 인덱스(Index) 유무
    * 저장 데이터 항목의 표현 방법

#### 내부 스키마(Internal Schema)
* 내부 단계에서 DB의 물리적 데이터 구조 정의
* 단 하나만 존재

#### 내부 단계와 물리 단계
* 내부 단계에서 특정 물리적 저장 장치를 직접 다루지 않음
* 실제로 내부 단계가 물리 단계보다 한 단계 위에 있는 형태
* 물리 단계(Physical level)는 DBMS의 지시에 따라 운영체제가 관리

#### 외부 / 개념 사상(External / Conceptual Mapping)
* 응용 인터페이스(Application Interface)
* 외부 스키마와 개념 스키마 간의 대응 관계 정의
* 개념 스키마가 변경되더라도 응용 인터페이스만 수정할 경우 외부 스키마에 영향 없음
* 응용 프로그램의 변경 필요 X

#### 개념 / 내부 사상(Conceptual / Internal Mapping)
* 저장 인터페이스(Storage Interface)
* 개념 스키마와 내부 스키마 간의 대응 관계 정의
* 내부 스키마가 변경되더라도 저장 인터페이스만 수정한다면 개념 스키마에 영향 없음

## 3절. ANSI/SPARC 구조와 스키마
#### 스키마(Schema)란?
* DB의 구조(Structure)
* 개체와 속성, 관계를 포함하는 논리적 정의
* 제약조건(Constraints)의 기술

#### ANSI/SPARC 3단계 구조와 스키마

![ANSISPARCSchema](https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch02/ANSISPARCSchema.PNG)

#### 스키마 작성 예시

![ANSISPARCSchemaex](https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch02/ANSISPARCSchemaex.PNG)

## 4절. 데이터 독립성
#### 데이터 독립성(Data Independency)이란?
* 응용 프로그램과 데이터가 서로 종속되지 않으며 영향을 미치지 않는 것
* DB의 논리적 구조나 물리적 구조가 변경되더라도 응용 프로그램에 영향 X

#### 데이터 독립성 분류

![DI](https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch02/DI.PNG)

![DI2](https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch02/DI2.PNG)

#### ANSI/SPARC 각 단계 간의 사상(Mapping)

![DI3](https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch02/DI3.PNG)

