![image](https://github.com/user-attachments/assets/dcc3cc7e-4ae5-4c39-90b5-16e3488cc978)# Chapter 3. 데이터베이스 시스템

> 1절. 데이터베이스 시스템 정의
>
> 2절. 데이터베이스 구조
>
> 3절. 데이터베이스 사용자
>
> 4절. 데이터 언어
>
> 5절. 데이터베이스 관리 시스템 구성

## 1절. 데이터베이스 시스템 정의

### 데이터베이스 시스템(DBS : DataBase System)

- 데이터베이스에 데이터를 저장하고 이를 관리하여 조직에 필요한 정보를 생성하는 시스템

<img src = "https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch03/ch03-01-DBS.PNG" width="30%" height="auto" />

## 2절. 데이터베이스 구조

### 스키마와 인스턴스

- 스키마(schema) : 데이터베이스에 저장되는 데이터 구조와 제약조건의 정의
- 인스턴스(instance) : 스키마에 따라 데이터베이스에 실제 저장된 값

<img src = "https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch03/ch03-02-Schema.PNG" width="30%" height="auto" />

### 3단계 데이터베이스 구조

<img src = "https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch03/ch03-03-DataBaseStructual.PNG" width="60%" height="auto" />

- 미국 표준화 기관인 ANSI/SPARC에서 제안
- 데이터베이스를 쉽게 이해하고 이용할 수 있도록 하나의 데이터베이스를 관점에 따라 세 단계로 나눈 것
  - 외부 단계(External Level) : 개별 사용자 관점
  - 개념 단계(Conceptual Level) : 조직 전체의 관점
  - 내부 단계(Internal Lever) : 물리적인 저장 장치의 관점
- 각 단계별 다른 추상화(Abstraction) 제공
  - 내부 단계에서 외부 단계로 갈수록 추상화 레벨 상승
 
<img src = "https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch03/ch03-04-Structual3.PNG" width="60%" height="auto" />

#### 외부 단계

- 데이터베이스를 개별 사용자 관점에서 이해하고 표현하는 단계
- 데이터베이스 하나에 외부 스키마가 여러 개 존재 가능
  - 외부 스키마(External Schema)
    - 외부 단계에서 사용자에게 필요한 데이터베이스 정의한 것
    - 각 사용자가 생각하는 데이터베이스의 모습, 논리적 구조가 사용자마다 상이
    - 서브 스키마(Sub Schema)
   
#### 개념 단계

- 데이터베이스를 조직 전체의 관점에서 이해하고 표현하는 단계
- 데이터베이스 하나에 개념 스키마가 하나만 존재
  - 개념 스키마(Conceptual Schema)
    - 개념 단계에서 데이터베이스 전체의 논리적 구조를 정의한 것
    - 조직 전체의 관점에서 생각하는 데이터베이스의 모습
    - 전체 데이터베이스에 어떤 데이터가 저장되는지가 ?
    - 데이터들 간에는 어떤 관계가 존재하고 어떤 제약조건이 있는지에 대한 정의
    - 데이터에 대한 보안 정책이나 접근 권한에 대한 정의도 포함

#### 내부 단계

- 데이터베이스를 저장 장치의 관점에서 이해하고 표현하는 단계
- 데이터베이스 하나에 내부 스키마가 하나만 존재
  - 내부 스키마(Internal Schema)
    - 전체 데이터베이스가 저장 장치에 실제로 저장되는 방법을 정의한 것
    - 레코드 구조, 필드 크기, 레코드 접근 경로 등 물리적 저장 구조를 정의

### 3단계 데이터베이스 구조의 사상 또는 매핑

<img src = "https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch03/ch03-05-Structual3.PNG" width="60%" height="auto" />

- 스키마 사이의 대응 관계
  - 외부/개념 사상 : 외부 스키마와 개념 스키마의 대응 관계
      - 응용 인터페이스(Application Interface)
  - 개념/내부 사상 : 개념 스키마와 내부 스키마의 대응 관계
      - 저장 인터페이스(Storage Interface)
   
- 미리 정의된 사상 정보를 통해 사용자가 원하는 데이터에 접근
- 데이터베이스를 3단계 구조로 나누고 단계별로 스키마를 유지하며 스키마 사이의 대응 관계를 정의하는 궁극적인 목적
  - 데이터 독립성 실현

### 데이터베이스 구조 예시 : 수강신청 데이터베이스 구조

- 외부 스키마 
<img src = "https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch03/ch03-06-EL.PNG" width="60%" height="auto" />

- 개념 스키마 
<img src = "https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch03/ch03-07-CL.PNG" width="60%" height="auto" />

- 내부 스키마 
<img src = "https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch03/ch03-08-IL.PNG" width="60%" height="auto" />

- 전체적인 관점
<img src = "https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch03/ch03-09-WL.PNG" width="60%" height="auto" />

### 데이터 독립성(Data Independency)

- 하위 스키마를 변경하더라도 상위 스키마가 영향 받지 않는 특성
- 논리적 데이터 독립성
  - 개념 스키마가 변경되더라도 외부 스키마는 영향 X
  - 개념 스키마가 변경될 경우 외부/개념 사상만 정확한 수정 필요
- 물리적 데이터 독립성
  - 내부 스키마가 변경되더라도 개념 스키마는 영향 X
  - 내부 스키마가 변경될 경우 개념/내부 사상만 정확한 수정 필요

### 데이터 사전(Data Dictionary)

- 시스템 카탈로그(System Catalog)
- 데이터베이스에 저장되는 데이터에 관한 정보, 메타 데이터를 유지하는 시스템 데이터베이스
  - 메타 데이터(Meta Data) : 데이터에 대한 데이터
- 데이터를 정확하고 효율적으로 이용하기 위해 참고해야 하는 스키마, 사상 정보, 다양한 제약 조건 등 저장
- 데이터베이스 관리 시스템이 스스로 생성하고 유지
- 일반 사용자도 접근이 가능하나 저장 내용 검색만 가능

### 데이터 디렉터리(Data Directory)

- 데이터 사전에 있는 데이터에 실제 접근할 때 필요한 위치 정보를 저장하는 시스템 데이터베이스
- 일반 사용자의 접근 비허용

### 사용자 데이터베이스(User DataBase)

- 사용자가 실제로 사용하는 데이터가 저장된 일반 데이터베이스

### INFORMATION_SCHEMA

- MySQL 서버 내에 존재하는 DB의 메타 정보(ex : 테이블, 컬럼, 인덱스 등의 스키마 정보)를 모아둔 데이터베이스
- 데이터베이스 내의 모든 테이블은 읽기 전용
  - 읽기 전용(Read-Only) : 사용자가 직접 수정 및 관여 불가능
- 단순 조회만 가능

## 3절. 데이터베이스 사용자

#### 데이터베이스 사용자

- 데이터베이스를 이용하기 위해 접근하는 모든 사람
- 이용 목적에 따라 데이터베이스 관리자, 최종 사용자, 응용 프로그래머로의 구분

(수정 필요)
