#  Chapter 0. 신호
> 1절. 디지털 신호 처리(DSP)
>
> 2절. 퓨리에(Fourier)
>
> 3절. 신호

## 1절. 디지털 신호 처리(DSP)
#### 디지털 신호 처리란?
* Digital Signal Processing(DSP)
* 디지털화된 신호를 원하는 방향으로 정보 신호를 수정하거나 개선할 목적으로 알고리즘에 의해 수치적으로 처리
* 일반적으로 아날로그 신호를 디지털화하는 과정에서 이산 신호가 되며 수치화

#### 목적
* 연속적인 실세계 아날로그 측정 후 걸러내고 압축

#### 사용 이유
* 디지털 기기의 대표적 예시 중 하나인 컴퓨터가 상용화되었기 때문
* 수학적 추상화를 통해 일반화 및 새로운 처리 기술 발견을 위해
* 컴퓨터로의 구현이 유연하기 때문
* 애플리케이션은 물리적인 내용, 글을 제공하기 때문(디스플레이)

## 2절. 퓨리에(Fourier)
#### 퓨리에(Fourier)의 사용처
* 통신
* 소리, 음악(CD ROM, 영상)
* 퓨리에 광학
* X-ray 결정학(프로틴 구조, DNA)
* 컴퓨터화 단층 촬영(CT)
* 자기공명영상(MRI)
* 전파천문학

#### 퓨리에(Fourier) 사용 이유
* 주파수를 분리해서 표현하기 위해
    * 즉, Time Domain으로 구성된 그래프를 Frequency Domain에 따른 그래프로 변환하기 위해

![TimeFrequency](https://github.com/BangYunseo/TIL/blob/main/Communication/SignalWithSystem/Image/ch00/TimeFrequency.PNG)

##### 주파수를 분리해서 표현해야 하는 이유
* Time Domain 그래프에서는 어느 수준의 주파수가 높게 출력되는지 확인 불가
* 하지만, Fourier를 통해 변환한 Frequency Domain 그래프에서는 어느 수준의 주파수가 높게 출력되는지 확인 가능

## 3절. 신호
#### 신호란?
* 시간에 대한 함수 $x(t)$

#### 아날로그 신호
* Analog Signal
* Continuous-time Signal
* $x(t)$
* 매개변수(parameter)로 시간 $t$를 사용하며 Time Domain 그래프
* 소괄호를 사용함으로써 연속적인 시간 의미
* $t$를 독립 변수로 사용

![Analog](https://github.com/BangYunseo/TIL/blob/main/Communication/SignalWithSystem/Image/ch00/Analog.PNG)

#### 디지털 신호
* Digital Signal
* Discrete-time Signal
* $x[n]$
* 매개변수(parameter)로 숫자 번호(index)를 사용하는 그래프
* 대괄호를 사용함으로써 불연속적인 시간 의미
* $n$을 독립 변수로 사용
* 그래프마다 $x[n]$에서의 값이 상이할 수 있음
    * 예시
        * A그래프 $x[1]$은 n = 9의 값
        * B 그래프 $x[1]$은 n = 15의 값

![Digital](https://github.com/BangYunseo/TIL/blob/main/Communication/SignalWithSystem/Image/ch00/Digital.PNG)

#### 소리 신호
* 정현파(Sinusoidal)
* 모든 소리 신호는 여러 개의 정현파 합
* 정현파 공식

![Sinusoidal](https://github.com/BangYunseo/TIL/blob/main/Communication/SignalWithSystem/Image/ch00/Sinusoidal.PNG)

##### 주기(Period)
* 1초당 신호 횟수

![Period](https://github.com/BangYunseo/TIL/blob/main/Communication/SignalWithSystem/Image/ch00/Period.PNG)

##### 위상(Phase)
* $t = 0$일 때 시작점과의 차이
* 기호 

![Phase](https://github.com/BangYunseo/TIL/blob/main/Communication/SignalWithSystem/Image/ch00/Phase.PNG)

##### 진폭(Amplitude)
* Magnitude 라고도 부름
* 기호

![Amplitude](https://github.com/BangYunseo/TIL/blob/main/Communication/SignalWithSystem/Image/ch00/Amplitude.PNG)

##### 주파수(Frequency)
* Radians / sec
* 헤르츠(Hertz) : (cycles / sec)

![Frequency](https://github.com/BangYunseo/TIL/blob/main/Communication/SignalWithSystem/Image/ch00/Frequency.PNG)

