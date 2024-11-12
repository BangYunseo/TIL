from tensorflow.keras import Model
from tensorflow import keras
from tensorflow.keras.models import Sequential
from tensorflow.keras.layers import Dense, Dropout, Flatten
from tensorflow.keras.layers import Conv2D, MaxPooling2D
from tensorflow.keras.datasets import mnist
import matplotlib.pyplot as plt
import numpy as np
import time

def load_data():
    # MNIST 데이터셋 로드
    # 케라스는 `keras.datasets`에 널리 사용하는 데이터셋을 로드하기 위한 함수를 제공합니다. 
    # 이 데이터셋은 이미 훈련 세트와 테스트 세트로 나누어져 있습니다. 
    # 훈련 세트를 더 나누어 검증 세트를 만드는 것이 좋습니다

    (X_train_full, y_train_full), (X_test, y_test) = mnist.load_data()
    X_train_full = X_train_full.astype(np.float32)
    X_test = X_test.astype(np.float32)
    #print(X_train_full.shape, y_train_full.shape)
    #print(X_test.shape, y_test.shape)
    return X_train_full, y_train_full, X_test, y_test

def data_normalization(X_train_full, X_test):
    # 전체 훈련 세트를 검증 세트와 (조금 더 작은) 훈련 세트로 나누어 보죠. 또한 픽셀 강도를 255로 나누어 0~1 범위의 실수로 바꾸겠습니다.

    X_train_full = X_train_full / 255\

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


    return model

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
import random


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
