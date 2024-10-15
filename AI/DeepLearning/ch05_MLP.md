# Chapter 5. 다층 퍼셉트론(Multilayer Perceptron)

> 1절. 
>
> 2절. 경사하강법
> 


## 1절.
#### 
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
```
