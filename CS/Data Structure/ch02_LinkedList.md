# chapter 2. 연결 리스트(Linked List)

![linkedlist](https://github.com/BangYunseo/TIL/blob/main/CS/Data%20Structure/%20Image/ch02/linkedlist.PNG)

#### 연결리스트란 ? 
* 데이터와 포인트로 구성된 노드 간의 연결을 이용해서 리스트를 구현한 자료구조
* 저장되는 데이터의 크기가 동적으로 변하고 리스트 중간에 있는 데이터를 삽입하거나 삭제해야 할 때 사용
* 연결 리스트는 배열의 고정크기의 단점을 보완
* 배열과 달리 연속적인 메모리 공간에 저장되어 있지 않기 때문에 연결이 필요함
    
#### 연결 리스트의 구분  
* 연결 리스트는 연결 방향에 따라 단일 연결 리스트, 이중 연결 리스트, 원형 연결 리스트가 존재함

#### 단일 연결 리스트(Singly Linked Linear List)
* 단일 연결 리스트는 각 노드에 자료 공간과 한 개의 포인터 공간이 있고, 각 노드의 포인터는 다음 노드를 가리킴

![Singly](https://github.com/BangYunseo/TIL/blob/main/CS/Data%20Structure/%20Image/ch02/Singly.PNG)

#### 이중 연결 리스트(Doubly Linked Linear List)
* 이중 연결 리스트의 구조는 단일 연결 리스트와 비슷하지만, 포인터 공간이 두 개가 있고 각각의 포인터는 앞의 노드와 뒤의 노드를 가리킴
    
![Doubly](https://github.com/BangYunseo/TIL/blob/main/CS/Data%20Structure/%20Image/ch02/Doubly.PNG)

#### 원형 연결 리스트(Circularly Linked Linear List)
* 원형 연결 리스트는 일반적인 연결 리스트에 마지막 노드와 처음 노드를 연결시켜 원형으로 만든 구조 

![Circularly](https://github.com/BangYunseo/TIL/blob/main/CS/Data%20Structure/%20Image/ch02/Circularly.PNG)

#### 연결리스트의 표현
* 연결 리스트는 그림과 같이 포인터를 사용해서 각 노드를 연결함

![linkedlist2](https://github.com/BangYunseo/TIL/blob/main/CS/Data%20Structure/%20Image/ch02/linkedlist2.PNG)

* Head는 리스트의 처음을 나타냄
* 노드는 데이터와 다음 노드를 가리키는 Next 포인터로 구성됨
* 각 노드는 Next 포인터를 사용하여 다음 노드와 연결됨
* 마지막 노드는 NULL을 가리켜 리스트의 끝을 나타냄
        
#### 장점 
* 동적(시간에 따라 변화)인 크기(가변적)
* 효율적인 삽입과 삭제 
  * 삽입 및 삭제 시에 데이터 이동이 필요 없음
* 유연함
    
##### 단점
* 요소에 접근하려면 첫 번째 노드부터 순차적으로 접근해야 함
  * 느린 접근
* 포인터를 위한 추가 메모리 공간이 필요
  * 구현하는 데 더 복잡함 
* 많은 양의 데이터를 저장하는 데 적합하지 않음


[본문 참고 자료](https://yoongrammer.tistory.com/44?category=956616)
