# Chapter 2. 데이터베이스 관리 시스템(DBMS)

> 1절. DBMS 등장 배경
>
> 2절. DBMS 정의
>
> 3절. 파일시스템 vs DBMS
>
> 4절. DBMS 발전 과정



## 0절. DBS 구조

<img src="https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch02/ch02-00-DBS.PNG"  width="70%" height="70%"/>

- JDBC(Java Database Connectivity) : 자바에서 데이터베이스에 접근할 수 있도록 하는 자바 API
- ODBC(Open Database Connectivity) : 마이크로소프트가 만든 데이터베이스에 접근하기 위한 소프트웨어의 표준 규격

## 1절. DBMS 등장 배경

#### 파일 시스템(File System)

- 데이터를 파일로 관리하기 위해 파일을 생성, 삭제, 수정, 검색하는 기능을 제공하는 소프트웨어
- 응용 프로그램마다 필요한 데이터를 별도의 파일로 관리

<img src="https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch02/ch02-01-FS.PNG"  width="70%" height="70%"/>

#### 파일 시스템 주요 문제점

#####  데이터 중복성

- 같은 내용의 데이터가 여러 파일에 중복 저장
   - 저장 공간 낭비 및 데이터 일관성, 데이터 무결성 유지에 어려움
   - ex) 여러 파일 중 한 파일의 속성만 수정할 경우 일관성 불일치
 
<img src="https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch02/ch02-02-Sol1.PNG"  width="40%" height="40%"/>


##### 데이터 종속성

- 응용 프로그램이 데이터 파일에 종속적
   - 데이터 구성 방법과 물리적인 저장 구조에 맞는 저장 필요
   - 사용하는 파일의 구조 변경 시 응용 프로그램도 함께 변경해야 하는 번거로움
   - 두 고객 파일 처리 시 다른 방식으로 처리

<img src="https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch02/ch02-03-Sol2.PNG"  width="70%" height="70%"/>

##### 동시 공유, 보안, 회복 기능

- 데이터 파일에 대한 동시 공유, 보안, 회복 기능이 부족
  - 데이터의 중복 가능성 문제 발생
  - 파일 수정 중 장애 발생 시 회복 불가능
  - 파일 단위로 읽기, 쓰기, 실행 권한을 부여하여 데이터 접근 통제
 
##### 응용 프로그램 개발

- 응용 프로그램 개발이 쉽지 않음
  - 새로운 응용 프로그램 개발 시 파일에서 데이터 읽기, 삽입, 삭제 등의 데이터 관리 기능 모두 포함 필요
 
## 2절. DBMS 정의

#### 데이터베이스 관리 시스템

- DBMS : DataBase Management System
- 파일 시스템의 문제 해결을 위해 제시된 소프트웨어
- 조직에 필요한 데이터를 데이터베이스에 통합하여 저장하고 관리
- 데이터를 통합 관리하는 시스템
- 데이터의 중복을 줄이고 표준화하며 무결성 유지

##### 서버와 클라이언트

- 서버(Server) : DBMS가 설치되어 데이터를 가진 쪽
- 클라이언트(Client) : 외부에서 데이터를 요청하는 쪽
- 서버가 파일을 다루며 데이터 일관성 유지, 복구, 동시 접근 제어 등의 기능 수행

#### DBMS에서의 데이터 관리

<img src="https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch02/ch02-04-DBMS.PNG"  width="40%" height="40%"/>

#### DBMS의 주요 기능

|기능|내용|
|:--:|:---|
|정의 기능|데이터베이스 구조를 정의하거나 수정|
|조작 기능|데이터를 삽입, 삭제, 수정, 검색하는 연산 수행|
|제어 기능|데이터를 항상 정확하고 안전하게 유지|

## 3절. 파일시스템 vs DBMS

#### 비교

- 파일 시스템과 DBMS
<img src="https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch02/ch02-05-FIDBMS.PNG"  width="70%" height="70%"/>


|구분|파일 시스템|DBMS|
|:---:|:---|:---|
|데이터 정의 및 저장|데이터 정의 : 응용 프로그램<br>데이터 저장 : 파일 시스템|데이터 정의 : DBMS<br>데이터 저장 : 데이터베이스|
|데이터 접근 방법|응용 프로그램이 파일에 직접 접근|응용 프로그램이 DBMS에 파일 접근 요청|
|사용 언어|Java, C, C++ 등|Javav, C, C++ 등과 SQL|
|CPU / 주기억장치|사용 적음|사용 많음|

(수정 필요)

#### DBMS 장점
