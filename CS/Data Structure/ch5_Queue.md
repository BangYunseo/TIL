# chapter 5. 큐(Queue)

### 1. 큐(수정중)

![stack](https://github.com/BangYunseo/TIL/blob/main/CS/Data%20Structure/%20Image/ch4/stack.PNG)

#### (1) 스택이란 ? 한쪽 끝에서만 데이터를 넣고 뺄 수 있는 제한적으로 접근할 수 있는 후입선출(Last-In-First-Out) 형태의 선형 자료구조
    - 후입선출 : 나중에 들어온 값을 먼저 계산하는 방식
    - 위의 그림에서 스택을 계산한다고 가정하자
    -> 맨 위의 top 자료부터 계산을 진행

(아래부터 작성)
#### (2) 연결 리스트의 구분  
- 연결 리스트는 연결 방향에 따라 단일 연결 리스트, 이중 연결 리스트, 원형 연결 리스트가 존재함

##### 1. 단일 연결 리스트(Singly Linked Linear List)
    - 단일 연결 리스트는 각 노드에 자료 공간과 한 개의 포인터 공간이 있고, 각 노드의 포인터는 다음 노드를 가리킴

![Singly](https://github.com/BangYunseo/TIL/blob/main/CS/Data%20Structure/%20Image/ch2/Singly.PNG)

##### 2. 이중 연결 리스트(Doubly Linked Linear List)
    - 이중 연결 리스트의 구조는 단일 연결 리스트와 비슷하지만, 포인터 공간이 두 개가 있고 각각의 포인터는 앞의 노드와 뒤의 노드를 가리킴
    
![Doubly](https://github.com/BangYunseo/TIL/blob/main/CS/Data%20Structure/%20Image/ch2/Doubly.PNG)

##### 3. 원형 연결 리스트(Circularly Linked Linear List)
    - 원형 연결 리스트는 일반적인 연결 리스트에 마지막 노드와 처음 노드를 연결시켜 원형으로 만든 구조 

![Circularly](https://github.com/BangYunseo/TIL/blob/main/CS/Data%20Structure/%20Image/ch2/Circularly.PNG)

#### (3) 연결 리스트 표현

##### 연결리스트의 표현

- 연결 리스트는 그림과 같이 포인터를 사용해서 각 노드를 연결함
![linkedlist2](https://github.com/BangYunseo/TIL/blob/main/CS/Data%20Structure/%20Image/ch2/linkedlist2.PNG)

    - Head는 리스트의 처음을 나타냄
    - 노드는 데이터와 다음 노드를 가리키는 Next 포인터로 구성됨
    - 각 노드는 Next 포인터를 사용하여 다음 노드와 연결됨
    - 마지막 노드는 NULL을 가리켜 리스트의 끝을 나타냄
        
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
