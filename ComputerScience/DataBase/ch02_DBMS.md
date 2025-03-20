# Chapter 2. 데이터베이스 관리 시스템(DBMS)

> 1절. DBMS 등장 배경
>
> 2절. DBMS 정의
>
> 3절. DBMS 장단점
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
 
<img src="https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch02/ch02-02-Sol1.PNG"  width="70%" height="70%"/>

(수정 필요)

##### 데이터 종속성

- 응용 프로그램이 데이터 파일에 종속적
   - 데이터 구성 방법과 물리적인 저장 구조에 맞는 저장 필요
   - 사용하는 파일의 구조 변경 시 응용 프로그램도 함께 변경해야 하는 번거로움
   - 두 고객 파일 처리 시 다른 방식으로 처리

##### 동시 공유, 보안, 회복 기능

- 데이터 파일에 대한 동시 공유, 보안, 회복 기능이 부족
  - 데이터의 중복 가능성 문제 발생
  - 파일 수정 중 장애 발생 시 회복 불가능
