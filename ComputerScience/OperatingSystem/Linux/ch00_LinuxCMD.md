# Chapter 0. 딥러닝(DeepLearning)

> 1절. 서버
>
> 2절. 리눅스 서버 접속 방법

## 1절. 서버

#### 서버 접속

- 클라이언트 / 서버 구조

![CSA](https://github.com/BangYunseo/TIL/blob/main/OperatingSystem/Linux/Image/ch00/CSA.PNG)

#### CPU

- CPU(Central Processing Unit)
  - 입력받은 명령을 해석 / 연산 후 이를 통해 결과 값을 출력 장치로 전달하는 컴퓨터의 주요 부품
- CPU의 성능 지표
  - 1. 클럭(동작속도)의 수치
  - 2. 코어(핵습 회로)의 수
  - 3. 캐시 메모리(임시 저장소)의 용량
- 클럭 수치가 높으면 단일 작업을 빠르게 처리하는데 유리
- 코어의 수가 많을 경우 작업 효율 상승
  - 멀티 태스킹(다중 작업)을 할 경우
  - 멀티코어 연산에 최적화된 프로그램을 구동할 경우
  - 캐시 메모리가 넉넉할 경우
  - 덩치가 큰 프로그램을 구동하거나 자주 하는 작업을 반복처리할 경우

#### GPU

- 최초 목적
  - 병렬 연산에 특화된 구조를 통한 높은 3D 그래픽 처리
- 최근 목적
  - 그래픽 처리 뿐 아니라 이외의 범용 작업에도 GPU의 처리 능력을 보태는 'GPGPU(General Purpose computing on Graphics Processing Units)' 기술 발전
- GPU 성능 기준은 CPU와 동일

#### CPU와 GPU 내부 구조 차이

- CPU

![CPU](https://github.com/BangYunseo/TIL/blob/main/OperatingSystem/Linux/Image/ch00/CPU.PNG)

    * 명령어가 입력된 순서대로 데이터를 처리하는 직렬(순차) 처리 방식
    * 내부 면적의 절반 이상이 캐시로 채워져 있기 때문에 GPU에 비해 상대적으로 ALU(Arithmetic Logic Unit)가 차지할 수 있는 공간이 작음
    * CPU는 고정소수점 데이터를 많이 사용하는 문서 작성 등 일상 생활의 작업을 빠르게 할 수 있도록 설계

- GPU

![GPU](https://github.com/BangYunseo/TIL/blob/main/OperatingSystem/Linux/Image/ch00/GPU.PNG)

    * 여러 명령을 동시에 처리하는 병렬 처리 방식에 특화된 구조
    * 캐시 메모리 비중이 크지 않고 연산을 할 수 있는 ALU 개수 다수
    * 1개의 코어에 수백, 수천 개의 ALU 장착
    * GPU는 CPU로는 시간이 많이 소요되어야 하는 3D 그래픽 작업 등을 빠르게 수행하도록 설계

#### GPU vs CPU vs TPU

- CPU vs GPU

![GPU](https://github.com/BangYunseo/TIL/blob/main/OperatingSystem/Linux/Image/ch00/CG.PNG)

- TPU
  - Tensor Processing Unit 약어 TPU
  - 기계 학습을 위해 특별히 개발
  - Google의 오픈 소스 기계 학습 프레임 워크인 TensorFlow를 위해 맞춤화된 맞춤형 내장 회로
  - 2015년부터 Google 데이터 센터에서 전력 공급
    - 그럼에도 불구하고 Google은 여전히 다른 유형의 기계학습에 CPU와 GPU를 사용

## 2절. 리눅스 서버 접속 방법

#### 윈도우 커맨드 프로그램을 이용한 서버 접속
