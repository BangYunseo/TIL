# Chapter 11. Graph(그래프)

> 0절. 개요
>
> 1절. 재귀적 해법
>
> 2절.
>
> 3절.

## 0절. 개요

### n!(n의 팩토리얼 계산)

1. n! = 1 × 2 × ··· × n
2. n! = n(n - 1)!

=> 크기가 n인 문제는 크기가 하나 작은 문제 포함

### 그래프 최단 경로 계산

- 임의 그래프 두 정점 s, t간 최단 경로 계산
  - s => t에 이르기 직전 방문하는 정점을 x라고 가정
  - 즉, s => x => t의 경로 계산
  - s와 t 간 최단 경로는 s와 x 간 최단 경로 포함

## 1절. 재귀적 해법

<img src = "https://github.com/BangYunseo/TIL/blob/main/ComputerScience/Algorithm/Image/ch03/03-01-SelectionSort.PNG" width="100%" height="auto" />
