#  Chapter 1. 넘파이(Numpy)
> 1절. Numpy
>
> 2절. Numpy 함수
>
> 3절. 


## 1절. Numpy
#### 넘파이(Numpy)란?

![Numpy](https://github.com/BangYunseo/TIL/blob/main/AI/DeepLearning/Image/ch01/Numpy.PNG)


![Numpy2](https://github.com/BangYunseo/TIL/blob/main/AI/DeepLearning/Image/ch01/Numpy2.PNG)

* 넘파이 라이브러리에는 다차원 배열 데이터 구조 포함
* 다양한 수학적 행렬 연산 수행 시 사용

#### 딥러닝에서의 넘파이
* 왜 딥러닝에서 넘파이가 중요할까?
    * 훈련 샘플이 2차원 or 3차원 행렬에 저장되기 때문
    * 4차원 이상으로 넘어갈 시 값이 매우 커져서 오히려 구하기 힘듦

![Numpy3](https://github.com/BangYunseo/TIL/blob/main/AI/DeepLearning/Image/ch01/Numpy3.PNG)

#### Numpy 모듈 불러오기
```Python
import numpy as np
```

#### Numpy 모듈 사용 예시

```Python
import numpy as np
a = np.array([1, 2, 3])
a
# array([1, 2, 3])

a[0]
# 1
```

* 2차원 배열에서의 사용
```Python
import numpy as np
b = np.array([[1, 2, 3], [4, 5, 6], [7, 8, 9]])
b
# array([[1, 2, 3], [4, 5, 6], [7, 8, 9]])

b[0][2]
# 3
```

* 배열의 인덱스는 일반적으로 0부터 시작

![NumpyIndex](https://github.com/BangYunseo/TIL/blob/main/AI/DeepLearning/Image/ch01/NumpyIndex.PNG)

## 2절. Numpy 함수
#### 넘파이 배열 속성
* 배열의 차원 및 항목 수는 형상(shape)에 의해 정의
* 배열의 형상은 각 차원의 크기를 지정하는 정수의 튜플
* 넘파이에서 차원은 축(axes)

![NumpyShape](https://github.com/BangYunseo/TIL/blob/main/AI/DeepLearning/Image/ch01/NumpyShape.PNG)

![NumpyShape2](https://github.com/BangYunseo/TIL/blob/main/AI/DeepLearning/Image/ch01/NumpyShape2.PNG)

![NumpyShape3](https://github.com/BangYunseo/TIL/blob/main/AI/DeepLearning/Image/ch01/NumpyShape3.PNG)

* 사용 코드
```Python
import numpy as np
a = np.array([[0, 1, 2], [3, 4, 5], [6, 7, 8]])

a.shape         # 배열의 형상
# (3, 3)

a.ndim          # 배열의 차원 
# 2

a.dtype         # 요소의 자료형
# dtype('int32')

a.size          # 전체 요소의 개수
# 9
```

#### zeros(), eye(), ones() 함수

```Python
import numpy as np
# (3, 4)는 배열의 형상
# (행 개수, 열 개수)

np.zeors((3, 4))
# array([[0., 0., 0., 0.],
# [0., 0., 0., 0.],
# [0., 0., 0., 0.]]) 

np.ones((3, 4))
# array([[1, 1, 1, 1], 
# [1, 1, 1, 1], 
# [1, 1, 1, 1]])

np.eye(3)
# array([[1., 0., 0.],
# [0., 1., 0.], 
# [0., 0., 1.]])
```

![NumpyFunc](https://github.com/BangYunseo/TIL/blob/main/AI/DeepLearning/Image/ch01/NumpyFunc.PNG)

#### arrange() 함수
```Python
import numpy as np
np.arrange(5)
# array([0, 1, 2, 3, 4])

# 시작값을 지정하려고 할 경우
np.arrange(1, 6)
# array([1, 2, 3, 4, 5])

# 증가되는 간격을 지정하려고 할 경우
np.arrange(1, 10, 2)
# array([1, 3, 5, 7, 9])
```

![Arrange](https://github.com/BangYunseo/TIL/blob/main/AI/DeepLearning/Image/ch01/Arrange.PNG)

#### linspace() 함수
```Python
import numpy as np
np.linspace(0, 10, 100)
# array([ 0. ,  0.1010101 ,  0.2020202 ,  0.3030303 ,  0.4040404 ,
# ...
# 8.08080808,  8.18181818,  8.28282828,  8.38383838,  8.48484848, 
# 8.58585859,  8.68686869,  8.78787879,  8.88888889,  8.98989899, 
# 9.09090909,  9.19191919,  9.29292929,  9.39393939,  9.49494949, 
# 9.5959596 ,  9.6969697 ,  9.7979798 ,  9.8989899 , 10.])
```

![Linspace](https://github.com/BangYunseo/TIL/blob/main/AI/DeepLearning/Image/ch01/Linspace.PNG)

#### concatenate(), vstack() 함수
* 배열 Addition 함수

##### concatenate()
* 가로로 Addition
```Python
import numpy as np
x = np.array([[1, 2], [3, 4]])
y = np.array([[5, 6], [7, 8]])

np.concatenate((x, y), axis = 1)
# array([[1, 2, 5, 6],
# [3, 4, 7, 8]])
```

![Concatenate](https://github.com/BangYunseo/TIL/blob/main/AI/DeepLearning/Image/ch01/Concatenate.PNG)

##### vstack()
* 세로로 Addition
```Python
import numpy as np
x = np.array([[1, 2], [3, 4]])
y = np.array([[5, 6], [7, 8]])

np.vstack((x, y))
# array([[1, 2],
# [3, 4], 
# [5, 6],
# [7, 8]])
```

![Vstack](https://github.com/BangYunseo/TIL/blob/main/AI/DeepLearning/Image/ch01/Vstack.PNG)

#### reshape() 함수

![Reshape](https://github.com/BangYunseo/TIL/blob/main/AI/DeepLearning/Image/ch01/Reshape.PNG)

```Python
import numpy as np
a = np.arrange(12)
# array([0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11])

# a에 대하여 reshape(3, 4)를 호출하면 2차원 배열로 변형
a.reshape(3, 4)
# array([0, 1, 2, 3],
# [4, 5, 6, 7], 
# [8, 9, 10, 11])

# reshape() 함수의 매개 변수(parameter)의 곱을 요소의 전체 개수와 맞출 때, 하나의 매개 변수만 작성 후 다른 매개 변수를 -1로 쓰더라도 정상적인 넘파이 배열 출력 가능
a.reshape(6, -1)
# array([0, 1],
# [2, 3],
# [4, 5],
# [6, 7],
# [8, 9],
# [10, 11])
```

#### split() 함수
* 배열 분할 함수

```Python
import numpy as np
array = np.arrange(30).reshape(-1, 10)
array
# array([[0, 1, 2, 3, 4, 5, 6, 7, 8, 9],
# [10, 11, 12, 13, 14, 15, 16, 17, 18, 19],
# [20, 21, 22, 23, 24, 25, 26, 27 , 28, 29]])

arr1, arr2 = np.split(array, [3], axis = 1)
# 두 번째 매개 변수를 기준으로 잘라짐

arr1
# array([[0, 1, 2],
# [10, 11, 12],
# [20, 21, 22]])

arr2
# array([[3, 4, 5, 6, 7, 8, 9],
# [13, 14, 15, 16, 17, 18, 19],
# [23, 24, 25, 26, 27, 28, 29]])
```

#### newaxis 함수
* 배열에 새로운 축 추가 함수
```Python
a = np.array([1, 2, 3, 4, 5, 6])
a.shape
# (6,)
# 1차원 함수

a1 = a[np.newaxis, :]
a1 
# array([[1, 2, 3, 4, 5, 6]])
a1.shape
# (1, 6)
# 2차원 함수이며 행이 1, 열이 6

a2 = a[:, np.newaxis] 
array([[1],
[2],
[3],
[4],
[5],
[6]])
a2.shape 
# (6, 1)
# 2차원 함수이며 행이 6, 열이 1
```

#### 인덱싱과 슬라이싱
