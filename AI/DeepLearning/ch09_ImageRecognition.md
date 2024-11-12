# Chapter 9. 영상 인식(ImageRecognition)

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

...


#### 보폭(stride)
- 커널을 적용하는 거리
- ex) 보폭이 1인 경우 : 한 번에 1 픽셀씩 이동하며 커널 적용
- ex) 보폭이 2인 경우 : 하나씩 건너뛰며 픽셀에 커널 적용

![]()

#### 패딩(padding)
- 이미지의 가장자리 처리 기법

![]()

##### Valid
- 커널을 입력 이미지 안에서만 움직임

![]()

##### Same

- 입력 이미지의 주변을 특정값(0 OR 이웃값)으로 채움

![]()

#### 필터가 다수일 때의 컨볼루션 레이어

![]()

![]()

#### 풀링(Pooling)
- 서브 샘플링
- 입력 데이터의 크기 줄임

![]()

##### 풀링 장점

- 레이어 크기의 감소로 계산 속도 증가 
- 레이어의 크기 감소 == 신경망 매개변수 감소
  - 즉, 과잉 적합 가능성 감소 
- 공간에서 물체의 이동이 있어도 결과는 불변
  - 즉, 물체의 공간 이동에 둔감 

![]()

![]()

#### 풀링 종류

![]()

##### 최대 풀링
- 컨볼루션처럼 윈도우를 움직여 가장 큰 값만 출력하는 연산

![]()

#### 컨볼루션 신경망 해석

![]()

#### 합성곱 신경망

![]()







