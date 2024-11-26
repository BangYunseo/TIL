# Chapter 11. 자연어 처리(NLP : Natural Language Processing)

> 1절. 자연어 처리
>
> 2절. 예제 : 스팸 메일 분류
>
> 3절. 
>
> 4절. 


## 1절. 자연어 처리

#### 자연어 처리
- 컴퓨터의 인간의 대화 방식(자연어)를 이해

##### 응용 분야
- 챗봇(ChatBot)
- 정보 검색(Information Retrieval)
- 감정 분석(Sentiment analysis)
- 정보 추출(Information Extraction)
- 기계 번역(Machine Translation)

##### 역사
- 1950년대부터 시작되어 많은 연구 진행
- 단어 간의 통계적인 유사성에 바탕을 둔 방법으로 연구
- 최근, 딥러닝을 이용한 방법인 RNN(순환 신경망)을 활용하여 연구 진행

#### 음성 인식과 자연어 처리

- 자연어 처리 : 텍스트 형태로 자연어 입력 후 처리
- 음성 인식(Speech Recognition)
  - 음성의 입력
  - 컴퓨터를 통해 음성을 텍스트로 변환하는 방법론과 기술 개발 분야
 
![SRP](https://github.com/BangYunseo/TIL/blob/main/AI/DeepLearning/Image/ch11/SRP.PNG)

##### NLTK
```Python
C > pip install nltk

import nltk
nltk.download()
```

##### 케라스의 자연어 처리 함수

#### 텍스트 전처리

- 자연어 처리의 첫 단계
- 텍스트를 받아 토큰으로 분리하는 작업
- 각종 구두점을 삭제하는 작업

![TP](https://github.com/BangYunseo/TIL/blob/main/AI/DeepLearning/Image/ch11/TP.PNG)

##### 토큰화(tokenization)
- 말뭉치에 포함된 텍스트를 꺼내 토큰(token)이라 불리는 단위로 나누는 직업
- 한국어는 파생어가 많이 존재하기에(ex : 했고, 해서, 했으니, 했으므로 등) 토큰화에 어려움

![Token](https://github.com/BangYunseo/TIL/blob/main/AI/DeepLearning/Image/ch11/TP.PNG)

##### 소문자 변환
- 영문에서 대문자를 소문자로 통합
- 대문자 단어를 소문자로 변경할 경우 단어의 개수 압축 가능
  - 검색 시 "dog"와 "Dog"가 들어간 문서 모두 검색 가능
- 무조건 대문자를 소문자로 만들 수는 없음
  - 미국을 나타내는 US != 우리라는 의미의 us
 
##### 구두점 제거(정제)
- 토큰화의 결과에 구두점이 포함되어 있다면 삭제
- 일반적으로 구두점들은 자연어 처리에 도움 X

```Python
from nltk.tokenize import word_tokenize

tokens = word_tokenize("Hello World!, This is a dog.")

# 문자나 숫자인 경우에만 단어를 리스트에 추가
words = [word for word in tokens if word.isalpha()]
print(words)

# 출력
# ['Hello', 'World', 'This', 'is', 'a', 'dog']
```

##### 불용어(StopWord)
- 자연어 처리 전 말뭉치에서 자연어 분석에 도움 되지 않는 토큰들 제거
- 문장에 많이 등장하지만 큰 의미 X

```Python
import nltk
nltk.download('punkt')
nltk.download('stopwords’)

from nltk.corpus import stopwords
print(stopwords.words('english')[:20])

# 출력
# ['i', 'me', 'my', 'myself', 'we', 'our', 'ours', 'ourselves', 'you', "you're",
# "you've", "you'll", "you'd", 'your', 'yours', 'yourself', 'yourselves', 'he', 'him',
# 'his']
```

#### NLTK를 이용한 전처리

##### 함수 word_tokenize() 사용

```Python
import nltk
nltk.download('punkt')                   # 1

from nltk.tokenize import word_tokenize  # 2

text = "This is a dog."                  # 3
print(word_tokenize(text))

# 출력
# ['This', 'is', 'a', 'dog', '.']
```

##### 함수 sent_tokenize() 사용

```Python
from nltk.tokenize import sent_tokenize    # 1

text = "This is a house. This is a dog."
print(sent_tokenize(text))                 # 2

# 출력
# ['This is a house.', 'This is a dog.']
```

#### Keras를 이용한 전처리

- 공백으로 단어 분할(split = " ")
- 구두점 필터링 (filters = ‘!”# $ % & () * +,-. / :; <=>? @ [\\] ^ _`{|} ~ \ t\ n’)
- 텍스트를 소문자로 변환(lower = True)

```Python
from tensorflow.keras.preprocessing.text import *

print(text_to_word_sequence("This is a dog."))

# 출력
# ['this', 'is', 'a', 'dog']
```

#### 단어의 표현
- 심층 신경망이 텍스트(언어)를 처리할 때 소화할 수 있는 방식
- 단어를 신경망에 제공

##### 정수 인코딩
- 고유한 숫자를 사용하여 각 단어 인코딩
- 일반적으로 단어를 빈도순으로 정렬 후 빈도가 높은 단어부터 차례대로 번호 부여
- 예시
  - 말뭉치에 단어 1000개가 있을 경우
  - 각 단어에 1번 ~ 1000번까지의 번호(정수) 매핑
 
![NE](https://github.com/BangYunseo/TIL/blob/main/AI/DeepLearning/Image/ch11/NE.PNG)

##### 원-핫 인코딩(One-Hot Encoding)
- 원-핫(One-Hot) : 이진 벡터 중 하나만 1이고 나머지는 모두 0인 것

![OHE](https://github.com/BangYunseo/TIL/blob/main/AI/DeepLearning/Image/ch11/OHE.PNG)

- 케라스 원-핫 인코딩

```Python
import numpy as np
from keras.utils import to_categorical

# 변환하고 싶은 텍스트
text = ["cat", "dog", "cat", "bird"]

# 단어 집합
total_pets = ["cat", "dog", "turtle", "fish", "bird"]
print("text=", text)

# 변환에 사용되는 딕셔너리 생성
mapping = {}
for x in range(len(total_pets)):
  mapping[total_pets[x]] = x #“cat"->0, "dog"->1, ...
print(mapping)
# 매핑

# 단어들을 순차적인 정수 인덱스로 변환
for x in range(len(text)):
  text[x] = mapping[text[x]]

print("text=", text)

# 순차적인 정수 인덱스를 원-핫 인코딩으로 변환
one_hot_encode = to_categorical(text)
print("text=", one_hot_encode)

# 출력
# text= ['cat', 'dog', 'cat', 'bird']
# {'cat': 0, 'dog': 1, 'turtle': 2, 'fish': 3, 'bird': 4}
# text= [0, 1, 0, 4]
# text= [[1. 0. 0. 0. 0.]
#        [0. 1. 0. 0. 0.]
#        [1. 0. 0. 0. 0.]
#        [0. 0. 0. 0. 1.]]
```

- 원-핫 인코딩의 약점
  - 비효율성
    - 원-핫 인코딩된 벡터는 희소
    - 즉 벡터의 대부분이 0
    - ex)단어 집합에 10,000개의 단어가 있다고 가정하고 각 단어를 원-핫 인코딩할 경우
    - 99.99%가 0인 벡터가 10,000개 생성
   
  - 각 벡터들은 단어들 간의 유사도 표현 불가

##### 워드 임베딩(Word Embedding)
- 하나의 밀집 벡터(dense vector)로 표현 방법
- 일반적으로 단어 표현 벡터들은 단어의 개수보다 차원이 작음
  - 벡터들은 효율적이며 조밀함
- 임베딩 벡터들은 학습을 통해 훈련 데이터에서 자동으로 생성(신경망 주 사용)

![WE](https://github.com/BangYunseo/TIL/blob/main/AI/DeepLearning/Image/ch11/WE.PNG)

##### Word2vec
- 단어 임베딩의 일종
- 아래 다이어그램처럼 텍스트 말뭉치를 입력으로 받아들인 후 각 단어에 대한 벡터 표현 출력 알고리즘

![WV](https://github.com/BangYunseo/TIL/blob/main/AI/DeepLearning/Image/ch11/WV.PNG)

##### CBOW(Continuous Bag of Words) 모델
- 주변의 단어들을 통해 중간 단어 예측

![CBOW1](https://github.com/BangYunseo/TIL/blob/main/AI/DeepLearning/Image/ch11/CBOW1.PNG)

![CBOW2](https://github.com/BangYunseo/TIL/blob/main/AI/DeepLearning/Image/ch11/CBOW2.PNG)

![CBOW3](https://github.com/BangYunseo/TIL/blob/main/AI/DeepLearning/Image/ch11/CBOW3.PNG)

##### skipgram
- 중간의 단어로 주변 단어 예측

![sp1](https://github.com/BangYunseo/TIL/blob/main/AI/DeepLearning/Image/ch11/sp1.PNG)

![sp2](https://github.com/BangYunseo/TIL/blob/main/AI/DeepLearning/Image/ch11/sp2.PNG)

#### 전처리와 토큰화
```Python
from tensorflow.keras.preprocessing.text import Tokenizer

t = Tokenizer()
text = """Deep learning is part of a broader family of machine learning methods
based on artificial neural networks with representation learning."""

t.fit_on_texts([text])
print("단어집합 : ", t.word_index)

# 출력
# 단어집합 : {'learning': 1, 'of': 2, 'deep': 3, 'is': 4, 'part': 5, 'a': 6, 'broader': 7,
# 'family': 8, 'machine': 9, 'methods': 10, 'based': 11, 'on': 12, 'artificial': 13,
# 'neural': 14, 'networks': 15, 'with': 16, 'representation': 17}
```

#### 텍스트의 정수 인코딩
```Python
seq = t.texts_to_sequences([text])[0]
print(text,"->", seq)

# 출력
# Deep learning is part of a broader family of machine learning methods
# based on artificial neural networks with representation learning. -> [3, 1, 4,
# 5, 2, 6, 7, 8, 2, 9, 1, 10, 11, 12, 13, 14, 15, 16, 17, 1]
```

#### 샘플의 패딩
- 샘플의 길이가 상이할 수 있음
- 텍스트를 문장 단위로 분리하여 신경망 훈련할 경우 많이 발생
- 패딩(padding) : 보통 숫자 0을 넣어 길이가 다른 샘플들의 길이를 맞추는 것


#### pad_sequence()

```Python
from tensorflow.keras.preprocessing.sequence import pad_sequences

X = pad_sequences([[7, 8, 9], [1, 2, 3, 4, 5], [7]], maxlen=3, padding='pre')
print(X)

# 출력
# [[7 8 9]
# [3 4 5]
# [0 0 7]]
```

##### 매개 변수

```Python
pad_sequences(sequences, maxlen=None, padding='pre’, truncating='pre', value=0.0)
```

- sequences = 패딩이 수행되는 시퀀스 데이터
- maxlen = 샘플의 최대 길이
- padding = 'pre'이면 앞에 0을 채우고 'post'이면 뒤에 0 채움

#### 케라스 Embedding 레이어

- 케라스는 텍스트 데이터를 처리하는 신경망에 사용 가능한 Embedding 레이어 제공
- Embedding 레이어의 입력 데이터는 정수 인코딩되어 각 단어가 고유한 정수로 표현

```Python
e = Embedding(input_dim, output_dim, input_length=100)
```
- input_dim
  - 텍스트 데이터의 어휘 크기
  - ex) 데이터가 0~9 사이의 값으로 정수 인코딩된 경우 어휘의 크기는 10 단어

- output_dim
  - 단어가 표현되는 벡터 공간의 크기
  - 각 단어에 대해 레이어의 출력 벡터 크기 정의
  - ex) 32 또는 100 이상

- input_length
  - 입력 시퀀스의 길이
  - ex) 모든 입력 문서가 100개의 단어로 구성되어 있을 경우 100

- 입력 형태
  - 2D 텐서 (batch_size, sequence_length)의 형태
  - 정수 인코딩 형태이어야 하는 정수의 시퀀스

- 출력 형태
  - 3D 텐서 (batch_size, sequence_length, output_dim)의 형태

##### 예제

```Python
import numpy as np
from tensorflow.keras.layers import Embedding
from tensorflow.keras.models import Sequential

# 입력 형태: (batch_size, input_length)=(32, 3)
# 출력 형태: (None, 3, 4)

model = Sequential()
model.add(Embedding(100, 4, input_length=3))

input_array = np.random.randint(100, size=(32, 3))
model.compile('rmsprop', 'mse')
output_array = model.predict(input_array)
print(output_array.shape)

# 출력
# (32, 3, 4)
```

- 출력 결과

![EXOP](https://github.com/BangYunseo/TIL/blob/main/AI/DeepLearning/Image/ch11/EXOP.PNG)

## 2절. 예제 : 스팸 메일 분류

## 3절. 

## 4절. 
