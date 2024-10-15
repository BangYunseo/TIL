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