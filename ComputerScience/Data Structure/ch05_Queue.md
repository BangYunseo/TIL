# chapter 5. 큐(Queue)

![queue](https://github.com/BangYunseo/TIL/blob/main/ComputerScience/Data%20Structure/%20Image/ch5/queue.PNG)

#### 큐
* 가장 먼저 삽입한 원소를 유일하게 접근 가능한 원소로 갖는 선입선출(First-In-First-Out) 형태의 선형 자료 구조
  * 선입선출 : 먼저 들어온 값을 먼저 계산하는 방식
* 위의 그림에서 큐를 연산한다고 가정하자
  * 맨 왼쪽의 front 값부터 연산 가능
  * 삭제할 때는 front 값부터, 삽입할 때는 tail의 값 뒤부터 연산
* 큐와 스택은 한 쌍으로 취급하는 경우가 많음

#### 큐 연산
* 큐 제공 연산 종류

|함수|특성|
|:--:|:---|
|dequeue()|큐의 맨 뒤 원소 삽입|
|enqueue()|큐의 맨 앞 원소 반환 후 삭제|
|front()|큐의 맨 앞 원소 반환|
|isEmpty()|큐가 비어있다면 True 반환|
|dequeueAll()|큐를 깨끗이 청소|

![queue2](https://github.com/BangYunseo/TIL/blob/main/ComputerScience/Data%20Structure/%20Image/ch5/queue2.PNG)

#### 큐의 삽입
* 큐에 값을 삽입하면 tail(끝)부분에 값이 삽입

![enqueue](https://github.com/BangYunseo/TIL/blob/main/ComputerScience/Data%20Structure/%20Image/ch5/enqueue.PNG)

#### 큐의 삭제
* 큐에 값을 삭제하면 front(처음)부분에 값이 삽입

![dequeue](https://github.com/BangYunseo/TIL/blob/main/ComputerScience/Data%20Structure/%20Image/ch5/dequeue.PNG)

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
