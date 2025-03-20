# Chapter 1. 데이터베이스 기본 개념

> 1절. 데이터베이스의 필요성
>
> 2절. 데이터베이스의 정의 및 특성
>
> 3절. 데이터와 데이터베이스

## 1절. 데이터베이스의 필요성

#### 데이터와 정보
- 데이터(Data) : 현실 시계에서 단순히 관찰하거나 측정하여 수집한 사실 혹은 값
- 정보(Information) : 의사 결정에 유용하게 활용할 수 있도록 데이터를 처리한 결과물

<img src="https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch01/ch01-01-DI.PNG"  width="30%" height="30%"/>

#### 정보 처리(Information Processing)
- 데이터에서 정보를 추출하는 과정 및 방법

<img src="https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch01/ch01-02-DI.PNG"  width="30%" height="30%"/>

#### 정보 시스템과 데이터베이스
- 정보 시스템(Information System) : 조직 운영에 필요한 데이터를 수집하여 저장 후 필요 시 유용한 정보를 만드는 수단
- 데이터베이스 : 정보 시스템 안에서 데이터를 저장하고 있다가 필요 시 제공하는 역할

<img src="https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch01/ch01-03-DI.PNG"  width="30%" height="30%"/>

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
* 장점
  * 데이터의 동시 공유 가능
  * 데이터 중복 최소화
  * 데이터의 무결성 유지 용이
  * 데이터의 일관성 유지 용이
  * 프로그램과 데이터 간의 독립성 유지
  * 데이터의 보안 보장
  * 데이터의 표준화 달성 가능

* 단점
  * 운영비 증가
  * 데이터 처리의 복잡성
  * 백업(Backup)과 복구(Recovery)의 복잡성
  * 시스템 장애에 취약


## 4절. DBMS의 역사
#### 1세대 DBMS
* 60년대 초반 ~ 70년대 중반
* 네트워크 데이터 모델과 계층 데이터 모델 기반 DBMS

![DBMS1](https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch01/DBMS1.PNG)

#### 2세대 DBMS
* 70년대 후반 ~ 80년대 주류
* 관계 데이터 모델(Relation Data Model) 기반 DBMS

![DBMS2](https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch01/DBMS2.PNG)

#### 3세대 DBMS
* 80년대 후반 ~ 현
* 객체 DBMS OR 객체-관계 DBMS

![DBMS3](https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch01/DBMS3.PNG)

#### 현재
* 제 2세대 DBMS와 제 3세대 DBMS의 공존
* 4세대 기술 개발 중
