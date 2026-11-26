---
title: "MS-SQL (T-SQL) vs Oracle (PL/SQL)"
date: 2026-10-28 11:33:12 +0900
categories: [DataBase]
---

## 1절. 기본 차이

### 선제 확인

| 항목 | MSSQL | Oracle |
|---|---|---|
| 빈 문자열 | `''`와 NULL 구분 | `''` = NULL |
| NULL과 문자열 연결 | `'a' + NULL` = NULL | `'a' \|\| NULL` = `'a'` |
| ORDER BY의 NULL | 가장 작음 (ASC 시 먼저) | 가장 큼 (ASC 시 나중), `NULLS FIRST/LAST` 지원 |
| 정수 나눗셈 | `5/2` = 2<br>`5/2.0` = 2.5 | `5/2` = 2.5 |
| 오토커밋 | 기본 ON | 기본 OFF (명시적 COMMIT) |
| DDL 트랜잭션 | 롤백 가능 | 실행 즉시 자동 커밋 |
| 대소문자 비교 | 콜레이션 따라 보통 구분 안 함 | 기본 구분함 |
| 후행 공백 비교 | `'a' = 'a '` TRUE | VARCHAR2는 FALSE, CHAR는 TRUE |
| 식별자 | `[name]`, 대소문자 구분 안 함 | `"name"`, 따옴표 없으면 대문자로 저장 |
| 날짜 타입 | DATE는 날짜만, 시간은 DATETIME | DATE에 시분초 포함 |

### 기본 문법

| 기능 | MSSQL | Oracle |
|---|---|---|
| 행 제한 | `SELECT TOP 10 *` | `FETCH FIRST 10 ROWS ONLY` (12c+), `WHERE ROWNUM <= 10` |
| 페이징 | `ORDER BY ... OFFSET n ROWS FETCH NEXT m ROWS ONLY` | 동일 (12c+), 이전 버전은 ROWNUM 서브쿼리 |
| 더미 테이블 | `SELECT 1` | `SELECT 1 FROM DUAL` (23c부터 생략 가능) |
| 문자열 연결 | `+`, `CONCAT` | `\|\|`, `CONCAT` (인자 2개만) |
| 테이블 별칭 | `FROM t AS a` 가능 | `FROM t a` (테이블 별칭에 AS 불가) |
| 파생 테이블 별칭 | 필수 | 불필요 |
| 컬럼 별칭 | `AS name`, `AS [name]` | `AS "name"` (공백/대소문자 필요 시 따옴표) |
| 집합 연산 | `EXCEPT` | `MINUS` |
| 외부 조인 | `LEFT/RIGHT JOIN` | `LEFT/RIGHT JOIN`, 구형 `(+)` |
| LATERAL | `CROSS/OUTER APPLY` | `CROSS/OUTER APPLY`, `LATERAL` (12c+) |
| IN 리스트 | 개수 제한 사실상 없음 | 1000개 초과 불가 |
| LIKE 패턴 | `[abc]`, `[^a]` 문자 클래스 지원 | `%`, `_`만 지원 (정규식은 `REGEXP_LIKE`) |
| 유니코드 리터럴 | `N'한글'` | 일반 `'한글'` |
| 문자열 이스케이프 | `''` | `''` (LIKE는 `ESCAPE '\'` 명시) |
| 구문 종결 | `;` 선택 | `;` 필요 (PL/SQL 블록은 `/`) |
| 암묵적 형변환 | 우선순위 기반, 엄격한 편 | 관대함 (인덱스 미사용 주의) |

### 함수 대응표

| 기능 | MSSQL | Oracle |
|---|---|---|
| NULL 치환 | `ISNULL(a,b)` | `NVL(a,b)`, `NVL2(a,b,c)` |
| 조건 분기 | `IIF(c,a,b)`, `CASE` | `DECODE`, `CASE` |
| 현재 시각 | `GETDATE()`, `SYSDATETIME()` | `SYSDATE`, `SYSTIMESTAMP` |
| 날짜 더하기 | `DATEADD(DAY,1,d)` | `d + 1` |
| 월 더하기 | `DATEADD(MONTH,1,d)` | `ADD_MONTHS(d,1)` |
| 날짜 차이 | `DATEDIFF(DAY,a,b)` | `b - a` (일 단위 숫자) |
| 월 차이 | `DATEDIFF(MONTH,a,b)` | `MONTHS_BETWEEN(b,a)` |
| 월말 | `EOMONTH(d)` | `LAST_DAY(d)` |
| 날짜 절삭 | `CAST(d AS DATE)` | `TRUNC(d)` |
| 날짜 → 문자 | `FORMAT(d,'yyyy-MM-dd')`, `CONVERT(VARCHAR,d,23)` | `TO_CHAR(d,'YYYY-MM-DD')` |
| 문자 → 날짜 | `CAST('2026-10-28' AS DATE)` | `TO_DATE('2026-10-28','YYYY-MM-DD')` |
| 날짜 리터럴 | `'2026-10-28'` | `DATE '2026-10-28'` |
| 숫자 변환 | `CAST(x AS INT)` | `TO_NUMBER(x)` |
| 문자열 길이 | `LEN()` (후행 공백 제외) | `LENGTH()` |
| 부분 문자열 | `SUBSTRING(s,start,len)` | `SUBSTR(s,start,len)` (음수 start 허용) |
| 문자열 찾기 | `CHARINDEX(찾을값, 대상)` | `INSTR(대상, 찾을값)` (인자 순서 반대) |
| 문자열 반복 | `REPLICATE` | `RPAD`, `LPAD` 활용 |
| 문자열 집계 | `STRING_AGG(c, ',')` | `LISTAGG(c, ',') WITHIN GROUP (ORDER BY ...)` |
| 정규식 | `PATINDEX`, `LIKE`만 | `REGEXP_LIKE/SUBSTR/REPLACE/INSTR` |
| 절삭 | `ROUND(x,n,1)` | `TRUNC(x,n)` |
| 난수 | `RAND()` | `DBMS_RANDOM.VALUE` |
| UUID | `NEWID()` | `SYS_GUID()` |
| 순번 | `ROW_NUMBER() OVER()` | 동일 + `ROWNUM` |
| 날짜 요소 추출 | `DATEPART`, `YEAR()`, `MONTH()` | `EXTRACT(YEAR FROM d)`, `TO_CHAR(d,'MM')` |

## 2절. 조작 · 조회
### DML 차이

| 기능 | MSSQL | Oracle |
|---|---|---|
| 다중 행 INSERT | `VALUES (..),(..)` | `INSERT ALL INTO ... SELECT FROM DUAL`, 23c는 VALUES 다중 지원 |
| 자동 증가 키 | `IDENTITY(1,1)` | `SEQUENCE.NEXTVAL`, 12c+ `GENERATED AS IDENTITY` |
| 방금 넣은 ID | `SCOPE_IDENTITY()`, `OUTPUT inserted.id` | `INSERT ... RETURNING id INTO :v` |
| UPDATE 조인 | `UPDATE a SET ... FROM a JOIN b ON ...` | 상관 서브쿼리 또는 `MERGE` |
| DELETE 조인 | `DELETE a FROM a JOIN b ON ...` | `DELETE FROM a WHERE EXISTS (...)` |
| SELECT INTO | 새 테이블 생성 | 변수 대입 (테이블 복제는 `CREATE TABLE AS SELECT`) |
| 테이블 복제 | `SELECT * INTO new FROM old` | `CREATE TABLE new AS SELECT * FROM old` |
| MERGE | 끝에 `;` 필수 | `WHEN MATCHED THEN UPDATE ... DELETE WHERE ...` 지원 |
| 락 힌트 | `WITH (NOLOCK)` | 불필요 (읽기가 쓰기를 막지 않음) |
| 잠금 조회 | `WITH (UPDLOCK)` | `SELECT ... FOR UPDATE [NOWAIT / SKIP LOCKED]` |
| 전체 삭제 | `TRUNCATE` (롤백 가능) | `TRUNCATE` (자동 커밋, 롤백 불가) |

### 조회 문법 차이

| 기능 | MSSQL | Oracle |
|---|---|---|
| 계층 쿼리 | 재귀 CTE | `START WITH ... CONNECT BY PRIOR ...`, `LEVEL`, `SYS_CONNECT_BY_PATH`, 재귀 CTE도 가능 |
| 재귀 CTE | `WITH cte AS (...)` | `WITH cte (컬럼목록) AS (...)` (컬럼 목록 필요) |
| PIVOT | 지원 | 지원 (11g+), `IN` 절에 값 하드코딩 |
| 분석함수 | `LAG/LEAD/SUM OVER` | 동일 + `KEEP (DENSE_RANK FIRST)`, `RATIO_TO_REPORT` |
| 윈도우 | `ROWS BETWEEN` | `ROWS/RANGE BETWEEN` |
| GROUP BY | 별칭 불가 | 별칭 불가 |
| 순번 부여 | `ROW_NUMBER()` | `ROW_NUMBER()`, `ROWNUM` (ORDER BY 전에 부여되므로 주의) |
| 상위 N건 (동률 포함) | `TOP N WITH TIES` | `FETCH FIRST N ROWS WITH TIES` |
| 테이블 변수 | `DECLARE @t TABLE (...)` | 컬렉션 타입, GTT |
| 임시 테이블 | `#temp` (세션 종료 시 삭제) | `GLOBAL TEMPORARY TABLE` (구조는 영구, 데이터만 세션/트랜잭션 단위) |

## 3절. 정의

### DDL 차이

| 기능 | MSSQL | Oracle |
|---|---|---|
| 컬럼 추가 | `ALTER TABLE t ADD col INT` | `ALTER TABLE t ADD (col NUMBER)` |
| 컬럼 수정 | `ALTER COLUMN col INT` | `MODIFY (col NUMBER)` |
| 컬럼 삭제 | `DROP COLUMN col` | `DROP COLUMN col` |
| 이름 변경 | `sp_rename` | `ALTER TABLE t RENAME COLUMN a TO b` |
| 존재 시 삭제 | `DROP TABLE IF EXISTS t` | 23c부터 `IF EXISTS`, 이전은 예외 처리 |
| 코멘트 | Extended Property | `COMMENT ON COLUMN t.c IS '...'` |
| 메타 조회 | `INFORMATION_SCHEMA`, `sys.tables`, `sys.columns` | `USER_TABLES`, `USER_TAB_COLUMNS`, `ALL_*`, `DBA_*` |
| 데이터 타입 | `VARCHAR`, `INT`, `DATETIME2`, `BIT`, `VARCHAR(MAX)` | `VARCHAR2`, `NUMBER`, `TIMESTAMP`, `NUMBER(1)`/`CHAR(1)`, `CLOB` |
| 문자 길이 단위 | `VARCHAR(n)` = 바이트 | `VARCHAR2(n BYTE/CHAR)` 선택 |
| 기본값 | `CONSTRAINT DF_x DEFAULT ...` | `DEFAULT ...` 절 |
| 인덱스 | Clustered / Non-clustered, `INCLUDE` 컬럼 | B-tree, Bitmap, Function-based, IOT |

## 4절. 프로시저/함수
### T-SQL vs PL/SQL

| 항목 | MSSQL (T-SQL) | Oracle (PL/SQL) |
|---|---|---|
| 변수 선언 | `DECLARE @v INT = 0;` | `DECLARE v NUMBER := 0;` |
| 대입 | `SET @v = 1;`, `SELECT @v = col` | `v := 1;`, `SELECT col INTO v` |
| 블록 구조 | `BEGIN ... END` | `DECLARE ... BEGIN ... EXCEPTION ... END;` |
| 조건문 | `IF ... BEGIN ... END ELSE ...` | `IF ... THEN ... ELSIF ... ELSE ... END IF;` |
| 반복문 | `WHILE ... BEGIN ... END` | `LOOP ... EXIT WHEN ... END LOOP;`, `FOR i IN 1..10 LOOP` |
| 결과셋 반환 | `SELECT`만 쓰면 클라이언트로 반환 | `SYS_REFCURSOR` OUT 파라미터 필수 |
| SELECT 단독 사용 | 가능 | 불가 (`INTO` 또는 커서 필요) |
| 단건 조회 예외 | 없으면 변수 유지 | `NO_DATA_FOUND`, `TOO_MANY_ROWS` 예외 발생 |
| 예외 처리 | `TRY ... CATCH`, `THROW`, `RAISERROR` | `EXCEPTION WHEN ... THEN`, `RAISE_APPLICATION_ERROR(-20001, 'msg')` |
| 에러 정보 | `ERROR_MESSAGE()`, `ERROR_NUMBER()` | `SQLERRM`, `SQLCODE` |
| 커서 | `DECLARE c CURSOR FOR ...; OPEN; FETCH; CLOSE; DEALLOCATE` | `CURSOR c IS ...; FOR r IN c LOOP ... END LOOP;` |
| 동적 SQL | `EXEC sp_executesql @sql, N'@p INT', @p=1` | `EXECUTE IMMEDIATE sql USING v` |
| 출력 파라미터 | `@p INT OUTPUT` | `p OUT NUMBER` (IN / OUT / IN OUT) |
| 프로시저 호출 | `EXEC proc @a=1` | `BEGIN proc(a => 1); END;` 또는 `CALL proc(1)` |
| 패키지 | 없음 | `PACKAGE` / `PACKAGE BODY` |
| 행 처리 건수 | `@@ROWCOUNT` | `SQL%ROWCOUNT` |
| 디버그 출력 | `PRINT 'msg'` | `DBMS_OUTPUT.PUT_LINE('msg')` |
| 트리거 | `AFTER`, `INSTEAD OF`, `inserted/deleted` 테이블 | `BEFORE/AFTER`, `FOR EACH ROW`, `:NEW/:OLD` |
| 트랜잭션 제어 | `BEGIN TRAN / COMMIT / ROLLBACK` | `COMMIT / ROLLBACK / SAVEPOINT` (BEGIN TRAN 없음) |
| 자율 트랜잭션 | 없음 | `PRAGMA AUTONOMOUS_TRANSACTION` |

## 5절. 튜닝·마이그레이션

### 튜닝/실행계획

| 항목 | MSSQL | Oracle |
|---|---|---|
| 실행계획 확인 | SSMS 실행계획, `SET SHOWPLAN_ALL ON` | `EXPLAIN PLAN FOR ...` + `DBMS_XPLAN.DISPLAY` |
| 힌트 문법 | `OPTION (RECOMPILE)`, `WITH (INDEX(ix))` | `/*+ INDEX(t ix) USE_NL(a b) */` |
| 통계 갱신 | `UPDATE STATISTICS` | `DBMS_STATS.GATHER_TABLE_STATS` |
| 바인드 변수 | `@p` | `:p` (바인드 변수로 하드 파싱 방지) |
| 파라미터 스니핑 | 이슈 잦음 (`OPTIMIZE FOR`) | 바인드 피킹, 적응형 커서 공유 |

### 마이그레이션 변환 체크리스트

- [ ] `TOP n` → `FETCH FIRST n ROWS ONLY`
- [ ] `ISNULL` → `NVL`, `GETDATE()` → `SYSDATE`
- [ ] `+` 문자열 연결 → `||`
- [ ] `LEN`→`LENGTH`, `SUBSTRING`→`SUBSTR`, `CHARINDEX`→`INSTR` (인자 순서 반대)
- [ ] `DATEADD`/`DATEDIFF` → 날짜 산술, `ADD_MONTHS`, `MONTHS_BETWEEN`
- [ ] `FORMAT`/`CONVERT` → `TO_CHAR`/`TO_DATE`
- [ ] `UPDATE ... FROM JOIN` → `MERGE` 또는 서브쿼리
- [ ] `DELETE ... FROM JOIN` → `WHERE EXISTS`
- [ ] `SELECT INTO` 테이블 생성 → `CREATE TABLE AS SELECT`
- [ ] `IDENTITY` → `SEQUENCE` 또는 `GENERATED AS IDENTITY`
- [ ] `#temp`, `@table` → GTT 또는 컬렉션
- [ ] `WITH (NOLOCK)` 제거
- [ ] `@var` → 변수명 (접두사 제거), `SET @v =` → `v :=`
- [ ] 프로시저의 단독 `SELECT` → `SYS_REFCURSOR` OUT 파라미터
- [ ] `TRY/CATCH` → `EXCEPTION WHEN`, `RAISERROR/THROW` → `RAISE_APPLICATION_ERROR`
- [ ] `sp_executesql` → `EXECUTE IMMEDIATE`
- [ ] `PRINT` → `DBMS_OUTPUT.PUT_LINE`
- [ ] `''` 비교/저장 로직 점검 (Oracle은 NULL)
- [ ] ORDER BY NULL 정렬 순서 점검
- [ ] 정수 나눗셈 결과 변화 점검
- [ ] 파생 테이블 별칭 / 테이블 별칭 `AS` 제거
- [ ] 한글 컬럼 길이 (`VARCHAR2(n CHAR)` 검토)
- [ ] 대소문자 비교 로직 (`UPPER()` 또는 콜레이션 차이)
- [ ] IN 리스트 1000개 제한
- [ ] 트랜잭션 경계 (오토커밋 OFF, DDL 자동 커밋)