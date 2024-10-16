#  Chapter 4. 퍼셉트론(Perceptron)

> 1절. 신경망
>
> 2절. 퍼셉트론


## 1절. 신경망
#### 개요
* 딥러닝의 시작 : 1950년대 인공 신경망(Artificial Neural Network : ANN)부터 시작


#### 퍼셉트론
* 1957년 프랑크 로젠블라트가 고안한 신경망의 기원이 되는 알고리즘
* 인공 뉴런으로 다수의 신호를 입력으로 받아 하나의 신호를 출력하는 것

![ANN](https://github.com/BangYunseo/TIL/blob/main/AI/DeepLearning/Image/ch04/ANN.PNG)

#### 컴퓨터 vs 인공신경망

![CAI](https://github.com/BangYunseo/TIL/blob/main/AI/DeepLearning/Image/ch04/CAI.PNG)

#### 신경망 장점
* 학습이 가능
    * 데이터만 주어진다면 예제로부터 배울 수 있음
* 몇 개의 소자가 오동작하더라도 전체적으로는 큰 문제 발생 X

#### 신경망 분야
* 인간이 인식할 수 있는 이미지 클래스가 존재하는 분야
* 만약, 인간도 인식의 메커니즘을 모른다면?
    * 인식 알고리즘 제작 불가능

#### 뉴런을 사용한 논리 연산

![1234](https://github.com/BangYunseo/TIL/blob/main/AI/DeepLearning/Image/ch04/1234.PNG)

* 1) 항등함수를 의미 
    * 뉴런 A가 활성화될 경우 뉴런 C도 활성화
* 2) 논리곱 연산을 의미
    * 뉴런 A와 B가 모두 활성화될 경우 뉴런 C 활성화
* 3) 논리합 연산 의미
    * 뉴런 A와 B 둘 중 하나라도 활성화될 경우 뉴런 C 활성화
* 4) 어떤 입력이 뉴런의 활성화를 억제할 수 있다고 가정
    * 위의 그림처럼 뉴런 A가 활성화되고 뉴런 B가 비활성화일 경우 뉴런 C 활성화

#### 퍼셉트론(Perceptron)
* 1957년에 로젠블라트(Frank Rosenblatt)가 고안한 인공 신경망
* 신호
    * 두 가지 종류 
        * 흐른다 - 1
        * 흐르지 않는다 - 0
    * 입력 신호 : $x_1$, $x_2$
    * 출력 신호 : $y$
    * 가중치 : $w_1$, $w_2$(w => weight의 머리글자)
    * 퍼셉트론에서는 가중치가 클수록 강한 신호 흘림
    * 전류에서 말하는 저항
