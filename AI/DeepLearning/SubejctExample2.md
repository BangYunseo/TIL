# Subject Example

> 1절. 7장 과제
>
> 2절. 8장 과제
>
> 3절. 10장 과제
>
> 4절. 11장 과제

## 1절. 7장 과제

#### keras : MNIST

```Python
import matplotlib.pyplot as plt
import tensorflow as tf
import cv2 as cv

(train_images, train_labels), (test_images, test_labels) = tf.keras.datasets.mnist.load_data()

print(train_images.shape)

print(train_labels)
print(test_images.shape)

plt.imshow(train_images[0], cmap = "Greys")

model = tf.keras.models.Sequential()

model.add(tf.keras.layers.Dense(512, activation = 'relu', input_shape=(784,)))
model.add(tf.keras.layers.Dense(10, activation = 'sigmoid'))

model.compile(optimizer = 'rmsprop',
                loss = 'mse',
                metrics=['accuracy'])

train_images = train_images.reshape((60000, 784))
train_images = train_images.astype('float32') / 255.0
test_images = test_images.reshape((10000, 784))
test_images = test_images.astype('float32') / 255.0

train_labels = tf.keras.utils.to_categorical(train_labels)
test_labels = tf.keras.utils.to_categorical(test_labels)

model.fit(train_images, train_labels, epochs=5, batch_size=128)

test_loss, test_acc = model.evaluate(test_images, test_labels)
print('테스트 정확도 : ', test_acc)

history = model.fit(train_images, train_labels, epochs=5, batch_size=128)
loss = history.history['loss']
acc = history.history['accuracy']
epochs = range(1, len(loss)+1)

plt.plot(epochs, loss, 'b', label='Training Loss')
plt.plot(epochs, acc, 'r', label='Accuracy')
plt.xlabel('epochs')
plt.ylabel('loss/acc')
plt.show()

image = cv.imread('test.png', cv.IMREAD_GRAYSCALE)
image = cv.resize(image, (28, 28))
image = image.astype('float32')
image = image.reshape(1, 784)
image = 255-image
image /= 255.0

plt.imshow(image.reshape(28, 28),cmap='Greys')
plt.show()

pred = model.predict(image.reshape(1, 784), batch_size = 1)
print("추정 숫자 = ", pred.argmax())
```

#### DNN : MNIST

```Python
from tensorflow import keras
import tensorflow as tf
import matplotlib.pyplot as plt
import pandas as pd
import time


class_names = ["T-shirt/top", "Trouser", "Pullover", "Dress", "Coat", "Sandal", "Shirt", "Sneaker", "Bag", "Ankle boot"]

def load_data():

    (X_train_full, y_train_full), (X_test, y_test) = tf.keras.datasets.fashion_mnist.load_data()
    # 훈련 세트는 60,000개의 흑백 이미지
    # 각 이미지의 크기는 28x28 픽셀

    return X_train_full, y_train_full, X_test, y_test


def data_normalization(X_train_full, y_train_full, X_test):

    X_valid, X_train = X_train_full[:5000] / 255., X_train_full[5000:] / 255.
    y_valid, y_train = y_train_full[:5000], y_train_full[5000:]
    X_test = X_test / 255.

    return X_valid, X_train, y_valid, y_train, X_test


def show_oneimg(X_train):
    plt.figure()
    plt.imshow(X_train[0], cmap = "binary")
    plt.axis('off')


def show_40images(X_train, y_train):
    n_rows = 4
    n_cols = 10
    plt.figure(figsize=(n_cols * 1.2, n_rows * 1.2))
    for row in range(n_rows):
        for col in range(n_cols):
            index = n_cols * row + col
            plt.subplot(n_rows, n_cols, index + 1) # figure 안의 figure를 사용하는 함수
            plt.imshow(X_train[index], cmap = "binary", interpolation = "nearest")
            plt.axis('off')
            plt.title(class_names[y_train[index]], fontsize=12)
    plt.subplots_adjust(wspace=0.2, hspace=0.5)
    plt.show()


def makemodel(X_train, y_train, X_valid, y_valid):
    model = keras.models.Sequential()
    model.add(keras.layers.Flatten(input_shape = [28, 28]))
    # 입력층 (28 * 28 = 784)
    model.add(keras.layers.Dense(300, activation = "relu"))
    # 은닉층 1 : 300개
    model.add(keras.layers.Dense(100, activation = "relu"))
    # 은닉층 2 : 100개
    model.add(keras.layers.Dense(10, activation = "softmax"))
    # 출력층 : 10개

    # (784 * 300 + 300) + (300 * 100 + 100) + (100 * 10 + 10) = 266,610
    # 학습 필요 데이터

    model.summary()

    model.compile(loss = "sparse_categorical_crossentropy",
                  optimizer = "sgd",
                  metrics = ["accuracy"])

    # 시간 측정
    tb_hist = keras.callbacks.TensorBoard(log_dir = './graph',
                                          histogram_freq = 0,
                                          write_graph = True,
                                          write_images = True)
    start = time.time()
    history = model.fit(X_train, y_train, epochs = 10,
                        validation_data = (X_valid, y_valid),
                        callbacks = [tb_hist])
    print("time : ", time.time() - start)
    return model, history


def evalmodel(model, history, X_test, y_test):
    model.evaluate(X_test, y_test)

    X_new = X_test[:3]
    # 3개만 보여지는 데이터셋
    y_proba = model.predict(X_new).round(2)

    plt.figure(figsize = (7.2, 2.4))
    for index, image in enumerate(X_new):
        plt.subplot(1, 3, index + 1)
        plt.imshow(image, cmap = "binary", interpolation = "nearest")
        plt.axis('off')
        plt.title(class_names[y_test[index]], fontsize = 12)
    plt.subplots_adjust(wspace = 0.2, hspace = 0.5)

    pd.DataFrame(history.history).plot(figsize = (8, 5))
    plt.grid(True)
    plt.gca().set_ylim(0, 1)

def main():
    X_train_full, y_train_full, X_test, y_test = load_data()

    X_valid, X_train, y_valid, y_train, X_test = data_normalization(X_train_full, y_train_full, X_test)
    show_oneimg(X_train)
    show_40images(X_train, y_train)
    model, history = makemodel(X_train, y_train, X_valid, y_valid)
    evalmodel(model, history, X_test, y_test)
    plt.show()

main()
```

## 2절. 8장 과제

#### CNN : MNIST

```Python
from tensorflow.keras import Model
from tensorflow import keras
from tensorflow.keras.models import Sequential
from tensorflow.keras.layers import Dense, Dropout, Flatten
from tensorflow.keras.layers import Conv2D, MaxPooling2D
from tensorflow.keras.datasets import mnist
import matplotlib.pyplot as plt
import numpy as np
import time
import random

def load_data():

    (X_train_full, y_train_full), (X_test, y_test) = mnist.load_data()
    X_train_full = X_train_full.astype(np.float32)
    X_test = X_test.astype(np.float32)

    return X_train_full, y_train_full, X_test, y_test

def data_normalization(X_train_full, X_test):
    X_train_full = X_train_full / 255.

    X_test = X_test / 255.
    train_feature = np.expand_dims(X_train_full, axis=3)
    test_feature = np.expand_dims(X_test, axis=3)

    print(train_feature.shape, train_feature.shape)
    print(test_feature.shape, test_feature.shape)

    return train_feature,  test_feature


def draw_digit(num):
    for i in num:
        for j in i:
            if j == 0:
                print('0', end='')
            else :
                print('1', end='')
        print()


def makemodel(X_train, y_train, X_valid, y_valid, weight_init):
    model = Sequential()
    model.add(Conv2D(32, kernel_size=(3, 3), input_shape=(28, 28, 1), activation='relu'))
    # n1 = 32
    model.add(MaxPooling2D(pool_size=2))
    model.add(Conv2D(64, kernel_size=(3, 3), activation='relu'))
    # n2 = 64 = bias
    # 즉, 32 * 3 * 3 * 64 + 64
    model.add(MaxPooling2D(pool_size=2))
    model.add(Dropout(0.25))
    model.add(Flatten())
    model.add(Dense(128, activation = 'relu'))
    model.add(Dense(10, activation = 'softmax'))

    model.compile(loss = 'sparse_categorical_crossentropy',
                  optimizer = 'adam',
                  metrics = ['accuracy'])

    #tb_hist = keras.callbacks.TensorBoard(log_dir='./graph', histogram_freq=0, write_graph=True, write_images=True)
    start = time.time()
    history = model.fit(X_train, y_train, epochs = 10,
                        validation_data=(X_valid, y_valid)) #callbacks=[tb_hist])
    print("time :", time.time() - start)
    return model, history

def plot_history(histories, key='accuracy'):
    plt.figure(figsize=(16,10))

    for name, history in histories:
        val = plt.plot(history.epoch, history.history['val_'+key],
                       '--', label=name.title()+' Val')
        plt.plot(history.epoch, history.history[key], color=val[0].get_color(),
                 label=name.title()+' Train')

    plt.xlabel('Epochs')
    plt.ylabel(key.replace('_',' ').title())
    plt.legend()

    plt.xlim([0,max(history.epoch)])
    plt.show()

def draw_prediction(pred, k,X_test,y_test,yhat):
    samples = random.choices(population=pred, k=16)

    count = 0
    nrows = ncols = 4
    plt.figure(figsize=(12,8))

    for n in samples:
        count += 1
        plt.subplot(nrows, ncols, count)
        plt.imshow(X_test[n].reshape(28, 28), cmap='Greys', interpolation='nearest')
        tmp = "Label:" + str(y_test[n]) + ", Prediction:" + str(yhat[n])
        plt.title(tmp)

    plt.tight_layout()
    plt.show()

def evalmodel(X_test,y_test,model):
    yhat = model.predict(X_test)
    yhat = yhat.argmax(axis=1)

    print(yhat.shape)
    answer_list = []

    for n in range(0, len(y_test)):
        if yhat[n] == y_test[n]:
            answer_list.append(n)

    draw_prediction(answer_list, 16,X_test,y_test,yhat)

    answer_list = []

    for n in range(0, len(y_test)):
        if yhat[n] != y_test[n]:
            answer_list.append(n)

    draw_prediction(answer_list, 16,X_test,y_test,yhat)

def main():
    X_train, y_train, X_test, y_test = load_data()
    X_train, X_test = data_normalization(X_train,  X_test)

    #show_oneimg(X_train)
    #show_40images(X_train, y_train)

    model, history= makemodel(X_train, y_train, X_test, y_test,'glorot_uniform')

    evalmodel(X_test, y_test, model)
    plot_history([('baseline', history)])

main()
```

## 3절. 10장 과제

#### Simple RNN

```Python
import numpy as np
import tensorflow as tf
from keras.models import Sequential
from keras.layers import Dense, SimpleRNN, Activation

X = []
Y = []
for i in range(6):
    lst = list(range(i,i+4))
    X.append(list(map(lambda c: [c/10], lst)))
    Y.append((i+4)/10)
X = np.array(X)
Y = np.array(Y)
print(X)
print(Y)



model = Sequential()
#model.add(SimpleRNN(50,  return_sequences=False, input_shape=(4,1)))
model.add(SimpleRNN(20,  return_sequences = False, input_shape=(4,1)))
model.add(Dense(1))
model.summary()
model.compile(loss='mse',
              optimizer='adam',
              metrics=['accuracy'])
model.fit(X,Y,epochs=200,  verbose=2)
print(model.predict(X))

X_test = np.array([[[0.8],[0.9],[1.0],[1.1]]])
print(model.predict(X_test))
```

## 4절. 11장 과제

#### Compare RNN LSTM

```Python
import numpy as np
import tensorflow as tf
from keras.models import Sequential
from keras.layers import Dense, SimpleRNN, Activation, LSTM
import matplotlib.pyplot as plt
import pandas as pd

def make_data_increase_linear():
  trainX = []
  trainY = []
  testX= []
  testY = []
  for i in range(4):
      lst = list(range(i,i+4))
      trainX.append(list(map(lambda c: [c/10], lst)))
      trainY.append((i+4)/10)
  trainX = np.array(trainX)
  trainY = np.array(trainY)
  lst = list(range(i,i+4))
  testX.append(list(map(lambda c: [c/10], lst)))
  testY.append((i+4)/10)

  return trainX,trainY,testX,testY

# convert into dataset matrix
def convertToMatrix(data, step):
    X, Y = [], []
    for i in range(len(data) - step):
        d = i + step
        X.append(data[i:d, ])
        Y.append(data[d, ])
    return np.array(X), np.array(Y)

def make_data_random_sin():
  # 데이터 생성
  N = 1000
  Tp = 800
  step = 4
  t = np.arange(0, N)
  x = np.sin(0.2*t) + 0.5 * np.random.rand(N)  # 노이즈 추가된 SIN 파
  df = pd.DataFrame(x)

  # Train/Test 데이터 분리
  values = df.values
  train, test = values[:Tp], values[Tp:]

  # 데이터 자르기
  train = np.append(train, np.repeat(train[-1], step))
  test = np.append(test, np.repeat(test[-1], step))
  trainX, trainY = convertToMatrix(train, step)
  testX, testY = convertToMatrix(test, step)

  # 데이터 Reshape
  trainX = np.reshape(trainX, (trainX.shape[0], trainX.shape[1],1))
  testX = np.reshape(testX, (testX.shape[0], testX.shape[1], 1))
  return trainX, trainY, testX,testY

def plot_history(histories):
  plt.figure(figsize=(16,10))


  for name, history in histories:
    plt.plot(history.epoch, history.history['loss'],label=name.title())

  plt.xlabel('Epochs')
  plt.legend()

  plt.xlim([0,max(history.epoch)])
  plt.show()


def makemodel(model_name,trainX, trainY, stacked_size):

  model = Sequential()
  #model.add(SimpleRNN(50,  return_sequences=False, input_shape=(4,1)))
  if stacked_size > 1 :
     for i in range(stacked_size) :
         model.add(model_name(20,  return_sequences=True, input_shape=(4,1)))
  model.add(model_name(20,  return_sequences=False, input_shape=(4,1)))
  model.add(Dense(1))
  model.summary()
  model.compile(loss='mse',
                optimizer='adam',
                metrics=['accuracy'])
  hist = model.fit(trainX,trainY,epochs=100)
  return model, hist

#단순히 0.1씩 증가 하는 데이터
#trainX, trainY, testX, testY =  make_data_increase_linear()

#sin 함수에 랜덤 값을 추가한 데이터
trainX, trainY, testX, testY =  make_data_random_sin()

model_simpleRNN, hist_simpleRNN = makemodel(SimpleRNN, trainX,  trainY, 1)

model_LSTM, hist_LSTM = makemodel(LSTM, trainX, trainY, 1)

model_stackeRNN, hist_stackeRNN = makemodel(SimpleRNN, trainX, trainY, 3)

X_test = np.array([[[0.8],[0.9],[1.0],[1.1]]])

print(model_simpleRNN.predict(X_test))
print(model_LSTM.predict(X_test))
print(model_stackeRNN.predict(X_test))


plot_history([('SimpleRNN', hist_simpleRNN),('SimpleLSTM', hist_LSTM),('StackedRNN', hist_stackeRNN)])
```
