# chapter 1. 배열(Array)

> [본문 참고 자료](https://yoongrammer.tistory.com/43)
>
> 1절. 배열
>
> 2절. 배열 구현

## 1절. 배열

### 배열(Array)

<img src="https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataStructure/Image/ch01/ch01-01-array.PNG" height="auto" />

- 연속된 메모리 공간에 순차적으로 저장된 데이터 집합
- 데이터가 동일한 유형을 가지고 순서대로 접근

#### 요소(element)

- 배열을 구성하는 각각의 값

#### 인덱스(index)

- 배열에서의 위치를 가리키는 숫자

#### 예시

- 염색체의 DNA 순서
- 영상의 픽셀 값
- 순차적인 데이터의 저장(값보다 순서가 중요한 경우)
- 다차원 데이터
- 어떤 특정 요소를 빠르게 읽을 때
- 정적인 데이터 사이즈와 그 요소 변화(추가, 삭제)가 빈번하지 않은 경우

### 배열 표현

<img src="https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataStructure/Image/ch01/ch01-01-array2.PNG" height="auto" />

- 연속된 메모리 공간에 순차적인 데이터 저장
- 인덱스는 <strong>0</strong>부터 시작

### 예시 : 배열의 크기가 10

- 요소 : 배열 크기가 10이므로 10개 요소 저장
- 인덱스 : 인덱스는 0부터 시작해서 9까지 저장
- ex) 각 요소에 접근하기 위한 인덱스
  - array[0] = 35;
  - array[-1] = 31;

### 특징

#### 1. 동일한 데이터 유형

- 동일 데이터 유형 형태로 존재
- 이질형 데이터도 지원 가능한 프로그래밍 언어 존재
- 레코드 : 이질형 데이터들이 모인 집합체

#### 2. 기본 위치 + 오프셋(요소 크기 \* 인덱스) 연산

- 모든 요소에 접근 가능

#### 3. 연속된 메모리에 단일 블록화

- 단일 블록화를 통한 데이터 저장
- 낭비되는 공간이 거의 없음
- 큰 배열은 필요한 메모리 할당이 불가능할 수 있음

#### 4. 실제 메모리의 저장 상태

- 데이터는 순차적으로 저장되므로 <strong>순서</strong> 존재

#### 5. 인덱싱(Indexing)과 슬라이싱(Slicing)

- 인덱스 형태로 존재

|   종류   |   영문   | 설명                                       |
| :------: | :------: | :----------------------------------------- |
|  인덱싱  | Indexing | index를 통해 특정 요소를 리스트로부터 읽기 |
| 슬라이싱 | Slicing  | 요소에 특정 부분을 따로 분리, 조작         |

### 장점

- 인덱스를 이용한 접근

  - 모든 요소에 빠른 접근 가능

- 부가정보 없이 데이터만 저장
  - 기록 밀도 == 1
    - 낮은 공간 낭비
- 간단한 구현
- 효율적인 공간 활용

### 단점

- 정적(Static)으로 할당된 배열의 메모리

  - 크기 변경 불가능
  - 삽입·삭제가 동적으로 발생하는 경우
    - 적절한 배열의 크기를 미리 결정하는 것이 어려움

- 높은 오버플로우 발생률
- 높은 저장공간 낭비 확률

- 중간에 특정 요소 삽입·삭제 작업을 하는 경우
  - 메모리는 항상 순차적
  - 작업이 진행된 요소로부터 앞의 모든 요소들의 이동 필요
  - 많은 비용 소모
- 범위를 벗어난 오류의 위험
- 이질적인 데이터에 부적합

## 2절. 배열 구현

### 구현

```python
# 1) 삽입 - (1) : 배열에 단순 삽입
arr = []
for i in range(10):
 arr.append(i)
print(arr)
# 출력 예시
# [0, 1, 2, 3, 4, 5, 6, 7, 8, 9]

# 2) 삽입 - (2) : 인덱스와 요소 지정 삽입
arr.insert(10, 'f')
print(arr)
# 출력 예시
# [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 'f']

# 3) 삭제 : 인덱스 지정 삭제
arr.remove(5)
arr.pop(0)
print(arr)
# 출력 예시
# [1, 2, 3, 4, 6, 7, 8, 9, 'f']

# 4) 탐색 - (1) : 인덱스 지정 탐색
print(arr.index(7))
# 출력 예시
# 5

# 5) 탐색 - (2) : 값이 있는 경우 인덱스 반환하는 탐색(값이 없으면 -1 반환)
def finding(array, val):
    res = -1
    for a in array:
        res += 1
        if val == a:
            return res
    else:
        return -1

print(finding(arr, 15))
# 출력 예시
# -1

print(finding(arr, 'f'))
# 출력 예시
# 8
```

### 시간 복잡도

|    작업     | 수행 시간 |
| :---------: | :-------: |
|    탐색     |  $O(1)$   |
| 삽입 · 삭제 |  $O(n)$   |
