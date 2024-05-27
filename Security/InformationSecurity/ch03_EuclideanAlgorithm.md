#  Chapter 3. 유클리드 호제법
> 1절. Division Algorithm
> 
> 2절. Greatest Common Divisor
>
> 3절. Euclidean Algorithm
>
> 4절. The Modulus
>
> 5절. $Z_n$
>
> 6절. Extended Euclidean Algorithm

## 1절. Division Algorithm
#### 나눠지는가 ? (Divisivility)
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

* 나눗셈의 특성
    * 만약 $a|1$ 이라면, $a = ±1$
        * a가 1의 약수
    * 만약 $a|b$ 와 $b|a$ 이라면, $a = ±b$