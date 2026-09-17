# 프로시저(Procedure)

> 1절. 프로시저
>
> 2절. 저장 프로시저

## 1절. 프로시저

### 프로시저(Procedure)

- 프로그래밍 일반 용어
- 이름을 붙여 놓은 호출 가능한 일련의 처리 절차

### 함수와 프로시저

|구분|영문|반환값|목적|
|:---:|:---:|:---:|:---|
|함수|Function|O|값을 계산한 뒤 return|
|프로시저|Procedure|X|작업 수행(출력, 저장, 갱신 등)|

- 위 구분은 언어 설계 상의 전통적인 분류
- SQL Server 저장 프로시저는 OUTPUT 파라미터·RETURN·결과 집합으로 값 반환 가능

## 2절. 저장 프로시저

### 저장 프로시저(Stored Procedure)

- 대부분의 RDBMS가 제공하는 기능
    - 본 문서는 SQL Server 기준
- 쿼리문 집합
- DB 서버에 저장되어 DB 엔진이 실행
- 어떤 동작을 일괄 처리하는 용도
- 개발자가 짜놓은 **쿼리문**을 **메서드 형식**으로 관리

### 사용 이유

|이유|설명|
|:---:|:---|
|재사용|같은 조회 로직을 여러 프로그램이 공유|
|보안|- 원본 테이블에 접근 권한을 주지 않고 실행 권한만 존재<br>- 정해진 방식으로만 사용자의 데이터 접근 가능|
|변경 용이|쿼리가 변경될 때 프로시저만 수정 가능|
|성능|- 실행 계획이 캐시되어 재사용<br>- 긴 쿼리문 대신 프로시저명만 전송해 네트워크 부하 감소|

### 명명 규칙

|접두사|용도|
|:---:|:---|
|usp_|사용자 정의 프로시저(user stored procedure)|
|sp_|**생성 금지**<br>- 시스템 프로시저 전용 접두사<br>- master DB를 먼저 탐색해 성능 저하 및 이름 충돌 발생|

### 파라미터 방향

|구분|키워드|설명|
|:---:|:---:|:---|
|입력|(기본)|호출부 → 프로시저|
|출력|OUTPUT|프로시저 → 호출부, 호출 시에도 OUTPUT 명시|

### RETURN & OUTPUT

|구분|반환 타입|용도|
|:---:|:---:|:---|
|RETURN|INT 타입만|성공/실패 상태코드|
|OUTPUT|모든 타입|실제 값 전달|

### 테이블 정의 예제

```sql
CREATE TABLE TBL_NAME(
    SEQ         INT IDENTITY(1, 1) PRIMARY KEY,
    NAME_A      NVARCHAR(20),
    NAME_B      NVARCHAR(20),
    NAME_C      NVARCHAR(20),
    REG_DATE    DATETIME2(7)
);
```

### 프로시저 생성 구문

```sql
CREATE PROCEDURE [프로시저명] ([파라미터])
AS
BEGIN
    [쿼리문];
END
```

### 프로시저 생성 예제

```sql
CREATE PROCEDURE ALPHA_NAME (
    @NAME_A     NVARCHAR(20),
    @NAME_B     NVARCHAR(20),
    @NAME_C     NVARCHAR(20),
    @DATE       DATETIME2(7)    OUTPUT,
    @RESULT     INT             OUTPUT
)
AS
BEGIN
    -- 결과 적용 행의 개수 미표시 옵션
    SET NOCOUNT ON;
    -- 실행 시점 고정(INSERT 값 == OUTPUT 값)
    SET @DATE = SYSDATETIME();
    BEGIN TRY
        -- 트랜잭션
        BEGIN TRAN;
        INSERT INTO TBL_NAME (NAME_A, NAME_B, NAME_C, REG_DATE)
        VALUES (@NAME_A, @NAME_B, @NAME_C, @DATE);
        -- 커밋
        COMMIT TRAN;
        -- 성공 시 0
        SET @RESULT = 0;
    END TRY
    BEGIN CATCH
        -- 트랜잭션이 살아있는 경우 롤백
        IF XACT_STATE() <> 0
            ROLLBACK TRAN;
        -- 실패
        SET @RESULT = -1;
        SET @DATE = NULL;
    END CATCH
    SET NOCOUNT OFF;
END;
```

### 프로시저 호출 구문

```sql
EXEC [프로시저명] [파라미터];
```

### 프로시저 호출 예제

```sql
DECLARE @OUT_DATE       DATETIME2(7);
DECLARE @OUT_RESULT     INT;

EXEC ALPHA_NAME
    @NAME_A = N'방'
   , @NAME_B = N'윤'
   , @NAME_C = N'서'
   , @DATE   = @OUT_DATE   OUTPUT
   , @RESULT = @OUT_RESULT OUTPUT;
    
SELECT @OUT_DATE AS REG_DATE, @OUT_RESULT AS RESULT;
```

### 프로시저 삭제 구문

```sql
DROP PROCEDURE [프로시저명];
```

### 프로시저 삭제 예제

```sql
DROP PROCEDURE ALPHA_NAME;
```

### 프로시저 조회

```sql
-- 원본 정의 확인
sp_helptext [프로시저명];

-- 파라미터 및 속성 확인
sp_help [프로시저명];

-- 전체 프로시저 목록
SELECT name, create_date, modify_date
FROM sys.procedures
ORDER BY name;
```