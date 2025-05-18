# Chapter 7. AVL 트리(AVL Tree)

> 0절. 개요
>
> 1절. AVL 트리
>
> 2절. 수선
>
> 3절. 표준화 : 4가지 수선
>
> 4절. 코드 구현

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

> 노드 1의 경우  
> Height(3) = 1  
> Height(6) = 3  
> Balance Factor(1) = Height(6) - Height(3) = 3 - 1 = 2

### 개념도

<img src = "https://github.com/BangYunseo/TIL/blob/main/ComputerScience/Algorithm/Image/ch07/ch07-04-AVLT.PNG" height="auto" />

### What is AVL Tree?

| <img src = "https://github.com/BangYunseo/TIL/blob/main/ComputerScience/Algorithm/Image/ch07/ch07-05-AVL1.PNG" height="auto" /> | <img src = "https://github.com/BangYunseo/TIL/blob/main/ComputerScience/Algorithm/Image/ch07/ch07-06-AVL2.PNG" height="auto" /> |
| ------------------------------------------------------------------------------------------------------------------------------- | ------------------------------------------------------------------------------------------------------------------------------- |

## 2절. 수선

### 수선 ?

- 삽입, 삭제 연산 후 트리의 균형이 깨질 때 트리의 균형을 다시 맞추는 과정
- 회전(rotation) 연산 이용

### 수선 예시

- 균형이 깨진 서브 트리 중 가장 낮은 곳부터 수선

<img src = "https://github.com/BangYunseo/TIL/blob/main/ComputerScience/Algorithm/Image/ch07/ch07-07-RB.PNG" height="auto" />

#### 좌회전 수선 : 불균형 1개

<img src = "https://github.com/BangYunseo/TIL/blob/main/ComputerScience/Algorithm/Image/ch07/ch07-08-RBP1.PNG" height="auto" />

#### 좌회전 수선 : 불균형 2개

<img src = "https://github.com/BangYunseo/TIL/blob/main/ComputerScience/Algorithm/Image/ch07/ch07-09-RBP2.PNG" height="auto" />

## 3절. 표준화 : 4가지 수선

### 표준화

- t = root
  - t의 4가지 서브 트리 유형에 따른 수선

| 유형 | 설명                           |
| :--: | :----------------------------- |
|  LL  | t.left.left가 가장 깊은 경우   |
|  LR  | t.left.right가 가장 깊은 경우  |
|  RR  | t.right.right가 가장 깊은 경우 |
|  RL  | t.right.left가 가장 깊은 경우  |

### LL

- 우회전(Right Rotation)

<img src = "https://github.com/BangYunseo/TIL/blob/main/ComputerScience/Algorithm/Image/ch07/ch07-10-LL.PNG" height="auto" />

### LR

- 좌회전 후 우회전(Left Rotation and Right Rotation)
- 타입 LL로의 변환

<img src = "https://github.com/BangYunseo/TIL/blob/main/ComputerScience/Algorithm/Image/ch07/ch07-11-LR.PNG" height="auto" />

### RR

- 좌회전(Left Rotation)

<img src = "https://github.com/BangYunseo/TIL/blob/main/ComputerScience/Algorithm/Image/ch07/ch07-12-RR.PNG" height="auto" />

### RL

- 우회전 후 좌회전(Right Rotation and Left Rotation)

<img src = "https://github.com/BangYunseo/TIL/blob/main/ComputerScience/Algorithm/Image/ch07/ch07-13-RL.PNG" height="auto" />

### 4가지 유형 수선 요약

<img src = "https://github.com/BangYunseo/TIL/blob/main/ComputerScience/Algorithm/Image/ch07/ch07-14-RBT.PNG" height="auto" />

## 4절. 코드 구현

### AVL 트리 코드 구현(파이썬)

- NIL 노드를 활용한 구현

```Py
# t = 회전 중심 노드

# AVL 노드 구현
class AVLNode:
  def __init__(self, newItem, left, right, h):
    self.item = newItem
    self.left = left
    self.right = right
    self.height = h

# AVL 트리 구현
class AVLTree:
  def __init__(self):
    self.NIL = AVLNode(None, None, None, 0)
    self.__root = self.NIL
    self.LL = 1; self.LR = 2; self.RR = 3; self.RL = 4
    self.NO_NEED = 0
    self.ILLEGAL = -1

  def height(self, node):
    return node.height

  def LeftRotation(t):
  childR = t.right
  childRL = childR.left
  childR.left = t
  t.right = childRL
  childR.height = max(childR.right.height, childR.left.height) + 1
  t.height = max(t.right.height, t.left.height) + 1
```
