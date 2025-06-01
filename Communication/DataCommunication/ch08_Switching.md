# Chapter 8. 교환(Switching)

> 0절. 교환
>
> 1절. 회선 교환망
>
> 2절. 패킷 교환
>
> 3절. 교환기 구조

## 0절. 교환

### 교환(Switching)

- 각 장치 간 일대일(One-to-One) 통신이 가능하도록 연결하는 방법

<img src = "https://github.com/BangYunseo/TIL/blob/main/Communication/DataCommunication/Image/ch08/ch08-01-Switching.PNG" height="auto"/>

### 교환 방법 종류

1. 회선 교환(Circuit Switching)
2. 패킷 교환(Packet Switching)
3. 메세지 교환(Message Switching)

<img src = "https://github.com/BangYunseo/TIL/blob/main/Communication/DataCommunication/Image/ch08/ch08-02-SwitchingType.PNG" height="auto"/>

### TCP/IP 계층에서의 교환

|      계층      |       영문        |                        교환 방식                        |           비고            |
| :------------: | :---------------: | :-----------------------------------------------------: | :-----------------------: |
|    물리 층     |  Physical Layer   |                        회선 교환                        |             .             |
| 데이터 링크 층 |  Data Link Layer  |           패킷 교환<br>(가상 회선 접근 방식)            | 프레임(Frame) OR 셀(Cell) |
|  네트워크 층   |   Network Layer   | 패킷 교환<br>(가상 회선 접근 방식, 데이터그램 접근 방식 |             .             |
|    응용 층     | Application Layer |                       메세지 교환                       |             .             |

## 1절. 회선 교환망

### 회선 교환망(Circuit-Switched Networks)

<img src = "https://github.com/BangYunseo/TIL/blob/main/Communication/DataCommunication/Image/ch08/ch08-03-CSN.PNG" height="auto"/>

> 각 링크를 n개 채널로 나누는 물리적 링크에 의해 연결된 교환기 집합

- 물리 링크로의 연결
- 단일 교환기
  - 두 지국 간 연결 : 1개 이상의 링크로 만들어진 <strong>전용 경로</strong>
    - 연결 : 각 링크 중 하나의 전용 채널만 사용
    - 링크 : FDM OR TDM 방식으로 n개의 채널로의 분할

#### 회선 교환망 연결 단계

|   단계 종류    | 작업                                        |
| :------------: | :------------------------------------------ |
| 연결 설정 단계 | 자원 할당 필요                              |
| 연결 해제 단계 | 전체 데이터 전송 기간 동안 전용적 자원 할당 |

#### 회선 교환망 스위치 I/O

<img src = "https://github.com/BangYunseo/TIL/blob/main/Communication/DataCommunication/Image/ch08/ch08-04-CSNIO.PNG" height="auto"/>

- 회로 스위치
  - 연결을 생성하는 n개의 Input
  - m개의 Output
- Input 수와 Output 수가 항상 동일하지는 않음

#### 접이식 스위치 I/O

<img src = "https://github.com/BangYunseo/TIL/blob/main/Communication/DataCommunication/Image/ch08/ch08-05-FCSN.PNG" height="auto"/>

- n × n 접이식(Folded) 스위치
- 전이중(Full-Duplex) 모드
- n개의 각 전화기는 다른 모든 전화기에 연결 가능

####
