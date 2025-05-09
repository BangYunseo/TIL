# Chapter 6. 대역폭 활용(BandWidth Utilization) : 다중화와 스펙트럼 확장(Multiplexing and Spreading)

> 0절. 대역폭 활용
>
> 1절. 다중화
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

### 주파수 분할 다중화(FDM : Frequency Division Multiplexing)

- 신호들을 합성하는 아날로그 다중화 기술
