#  Chapter 3. 유클리드 호제법
> 1절. Division Algorithm
> 
> 2절. Greatest Common Divisor(GCD)
>
> 3절. Euclidean Algorithm
>
> 4절. The Modulus
>
> 5절. $Z_n$
>
> 6절. Extended Euclidean Algorithm

## 1절. Division Algorithm
#### Divisivility
* $a, b, m$이 모두 정수일 때 $m$에 대해 $a = mb$가 성립한다면 0이 아닌 숫자 $b$는 $a$를 나눔
    * $b | a$는 $b$가 $a$를 나눈다는 것을 의미
    * $b | a$일 때, $b$는 $a$의 약수
    * 예시
        * $24$의 양의 약수는 $1, 2, 3, 4, 6, 8, 12, 24$
        * 비슷한 예시
            * $13|182$
            * $-5|30$
            * $17|289$
            * $-3|33$
            * $17|0$

#### Divisivility의 특성
* 만약 $a|1$ 이라면, $a = ±1$
    * a가 1의 약수
* 만약 $a|b$ 와 $b|a$ 이라면, $a = ±b$
    * 절댓값이 동일
* 0이 아닌 b는 0으로 나눠짐
* $a | b$와 $b | c$가 성립한다면, $a | c$도 성립
* $b | g$ 와 $b | h$가 성립한다면, $b | (mg + nh) $도 $m$과 $n$이 선형결합에 의해 성립

#### 나눗셈 알고리즘(Divisibility Algorithm)
* 양의 정수 n과 정수 a가 주어지면 a를 n으로 나누고 정수 몫 q와 정수 나머지 r을 얻음
    > $a = qn + r$ 의 수식으로 표현 가능   
    > 조건 : $0 ≤  r < n$  and  $ q = [a/n]$
* $[x]$는 $x$보다 작거나 같은 가장 큰 정수
* 예시

![DA](https://github.com/BangYunseo/TIL/blob/main/Security/InformationSecurity/Image/ch03/DA.PNG)

## 2절. Greatest Common Divisor(GCD)
#### 최대공약수
* 정수 $p > 1$은 약수가 $±1$과 $±p$뿐인 경우 소수
    * $2, 3, 5, 7, 11, 13, 17, 19, …$
* a와 b의 최대공약수는 a와 b가 동시에 나눠지는 가장 큰 양의 정수
    * $gcd(a, b)$ = max[k, $k|a$ 와 $k|b$인 a와 b의 공약수 중 가장 큰 수]
    * $gcd(a, b) = gcd(a, −b) = gcd(−a, b) = gcd(−a, −b)$
        * 부호와 관계 없는 최대공약수
    * $gcd(60, 24) = gcd(60, −24) = 12$
* 두 정수의 유일한 공약수가 1인 경우 그 둘은 서로소에 해당
    * 만약 gcd(a, b) = 1인 경우 두 정수 a와 b가 소수
    * 8과 15
        * 각 숫자는 소수가 아님
        * 두 숫자는 서로소에 해당(최대공약수가 1)

## 3절. Euclidean Algorithm
#### 유클리드 알고리즘 : GCD
* GCD는
