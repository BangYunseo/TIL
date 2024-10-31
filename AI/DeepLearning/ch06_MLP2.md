# Chapter 6. 다층 퍼셉트론(MLP : MutiLayer Perceptron)- 2

> 1절. TensorFlow
>
> 2절. Keras
>
> 3절.

## 1절. TensorFlow

#### 텐서플로우(TensorFlow)

- 딥러닝 프레임워크의 일종
- 내부적으로 C/C++로 구현
- 파이썬을 비룻하여 여러 가지 언어에서 접근할 수 있도록 인터페이스를 제공

![Tensor](https://github.com/BangYunseo/TIL/blob/main/AI/DeepLearning/Image/ch06/Tensor.PNG)

#### 텐서플로우 구조

![TensorSturucture](https://github.com/BangYunseo/TIL/blob/main/AI/DeepLearning/Image/ch06/TensorSturucture.PNG)

- C++ 커널을 Python 으로 한 번 래핑

#### Tensor

- 다차원 넘파이 배열
- 데이터(실수)를 저장하는 컨테이너
- 배열의 차원은 축(axis)

##### 3차원 텐서 생성

```Python
import numpy as np

x = np.array([[[0, 1, 2, 3, 4], [5, 6, 7, 8, 9]], [[10, 11, 12, 13, 14], [15, 16, 17, 18, 19]], [[20, 21, 22, 23, 24], [25, 26, 27, 28, 29]],])

x.ndim
# 3

x.shape 
# (3, 2, 5)
```

![img2](https://github.com/BangYunseo/TIL/blob/main/AI/DeepLearning/Image/ch06/img2.png)

#### 텐서의 속성

- 텐서의 차원(축의 개수) : 텐서에 존재하는 축의 개수 / 3차원 텐서에는 3개의 축이 있으며 ndim 속성
- 형상(Shape) : 텐서의 각 축으로 얼마나 데이터가 있는지를 파이썬 튜플로 표현
- 데이터 타입(Data Type) : 텐서 요소의 자료형

## 2절. Keras

#### 케라스(Keras)

- 파이썬으로 작성된 고수준 딥러닝 API
- 여러 가지 백엔드를 선택 가능(가장 많이 선택되는 백엔드는 텐서플로우)
- 쉽고 빠른 프로토타이핑 가능
- 피드포워드 신경망, 컨볼루션 신경망, 순환 신경망 등 여러 가지 조합 지원
- CPU 및 GPU에서 원활하게 실행

#### 딥러닝 프레임워크

![Framework](https://github.com/BangYunseo/TIL/blob/main/AI/DeepLearning/Image/ch06/Framework.PNG)

#### 신경망 작성(by keras)

- 케라스의 핵심 데이터 구조는 모델(model)
- 레이어 구성 방법
- 가장 간단한 모델 유형은 Sequential 선형 스택 모델
- Sequential 모델은 레이어를 선형으로 쌓을 수 있는 신경망 모델

![PerceptronByKeras](https://github.com/BangYunseo/TIL/blob/main/AI/DeepLearning/Image/ch06/PerceptronByKeras.PNG)

#### 실습 : XOR를 학습하는 MLP

- 구조

![XOR](https://github.com/BangYunseo/TIL/blob/main/AI/DeepLearning/Image/ch06/XOR.PNG)

- 훈련 데이터

![TrainData](https://github.com/BangYunseo/TIL/blob/main/AI/DeepLearning/Image/ch06/TrainData.PNG)

- 모델 생성 코드

```Python
model = tf.keras.models.Sequential()
# Sequential 모델 생성

model.add(tf.keras.layers.Dense(units = 2, input_shape = (2,), activation = 'sigmoid'))  # 유닛 1 : 은닉층

# 은닉층이 하나 더 생겼을 경우 아래 코드 작성
# model.add(tf.keras.layers.Dense(units = 2, activation = 'sigmoid'))

model.add(tf.keras.layers.Dense(units = 1, activation='sigmoid'))                        # 유닛 2 : 출력층
# Sequential 모델에 add() 함수를 이용하여 필요한 레이어 추가

model.compile(loss='mean_squared_error', optimizer=keras.optimizers.SGD(lr = 0.3))
# compile() 함수 호출을 통한 Sequential 모델 컴파일
# 사용 학습법에 따라 성능 차이 존재
```

- 모델 테스트 코드
```Python
model.fit(X, y, batch_size=1, epochs=10000)
# fit() 호출을 통한 학습 수행

print(model.predict(X))
# 모델 테스트
```

#### 케라스 사용 방법

##### 1) Sequential 모델 생성 후 모델에 필요한 레이어 추가

```Python
model = Sequential()
model.add(Dense(units=2, input_shape=(2,), activation='sigmoid')) 
model.add(Dense(units=1, activation='sigmoid')) 
```

![Seq](https://github.com/BangYunseo/TIL/blob/main/AI/DeepLearning/Image/ch06/Seq.png)

##### 2) 함수형 API 사용

```Python
inputs = Input(shape=(2,))                         # 입력층
x = Dense(2, activation="sigmoid")(inputs)         # 은닉층 1
prediction = Dense(1, activation="sigmoid")(x)     # 출력층

model = Model(inputs=inputs, outputs=prediction)
```

![API](https://github.com/BangYunseo/TIL/blob/main/AI/DeepLearning/Image/ch06/API.png)

##### 3) Model 클래스 상속 후 클래스 정의

```Python
class SimpleMLP(Model):

  def __init__(self, num_classes):            # 생성자 작성
    super(SimpleMLP, self).__init__(name='mlp')
    self.num_classes = num_classes

    self.dense1 = Dense(32, activation='sigmoid')
    self.dense2 = Dense(num_classes, activation='sigmoid')

  def call(self, inputs):                     # 순방향 호출을 구현 
    x = self.dense1(inputs)
    return self.dense2(x)

model = SimpleMLP()
model.compile(...)
model.fit(...)
```

#### Keras를 이용한 MNIST 숫자 인식

![MNIST](https://github.com/BangYunseo/TIL/blob/main/AI/DeepLearning/Image/ch06/MNIST.png)

- 입력 : 784(28 * 28)
- 출력 : 10(0 ~ 9)

#### 숫자 데이터 관리

##### 숫자 데이터 불러오기

- 28 * 28로 60000개의 이미지 존재

```Python
import matplotlib.pyplot as plt
import tensorflow as tf

(train_images, train_labels), (test_images, test_labels) = tf.keras.datasets.mnist.load_data()
```

##### 숫자 데이터 표시

```Python
train_images.shape
# (60000, 28, 28)

train_label
# array([5, 0, 4, ..., 5, 6, 8], dtype=uint8)

test_images.shape
# (10000, 28, 28)

plt.imshow(train_images[0], cmap="Greys")
```

![img](https://github.com/BangYunseo/TIL/blob/main/AI/DeepLearning/Image/ch06/img.png)

##### 신경망 모델 구축

```Python
```

![MNISTmodel](https://github.com/BangYunseo/TIL/blob/main/AI/DeepLearning/Image/ch06/MNISTmodel.png)

#### 컴파일 단계
- 손실 함수(Loss Function) : 신경망의 출력과 정답 간의 오차를 계산하는 함수
- 옵티마이저(Optimizer) : 손실 함수를 기반으로 신경망의 파라미터(매개 변수)를 최적화하는 알고리즘
- 지표(Metric) : 훈련과 테스트 과정에서 사용되는 척도

```Python
model.compile(optimizer = 'rmsprop', loss = 'mse', metrics = ['accuracy'])
```

#### 데이터 전처리 과정

##### 데이터 전처리

```Python
train_images = train_images.reshape((60000, 784))
train_images = train_images.astype('float32') / 255.0

test_images = test_images.reshape((10000, 784))
test_images = test_images.astype('float32') / 255.0
```

- 데이터를 255로 나눈 후 축소(정규화)
- 0~1 범위의 실수로 교체하는 과정

![DP](https://github.com/BangYunseo/TIL/blob/main/AI/DeepLearning/Image/ch06/DP.png)

##### 정답 레이블 형태 변경(원핫 인코딩)
```Python
train_labels = tf.keras.utils.to_categorical(train_labels)
test_labels = tf.keras.utils.to_categorical(test_labels)
```

![Incoding](https://github.com/BangYunseo/TIL/blob/main/AI/DeepLearning/Image/ch06/Incoding.png)

##### 학습

```Python
model.fit(train_images, train_labels, epochs = 5, batch_size = 128)

# Epoch 1/5
# 469/469 [==============================] - 2s 3ms/step - loss: 0.0158 - accuracy: 
# 0.9168
# ...
# Epoch 5/5
# 469/469 [==============================] - 2s 3ms/step - loss: 0.0027 - accuracy: 
# 0.9867
```

- Loss값은 감소, accuracy는 증가

##### 