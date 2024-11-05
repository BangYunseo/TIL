# Chapter 7. 심층 신경망(DNN : Deep Neural Networks)

> 1절. 심층 신경망 구조
>
> 2절. 활성화 함수
>
> 3절. 손실 함수
>
> 4절. 가중치치

## 1절. 심층 신경망 구조

#### 심층 신경망(DNN)

- Deep Neural Networks
- MLP(다층 퍼셉트론)에서 은닉층의 개수 증
- 은닉층을 여러 개 사용(2개 이상)
- MLP의 문제점을 해결한 형태

![MLPDNN](https://github.com/BangYunseo/TIL/blob/main/AI/DeepLearning/Image/ch07/MLPDNN.PNG)

![MLPDNN2](https://github.com/BangYunseo/TIL/blob/main/AI/DeepLearning/Image/ch07/MLPDNN2.PNG)

#### GPU의 도움

- DNN의 학습 속ㄷ도는 상당히 느리고 계산 집약적
  - 학습에 시간과 자원이 많이 소모
- 최근 GPU(Graphic Processor) 기술의 발전으로 GPU가 제공하는 데이터 처리 기능을 딥러닝이 사용

![DNN](https://github.com/BangYunseo/TIL/blob/main/AI/DeepLearning/Image/ch07/DNN.PNG)

#### 은닉층의 역할

- 앞단 : 경계선(edge)과 같은 저급 특징들 추출
- 뒷단 : 코너와 같은 고급 특징들 추출

![HL](https://github.com/BangYunseo/TIL/blob/main/AI/DeepLearning/Image/ch07/HL.PNG)

## 2절. 활성화 함수

#### 그래디언트 소실 문제

- 심층 신경망에서 그래디언트가 전달되다가 점점 0에 가까워지는 현상

  - 시그모이드 활성화 함수로 인해 발생
  - 특성상, 아주 큰 양수나 음수가 입력되면 출력이 포화되어 0이 됨

    ![SF](https://github.com/BangYunseo/TIL/blob/main/AI/DeepLearning/Image/ch07/SF.PNG)

![GP](https://github.com/BangYunseo/TIL/blob/main/AI/DeepLearning/Image/ch07/GP.PNG)

#### 역전파 알고리즘의 복습

![S1](https://github.com/BangYunseo/TIL/blob/main/AI/DeepLearning/Image/ch07/S1.PNG)

#### 활성화 함수 : ReLU 함수

![RF](https://github.com/BangYunseo/TIL/blob/main/AI/DeepLearning/Image/ch07/RF.PNG)

- 그래디언트 소실 문제 해결을 위해 심층 신경망에서 ReLU 함수 주 사용

#### 다양한 활성화 함수 변경

![MF](https://github.com/BangYunseo/TIL/blob/main/AI/DeepLearning/Image/ch07/MF.PNG)

- ReLU, tanh 함수가 원만하게 분류
- Linear 다른 활성화 함수보다 부족한 모습

## 3절. 손실 함수

#### 손실 함수 선택 문제

- 과거에는 평균 제곱 오차(Mean Squared Error : MSE) 사용
- 더 나은 손실 함수 존재

#### 소프트맥스(SoftMax) 활성화 함수

- Max 함수의 소프트한 버전
- Max 함수의 출력은 최대 입력값에 의해 결정

![MAX](https://github.com/BangYunseo/TIL/blob/main/AI/DeepLearning/Image/ch07/MAX.PNG)

#### 교차 엔트로피 손실 함수

- 2개의 확률 분포 $p$, $q$ 정의

![CEF](https://github.com/BangYunseo/TIL/blob/main/AI/DeepLearning/Image/ch07/CEF.PNG)

![CEF1](https://github.com/BangYunseo/TIL/blob/main/AI/DeepLearning/Image/ch07/CEF1.PNG)

##### 손실 함수(Loss Function)가 0 : 완벽한 일치

![CEF2](https://github.com/BangYunseo/TIL/blob/main/AI/DeepLearning/Image/ch07/CEF2.PNG)

- 학습이 여러번 되어질 경우, 실제 출력 S의 정확도가 상승하여 손실 함수(Loss Function)이 0에 가까워지도록 설정

##### 교차 엔트로피 계산 예제

[CEFex](https://github.com/BangYunseo/TIL/blob/main/AI/DeepLearning/Image/ch07/CEFex.PNG)

- 샘플 #3의 교차 엔트로피가 가장 큼 : 손실 함수(Loss Function)값이 가장 큼

#### 평균 제곱 오차 VS 교차 엔트로피

[MSECEF](https://github.com/BangYunseo/TIL/blob/main/AI/DeepLearning/Image/ch07/MSECEF.PNG)

#### 케라스에서의 손실 함수

- BinaryCrossEntropy : 이진 교차 엔트로피(BCE)로 이진 분류 문제 해결에 사용
- 분류해야 하는 부류(클래스)가 2개일 경우 사용

[kerasL](https://github.com/BangYunseo/TIL/blob/main/AI/DeepLearning/Image/ch07/kerasL.PNG)

##### 계산 예제

[kerasLex](https://github.com/BangYunseo/TIL/blob/main/AI/DeepLearning/Image/ch07/kerasLex.PNG)

#### 다중 분류 엔트로피

##### CCE

- CategoricalCrossEntropy : 분류해야 할 부류(클래스)가 2개 이상일 경우 사용
- 정답 레이블을 원-핫 인코딩으로 제공

[CCE](https://github.com/BangYunseo/TIL/blob/main/AI/DeepLearning/Image/ch07/CCE.PNG)

##### SCE

- SparseCategoricalCrossEntropy : 정답 레이블이 원-핫 인코딩이 아닌 정수로 주어질 경우 사용
- 정답 레이블이 0(강아지), 1(고양이), 2(호랑이)인 경우

[SCE](https://github.com/BangYunseo/TIL/blob/main/AI/DeepLearning/Image/ch07/SCE.PNG)

## 4절. 가중치

#### 가중치 초기화 문제

- 가중치 $w1, w2, w3, w4$와 가중치$w5, w6, w7, w8$이 모두 같은 값으로 설정된 경우
  - 노드 $E$와 노드$G$는 완벽한 일 실행
  - 이것을 방지하기 위한 "균형 깨뜨리기(Breaking The Symmetry)" 필요

[SW](https://github.com/BangYunseo/TIL/blob/main/AI/DeepLearning/Image/ch07/SW.PNG)

#### 난수 가중치 초기값
- 가중치의 초깃값은 난수로 결정
- 반대로 너무 큰 가중치는 그래디언트 폭발(Exploding Gradients) 발생
  - 학습이 수렴하지 않고 발산
 
##### Xavier 방법

[Xavier](https://github.com/BangYunseo/TIL/blob/main/AI/DeepLearning/Image/ch07/Xavier.PNG)

##### He 방법

[He](https://github.com/BangYunseo/TIL/blob/main/AI/DeepLearning/Image/ch07/He.PNG)

#### Data Load

```Python
def load_mnist() :
 digits = load_digits()
 x_data= digits.data
 y_data= digits.target
 x_trainf, x_test, y_trainf, y_test= train_test_split(x_data, y_data, test_size=0.3)
 X_valid, X_train= x_trainf[:50] , x_trainf[50:]
 y_valid, y_train= y_trainf[:50], y_trainf[50:]
 return X_valid,X_train,y_valid,y_train,x_test,y_test
```

##### 기존 가중치 초기화 방법

```Python
def makemodel(X_train, y_train, X_valid, y_valid):
 model = keras.models.Sequential()
 model.add(keras.layers.Flatten(input_shape=[28, 28]))
 model.add(keras.layers.Dense(300, activation="relu"))
 model.add(keras.layers.Dense(100, activation="relu"))
 model.add(keras.layers.Dense(10, activation="softmax"))
 model.summary()
```

##### 서로 다른 가중치 초기화 방법

```Python
def makemodel(X_train, y_train, X_valid, y_valid, weight_init,):
 model = keras.models.Sequential()
 model.add(keras.layers.Flatten(input_shape=[28, 28]))
 model.add(keras.layers.Dense(300, weight_init, activation="relu"))
 model.add(keras.layers.Dense(100, weight_init, activation="relu"))
 model.add(keras.layers.Dense(10, weight_init, activation="softmax"))
 model.summary()
```

##### 정확도, 손실 함수 비교

```Python
model_xavier,hist_xavier= makemodel(X_train, y_train, X_valid, y_valid,'glorot_uniform')
 model_RandomNormal,hist_RandomNormal= makemodel(X_train, y_train, X_valid, y_valid,'RandomNormal')
 model_he,hist_he= makemodel(X_train, y_train, X_valid, y_valid,'he_normal')
```

[HX](https://github.com/BangYunseo/TIL/blob/main/AI/DeepLearning/Image/ch07/HX.PNG)

- He normal이나 Xiver의 정확도와 손실함수가 더 좋은 모습
