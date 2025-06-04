# Chapter 12. Greedy(그리디 알고리즘)

> 0절. 개요
>
> 1절. 
>
> 2절. 
>
> 3절.

## 0절. 개요

### 그리디(Greedy)

- 눈 앞의 이익만 취하는 알고리즘
- 현재 시점에서 가장 이득인 것 같은 해를 선택하는 행위의 반복
- 대부분 최적해 탐색이 불가하고 괜찮은 해를 찾는 것이 목적
  - 다만, 드물게 최적해가 보장되는 경우가 존재

### 그리디 알고리즘 == 탐욕 알고리즘의 최적해 보장 조건

- 매 단계에서 가장 좋아보이는, 즉 현재 상황에서 최적이라고 판단한 선택을 하는 방식
- 항상 최적해를 보장하기 위한 2가지 조건
  - Greedy choice property(탐욕 선택 속성)
    - 지역적인 최선의 선택이 전체적인 최선의 해
  - Optimal substructure(최적 부분 구조)
    - 문제의 최적 해가 부분 문제의 최적 해로 구성

### 그리디 알고리즘과 DP

|그리디|DP|
|:---:|:---:|
|매 순간 최선의 선택을 하며 최적해 선택|모든 가능한 경우를 저장 후 비교하며 최적해 선택|
|간단한 구현과 빠른 실행|간단(?)하지 않은 구현과 그리디보다 느린 실행|
|항상 최적해 보장 X|항상 최적해 보장|

### 그리디 알고리즘 구조

<img src = "https://github.com/BangYunseo/TIL/blob/main/ComputerScience/Algorithm/Image/ch12/ch12-01-GreedyS.PNG" width="100%" height="auto" />

### 그리디의 최적해 보장

#### 최적해 보장 불가한 예시

- 이진 트리 최적합 경로 탐색 : 경로의 합 최대화

<img src = "https://github.com/BangYunseo/TIL/blob/main/ComputerScience/Algorithm/Image/ch12/ch12-02-BST.PNG" width="100%" height="auto" />

(여기부터 작성!)

- 배낭 문제
#### 최적해 보장 가능한 예시
