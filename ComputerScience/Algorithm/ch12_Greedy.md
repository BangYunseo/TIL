# Chapter 12. Greedy(그리디 알고리즘)

> 1절. 개요

## 1절. 개요

### 그리디(Greedy)

- 눈 앞의 이익만 취하는 알고리즘
- 현재 시점에서 가장 이득인 것 같은 해, 최적이라고 판단하는 해를 선택하는 행위의 반복
- 대부분 최적해 탐색이 불가하고 괜찮은 해를 찾는 것이 목적
  - 다만, 드물게 최적해가 보장되는 경우가 존재

### 그리디 알고리즘 == 탐욕 알고리즘의 최적해 보장 조건

|최적해 보장 조건|설명|
|:---:|:---|
|Greedy choice property(탐욕 선택 속성)|지역적인 최선의 선택이 전체적인 최선의 해인 경우|
|Optimal substructure(최적 부분 구조)|문제의 최적 해가 부분 문제의 최적 해로 구성된 경우|

### 그리디 알고리즘과 DP의 차이점

|                 그리디                 |                       DP                        |
| :------------------------------------: | :---------------------------------------------: |
| 매 순간 최선의 선택을 하며 최적해 선택 | 모든 가능한 경우를 저장 후 비교하며 최적해 선택 |
|        간단한 구현과 빠른 실행         |  간단(?)하지 않은 구현과 그리디보다 느린 실행   |
|           항상 최적해 보장 X           |                항상 최적해 보장                 |

### 그리디 알고리즘 구조

<img src = "https://github.com/BangYunseo/TIL/blob/main/ComputerScience/Algorithm/Image/ch12/ch12-01-GreedyS.PNG" width="60%" height="auto" />

### 그리디의 최적해 보장 불가능 예시

#### 이진 트리 최적합 경로 탐색

- 경로의 합 최대화

<img src = "https://github.com/BangYunseo/TIL/blob/main/ComputerScience/Algorithm/Image/ch12/ch12-02-BST.PNG" width="40%" height="auto" />

#### 배낭 문제

- 7kg을 넣을 수 있는 배낭이 있을 때, 배낭에 넣는 물건은 아래와 같다.

| 물건 | 무게 | 가격 | (가격)/(무게) 값 |
| :--: | :--: | :--: | :--------------: |
|  A   | 3 kg | $ 2  |       0.67       |
|  B   | 1 kg | $ 2  |        2         |
|  C   | 3 kg | $ 4  |       1.33       |
|  D   | 4 kg | $ 5  |       1.25       |
|  E   | 2 kg | $ 3  |       1.5        |

- 그리디 알고리즘 방법
  - (가격)/(무게) 값이 큰 순서대로 넣는다
  - B, E, C, D, A
    - B, E만 삽입하면 무게가 가득 차기 때문에 가치는 $ 5
    - 최적해 : C, D (가치 : $ 9)

#### 동전 바꾸기 문제(액면 배수가 보장되지 않는 경우)

- 동전 액면이 모두 바로 아래 액면의 배수가 아닌 경우 최적해 보장 불가
- ex) 1300원을 동전으로 바꾼 최적해 비교

<img src = "https://github.com/BangYunseo/TIL/blob/main/ComputerScience/Algorithm/Image/ch12/ch12-03-BadCoin.PNG" height="auto" />

### 매트로이드(Matroid) : 그리디의 최적해 보장 가능한 예시

- 그리디 알고리즘으로 최적해가 보장되는 공간 구조

#### 동전 바꾸기 문제(액면 배수가 보장되는 경우)

- 동전 액면이 모두 바로 아래 액면의 배수인 경우 최적해 보장 가능
- ex) 3,261원을 동전으로 바꾼 최적해

<img src = "https://github.com/BangYunseo/TIL/blob/main/ComputerScience/Algorithm/Image/ch12/ch12-04-GoodCoin.PNG" height="auto" />

#### 최소 신장 트리를 위한 Prim 알고리즘과 Kruskal 알고리즘 구조

<img src = "https://github.com/BangYunseo/TIL/blob/main/ComputerScience/Algorithm/Image/ch12/ch12-05-PK.PNG" height="auto" />

#### 회의실 배정 문제(Room Scheduling Problem, Activity Selection Problem)

- 1 개의 회의실에 여러 부서에서 회의실 사용 요청
- (시작 시간, 종료 시간) 명시
- Greedy Idea : 끝나는 시간이 빠른 회의를 먼저 선택하면 그 이후 더 많은 회의를 배정할 수 있는 기회 획득

#### 회의실 배정 문제 예시

- 종료 시간이 빠른 순서로 정렬

> (3, 5), (1, 6), (6, 7), (5, 9), (8, 13), (7, 14), (12, 18), (16, 20)
>
> (3, 5) : 첫 번째 선택  
> (1, 6) : 미선택 : (3, 5)와 겹침     
> (6, 7) : 두 번째 선택     
> (5, 9) : 미선택 : (6, 7)과 겹침     
> (8, 13) : 세 번째 선택     
> (7, 14) : 미선택 : (8, 13)과 겹침     
> (12, 18) : 미선택 : (8, 13)과 겹침     
> (16, 20) : 네 번째 선택     
>
> => 최적해 : (3, 5), (6, 7), (8, 13), (16, 20)

#### 호프만 코딩(Huffman Coding)

<img src = "https://github.com/BangYunseo/TIL/blob/main/ComputerScience/Algorithm/Image/ch12/ch12-06-HC.PNG" height="auto" />

- Lossless Data Compression Algorithm
  - 무손실 데이터 압축 알고리즘
  - 데이터 압축 후 원래의 정보를 완벽하게 복원 가능
- Optimal Prefix Code
  - 최적 접두어 코드
  - 주어진 데이터에 가장 효율적인(최소 길이) 접두어 코드 생성성
- Variable-Length Code table for Encoding a source symbol
  - 인코딩을 위한 가변 길이 코드 테이블
  - ex) 파일 내 문자

#### 호프만 코딩 예시 (1)

<img src = "https://github.com/BangYunseo/TIL/blob/main/ComputerScience/Algorithm/Image/ch12/ch12-07-HC2.PNG" height="auto" />

- 어떤 Code도 다른 코드의 접두어가 되지 않음

#### 호프만 코딩 예시 (2)

<img src = "https://github.com/BangYunseo/TIL/blob/main/ComputerScience/Algorithm/Image/ch12/ch12-08-HC3.PNG" height="auto" />

- 예시문 : this is an example of a huffman tree
