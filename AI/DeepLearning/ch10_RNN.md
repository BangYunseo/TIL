# Chapter 10. 순환 신경망(RNN : Recurrent Neural Networks)

> 1절. 순환 데이터
>

## 1절. 순환 데이터

#### 순차 데이터(시계열 데이터)

- 순서가 있는 데이터
- 순차 데이터 처리를 통해 정확한 예측을 도출하려면 과거의 데이터 정보 필요
- 시간적 순서 / 공간적 순서 모두 가능
- ex) 주식 가격, 텍스트 데이터, 오디오 데이터

##### 응용 분야

![]()

#### 표준 신경망과 순환 신경망
- 1980년 후쿠시마에 의해 소개된 신경망 구조

![]()

#### 컨볼루션 레이어

##### Conv2D()
```Python
import tensorflow as tf
tf.keras.layers.Conv2D(filters, kernel_size, strides=(1, 1),
                       activation=None, input_shape, padding='valid’)
```

- filters : 필터 개수
- kernel_size : 필터 크기
- strides : 보폭
- activation : 유닛 활성화 함수
- input_shape : 입력 배열 형상
- padding : 패딩 방법 선택(Default = "valid")

```Python
 shape = (4, 28, 28, 3)
 x = tf.random.normal(shape)
 y = tf.keras.layers.Conv2D(2, 3, activation='relu', input_shape=shape[1:])(x)
 print(y.shape)

# 출력
# (4, 26, 26, 2)
```

##### MaxPooling2D()

```Python
tf.keras.layers.MaxPooling2D(pool_size=(2, 2), strides=None, padding="valid")
```

- pool_size : 풀링 윈도우의 크기로 정수 또는 2개 정수의 튜플
  - ex) (2, 2)라면 2 x 2 풀링 윈도우에서 최대값 추출
- strides : 보폭, 각 풀링 단계에 대해 풀링 윈도우가 이동하는 거리 지정
- padding : "valid"나 "same" 중 하나
  - valid = 패딩이 없음
  - same = 출력이 입력과 동일한 높이 / 너비 치수를 갖도록 입력의 왼, 오, 위, 아래쪽에 균일하게 패딩

```Python
x = tf.constant([[1., 2., 3.], [4., 5., 6.], [7., 8., 9.]])
 x = tf.reshape(x, [1, 3, 3, 1])
 max_pool_ 2d = tf.keras.layers.MaxPooling2D(pool_size=(2, 2), strides=(1, 1),
 padding='valid')
 print(max_pool_2d(x))
```

- 출력

![]()

#### EX : MNIST 필기체 숫자 인식

```Python
import tensorflow as tf
from tensorflow.keras import datasets, layers, models

(train_images, train_labels), (test_images, test_labels) = datasets.mnist.load_data()
train_images = train_images.reshape((60000, 28, 28, 1))
test_images = test_images.reshape((10000, 28, 28, 1))

# 픽셀 값 0~1로 정규화 
train_images, test_images = train_images / 255.0, test_images / 255.0

model = models.Sequential()

model.add(layers.Conv2D(32, (3, 3), activation='relu', input_shape=(28, 28, 1)))
model.add(layers.MaxPooling2D((2, 2)))                                              # 은닉층 1
model.add(layers.Conv2D(64, (3, 3), activation='relu'))
model.add(layers.MaxPooling2D((2, 2)))                                              # 은닉층 2
model.add(layers.Conv2D(64, (3, 3), activation='relu'))

model.add(layers.Flatten())
model.add(layers.Dense(64, activation='relu'))                                      # n2 = 4
model.add(layers.Dense(10, activation='softmax'))                                   # 0 ~ 9

model.summary()
model.compile(optimizer='adam’, loss='sparse_categorical_crossentropy’, metrics=['accuracy'])
model.fit(train_images, train_labels, epochs=5)

# 출력
#  Epoch 1/5
#  1875/1875 [==============================] - 14s 7ms/step - loss: 0.1414 
# accuracy: 0.9560
#  ...
#  Epoch 5/5
#  1875/1875 [==============================] - 14s 7ms/step - loss: 0.0194 
# accuracy: 0.9940
```

- 출력 결과 예시
![]()
