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

#### 힙의 예시(여기부터 다시 작성)


#### 큐의 삭제
* 큐에 값을 삭제하면 front(처음)부분에 값이 삽입

![dequeue](https://github.com/BangYunseo/TIL/blob/main/ComputerScience/Data%20Structure/%20Image/ch05/dequeue.PNG)

#### 리스트로 구현한 큐

```py
class ListQueue:
  def __init__(self):
    self.__queue = []

  def enqueue(self, x):
    self.__queue.append(x)

  def dequeue(self):
    return self.__stack.pop(0)
    # pop(0) : 리스트의 첫 원소 삭제 후 반환

  def front(self):
    if self.isEmpty():
      return None
    else:
      return self.__queue[0]

  def isEmpty(self) -> bool:
    return (len(self.__queue) == 0)

  def dequeueAll(self):
    self.__queue.clear()

  def printQueue(self):
    print("Queue from top : ")
    for i in range(len(self.__queue)):
      print(self.__queue[i], end=' ')
    print()
```

#### 큐의 시간 복잡도(여기부터 다시 작성)
* 삽입(Insertion) : O(1)
* 삭제(Deletion)
  * dequeue : O(1)
  * remove : O(N)
* 검색(Search) : O(N)
* 큐의 삽입은 front에서만 일어나고 삭제는 항상 rear에서만 일어나므로 삽입과 삭제에 소요되는 시간복잡도는 O(1)로 고정

#### 장점 
* 데이터의 순서가 중요한 작업에 사용 가능
* 버퍼로 사용 가능
    
#### 단점
* 고정된 큐의 크기
  * 데이터가 가득 차면 삽입이 더이상 불가능

[본문 참고 자료](https://bigsong.tistory.com/32)
