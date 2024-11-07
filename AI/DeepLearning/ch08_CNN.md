# Chapter 8. 컨볼루션 신경망(CNN : Convolution Neural Networks)

> 1절. 컨볼루션 신경망
>
> 2절.

## 1절. 컨볼루션 신경망

#### 컨볼루션 신경망(CNN)

- Convolution Neural Networks
- 2차원(특정 부분들의 특징들을 추출하여 탐색)
- 하위 레이어의 노드들과 상위 레이어의 노드들이 부분적 연결

![CNN](https://github.com/BangYunseo/TIL/blob/main/AI/DeepLearning/Image/ch08/CNN.PNG)

##### 네오코그니트론(Neocognitron)
- 1980년 후쿠시마에 의해 소개된 신경망 구조

![Neo](https://github.com/BangYunseo/TIL/blob/main/AI/DeepLearning/Image/ch08/Neo.PNG)

#### 컨볼루션 신경망 중요성
- 신경망 구조 중 가장 강력한 성능을 보여주는 신경망 중 하나
- 2차원 형태의 입력을 처리하기에 이미지 처리에 적합
- 신경망의 각 레이어에서 일련의 필터 이미지 적용

#### 컨볼루션 신경망 구조

![CNNS](https://github.com/BangYunseo/TIL/blob/main/AI/DeepLearning/Image/ch08/CNNS.PNG)

- 여러 레이어의 연결을 통한 구조
  
- 입력층
- 특징맵(feature map) : 입력층에서 컨볼루션 연산을 통해 특징 추출
- 풀링(Pooling) 연산 : 입력의 차원 감소
- 컨볼루션 레이어와 풀링 레이어 반복
- 물체 인식 : 추출된 특징을 바탕의 전통적인 분류 신경망 존재

#### 컨볼루션 연산

- 주변 화소값들 중 가중치를 곱해 더한 후 새로운 화소 값으로 하는 연산

![CA](https://github.com/BangYunseo/TIL/blob/main/AI/DeepLearning/Image/ch08/CA.PNG)

![CA2](https://github.com/BangYunseo/TIL/blob/main/AI/DeepLearning/Image/ch08/CA2.PNG)

##### 컨볼루션의 구체적 예시

![CAex1](https://github.com/BangYunseo/TIL/blob/main/AI/DeepLearning/Image/ch08/CAex1.PNG)

![CAex2](https://github.com/BangYunseo/TIL/blob/main/AI/DeepLearning/Image/ch08/CAex2.PNG)

#####
