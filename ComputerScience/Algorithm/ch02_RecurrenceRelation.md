# Chapter 2. 점화식(Recurrence Relation)

> 1절. 점화식
>
> 2절. 반복 대치
>
> 3절. 추정 후 증명
>
> 4절. 마스터 정리

## 1절. 점화식

### 점화식(Recurrence Relation)

- 점화식과 점근적 표현법은 알고리즘 수행 시간 분석에 필요한 핵심 도구
- 점화식은 어떤 함수를 자신과 동일한 함수로 이용 후 표현

- ex 1) 동일한 함수 표현
  - $f(n) = f(n-1) + f(n-2)$
  - $T(n) = 2 T(n/2) + c $

### 점근적 분석 방법

- 점화식으로 표현된 식의 점근적 복잡도 분석 방법

  - $O(g(n))$ 과 같은 복잡도 계산

1. 반복 대치
2. 추정 후 증명
3. 마스터 정리

## 2절. 반복 대치

### 반복 대치 분석 과정

- 점화식을 반복 대치 후 경계 조건 대입
- $T(0)$에 도달 시 값 계산 가능

<img src = "https://github.com/BangYunseo/TIL/blob/main/ComputerScience/Algorithm/Image/ch02/ch02-01-T0.PNG" width="100%" height="auto" />

- $T(0) = 1$일 경우 $T(n) = 2n + 1 = O(n)$

#### 병합 정렬의 반복 대치

- 병합 정렬 함수

```Python
# A[p ... r]을 정렬
def mergeSort(A, p, r):
  if (p < r):
    q = floor((p + r)/2)
    # p, r의 중간 지점 계산

    mergeSort(A, p, q)
    # 전반부 정렬

    mergeSort(A, q+1, r)
    # 후반부 정렬

    merge(A, p, q, r)
    # 병합

def merge(A, p, q, r) {
  # 정렬되어 있는 두 배열 A[p ... q]와 A[q+1 ... r]을 합하여 정렬된 하나의 배열 A[p ... r] 생성
}
```

- mergeSort()의 중간 지점 계산에서 이등분 후 절반으로 줄어듦
- 전반부 정렬, 후반부 정렬 해결 후 병합에서 후처리
- 알고리즘 수행 시간
  - $T(n) = 2T(n / 2) +$ 후처리 시간
  - 병합 정렬은 $T(n) = 2T(n / 2) + n$, $T(1) = 1$ 로 표현
  - $k = log n$, $2^k = n$ 사용

$$
\begin{aligned}
T(n) &= 2T(n / 2) + n\\
    &= 2(2T(n / 2^2) + n / 2) + n = 2^2T(n / 2^2) + 2n\\
    &= 2^2(2T(n / 2^3) + n / 2^2) + 2n = 2^3T(n / 2^3) + 3n\\
    &···\\
    &= 2^kT(n / 2^k) + kn\\
    &= n + n log n\\
    &= O(n log n)\\
\end{aligned}
$$

#### Factorial(n) 함수의 반복 대치

```Python
def factorial(n):
  if(n == 1) return 1
  return n * factorial(n - 1)
```

- 알고리즘 수행 시간
  - $O(n) = T(n)$
  - $c$는 자기 호출을 제외한 나머지 수행 시간

$T(n) = T(n - 1) + c$
$T(1) \leq c$

$$
\begin{aligned}
T(n)&= T(n - 1) + c\\
    &= (T(n - 2) + c) + c = T(n - 2) + 2c\\
    &= (T(n - 3) + c) + 2c = T(n - 3) + 3c\\
    &···\\
    &=T(1) + (n - 1)c\\
    &\leq c + (n - 1)c\\
    &= cn\\
\end{aligned}
$$

## 3절. 추정 후 증명

### 추정 후 정리 분석 과정

- $T(n) = 2T(n / 2) + n$
- 추정 : $T(n) = O(n$ $log$ $n)$ 즉, $T(n) \leq c$ $n$ $log$ $n$

- 방법

1. 우리가 찾고자 하는 식 $T(n) \leq c$ $n$ $log$ $n$ 을 증명에 적용하니 맞았음
2. 따라서 우리가 제시한 추정이 맞는 것 같다는 논리
3. 만약 식 $T(n) \leq c$ $n$ $log$ $n$ 가 틀리면 추정과 같은 결로에 도달 불가

- 증명식

$$
\begin{aligned}
T(n) &=2T(n / 2) + n\\
    & \leq 2c(n / 2) log (n / 2) + n\\
    &= cn log n - cn log 2 + n\\
    &= cn log n + (-c log 2 + 1)n\\
    & \leq cn log n\\
\end{aligned}
$$

## 4절. 마스터 정리

### 마스터 정리 분석 과정

- $T(n) = aT(\frac {n}  {b}) + f(n)$ 으로 표현된 경우 정리를 통해 복잡도 계산 가능
- $h(n) = n^{log_b a}$

- $ \displaystyle \lim_{n \to \infin} \frac{f(n)}{h(n)} $ 이 0으로

1. 수렴하거나
2. 무한대로 발산하거나
3. 어떤 상수로 수렴하는가

- 위의 3가지 경우에 따라 점근적 복잡도 결정

### 마스터 정리 경우의 수

- $T(n) = aT(\frac {n}  {b}) + f(n)$, $h(n) = n^{log_b a}$

1. $ \displaystyle \lim_{n \to \infin} \frac{f(n)}{h(n)} $ 의 값이 0으로 수렴할 때 $T(n) = \Theta(h(n))$
2. $ \displaystyle \lim_{n \to \infin} \frac{f(n)}{h(n)} $ 의 값이 무한대로 발산할 때 $af(\frac{n}{b}) \leq f(n)$ 이라면 $T(n) = \Theta (f(n))$
3. $ \displaystyle \lim_{n \to \infin} \frac{f(n)}{h(n)} $ 의 값이 $\Theta(1)$ 일 때 $\\Theta(h(n)log n)$

#### ex 1 : $T(n) = 2(\frac{n}{3}) + c$

- a = 2, b = 3, h(n) = $n^{log_32}$, f(n) = c

- h(n)과 f(n)을 비교하면 h(n)의 차수가 높으므로 1번 정리에 해당

- h(n)이 수행 시간 결정

- 수행 시간 : $T(n) = \Theta(h(n)) = \Theta(n^{log_32})$

#### ex 2 : $T(n) = 2(\frac{n}{4}) + n$

- a = 2, b = 4, h(n) = $n^{log_42}$, f(n) = n

- h(n)과 f(n)을 비교하면 f(n)의 차수가 높으므로 2번 정리에 해당

- f(n)이 수행 시간 결정

- 수행 시간 : $T(n) = \Theta(f(n)) = \Theta(n)$

#### ex 3 : $T(n) = 2(\frac{n}{2}) + n$

- a = 2, b = 2, h(n) = $n^{log_22}$, f(n) = n

- h(n)과 f(n)을 비교하면 차수가 동일하므로 3번 정리에 해당

- 수행 시간 : $T(n) = \Theta(n log n)$
