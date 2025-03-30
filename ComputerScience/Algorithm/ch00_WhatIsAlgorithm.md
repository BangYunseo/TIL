# Chapter 0. 알고리즘(Algorithm)

> 1절. 알고리즘 정의
>
> 2절. 알고리즘 효율성
>
> 3절. 데이터와 데이터베이스

## 1절. 알고리즘 정의

### 알고리즘(Algorithm) 이란 ?

- 문제 해결, 연산 수행을 위해 필요한 일련의 단계적 절차나 규칙
- 알고리즘에서 해결하려는 문제는 입력과 출력의 명시 필요
  - 문제의 입력이 알고리즘을 거치면 출력 생성

| 고려할 요소 |  특성  |
| :---------: | :----: |
|    입력     | 유한성 |
|    출력     | 명확성 |
|             | 효율성 |

## 2절. 알고리즘 효율성

### 효율성(Efficiency)

- 입력 크기가 커질수록 효율성의 중요성 증가
- 효율적인(efficient) 알고리즘 작성 시 고려할 점
  - 수행 시간
  - 메모리
- 알고리즘의 수행시간은 입력 크기를 기반으로 특정 비율로 소요

  - N : 입력 크기

- 수행 시간 예시

| 수행 시간 |     기호     |
| :-------: | :----------: |
|  1(상수)  |    $O(1)$    |
|    $N$    |    $O(N)$    |
|   $N^2$   |   $O(N^2)$   |
|   $N^3$   |   $O(N^3)$   |
|  $log N$  |  $O(log N)$  |
| $N log N$ | $O(N log N)$ |
| $log 2^n$ | $O(log 2^N)$ |

## 3절. 알고리즘 수행시간

### 알고리즘 특정 비율 별 수행 시간

<img src = "https://github.com/BangYunseo/TIL/blob/main/ComputerScience/Algorithm/Image/ch00/ch00-01-TimeGraph.PNG" width="60%" height="auto" />

<img src = "https://github.com/BangYunseo/TIL/blob/main/ComputerScience/Algorithm/Image/ch00/ch00-02-TimeTable.PNG" width="60%" height="auto" />

### 상수 시간 소요 : $O(1)$

- $n$에 관계 없이 상수 시간 소요

```python
def sample1(A[], n):
  k = floor(n / 2)
  // 내림수 사용
  return A[k]
```

### $n$에 비례하는 시간 소요 : $O(N)$

- $n$의 값에 비례하는 시간 소요

```python
def sample2(A, n):
  sum = 0
  for i in range(1, n):
    sum += A[i]
  return sum
```

### $n^2$에 비례하는 시간 소요 : $O(N^2)$

- $n^2$ 의 값에 비례하는 시간 소요

```python
def sample3(A, n):
  sum = 0
  for i in range(1, n):
    for j in range(1, n):
      sum += (A[i] * A[j])
  return sum

# 예시
print(sample3([1, 2, 3, 4, 5], 4))

# 출력
81
```

### $n^3$에 비례하는 시간 소요 : $O(N^3)$

- $n^3$ 의 값에 비례하는 시간 소요

```python
def sample4(A, n):
  sum = 0
  for i in range(1, n):
    for j in range(1, n):
      k <- A[1...n]에서 임의로 floor(n/2)개를 뽑을 경우 이들 중 최댓값
      sum += k
  return sum

# 예시
print(sample3([1, 2, 3, 4, 5], 4))

# 출력
81
```
