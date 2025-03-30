# Chapter 0. 알고리즘(Algorithm) 개요

> 1절. 알고리즘 정의
>
> 2절. 알고리즘 효율성
>
> 3절. 알고리즘 수행시간

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
```

#### Q. 아래의 sample5 함수는 비례하는 수행 시간이 몇인가?

```python
def sample5(A, n):
  sum = 0
  for i in range(1, n):
    for j in range(1 + 1, n):
      sum += A[i] * A[j]
  return sum
```

- sample5 함수는 $n^2$에 비례하는 수행 시간을 가짐

### Binary Search

- $log n$에 비례하는 시간 소요

```python
def binary_search(arr, target):
  low = 0
  high = len(arr) - 1

  while low <= high:
    mid = (low + high) // 2

    if arr[mid] == target:
      return mid
    elif arr[mid] < target:
      low = mid + 1
    else:
      high = mid - 1
  return -1
# 어느 것도 찾지 못한 경우 -1 리턴
```

### 자기호출(재귀)

- 해결하고자 하는 문제 안에 크기가 작은 동일한 문제 존재
- ex) factorial 함수 : factorial 안에 factorial 존재

```Python
def factorial(n):
  if(n == 1) return 1
  return n * factorial(n - 1)
```

- factorial(n) 함수는

### 병합 정렬의 재귀

```Python
# A[p ... r]을 정렬
def mergeSort(A[ ], p, r):
  if (p < r):
    q = floor((p + r)/2)
    # p, r의 중간 지점 계산

    mergeSort(A, p, q)
    # 전반부 정렬

    mergeSort(A, q+1, r)
    # 후반부 정렬

    merge(A, p, q, r)
    # 병합

def merge(A[ ], p, q, r) {
  # 정렬되어 있는 두 배열 A[p ... q]와 A[q+1 ... r]을 합하여 정렬된 하나의 배열 A[p ... r] 생성
}
```

### 재귀 정리

- 프로그램의 크기가 작고 간단하게 표현 가능
- 그러나 stack에서 계속 복잡한 push, pop 연산으로 많은 메모리 사용
- 속도 저하로 이어질 가능성 존재
- loop로 해결할 수 있다면 loop를 사용하는 것이 효율적
