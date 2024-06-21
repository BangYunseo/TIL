# Chapter 4. 데이터 모델링(Data Modeling)

> 1절. 데이터의 구분
>
> 2절. 데이터 모델링
>
> 3절. 데이터 모델의 이해
>
> 4절. 개념적 데이터 모델
>
> 5절. 논리적 데이터 모델

## 1절. 데이터의 구분
#### 데이터가 속한 세계에 따른 데이터 구분
* 현실 세계(Real World)
    * 오감으로 인지할 수 있는 실체
    * 하나 이상의 특성으로 구성된 개체 표현

* 개념 세계(Conceptual World)
    * 개체의 의미로부터 얻은 개념
    * 하나 이상의 속성으로 구성된 개체 타입 표현

* 컴퓨터 세계(Computer World)
    * 개념을 컴퓨터가 처리할 수 있도록 표현한 데이터
    * 하나 이상의 필드로 구성된 레코드 타입 표현

#### 각 데이터의 구성 요소

![DATAtype](https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch04/DATAtype.PNG)

#### 데이터의 구분 사례
|구분|특징|
|:---:|:---|
|현실 세계의 학생 개체|얼굴 모습 등 신체적 특징, 이름, 주민등록번호, 고향, 학력, 취미, 별명, 연락처, 교우 관계, 가족 관계 등 수없이 많은 특성의 구성|
|대학이라는 개념 세계의 학생 개체 타입|이름, 학번, 전공, 지도 교수, 이수 학점 수, 평균 평점 등 대학에서 필요로하는 많은 속성들로 구성|
|컴퓨터 세계의 학생 레코드 타입|이름(문자 20 byte), 학번(문자 10 byte), 전공(문자 20 byte) 등 개념 세계의 속성에 대응하는 많은 필드들로 구성|

## 2절. 데이터 모델링
#### 데이터 모델링이란?
* 현실 세계의 데이터를 DB로 표현하기 위한 모델을 만드는 과정

![DM](https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch04/DM.PNG)

> 3절. 데이터 모델의 이해
>
> 4절. 개념적 데이터 모델
>
> 5절. 논리적 데이터 모델

#### DBS의 구성 요소
|구성 요소|영어|특성|
|:---:|:---:|:---|
|데이터베이스|DataBase|데이터를 저장|
|데이터베이스 관리 시스템|DataBase Management System|DB를 생성, 관리, 조작함으로써 사용자와 DB를 연결해주는 소프트웨어|
|데이터 언어|Data Language|DB 정의와 조작, 제어를 위한 DB 전용 언어|
|데이터베이스 사용자|DataBase User|데이터 언어를 사용해서 DB에 접근하는 사람으로 일반 사용자, 응용 프로그래머, DB 관리자로 구분|
|데이터베이스 컴퓨터|DataBase Computer|효율적인 DB 관리를 위해 DB에 대한 연산을 전담하는 DB 관리 전용 컴퓨터|

## 2절. 데이터 언어
#### 데이터 언어(Data Language)란?
* DB를 정의, 조작, 제어하기 위해 사용하는 언어
* 사용자가 데이터에 접근하는 수단
* 사용자와 DBMS 간의 통신 수단 제공

#### 데이터 언어의 종류

|종류|영어|
|:---:|:---|
|데이터 정의어|DDL : Data Definition Language|
|데이터 조작어|DML : Data Manipulation Languagee|
|데이터 제어어|DCL : Data Control Language|

#### 데이터 언어의 완전성(Completeness of Data Language)
* 데이터 언어가 반드시 갖춰야 하는 필수 요건
* 사용자가 원하는 어떤 데이터도 검색 및 처리 가능
* 어떠한 연산도 표현할 수 있는 능력

#### 데이터 정의어(DDL : Data Definition Language)란?
* DB 구조를 정의하거나 변경하기 위해 사용하는 언어
* DB 설계자 또는 DB 관리자가 DB 스키마를 정의하기 위해 사용

#### 데이터 정의
* 논리적 데이터 구조의 정의
    * 개념 스키마(그냥 스키마)와 외부 스키마(서브 스키마) 명세
* 물리적 데이터 구조의 정의
    * 내부 스키마 명세
    * 별도의 데이터 저장 정의어(DSDL : Data Storage Definition Language)를 사용하여 명세하는 경우
* 논리적 데이터 구조와 물리적 데이터 구조 간의 사상(Mapping) 정의

#### 데이터 정의의 저장
* DDL로 정의된 DB 스키마 
    * DBMS의 구성 요소 가운데 하나인 DDL 컴파일러가 컴파일 후 시스템 카탈로그(System Catalog) 또는 데이터 디렉토리(Data Directory)에 저장하고 필요할 경우 참조

#### 시스템 카탈로그(System Catalog)
* 시스템 DB 또는 메타 데이터(Metadata) 혹은 데이터 사전(Data Dictionary) 라고 칭함
* DB에 포함된 모든 객체들에 대한 정의(Definition)나 명세(Specification)에 대한 정보가 수록된 시스템 테이블
* DB 관리자가 주로 사용하는 도구
* 사용자와 시스템 모두 사용 가능

#### 데이터 디렉토리(Data Directory)
* DB에 저장된 데이터를 참조하는데 필요한 정보가 수록된 시스템 테이블
* 시스템만 사용 가능

#### 데이터 정의어의 상세 구분
* DB를 ANSI/SPARC의 3단계로 엄격히 구분하는 시스템의 경우
    * 외부 스키마 정의어와 개념 스키마 정의어, 내부 스키마 정의어 각각 제공
* DB를 ANSI/SPARC의 3단계로 엄격히 구분하지 않는 시스템의 경우
    * DDL을 외부 스키마와 개념 스키마를 정의(개체와 속성, 관계, 제약 조건 및 스키마 간의 사상(Mapping)등 포함)할 때 모두 사용
* 개념 스키마와 내부 스키마를 분명히 구분하는 경우
    * 내부 스키마 정의를 위해 별도의 데이터 저장 정의어(DSDL : Data Storage Definition Language) 사용
* 외부 스키마와 개념 스키마를 분명히 구분하는 경우
    * 외부 스키마를 정의할 때 대개 약간 확장된 DDL을 사용
    * 외부 스키마 대신 서브 스키마(Sub Schema)라는 용어를 사용하는 시스템의 경우 스키마 DDL과 서브 스키마 DDL로 구분
    * 외부 스키마는 응용 프로그램 안에 DDL 명령문으로 정의되는 경우가 다반사 

#### 데이터 조작어(DML : Data Manipulation Language)란?
* DB 사용자(응용 프로그램 포함)와 DBMS 사이의 통신 수단
* 데이터 검색, 삽입, 삭제, 갱신과 같은 DB 연산 처리

#### 데이터 조작어의 종류 및 역할
* 절차적 DML
    * 사용자가 데이터를 어떻게 접근해서 처리해야 하는지 기술 
    * 저수준 데이터 언어(Low Level Data Language)
    * 한 번에 하나의 레코드만 검색해서 호스트 언어로 전달해서 처리되는 특성
        * 독자적으로 사용 불가능
        * 응용 프로그램 속에 삽입(embedded)되어 사용
    * 호스트 언어로 작성된 응용 프로그램 안에서 프로시저(Procedure) 호출문 형식으로 표현
    * DML 예비 컴파일러(Pre-compiler)에 의해 별도로 컴파일

* 비절차적 DML
    * 사용자가 어떤 데이터를 원하는 지만 기술
    * 어떻게 접근해서 처리해야 하는지 기술하지 않고 DBMS에게 위임
    * 고수준 데이터 언어(High Level Data Language)
    * 한 번에 여러 개의 레코드 처리
    * 단말기에서 일반 사용자가 대화식으로 사용
    * 응용 프로그램 속에 삽입해서 사용
    * 독자적이고 대화식으로 사용하는 고급 명령어 형태의 데이터 조작어를 질의어(Query Language)라고 칭함

##### 데이터 부속어(DSL : Data Sublanguage)
* 절차적이든 비절차적이든 호스트 프로그램 속에 삽입해서 사용하는 DML 명령어

#### 데이터 제어어(DCL : Data Control Language)란?
* 공용 DB 관리를 위해 데이터 제어를 정의하고 기술하는 언어
* DB 관리를 목적으로 주로 DB 관리자가 사용

#### 데이터 제어의 기능
* 데이터 보안(Security)
* 데이터 무결성(Integrity)
* 데이터 복구(Recovery)
* 병행 수행 제어(oncurrency Control)

#### 데이터 언어의 주의사항
* 데이터 언어는 개념적으로 DDL / DML / DCL로 구분
    * 현실적으로는 별도의 언어로 존재하는 것이 아닌 하나의 언어 안에 포함된 다른 명령어로서 기능적으로만 구분되는 것이 일반적

## 3절. DB 관리자와 사용자
#### 일반 사용자
* 대개 질의어(Query Language)를 사용해서 DB에 접근하는 사람
    * 질의어(Query Language)
        * 독자적이고 대화식으로 사용하는 고급 명령어 형태의 독립된 데이터 조작어
* DB에 대한 특별한 지식 없이 주로 데이터 검색, 삽입, 삭제, 갱신을 목적으로 DB에 접근

![NU](https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch03/NU.PNG)

#### 응용 프로그래머(Application Programmer)
* 업무 중심의 응용 프로그램을 개발하는데 참여하는 정보 기술 전문가
* C, Java 등과 같은 호스트 언어와 DML에 익숙
* DB에 대한 기초 지식을 갖춘 프로그래밍 전문가

##### 호스트 언어(Host Language)
* 응용 프로그램을 작성할 때 사용되는 범용 프로그래밍 언어

#### DB 관리자
* DB 시스템이 기능을 원활히 수행할 수 있도록 관리를 책임지는 사
* DB 시스템을 총체적으로 감시하고 관리하는 책임과 권한을 가진 사람
* DB를 설계 및 구축
* DB의 변경 및 계획도 수립

#### DB 관리자의 주요 역할
* DB 시스템 감시(Monitoring) 및 성능 분석
* DB의 구성 요소 결정 및 스키마 정의
* DB의 저장 구조와 접근 방법 결정
* 보안 및 권한 부여 정책과 데이터 유효성 검사 방법 수립
* 백업(BackUp) 및 복구(Recovery) 절차 수립
* DB의 무결성 유지를 위한 대책 수립
* DB 시스템의 성능 향상 및 새로운 요구에 대응한 DB 재구성
* 시스템 카탈로그의 관리
* 데이터 표현 및 시스템 문서화에 대한 표준 설정
* 사용자의 요구 및 불만 해소 등



## 4절. DB 컴퓨터
#### DB 컴퓨터란?
* 대규모 DB(VLDB : Very Large DataBase)를 보다 효율적으로 관리하기 위한 DB 관리 전용 컴퓨터
* DB 머신(Machine)라고도 함

#### DB 컴퓨터 특징
* 호스트 컴퓨터 후위에서 DB 관리 및 연산 수행 기능을 전담하는 특수 목적의 컴퓨터
* 일종의 후위 컴퓨터(Backend Computer)
* DB 관리 기능을 소프트웨어만으로 처리하는 것이 아닌 펌웨어(Firmware)나 하드웨어로 수행
    * 저비용으로 고성능 달성 가능
* 후위 처리기(Backend processor), 고성능 메인 메모리, CPU, 대용량 저장장치, 병렬 처리 및 DB 연산 수행을 위한 특수 처리기 등으로 구성

##### 펌웨어(Firmware)
* 변경할 필요가 없는 소프트웨어를 ROM 등에 고정시켜 하드웨어처럼 사용

#### DB 컴퓨터와 호스트 컴퓨터의 관계

![DBHOST](https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch03/DBHOST.PNG)

#### DB 컴퓨터의 주요 역할
* DB 연산 기능
    * 호스트 컴퓨터가 일반 사용자나 응용 프로그램으로부터 DB 접근 요청을 받아 DB 컴퓨터로 전달하면 실제로 DB 컴퓨터가 데이터 검색, 삽입, 삭제, 갱신 등의 연산 수행

* DB 관리 기능
    * 데이터 접근 권한 확인, 병행 수행 제어, 데이터 복구, 최적의 접근 경로 신청 등을 포함하는 데이터 관리 기능 직접 수행

## 5절. DBMS의 DB 연산 처리 방법
#### DBMS의 주요 기능
* DB 관리 및 사용자 요구 처리를 위한 연산 수행을 통해 필요한 정보 생성

#### DBMS의 연산 수행 절차

![DBMS1](https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch03/DBMS1.PNG)

![DBMS2](https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch03/DBMS2.PNG)

#### 질의어 처리기
* 터미널에서 일반 사용자가 입력한 질의문을 컴파일한 후 DB에 접근하기 위한 오브젝트 코드 생성

##### 오브젝트 코드(Object Code)
* 원시 코드(Source Code)가 컴파일러(Compiler)에 의해 처리기(Processor)가 이해할 수 있는 명령어 형태로 번역된 것

#### DML 예비 컴파일러
* 호스트 언어로 작성된 응용 프로그램에 삽입된 DML 추출 후 그 자리에 함수 호출문(Procedure Call Statement) 삽입
* 추출된 DML은 DML 컴파일러로 전달, 수정된 응용 프로그램은 호스트 프로그래밍 언어의 컴파일러로 전달

#### DDL 컴파일러
* DDL로 정의된 스키마를 내부 형태로 변환해서 시스템 카탈로그에 저장
    * 시스템 카탈로그에 저장된 데이터를 메타 데이터(MetaData) 즉, 데이터의 데이터라고 칭함
* DDL 처리기(Processor) 라고도 칭함

#### DML 컴파일러
* DMl 명령어를 컴파일해서 오브젝트 코드로 변환
* 오브젝트 코드는 호스트 프로그래밍 언어의 컴파일러에 의해 수정된 응용 프로그램의 오브젝트 코드와 연결되어 런타임 DB 처리기에 의해 실행
* DML 처리기(Processor)라고도 칭함

#### 트랜잭션 관리자
* 데이터를 일관되게 변경하는 하나 이상의 DML 문장으로 구성된 트랜잭션(Transaction) 단위의 작업 수행
* 예시
    * DB 접근 과정에서 무결성(Integrity) 제약 조건 검사, 데이터에 대한 접근 권한 검사, 여러 사용자의 요구를 동시에 처리하기 위한 병행 제어(Concurrency Control), 장애 발생 시 복구(Recovery) 작업 등 수행

##### 트랜잭션(Transaction)
* 데이터를 일관되게 변경하는 하나 이상의 데이터 조작어(DML) 문장

#### 런타임 데이터베이스 처리기
* 실행 시간에 DB 접근 관리
* 여러 가지 DB 연산(Operations)을 저장 데이터 관리자(Stored Data Manager)를 통해 수행

#### 저장 데이터 관리자
* 디스크에 저장되어 있는 사용자의 DB나 시스템 카탈로그에 대한 접근 제어
* 아래와 같은 운영 체제의 기본 모듈 이용
    * 파일 관리자(File Manager)
        * 요구된 저장 레코드가 어떤 파일의 어떤 페이지에 있는지 결정
    * 디스크 관계자(Disk Manager)
        * 실제로 디스크와 메인 메모리 버퍼 간의 데이터 전송 책임