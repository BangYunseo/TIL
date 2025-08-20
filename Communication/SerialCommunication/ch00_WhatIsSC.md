# Chapter 0. 시리얼 통신 개요

> 0절. 기본 용어
>
> 1절. 직렬(Serial) & 병렬(Parallel)
>
> 2절. RS-232
>
> 3절. RS-422
>
> 4절. RS-485

## 0절. 기본 용어

|     용어      |           영문            | 설명                                                                                                         |
| :-----------: | :-----------------------: | :----------------------------------------------------------------------------------------------------------- |
|   보 레이트   |         Baud Rate         | - bit/sec 단위<br>- 초당 전송이 가능한 데이터 비트 수                                                        |
|  데이터 비트  |         Data Bits         | - 통신의 단위 비트 길이를 결정하는 설정<br>- 일반적으로 8 bits<br>=> 확장된 아스키 코드 사용의 목적          |
|  패리티 비트  |        Parity Bits        | - 패리티 오류 검출을 위한 비트<br>- 통신 무결성 체크<br>- 일반적으로 NONE 상태<br>- 오류 검출 시 수정 기능 X |
|   스탑 비트   |         Stop Bits         | -일반적으로 1로 설정<br>- 다음 시작 비트 전송을 위한 시간 할당 역할                                          |
|   흐름 제어   |       Flow Control        | 하드웨어 통신 무결성 보장                                                                                    |
|    동기화     |      Synchronization      | 송신 측에서 보낸 데이터를 수신한 쪽에서도 같은 값으로 인식하기 위해 값을 맞추는 것                           |
|   동기 통신   | Synchronous Communication | 수신자 & 송신자 간 상호 동기를 맞추고자 클럭 신호를 추가하는 통신                                            |
| 통신 프로토콜 |  Communication Protocol   | 서로 다른 기기들 간 데이터 교환을 원활하게 수행하기 위한 표준화 통신 규약                                    |

## 1절. 직렬(Serial) & 병렬(Parallel)

### 직렬(Serial) 통신

- 한 비트씩 순차적으로 전송하는 통신

<img src = "https://github.com/BangYunseo/TIL/blob/main/Communication/SerialCommunication/Image/ch00/ch00-01-SC.PNG" width="80%" height="auto"/>

> 데이터를 일렬 전송<br>=> 전송 속도가 느림<br><br>다만, 더 멀리 전송 가능<br>단순하며 I/O 라인을 아낄 수 있음<br>즉, 비용 절감이 가능

### 직렬(Serial) 통신 장점

- 비교적 적은 전선으로 데이터를 안정적으로 전송

#### 1. 배선이 단순하고 저렴

#### 2. 장거리 데이터 전송 가능

#### 3. 높은 노이즈 저항성

#### 4. 무선 통신 적용 가능

### 병렬(Parallel) 통신

- 별도의 연결로 동시에 전송하는 통신

<img src = "https://github.com/BangYunseo/TIL/blob/main/Communication/SerialCommunication/Image/ch00/ch00-02-PC.PNG" width="80%" height="auto"/>

> 데이터를 한 번에 여러 개로 전송(여러 개의 선로)<br>=> 직렬 통신보다 빠른 속도<br><br>동기화 필수<br>짧은 통신 거리<br>많은 I/O 라인 소모

### 병렬 통신의 한계

#### 1. 하드웨어 복잡성 증가

- 여러 개의 데이터 라인 필요
- 선이 많아지고 회로 복잡성 증가

#### 2. 신호 간섭 문제

- 데이터 라인 증가
- 신호 간섭(CrossTalk) 발생 가능성 상승

#### 3. 장거리 전송 부적합

- 거리가 길어질수록 신호 약화
- 타이밍 차이(skew) 발생
  - 동기화가 어려움

### 직렬 VS 병렬

|         특징         |     직렬(Serial)      |    병렬(Parallel)     |
| :------------------: | :-------------------: | :-------------------: |
|      전송 속도       |         느림          |    상대적으로 빠름    |
|    통신 선로 개수    |         1 개          |        여러 개        |
| 클럭 당 전송 비트 수 |        1 bits         |  통신 선로 개수 만큼  |
|         비용         |         적음          |         높음          |
|     채널 간 간섭     |           X           |         존재          |
|  시스템 업그레이드   |         쉬움          |        어려움         |
|      전송 모드       | 전이중<br>Full-Duplex | 반이중<br>Half-Duplex |
|      전송 거리       |        먼 거리        |       짧은 거리       |
|    고 주파수 동작    |   상대적으로 효과적   |       덜 효과적       |

## 2절. RS-232C

### RS-232C

- 미국 EIA(에너지 관리청)에 의해 정해진 표준 인터페이스
- 직렬 이진 데이터의 교환을 하는 데이터 터미널 장비와 데이터 통신 장비 간 인터페이스 제반 사항 규정
- 일대일 통신(1 : 1)
- 5V와 0V 사이를 움직이며 최대 전압은 5V
- 0.4V의 노이즈 마진을 가진 TTL 통신에 비해 10V ~ -10V를 움직여 2V의 노이즈 마진을 가지므로 비교적 노이즈에 강함
- 통신 거리는 일반적으로 15m
  - 통신 속도가 빨라질 경우 거리가 짧아짐
  - 통신 속도가 느릴 경우 좀 더 멀어짐
  - 선로가 좋을 경우 먼 거리에서 통신 가능
- 서로 주고 받는 신호로 연결

### RS-232C 용어 분해

- Recommended Standard(권장 표준)
- 232(규격 식별 번호)
- C(버전)

### RS-232C 통신

- 해당 통신을 위한 3개의 선
  - TXD(송신)
  - RXD(수신)
  - GND(접지)

<img src = "https://github.com/BangYunseo/TIL/blob/main/Communication/SerialCommunication/Image/ch00/ch00-03-SCpin.PNG" width="80%" height="auto"/>

| PIN # |  방향  | 명칭 |        영문         | 설명                                                                           |
| :---: | :----: | :--: | :-----------------: | :----------------------------------------------------------------------------- |
|   1   | Input  |  CD  |   Carrier Detect    | 해당 핀이 논리 0이 되면 해당 장치가 보낸 데이터를 상대 장치가 수신했음을 인지  |
|   2   | Input  | RxD  |    Received Data    | 데이터 수신 핀                                                                 |
|   3   | Output | TxD  |  Transmitted Data   | - 데이터 전송 핀<br>- 이 장치가 대기 상태인 경우 논리 1 출력                   |
|   4   | Output | DTR  | Data Terminal Ready | 해당 핀이 논리 0을 출력하면 상대 장치에게 데이터 송신 준비가 됐음을 알림       |
|   5   |   .    | GND  |    Signal Ground    | 접지                                                                           |
|   6   | Input  | DSR  |   Data Set Ready    | 해당 핀이 논리 0이 되면 상대 장치가 데이터를 송신할 준비가 됐음을 인지         |
|   7   | Output | RTS  |   Request TO Send   | 해당 핀에 논리 0을 출력하면 상대방 장치에게 데이터를 수신할 준비가 됐음을 알림 |
|   8   | Input  | CTS  |    Clear TO Send    | 해당 핀이 논리 0이 되면 상대 장치가 데이터를 수신할 준비가 됨을 인지           |
|   9   | Input  |  RI  |   Ring Indicator    | 해당 핀이 논리 0이 되면 모뎀에 통신 연결 요구의 발생을 인지                    |

## 3절. RS-422

### RS-422

<img src = "https://github.com/BangYunseo/TIL/blob/main/Communication/SerialCommunication/Image/ch00/ch00-04-SCpin2.PNG" width="80%" height="auto"/>

- 차동 신호 이용 통신
- 각 신호 종류 당 <strong>2개의 신호선</strong>을 쓰는 것이 중요
  - 차동 신호 : 두 신호 간 차를 이용한 것으로 노이즈에 강함
  - ex) 전선 2가닥을 꼬아서 각각 10V, 5V를 준 상태
    - 노이즈가 3V라면?
    - 13 - 7 = 5V
    - 즉, 차잇값이 5V로 동일
    - 노이즈에 영향이 적거나 없음

## 4절. RS-485

(여기부터 작성)

## 정리 : 통신 규격 사양
