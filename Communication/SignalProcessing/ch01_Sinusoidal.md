#  Chapter 0. 정현파
> 1절. 정현파 변화
>
> 2절. 극좌표
>
> 3절. 신호

## 1절. 정현파 변화
#### 수식과 그래프
* $5cos(0.3𝝿t+1.2𝝿)$

![GraphEx1](https://github.com/BangYunseo/TIL/blob/main/Communication/SignalProcessing/Image/ch00/GraphEx1.jpg)

* 주기$(T)$ = $\frac{1}{f}$ 임을 고려하면 $\frac{2𝝿}{0.3𝝿} = \frac{20}{3}$. 즉, 6.6666...의 주기
* 시작점 $= (wt+φ) = 0$인 지점을 구하기 위해 $(0.3𝝿t+1.2𝝿) = 0$인 t의 값 필요
* $t = -\frac{1.2𝝿}{0.3𝝿} = -4$ 이므로 $t$의 값이 $-4$일 때, $cos(0) = 1$의 값을 가짐

#### 시간 이동(TIME-SHIFT)
* 만약 $t_m$만큼 shift된 경우 아래의 식으로 표현
    * $x(t-t_m)=Acos(w(t-t_m))$
        * $x(t-t_m)$은 $t_m$만큼 $t$축 상에서 이동시킨 것으로 아래 사진처럼 구분

![PosNe](https://github.com/BangYunseo/TIL/blob/main/Communication/SignalProcessing/Image/ch00/PosNe.jpg)

* 정현파에서의 시간 이동
    * $x(t+4)
    =5cos(0.3𝝿(t+4))
    =5cos(0.3𝝿(t-(-4)))
    =5cos(0.3𝝿t+1.2𝝿)$
* 위상과 시간이동의 관계
    * $Acos(w(t-t_m))
    =Acos(wt+φ)$
        * $-wt_m = φ$ or $t_m = -\frac{φ}{w}$

#### A, W, φ으로 표현하는 그래프(진폭, 주파수, 위상)

![GraphEx2](https://github.com/BangYunseo/TIL/blob/main/Communication/SignalProcessing/Image/ch00/GraphEx2.jpg)

#### 위상의 모호함
* cos함수의 주기성 : $2𝝿$ 간격
* $Acos(wt+φ+2𝝿)
    =Acos(wt+φ)$
    * 정현파는 $2𝝿$ 간격으로 반복되기 때문에 그의 배수를 더해도 값은 동일

## 2절. 극좌표
#### 복소수
* 실수 + 허수 == 복소수
* 복소수는 Z, 실수는 X, 허수는 y로 값 표현
* 기본적인 허수의 단위 = j

##### ex : $Z = 3 + j2$ 표현(직교좌표)

![GraphEx3](https://github.com/BangYunseo/TIL/blob/main/Communication/SignalProcessing/Image/ch00/GraphEx3.jpg)

#### 벡터로 표현한 복소수
* 벡터는 크기와 방향 존재

![GraphEx4](https://github.com/BangYunseo/TIL/blob/main/Communication/SignalProcessing/Image/ch00/GraphEx4.jpg)

#### 극좌표(크기 = $|Z|$, 각도 = $θ$)