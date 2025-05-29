# Chapter 10. 회복과 병행 제어(Recovery & Concurrency Control)

> 1절. 트랜잭션
>
> 2절. 장애와 회복
>
> 3절. 병행 제어

## 1절. 트랜잭션

### 트랜잭션(Transaction)

- 논리적 작업 단위
- 하나의 작업을 수행하는데 필요한 데이터베이스 연산들의 집합
- 작업 수행에 필요한 SQL 문들의 집합
  - 데이터베이스를 변경의 INSERT, DELETE, UPDATE 문 실행 관리
- 장애 발생 시 복구 작업이나 병행 제어 작업을 위한 중요한 단위로 사용
- 데이터베이스의 무결성과 일관성을 보장하기 위해 작업 수행에 필요한 연산들을 하나의 트랜잭션으로 제대로 정의 및 관리

### 트랜잭션 예시 : (1)

<img src="https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch10/ch10-01-TSex.PNG"  height="auto" />

- 처리 순서는 중요 X
- 두 UPDATE 문이 모두 정상적인 실행 필요

### 트랜잭션 예시 : (2)

<img src="https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch10/ch10-02-TSex2.PNG"  height="auto" />

- 상품 주문 트랜잭션 수행 조건
  - INSERT 문과 UPDATEE 문의 정상적 실행

### 트랜잭션 특성(ACID)

<img src="https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch10/ch10-03-ACID.PNG"  height="auto" />

#### 원자성(Atomicity)

- ALL OR NOTHING
- 트랜잭션 연산들이 모두 정상적으로 실행 or 하나도 실행 X
- 트랜잭션 수행 중 장애 발생
  - 지금까지 실행한 연산 모두 취소
  - 데이터베이스를 트랜잭션 작업 전 상태로 되돌림
- 장애 발생 시 회복 기능 필요

#### 일관성(Consistency)

- 트랜잭션이 성공적으로 수행된 후 데이터베이스는 일관된 상태를 유지
- 모순된 데이터 존재 불가

#### 격리성(Isolation)

- 수행 중인 트랜잭션의 완료 전까지 다른 트랜잭션들이 중간 연산 결과에 접근 불가
- 여러 트랜잭션 동시 수행 시 제어 기능 필요

#### 지속성(Durability)

- 트랜잭션이 성공적으로 완료된 후 데이터베이스에 수행한 결과는 영구적
- 장애 발생 시 회복 기능 필요

### ACID & DBMS 기능

<img src="https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch10/ch10-04-ACIDDBMS.PNG"  height="auto" />

### 트랜잭션 연산

|   종류   | 설명                              |
| :------: | :-------------------------------- |
|  commit  | 트랜잭션의 성공적 수행(작업 완료) |
| rollback | 트랜잭션 수행 실패(작업 취소)     |

#### commit

- 트랜잭션 수행의 성공
- 트랜잭션 수행 결과가 데이터베이스에 반영되고 일관된 상태를 지속적 유지

#### rollback

- 트랜잭션 수행의 실패
- 트랜잭션이 지금까지 실행한 연산 결과 취소 및 데이터베이스가 트랜잭션 수행 전의 일관된 상태로 돌아감

### 트랜잭션 상태

<img src="https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch10/ch10-05-TSstate.PNG"  height="auto" />

#### 활동(Active) 상태

- 트랜잭션이 수행되기 시작해서 현재 수행중인 상태

#### 부분 완료(Partially Committed) 상태

- 트랜잭션의 마지막 연산이 실행을 끝낸 직후 상태

#### 완료(Committed) 상태

- 트랜잭션이 성공적으로 완료되어 commit 연산을 실행한 상태
- 트랜잭션이 수행한 최종 결과를 데이터베이스에 반영
- 데이터베이스가 새로운 일관된 상태가 되며 트랜잭션 종료

#### 실패(Failed) 상태

- 장애가 발생해 트랜잭션 수행이 중단된 상태

#### 철회(Aborted) 상태

- 트랜잭션 수행 실패로 rollback 연산이 실행된 상태
- 지금까지 실행한 트랜잭션 연산 모두 취소
- 트랜잭션 수행 전의 데이터베이스 상태로 되돌린 후 트랜잭션 종료
- 종료된 트랜잭션은 상황에 따라 재수행되거나 폐기

### 트랜잭션 SQL 예시

<img src="https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch10/ch10-06-TSSQLex1.PNG"  height="auto" />

#### 수행 과정

<img src="https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch10/ch10-07-TSSQLex2.PNG"  height="auto" />

1. A 계좌(박지성) 값을 데이터베이스에서 주기억장치 버퍼로 읽음
2. B 계좌(김연아) 값을 데이터베이스에서 주기억장치 버퍼로 읽음
3. A 계좌(박지성)에서 10,000원 인출한 값 저장
4. B 계좌(김연아)에 10,000원 입금한 값 저장
5. A 계좌(박지성)의 값을 주기억장치 버퍼에서 데이터베이스에 기록
6. B 계좌(김연아)의 값을 주기억장치 버퍼에서 데이터베이스에 기록

#### 종료(COMMIT) 알림

- DBMS는 사용자에게 빠른 응답성 보장을 위해 방법 1 사용
- 방법 1 : 1 -> 2 -> 3 -> 4 -> COMMIT -> 5 -> 6
- 방법 2 : 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> COMMIT

### 트랜잭션 제어 명령어(TCL : Transaction Control Language)

| 표준 명령어       | MySQL                         | 설명                                         |
| :---------------- | :---------------------------- | -------------------------------------------- |
| START TRANSACTION | SET TRANSACTION NAME \<이름\> | 트랜잭션 시작                                |
| COMMIT            | COMMIT                        | 트랜잭션 종료                                |
| ROLLBACK          | ROLLBACK {TO \<savepoint\>}   | 트랜잭션 전체 혹은 \<savepoint\> 까지 무효화 |
| SAVEPOINT         | SAVEPOINT \<savepoint\>       | \<savepoint\> 생성                           |

## 2절. 장애와 회복

### 장애(Failure)

- 시스템이 제대로 동작하지 않는 상태

<img src="https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch10/ch10-08-Failure.PNG"  height="auto" />

### 데이터베이스 저장 장치 종류

<img src="https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch10/ch10-09-Storage.PNG"  height="auto" />

### 데이터 이동 연산

<img src="https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch10/ch10-10-iorw.PNG"  height="auto" />

#### 디스크 & 메인 메모리 간 데이터 이동 연산

<img src="https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch10/ch10-11-io.PNG"  height="auto" />

- input / output

  - input(X)

    - 디스크 블록에 저장된 데이터 X를 메인 메모리 버퍼 블록으로 이동시키는 연산

  - output(X)

    - 메인 메모리 버퍼 블록에 저장된 데이터 X를 디스크 블록으로 이동시키는 연산

- 블록(block) 단위 수행

  - 디스크 블록 : 디스크에 있는 블록
  - 버퍼 블록 : 메인 메모리에 있는 블록

- 필요성
  - 데이터베이스는 비휘발성 저장 장치인 디스크에 상주
  - 데이터를 디스크에서 메인 메모리로 가져와 처리 후 결과를 디스크로 보내는 작업 필요

#### 메인 메모리 & 프로그램 변수 간 데이터 이동 연산

<img src="https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch10/ch10-12-rw.PNG"  height="auto" />

- read / write

  - read(X)

    - 메인 메모리 버퍼 블록에 저장된 데이터 X를 프로그램 변수로 읽어오는 연산

  - write(X)

    - 프로그램 변수 값을 메인 메모리 버퍼 블록에 저장된 데이터 X에 기록하는 연산

- 필요성
  - 메인 메모리 버퍼 블록의 데이터를 프로그램의 변수로 가져오고 데이터 처리 결과를 저장한 변수 값을 메인 메모리 버퍼 블록으로 옮기는 작업 필요

### 회복(Recovery)

- 장애 발생 시 데이터베이스를 장애가 발생하기 전 일관된 상태로 복구
- 트랜잭션 특성 보장, 데이터베이스를 일관된 상태로 유지하는 필수 기능
- 회복 관리자(Recovery Manager) 담당
  - 장애 발생 탐지
  - 장애 탐지 시 데이터베이스 복구 기능 제공

### 데이터베이스 복사본 생성 방법

- 회복 핵심 원리 : 데이터 중복

|      종류      | 설명                                                                                           |
| :------------: | :--------------------------------------------------------------------------------------------- |
| 덤프<br>(dump) | 데이터베이스 전체를 다른 저장 장치에 주기적으로 복사                                           |
| 로그<br>(log)  | 데이터베이스에서 변경 연산 실행 시 데이터를 변경하기 이전 값과 변경 이후 값을 별도 파일에 기록 |

### 데이터 회복 기본 연산

|       종류       | 설명                                                                                                                                                                                                         |
| :--------------: | :----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| 재실행<br>(redo) | 가장 최근 저장한 데이터베이스 복사본을 가져온 후 로그를 통해 복사본이 만들어진 이후 실행된 모든 변경 연산을 재실행하여 장애가 발생하기 직전의 데이터베이스 상태로 복구<br>(전반적으로 손상된 경우 주로 사용) |
|  취소<br>(undo)  | 로그를 통해 지금까지 실행된 모든 변경 연산을 취소해 데이터베이스를 원래 상태로 복구<br>(변경 중이거나 이미 변경된 내용만 신뢰성을 잃은 경우 주 사용)                                                         |

### 로그 파일

- 데이터 변경 이전 값과 변경 이후 값을 기록한 파일
- 레코드 단위로 트랜잭션 수행과 함께 기록

<img src="https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch10/ch10-13-logfile.PNG"  height="auto" />

### 로그 기록 예시

- 계좌 잔액이 10,000원인 성호가 계좌 잔액이 0원인 은경에게 5,000원 이체

<img src="https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch10/ch10-14-logfileex.PNG"  height="auto" />

### 회복 기법

<img src="https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch10/ch10-15-RecoveryMethod.PNG"  height="auto" />

### 로그 회복 기법 : 즉시 갱신(Immediate Update) 회복 기법

- 트랜잭션 수행 중 데이터 변경 연산 결과를 데이터베이스에 즉시 반영
- 장애 발생에 대비하기 위해 데이터 변경에 대한 내용을 로그 파일에 기록
  - 데이터 변경 연산 실행 시 로그 파일에 로그 레코드 먼저 기록 후 데이터베이스에 변경 연산 반영
- 장애 발생 시점에 따라 redo, undo 연산 실행 후 데이터베이스 복구

#### 즉시 갱신 회복 기법 예시

<img src="https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch10/ch10-16-IURex.PNG"  height="auto" />

- 데이터베이스 회복 전략

<img src="https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch10/ch10-17-RS.PNG"  height="auto" />

- 장애 발생 시 반영 결과
  - 1에서 장애 발생 : undo($T_1$)
  - 2에서 장애 발생 : undo($T_2$), redo($T_1$)

<img src="https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch10/ch10-18-IURex2.PNG"  height="auto" />

### 로그 회복 기법 – 지연 갱신(Deferred Update) 회복 기법

- 트랜잭션 수행 중 데이터 변경 연산의 결과를 로그에만 기록
- 트랜잭션 부분 완료 후 로그 기록 내용을 데이터베이스에 한 번에 반영
- 트랜잭션 수행 중 장애 발생
  - 로그에 기록된 내용을 버리면 데이터베이스가 원래 상태 그대로 유지
    - undo 연산 사용 X
    - redo 연산 사용
    - 로그 레코드 : 변경 이후 값만 기록(\<T1, X, new_value\> 형식)

#### 지연 갱신 회복 기법 예시

- 데이터베이스 회복 전략

<img src="https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch10/ch10-19-RS.PNG"  height="auto" />

- 장애 발생 시 반영 결과
  - 1에서 장애 발생 : 로그 기록 무시 후 별다른 회복 조치 X
  - 2에서 장애 발생 : redo($T_1$)

<img src="https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch10/ch10-20-DURex.PNG"  height="auto" />

### 검사 시점 회복 기법

- 로그 기록을 이용하되, 일정 시간 간격의 검사 시점(checkpoint) 생성
  - 검사 시점이 된 경우
    - 모든 로그 레코드를 로그 파일에 기록
    - 데이터 변경 내용을 데이터베이스에 반영
    - \<checkpoint L\>
      - L : 현재 실행되는 트랜잭션 리스트
      - 검사 시점을 표시하는 로그 레코드
      - 로그 레코드 부분을 로그 파일에 기록
- 장애 발생
  - 가장 최근의 \<checkpoint L\> 로그 레코드 이후 기록에 대해서만 회복 작업 수행
    - 회복 작업 : 즉시 갱신 회복 기법 or 지연 갱신 회복 기법
- 로그 전체 대상 회복 기법 적용 시 발생하는 비효율성 문제 해결
  - 검사 시점으로 작업 범위가 결정
  - 불필요한 회복 작업이 없어 시간이 단축

#### 체크포인트(검사점)

- 회복(Recovery) 시 많은 양의 로그 검색 및 갱신 시간을 줄일 필요 존재
- 몇 십 분 단위로 데이터베이스와 트랜잭션 로그 파일 동기화 후 그 시점을 로그 파일에 기록하는 방법 혹은 그 시점

#### 체크포인트 시점 작업

- 주기억장치의 로그 레코드를 모두 하드디스크의 로그 파일에 저장
- 버퍼에 있는 변경 내용을 하드디스크 데이터베이스에 저장
- 체크포인트를 로그 파일에 표시

#### 체크포인트가 있는 로그 이용 회복 기법

- 체크포인트 이전 [COMMIT] 기록 존재

  - 어느 작업도 필요 X
  - 로그에 체크포인트가 나타나는 시점
    - 이미 변경 내용이 데이터베이스에 모두 기록된 후

- 체크포인트 이후 [COMMIT] 기록 존재

  - REDO(T) 진행
  - 체크포인트 이후 변경 내용이 데이터베이스에 미반영

- 체크포인트 이후 [COMMIT] 기록 존재 X

  - 즉시 갱신 방법

    - UNDO(T)를 진행
    - 버퍼의 내용이 반영됐을 수도 있기 때문에 원상 복구 필요

  - 지연 갱신 방법
    - 어느 작업도 필요 X
    - [COMMIT] 이전에 버퍼의 내용을 데이터베이스에 반영하지 않음

#### 검사 시점 회복 기법 예시

<img src="https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch10/ch10-21-Rex.PNG"  height="auto" />

- 즉시 갱신 방법
  - T2, T3 : 어떤 작업도 필요 없음
  - T4, T5 : REDO
  - T1, T6 : UNDO
- 지연 갱신 방법
  - T2, T3 : 어떤 작업도 필요 없음
  - T4, T5 : REDO
  - T1, T6 : 어떤 작업도 필요 없음

### 미디어 회복 기법

- 디스크에 발생할 수 있는 장애에 대비
- 덤프(복사본) 이용
  - 전체 데이터베이스의 내용을 일정 주기마다 다른 안전 저장 장치에 복사
- 디스크 장애 발생
  - 가장 최근 복사한 덤프 이용
  - 장애 발생 이전의 데이터베이스 상태로 복구
  - 필요에 따라 redo 연산 수행

## 3절. 병행 제어

### 병행 수행(Concurrency)

- 여러 사용자가 데이터베이스를 동시 공유할 수 있도록 여러 트랜잭션을 동시에 수행
- 여러 트랜잭션이 차례로 번갈아 수행되는 인터리빙(Interleaving) 방식

### 병행 제어(Concurrency Control)

- 동시성 제어
- 병행 수행 시 같은 데이터에 접근해 연산을 실행해도 문제 발생 X
- 정확한 수행 결과를 얻도록 트랜잭션 수행 제어

### 병행 수행 시 문제점

### 갱신 분실(Lost Update)

- 하나의 트랜잭션이 수행한 데이터 변경 연산 결과를 다른 트랜잭션이 덮어씀 => 변경 연산 무효화
- 두 개의 트랜잭션이 한 개의 데이터를 동시에 갱신(update) 시 발생
- 데이터베이스에서 절대 발생하면 안 되는 현상
- 트랜잭션들을 순차적으로 수행한 것과 같은 결과 값 필요

#### 갱신 분실 예시

- 트랜잭션 $T_1$ 에 대한 갱신 분실 발생

  - $T_1$ 의 변경 연산 결과가 데이터베이스에 반영 X

<img src="https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch10/ch10-22-LUex.PNG"  height="auto" />

- 해결 과정
  - 트랜잭션을 순차적으로 수행해서 갱신 분실 문제 방지

<img src="https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch10/ch10-23-LUex2.PNG"  height="auto" />

### 모순성(Inconsistency)

- 하나의 트랜잭션이 여러 개 데이터 변경 연산을 실행 시 발생
  - 일관성 없는 상태의 데이터베이스에서 데이터를 가져와 연산함으로써 모순 결과 발생
- 트랜잭션들을 순차적으로 수행한 것과 같은 결과 값 필요

#### 모순성 예시

- 트랜잭션 $T_1$ 에 대한 모순성 발생
  - $T_1$ 이 데이터 X와 Y를 서로 다른 상태의 데이터베이스에서 가져와 실행하는 모순 발생

<img src="https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch10/ch10-24-Iex.PNG"  height="auto" />

- 해결 과정
  - 트랜잭션을 순차적으로 수행해서 모순성 문제 방지

<img src="https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch10/ch10-25-Iex2.PNG"  height="auto" />

### 연쇄 복귀(Cascading Rollback)

- 트랜잭션 완료 전에 장애 발생
  - rollback 연산 수행 시 장애 발생 전에 이 트랜잭션이 변경한 데이터를 가져가서 변경 연산을 실행한 다른 트랜잭션에도 rollback 연산을 연쇄적으로 실행해야 하는 연쇄 복귀 발생
- 트랜잭션들을 순차적으로 수행한 것과 같은 결과 값 필요

#### 연쇄 복귀 예시

- 트랜잭션 $T_2$ 에 대한 연쇄 복귀 발생
  - $T_1$ 이 변경한 데이터 X를 가져가 연산을 수행한 $T_2$ 도 rollback 연산이 연쇄적으로 실행되어야 함
  - 이미 완료된 상태라서 rollback 연산을 실행할 수 없는 문제

<img src="https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch10/ch10-26-CRex.PNG"  height="auto" />

- 해결 과정
  - 트랜잭션을 순차적으로 수행해서 연쇄 복귀 문제 방지

<img src="https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch10/ch10-27-CRex2.PNG"  height="auto" />

### 트랜잭션 스케줄

- 트랜잭션에 포함된 연산들을 수행하는 순서

### 트랜잭션 스케줄 유형

<img src="https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch10/ch10-28-TStype.PNG"  height="auto" />

### 직렬 스케줄(Serial Schedule)

#### 의미

- 인터리빙 방식을 이용하지 않고 각 트랜잭션 별 연산들을 순차적으로 실행

#### 특징

- 다른 트랜잭션의 방해를 받지 않고 독립적으로 수행
  - 병행 수행이 아님
  - 항상 모순이 없는 정확한 결과
- 다양한 직렬 스케줄 생성
- 직렬 스케줄마다 데이터베이스에 반영되는 최종 결과가 상이
  - 직렬 스케줄의 결과는 모두 정확

#### 예시

- 트랜잭션 $T_1$, $T_2$ 대상 첫 번째 직렬 스케줄

<img src="https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch10/ch10-29-SSex1.PNG"  height="auto" />

- 트랜잭션 $T_1$, $T_2$ 대상 두 번째 직렬 스케줄

<img src="https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch10/ch10-30-SSex2.PNG"  height="auto" />

### 비직렬 스케줄(Non-Serial Schedule)

#### 의미

- 인터리빙 방식으로 트랜션을 병행 수행

#### 특징

- 트랜잭션이 번갈아 연산 수행
  - 하나의 트랜잭션 완료 전 다른 트랜잭션 연산 실행 가능
- 병행 수행 사 갱신 분실, 모순성, 연쇄 복귀 등의 문제 발생 가능
  - 결과 정확성 보장 불가
  - 잘못된 결과 생성 가능

#### 예시

- 트랜잭션 $T_1$, $T_2$ 대상 첫 번째 비직렬 스케줄 : 성공

<img src="https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch10/ch10-31-NSSex1.PNG"  height="auto" />

- 트랜잭션 $T_1$, $T_2$ 대상 두 번째 비직렬 스케줄 : 실패

<img src="https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch10/ch10-32-NSSex2.PNG"  height="auto" />

### 직렬 가능 스케줄(Serializable Schedule)

#### 의미

- 직렬 스케줄에 따라 수행한 것처럼 정확한 결과를 생성하는 비직렬 스케줄
- 비직렬 스케줄 중 수행 결과가 동일한 직렬 스케줄이 존재

#### 특징

- 인터리빙 방식으로 병행 수행하면서 정확한 결과
- 직렬 가능 스케줄 여부 판단
  - 직렬 가능성을 보장하는 병행 제어 기법 사용

#### 예시

- 트랜잭션 $T_1$, $T_2$ 대상 비직렬 스케줄이면서 정확한 수행 결과를 생성하므로 직렬 가능 스케줄

<img src="https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch10/ch10-33-SSex.PNG"  height="auto" />

### 병행 제어 기법

#### 개념

- 병행 수행하면서 직렬 가능성을 보장하기 위한 기법

#### 방법

- 모든 트랜잭션이 준수하면 직렬 가능성이 보장되는 규약 정의
- 트랜잭션들의 규약 준수를 권장

#### 대표적인 병행 제어 기법

- 로킹(Locking) 기법

### 로킹 기법

#### 기본 원리

- 한 트랜잭션이 먼저 접근한 데이터에 대한 연산을 끝내기 전까지 다른 트랜잭션이 접근하지 못하도록 상호 배제(Mutual Exclusion)

#### 방법

- lock / unlock 연산
  - lock : 트랜잭션이 데이터에 대한 독점권을 요청하는 연산
  - unlock : 트랜잭션이 데이터에 대한 독점권을 반환하는 연산

#### 기본 로킹 규약

- 트랜잭션은 데이터 접근을 위해 lock 연산 실행 후 독점권 획득
  - read / write 연산 실행 전 lock 연산 실행
- 다른 트랜잭션에 의해 lock 연산이 실행된 데이터에 다시 lock 연산 실행 불가
- 독점권을 획득한 데이터에 대한 모든 연산 수행 후 트랜잭션은 unlock 연산 실행으로 독점권 반납 필요

#### 로킹 단위

- lock 연산 실행 대상 데이터의 크기
- 전체 데이터베이스부터 릴레이션, 튜플, 속성까지 가능
- 로킹 단위가 커질수록 병행성은 낮아지지만 제어가 쉬움
- 로킹 단위가 작아질수록 제어가 어렵지만 병행성은 높아짐

### 두 개의 트랜잭션 작업

- 한 개의 데이터에 두 개의 트랜잭션이 접근해 갱신하는 작업

<img src="https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch10/ch10-34-2TW.PNG"  height="auto" />

### MySQL 실습

- 다른 두 세션(세션은 데이터베이스 접속단위)에서 진행
- MySQL 두 번 연결을 위해 MySQL Workbench에서 접속 2개 생성
  - LAB1과 동일한 내용의 LAB2 생성
  - 워크시트를 LAB1과 LAB2로 두 번 접속 후 진행

<img src="https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch10/ch10-35-2TWex1.PNG"  height="auto" />

<img src="https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch10/ch10-36-2TWex2.PNG"  height="auto" />

#### 로킹 기법 예시

<img src="https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch10/ch10-37-Lex1.PNG"  height="auto" />

### 기본 로킹 규약 효율성 증가 방법

- 트랜잭션들이 같은 데이터에 동시에 read 연산을 실행하도록 허용
- lock 연산 2가지

|      연산 종류       | 데이터에 해당 lock 연산을 수행한 경우                                                                                                               |
| :------------------: | :-------------------------------------------------------------------------------------------------------------------------------------------------- |
|  공용(Shared) lock   | read 연산 실행 가능 / write 연산 실행 불가능<br>다른 트랜잭션도 공용 lock 연산 동시 실행 가능<br>(데이터에 대한 사용권을 여러 트랜잭션이 함께 보유) |
| 전용(Exclusive) lock | read 연산 / write 연산 실행 가능<br>다른 트랜잭션은 모든 lock 연산 실행 불가능<br>(전용 lock 연산 실행 트랜잭션만 해당 데이터에 대한 독점권 보유)   |

#### 공유락(LS : Shared Lock)

- 트랜잭션이 읽기를 할 때 사용하는 락

#### 배타락(LX : Exclusive Lock)

- 읽고 쓸 때 사용하는 락

#### 공유락, 배타락 사용 규칙

- 데이터에 락이 걸려있지 않으면 트랜잭션은 데이터에 락 가능
- 데이터 X를 읽기만 할 경우
  - LS(X) 요청
- 데이터 X를 읽거나 쓸 경우
  - LX(X) 요청
- 다른 트랜잭션이 데이터에 LS(X)을 걸어둔 경우
  - LS(X) 요청 : 허용
  - LX(X) 요청 : 비허용
- 다른 트랜잭션이 데이터에 LX(X)을 걸어둔 경우
  - LS(X) & LX(X) : 비허용
- 트랜잭션이 락을 허용받지 못하면 대기 상태

### lock 연산 양립성

<img src="https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch10/ch10-38-Lock1.PNG"  height="auto" />

- 서로 다른 트랜잭션이 같은 데이터에 공용 lock 연산 동시 실행 가능
- 다른 트랜잭션이 전용 lock 연산을 실행한 데이터에 공용 lock, 전용 lock 모두 실행 불가

### 기본 로킹 규약으로 직렬 가능성이 보장되지 않는 스케줄 예시

- 트랜잭션 $T_1$ 이 데이터 X에 너무 빨리 unlock 연산을 실행해 트랜잭션 $T_2$가 일관성 없는 데이터에 접근
  - 2단계 로킹 규약 필요

<img src="https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch10/ch10-39-Lockex1.PNG"  height="auto" />

### 2단계 로킹 규약(2PLP : 2Phase Locking Protocol)

#### 의미

- 기본 로킹 규약의 문제를 해결하고 트랜잭션의 직렬 가능성을 보장을 위해 lock과 unlock 연산의 수행 시점에 대한 새로운 규약 추가

#### 방법

- lock / unlock 연산
- 확장 단계 / 축소 단계

|   단계    | 설명                                                                   |
| :-------: | :--------------------------------------------------------------------- |
| 확장 단계 | 트랜잭션이 lock 연산만 실행 가능하고 unlock 연산은 실행할 수 없는 단계 |
| 축소 단계 | 트랜잭션이 unlock 연산만 실행 가능하고 lock 연산은 실행할 수 없는 단계 |

- 트랜잭션이 처음 수행
  - 확장 단계로 들어가 lock 연산만 실행 가능
- unlock 연산 실행
  - 축소 단계로 들어가 unlock 연산만 실행 가능
- 트랜잭션은 첫 번째 unlock 연산 실행 전에 필요한 모든 lock 연산을 실행 필요

#### 예시

- 2단계 로킹 규약을 준수하며 직렬 가능성이 보장된 스케줄

<img src="https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch10/ch10-40-2PLPex1.PNG"  height="auto" />

### 교착 상태(Deadlock)

- 트랜잭션들이 상대가 독점하는 데이터에 unlock 연산이 실행되기를 서로 기다리며 트랜잭션의 수행을 중단하는 상태
- 교착 상태가 발생하지 않도록 예방
- 발생 시 빨리 탐지 후 조치 필요

## 4절. 트랜잭션 고립 수준

### 트랜잭션 시나리오

<img src="https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch10/ch10-41-TSS.PNG"  height="auto" />

### 오손 읽기(Uncommitted Dependency)

- 읽기 작업을 하는 트랜잭션 1이 쓰기 작업을 하는 트랜잭션 2가 작업한 중간 데이터를 읽기 때문에 생기는 문제
- 작업 중인 트랜잭션 2가 어떤 이유에서 작업을 철회(Rollback)할 경우 트랜잭션 1은 무효가 된 데이터를 읽고 잘못된 결과를 도출하는 현상

```SQL
DROP TABLE USERS;
CREATE TABLE USERS(
  id INTEGER,
  name VARCHAR2(20),
  age NUMBER
);

INSERT INTO USERS VALUES(1, 'HONG GILDONG', 30);

SELECT *
FROM USERS;

COMMIT;
```

<img src="https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch10/ch10-42-Tableex1.PNG"  height="auto" />

### 오손 읽기 문제 발생 예제

#### 작업 설명 : 두 트랜잭션 동시 실행

- 트랜잭션 $T_1$, $T_2$ 동시 실행
  - $T_1$ : 읽기
  - $T_2$ : 쓰기
- $T_1$ 은 $T_2$ 가 변경한 데이터를 읽어와 작업
- $T_2$ 가 작업 중 철회(ROLLBACK)

#### 문제 발생 : 오손 읽기

- $T_2$의 변경 데이터를 $T_1$ 이 읽고 어떤 원인으로 $T_2$ 가 철회(ROLLBACK) : $T_2$ 의 작업은 없던 일
- $T_1$ 은 $T_2$ 가 종료하지 않은 상태에서 $T_2$ 의 변경 데이터를 보고 작업을 수행한 상태

#### 문제 발생 예시 상황

- $T_2$ 가 홍길동의 나이를 30에서 21로 변경한 후 철회(ROLLBACK)해 $T_1$ 에게 오류를 발생시킨 예시

<img src="https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch10/ch10-43-Problemex1.PNG"  height="auto" />

### 반복 불가능 읽기(Inconsistent Analysis)

- ① $T_1$ : 데이터 읽기 => ② $T_2$ : 데이터 쓰기(갱신, UPDATE) => ③ $T_1$ : 다시 한 번 데이터를 읽을 때 생기는 문제
- $T_1$ 이 읽기 작업을 다시 한 번 반복할 경우 이전의 결과와 다른 결과가 나오는 현상

### 반복 불가능 읽기 문제 발생 예제

#### 작업 설명 : 두 트랜잭션 동시 실행

- 트랜잭션 $T_1$, $T_2$ 동시 실행
  - $T_1$ : 읽기
  - $T_2$ : 쓰기
- $T_1$ 은 데이터를 읽고 작업한 후 $T_2$ 가 변경한 데이터를 다시 한 번 읽어와 작업

#### 문제 발생 : 반복 불가능 읽기

- $T_1$ 이 데이터를 읽고 작업하던 중 $T_2$ 가 데이터 변경
- $T_1$ 은 변경 데이터를 다시 한 번 작업
- 오손 읽기와 달리 $T_2$ 가 COMMIT해서 틀린 데이터는 아님
- $T_1$ 입장에서 같은 SQL로 다른 결과 도출

#### 문제 발생 예시 상황

<img src="https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch10/ch10-44-Problemex2.PNG"  height="auto" />

(여기부터 작성)

### 유령 데이터 읽기(Phantom Read)

- 트랜잭션 1이 데이터를 읽고 트랜잭션 2가 데이터를 쓰고(삽입) 트랜잭션 1이 다시 한 번 데이터를 읽을 때 생기는 문제
  • 트랜잭션 1이 읽기 작업을 다시 한 번 반복할 경우 이전에 없던 데이터(유령 데이터)가 나타나는 현상

#### [작업 설명] 두 개의 트랜잭션을 동시에 실행

§ 트랜잭션 T1은 읽기만 하고 T2는 쓰기(삽입, INSERT)를 함
§ T1은 데이터를 읽고 작업을 한 후, T2가 변경한 데이터를 다시 한 번 읽어와 작업을 함

#### [문제 발생] 유령데이터 읽기

§ T1이 T2가 새로운 데이터를 삽입한 사실을 모르고 작업을 함
§ T2가 COMMIT을 했기 때문에 틀린 데이터는 아님
§ 그러나 T1 입장에서는 새로운 데이터가 반영되어 반복불가능 읽기와 마찬가지로 같은 SQL 문이 다른 결과를 도출함
§ 유령데이터 읽기는 반복불가능 읽기와 비슷하지만 없던 데이터가 삽입되었기 때문에 다르게 구분함

### 트랜잭션 고립 수준 명령어(Transaction Isolation Level Instruction)

- 트랜잭션 동시 실행으로 락보다 완화된 방법의 문제 해결을 위한 명령어

|    고립 수준     | 문제                                                                                  |
| :--------------: | :------------------------------------------------------------------------------------ |
| READ UNCOMMITTED | 1. 오손 읽기 : 가능<br>2. 반복 불가능 읽기 : 가능<br>3. 유령 데이터 읽기 : 가능       |
|  READ COMMITTED  | 1. 오손 읽기 : 불가능<br>2. 반복 불가능 읽기 : 가능<br>3. 유령 데이터 읽기 : 가능     |
| REPEATABLE READ  | 1. 오손 읽기 : 불가능<br>2. 반복 불가능 읽기 : 불가능<br>3. 유령 데이터 읽기 : 가능   |
|   SERIALIZABLE   | 1. 오손 읽기 : 불가능<br>2. 반복 불가능 읽기 : 불가능<br>3. 유령 데이터 읽기 : 불가능 |

#### 트랜잭션 동시 실행 예시

(38페이지부터 재작성!)
