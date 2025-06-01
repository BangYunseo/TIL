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
- 전통적인 전화망의 물리층 교환 방식

#### 회선 교환망 단계 별 작업

|    단계 종류     | 작업                                        |
| :--------------: | :------------------------------------------ |
|  연결 설정 단계  | 자원 할당 필요                              |
| ~ 연결 해제 단계 | 전체 데이터 전송 기간 동안 전용적 자원 할당 |

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

#### 연결 단계

|    단계 종류     |        영문         | 설명                                          |
| :--------------: | :-----------------: | :-------------------------------------------- |
|  연결 설정 단계  |     Setup Phase     | 교환기 사이 전용 회선 생성                    |
| 데이터 전송 단계 | Data Transfer Phase | 두 당사자 간 데이터 전달                      |
|  연결 해제 단계  |   Teardown Phase    | 당사자 중 하나가 연결 끊기를 원하면 자원 해제 |

#### 연결 설정 단계

<img src = "https://github.com/BangYunseo/TIL/blob/main/Communication/DataCommunication/Image/ch08/ch08-06-SP.PNG" height="auto"/>

- 연결 설정 단계(Setup Phase)

  - 스위치 간 전용 채널 생성
    - ex) A -> I에게 채널 요청 -> IV로 연결 III으로 연결 -> M은 연결 받은 후 A에게 Acknowledge 전송

- 데이터 전송 단계

  - 전송 채널로 데이터 전송

- 연결 해제 단계

  - 연결 끊을 경우 각 스위치에게 신호를 보내서 Disconnect

#### 효율(Efficiency)

- 데이터 전송 기간 동안 지속적인 자원 할당
  - 안좋은 효율

| 전송 상황 경우 | 상황                         |
| :------------: | :--------------------------- |
|  전화의 경우   | 통화가 끝날 때까지 계속 연결 |
| 데이터의 경우  | 지속적인 연결 필요 X         |

#### 지연(Delay)

<img src = "https://github.com/BangYunseo/TIL/blob/main/Communication/DataCommunication/Image/ch08/ch08-07-Delay.PNG" height="auto"/>

- 데이터 전송 기간 에는 적은 지연
- 연결 설정 단계
  - 1. src로부터 전파 시간
  - 2. 요청 신호 전송 시간
  - 3. 확인 응답 전파 시간
  - 4. 확인 응답 전송 시간
- 데이터 전송 단계
  - 1. 전파 시간
  - 2. 데이터 전송 시간
- 연결 해제 단계

## 2절. 패킷 교환망

### 패킷 교환망(Packet Switching)

<img src = "https://github.com/BangYunseo/TIL/blob/main/Communication/DataCommunication/Image/ch08/ch08-08-PS.PNG" height="auto"/>

- 패킷
  - 고정 또는 가변길이로 나눔
  - 각 패킷은 다른 패킷과 무관한 취급
  - 길이 : 네트워크 및 패당 프로토콜에 따라 결정
- 자원
  - 예약 필요 X
  - 필요에 따라 할당
- 네트워크 층의 교환망
- 비연결형 망(Connectionless Networks)
- 교환기 : 라우터(Router)
- 패킷 교환망 유형
  - 데이터그램망
  - 가상 회선망

### 데이터그램 망

<img src = "https://github.com/BangYunseo/TIL/blob/main/Communication/DataCommunication/Image/ch08/ch08-09-Rt.PNG" height="auto"/>

- 경로지정 표(Routing table)
  n 각 switch는 destination address를 기반으로 하는 routing table을 갖고 있음
  n Destination address와 그에 해당하는 output port 를 갖고 있음
  n 각 packet의 header에는 destination address를 갖고 있으며 목적지에 도달할 때 까지 변하지 않음
