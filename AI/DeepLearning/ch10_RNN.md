# Chapter 10. 순환 신경망(RNN : Recurrent Neural Networks)

> 1절. 순환 데이터
>
> 2절. 순환 신경망
>
> 3절. 순환 신경망 유형
>
> 4절. 역전파 방향향


## 1절. 순환 데이터

#### 순차 데이터(시계열 데이터)

- 순서가 있는 데이터
- 순차 데이터 처리를 통해 정확한 예측을 도출하려면 과거의 데이터 정보 필요
- 시간적 순서 / 공간적 순서 모두 가능
- ex) 주식 가격, 텍스트 데이터, 오디오 데이터

##### 응용 분야

![RNNEX](https://github.com/BangYunseo/TIL/blob/main/AI/DeepLearning/Image/ch10/RNNEX.PNG)

#### 표준 신경망과 순환 신경망

##### 순환 신경망(RNN : Recurrent Neural Network)

- 표준 신경망의 구조를 데이터가 잘 처리되게끔 변경한 신경망
- 표준 신경망 : 일부만 예측 가능 / 멀리 떨어진 과거의 데이터는 희미

##### 예시 : 빈칸 예측 문제

- "난 주말이면 영화를 보기 위해 우리 동네의 \_\_\_\_에 간다."

-> 이전 단어로부터 새로운 단어 예측

#### 순환 신경망 기능

- 가변 길이 입력 처리 가능
- 장기 의존성 추적 가능
- 순서에 대한 정보 유지
- 시퀀스 전체의 파라미터 공유 가능

#### 순환 데이터

- 본격적으로 순환 신경망을 학습시키는 데 사용되는 데이터
- 순환 신경망 학습을 위해 데이터를 일정 길이로 잘라서 여러 훈련 샘플 생성

##### 순환 데이터 예시

1. 일정한 길이(윈도우 크기 = 3)로 자른 후 여러 개의 훈련 샘플 생성

![window3](https://github.com/BangYunseo/TIL/blob/main/AI/DeepLearning/Image/ch10/window3.PNG)

2. 전체 데이터를 다음과 같이 크기가 3인 샘플과 정답으로 분리

![res](https://github.com/BangYunseo/TIL/blob/main/AI/DeepLearning/Image/ch10/res.PNG)

#### 예제 : 데이터 다운 후 그래프 표현

```Python
# 라이브러리 포함
import FinanceDataReader as fdr
import numpy as np
import matplotlib.pyplot as plt

# 삼성전자 코드 = '005930', 2020년 데이터부터 다운로드
samsung = fdr.DataReader('005930', '2020')

# 시작가격
seq_data = (samsung[['Open']]).to_numpy() # 선형 그래프
plt.plot(seq_data, color = 'blue')
plt.title("Samsung Electronics Stock Price")
plt.xlabel("days")
plt.xlabel("")
plt.show()
```

- 결과 출력

![samsung](https://github.com/BangYunseo/TIL/blob/main/AI/DeepLearning/Image/ch10/samsung.PNG)

##### 샘플화

```Python
# 라이브러리 포함
import FinanceDataReader as fdr
import numpy as np
import matplotlib.pyplot as plt

# 삼성전자 코드 = '005930', 2020년 데이터부터 다운로드
samsung = fdr.DataReader('005930', '2020')

# 시작가격
seq_data = (samsung[['Open']]).to_numpy() # 선형 그래프
plt.plot(seq_data, color = 'blue')
plt.title("Samsung Electronics Stock Price")
plt.xlabel("days")
plt.xlabel("")
plt.show()

seq_data = (samsung[['Open']]).to_numpy()
def make_sample(data, window):
  train = []                                   # 공백 리스트 생성
  target = []
  for i in range(len(data) - window):          # 데이터의 길이만큼 반복(0 ~ len(data) - window)
    train.append(data[i : i + window])         # i부터 (i+window-1) 까지를 저장
    target.append(data[i + window])            # (i+window) 번째 요소는 정답
  return np.array(train), np.array(target)     # 훈련 샘플과 정답 레이블을 반환

X, y = make_sample(seq_data, 7)                # 윈도우 크기 = 7
print(X.shape, y.shape)                        # 넘파이 배열의 형상 출력
print(X[0], y[0])                              # 첫 번째 샘플 출력

# 출력 결과
#
# (284, 7, 1) (284, 1)      # Rank = 3, Rank = 2 (1 생략 불가)
# [[55500]
# [56000]
# [54900]
# [55700]
# [56200]
# [58400]
# [58800]] [59600]
```

## 2절. 순환 신경망(RNN)
#### 순환 신경망의 구조

![RNNStructure](https://github.com/BangYunseo/TIL/blob/main/AI/DeepLearning/Image/ch10/RNNStructure.PNG)

#### 피드-포워드 신경망(Feed-Forward Neural Network)과 RNN

![FFNNRNN](https://github.com/BangYunseo/TIL/blob/main/AI/DeepLearning/Image/ch10/FFNNRNN.PNG)

- 피드-포워드 신경망 : 여태까지 배웠던 신경망

#### 단어 예측 RNN

![PredictWord](https://github.com/BangYunseo/TIL/blob/main/AI/DeepLearning/Image/ch10/PredictWord.PNG)

#### 은닉 상태, 입력 벡터, 출력 벡터

- 은닉 상태 : 은닉층
- 입력 벡터 : 입력층
- 출력 벡터 : 출력층

> ex) 주가 예측 신경망에서 지난 3일치의 데이터로 다음 날의 주가를 예측한다면 입력 벡터의 크기는 3

#### 순환 신경망의 동작

- 활성화 함수 : tanh 함수

![RNNA](https://github.com/BangYunseo/TIL/blob/main/AI/DeepLearning/Image/ch10/RNNA.PNG)

![RNNA2](https://github.com/BangYunseo/TIL/blob/main/AI/DeepLearning/Image/ch10/RNNA2.PNG)

#### Vanilla RNN(Keras.SimpleRNN)

- 레이어의 출력을 다시 입력으로 받아서 사용
- 이전의 데이터가 함께 결과에 영향

![VRNN](https://github.com/BangYunseo/TIL/blob/main/AI/DeepLearning/Image/ch10/VRNN.PNG)

##### return_sequences

- RNN 계산과정에 있는 hidden state의 출력 여부 결정 값
- RNN, one-to-many, many-to-many 출력을 위해 사용

![rs](https://github.com/BangYunseo/TIL/blob/main/AI/DeepLearning/Image/ch10/rs.PNG)

##### Ideal RNN Layer

![IRNN](https://github.com/BangYunseo/TIL/blob/main/AI/DeepLearning/Image/ch10/IRNN.PNG)

##### 예제 1)

```Python
X = []
Y = []
for
i in range
(
6):
lst = list
(range(i,i+
4))
X.append
(list
(map
(lambda c: [c/10], lst)))
Y.append((i+
4)/10
)
X = np.array(X)
Y = np.array(Y)
print(X)
print(Y)

# 출력
# array([[[0. ],
 [0.1],
 [0.2],
 [0.3]],
 [[0.1],
 [0.2],
 [0.3],
 [0.4]],
 [[0.2],
 [0.3],
 [0.4],
 [0.5]],
 [[0.3],
 [0.4],
 [0.5],
 [0.6]],
 [[0.4],
 [0.5],
 [0.6],
 [0.7]],
 [[0.5],
 [0.6],
 [0.7],
 [0.8]]])
0.4
0.5
0.6
0.7
0.8
0.9
```

##### 예제 2)

```Python
model = Sequential()
model.add(SimpleRNN(50, return_sequences=False, input_shape=(4,1)))
model.add(Dense(1))
model.summary()
model.compile(loss='mse',
optimizer='adam',
metrics=['accuracy'])
model.fit(X,Y,epochs=200, verbose=2)
print(model.predict(X))
X_test = np.array([[[0.8],[0.9],[1.0],[1.1]]])
print(model.predict(X_test))

# 출력

```

- 파라미터 아웃값 * (파라미터 아웃값 + 차원수 (아웃풋 1) + 1(바이어스)
- 50 * (50+1+1)

![VRNNOP](https://github.com/BangYunseo/TIL/blob/main/AI/DeepLearning/Image/ch10/VRRNOP.PNG)

## 3절. 순환 신경망 유형

#### RNN 유형

- 일대일(One to One)
- 일대다(One to Many)
- 다대일(Many to One)
- 다대다(Many to Many)

## 4절. 역전파 방향
















#### 정리(11/19)
- 퍼셉트론 : weight값, 입력값 각각 2개씩 존재하고 bias를 더해준 값(ex : $X_1*W_1 + X_2*W_2 + b$)
- 다층 퍼셉트론 : 퍼셉트론에서 은닉층이 추가된 값으로, 은닉층의 값들은 여러 개가 될 수 있음. 은닉층의 값마다 bias가 추가됨
- 다층 퍼셉트론 최적화 : 끝쪽을 미분하면 0으로 수렴했기에, 조금 더 자세한 값이 필요하게 됨 => Sigmoid, ReLU, tanh, softmax, UnitStep의 활성화 함수 / He, Xaiver과 같은 방법으로도 가능
- 컨볼루션 신경망 : 영상, 이미지에서의 값을 계산할 경우 여러 개의 커널로 엣지, 색깔, 원 등 다양한 입력에 따른 결과를 추출 / 출력값이 늘어날수록 고수준 / pooling이나 데이터 증강 등의 방법으로 OverFitting(과적합) 방지
- 심층 신경망과 컨볼루션 신경망 : 사용 환경에 따라 성능 차이가 존재 = 둘 다 좋은 방법이나 환경, 계산 형식에 맞는 신경망을 사용하는 것이 중요
