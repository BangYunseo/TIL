# Chapter 11. 권한 부여(Autorization)

> 1절. 보안
>
> 2절. 권한 관리

## 1절. 보안

### 데이터베이스 보안

<img src="https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch11/ch11-01-Protection.PNG"  height="auto" />

#### 목표

- 조직에서 허가한 사용자만 데이터베이스에 접근하도록 통제 및 보안 유지

#### 1. 물리적 환경 보안

- 데이터베이스에 물리적 손실을 발생시키는 위험으로부터 보호
  - 자연 재해

#### 2. 권한 관리 보안

- 접근이 허락된 사용자만 권한 내에서 데이터베이스를 사용하도록 보호
  - 계정이 발급된 사용자 : 데이터베이스 접근 가능
  - 사용자별로 사용 범위 / 수행 가능한 작업 내용 제한

#### 3. 운영 관리 보안

- 접근이 허락된 사용자가 권한 내에서 데이터베이스를 사용하는 동안 데이터 무결성 유지
  - 제약조건 정의
  - 제약조건 위반 방지를 위한 통제

## 2절. 권한 관리

### 권한 관리 개념

<img src="https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch11/ch11-02-Access.PNG"  height="auto" />

#### 접근 제어(Access Control)

- 계정이 발급된 사용자가 로그인 성공한 경우 데이터베이스에 접근 허용
- 사용자 계정 관리는 데이터베이스 관리자 담당

#### 허용 권한

- 각 사용자는 허용된 권한 내에서만 데이터베이스 사용
- 로그인에 성공한 사용자도 데이터베이스 사용 범위와 수행 가능 작업 제한
  - 보안을 위한 데이터 단
    - 데이터베이스 전체 ~
    - 특정 테이블의 특정 행 or 열 위치의 특정 데이터 값

#### 객체 생성 사용자

- 데이터베이스의 모든 객체는 객체 생성 사용자만 권한 보유
- 데이터베이스의 객체 소유자는 필요에 따라 SQL로 다른 사용자에게 권한 부여 / 취소 가능

### 권한 관리 보안

<img src="https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch11/ch11-03-Autorization.PNG"  height="auto" />

### 객체 권한 부여 : GRANT

- 객체 소유자가 다른 사용자에게 객체 사용 권한을 부여
- GRANT로 부여받은 권한은 다른 사용자에게 부여 불가

```SQL
GRANT 권한 ON 객체 TO 사용자 [WITH GRANT OPTION];
```

| 부여 가능 권한 |                  비고                  |
| :------------: | :------------------------------------: |
|     INSERT     |                   .                    |
|     DELETE     |                   .                    |
|     UPDATE     | 테이블 일부 속성에 대한 권한 부여 가능 |
|     SELECT     | 테이블 일부 속성에 대한 권한 부여 가능 |
|   REFERENCES   |       외래키 제약 조건 정의 권한       |

- PUBLIC

  - 모든 사용자에게 권한을 똑같이 부여
  - 특정 사용자 지정 X
  - PUBLIC 키워드를 통한 권한 부여

- WITH GRANT OPTION
  - 사용자 자신이 부여받은 권한을 다른 사용자에게도 부여

#### 객체 권한 부여 : GRANT 예시

1. 고객 테이블에 대한 검색 권한을 사용자 Hong에게 부여하라.

```SQL
GRANT SELECT ON 고객 TO Hong;
```

2. 고객 테이블에 대한 삽입과 삭제 권한을 모든 사용자에게 부여하라.

```SQL
GRANT INSERT, DELETE ON 고객 TO PUBLIC;
```

3. 고객 테이블을 구성하는 속성 중 등급과 적립금 속성의 수정 권한을 사용자 Park 에게 부여하라.

```SQL
GRANT UPDATE(등급, 적립금) ON 고객 TO Park;
```

4. 고객 테이블에 대한 검색 권한을 WITH GRANT OPTION을 포함해 사용자 Lee 에게 부여하라.

```SQL
GRANT SELECT ON 고객 TO Lee WITH GRANT OPTION;
```

### 객체 권한 취소 : REVOKE

- 객체 소우자가 다른 사용자에게 부여한 객체의 사용 권한 취소

```SQL
REVOKE 권한 ON 객체 FROM 사용자 CASCADE|RESTRICT;


```

| 옵션 종류 | A->B, B->C에게 같은 권한을 부여한 경우                                |
| :-------: | :-------------------------------------------------------------------- |
|  CASCADE  | 권한을 취소할 사용자 A가 B와 C가 부여받은 권한도 연쇄적으로 함께 취소 |
| RESTRICT  | 권한을 취소할 사용자 A가 C가 부여받은 권한은 취소 X                   |

#### 객체 권한 취소 : REVOKE 예시

1. 사용자 "Kim"이 "Hong"에게 부여한 고객 테이블에 대한 검색 권한 취소 시 "Park"에게 부여된 검색 권한은 어떻게 처리되는가?

<img src="https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch11/ch11-04-Q1.PNG"  height="auto" />

> CASCADE : Hong, Park의 사용자 권한 모두 취소  
> RESTRICT : Hong이 다른 사용자에게 권한을 부여하지 않았을 경우에만 취소  
> => 옵션 선택 가능

2. 위의 그림과 같이 권한이 부여된 상황에서 Kim이 Hong에게 부여한 고객 테이블에 대한 검색 권한을 취소하고 Hong이 다른 사용자에게 부여한 고객 테이블에 대한 검색 권한도 함께 취소하라.

```SQL
REVOKE SELECT ON 고객 FROM Hong CASCADE;
```

3. 위의 그림과 같이 권한이 부여된 상황에서 Hong이 다른 사용자에게 권한을 부여한 적이 없는 경우에만 Kim이 Hong에게 부여한 고객 테이블에 대한 검색 권한을 취소하라.

```SQL
REVOKE SELECT ON 고객 FROM Hong RESTRICT;
```

### 시스템 권한 부여 : GRANT

- 시스템 권한 : 데이터베이스 관리와 관련 작업에 대한 권한
  - 데이터베이스 관리자가 부여
  - 객체 지정할 필요 X

#### 시스템 권한 부여 : GRANT 예시

1. 테이블을 생성할 수 있는 시스템 권한을 사용자 Song에게 부여하라.

```SQL
GRANT CREATE TABLE TO Song;
```

2. 뷰를 생성할 수 있는 시스템 권한을 사용자 Shin에게 부여하라.

```SQL
GRANT CREATE VIEW TO Shin;
```

### 시스템 권한 취소 : REVOKE

- 데이터베이스 관리자가 다른 사용자에게 부여한 시스템 권한 취소
- 특정 객체에 대한 취소가 아니므로 객체를 지정할 필요 X

#### 시스템 권한 취소 : REVOKE 예시

1. Hong에게 부여한 테이블 생성 권한을 취소하라.

```SQL
REVOKE CREATE TABLE FROM Hong;
```

### 권한 목록

- 권한 부여에 관한 내용 기록

  - 사용자들에게 어떤 권한을 부여했는가?
  - WITH GRANT OPTION을 포함해 권한을 부여했는가?

- 예시

| 사용자 | 고객 테이블 권한                            |
| :----: | :------------------------------------------ |
|  Kim   | 소유자                                      |
|  Hong  | INSERT / DELETE / SELECT                    |
|  Park  | INSERT / DELETE / UPDATE(등급, 적립금)      |
|  Lee   | INSERT / DELETE / SELECT(WITH GRANT OPTION) |

### 역할(Role)

- 여러 권한을 그룹으로 묶은 것

### 역할 필요성

- 여러 사용자에게 동일한 권한들을 부여 / 취소하는 작업을 신속하고 편리하게 실행
  - 사용자에게 부여하고 싶은 여러 권한을 역할에 미리 삽입
  - 필요할 때 역할 부여
  - 여러 권한을 한 번에 부여 가능
  - 사용자에게 부여한 역할 취소 시 한 번에 여러 권한 취소 가능
- 쉬운 권한 관리
  - 역할에 변화가 생길 경우 해당 역할을 부여받은 모든 사용자에게 변화가 그대로 전달
    - 새로운 권한 추가
    - 기존 권한 취소

### 역할 필요성 예시

<img src="https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch11/ch11-05-Role.PNG"  height="auto" />

- 사용자 "Kim"이 자신의 고객 테이블에 대한 검색, 삽입, 삭제 권한을 "Hong", "Park", "Lee"에게 모두 부여하려고 하는 경우
  - 번거로운 작업 발생
  - 역할을 통한 편리한 작업 필요

### 역할 생성 : CREATE ROLE

- 새로운 역할 생성은 데이터베이스 관리자 담당

```SQL
CREATE ROLE 역할이름;
```

### 역할 생성 : CREATE ROLE 예시

1. role_1이라는 이름의 역할을 생성하라.

```SQL
CREATE ROLE role_1;
```

### 역할 권한 추가 : GRANT

- 객체와 관련된 권한을 역할에 추가하는 작업은 객체 소유자 담당

```SQL
GRANT 권한 ON 객체 TO 역할이름;
```

#### 역할 권한 추가 : GRANT 예시

1. 고객 테이블에 대한 검색, 삽입, 삭제 권한을 앞의 \[역할 생성 : CREATE ROLE 예시\] 에서 생성한 role_1 역할에 넣어라.

```SQL
GRANT SELECT, INSERT, DELETE ON 고객 TO role_1;
```

### 역할 권한 부여 : GRANT

- 역할을 사용자에게 부여하는 것은 데이터베이스 관리자 담당

```SQL
GRANT 역할이름 TO 사용자;
```

#### 역할 권한 부여 : GRANT 예시

1. 고객 테이블에 대한 검색, 삽입, 삭제 권한을 포함하는 role_1 역할을 사용자 Hong에게 부여하라.

```SQL
GRANT role_1 TO Hong;
```

### 역할 취소 : REVOKE

- 사용자에게 부여한 역할 취소는 데이터베이스 관리자 담당

```SQL
REVOKE 역할이름 FROM 사용자;
```

#### 역할 취소 : REVOKE 예시

1. 사용자 Hong에게 부여한 role_1 역할을 취소하라.

```SQL
REVOKE role_1 FROM Hong;
```

### 역할 제거 : DROP ROLE

- 제거된 역할을 부여받은 모든 사용자의 권한 모두 취소
- 역할 제거는 데이터베이스 관리자 담당

```SQL
DROP ROLE 역할이름;
```

#### 역할 제거 : DROP ROLE 예시

1. role_1 역할을 제거하라.

```SQL
DROP ROLE role_1;
```

### 역할 사용 예시

<img src="https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch11/ch11-06-Role2.PNG"  height="auto" />
