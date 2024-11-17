# Chapter 10. 순환 신경망(RNN : Recurrent Neural Networks)

> 1절. 순환 데이터

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
