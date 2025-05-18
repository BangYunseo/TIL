# Chapter 7. AVL 트리(AVL Tree)

> 0절. 개요
>
> 1절. AVL 트리
>
> 2절.
>
> 3절.

## 0절. 개요

### AVL 트리

- 러시아 수학자 Adelson, Velskii, Landis에 의해 제안(1962년)
- 모든 노드의 왼쪽 서브 트리 높이(깊이)와 오른쪽 서브 트리 높이 차가 1 이하

## 1절. AVL 트리

### 깊이(Depth), 높이(Height)

- 이진 트리 한 노드 N에 대한 깊이(Depth)와 높이(Height) 정의

<img src = "https://github.com/BangYunseo/TIL/blob/main/ComputerScience/Algorithm/Image/ch07/ch07-01-AVL.PNG" height="auto" />

|     종류     | 설명                                         |
| :----------: | :------------------------------------------- |
| 깊이(Depth)  | 루트 노드에서 노드 N까지의 간선 수           |
| 높이(Height) | 노드 N에서 가장 깊은 리프 노드까지의 간선 수 |

### 균형 인수(Balance Factor)

- 이진 트리 한 노드 N에 대한 균형 인수(Balance Factor) 정의

| <img src = "https://github.com/BangYunseo/TIL/blob/main/ComputerScience/Algorithm/Image/ch07/ch07-02-BF1.PNG" height="auto" /> | <img src = "https://github.com/BangYunseo/TIL/blob/main/ComputerScience/Algorithm/Image/ch07/ch07-03-BF2.PNG" height="auto" /> |
| ------------------------------------------------------------------------------------------------------------------------------ | ------------------------------------------------------------------------------------------------------------------------------ |

> Balance Factor(N)  
> = Height(RightSubtree(N))- Height(LeftSubtree(N))  
> = Height(LeftSubtree(N))- Height(RightSubtree(N))
