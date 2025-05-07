# Chapter 5. 아날로그 전송(Analog Transmission)

> 1절. 디지털 -> 아날로그 변환
>
> 2절. 아날로그 -> 아날로그 변환

## 1절. 디지털 -> 아날로그 변환

### 디지털 -> 아날로그 변환

- 디지털 데이터 정보를 기반으로 아날로그 신호 특성 중 하나를 바꾸는 과정
- 디지털 데이터(Digital Data)를 아날로그 신호(Analog Signal)로 변환 후 전송

<img src = "https://github.com/BangYunseo/TIL/blob/main/Communication/DataCommunication/Image/ch05/ch05-01-DigitalAnalog.PNG" height="auto"/>

### 디지털 -> 아날로그 변환 유형

|    변환 유형     | 영문 약어 | 영문                            |
| :--------------: | :-------: | :------------------------------ |
|  진폭 편이 변조  |    ASK    | Amplitude Shift Keying          |
| 주파수 편이 변조 |    FSK    | Frequency Shift Keying          |
|  위상 편이 변조  |    PSK    | Phase Shift Keying              |
|  직교 진폭 변조  |    QAM    | Quadrature Amplitude Modulation |

<img src = "https://github.com/BangYunseo/TIL/blob/main/Communication/DataCommunication/Image/ch05/ch05-02-DigitalAnalogType.PNG" height="auto"/>

### 반송파 신호(Carrier Signal)

- 아날로그 전송에서 신호의 기반이 되는 고주파 신호

### 반송파 신호 특성

- 진폭(Amplitude)
- 주파수(Frequency)
- 위상(Phase)

### 변조(Modulation or Shift Keying)

- 반송파 신호의 특성 중 한 가지 이상을 변화시키는 방식

### 디지털 -> 아날로그 변환의 여러 관점

- 대역폭(BandWidth)
- 데이터 요소 대 신호 요소
- 데이터 전송률 대 신호 전송률
  - 비트 전송률(bps) : N, 데이터율, 초당 비트 수
  - 보오율(baud) : S, 신호율, 초당 신호 단위 수
  - r : 하나의 신호 요소에 전달되는 데이터 요소의 수

> 사용 공식 : $S = N × \frac{1}{r}$ baud

- 디지털 데이터의 아날로그 전송 : 보오율은 비트 전송률과 같거나 적음

### 진폭 편이 변조(ASK : Amplitude Shift Keying)

- 신호 요소 생성을 위해 반송파 진폭 변화
- 주파수 & 위상 : 진폭이 변화 시 일정하게 유지
- 잡음(Noise)에 약함
  - noise는 진폭에 많은 영향

<img src = "https://github.com/BangYunseo/TIL/blob/main/Communication/DataCommunication/Image/ch05/ch05-03-ASK.PNG" height="auto"/>

> 수식 정리  
> $B = (1+d) × S$  
> B : 대역폭(Bandwidth)  
> S : 신호율(Signal Rate : Baud Rate)  
> d : 변조 과정 관련 요소(0과 1 사이)  
> $f_c$ : 캐리어 주파수(Carrier Frequency), 대역폭 중간

#### 2진 ASK(Binary ASK, BASK)

<img src = "https://github.com/BangYunseo/TIL/blob/main/Communication/DataCommunication/Image/ch05/ch05-04-BASK.PNG" height="auto"/>

- 디지털 데이터(Digital Data)를 디지털 신호(digital Signal)로 만든 후 캐리어 신호(Carrier Signal)과 곱셈

- 두 가지 전압 사용
- 에너지 소모 감소

  - 하나의 값은 전압 없음
  - 온-오프 변조(OOK : On-Off Keying)
  - 전송 에너지 소비 감소

- 다준위 ASK(Multilevel ASK)
  - 2 Level 이상의 진폭(Amplitude)를 사용하는 ASK

### 주파수 편이 변조(FSK : Frequency Shift Keying)

- 데이터를 나타내기 위해 신호의 주파수를 변화
   데이터 요소가 다른 값을 가지면 주파수를 변화
   최고 진폭과 위상은 일정하게 유지; ASK의 Noise문제 해결
   2진 FSK, 다준위 FSK
- B=(1+d)S + 2Δf, 2Δf는최소(1+d)S 이상임

## 2절. 아날로그 -> 아날로그 변환

###
