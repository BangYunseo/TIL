# Chapter 7. SQL 질의어

> 1절. SQL 소개
>
> 2절. SQL 데이터 정의
>
> 3절. SQL 데이터 조작
>
> 4절. 조인
>
> 5절. MySQL 내장 함수
>
> 6절. 뷰
>
> 7절. 삽입 SQL

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

### 사용 테이블 정보(고객, 제품, 주문)

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

### CREATE TABLE : 테이블 생성

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

- ex 1 : 고객 테이블 생성

<img src="https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch07/ch07-07-CreateTable.PNG"  height="auto" />

| 고객 테이블 생성 조건                                                      |
| :------------------------------------------------------------------------- |
| 고객 테이블은 고객아이디, 고객이름, 나이, 등급, 직업, 적립금 속성으로 구성 |
| '고객아이디' 속성은 기본키                                                 |
| '고객이름'과 '등급' 속성은 값이 반드시 입력                                |
| '적립금' 속성은 값을 입력하지 않으면 0이 기본 입력                         |

- ex 2 : 제품 테이블 생성

<img src="https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch07/ch07-08-CreateTable2.PNG"  height="auto" />

| 제품 테이블 생성 조건                                                |
| :------------------------------------------------------------------- |
| 제품 테이블은 제품번호, 제품명, 재고량, 단가, 제조업체 속성으로 구성 |
| '제품번호' 속성은 기본키                                             |
| '재고량' 속성이 항상 0개 이상 10,000개 이하를 유지 필수              |

- ex 3 : 주문 테이블 생성

<img src="https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch07/ch07-09-CreateTable3.PNG"  height="auto" />

| 주문 테이블 생성 조건                                                            |
| :------------------------------------------------------------------------------- |
| 주문 테이블은 주문번호, 주문고객, 주문제품, 수량, 배송지, 주문일자 속성으로 구성 |
| '주문번호' 속성은 기본키                                                         |
| '주문고객' 속성이 고객 테이블의 고객아이디 속성을 참조하는 외래키                |
| '주문제품' 속성이 제품 테이블의 제품번호 속성을 참조하는 외래키                  |

- ex 4 : 배송업체 테이블 생성

<img src="https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch07/ch07-10-CreateTable4.PNG"  height="auto" />

| 주문 테이블 생성 조건                                |
| :--------------------------------------------------- |
| 주문 테이블은 업체번호, 주소, 전화번호 속성으로 구성 |
| '업체번호' 속성이 기본키                             |

### ALTER TABLE : 테이블 수정

- 새로운 속성 추가
- 기존 속성 삭제
- 새로운 제약조건 추가
- 기존 제약조건 삭제

#### ALTER TABLE : 새로운 속성 추가

```SQL
ALTER TABLE 테이블_이름
ADD 속성_이름 데이터_타입 [NOT NULL] [DEFAULT 기본_값];
```

- ex 1 : 고객 테이블에 가입날짜 속성 추가

```SQL
ALTER TABLE 고객 ADD 가입날짜 DATE;
```

#### ALTER TABLE : 기존 속성 삭제

```SQL
ALTER TABLE 테이블_이름 DROP COLUMN 속성_이름;
```

- 삭제할 속성과 관련된 제약조건이 존재할 경우

  - 속성 삭제 미수행
  - 관련 제약조건 먼저 삭제 필요

- ex 2 : 고객 테이블 가입날짜 속성 삭제

```SQL
ALTER TABLE 고객 DROP COLUMN 가입날짜;
```

#### ALTER TABLE : 새로운 제약조건 추가

```SQL
ALTER TABLE 테이블_이름 ADD CONSTRAINT 제약조건_이름 제약조건_내용;
```

- ex 3 : 고객 테이블에 20세 이상 고객만 가입 가능하다는 데이터 무결성 제약조건 추가

```SQL
ALTER TABLE 고객 ADD CONSTRAINT CHK_AGE CHECK(나이 >= 20);
```

#### ALTER TABLE : 기존 제약조건 삭제

```SQL
ALTER TABLE 테이블_이름 DROP CONSTRAINT 제약조건_이름;
```

- ex 4 : 고객 테이블에 20세 이상 고객만 가입할 수 있는 데이터 무결성 제약조건, CHK_AGE 삭제

```SQL
ALTER TABLE 고객 DROP CONSTRAINT CHK_AGE;
```

### DROP TABLE : 테이블 삭제

```SQL
DROP TABLE 테이블_이름;
```

- 삭제할 테이블을 참조하는 테이블이 존재할 경우

  - 테이블 삭제 미수행
  - 관련 외래키 제약조건 먼저 삭제 필수

- ex 1 : 배송업체 테이블 삭제

```SQL
DROP TABLE 배송업체;
```

## 3절. SQL 데이터 조작

### 데이터 조작 기능

- 데이터 검색·삽입·수정·삭제 기능

<img src="https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch07/ch07-11-DML.PNG"  height="auto" />

### INSERT : 데이터 삽입

```SQL
INSERT
INTO 테이블_이름[(속성_리스트)]
VALUES (속성값_리스트);
```

| 키워드 | 설명                                           |
| :----: | :--------------------------------------------- |
|  INTO  | 튜플 함께 삽입 시 테이블 이름과 속성 이름 나열 |
| VALUES | 키워드와 함께 삽입할 속성값들 나열             |

- INTO 키워드
  - 속성\_리스트 생략 시 테이블을 정의할 때 지정된 속성 순서로 값 삽입
  - INTO 키워드 속성 이름 <=> VALUES 키워드 속성값 : 순서대로 1:1 대응

#### INSERT : 데이터 직접 삽입

- ex 1 : 판매 데이터베이스의 고객 테이블에 고객아이디가 'strawberry', 고객이름이 '최유경', 나이가 '30', 등급이 'vip', 직업이 '공무원', 적립금이 '100'원인 새로운 고객의 정보 삽입

```SQL
/* 고객 테이블 속성 나열 */
INSERT
INTO 고객(고객아이디, 고객이름, 나이, 등급, 직업, 적립금)
VALUES ('strawberry', '최유경', 30, 'vip', '공무원', 100);

/* 고객 테이블 속성 생략 */
INSERT
INTO 고객
VALUES ('strawberry', '최유경', 30, 'vip', '공무원', 100);
```

<img src="https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch07/ch07-12-InsertData.PNG"  height="auto" />

- ex 2 : 판매 데이터베이스의 고객 테이블에 고객아이디가 'tomato', 고객이름이 '정은심', 나이가 '36', 등급이 'gold', 적립금이 '4000'원인 새로운 고객의 정보 삽입

```SQL
/* 고객 테이블 속성 나열 */
INSERT
INTO 고객(고객아이디, 고객이름, 나이, 등급, 적립금)
VALUES ('tomato', '정은심', 36, 'gold', 4000);

/* 고객 테이블 속성 생략 */
INSERT
INTO 고객
VALUES ('tomato', '정은심', 36, 'gold', NULL, 4000);
/* 속성 생략 시 NULL 지정 필수 */
```

<img src="https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch07/ch07-13-InsertData2.PNG"  height="auto" />

- 직업 속성에 NULL 삽입
- 직업 속성은 NULL을 허용하기 때문에 삽입 가능

#### INSERT : 부속 질의문을 이용한 데이터 삽입

- SELECT문을 이용한 부속 질의문 생성

```SQL
INSERT
INTO 테이블_이름[(속성_리스트)]
SELECT 문;
```

- ex 1 : '한빛제과'에서 제조한 제품의 제품명, 재고량, 단가를 제품 테이블에서 검색하여 '한빛제품' 테이블에 삽입

```SQL
INSERT
INTO 한빛제품(제품명, 재고량, 단가)
SELECT 제품명, 재고량, 단가
FROM 제품
WHERE 제조업체 = '한빛제과';
```

### SELECT : 데이터 검색

- 검색 결과를 테이블 형태로 반환

```SQL
SELECT [ALL | DISTINCT] 속성_리스트
FROM 테이블_리스트;
```

| 키워드 | 설명                                                                                                                     |
| :----: | :----------------------------------------------------------------------------------------------------------------------- |
| SELECT | 검색하고 싶은 속성 이름 나열                                                                                             |
|  FROM  | 검색하고 싶은 속성이 있는 테이블 나열                                                                                    |
|   AS   | 1. 결과 테이블 속성 별칭 설정<br>2. 새로운 이름에 공백 포함 시 큰따옴표("") · 작은따옴표('')로 묶어 표현<br>3. 생략 가능 |

| 중복 옵션 | 설명                                                     |
| :-------: | :------------------------------------------------------- |
|    ALL    | 1. 결과 테이블 튜플 중복 허용<br>2. 기본값으로 생략 가능 |
| DISTINCT  | 결과 테이블 튜플 중복 비허용                             |

#### SELECT : 기본 검색

- ex 1 : 고객 테이블에서 고객아이디, 고객이름, 등급 속성 검색

```SQL
SELECT 고객아이디, 고객이름, 등급
FROM 고객;
```

<img src="https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch07/ch07-14-SelectData.PNG"  height="auto" />

- ex 2 : 고객 테이블에 존재하는 모든 속성 검색

```SQL
SELECT 고객아이디, 고객이름, 나이, 등급, 직업, 적립금
FROM 고객;

/* 모든 속성의 이름은 *로 대체 가능 */
SELECT *
FROM 고객;
```

<img src="https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch07/ch07-15-SelectData2.PNG"  height="auto" />

- ex 3 : 제품 테이블에서 제조업체 검색(중복)

```SQL
SELECT ALL 제조업체
FROM 제품;
/* ALL 생략 시에도 동일한 결과 */
```

<img src="https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch07/ch07-16-SelectData3.PNG"  height="auto" />

- ex 4 : 제품 테이블에서 제조업체 검색(중복 제거)

```SQL
SELECT DISTINCT 제조업체
FROM 제품;
```

<img src="https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch07/ch07-17-SelectData4.PNG"  height="auto" />

- ex 5 : 제품 테이블에서 제조명과 단가를 검색하되 단가를 가격이라는 이름으로 검색

```SQL
SELECT 제조명, 단가 AS '가격'
FROM 제품;
```

<img src="https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch07/ch07-18-SelectData5.PNG"  height="auto" />

#### SELECT : 산술식을 이용한 검색

- SELECT 키워드와 함께 산술식 제시
- 속성값은 실제로 변경 X
- 결과 테이블에서만 계산된 결과값 검색

|       산술식 구성 요소       |
| :--------------------------: |
|          속성 이름           |
| 산술 연산자(+, -, ,\*, / 등) |
|             상수             |

- ex 1 : 제품명과 단가 속성을 검색하되 단가에 500원을 더해 '조정 단가'라는 이름으로 검색

```SQL
SELECT 제조명, 단가+500 AS '조정 가격'
FROM 제품;
```

<img src="https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch07/ch07-19-SelectData6.PNG"  height="auto" />

#### SELECT : 조건 검색

- 조건 만족 데이터만 검색
- WHERE 키워드·비교 연산자·논리 연산자
  - 숫자·문자·날짜 비교 가능
  - 조건에서 문자·날짜값은 작은따옴표('')로 묶어 표현
    - ex 1 : 'A' < 'C'
    - ex 2 : '2019-12-01' < '2019-12-02'

```SQL
SELECT [ALL | DISTINCT] 속성_리스트
FROM 테이블_리스트
[WHERE 조건];
```

| 비교 연산자 | 의미        |
| :---------: | :---------- |
|      =      | 같다        |
|     <>      | 다르다      |
|      <      | 작다        |
|      >      | 크다        |
|     <=      | 작거나 같다 |
|     >=      | 크거나 같다 |

| 논리 연산자 | 의미                              |
| :---------: | :-------------------------------- |
|     AND     | 모든 조건을 만족해야 검색         |
|     OR      | 여러 조건 중 하나만 만족해도 검색 |
|     NOT     | 조건을 만족하지 않는 것만 검색    |

- ex 1 : 제품 테이블에서 '한빛제과'가 제조한 제품의 제품명, 재고량, 단가 검색

```SQL
SELECT 제품명, 재고량, 단가
FROM 제품
WHERE 제조업체 = '한빛제과';
```

<img src="https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch07/ch07-20-SelectData7.PNG"  height="auto" />

- ex 2 : 주문 테이블에서 'apple' 고객이 15개 이상 주문한 주문제품, 수량, 주문일자 검색

```SQL
SELECT 주문제품, 수량, 주문일자
FROM 주문
WHERE 주문고객 = 'apple' AND 수량 >= 15;
```

<img src="https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch07/ch07-21-SelectData8.PNG"  height="auto" />

- ex 3 : 주문 테이블에서 'apple' 고객이 주문했거나 15개 이상 주문한 주문제품, 수량, 주문일자, 주문고객 검색

```SQL
SELECT 주문제품, 수량, 주문일자
FROM 주문
WHERE 주문고객 = 'apple' OR 수량 >= 15;
```

<img src="https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch07/ch07-22-SelectData9.PNG"  height="auto" />

- ex 4 : 제품 테이블에서 단가가 2000원 이상이면서 3000원 이하인 제품의 제품명, 단가, 제조업체 검색

```SQL
SELECT 제품명, 단가, 제조업체
FROM 제품
WHERE 단가 >= 2000 AND 단가 <= 3000;
```

<img src="https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch07/ch07-23-SelectData10.PNG"  height="auto" />

#### SELECT : LIKE 이용 검색

- LIKE 키워드를 이용해 부분적으로 일치하는 데이터 검색
- 문자열 이용 조건 시에만 사용 가능

| 기호 | 설명                                 |
| :--: | :----------------------------------- |
|  %   | 0개 이상 문자(문자 내용·개수 상관 X) |
|  \_  | 1개 문자(문자 내용 상관 X)           |

|       사용 예시       | 설명                                                    |
| :-------------------: | :------------------------------------------------------ |
|    LIKE '데이터%'     | 데이터로 시작하는 문자열(데이터로 시작하면 길이 상관 X) |
|    LIKE '%데이터'     | 데이터로 끝나는 문자열(데이터로 끝나면 길이 상관 X)     |
|    LIKE '%데이터%'    | 데이터가 포함된 문자열                                  |
| LIKE '데이터\_ \_ \_' | 데이터로 시작하는 6글자 문자열                          |
|   LIKE '\_ \_ 한%'    | 세 번째 글자가 '한'인 문자열                            |

- ex 1 : 고객 테이블에서 성이 김 씨인 고객의 고객이름, 나이, 등급, 적립금 검색

```SQL
SELECT 고객이름, 나이, 등급, 적립금
FROM 고객
WHERE 고객이름 LIKE '김%';
```

<img src="https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch07/ch07-24-SelectData11.PNG"  height="auto" />

- ex 2 : 고객 테이블에서 고객아이디가 5글자인 고객의 고객아이디, 고객이름, 등급 검색

```SQL
SELECT 고객아이디, 고객이름, 등급
FROM 고객
WHERE 고객아이디 LIKE '_ _ _ _ _';
```

<img src="https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch07/ch07-25-SelectData12.PNG"  height="auto" />

#### SELECT : NULL 이용 검색

- 검색 조건에서 NULL은 다른 값과 크기 비교 시 모두 거짓

|   키워드    | 설명                             |
| :---------: | :------------------------------- |
|   IS NULL   | 특정 속성값이 NULL인지 비교      |
| IS NOT NULL | 특정 속성값이 NULL이 아닌지 비교 |

- ex 1 : 고객 테이블에서 나이가 아직 입력되지 않은 고객의 고객이름 검색

```SQL
SELECT 고객이름
FROM 고객
WHERE 나이 IS NULL;
```

<img src="https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch07/ch07-26-SelectData13.PNG"  height="auto" />

- ex 2 : 고객 테이블에서 나이가 이미 입력된 고객의 고객이름 검색

```SQL
SELECT 고객이름
FROM 고객
WHERE 나이 IS NOT NULL;
```

<img src="https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch07/ch07-27-SelectData14.PNG"  height="auto" />

#### SELECT : 정렬 검색

```SQL
SELECT [ALL | DISTINCT] 속성_리스트
FROM 테이블_리스트
[WHERE 조건]
[ORDER BY 속성_리스트[ASC | DESC]];
```

|  키워드  | 설명                                                |
| :------: | :-------------------------------------------------- |
| ORDER BY | 결과 테이블 내용을 사용자가 원하는 순서로 검색      |
|   ASC    | 1. 기본 오름차순 정렬<br>2. NULL을 맨 마지막에 검색 |
|   DESC   | 1. 내림차순 정렬<br>2. NULL을 맨 처음에 검색        |

- 정렬 기준이 여럿인 경우

  - 정렬 기준 속성 순서로 제시

- ex 1 : 고객 테이블에서 고객이름, 등급, 나이를 검색하되 나이를 기준으로 내림차순 정렬 검색

```SQL
SELECT 고객이름, 등급, 나이
FROM 고객
ORDER BY 나이 DESC;
```

<img src="https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch07/ch07-28-SelectData15.PNG"  height="auto" />

- ex 2 : 주문 테이블에서 수량이 10개 이상인 주문의 주문고객, 주문제품, 수량, 주문일자 검색 / 주문제품 기준 오름차순 정렬, 동일 제품은 수량 기준 내림차순 정렬

```SQL
SELECT 주문고객, 주문제품, 수량, 주문일
FROM 주문
WHERE 수량 >= 10
ORDER BY 주문제품 ASC, 수량 DESC;
```

<img src="https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch07/ch07-29-SelectData16.PNG"  height="auto" />

#### SELECT : 집계 함수 이용 검색

- 특정 속성값을 통계적으로 계산한 결과 검색을 위해 집계 함수 이용

- 집계 함수(Aggregate Function)
  - 열 함수(Column Function)
  - 개수 · 합계 · 평균 · 최댓값 · 최솟값 계산 기능 제공

| 집계 함수 사용 시 주의 사항     |
| :------------------------------ |
| NULL 속성값 제외 계산           |
| WHERE 절 사용 불가              |
| SELECT 절 · HAVING 절 사용 가능 |

| 집계 함수 종류 | 의미        | 사용 가능 속성 타입 |
| :------------: | :---------- | :-----------------: |
|     COUNT      | 속성값 개수 |     모든 데이터     |
|      MAX       | 속성 최댓값 |     모든 데이터     |
|      MIN       | 속성 최솟값 |     모든 데이터     |
|      SUM       | 속성값 합계 |     숫자 데이터     |
|      AVG       | 속성값 평균 |     숫자 데이터     |

- ex 1 : 제품 테이블에서 모든 제품의 단가 평균 검색

```SQL
SELECT AVG(단가)
FROM 제품;
```

<img src="https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch07/ch07-30-SelectData17.PNG"  height="auto" />

- ex 2 : 한빛제과에서 제조한 제품의 재고량 합계 검색

```SQL
SELECT SUM(재고량) AS '재고량 합계'
FROM 제품
WHERE 제조업체 = '한빛제과';
```

<img src="https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch07/ch07-31-SelectData18.PNG"  height="auto" />

- ex 3 : 고객 테이블의 고객 수 검색

1. 고객아이디 속성 이용 계산

```SQL
SELECT COUNT(고객아이디) AS '고객수'
FROM 고객;
```

<img src="https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch07/ch07-32-SelectData19.PNG"  height="auto" />

2. 나이 속성 이용 계산

```SQL
SELECT COUNT(나이) AS '고객수'
FROM 고객;
/* 나이 속성이 NULL인 오형준 튜플 제외 계산 */
```

<img src="https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch07/ch07-33-SelectData20.PNG"  height="auto" />

3. - 이용 계산

```SQL
SELECT COUNT(*) AS '고객수'
FROM 고객;
```

<img src="https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch07/ch07-32-SelectData19.PNG"  height="auto" />

- ex 4 : 제품 테이블에서 제조업체 수 검색

```SQL
SELECT COUNT(DISTINCT 제조업체) AS '제조업체 수'
FROM 제품;
/* DISTINCT 키워드로 중복 제거 후 서로 다른 제조업체 개수만 계산 */
```

<img src="https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch07/ch07-34-SelectData21.PNG"  height="auto" />

#### SELECT : 그룹 검색

```SQL
SELECT [ALL | DISTINCT] 속성_리스트
FROM 테이블_리스트
[WHERE 조건]
[GROUP BY 속성_리스트 [HAVING 조건]]
[ORDER BY 속성_리스트 [ASC | DESC]];
```

|  키워드  | 설명                                                                               |
| :------: | :--------------------------------------------------------------------------------- |
| GROUP BY | 특정 속성값이 같은 튜플을 모아 그룹 생성 후 그룹별 검색                            |
|  HAVING  | 1. 그룹에 대한 조건 작성<br>2. GROUP BY 키워드와 함께 그룹을 나누는 기준 속성 지정 |

- 그룹 기준 속성을 SELECT 절에 작성하는 것을 권장

- ex 1 : 주문 테이블에서 주문제품별 수량의 합계 검색

```SQL
SELECT 주문제품, SUM(수량) AS '주문제품 총 수량'
FROM 주문
GROUP BY 주문제품;
```

<img src="https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch07/ch07-35-SelectData22.PNG"  height="auto" />

- 동일 제품 주문 튜플을 그룹화
- 그룹별 수량 합계 계산

<img src="https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch07/ch07-36-SelectData23.PNG"  height="auto" />

- ex 2 : 제품 테이블에서 제조업체 별 제조한 제품 개수, 제품 중 가장 비싼 단가를 검색하되 제품의 개수는 '제품 수', 가장 비싼 단가는 '최고가'로 출력

```SQL
SELECT 제조업체, COUNT(*) AS '제품 수', MAX(단가) AS '최고가'
FROM 제품
GROUP BY 제조업체;
```

<img src="https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch07/ch07-37-SelectData24.PNG"  height="auto" />

- ex 3 : 제품 테이블에서 제품을 3개 이상 제조한 제품업체 별 제품의 개수, 제품 중 가장 비싼 단가 검색

```SQL
SELECT 제조업체, COUNT(*) AS '제품 수', MAX(단가) AS '최고가'
FROM 제품
GROUP BY 제조업체
HAVING COUNT(*) >= 3;
```

<img src="https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch07/ch07-38-SelectData25.PNG"  height="auto" />

- ex 4 : 고객 테이블에서 적립금 평균이 1000원 이상인 등급에 대해 등급별 고객수, 적립금 평균 검색

```SQL
SELECT COUNT(*) AS '고객 수', AVG(적립금) AS '적립금 평균'
FROM 고객
GROUP BY 등급
HAVING AVG(적립금) >= 1000;
```

<img src="https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch07/ch07-39-SelectData26.PNG"  height="auto" />

- ex 5 : 주문 테이블에서 각 주문이 주문한 제품의 총 주문 수량을 주문제품 별로 검색

```SQL
SELECT 주문제품, 주문고객, SUM(수량) AS '총 주문 수량'
FROM 주문
GROUP BY 주문제품, 주문고객;
```

<img src="https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch07/ch07-40-SelectData27.PNG"  height="auto" />

- 집계 함수 · GROUP BY 절에 명시된 속성 외의 속성은 SELECT 절에 작성 불가

#### SELECT : 여러 테이블 조인 검색

- 조인 검색 : 여러 테이블을 연결하여 데이터 검색
- 조인 속성 : 조인 검색을 위한 테이블 연결 속성

| 조인 속성 주의 사항                                                  |
| :------------------------------------------------------------------- |
| 연결 테이블 간 조인 속성 이름 상관 X                                 |
| 도메인은 무조건 일치해야 함                                          |
| 외래키가 조인 속성인 경우 다수                                       |
| 속성 이름 앞에 해당 속성 소속 테이블 이름 명시<br>ex ) 주문.주문고객 |

| 키워드 | 설명                                   |
| :----: | :------------------------------------- |
|  FROM  | 검색에 필요한 모든 테이블 나열         |
| WHERE  | 조인 속성값 동일 의미의 조인 조건 제시 |

- ex 1 : 판매 데이터베이스에서 banana 고객이 주문한 제품의 이름 검색

```SQL
SELECT 제품.제품명
FROM 주문, 제품
WHERE 주문.주문고객 = 'banana'
AND 제품.제품번호 = 주문.주문제품;
```

<img src="https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch07/ch07-41-SelectData28.PNG"  height="auto" />

- ex 2 : 판매 데이터베이스에서 나이가 30세 이상인 고객에 주문한 제품의 번호와 주문일자 검색

```SQL
SELECT 제품번호, 주문일자
FROM 고객, 주문
WHERE 고객.나이 >= 30
AND 고객.고객아이디 = 주문.주문고객;
```

<img src="https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch07/ch07-42-SelectData29.PNG"  height="auto" />

- 여러 테이블 조인 검색 특성

```SQL
/* 이름이 같은 속성이 없는 경우 테이블 이름 없이 이름으로만 작성 가능 */

SELECT 주문제품, 주문일자
FROM 고객 A, 주문 B
WHERE A.나이 >= 30
AND A.고객아이디 = B.주문고객;

/* 테이블 이름 별칭 가능 */
```

- ex 3 : 판매 데이터베이스에서 고명석 고객이 주문한 제품의 제품명 검색

```SQL
SELECT 제품.제품명
FROM 제품, 고객, 주문
WHERE 고객.고객아이디 = '고명석'
AND 주문.주문고객 = 고객.고객아이디
AND 제품.제품번호 = 주문.주문제품;
```

<img src="https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch07/ch07-43-SelectData30.PNG"  height="auto" />

#### INNER JOIN : JOIN 활용

- 표준 SQL에서 사용하는 방법
- INNER JOIN과 ON 키워드 이용

```SQL
SELECT 속성_리스트
FROM 테이블1 INNER JOIN 테이블 2
ON 조인조건
[WHERE 검색조건];
```

- ex 1 : 나이가 30세 이상인 고객이 주문한 제품번호와 주문일자 검색

```SQL
SELECT 주문.주문제품, 주문.주문일자
FROM 고객 INNER JOIN 주문
ON 고객.고객아이디 = 주문.주문고객
WHERE 고객.나이 >= 30;
```

#### OUTER JOIN : 외부 조인

- 조인 조건을 만족하지 않는 튜플에서 검색 수행
- OUTER JOIN과 ON 키워드 이용

```SQL
SELECT 속성_리스트
FROM 테이블1 LEFT|RIGHT|FULL OUTER JOIN 테이블2
ON 조인조건
[WHERE 검색조건];
```

|       분류       |       명칭       | 설명                    |
| :--------------: | :--------------: | :---------------------- |
| LEFT OUTER JOIN  |  왼쪽 외부 조인  | 왼쪽 테이블 기준 정렬   |
| RIGHT OUTER JOIN | 오른쪽 외부 조인 | 오른쪽 테이블 기준 정렬 |
| FULL OUTER JOIN  |  완전 외부 조인  | 모든 테이블 기준 정렬   |

- ex 1 : 고객 테이블 기준 정렬

```SQL
/* LEFT OUTER JOIN */
SELECT 고객.고객이름, 주문.주문제품, 주문.주문일자
FROM 고객 LEFT OUTER JOIN 주문
ON 고객.고객아이디 = 주문.주문고객;

/* RIGHT OUTER JOIN */
SELECT 고객.고객이름, 주문.주문제품, 주문.주문일자
FROM 주문 RIGHT OUTER JOIN 고객
ON 고객.고객아이디 = 주문.주문고객;

/* 고객 테이블 기준 정렬이므로 두 외부 조인의 결과는 동일 */
```

<img src="https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch07/ch07-44-SelectData31.PNG"  height="auto" />

- 주문하지 않는 고객 포함 조회

#### SELECT : 부속 질의문 이용 검색

- SELECT 문 안에 또 다른 SELECT 문 포함

|    종류     | 설명                                                         |
| :---------: | :----------------------------------------------------------- |
| 상위 질의문 | 1. 주 질의문<br>2. 다른 SELECT 문을 포함하는 SELECT 문       |
| 부속 질의문 | 1. 서브 질의문<br>2. 다른 SELECT 문 안에 들어 있는 SELECT 문 |

| 부속 질의문 주의 사항                            |
| :----------------------------------------------- |
| 괄호로 묶어서 작성                               |
| ORDER BY 절 사용 불가                            |
| 단일 행 부속 질의문 : 하나의 행 결과로 반환      |
| 다중 행 부속 질의문 : 하나 이상의 행 결과로 반환 |

- 수행 순서 : 부속 질의문 -> 상위 질의문
- 질의문 연결 연산자

  - 단일 행 부속 질의문 : 비교 연산자(=, <>, >, >=, <, <=>) 사용
  - 다중 행 부속 질의문 : 비교 연산자 사용 불가

- ex 1 : 판매 데이터베이스에서 달콤비스킷을 생산한 제조업체가 만든 제품들의 제품명과 단가 검색

```SQL
SELECT 제품명, 단가
FROM 제품
WHERE 제조업체  = ( SELECT 제조업체
                    FROM 제품
                    WHERE 제품명 = '달콤비스킷');
```

<img src="https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch07/ch07-45-SelectData32.PNG"  height="auto" />

- ex 2 : 판매 데이터베이스에서 적립금이 가장 많은 고객의 고객 이름과 적립금 검색

```SQL
SELECT 고객이름, 적립금
FROM 고객
WHERE 적립금 = (SELECT MAX(적립금) FROM 고객);
```

<img src="https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch07/ch07-46-SelectData33.PNG"  height="auto" />

- 부속 질의문 연산자

|   연산자   | 설명                                                                                        |
| :--------: | :------------------------------------------------------------------------------------------ |
|     IN     | 부속 질의문 결과값 중 일치하는 것이 있으면 검색 조건이 참                                   |
|   NOT IN   | 부속 질의문 결과값 중 일치하는 것이 없으면 검색 조건이 참                                   |
|   EXISTS   | 부속 질의문 결과값이 하나라도 존재하면 검색 조건이 참                                       |
| NOT EXISTS | 부속 질의문 결과값이 하나도 존재하지 않으면 검색 조건이 참                                  |
|    ALL     | 부속 질의문 결과값 모두와 비교한 결과가 참이면 검색 조건 만족(비교 연산자와 함께 사용)      |
| ANY · SOME | 부속 질의문 결과값 중 하나라도 비교한 결과가 참이면 검색 조건 만족(비교 연산자와 함께 사용) |

- ex 3 : 판메 데이터베이스에서 banana 고객이 주문한 제품의 제품명과 제조업체 검색

```SQL
SELECT 제품명, 제조업체
FROM 제품
WHERE 제품번호 IN (SELECT 주문제품
                  FROM 주문
                  WHERE 주문고객 = 'banana');
```

<img src="https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch07/ch07-47-SelectData34.PNG"  height="auto" />

- ex 4 : 판매 데이터베이스에서 banana 고객이 주문하지 않은 제품의 제품명과 제조업체 검색

```SQL
SELECT 제품명, 제조업체
FROM 제품
WHERE 제품번호 NOT IN (SELECT 주문제품
                      FROM 주문
                      WHERE 주문고객 = 'banana');
```

<img src="https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch07/ch07-48-SelectData35.PNG"  height="auto" />

- ex 5 : 판매 데이터베이스에서 대한식품이 제조한 모든 제품의 단가보다 비싼 제품의 제품명, 단가, 제조업체 검색

```SQL
SELECT 제품명, 단가, 제조업체
FROM 제품
WHERE 단가 > ALL (SELECT 단가
                  FROM 제품
                  WHERE 제조업체 = '대한식품');
```

<img src="https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch07/ch07-49-SelectData36.PNG"  height="auto" />

- ex 6 : 판매 데이터베이스에서 2022년 3월 15일에 제품을 주문한 고객의 고객이름 검색

```SQL
SELECT 고객이름
FROM 고객
WHERE EXISTS (SELECT *
              FROM 주문
              WHERE 주문일자 = '2022-03-15'
              AND 고객.고객아이디 = 주문.주문고객);
```

<img src="https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch07/ch07-50-SelectData37.PNG"  height="auto" />

- ex 7 : 판매 데이터베이스에서 2002년 3월 15일에 제품을 주문하지 않은 고객의 고객이름 검색

```SQL
SELECT 고객이름
FROM 고객
WHERE NOT EXISTS (SELECT *
              FROM 주문
              WHERE 주문일자 = '2022-03-15'
              AND 고객.고객아이디 = 주문.주문고객);
```

<img src="https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch07/ch07-51-SelectData38.PNG"  height="auto" />

### UPDATE : 데이터 수정

- 테이블에 저장된 튜플에서 특정 속성값 수정

```SQL
UPDATE 테이블_이름
SET 속성_이름1 = 값1, 속성_이름2 = 값2, ···
[WHERE 조건];
```

| 키워드 | 설명                                                                                                        |
| :----: | :---------------------------------------------------------------------------------------------------------- |
|  SET   | 속성값 수정 방법 지정                                                                                       |
| WHERE  | 1. 제시된 조건을 만족하는 튜플의 속성값만 수정<br>2. WHERE 절 생략 시 테이블에 존재하는 모든 튜플 대상 수정 |

- ex 1 : 제품 테이블에서 제품번호가 p03인 제품의 제품명을 통큰파이로 수정

```SQL
UPDATE 제품
SET 제품명 = '통큰파이'
WHERE 제품번호 = 'p03';
```

<img src="https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch07/ch07-52-UpdateData.PNG"  height="auto" />

- ex 2 : 제품 테이블의 모든 제품의 단가를 10% 인상 후 검색

```SQL
UPDATE 제품
SET 단가 = 단가 * 1.1;

SELECT *
FROM 제품;
```

<img src="https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch07/ch07-53-UpdateData2.PNG"  height="auto" />

- ex 3 : 판매 데이터베이스에서 정소화 고객이 주문한 제품의 주문수량을 5개로 수정 후 내용 검색

```SQL
UPDATE 주문
SET 수량 = 5
WHERE 주문고객 IN (SELECT 고객아이디
                  FROM 고객
                  WHERE 고객이름 = '정소화');

SELECT *
FROM 주문;
```

<img src="https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch07/ch07-54-UpdateData3.PNG"  height="auto" />

### DELETE : 데이터 삭제

- 테이블에 저장된 데이터 삭제

```SQL
DELETE
FROM 테이블_이름
[WHERE 조건];
```

- WHERE 절에 제시한 조건을 만족하는 튜플 삭제

  - WHERE 절 생략 시 테이블에 존재하는 모든 튜플을 삭제해서 빈 테이블로 변환

- ex 1 : 주문 테이블에서 주문일자가 2022년 5월 22일인 주문 내역 삭제 후 삭제 여부 확인

```SQL
DELETE
FROM 주문
WHERE 주문일자 = '2022-05-22';

SELECT *
FROM 주문;
```

<img src="https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch07/ch07-55-DeleteData.PNG"  height="auto" />

- ex 2 : 판매 데이터베이스에서 정소화 고객이 주문한 내역을 주문 테이블에서 삭제 후 삭제 여부 확인

```SQL
DELETE
FROM 주문
WHERE 주문고객 IN (SELECT 고객아이디
                  FROM 고객
                  WHERE 고객이름 = '정소화');

SELECT * FROM 주문;
```

<img src="https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch07/ch07-56-DeleteData2.PNG"  height="auto" />

- ex 3 : 판매 데이터베이스의 주문 테이블에 존재하는 모든 튜플 삭제 후 삭제 여부 확인

```SQL
DELETE
FROM 주문;

SELECT * FROM 주문;
```

<img src="https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch07/ch07-57-DeleteData3.PNG"  height="auto" />

- DROP TABLE과는 다르게 빈 테이블 형태로 스키마는 존재

## 4절. 조인

### JOIN : 테이블 연결

- ex 1 : 주문번호에 따른 고객이름과 배송지 조회

```SQL
SELECT 주문.주문번호, 고객.고객이름, 주문.배송지
FROM 고객
JOIN 주문
ON 고객.고객아이디 = 주문.주문고객;
```

<img src="https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch07/ch07-58-JoinTable.PNG"  height="auto" />

#### LEFT JOIN : 왼쪽 테이블 기준 조인

- ex 1 : 모든 고객들의 고객아이디, 고객이름, 배송지 검색

```SQL
SELECT 고객.고객아이디, 고객.고객이름, 주문.배송지
FROM 고객
LEFT OUTER JOIN 주문
ON 고객.고객아이디 = 주문.주문고객;
```

<img src="https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch07/ch07-59-LeftJoinTable.PNG"  height="auto" />

- ex 2 : 제품번호 별 제품명, 주문고객의 수량, 나이, 등급 검색

```SQL
SELECT 제품.제품번호, 제품.제품명, 주문.수량, 고객.나이, 고객.등급
FROM 제품
LEFT OUTER JOIN 주문
ON 제품.제품번호 = 주문.주문제품
LEFT OUTER JOIN 고객
주문.주문고객 = 고객.고객아이디;
```

<img src="https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch07/ch07-61-LeftJoinTable2.PNG"  height="auto" />

- ex 3 : apple 고객이 주문한 제품번호, 제품명, 수량, 나이, 등급 검색

```SQL
SELECT 제품.제품번호, 제품.제품명, 주문.수량, 고객.나이, 고객.등급
FROM 제품
LEFT OUTER JOIN 주문
ON 제품.제품번호 = 주문.주문제품
LEFT OUTER JOIN 고객
ON 주문.주문고객 = 고객.고객아이디
WHERE 고객.고객아이디 = 'apple'
```

#### RIGHT JOIN : 오른쪽 테이블 기준 조인

- ex 1 : 모든 제품의 주문된 제품번호, 제품명, 주문고객 검색

```SQL
SELECT 제품.제품번호, 제품.제품명, 주문.주문고객
FROM 주문
RIGHT OUTER JOIN 제품
ON 제품.제품번호 = 주문.주문제품;
```

<img src="https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch07/ch07-60-RightJoinTable.PNG"  height="auto" />

## 5절. MySQL 내장 함수

### 단일행 함수

|         구분         | 함수                                                                                                     |
| :------------------: | :------------------------------------------------------------------------------------------------------- |
|      숫자 함수       | ABS, CEIL, COS, EXP, FLOOR, LN, LOG, MOD, POWER, RAND, ROUND, SIGN, TRUNCATE                             |
| 문자 함수(문자 반환) | CHAR, CONCAT, LEFT, RIGHT, LOWER, UPPER, LPAD, RPAD, LTRIM, RTRIM, REPLACE, REVERSE, RIGHT, SUBSTR, TRIM |
| 문자 함수(숫자 반환) | ASCII, INSTR, LENGTH                                                                                     |
|    날짜·시간 함수    | ADDDATE, CURRENT_DATE, DATE, DATEDIFF, DAYNAME, LAST_DAY, SYSDATE, TIME                                  |
|      변환 함수       | CAST, CONVERT, DATE_FORMAT, STR_TO_DATE                                                                  |
|      정보 함수       | DATABASE, SCHEMA, ROWCOUNR, USER, VERSION                                                                |
|    NULL 관련 함수    | COALESCE, ISNULL, IFNULL, NULLIF                                                                         |

### 집계 함수

|  종류  |
| :----: |
|  AVG   |
| COUNT  |
|  MAX   |
|  MIN   |
|  STD   |
| STDDEV |
|  SUM   |

### 윈도우 함수·분석 함수

|    종류     |
| :---------: |
|  CUME_DIST  |
| DENSE_RANK  |
| FIRST_VALUE |
| LAST_VALUE  |
|    LEAD     |
|    NTILE    |
|    RANK     |
| ROW_NUMBER  |

#### 숫자 함수 예시

|          종류          | 설명                                     | 예시               |
| :--------------------: | :--------------------------------------- | :----------------- |
|       ABS(숫자)        | 절댓값 계산                              | ABS(-4.5) => 4.5   |
|       CEIL(숫자)       | 숫자보다 크거나 같은 최소 정수           | CEIL(4.1) => 5     |
|      FLOOR(숫자)       | 숫자보다 작거나 같은 최소 정수           | FLOOR(4.1) => 4    |
|     ROUND(숫자, m)     | 숫자의 반올림<br>                        |
| m : 반올림 기준 자릿수 | ROUND(5.36, 1) => 5.40                   |
|      LOG(n, 숫자)      | 숫자의 자연로그 값 반환                  | LOG(10) => 2.30259 |
|     POWER(숫자, n)     | 숫자의 n 제곱값 계산                     | POWER(2, 3) => 8   |
|       SQRT(숫자)       | 숫자의 제곱근 값 계산(숫자는 양수)       | SQRT(9.0) => 3.0   |
|       SIGN(숫자)       | 숫자가 음수면 -1, 0이면 0, 양수면 1 반환 | SIGN(3.45) => 1    |

- ex 1 : 등급별 나이를 단위로 두 번째 자리에서 반올림한 값 계산

```SQL
SELECT 등급, ROUND(AVG(나이), 2) AS 'avg_age'
FROM 고객
GROUP BY 등급;
```

<img src="https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch07/ch07-62-round.PNG"  height="auto" />

#### 문자값 반환 함수

- s : 문자열
- c : 문자
- n : 정수
- k : 정수

|        종류         | 설명                                                                                | 예시                                                     |
| :-----------------: | :---------------------------------------------------------------------------------- | :------------------------------------------------------- |
|   CONCAT(s1, s2)    | 두 문자열 연결                                                                      | CONCAT('나는야', ' 천재 개발자') => '나는야 천재 개발자' |
|      LOWER(s)       | 대상 문자열 모두 소문자 변환                                                        | LOWER('MR.SCOTT') => 'mr.scott'                          |
|      UPPER(s)       | 대상 문자열 모두 대문자 변환                                                        | UPPER('mr.scott') => 'MR.SCOTT'                          |
|    LPAD(s, n, c)    | 대상 문자열 왼쪽부터 지정한 자리 수까지 지정 문자로 채움                            | LPAD('Page 1', 10, '\*') => '\*\*\*\*Page 1'             |
|    RPAD(s, n, c)    | 대상 문자열 오른쪽부터 지정한 자리 수까지 지정 문자로 채움                          | RPAD('AbC', 5, '$') => 'AbC$$'                           |
| REPLACE(s1, s2, s3) | 대상 문자열의 지정 문자를 원하는 문자로 변경                                        | REPLACE('JACK & JUE', 'J', 'BL') => 'BLACK & BLUE'       |
|   SUBSTR(s, n, k)   | 대상 문자열 지정 자리에서부터 지정 길이만큼 잘라 반환                               | SUBSTR('ABCDEFG', 3, 4) => 'CDEF'                        |
|   TRIM(c FROM s)    | 1. 대상 문자열 양쪽에서 지정된 문자 삭제<br>2. 문자열만 넣으면 기본값으로 공백 제거 | TRIM('=' FROM '==BROWNING==') => 'BROWNING'              |

#### REPLACE

- ex 1 : 고객 테이블의 직업 속성 중 학생을 대학생으로 변경

```SQL
SELECT 고객아이디, REPLACE(직업, '학생', '대학생')
FROM 고객;
```

<img src="https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch07/ch07-63-replace.PNG"  height="auto" />

#### 날짜 함수

|            종류             | 반환형  | 설명                                         | 예시                                                       |
| :-------------------------: | :-----: | :------------------------------------------- | :--------------------------------------------------------- |
| STR_TO_DATE(string, format) |  DATE   | 문자열(STRING) 데이터를 날짜형(DATE)로 반환  | STR_TO_DATE('2019-02-14', '%Y-%m-%d') <br>=> 2019-02-14    |
|  DATE_FORMAT(date, format)  | STRING  | 날짜형(DATE) 데이터를 문자열(VARCHAR)로 반환 | DATE_FORMAT('2019-02-14', '%Y-%m-%d') <br>=> '2019-02-14'  |
|   ADDDATE(date, interval)   |  DATE   | DATE형 날짜에서 INTERVAL 지정 시간만큼 덧셈  | ADDDATE('2019-02-14', INTERVAL 10 DAY) <br>=> '2019-02-24' |
|         DATE(date)          |  DATE   | DATE 형의 날짜 부분 반환                     | SELECT DATE('2003-12-31 01:02:03'); <br>=> 2003-12-31      |
|   DATEDIFF(date1, date2)    | INTEGER | DATE 형의 date1 - date2 날짜 차이 반환       | SELECT DATEDIFF('2019-02-14', '2019-02-04') <br>=> 10      |
|           SYSDATE           |  DATE   | DBMS 시스템 상 오늘 날짜 반환 함수           | SYSDATE() <br>=> 2025-04-27 21:48:02                       |

#### ADDDATE

- 주문일로부터 10일 후 입금이 들어온다면 각 주문의 입금일자를 구해라

```SQL
SELECT 주문번호, 주문고객, 주문일자,
      ADDDATE(주문일자, INTERVAL 10 DAY) AS '입금일자'
FROM 주문;
```

<img src="https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch07/ch07-64-adddate.PNG"  height="auto" />

## 6절. 뷰

### 뷰

- 기본 테이블을 들여다볼 수 있는 창의 역할
- 다른 테이블 기반 가상 테이블
  - 데이터 실제 저장 X
  - 논리적으로만 존재
- 일반 테이블과 동일한 방법 사용
- 뷰로 기본 테이블 내용 검색 가능
- 기본 테이블의 내용을 바꾸는 작업은 제한적
  - 기본 테이블 : 뷰 생성 시 기반이 되는 물리적 테이블
- 다른 뷰 기반의 새로운 뷰 생성 가능

#### CREATE VIEW : 뷰 생성

```SQL
CREATE VIEW 뷰_이름[(속성_리스트)]
AS SELECT 문
[WITH CHECK OPTION];
```

|      키워드       | 설명                                                                                                         |
| :---------------: | :----------------------------------------------------------------------------------------------------------- |
|    CREATE VIEW    | 1. 함께 생성할 뷰의 이름과 속성 이름 나열<br>2. 속성 리스트 생략 시 SELECT 절에 나열된 속성 이름 그대로 사용 |
|        AS         | 1. 기본 테이블에 대한 SELECT 문 제시<br>2. SELECT 문은 생성하려는 뷰의 정의를 표현하며 ORDER BY 사용 불가    |
| WITH CHECK OPTION | 뷰 삽입·수정 연산 시 SELECT 문에서 제시한 뷰의 정의 조건을 위반하면 수행되지 않도록 제약조건 지정            |

- ex 1 : 고객 테이블에 등급이 vip인 고객의 고객아이디, 고객이름, 나이, 등급으로 구성된 뷰를 우수고객이라는 이름으로 생성하고 모든 내용 검색

```SQL
/* 속성 리스트 나열 */
CREATE VIEW 우수고객(고객아이디, 고객이름, 나이, 등급)
AS SELECT 고객아이디, 고객이름, 나이, 등급
FROM 고객
WHERE 등급 = 'vip'
WITH CHECK OPTION;

/* 속성 리스트 생략 */
CREATE VIEW 우수고객
AS SELECT 고객아이디, 고객이름, 나이
FROM 고객
WHERE 등급 = 'vip'
WITH CHECK OPTION;

SELECT * FROM 우수고객;
```

<img src="https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch07/ch07-65-createview.PNG"  height="auto" />

- 뷰 생성 후 우수고객 뷰에 아래 행동 시 실행 거부 : WITH CHECK OPTION

  1. vip 등급이 아닌 고객 데이터 삽입
  2. 뷰의 정의 조건을 위반하는 수정·삭제 연산

- ex 2 : 제품 테이블에서 제조업체 별 제품 수로 구성된 뷰를 업체별제품수라는 이름으로 생성 후 내용 검색

```SQL
CREATE VIEW 업체별제품수(제조업체, 제품수)
AS SELECT 제조업체, COUNT(*) AS '제품수'
  FROM 제품
  GROUP BY 제조업체
WITH CHECK OPTION;

SELECT *
FROM 업체별제품수;
```

- 제품수 속성은 제품 테이블의 우너래 속성이 아닌 집계 함수로 새로 계산된 속성이므로 속성명의 명확한 제시 필수

<img src="https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch07/ch07-66-createview2.PNG"  height="auto" />

#### SELECT : 뷰 활용

- 일반 테이블과 같은 방법으로 데이터 검색 가능
- 뷰에 대한 SELECT 문이 내부적으로 기본 테이블에 대한 SELECT 문으로 변환 후 수행
- 검색 연산은 모든 뷰에 수행 가능

- ex 1 : 우수고객 뷰에서 나이가 20세 이상인 고객에 대한 모든 내용 검색

```SQL
SELECT *
FROM 우수고객
WHERE 나이 >= 20;
```

<img src="https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch07/ch07-65-createview.PNG"  height="auto" />

#### INSERT, UPDATE, DELETE : 뷰 활용

- 뷰에 대한 삽입·수정·삭제 연산 가능

  - 실제 기본 테이블에 수행
  - 결과적으로 기본 테이블 변경

- 뷰에 대한 삽입·수정·삭제 연산은 제한적 수행
  - 변경 가능 뷰 vs 변경 불가능 뷰

| 변경 불가능 뷰 특징                                                     |
| :---------------------------------------------------------------------- |
| 기본 테이블의 기본키를 구성하는 속성이 미포함된 뷰                      |
| 기본 테이블에서 NOT NULL로 지정된 속성이 미포함된 뷰                    |
| 기본 테이블에 있던 내용이 아닌 집계 함수로 새로 계산된 내용을 포함한 뷰 |
| DISTINCT 키워드를 포함해 정의한 뷰                                      |
| GROUP BY 절을 포함해 정의한 뷰                                          |
| 여러 테이블을 조인하여 정의한 뷰                                        |

- ex 1 : 제품1 뷰와 제품2 뷰의 비교

```SQL
CREATE VIEW 제품1
AS SELECT 제품번호, 재고량, 제조업체
FROM 제품
WITH CHECK OPTION;

SELECT *
FROM 제품1;
```

<img src="https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch07/ch07-67-product1.PNG"  height="auto" />

```SQL
CREATE VIEW 제품2
AS SELECT 제품명, 재고량, 제조업체
FROM 제품
WITH CHECK OPTION;

SELECT *
FROM 제품2;
```

<img src="https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch07/ch07-68-product2.PNG"  height="auto" />

- ex 1 - 1 : 제품번호가 p08, 재고량이 1000, 제조업체가 신선식품인 새로운 제품의 정보를 제품1 뷰에 삽입 후 모든 내용 검색

```SQL
INSERT
INTO 제품1
VALUES('p08', 1000, '신선식품');

SELECT *
FROM 제품1;
```

<img src="https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch07/ch07-69-product1-1.PNG"  height="auto" />

```SQL
SELECT *
FROM 제품;
```

<img src="https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch07/ch07-70-product1-2.PNG"  height="auto" />

- 제품1 뷰에 대한 삽입 연산은 실제로 기본 테이블인 제품 테이블에 수행
- 새로운 제품의 데이터는 제품 테이블에 삽입

- ex 1 - 2 : 제품 2 뷰에 대한 삽입 연산 실행

```SQL
INSERT
INTO 제품2
VALUES('시원냉면', 1000, '신선식품');
```

- 제품2 뷰에 대한 삽입 연산은 실패(오류 발생)
  - why ? 제품2 뷰는 제품 테이블의 기본키인 제품번호 속성을 미포함하기 때문
  - 새로운 튜플 삽입 시 제품번호 속성이 NULL이 되어 삽입 연산 실패

#### 뷰 장점

- 쉬운 질의문 작성

  - GROUP BY, 집계 함수, 조인 등을 통해 뷰를 미리 생성
  - 복잡한 SQL 문을 작성하지 않아도 SELECT, FROM 절로 원하는 데이터 검색 가능

- 데이터 보안 유지에 도움

  - 자신에게 제공된 뷰를 통해서만 데이터에 접근하도록 권한 설정 가능

- 데이터를 편하게 관리
  - 제공된 뷰와 관련 없는 다른 내용에 사용자가 신경 X

#### DROP VIEW : 뷰 삭제

```SQL
DROP VIEW 뷰_이름;
```

- 뷰를 삭제해도 기본 테이블은 영향 X

- 만약 삭제할 뷰를 참조하는 제약조건이 존재하는 경우

  - 뷰 삭제 미수행
  - 관련 제약조건 먼저 삭제 필수
    - ex) 삭제할 뷰를 통해 만들어진 다른 뷰가 존재하는 경우

- ex 1 : 우수고객 뷰 삭제

```SQL
DROP VIEW 우수고객;
```

## 7절. 삽입 SQL

### 삽입 SQL(ESQL : Embedded SQL)

- 프로그래밍 언어로 작성된 응용 프로그램 안에 삽입 후 사용하는 SQL문

### 주요 특징

- 프로그램 안에서 일반 명령문 위치 가능하면 어디든 삽입 가능
- 일반 명령문과 구별을 위해 삽입 SQL 문 앞에 EXEC SQL 삽입
- 프로그램에 선언된 일반 변수를 삽입 SQL 문에서 사용하면 이름 앞에 콜론(:)으로 구분

### 커서(Cursor)

- 수행 결과로 반환된 여러 행을 한 번에 하나씩 가리키는 포인터
- 여러 개의 행을 결과로 반환하는 SELECT 문 사용 시 필요

### 변수 선언 방법

- BEGIN DECLARE SECTION 과 END DECLARE SECTION 사이에 선언

### 커서가 필요 없는 삽입 SQL

| 종류                                |
| :---------------------------------- |
| CREATE TABLE 문                     |
| INSERT 문                           |
| DELETE 문                           |
| UPDATE 문                           |
| 결과로 행 하나만 반환하는 SELECT 문 |

### C 언어 삽입 SQL 문

```C
int main(){
  // 삽입 SQL 문은 "EXEC SQL"을 붙여 일반 명령문과 구분

  // 단계 1
  EXEC SQL BEGIN DECLARE SECTION;
    char p_no[4], p_name[21];
    int price;
  EXEC SQL END DECLARE SECTION;

  // 단계 2
  printf("제품번호를 입력하세요  : ");
  scanf("%s", p_no);

  // 단계 3
  EXEC SQL SELECT 제품명, 단가 INTO :p_name, :price
        FROM 제품
        WHERE 제품번호 = :p_no;

  // 단계 4
  printf("\n제품명 = %s", p_name);
  printf("\n단가 = %d", price);

  return 0;
}
```

|  단계  | 설명                                                                                                 | 자세히                                                                                                                                                                                      |
| :----: | :--------------------------------------------------------------------------------------------------- | :------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------ |
| 단계 1 | 삽입 SQL 문에서 사용할 변수 선언                                                                     | 1. 테이블 내에 대응되는 속성과 같은 타입 변수를 데이터 타입으로 선언<br>2. C에서는 문자열 끝을 표시하는 NULL 문자('\0')를 포함하도록 변수 선언 시 속성의 문자열 길이보다 한 개 더 길게 선언 |
| 단계 2 | 검색하고자 하는 제품의 제품번호를 사용자로부터 입력                                                  | .                                                                                                                                                                                           |
| 단계 3 | 제품 테이블에서 사용자가 입력한 제품번호에 해당하는 제품명과 단가를 검색하여 대응되는 각 변수에 저장 | 변수는 INTO 키워드 다음 차례로 나열                                                                                                                                                         |
| 단계 4 | 검색된 제품명과 단가를 화면에 출력                                                                   | .                                                                                                                                                                                           |

### 커서가 필요한 삽입 SQL

#### 커서 선언 삽입 SQL 문

- 커서를 사용하기 전 커서 이름과 커서가 필요한 SELECT 문 선언

```SQL
EXEC SQL DECLARE 커서_이름 CURSOR FOR SELECT 문;
```

- ex 1 : 제품 테이블에서 제품명과 단가를 모두 검색하는 SELECT 문을 위한 커서를 product_cursor라는 이름으로 선언

```SQL
EXEC SQL DECLARE product_cursor CURSOR FOR
          SELECT 제품명, 단가 FROM 제품;
```

#### 커서 연결 SELECT 문 실행

```SQL
EXEC SQL OPEN 커서_이름;
```

- ex 2 : product_cursor라는 이름의 커서에 연결된 SELECT 문 실행

```SQL
EXEC SQL OPEN product_cursor;
```

#### 커서 이동 삽입 SQL 문

- 커서 이둥 후 처리할 다음 행을 가리키도록 설정
- 커서가 가리키는 행에서 속성값을 가져와 변수에 저장
- 결과 테이블에는 여러 행이 존재
- FETCH 문의 다중 수행 필요
  - for, while 문의 반복문과 함께 사용

```SQL
EXEC SQL FETCH 커서_이름 INTO 변수_리스트;
```

- ex 1 : product_cursor 커서로 결과 테이블의 다음 행에 접근 후 제품명 속성값을 p_name 변수에 저장하고 단가 속성값을 price 변수에 저장

```SQL
EXEC SQL FETCH product_cursor INTO :p_name, :price;
```

#### 커서 사용 종료 삽입 SQL문

```SQL
EXEC SQL CLOSE 커서_이름;
```

- ex 1 : product_cursor 커서 미사용

```SQL
EXEC SQL CLOSE product_cursor;
```

### PHP + SQL

```PHP
$conn = mysqli_connect("127.0.0.1", "root", "1234", "test_db");

$select_query = "SELECT seq, name FROM test_table WHERE seq <= 4";
$result_set = mysqli_query($conn, $select_query);

while($row = mysqli_fetch_array($result_set)){
  print_r($row);
  echo '<br>';
}

mysqli_close($conn);

# 출력 결과

# Array([0] => 1 [seq] => 1 [1] => 홍길동 [name] => 홍길동)
# Array([0] => 2 [seq] => 2 [1] => 일지매 [name] => 일지매)
# Array([0] => 3 [seq] => 3 [1] => 임꺽정 [name] => 임꺽정)
# Array([0] => 4 [seq] => 4 [1] => 이순신 [name] => 이순신)
```

### Python + SQL

#### Classnet 서버 내 접속 후 pandas 형태 결과물 얻기

```python
import pymysql

con = pymysql.connect(host = 'localhost', user = 'student',
password = '12345678', db = 'employees',
charset = 'utf8', autocommit = True,
cursorclass = pymysql.cursors.DictCursor, port = 33060)
cur = con.cursor()

sql = "select * from dept_manager"
# dept_manager 테이블 전체 출력

cur.execute(sql)
rows = cur.fetchall()
con.close()
# DB와 연결 종료

print(rows)
```

#### Classnet server

```python
from sshtunnel import SSHTunnelForwarder
import pymysql

sql =
con = SSHTunnelForwarder(('classnet.mju.ac.kr', 1004),
ssh_username = 's학번',
ssh_password = '비밀번호',
remote_bind_address = ('127.0.0.1', 33060))

server.start()

mysqlcmd = pymysql.connect(user = 's학번',
port = server.local_bind_port,
passwd = '1234', host = '127.0.0.1', charset = 'utf8')

sqlcur = mysqlcmd.cursor()
sqlcur.execute("use DBs학번")
sqlcur.execute("select * from dept_manager")

result = sqlcur.fetchall()
for data in result:
  print(data)
sqlcur.close()
```
