#  Chapter 2. 회귀(Regression)

> 1절. 회귀
>
> 2절. 경사 하강법
>
> 3절. 과잉 적합과 과소 적합
>
> 4절. 회귀 구현



## 1절. 회귀
#### 회귀와 분류
![RC](https://github.com/BangYunseo/TIL/blob/main/AI/DeepLearning/Image/ch03/RC.PNG)

#### 선형 회귀
* 데이터들을 2차원 공간에 찍은 후 데이터들을 가장 잘 설명하는 직선 OR 곡선을 찾는 문제
* 입력 데이터를 가장 잘 설명하는 기울기와 절편값을 찾는 문제
* $y = f(x)$에서 출력 $y$와 입력 $x$가 실수일 때, 함수 $f(x)$ 예측

![RCT](https://github.com/BangYunseo/TIL/blob/main/AI/DeepLearning/Image/ch03/RCT.PNG)

* 직선의 방정식 : $f(x) = mx + b$
* 선형 회귀 기본식 : $f(x) = Wx + b$
    * 기울기 -> 가중치
    * 절편 -> 바이어스

#### 선형 회귀 예시
* 부모의 키와 자녀 키의 관계 조사
* 면적에 따른 주택 가격
* 연령에 따른 실업율 예측
* 공부 시간과 학점과의 관계
* CPU 속도와 프로그램 실행 시간 예측

#### 선형 회귀 예제

![EX](https://github.com/BangYunseo/TIL/blob/main/AI/DeepLearning/Image/ch03/EX.PNG)

#### 선형 회귀 종류
* 단순 선형 회귀
    * 독립 변수($x$)가 하나인 경우
    * $f(x) = wx + b$
* 다중 선형 회귀
    * 독립 변수가 여러 개인 경우

![MLP](https://github.com/BangYunseo/TIL/blob/main/AI/DeepLearning/Image/ch03/MLP.PNG)

#### 선형 회귀 원리
```Python
import numpy as np
from sklearn.linear_model import LinearRegression

X = 10 * np.random.randn(100, 1)
y = 3 + X + np.random.randn(100, 1)

plt.plot(X, y, 'o')
plt.show()
```

![Data](https://github.com/BangYunseo/TIL/blob/main/AI/DeepLearning/Image/ch03/Data.PNG)

![RES](https://github.com/BangYunseo/TIL/blob/main/AI/DeepLearning/Image/ch03/RES.PNG)

* 최선의 것은 데이터 간의 오차가 작은 경우
![RES2](https://github.com/BangYunseo/TIL/blob/main/AI/DeepLearning/Image/ch03/RES2.PNG)

#### 손실 함수(Loss Function)
* 손실 함수 또는 비용 함수(Cost Function)
    * 직선과 데이터 사이의 간격을 제곱하여 합한 값

![LF](https://github.com/BangYunseo/TIL/blob/main/AI/DeepLearning/Image/ch03/LF.PNG)

* 선형 회귀 선과의 차이가 큰 경우 손실이 큼
* 선형 회귀 선과의 차이가 작은 경우 손실이 작음

![LF2](https://github.com/BangYunseo/TIL/blob/main/AI/DeepLearning/Image/ch03/LF2.PNG)

#### 선형 회귀에서 손실 함수 최소화 방법
* 분석적인 방법
   * 독립 변수와 종속 변수가 각각 하나인 선형 회귀

![MinLR](https://github.com/BangYunseo/TIL/blob/main/AI/DeepLearning/Image/ch03/MinLR.PNG)

## 2절. 경사 하강법
#### 경사 하강법(Gradient descent method)
* Cost 함수 그래프를 그리면 아래와 같은 2차 포물선 생성
* 손실 함수가 어떤 형태이더라도, 매개 변수가 아무리 많아도 적용 가능한 일반적인 방법
* 점진적인 학습 가능

![GDM](https://github.com/BangYunseo/TIL/blob/main/AI/DeepLearning/Image/ch03/GDM.PNG)

```Python
import numpy as np
import matplotlib.pyplot as plt
import tensorflow as tf

def forward(wa, x):
   return wa * x

X = np.array([1., 2., 3.])
Y = np.array([1., 2., 3.])

W_val = []
cost_val = []
m = n_samples = len(X)

for i in range(-30, 50):
   W_val.append(i )
   print(forward(i ,X))
   cost_val.append(tf.reduce_sum(tf.pow(forward(i ,X)-Y, 2))/(m))

plt.plot(W_val, cost_val, 'ro')
plt.ylabel('Cost')
plt.xlabel('W')
plt.show()
```

![GDM2](https://github.com/BangYunseo/TIL/blob/main/AI/DeepLearning/Image/ch03/GDM2.PNG)

![GDM3](https://github.com/BangYunseo/TIL/blob/main/AI/DeepLearning/Image/ch03/GDM3.PNG)

#### 학습률

![LP](https://github.com/BangYunseo/TIL/blob/main/AI/DeepLearning/Image/ch03/LP.PNG)

#### 지역 최솟값 문제

![LM](https://github.com/BangYunseo/TIL/blob/main/AI/DeepLearning/Image/ch03/LM.PNG)

#### 선형 회귀에서의 경사 하강법

![LRGDM](https://github.com/BangYunseo/TIL/blob/main/AI/DeepLearning/Image/ch03/LRGDM.PNG)

#### 경사 하강법 코드 구현
```Python
import numpy as np
import matplotlib.pyplot as plt

X = np.array([0.0, 1.0, 2.0])
y = np.array([3.0, 3.5, 5.5])

W = 0 # 기울기
b = 0 # 절편

lrate = 0.01 # 학습률
epochs = 1000 # 반복 횟수

n = float(len(X))                      # 입력 데이터의 개수

# 경사 하강법
for i in range(epochs):
   y_pred = W*X + b                    # 예측값
   dW = (2/n) * sum(X * (y_pred-y))
   db = (2/n) * sum(y_pred-y)
   W = W - lrate * dW                  # 기울기 수정
   b = b - lrate * db                  # 절편 수정

# 기울기와 절편을 출력
print (W, b)

# 예측값
y_pred = W*X + b

# 입력 데이터를 그래프에 plot
plt.scatter(X, y)

# 예측값은 선그래프
plt.plot([min(X), max(X)], [min(y_pred), max(y_pred)], color='red')
plt.show()

# 1.2532418085611319 2.745502230882486 (기울기 절편 순서)
```

![GDMex](https://github.com/BangYunseo/TIL/blob/main/AI/DeepLearning/Image/ch03/GDMex.PNG)

#### 선형 회귀 예제
* 아나콘다에 포함된 Scikit-Learn 라이브러리를 사용하여 회귀 함수를 구현하는 방법

##### 모델 생성 및 학습
```Python
import matplotlib.pylab as plt
from sklearn import linear_model

# 선형 회귀 모델을 생성
reg = linear_model.LinearRegression()

# 데이터는 파이썬의 리스트와 넘파이의 배열 모두 가능
X = [[0], [1], [2]]          # 2차원으로 만들어야 함
y = [3, 3.5, 5.5]            # y = x + 3

# 학습
reg.fit(X, y)
```

##### 학습 데이터 생성
* 학습 데이터는 반드시 2차원 배열
  * 한 열만 있더라도 반드시 2차원 배열 형태
* 리스트의 리스트를 생성하여 2차원 배열 생성

##### 값 확인
```Python
# 직선의 기울기
reg.coef_ 
# array([1.25])

# 직선의 y-절편
reg.intercept_ 
# 2.7500000000000004

reg.score(X, y)
# 0.8928571428571429

reg.predict([[5]])
# array([8.])
```

##### 그래프 생성(d여기부터 다시 수정)
```Python
# 학습 데이터와 y 값을 산포도로 그린다.
plt.scatter(X, y, color='black')
# 학습 데이터를 입력으로 하여 예측값을 계산한다.
y_pred = reg.predict(X)
# 학습 데이터와 예측값으로 선그래프로 그린다.
# 계산된 기울기와 y 절편을 가지는 직선이 그려진다.
plt.plot(X, y_pred, color='blue', linewidth=3)
plt.show()
```

##### 실행 결과

![RES](https://github.com/BangYunseo/TIL/blob/main/AI/DeepLearning/Image/ch03/RES.PNG)

## 3절. 과잉 적합과 과소 적합

## 4절. 회귀 구현
