# chapter 6. 힙(Heap)

#### 이진 트리의 종류
* 이진 트리(Binary Tree)
  * 노드 중 하나가 루트
  * 각 노드는 최대 2개까지의 자식을 가질 수 있음

![BT](https://github.com/BangYunseo/TIL/blob/main/ComputerScience/Data%20Structure/%20Image/ch06/BT.PNG)

* 포화 이진 트리(Full Binary Tree)
  * 루트로부터 시작해서 모든 노드가 정확히 두 개씩 자식 노드를 가지도록 꽉 채워진 트리
  * 노드 수가 (2^k - 1)일 때만 가능
    * (2^k - 1) : 0, 1, 3, 7, 15, 31, ...

![FBT](https://github.com/BangYunseo/TIL/blob/main/ComputerScience/Data%20Structure/%20Image/ch06/FBT.PNG)

* 완전 이진 트리(Complete Binary Tree)
  * 루트로부터 시작해서 가능한 지점까지 모든 노드가 정확히 두 개씩의 자식 노드를 가짐
  * 노드 수가 맞지 않아 full binary tree를 만들 수 없으면 맨 마지막 레벨은 왼쪽부터 채워짐
   
![CBT](https://github.com/BangYunseo/TIL/blob/main/ComputerScience/Data%20Structure/%20Image/ch06/CBT.PNG)

#### 힙

![heap](https://github.com/BangYunseo/TIL/blob/main/ComputerScience/Data%20Structure/%20Image/ch06/heap.PNG)

* 대표적인 우선순위 큐
* 우선순위를 관리하기 위한 특수한 성질을 가진 자료구조
* 힙이 만족해야 하는 두 조건
  * 완전 이진 트리
  * 힙 특성
    * 모든 노드는 값을 갖고 자식 노드 값보다 크거나 같음
    * 결과적으로 루트 노드가 제일 큰 원소를 가짐
* 최대 힙(Max heap) : 최소 힙(Min heap)
  * 루트가 최댓값 : 최솟값을 가짐
  * 둘은 대칭적인 특성을 가짐

#### 힙과 배열

![heaparray](https://github.com/BangYunseo/TIL/blob/main/ComputerScience/Data%20Structure/%20Image/ch06/heaparray.PNG)

* A[i]의 자식은 A[2i + 1]과 A[2i + 2]

![array](https://github.com/BangYunseo/TIL/blob/main/ComputerScience/Data%20Structure/%20Image/ch06/array.PNG)

* 배열은 그 자체로 완전 이진 트리
  * 노드 i의 자식 노드 : 2i + 1, 2i + 2
  * 노드 i의 부모 노드 : (i-1)/2

#### 힙 예시
* 10개의 원소로 구성된 힙과 대응되는 배열의 형태

![trueex](https://github.com/BangYunseo/TIL/blob/main/ComputerScience/Data%20Structure/%20Image/ch06/trueex.PNG)

* 힙 특성은 만족하지만 완전 이진 트리를 만족하지 못하는 형태

![falseex](https://github.com/BangYunseo/TIL/blob/main/ComputerScience/Data%20Structure/%20Image/ch06/falseex.PNG)

#### 힙 구조
* 힙 제공 연산 종류

|함수|특성|
|:--:|:---|
|insert(x)|힙에 원소 x 삽입|
|deleteMax()|힙의 최대 원소를 알려주면서 삭제|
|max()|힙의 최대 원소 반환|
|buildHeap()|배열을 힙으로 변환|
|isEmpty()|힙이 빈 힙인지 반환|
|clear()|힙 청소|

#### 힙의 삽입(insert)

- 새 원소를 힙의 마지막 자리(완전 이진 트리의 마지막 위치)에 추가
- 부모와 비교하며 힙 성질(부모 ≥ 자식)을 만족할 때까지 위로 이동(percolate-up)

```py
class Heap:
  def __init__(self):
    self.__heap = [None]                            # index 0은 사용하지 않음(1-based)

  def __percolateUp(self, i):                        # 부모와 비교하며 위로 이동
    parent = i // 2
    if i > 1 and self.__heap[i] > self.__heap[parent]:
      self.__heap[i], self.__heap[parent] = self.__heap[parent], self.__heap[i]
      self.__percolateUp(parent)

  def insert(self, x):
    self.__heap.append(x)                            # 마지막 자리에 추가
    self.__percolateUp(len(self.__heap) - 1)         # 제자리를 찾을 때까지 위로
```

#### 힙의 삭제(deleteMax)

- 루트(최대 원소)를 꺼내고, 마지막 원소를 루트 자리로 옮긴 뒤
- 더 큰 자식과 비교하며 아래로 이동(percolate-down)

```py
  def __percolateDown(self, i):                      # 더 큰 자식과 비교하며 아래로 이동
    last = len(self.__heap) - 1
    child = 2 * i                                    # 왼쪽 자식
    right = 2 * i + 1                                # 오른쪽 자식
    if child <= last:
      if right <= last and self.__heap[child] < self.__heap[right]:
        child = right                                # 더 큰 자식 선택
      if self.__heap[i] < self.__heap[child]:
        self.__heap[i], self.__heap[child] = self.__heap[child], self.__heap[i]
        self.__percolateDown(child)

  def deleteMax(self):
    if len(self.__heap) == 1:                        # 빈 힙
      return None
    self.__heap[1], self.__heap[-1] = self.__heap[-1], self.__heap[1]
    maximum = self.__heap.pop()                      # 원래 루트(최댓값) 제거 후 반환
    self.__percolateDown(1)
    return maximum
```

#### 힙의 시간 복잡도

|연산|시간 복잡도|
|:--:|:--:|
|insert(x)|O(log N)|
|deleteMax()|O(log N)|
|max()|O(1)|
|buildHeap()|O(N)|

* 삽입·삭제는 트리의 높이(O(log N))만큼만 이동하므로 O(log N)
* 최대 원소는 항상 루트에 있으므로 max()는 상수 시간
* buildHeap()은 임의 배열을 힙으로 만드는 연산으로 O(N)

#### 힙의 활용
* 우선순위 큐(Priority Queue) 구현
* 힙 정렬(Heap Sort)
* 최댓값(또는 최솟값)을 반복적으로 빠르게 구해야 하는 문제

[본문 참고 자료](https://bigsong.tistory.com/32)
