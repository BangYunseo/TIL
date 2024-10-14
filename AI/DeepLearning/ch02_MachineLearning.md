#  Chapter 2. 머신러닝의 기초(Basic of MachineLearning)
> 1절. 머신러닝
>
> 2절. 지도 학습과 비지도 학습
>
> 3절. 모델 및 평가
>
> 4절. 교차 검증 
>
> 5절. 데이터 세트
>
> 6절.


## 1절. 머신러닝
#### 전통적인 프로그래밍과 머신러닝
![CM](https://github.com/BangYunseo/TIL/blob/main/AI/DeepLearning/Image/ch02/CM.PNG)

|종류|입력값|
|:---|:-----|
|전통적인 프로그래밍|데이터, 코드|
|머신러닝|데이터, 출력값|

#### 인공지능, 머신러닝, 딥러닝
![AI](https://github.com/BangYunseo/TIL/blob/main/AI/DeepLearning/Image/ch02/AI.PNG)

#### 머신러닝의 역사
![HOM](https://github.com/BangYunseo/TIL/blob/main/AI/DeepLearning/Image/ch02/HOM.PNG)

#### 머신러닝
* 입력을 받아 출력하는 함수 $y = f(x)$의 학습(함수 근사)

![MF](https://github.com/BangYunseo/TIL/blob/main/AI/DeepLearning/Image/ch02/MF.PNG)

* 종류

![MT](https://github.com/BangYunseo/TIL/blob/main/AI/DeepLearning/Image/ch02/MT.PNG)

![MT2](https://github.com/BangYunseo/TIL/blob/main/AI/DeepLearning/Image/ch02/MT2.PNG)

![MT3](https://github.com/BangYunseo/TIL/blob/main/AI/DeepLearning/Image/ch02/MT3.PNG)

## 2절. 지도 학습과 비지도 학습
#### 지도 학습의 종류
![SLT](https://github.com/BangYunseo/TIL/blob/main/AI/DeepLearning/Image/ch02/SLT.PNG)

#### 회귀(Regression)
* 주어진 입력-출력 쌍을 학습
* 학습 후 새로운 입력값에 합리적인 출력값 예측
* 즉, 입력($x$)과 출력($y$)이 주어질 경우 입력에서 출력으로의 매핑 함수를 학습하는 것
* $y = f(x)$
    * 입력, 출력이 모두 실수
    * ex)
        * "사용자가 이 광고를 클릭할 확률은?"
        * "면적에 따른 각 아파트의 가격은?"

![Regression](https://github.com/BangYunseo/TIL/blob/main/AI/DeepLearning/Image/ch02/Regression.PNG)

#### 분류(Classification)
* 앞의 회귀에서 나왔던 공식 $y = f(x)$에서 출력 $y$가 이산적(discrete)인 경우 분류 문제(또는 인식 문제)
* 입력을 2개 이상의 클래스(부류)로 분류
* ex)
    * 사진을 보고 "강아지"클래스나 "고양이"클래스로 분류하는 것

![Classification](https://github.com/BangYunseo/TIL/blob/main/AI/DeepLearning/Image/ch02/Classification.PNG)

* 크기, 색상, 모양의 정보만 가지고 과일 이름으로 분류하는 예시

![C2](https://github.com/BangYunseo/TIL/blob/main/AI/DeepLearning/Image/ch02/C2.PNG)

* 분류를 수행하기 위한 일반적인 알고리즘
    * 신경망
    * KNN(K-Nearest Neighbor)
    * SVM(Support Vector Machine)
    * 의사 결정 트리

#### 비지도 학습
* "교사"없이 컴퓨터가 스스로 입력들을 분류
* $y = f(x)$에서 레이블 $y$가 주어지지 않음
* 데이터들의 상관도를 분석하여 유사한 데이터 결집

![UL](https://github.com/BangYunseo/TIL/blob/main/AI/DeepLearning/Image/ch02/UL.PNG)

## 3절. 모델 및 평가
#### 머신 러닝의 과정

![MP](https://github.com/BangYunseo/TIL/blob/main/AI/DeepLearning/Image/ch02/MP.PNG)

#### 모델 평가
* 머신 러닝의 모델
    * 음료수를 판별하는 시스템을 만들어 달라는 요청을 받았을 경우  
    * 시스템이 "모델(model)"
    * 모델은 "학습(train)"의 과정을 통해 생성

![ModelTest](https://github.com/BangYunseo/TIL/blob/main/AI/DeepLearning/Image/ch02/ModelTest.PNG)

* 머신 러닝의 특징
    * 색상(파장)과 산성도(실수)의 두 가지를 선택해야 하는 경우
    * 두 가지 요소만으로 구별할 수 있기를 희망하는 "특징(feature)"

![Feature](https://github.com/BangYunseo/TIL/blob/main/AI/DeepLearning/Image/ch02/Feature.PNG)

* 데이터 수집을 통한 특징 비교
![Feature2](https://github.com/BangYunseo/TIL/blob/main/AI/DeepLearning/Image/ch02/Feature2.PNG)

#### 훈련 데이터, 테스트 데이터
* 머신 러닝에는 항상 훈련 데이터와 테스트 데이터 존재

![Data](https://github.com/BangYunseo/TIL/blob/main/AI/DeepLearning/Image/ch02/Data.PNG)

* 훈련 데이터 구조

![TD](https://github.com/BangYunseo/TIL/blob/main/AI/DeepLearning/Image/ch02/TD.PNG)

* 훈련 단계와 테스트 단계 존재
##### 훈련 단계

![Training](https://github.com/BangYunseo/TIL/blob/main/AI/DeepLearning/Image/ch02/Training.PNG)

##### 테스트 단계

![Test](https://github.com/BangYunseo/TIL/blob/main/AI/DeepLearning/Image/ch02/Test.PNG)

#### 모델 선택
* 머신러닝의 모델 선택
* 특징(Feature)의 개수에 따라 여러 타입 모델 존재

![MF](https://github.com/BangYunseo/TIL/blob/main/AI/DeepLearning/Image/ch02/MF.PNG)

#### 선형 모델

![LinearModel](https://github.com/BangYunseo/TIL/blob/main/AI/DeepLearning/Image/ch02/LinearModel.PNG)

#### 학습
* 가중치$(W)$와 $y$절편$(b)$을 임의의 값으로 초기화한 후 출력 예측
* 출력값의 정확한 값과 비교 후 더 정확한 예측을 갖도록 $W$ 및 $b$의 값 조정

![Learning](https://github.com/BangYunseo/TIL/blob/main/AI/DeepLearning/Image/ch02/Learning.PNG)

#### 평가
* 학습이 완료되면 모델을 평가 후 모델의 정확도 판단
* 테스트 데이터 사용
* 일반적인 훈련 데이터와 테스트 데이터의 비율
    * 80 : 20
    * 70 : 30

## 4절. 교차 검증
#### 교차 검증(Cross Validation)
* 교차 검증 과정

![CV](https://github.com/BangYunseo/TIL/blob/main/AI/DeepLearning/Image/ch02/CV.PNG)

#### 사전 데이터 셋 분류

![Legend](https://github.com/BangYunseo/TIL/blob/main/AI/DeepLearning/Image/ch02/Legend.PNG)

#### 홀드아웃 방법(Holdout Method)

![HM](https://github.com/BangYunseo/TIL/blob/main/AI/DeepLearning/Image/ch02/HM.PNG)

#### K-겹 교차 검증(K-Fold Cross Validation)

![KCV](https://github.com/BangYunseo/TIL/blob/main/AI/DeepLearning/Image/ch02/KCV.PNG)

#### 리브-P-아웃 교차 검증(Leave-P-Out Cross Validation)
* 전체 데이터(서로 다른 데이터 샘플들) 중 P개의 샘플을 선택하여 그것을 모델 검증에 사용하는 방법

![LCV](https://github.com/BangYunseo/TIL/blob/main/AI/DeepLearning/Image/ch02/LCV.PNG)

#### 리브-원-아웃 교차 검증(Leave-One-Out Cross Validation)

![OCV](https://github.com/BangYunseo/TIL/blob/main/AI/DeepLearning/Image/ch02/OCV.PNG)

## 5절. 데이터 세트
#### 예측
* 머신러닝 시스템은 사용자의 질문에 대답
* 예시
    * 색상이 600nm, 산성도가 1.5인 음료가 무엇인지 머신러닝 시스템에 질문
    * 훈련된 결과를 바탕으로 색상 및 산성도를 고려하여 음료를 예측

![Prediction](https://github.com/BangYunseo/TIL/blob/main/AI/DeepLearning/Image/ch02/Prediction.PNG)

#### 기본적인 데이터 세트
![DS](https://github.com/BangYunseo/TIL/blob/main/AI/DeepLearning/Image/ch02/DS.PNG)

#### 붓꽃 데이터 세트
![iris](https://github.com/BangYunseo/TIL/blob/main/AI/DeepLearning/Image/ch02/iris.PNG)

* 특징과 레이블의 구조
![43p사진구조]()
```Python
from sklearn import datasets
iris = datasets.load_iris()
print(iris)
```

* 훈련 데이터와 테스트 데이터 분리
```Python
from sklearn.model_selection import train_test_split

X = iris.data
y = iris.target

# (80 : 20)으로 분할
X_train, X_test, y_Train, y_test = train_test_split(X, y, test_size = 0.2, random_state = 4)

print(X_train.shape)
print(X_test.shape)

# (120, 4)
# (30, 4)
```

* 붗꽃 데이터 실습 결과
```Python
from sklearn.datasets import load_iris
from sklearn.linear_model import Perceptron
import numpy as np
import matplotlib.pyplot as plt

iris = load_iris()

print(iris.feature_names)
print(iris.target_names)

X, y = iris.data, iris,target
```

![45p]()

#### 모델 선택
* K-Nearest Neighbor(KNN) 알고리즘은 모든 머신러닝 알고리즘 중에서도 가장 간단하고 이해하기 쉬운 분류 알고리즘
* KNN은 학습 시에 교사가 존재하는 "지도 학습"

 ![46p]() 

* 학습
```Python
from sklearn.neighbors import KNeighborsClassifier

knn = KNeighborsClassifier(n_neighbors = 6)
knn.fit(X_train, y_train)
```

* 평가
```Python
from sklearn.neighbors import KNeighborsClassifier
from sklearn import metrics

y_pred = knn.predict(X_train)
scores = metrics.accuracy_score(y_testm y_pred)
# 0.9666666666666666667
```

* 예측
```Python
from sklearn.neighbors import KNeighborsClassifier
from sklearn import metrics

classes={0:'setosa',1:'versicolor',2:'virginica’}

# 전혀 보지 못한 새로운 데이터 제시
x_new = [[3, 4, 5, 2], [5, 4, 2, 2]]
y_predict = knn.predict(x_new)

print(classes[y_predict[0]])
print(classes[y_predict[1]])

# versicolor
# setosa
```

* 모델 - perceptron
* 












