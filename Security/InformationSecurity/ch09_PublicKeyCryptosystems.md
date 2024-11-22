# Chapter 9. 공개 키 암호 시스템(Public Key Cryptosystems)

> 1절. Diffie-Hellman Key
>
> 2절. ElGamal Encryption
>
> 3절. Man-in-the-Middle Attack

## 1절. Diffie-Hellman Key

#### 디피-헬먼 키 교환(Diffie-Hellman Key Exchange)

##### 역사

- 1976년 Whitfield Diffie와 Martin Hellman에 의해 처음 발표

- 몇 년 전 영국 정부 통신 본부(GCHQ)에서 별도로 개발되었으나 기밀로 유지

##### 키 교환

- 사전 정보가 없는 두 당사자가 안전하지 않은 통신 채널에서 공동으로 공유 비밀 키를 설정

##### 디피-헬만 문제 계산

- $g$를 어떤 그룹 $G$의 생성자로 설정
- 임의로 선택된 정수
  $x$와 $y$에 대해, DHP는 아래처럼 정의

  - 주어진 요소
    $g$와 값 $g^x$, $g^y$ 로부터
    $g^{xy}$ 의 값 계산

- 이산 로그 문제(DLP)만큼 어려운 난이도

##### 공식(Scheme)

1. 앨리스와 밥은 순환 그룹 소수 차수 $q$의 $G$와 생성자 $g∈G$에 합의  
   (소수 차수의 순환 그룹이 권장)

2. 앨리스는 $1 ≤ a < q$ 범위의 랜덤 정수 $a$ 선택 후 $pk_A = g^a$를 밥에게 전송

3. 밥은 $1 ≤ b < q$ 범위의 랜덤 정수 $b$ 선택 후 $pk_B=g^b$를 앨리스에게 전송

4. 앨리스는 $(pk_B)^a = (g^b)^a=g^{ab}$ 계산
5. 밥은 $(pk_A)^b = (g^a)^b=g^{ab}$ 계산

##### 예시

1. 앨리스와 밥은 $G=Z_{23}^∗$ $(p=23, q=22)$및 $g=5$에 동의

2. 앨리스는 $a = 6$을 선택하고 pk
   A
   ​
   =5
   6
   mod23=8을 밥에게 전송
   밥은
   𝑏
   =
   15
   b=15를 선택하고
   𝑝
   𝑘
   𝐵
   =
   5
   15
   m
   o
   d

# 23

19
pk
B
​
=5
15
mod23=19를 앨리스에게 보냅니다.
앨리스는
(
𝑝
𝑘
𝐵
)
𝑎
=
1
9
6
m
o
d

# 23

2
(pk
B
​
)
a
=19
6
mod23=2를 계산합니다.
밥은
(
𝑝
𝑘
𝐴
)
𝑏
=
8
15
m
o
d

# 23

2
(pk
A
​
)
b
=8
15
mod23=2를 계산합니다.

## 2절. ElGamal Encryption

#### 엘가말 암호(EIGamal Encryption)

![CP](https://github.com/BangYunseo/TIL/blob/main/Security/InformationSecurity/Image/ch08/CP.PNG)
