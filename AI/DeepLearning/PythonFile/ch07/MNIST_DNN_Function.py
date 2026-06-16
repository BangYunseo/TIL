from tensorflow import keras
import tensorflow as tf
import matplotlib.pyplot as plt
import pandas as pd
import time


class_names = ["T-shirt/top", "Trouser", "Pullover", "Dress", "Coat",
               "Sandal", "Shirt", "Sneaker", "Bag", "Ankle boot"]

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
