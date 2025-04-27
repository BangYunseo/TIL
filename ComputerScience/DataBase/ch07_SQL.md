# Chapter 7. SQL 질의어

> 1절. SQL 소개
>
> 2절. SQL 데이터 정의
>
> 3절. SQL 데이터 조작
>
> 4절. 키(Key)
>
> 5절. 무결성 제약조건

## 1절. SQL 소개

### SQL(Structured Query Language)

|   내용    | 설명                                                                                                                                     |
| :-------: | :--------------------------------------------------------------------------------------------------------------------------------------- |
|   의미    | 1. 관계 데이터베이스를 위한 표준 질의어<br>2. 비절차적 데이터 언어                                                                       |
| 발전 역사 | 1. SEQUEL(Structured English QUEry Language)에서 유래<br>2. 미국 표준 연구소 ANSI와 국제 표준화 기구 ISO에서 표준화 작업 진행            |
| 사용 방식 | 1. 대화식 SQL : 데이터베이스 관리 시스템에 직접 접근 후 질의 작성 및 실행<br>2. 삽입 SQL : 프로그래밍 언어로 작성된 응용 프로그램에 삽입 |

### 분류

<img src="https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch07/ch07-01-SQL.PNG"  height="auto" />

|        종류        | 영문                       | 설명                                                                         |
| :----------------: | :------------------------- | :--------------------------------------------------------------------------- |
| 데이터 정의어(DDL) | Data Definition Language   | 테이블 생성·변경·제거 기능 제공                                              |
| 데이터 조작어(DML) | Data Manipulation Language | 테이블에 새 데이터를 삽입·저장된 데이터를 수정·삭제·검색 기능 제공           |
| 데이터 제어어(DCL) | Data Control Language      | 보안을 위해 데이터에 대한 접근 허용·사용 권한을 사용자별 부여·취소 기능 제공 |

#### 예제 사용 테이블

- 고객 테이블

<img src="https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch07/ch07-02-CUSTOMER.PNG"  height="auto" />

- 제품 테이블

<img src="https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch07/ch07-03-PRODUCT.PNG"  height="auto" />

- 주문 테이블

<img src="https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch07/ch07-04-ORDER.PNG"  height="auto" />

## 2절. SQL 데이터 정의

### 데이터 정의 기능

- 테이블 생성·변경·삭제

<img src="https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch07/ch07-05-DDL.PNG"  height="auto" />

### 테이블 생성 : CREATE TABLE

```SQL
CREATE TABLE 테이블_이름(
    1. 속성_이름 데이터_타입 [NOT NULL] [DEFAULT 기본_값]
    2. [PRIMARY KEY (속성_리스트)]
    3. [UNIQUE (속성_리스트)]
    4. [FOREIGN KEY (속성_리스트) REFERENCES 테이블_이름(속성_리스트)]
       [ON DELETE 옵션] [ON UPDATE 옵션]
    5. [CONSTRAINT 이름] [CHECK(조건)]
);
```

- [] 안의 내용 생략 가능
- SQL 질의문은 세미콜론(;)으로 문장 끝 표시
- 대소문자 구분 X

| 번호 | 설명                                                       |
| :--: | :--------------------------------------------------------- |
|  1   | 테이블 구성 각 속성의 이름·데이터 타입·기본 제약 사항 정의 |
|  2   | 기본키 정의                                                |
|  3   | 대체키 정의                                                |
|  4   | 외래키 정의                                                |
|  5   | 데이터 무결성을 위한 제약조건 정의                         |

#### 속성 정의

- 테이블을 구성하는 각 속성 데이터 타입 선택
- NULL 값 허용 여부 · 기본값 필요 여부 결정

|   종류   | 설명                  | 예시                                                              |
| :------: | :-------------------- | :---------------------------------------------------------------- |
| NOT NULL | 속성이 NULL 값 비허용 | 1. 고객아이디 VARCHAR(20) NOT NULL                                |
| DEFAULT  | 속성의 기본값 지정    | 1. 적립금 INT DEFAULT 0<br>2. 담당자 VARCHAR(10) DEFAULT '홍길동' |

- 문자열·날짜 데이터는 작은 따옴표로 묶어서 표현
  - 작은 따옴표로 묶인 문자열은 대소문자 구분 필수

|         속성 데이터 타입          | 의미                                                                              |
| :-------------------------------: | :-------------------------------------------------------------------------------- |
|           INT · INTEGER           | 정수                                                                              |
|             SMALLINT              | INT보다 작은 정수                                                                 |
|      CHAR(n) · CHARACTER(n)       | 길이가 n인 고정 길이 문자열                                                       |
| VARCHAR(n) · CHARACTER VARYING(n) | 최대 길이가 n인 가변 길이 문자열                                                  |
|   NUMERIC(p, s) · DECIMAL(p, s)   | 고정 소수점 실수<br>p : 소수점 제외 전체 숫자 길이<br>s : 소수점 이하 숫자의 길이 |
|             FLOAT(n)              | 길이가 n인 부동 소수점 실수                                                       |
|               REAL                | 부동 소수점 실수                                                                  |
|               DATE                | 연, 월, 일로 표현되는 날짜                                                        |
|               TIME                | 시, 분, 초로 표현되는 시간                                                        |
|             DATETIME              | 날짜와 시간                                                                       |

#### 키 정의

|    종류     | 설명                                                                                             | 예시                                                                                                                                             |
| :---------: | :----------------------------------------------------------------------------------------------- | :----------------------------------------------------------------------------------------------------------------------------------------------- |
| PRIMARY KEY | 기본키 지정 키워드                                                                               | 1. PRIMARY KEY(고객아이디)<br>2. PRIMARY KEY(주문고객, 주문제품)                                                                                 |
|   UNIQUE    | 1. 대체키 지정 키워드<br>2. 대체키로 지정되는 속성값은 유일성을 가지고 기본키와 달리 NULL값 허용 | UNIQUE(고객이름)                                                                                                                                 |
| FOREIGN KEY | 1. 외래키 지정 키워드<br>2. 외래키가 참조하는 테이블의 속성을 REFERENCES 키워드 다음에 제시      | 1. FOREIGN KEY(소속부서) REFERENCES 부서(부서번호)<br>2. FOREIGN KEY(소속부서) REFERENCES 부서(부서번호)<br> ON DELETE CASCADE ON UPDATE CASCADE |

#### 외래키 옵션

- 참조 무결성 제약조건 유지 관련 옵션
- 참조 테이블에서 튜플 변경 시 처리 방법 지정 옵션

|    옵션     | 설명                                    |
| :---------: | :-------------------------------------- |
|  NO ACTION  | 튜플 변경 불가                          |
|   CASCADE   | 외래키 값 함께 변경                     |
|  SET NULL   | 외래키 값 NULL 변경                     |
| SET DEFAULT | 외래키 값을 미리 지정한 기본값으로 변경 |

#### 참조 무결성 제약조건 튜플 삭제 예시

<img src="https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch07/ch07-06-DeleteOption.PNG"  height="auto" />

|         옵션          | 예시                                                         |
| :-------------------: | :----------------------------------------------------------- |
|  ON DELETE NO ACTION  | 부서 테이블 튜플 삭제 불가                                   |
|   ON DELETE CASCADE   | 사원 테이블의 홍보부에 근무하는 정소화 사원 튜플도 함께 삭제 |
|  ON DELETE SET NULL   | 사원 테이블의 정소화 사원 소속부서 속성 값을 NULL로 변경     |
| ON DELETE SET DEFAULT | 사원 테이블의 정소화 사원 소속부서 속성값을 기본값으로 변경  |

#### 데이터 무결성 제약조건 정의

| 종류  | 설명                                                                                                           | 예시                                                                                            |
| :---: | :------------------------------------------------------------------------------------------------------------- | :---------------------------------------------------------------------------------------------- |
| CHECK | 1. 테이블에 정확·유효 데이터 유지를 위한 특정 속성 제약조건 지정<br>2. CONSTRAINT 키워드와 고유 이름 부여 가능 | 1. CHECK(재고량 >= 0 AND 재고량 <= 10000)<br>2. CONSTRAINT CHK_CPY CHECK(제조업체 = '한빛제과') |

#### CREATE TABLE문 작성 예제

| <h6>ex 1 : 고객 테이블은 고객아이디, 고객이름, 나이, 등급, 직업, 적립금 속성으로 구성된다. '고객아이디' 속성은 기본키다. '고객이름'과 '등급' 속성은 값이 반드시 입력되어야 하고 '적립금' 속성은 값을 입력하지 않으면 0이 기본으로 입력된다.</h6> | <img src="https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch07/ch07-07-CreateTable.PNG"  height="auto" /> |
| ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------ | ------------------------------------------------------------------------------------------------------------------------------------ |

### 테이블 변경 : ALTER TABLE

```SQL
ALTER TABLE 테이블_이름
ADD 속성_이름 데이터_타입 [NOT NULL] [DEFAULT 기본_값];
```

## 3절. SQL 데이터 조작
