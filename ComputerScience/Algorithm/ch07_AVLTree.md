# Chapter 7. AVL 트리(AVL Tree)

> 0절. 개요
>
> 1절. 재귀적 해법
>
> 2절.
>
> 3절.

## 0절. 개요

### AVL 트리

- 러시아 수학자 Adelson, Velskii, Landis에 의해 제안(1962년)
- 모든 노드의 왼쪽 서브 트리 높이(깊이)와 오른쪽 서브 트리 높이 차가 1 이하

### 트리의 깊이와 높이

- 이진 트리 한 노드 N에 대한 깊이(Depth)와 높이(Height)

<img src = "https://github.com/BangYunseo/TIL/blob/main/ComputerScience/Algorithm/Image/ch03/ch07-01-AVL.PNG" height="auto" />

|     종류     | 설명                                         | 영문                                          |
| :----------: | :------------------------------------------- | :-------------------------------------------- |
| 깊이(Depth)  | 루트 노드에서 노드 N까지의 간선 수           | of edges from the root to the node N          |
| 높이(Height) | 노드 N에서 가장 깊은 리프 노드까지의 간선 수 |  of edges from the node N to the deepest leaf |

- 임의 그래프 두 정점 s, t간 최단 경로 계산
  - s => t에 이르기 직전 방문하는 정점을 x라고 가정
  - 즉, s => x => t의 경로 계산
  - s와 t 간 최단 경로는 s와 x 간 최단 경로 포함

## 1절. 재귀적 해법
