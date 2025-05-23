# Chapter 10. 동적 프로그래밍(Dynamic Programming)

> 0절. 개요
>
> 1절. 재귀적 해법
>
> 2절. 동적 프로그래밍
>
> 3절. DP : 행렬 경로 문제
>
> 4절. DP : 돌 놓기 문제
>
> 5절. DP : 행렬 곱셈 순서 문제
>
> 6절. DP : 최장 공통 부분 순서 문제

## 0절. 개요

### n!(n의 팩토리얼 계산)

1. n! = 1 × 2 × ··· × n
2. n! = n(n - 1)!

=> 크기가 n인 문제는 크기가 하나 작은 문제 포함

### 그래프 최단 경로 계산

- 임의 그래프 두 정점 s, t간 최단 경로 계산
  - s => t에 이르기 직전 방문하는 정점 : x
  - s => x => t의 경로 계산
  - s와 t 간 최단 경로는 s와 x 간 최단 경로 포함

## 1절. 재귀적 해법

### 재귀적 해법 사용

|     경우      | 예시                                                                        |
| :-----------: | :-------------------------------------------------------------------------- |
| 바람직한 경우 | 1. 퀵 정렬, 병합 정렬 등 정렬 알고리즘<br>2. 계승 계산(n!)<br>3. 그래프 DFS |
|  피하는 경우  | 1. 피보나치 수 계산<br>2. 행렬 곱셈 최적 순서 계산                          |

### 재귀적 해법과 DP

- 유사한 점

  - 분할 정복적 사고 : 큰 문제를 작은 부분 문제로 분할 후 해결
  - 문제 구조 : 중복 부분 문제와 최적 부분 구조의 문제에 적합

- 차이점
  - 중복 계산
  - 메모리 사용
  - Top-Down VS Bottom-Up
  - Call Stack 사용 VS Stack 과부화 없음

## 2절. 동적 프로그래밍

### 재귀 함수 : 피보나치 수 계산

- 피보나치 수 계산 공식
  - $f(n)=f(n-1)+f(n-2)$
  - $f(1)=f(2)=1$

```python
# 재귀 알고리즘 코드 구현

def fib(n):
  if(n == 1 or n == 2):
      return 1
  else:
    return (fib(n - 1) + fib(n - 2))
```

- ex) fib(7)을 재귀적으로 구현한 경우

<img src = "https://github.com/BangYunseo/TIL/blob/main/ComputerScience/Algorithm/Image/ch10/ch10-01-fibex.PNG" height="auto" />

- fib() 문제 크기에 의한 fib(2) 중복 호출

|  fib()  | fib(2) 중복 호출 횟수 |
| :-----: | :-------------------: |
| fib(4)  |           2           |
| fib(5)  |           3           |
| fib(6)  |           5           |
| fib(7)  |           8           |
| fib(8)  |          13           |
| fib(9)  |          21           |
| fib(10) |          34           |

### 동적 프로그래밍 사용 조건

#### 1. 최적 부분 구조(Optimal Substructure)

- 문제의 해답에 그보다 작은 문제의 해답이 포함된 경우

#### 2. 중복 호출

- 재귀적 구현 시 중복 호출로 심각한 비효율이 발생한 경우

### DP : 피보나치 수 계산

- DP 알고리즘의 피보나치 수

```Python
# 동적 프로그래밍 알고리즘 코드 구현

def fib(n):
  if(n <= 0):
    return 0
  elif(n == 1 or n == 2):
    return 1

  f = [0] * (n + 1)

  f[1] = 1
  f[2] = 1

  for i in range(3, n + 1):
    f[i] = f[i - 1] + f[i - 2]

  return f[n]
```

### Memoization

<img src = "https://github.com/BangYunseo/TIL/blob/main/ComputerScience/Algorithm/Image/ch10/ch10-02-Memo.PNG" height="auto" />

- Memo(메모, 쪽지) + ization(화) => 메모 기법
- Top-Down Code
- 이미 계산된 결과를 저장하고 재사용하는 기법
- 중복 계산 방지
- 같은 입력에 대해 한 번만 계산 후 저장

### Tabulation

- Tab(le)(메모, 쪽지) + ulation(화) => 테이블 기법
- Bottom-Up Code
- 중복 재귀 호출을 피하는 방법
- 작은 문제 -> 큰 문제 순서로 해결하는 방법
- Loop를 통해 해결
- 테이블(배열) 생성을 통해 값 저장 후 진행
- 재귀 호출 미사용(Stack Overflow X)
- Memoization X

### Memoization VS Tabulation

|    종류     |     구현<br>방식      | 저장<br>방식 |             호출<br>순서             |    사용<br>메모리    |
| :---------: | :-------------------: | :----------: | :----------------------------------: | :------------------: |
| Memoization | 재귀 호출 + 결과 저장 |   Top-Down   | 큰 문제부터 호출, 작은 문제로 내려감 | 적음(재귀 스택 사용) |
| Tabulation  | 반복문으로 직접 계산  |  Bottom-Up   |         작은 문제부터 올라감         | 배열 전체 미리 할당  |

#### 알고리즘 구현 비교 : Memoization VS Tabulation

- 일반적인 피보나치 함수

```python
def fib(n):
  if n <= 1:
    return n
  return fib(n - 1) + fib(n - 2)
```

- Memoization : Top-Down 코드

```python
def fib_memo(n, memo = {}):
  # 입력받은 값이 memo 배열에 존재할 경우 바로 리턴
  if n in memo:
    return memo[n]

  if n <= 1:
    return n
  memo[n] = fib(n - 1, memo) + fib(n - 2, memo)
  return memo[n]
```

- Tabulation : Bottom-Up 코드

```python
def fib_tab(n):
  if n <= 1:
    return n

  # 맨 아래 배열부터 값 저장
  dp = [0] * (n + 1)
  dp[1] = 1
  for i in range(2, n + 1):
    dp[i] = dp[i - 1] + dp[i - 2]
  return dp[n]
```

- 시간 복잡도는 모두 $O(n)$

## 3절. DP : 행렬 경로 문제

### 문제 설명

- 양수 원소로 구성된 n × n 행렬 존재
- 행렬의 좌상단 -> 우하단까지 이동

### 이동 방법(제약조건)

- 오른쪽 or 아래쪽으로만 이동 가능
- 왼쪽, 위쪽, 대각선 이동 비허용

<img src = "https://github.com/BangYunseo/TIL/blob/main/ComputerScience/Algorithm/Image/ch10/ch10-03-BadMoving.PNG" height="auto" />

<img src = "https://github.com/BangYunseo/TIL/blob/main/ComputerScience/Algorithm/Image/ch10/ch10-04-GoodMoving.PNG" height="auto" />

### 목표

<img src = "https://github.com/BangYunseo/TIL/blob/main/ComputerScience/Algorithm/Image/ch10/ch10-05-moveMax.PNG" height="auto" />

- 행렬 좌상단 -> 우하단 까지의 이동
- 방문한 칸의 수들을 더한 값이 최대화(or 최소화)

### 재귀 알고리즘

```python
def moveMax(m, i, j):
  if i == 0 or j == 0:
    return 0

  res = m[i][j] + max(moveMax(m, i - 1, j), moveMax(m, i, j - 1))
  return res
```

- 중복 호출 발생 : DP로의 구현 가능

<img src = "https://github.com/BangYunseo/TIL/blob/main/ComputerScience/Algorithm/Image/ch10/ch10-06-moveProblem.PNG" height="auto" />

### 동적 프로그래밍 알고리즘

- 수행시간
  - $Θ(n^2)$
  - 행렬 원소 수 $(n^2)$ 에 대한 선형시간

```python
def moveMax(m, n):
  # 딕셔너리에 (i, j) 값이 계산된 경우 바로 반환
  c = [[0] * (n + 1) for i in range(n + 1)]

  for a in range(n + 1):
    c[a][0] = 0

  for b in range(n + 1):
    c[0][b] = 0

  for i in range(1, n + 1):
    for j in range(1, n + 1):
      c[i][j] = m[i][j] + max(c[i - 1][j], c[i][j - 1])

  return c[n][n]
```

### 응용 분야

- 로봇 경로 최적화(Robot Path Planning)
- 지도 기반 길찾기 (Pathfinding on Grids)
- 이미지 처리 및 컴퓨터 비전
- DNA 서열 정렬 (Sequence Alignment)
- 게임 인공지능 (Game AI Movement)
- 데이터 테이블 비교 및 변환 (Diff Tools)

## 4절. DP : 돌 놓기 문제

### 문제 설명

<img src = "https://github.com/BangYunseo/TIL/blob/main/ComputerScience/Algorithm/Image/ch10/ch10-07-PP.PNG" height="auto" />

- 3 × n 테이블의 각 칸에 숫자를 제한 조건에 따라 처리
- 돌이 놓인 곳에 있는 수의 합을 최대(or 최소)로 하는 문제

### 제한 조건

<img src = "https://github.com/BangYunseo/TIL/blob/main/ComputerScience/Algorithm/Image/ch10/ch10-08-PPV.PNG" height="auto" />

- 가로 or 세로의 인접 두 칸에 동시에 돌 놓기 불가
- 각 열에 적어도 하나 이상의 돌 필수

### 패턴 조건

#### 패턴 1

<img src = "https://github.com/BangYunseo/TIL/blob/main/ComputerScience/Algorithm/Image/ch10/ch10-09-P1.PNG" height="auto" />

- 양립 가능 패턴
  - 1 : 2 : 1
  - 1 : 3 : 1

<img src = "https://github.com/BangYunseo/TIL/blob/main/ComputerScience/Algorithm/Image/ch10/ch10-13-P1-2.PNG" height="auto" />

#### 패턴 2

<img src = "https://github.com/BangYunseo/TIL/blob/main/ComputerScience/Algorithm/Image/ch10/ch10-10-P2.PNG" height="auto" />

- 양립 가능 패턴
  - 2 : 1 : 2
  - 2 : 3 : 2
  - 2 : 4 : 2

<img src = "https://github.com/BangYunseo/TIL/blob/main/ComputerScience/Algorithm/Image/ch10/ch10-14-P2-2.PNG" height="auto" />

#### 패턴 3

<img src = "https://github.com/BangYunseo/TIL/blob/main/ComputerScience/Algorithm/Image/ch10/ch10-11-P3.PNG" height="auto" />

- 양립 가능 패턴
  - 3 : 1 : 3
  - 3 : 2 : 3

<img src = "https://github.com/BangYunseo/TIL/blob/main/ComputerScience/Algorithm/Image/ch10/ch10-15-P3-2.PNG" height="auto" />

#### 패턴 4

<img src = "https://github.com/BangYunseo/TIL/blob/main/ComputerScience/Algorithm/Image/ch10/ch10-12-P4.PNG" height="auto" />

- 양립 가능 패턴
  - 4 : 2 : 4

<img src = "https://github.com/BangYunseo/TIL/blob/main/ComputerScience/Algorithm/Image/ch10/ch10-16-P4-2.PNG" height="auto" />

### 문제 해결 예시

<img src = "https://github.com/BangYunseo/TIL/blob/main/ComputerScience/Algorithm/Image/ch10/ch10-17-PPP.PNG" height="auto" />

- i 열이 패턴 2로 놓여있는 경우의 최고점 계산

<img src = "https://github.com/BangYunseo/TIL/blob/main/ComputerScience/Algorithm/Image/ch10/ch10-18-PPS.PNG" height="auto" />

- 문제 해결 경우의 수 3가지
  - (i - 1)열이 패턴 1인 경우
  - (i - 1)열이 패턴 3인 경우
  - (i - 1)열이 패턴 4인 경우

#### 계산 방식

- $c_{i2}$ : i 열이 패턴 2로 놓일 때의 최고점
- $w_{i2}$ : i 열 패턴 2에 놓은 돌의 값
- $c_{i2} = w_{i2} + max(c_{i-1, 1}, c_{i-1, 3}, c_{i-1, 4})$

#### 최종 목표

- 돌 놓기 문제에서 최종적으로 계산하는 값
  - {$c_{i1}, c_{i2}, c_{i3}, c_{i4}$} 중 가장 큰 값

### 재귀적 관계

- $c_{ip}$ 의 재귀적 관계

$$
c_{ip} = \begin{cases} w_{1p} & \text{if } i = 1 \\ \max_q{ c_{i-1 ,q} } + w_{ip} & \text{if } i > 1 \end{cases}
$$

- 최적 부분 구조(Optimal Substructure)
  - 자신보다 크기가 1 작은 문제의 최적해를 자신의 최적해 구성에 사용

### 응용 분야

- 격자 형태의 그래프에서 인접하지 않은 노드들 중 최대 개수 선택
  - WiFi 안테나 설치
  - 센서 배치
  - 자원 분산
- 논리 회로 배치 및 VLSI 설계
- 게임 이론 및 AI 전략 수립
- 작업 스케줄링 및 자원 할당
  - 회의실 예약
  - 학교 시간표
  - CPU 스케줄링

## 5절. DP : 행렬 곱셈 순서 문제

## 6절. DP : 최장 공통 부분 순서 문제
