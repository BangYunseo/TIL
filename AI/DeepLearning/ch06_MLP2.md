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

- 모델 코드

```Python
model = tf.keras.models.Sequential()
# Sequential 모델 생성

model.add(tf.keras.layers.Dense(units = 2, input_shape = (2,), activation = 'sigmoid'))  # 유닛 1 : 은닉층
model.add(tf.keras.layers.Dense(units = 1, activation='sigmoid'))                    # 유닛 2 : 출력층
# Sequential 모델에 add() 함수를 이용하여 필요한 레이어 추가

model.compile(loss='mean_squared_error', optimizer=keras.optimizers.SGD(lr = 0.3))
# compile() 함수 호출을 통한 Sequential 모델 컴파일

model.fit(X, y, batch_size=1, epochs=10000)
# fit() 호출을 통한 학습 수행

print(model.predict(X))
# 모델 테스트
```

#### 케라스 사용 방법

##### Sequential 모델 생성 후 모델에 필요한 레이어 추가

##### 함수형 API 사용

##### Model 클래스 상속 후 클래스 정의
