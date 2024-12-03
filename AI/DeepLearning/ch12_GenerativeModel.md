# Chapter 12. 생성형 모델(Generative Model)

> 1절. 생성 모델
>
> 2절. 오토 인코더(Auto Encorder)
>
> 3절. GAN(Generative 

## 1절. 생성 모델

#### 생성 모델(Generative Model)

- 훈련 데이터의 규칙성 또는 패턴을 자동으로 발견 및 학습
- 훈련 데이터의 확률 분포와 유사하지만, 새로운 샘플을 생성하는 신경망
- 훈련 데이터들의 잠재 공간 표현 학습
- 학습 종료 후, 잠재 공간에서 랜덤의 한 좌표가 입력되면 대응하는 출력 생성 가능

#### 훈련 데이터 생성 규칙

- 생성 모델이 사실적인 몬드리안 스타일의 그림을 생성할 수 있다고 가정하자.
  - 생성 모델은 몬드리안 스타일의 일반적인 규칙이 학습된 것
 
![GM](https://github.com/BangYunseo/TIL/blob/main/AI/DeepLearning/Image/ch12/GM.PNG)

#### 확률직어니 생성 모델

- 모든 샘플 이미지에 대하여 각 픽셀 위치에서 픽셀값의 평균을 계산
  - 샘플 이미지와 유사한 출력 생성
  - 하지만 고정된 계산일 경우, 생성 모델이 매번 동일한 출력 생성(결정적)

- 생성 모델은 출력에 영향을 미치는 확률적인 무작위 요소 포함
  - 학습이 종료된 후에 입력되는 랜덤 노이즈

#### 분류 모델(discriminative modeling)

- 데이터 $x$ 와 레이블 $y$ 가 주어지면 분류 모델은 x가 어떤 부류에 속하는지 판단

![GMDM](https://github.com/BangYunseo/TIL/blob/main/AI/DeepLearning/Image/ch12/GMDM.PNG)

##### 분류 모델과 생성 모델의 차이

- 분류 모델 : 조건부 확률 $p(y|x)$ 탐색
  - 샘플 $x$ 가 주어진 상태에서 레이블 $y$ 확률 추정
 
- 생성 모델 : 입력 데이터의 확률 분포 $p(x)$ 탐

![GMDM2](https://github.com/BangYunseo/TIL/blob/main/AI/DeepLearning/Image/ch12/GMDM2.PNG)

#### Keras의 함수형 API

- 함수형 API
  - 사용 시 원하는 방식의 객체들 연결 가능
  - ex) 은닉층의 출력을 알고자 할 경우 사용

![KA](https://github.com/BangYunseo/TIL/blob/main/AI/DeepLearning/Image/ch12/KA.PNG)

#### 예제_MNIST 숫자 이미지 처리 신경

![EX1](https://github.com/BangYunseo/TIL/blob/main/AI/DeepLearning/Image/ch12/EX1.PNG)

```Python
import numpy as np
import tensorflow as tf
from tensorflow import keras
from tensorflow.keras import layers

inputs = keras.Input(shape=(784,))               # (1)
dense = layers.Dense(64, activation="relu")      # (2)
x = dense(inputs)                                # (3)
x = layers.Dense(64, activation="relu")(x)       # (4)
outputs = layers.Dense(10)(x)                    # (5)

# (x)의 의미
# tmp = layers.Dense(64, activation="relu")
# x = tmp(x)

model = keras.Model(inputs=inputs, outputs=outputs)

(x_train, y_train), (x_test, y_test) = keras.datasets.mnist.load_data()

x_train = x_train.reshape(60000, 784).astype("float32") / 255
x_test = x_test.reshape(10000, 784).astype("float32") / 255

model.compile(
  loss = keras.losses.SparseCategoricalCrossentropy(from_logits=True),
  optimizer=keras.optimizers.RMSprop(),
  metrics=["accuracy"],
)

history = model.fit(x_train, y_train, batch_size=64, epochs=2, validation_split=0.2)
test_scores = model.evaluate(x_test, y_test, verbose=2)

```

##### Sequential 모델과 함수형 API

![SA](https://github.com/BangYunseo/TIL/blob/main/AI/DeepLearning/Image/ch12/SA.PNG)

## 2절. 오토 인코더(Auto Encorder)

## 3절. GAN(Generative 
