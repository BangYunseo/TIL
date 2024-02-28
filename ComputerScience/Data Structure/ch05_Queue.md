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


#### (4) 장단점

##### 1. 장점 
    - 동적(시간에 따라 변화)인 크기(가변적)
    - 효율적인 삽입과 삭제 
    -> 삽입 및 삭제 시에 데이터 이동이 필요 없음
    - 유연함
    
##### 2. 단점
    - 요소에 접근하려면 첫 번째 노드부터 순차적으로 접근해야 함
    -> 느린 접근
    - 포인터를 위한 추가 메모리 공간이 필요
    -> 구현하는 데 더 복잡함 
    - 많은 양의 데이터를 저장하는 데 적합하지 않음


[보충 참고 자료](https://velog.io/@alkwen0996/%EC%9E%90%EB%A3%8C%EA%B5%AC%EC%A1%B0-%EC%8A%A4%ED%83%9DStack)
