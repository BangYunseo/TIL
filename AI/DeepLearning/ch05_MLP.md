# Chapter 5. 다층 퍼셉트론(Multilayer Perceptron)

> 1절. MLP
>
> 2절. 경사하강법
> 


## 1절. MLP
#### MLP(Multilayer Perceptron)
* 입력층과 출력층 사이에 은닉층(hidden layer)을 가진 퍼셉트론

![MLP](https://github.com/BangYunseo/TIL/blob/main/AI/DeepLearning/Image/ch05/MLP.PNG)

#### 활성화 함수(Activation Function)
* 입력의 총합을 받아 출력값을 계산하는 함수
* 여러 가지 활성화 함수 존재

![AC](https://github.com/BangYunseo/TIL/blob/main/AI/DeepLearning/Image/ch05/AC.PNG)

#### 일반적으로 많이 사용되는 활성화 함수

![AF](https://github.com/BangYunseo/TIL/blob/main/AI/DeepLearning/Image/ch05/AF.PNG)

#### 선형 레이어
* 선형 레이어는 아무리 많아도 하나의 레이어로 대체 가능

![LL](https://github.com/BangYunseo/TIL/blob/main/AI/DeepLearning/Image/ch05/LL.PNG)

#### 계단 함수
* 입력 신호의 총합이 0을 넘으면 1을, 그렇지 않으면 0을 출력하는 함수

![USF](https://github.com/BangYunseo/TIL/blob/main/AI/DeepLearning/Image/ch05/USF.PNG)

#### 시그모이드 함수
* 1980년대부터 사용된 전통적인 활성화 함수
* S자 형태의 함수

![SF](https://github.com/BangYunseo/TIL/blob/main/AI/DeepLearning/Image/ch05/SF.PNG)

#### ReLU 함수(Rectifed Linear Unit Function)
* 최근에 가장 인기있는 활성화 함수
* 입력이 0을 넘으면 그대로 출력하고, 그렇지 않으면 0 출력

![RF](https://github.com/BangYunseo/TIL/blob/main/AI/DeepLearning/Image/ch05/RF.PNG)

#### tanh 함수
* numpy에서 제공하고 있는 함수
 * 별도의 함수 작성은 필요 X
* 시그모이드 함수와 매우 비슷하지만 출력값이 -1 ~ 1까지

![tF](https://github.com/BangYunseo/TIL/blob/main/AI/DeepLearning/Image/ch05/tF.PNG)

#### 실습 - 활성화 함수 구현
* 하드 코딩 활성화 함수 구현
```Python
def step(x):
 if x > 0.000001:
  return 1
  # 부동 소수점 오차 방지
 else
  return 0
```

* 넘파이 배열을 받기 위한 변경
```Python
def step(x):
 result = x > 0.000001
 # True 또는 False 저장

 return result.astype(np.int)
 # 정수로 반환
```

#### 그래프 그리기
```Python
import numpy as np
import matplotlib.pyplot as plt

x = np.arange(-10.0, 10.0, 0.1)
y = step(x)
plt.plot(x, y)
plt.show()
```

![BG](https://github.com/BangYunseo/TIL/blob/main/AI/DeepLearning/Image/ch05/BG.PNG)

##### 시그모이드 함수
```Python
import numpy as np
import matplotlib.pyplot as plt

def sigmoid(x):
 return 1.0 / (1.0 + np.exp(-x))

x = np.arange(-10.0, 10.0, 0.1)
y = sigmoed(x)
plt.plot(x, y)
plt.show()
```

![SFG](https://github.com/BangYunseo/TIL/blob/main/AI/DeepLearning/Image/ch05/SFG.PNG)

##### tanh 함수
```Python
import numpy as np 
import matplotlib.pyplot as plt

x = np.linspace(-np.pi, np.pi, 60) 
y = np.tanh(x) 
plt.plot(x, y) 
plt.show() 
```

![tFG](https://github.com/BangYunseo/TIL/blob/main/AI/DeepLearning/Image/ch05/tFG.PNG)

(여기부터 수정)
##### ReLU 함수
```Python
import numpy as np 
import matplotlib.pyplot as plt

x = np.linspace(-np.pi, np.pi, 60) 
y = np.tanh(x) 
plt.plot(x, y) 
plt.show() 
```

![tFG](https://github.com/BangYunseo/TIL/blob/main/AI/DeepLearning/Image/ch05/tFG.PNG)

#### MLP의 순방향 패스
## 2절. 경사하강법
#### 경사하강법
* 역전파 알고리즘
  * 신경망 학습 문제를 최적화 문제(optimization)로 접근
  * 손실함수 값(오차값)을 최소화하는 가중치 탐색
      
![GD](https://github.com/BangYunseo/TIL/blob/main/AI/DeepLearning/Image/ch05/GD.PNG)

![GD2](https://github.com/BangYunseo/TIL/blob/main/AI/DeepLearning/Image/ch05/GD2.PNG)

* 기울기 : 손실함수를 가중치로 미분한 값

#### 실습
* 손실 함수
* $y = {(x-3)}^2 + 10$
* 그래디언트 : $y' = 2x - 6$

![GDex](https://github.com/BangYunseo/TIL/blob/main/AI/DeepLearning/Image/ch05/GDex.PNG)

```Python
x = 10
# 정해지는 값

learning_rate = 0.2 
precision = 0.00001 
max_iterations = 100
# 손실함수를 람다식으로 정의

loss_func = lambda x : (x-3) ** 2 + 10
# 그래디언트를 람다식으로 정의
# 손실함수의 1차 미분값

gradient = lambda x : 2 * x - 6

# 그래디언트 하강법(높은 값에서부터 작은 값까지 하강)
for i in range(max_iterations):
    x = x - learning_rate * gradient(x)
    print("손실함수값(", x, ")=", loss_func(x))
print("최소값 = ", x)

# 손실함수값( 7.199999999999999 )= 27.639999999999993
# 손실함수값( 5.52 )= 16.350399999999997
# 손실함수값( 4.512 )= 12.286143999999998
# 손실함수값( 3.9071999999999996 )= 10.82301184
# 손실함수값( 3.54432 )= 10.2962842624
# 손실함수값( 3.3265919999999998 )= 10.106662334464
# 손실함수값( 3.1959551999999998 )= 10.03839844040704
# 손실함수값( 3.11757312 )= 10.013823438546535
# 손실함수값( 3.070543872 )= 10.004976437876753
# 손실함수값( 3.0423263232 )= 10.001791517635631
# 손실함수값( 3.02539579392 )= 10.000644946348826
# 손실함수값( 3.015237476352 )= 10.000232180685577
# 손실함수값( 3.0091424858112 )= 10.000083585046807
# 손실함수값( 3.00548549148672 )= 10.000030090616852
# 손실함수값( 3.003291294892032 )= 10.000010832622067
# 손실함수값( 3.0019747769352194 )= 10.000003899743945
# 손실함수값( 3.0011848661611316 )= 10.00000140390782
# 손실함수값( 3.000710919696679 )= 10.000000505406815
# 손실함수값( 3.0004265518180073 )= 10.000000181946453
# 손실함수값( 3.0002559310908046 )= 10.000000065500723
# 손실함수값( 3.0001535586544827 )= 10.00000002358026
# 손실함수값( 3.0000921351926895 )= 10.000000008488893
# 손실함수값( 3.0000552811156136 )= 10.000000003056002
# 손실함수값( 3.000033168669368 )= 10.00000000110016
# 손실함수값( 3.000019901201621 )= 10.000000000396058
# . ..
# 손실함수값( 3.0000000000000004 )= 10.0
# 손실함수값( 3.0000000000000004 )= 10.0
# 손실함수값( 3.0000000000000004 )= 10.0
# 최소값 =  3.0000000000000004
```

#### 2차원 그래디언트 시각화(3D)
```Python
from mpl_toolkits.mplot3d import axes3d
import matplotlib.pyplot as plt
import numpy as np

x = np.arange(-5, 5, 0.5)
y = np.arange(-5, 5, 0.5)
X, Y = np.meshgrid(x, y)
Z = X ** 2 + Y ** 2

fig = plt.figure(figsize = (6, 6))
ax = fig.add_subplot(111, projection = '3d')

# 3차원 그래프 그리기
ax.plot_surface(X, Y, Z)
plt.show()
```

![GDres](https://github.com/BangYunseo/TIL/blob/main/AI/DeepLearning/Image/ch05/GDres.PNG)

#### 2차원 그래디언트 시각화(격자)
```Python
import matplotlib.pyplot as plt
import numpy as np

x = np.arange(-5, 5, 0.5)
y = np.arange(-5, 5, 0.5)

X, Y = np.meshgrid(x, y)

U = -2 * X
V = -2 * Y

plt.figure()
Q = plt.quiver(X, Y, U, V, units = 'width)
plt.show()
```

![GDres2](https://github.com/BangYunseo/TIL/blob/main/AI/DeepLearning/Image/ch05/GDres2.PNG)

#### 역전파(backpropogation) 학습 알고리즘
* 입력이 주어지면 순방향으로 계산하여 출력 계산 후 실제 출력과 우리가 원하는 출력 간의 오차 계산
* 오차를 역방향으로 전파하여 줄이는 방향으로 가중치 변경

![BP](https://github.com/BangYunseo/TIL/blob/main/AI/DeepLearning/Image/ch05/BP.PNG)

![BP2](https://github.com/BangYunseo/TIL/blob/main/AI/DeepLearning/Image/ch05/BP2.PNG)

* 손실함수 E의 그래디언트 값
  * 양수
    * $w(t)$의 값이 커지고, $w(t+1)$의 값이 작아짐
    * Sub를 진행하는 값이 커졌기 때문에 결과값이 작아짐
  * 음수
    * $w(t)$의 값이 작아지고, $w(t+1)$의 값이 커짐
    * Sub를 진행하는 값이 없고 Add를 진행하는 값만 존재하기 때문에 결과값이 커짐
      
* 목표 : 정확한 지점을 찾아가는 것

#### 역전파 - 체인룰

![CR](https://github.com/BangYunseo/TIL/blob/main/AI/DeepLearning/Image/ch05/CR.PNG)

#### 역전파 알고리즘의 유도
* 미분의 체인룰을 통해 유도 가능

![BPin](https://github.com/BangYunseo/TIL/blob/main/AI/DeepLearning/Image/ch05/BPin.PNG)

* 출력층 유닛

![PL](https://github.com/BangYunseo/TIL/blob/main/AI/DeepLearning/Image/ch05/PL.PNG)

* 은닉층 유닛

![HL](https://github.com/BangYunseo/TIL/blob/main/AI/DeepLearning/Image/ch05/HL.PNG)

#### 델타
* 여러 문헌에서 델타라는 이름으로 불리는 값

(중간부분 학습 후 입력)


#### MLP 구현
```Python
import numpy as np

# 시그모이드 함수
def actf(x):
 return 1/(1+np.exp(-x))

# 시그모이드 함수의 미분치
def actf_deriv(x):
 return x*(1-x)

# 입력유닛의 개수, 은닉유닛의 개수, 출력유닛의 개수
inputs, hiddens, outputs = 2, 2, 1
learning_rate=0.2

# 훈련 샘플과 정답
X = np.array([[0, 0], [0, 1], [1, 0], [1, 1]])
T = np.array([[1], [0], [0], [1]])
```

##### 순방향 전파 구현
```Python
W1 = np.array([[0.10,0.20], [0.30,0.40]])
W2 = np.array([[0.50],[0.60]])
B1 = np.array([0.1, 0.2])
B2 = np.array([0.3]) 

# 순방향 전파 계산
def predict(x):
 layer0 = x
 # 입력을 layer0에 대입

 Z1 = np.dot(layer0, W1)+B1
 # 행렬의 곱을 계산
 layer1 = actf(Z1)
 # 활성화 함수를 적용

 Z2 = np.dot(layer1, W2)+B2
 # 행렬의 곱을 계산
 layer2 = actf(Z2)
 # 활성화 함수를 적용 
 return layer0, layer1, layer2
```

##### 오차 역전파 구현
```Python
# 역방향 전파 계산
def fit():
 global W1, W2, B1, B2 # 우리는 외부에 정의된 변수를 변경해야 한다. 
 for i in range(90000): # 9만번 반복한다. 
  for x, y in zip(X, T): # 학습 샘플을 하나씩 꺼낸다. 
   x = np.reshape(x, (1, -1)) # 2차원 행렬로 만든다. ①
   y = np.reshape(y, (1, -1)) # 2차원 행렬로 만든다. 
   layer0, layer1, layer2 = predict(x) # 순방향 계산
   layer2_error = layer2-y # 오차 계산
   layer2_delta = layer2_error*actf_deriv(layer2) # 출력층의 델타 계산
   layer1_error = np.dot(layer2_delta, W2.T) # 은닉층의 오차 계산 ②
   layer1_delta = layer1_error*actf_deriv(layer1) # 은닉층의 델타 계산 ③
   W2 += -learning_rate*np.dot(layer1.T, layer2_delta) # ④
   W1 += -learning_rate*np.dot(layer0.T, layer1_delta) # 
   B2 += -learning_rate*np.sum(layer2_delta, axis=0) # ⑤
   B1 += -learning_rate*np.sum(layer1_delta, axis=0) #
def test():
 for x, y in zip(X, T):
   x = np.reshape(x, (1, -1))
   # 하나의 샘플을 꺼내서 2차원 행렬 
   layer0, layer1, layer2 = predict(x)

   print(x, y, layer2)
   # 출력층의 값 출력
fit()
test()

# [[0 0]] [1] [[0.99196032]]
# [[0 1]] [0] [[0.00835708]]
# [[1 0]] [0] [[0.00836107]]
# [[1 1]] [1] [[0.98974873]]
```
