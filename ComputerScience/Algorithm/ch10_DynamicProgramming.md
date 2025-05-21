# Chapter 10. 동적 프로그래밍(Dynamic Programming)

> 0절. 개요
>
> 1절. 재귀적 해법
>
> 2절. 동적 프로그래밍
>
> 3절.

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

<img src = "https://github.com/BangYunseo/TIL/blob/main/ComputerScience/Algorithm/Image/ch10/10-01-fibex.PNG" height="auto" />

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

<img src = "https://github.com/BangYunseo/TIL/blob/main/ComputerScience/Algorithm/Image/ch10/10-02-Memo.PNG" height="auto" />

- Memo(메모, 쪽지) + ization(화) => 메모 기법
- Top-Down Code
- 이미 계산된 결과를 저장하고 재사용하는 기법
- 중복 계산 방지
- 같은 입력에 대해 한 번만 계산 후 저장

### Tabulation

(여기부터 작성)

- 중복 재귀 호출을 피하는 방법
