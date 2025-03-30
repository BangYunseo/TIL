# Chapter 1. 점근적 분석(Asymptotic Analysis)

> 1절. 점근적 분석
>
> 2절. 점근법 표기

## 1절. 점근적 분석

### 배경

- 입력 크기가 작으면 알고리즘의 효율성은 중요하지 않음
- 입력 크기가 크면 알고리즘의 효율성이 중요해짐

### 점근적 분석

- 입력 크기가 충분히 큰 경우에 대한 분석
- $\displaystyle \lim_{ n\to \infty }f(n)$
- $Ο, Ω, Θ, ω, O$ 표기법

## 2절. 점근법 표기

### $O(g(n))$

- 점근적 증가율이 $g(n)$을 넘지 않는 모든 함수
- 상한이자 최악의 경우
- ex 1) $2n^2+100n = O(n^2)$
- ex 2) $5n log n = O(n^2)$
- ex 3) $5n^3- 1000n = O(n^4)$
- 수학적 정의
  : $\{O(g(n))={f(n)|\exists c > 0, n_0 > 0, s.t.\forall n \geq n_0, f(n) \leq cg(n)}\}$

### $\Omega(g(n))$

- 점근적 증가율이 적어도 $g(n)$이 되는 모든 함수
- 하한이자 최선의 경우
- ex 1) $2n^2+100n = Ω(n^2)$
- ex 2) $5n log n = Ω(n)$
- ex 3) $5n^3- 1000n = Ω(n^2)$
- 수학적 정의
  : $\{Ω(g(n))={f(n)|\exists c > 0, n_0 > 0, s.t.\forall n \geq n_0, f(n) \geq cg(n)}\}$

### $\Theta(g(n))$

- 점근적 증가율이 $g(n)$과 일치하는 모든 함수
- 평균의 경우
- $\Theta (g(n)) = O(g(n))\cap \Omega (g(n))$
- ex 1) $2n^2+100n = \Theta(n^2)$
- ex 2) $5n log n = \Theta(n log n)$
- ex 3) $5n^3- 1000n = \Theta(n^3)$
- 수학적 정의
  : $\{\Theta(g(n))={f(n)|\exists c, d > 0, n_0 > 0, s.t.\forall n \geq n_0, cg(n) \leq f(n) \leq dg(n)}\}$

### 점근적 표기 그래프

<img src = "https://github.com/BangYunseo/TIL/blob/main/ComputerScience/Algorithm/Image/ch01/ch01-01-Graph.PNG" width="100%" height="auto" />

### 빅오(O) 복잡도 차트

<img src = "https://github.com/BangYunseo/TIL/blob/main/ComputerScience/Algorithm/Image/ch01/ch01-02-BigOh.PNG" width="100%" height="auto" />

### 정렬 알고리즘 복잡도

<img src = "https://github.com/BangYunseo/TIL/blob/main/ComputerScience/Algorithm/Image/ch01/ch01-03-ArraySorting.PNG" width="100%" height="auto" />

### 점근적 표기 예제

- ex 1) $5n^2 = O(n^2)$
- ex 2) $5n + 3 = O(n^2)$
- ex 3) $5n^2 = \Omega(n^2)$
- ex 4) $5n^3 + 3 = \Omega(n^2)$
- ex 5) $5n^2 = \Theta(n^2)$

### 시간 복잡도 분석 정리

- Worst Case $(O(g(n)))$는 가장 나쁜 경우에 대한 시간 복잡도 제공
- Average Case는 모든 입력을 분석하여 얻는 복잡도지만 현실적으로 구하기 힘듦
- Best Case는 낙관적인 경우의 복잡도라 유용하지 않음
