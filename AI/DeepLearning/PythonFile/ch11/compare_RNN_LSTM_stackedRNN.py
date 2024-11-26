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
