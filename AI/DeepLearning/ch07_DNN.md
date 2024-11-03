# Chapter 7. 심층 신경망(DNN : Deep Neural Networks)

> 1절. 심층 신경망 구조
>
> 2절. 활성화 함수
>
> 3절. 손실 함수

## 1절. 심층 신경망 구조

#### 심층 신경망(DNN)

- Deep Neural Networks
- MLP(다층 퍼셉트론)에서 은닉층의 개수 증
- 은닉층을 여러 개 사용(2개 이상)
- MLP의 문제점을 해결한 형태

![MLPDNN](https://github.com/BangYunseo/TIL/blob/main/AI/DeepLearning/Image/ch07/MLPDNN.PNG)

![MLPDNN2](https://github.com/BangYunseo/TIL/blob/main/AI/DeepLearning/Image/ch07/MLPDNN2.PNG)

#### GPU의 도움

- DNN의 학습 속ㄷ도는 상당히 느리고 계산 집약적
  - 학습에 시간과 자원이 많이 소모
- 최근 GPU(Graphic Processor) 기술의 발전으로 GPU가 제공하는 데이터 처리 기능을 딥러닝이 사용

![DNN](https://github.com/BangYunseo/TIL/blob/main/AI/DeepLearning/Image/ch07/DNN.PNG)

#### 은닉층의 역할

- 앞단 : 경계선(edge)과 같은 저급 특징들 추출
- 뒷단 : 코너와 같은 고급 특징들 추출

![HL](https://github.com/BangYunseo/TIL/blob/main/AI/DeepLearning/Image/ch07/HL.PNG)

## 2절. 활성화 함수

#### 그래디언트 소실 문제

- 심층 신경망에서 그래디언트가 전달되다가 점점 0에 가까워지는 현상

  - 시그모이드 활성화 함수로 인해 발생
  - 특성상, 아주 큰 양수나 음수가 입력되면 출력이 포화되어 0이 됨

    ![SF](https://github.com/BangYunseo/TIL/blob/main/AI/DeepLearning/Image/ch07/SF.PNG)

![GP](https://github.com/BangYunseo/TIL/blob/main/AI/DeepLearning/Image/ch07/GP.PNG)

#### 역전파 알고리즘의 복습

![S1](https://github.com/BangYunseo/TIL/blob/main/AI/DeepLearning/Image/ch07/S1.PNG)

#### 활성화 함수 : ReLU 함수

![RF](https://github.com/BangYunseo/TIL/blob/main/AI/DeepLearning/Image/ch07/RF.PNG)

#### 다양한 활성화 함수 변경

![MF](https://github.com/BangYunseo/TIL/blob/main/AI/DeepLearning/Image/ch07/MF.PNG)

## 3절. 손실 함수

#### 손실 함수 선택 문제
