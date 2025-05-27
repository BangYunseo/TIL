# Chapter 6. 대역폭 활용(BandWidth Utilization) : 다중화와 스펙트럼 확장(Multiplexing and Spreading)

> 0절. 대역폭 활용
>
> 1절. 다중화
>
> 1절 - 1. FDM
>
> 1절 - 2. WDM
>
> 2절. 대역 확산 방식

## 0절. 대역폭 활용

### 대역폭 활용

- 특정 목적을 위해 이용 가능 대역폭을 효율적으로 사용

|         달성 목표          | 사용 요소                         |
| :------------------------: | :-------------------------------- |
|            효율            | 다중화(Multiplexing)              |
| 프라이버시 & 방해전파 방지 | 스펙트럼 확장(Spectrum Spreading) |

## 1절. 다중화

### 다중화(Multiplexing)

- 단일 링크로 여러 신호를 동시에 전송하는 기술
- n개의 장치가 단일 링크 대역폭 공유

| 상황 예시                                   |                     결과                     |
| :------------------------------------------ | :------------------------------------------: |
| 링크 대역폭 > 연결된 장치들이 필요한 대역폭 |              여분의 대역폭 낭비              |
| 매체 대역폭 > 두 장치가 필요한 대역폭       | 항상 n개 장치가 단일 링크의 대역폭 공유 가능 |

### 다중화 시스템 기본 형식

<img src = "https://github.com/BangYunseo/TIL/blob/main/Communication/DataCommunication/Image/ch06/ch06-01-BasicMultiplexing.PNG" height="auto"/>

- 단일 데이터 링크를 통해 여러 개의 신호를 동시에 전송하기 위한 기술

| 구성 요소  | 영문 약어 |     영어      | 설명                                                                                 |
| :--------: | :-------: | :-----------: | :----------------------------------------------------------------------------------- |
|  다중화기  |    MUX    |  Multiplexer  | 전송 스트림을 단일 스트림으로 결합(MTO : Many To One)                                |
| 다중복구기 |   DEMUX   | Demultiplexer | 스트림을 각각의 요소로 분리(OTM : One To Many)<br>전송 스트림을 해당 수신장치에 전달 |
|    링크    |     .     |     Link      | 물리적인 경로                                                                        |
|    채널    |     .     |    Channel    | 한 쌍의 장치 간 전송을 위한 하나의 경로                                              |

### 다중화 범주

<img src = "https://github.com/BangYunseo/TIL/blob/main/Communication/DataCommunication/Image/ch06/ch06-02-MultiplexingType.PNG" height="auto"/>

## 1절 - 1. FDM

### 주파수 분할 다중화(FDM : Frequency Division Multiplexing)

<img src = "https://github.com/BangYunseo/TIL/blob/main/Communication/DataCommunication/Image/ch06/ch06-03-FDM.PNG" height="auto"/>

- 신호들을 합성하는 아날로그 다중화 기술
- 전송되어야 하는 신호들의 대역폭 합보다 링크의 대역폭이 클 때 적용 가능
- 전송될 신호는 서로 다른 주파수의 Carrier Frequency로 변환
  - 변환된 신호들을 합쳐 하나의 Composite Signal로 만든 후 전송
- 신호가 겹치지 않도록 보호 대역(Guard Band)만큼 간격 필요

### 다중화 과정

<img src = "https://github.com/BangYunseo/TIL/blob/main/Communication/DataCommunication/Image/ch06/ch06-04-MP.PNG" height="auto"/>

1. 각 소스는 유사한 주파수 범위의 신호 생성
   - 신호들은 다중화기 내부에서 각기 서로 다른 반송 주파수로 변조(f1, f2, f3)
2. 생성된 변조 신호들은 하나의 복합 신호로 결합
   - 신호 수용 가능한 대역폭을 가진 매체 링크로 전송

### 다중화 복구 과정(Demultiplexing)

<img src = "https://github.com/BangYunseo/TIL/blob/main/Communication/DataCommunication/Image/ch06/ch06-05-DM.PNG" height="auto"/>

- 필터를 사용해 다중화된 신호를 구성요소의 신호들로부터 분리
- 개별적 신호를 넘겨받은 복조기는 반송파로부터 신호만 분리 후 수신 장치로 전달

### 아날로그 반송파 구조

<img src = "https://github.com/BangYunseo/TIL/blob/main/Communication/DataCommunication/Image/ch06/ch06-06-FDM2.PNG" height="auto"/>

- 전화 회사에서 사용하는 방식
- 낮은 대역폭 회선들을 높은 대역폭 회선들로 다중화
- 아날로그 회선에서 FDM 사용

### FDM 응용

|      종류       | 응용 형태                                                                                          |
| :-------------: | :------------------------------------------------------------------------------------------------- |
|     라디오      | AM : 530 ~ 1,700 kHz, 방송국 당 10kHz<br>FM : 88 ~ 108 MHz, 방송국 당 200kHz                       |
|       TV        | 54 MHz ~ 88 MHz(ch.2 - 6), 174 MHz ~ 216 MHz(ch.7 - 13)<br>채널 당 6 MHz                           |
| 1 세대 이동전화 | FDM의 BW : 10 \* BW / 음성 신호의 BW : 3 kHz<br>사용자마다 60 kHz<br>수신 : 30 kHz / 발신 : 30 kHz |

## 1절 - 2. WDM

### 파장 분할 다중화(WDM : Wavelength Division Multiplexing)

<img src = "https://github.com/BangYunseo/TIL/blob/main/Communication/DataCommunication/Image/ch06/ch06-07-WDM.PNG" height="auto"/>

- 광섬유 신호 조합을 위한 아날로그 다중화 기법
  - 광 == 빛 채널 이용 : 빛으로 된 신호 전송
- 광섬유
  - 고속 데이터 전송률 이용을 위해 설계
  - 데이터 전송률 : 금속 전송 매체에 비해 높음
- Multiple light source 사용 => 하나의 signal light로 혼합(prism 사용)
- 개념적으로 FDM과 동일

<img src = "https://github.com/BangYunseo/TIL/blob/main/Communication/DataCommunication/Image/ch06/ch06-08-prism.PNG" height="auto"/>

- 다중 빛 소스를 단일 빛으로 결합
- 단일 빛은 다중 빛 소스로 분리

## 1절 - 3. TDM

### 동시 시분할 다중화(TDM : Time Division Multiplexing)

<img src = "https://github.com/BangYunseo/TIL/blob/main/Communication/DataCommunication/Image/ch06/ch06-09-TDM.PNG" height="auto"/>

- 여러 개의 저속 채널을 하나의 고속 채널로 조합하는 디지털 다중화 기법
  - 동기식 TDM
  - 통계식 시분할 다중화
- 높은 링크 대역폭을 여러 연결이 공유하는 디지털 처리 방식
- 다른 발신지로부터 디지털 데이터를 하나의 시간 공유 링크로 통합

#### 동기식 TDM

<img src = "https://github.com/BangYunseo/TIL/blob/main/Communication/DataCommunication/Image/ch06/ch06-10-ATDM.PNG" height="auto"/>

- 시간 틈새(time-slot)와 프레임(frame)
- Time slot
  - 여러 개를 Frame 단위로 group : 하나의 Frame 형성
  - duration : T/n
  - n 개의 input : 최소한 n time slot으로 frame 구성

### 끼워넣기(Interleaving)

<img src = "https://github.com/BangYunseo/TIL/blob/main/Communication/DataCommunication/Image/ch06/ch06-11-Interleaving.PNG" height="auto"/>

- 하나는 다중화기 쪽에서 다른 하나는 다중화 복구 장치 쪽에서 매우 빠르게 도는 교환기
  - 일정한 속도로 회전하는 switch와 동일한 개념
- 교환기가 연결 앞에서 열리고 연결이 경로에 한 단위를 전송할 기회를 획득하는 과정
- 일정한 순서, 일정한 rate로 데이터 전송
- 비어있는 time slot 발생

### 빈 틈새(Empty Slots)

<img src = "https://github.com/BangYunseo/TIL/blob/main/Communication/DataCommunication/Image/ch06/ch06-12-Es.PNG" height="auto"/>

- 동기식 TDM은 효율적 X
- 발신자가 전송할 데이터가 없으면 빈 틈새 생성

### 데이터 전송률 관리 : 입력 측 데이터율이 상이한 경우 해결 방법

#### 1. 다단계 다중화(Multilevel Multiplexing)

<img src = "https://github.com/BangYunseo/TIL/blob/main/Communication/DataCommunication/Image/ch06/ch06-13-MM.PNG" height="auto"/>

- 입력 데이터 전송률이 다른 값들에 비해 정수 배만큼 빠를 경우 사용하는 기술

#### 2. 다중-틈새 할당(Multiple-Slot Allocation)

<img src = "https://github.com/BangYunseo/TIL/blob/main/Communication/DataCommunication/Image/ch06/ch06-14-MA.PNG" height="auto"/>

- 단일 입력 회선에 1개보다 많은 틈새 할당

#### 3. 펄스 채워 넣기(Pulse Stuffing)

<img src = "https://github.com/BangYunseo/TIL/blob/main/Communication/DataCommunication/Image/ch06/ch06-15-PS.PNG" height="auto"/>

- 가장 높은 데이터율의 입력 회선을 주 데이터율로 설정
- 낮은 데이터율의 입력 회선에 공 비트 끼워넣기
  - 비트 패딩
  - 비트 채워 넣기

### 프레임 동기화(Frame Synchronization)

- 다중기와 다중화 복구 장치 사이 동기를 맞추는 것

(여기부터 재작성!)
