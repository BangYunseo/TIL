# chapter 4. 스택(Stack)

![stack](https://github.com/BangYunseo/TIL/blob/main/CS/Data%20Structure/%20Image/ch4/stack.PNG)

#### 스택이란 ? 
* 한쪽 끝에서만 데이터를 넣고 뺄 수 있는 제한적으로 접근할 수 있는 후입선출(Last-In-First-Out) 형태의 선형 자료구조
  * 후입선출 : 나중에 들어온 값을 먼저 계산하는 방식
* 위의 그림에서 스택을 계산한다고 가정하자
  * 맨 위의 top 자료부터 계산을 진행

#### 스택의 간단한 개념
* 스택 제공 연산 종류
  * pop() : 스택의 가장 위 항목 제거
  * push(item) : item 하나를 스택의 가장 윗 부분에 추가
  * top() : 스택의 가장 위 항목 반환
  * isEmpty() : 스택이 비어있다면 True 반환
![stack2](https://github.com/BangYunseo/TIL/blob/main/CS/Data%20Structure/%20Image/ch4/stack2.PNG)

#### 스택의 예시
* 웹 브라우저 방문 기록(뒤로 가기)에서 가장 나중에 열린 페이지부터 확인 가능
* 키보드의 백스페이스(<-) 키로 최근에 입력한 글자를 지움
* 한글, 워드, 파워포인트, 엑셀 등 모든 편집기는 최근에 한 작업순으로 취소하는 기능 존재(ctrl + z)
* 함수 호출 체인의 경로

![stackfunction](https://github.com/BangYunseo/TIL/blob/main/CS/Data%20Structure/%20Image/ch4/stackfunction.PNG)

#### 스택의 활용
* 일반적인 가상 메모리 구조

![stackstructure](https://github.com/BangYunseo/TIL/blob/main/CS/Data%20Structure/%20Image/ch4/stackstructure.PNG)

#### 스택의 삽입과 삭제
* 값을 삽입할 때는 위에서 놓음
* 값을 삭제할 때는 위에서 뺌
  * 즉, 맨 윗 항목의 값만 파악 가능
![stackir](https://github.com/BangYunseo/TIL/blob/main/CS/Data%20Structure/%20Image/ch4/stackir.PNG)

#### 리스트로 구현한 스택
```py
class ListStack:
  def __init__(self):
    self.__stack = []
  def push(self, x):
    self.__stack.append(x)
  def pop(self):
    return self.__stack.pop()
  def top(self):
    if self.isEmpty():
      return None
    else:
      return self.__stack[-1]
  def isEmpty(self) -> bool:
    return not bool(self.__stack)
    # 또는  return len(self.__stack) == 0
  def popAll(self):
    self.__stack.clear()
  def printStack(self):
    print("Stack from top:", end=' ')
    for i in range(len(self.__stack) -1, -1, -1):
      print(self.__stack[i], end=' ')
    print()
```
#### 장점 
* 구조가 단순
* 쉬운 구현
* 데이터 저장 / 읽기 속도가 매우 빠름
    
#### 단점(배열일 경우)
* 데이터 최대 개수를 미리 정할 필요가 존재
* 저장 공간 낭비 발생 가능성 존재

[보충 참고 자료](https://velog.io/@alkwen0996/%EC%9E%90%EB%A3%8C%EA%B5%AC%EC%A1%B0-%EC%8A%A4%ED%83%9DStack)
[보충 참고 자료](https://jin-network.tistory.com/130)
