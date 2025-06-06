# Chapter 8. 공개 키 암호 시스템(Public Key Cryptosystems)

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

2. 앨리스는 $a = 6$을 선택하고 $pk_A = 5^6$ $mod$ $23$ $=$ $8$을 밥에게 전송

3. 밥은 $b = 15$를 선택하고 $pk_B = 5^{15}$ $mod$ $23 = 19$를 앨리스에게 전송

4. 앨리스는 $(pk_B)^a = 19^6$ $mod$ $23 = 2$를 계산

5. 밥은 $(pk_A)^b = 8^{15}$ $mod$ $23 = 2$를 계산

## 2절. ElGamal Encryption

#### 엘가말 암호(EIGamal Encryption)

##### 키 생성

- 앨리스는 소수 차수 $q$를 가진 순환군 $G$와 생성자 $g ∈ G$ 선택
- 앨리스는 개인 키 $x ∈ \{1,…,q−1\}$를 임의로 선택
- 공개 키 $y = g^x$계산

##### 암호(Encryption)

- 밥은 임의의 정수 $r ∈ \{1,…,q−1\}$를 선택
- $c_1 = g^r$ 을 계산
- 메시지 $m ∈ G$ 암호화를 위해 밥은 $c_2=my^r(=mg^{xr})$을 계산
- 밥은 암호문 $(c_1, c_2)$를 앨리스에게 전송

##### 복호화

- 앨리스는 $c_2(c_1^x)^{−1} =
  mg^{xr}(g^{rx})^{−1} = m$ 계산 후 메시지 복호화

##### 결정적 디피-헬만 가정 (Decisional Diffie-Hellman assumption)

- DDH 가정에 따르면, $(g^a, g^b, g^{ab})$와 $(g^a, g^b, g^c)$의 확률 분포가 계산적으로 구분 불가능하다고 가정

- $a, b, c$는 $Z_q$ 에서 임의로 선택된 값

##### 예시

- 키 생성

  - 앨리스는 $G=Z_{19}^∗ (p=19, q=18)$와 $g=10$ 선택

  - 앨리스는 개인 키 $x=5$ 선택 후 공개 키 $y = g^x = 10^5$ $mod$ $19 = 3$ 계산

- 암호화

  - 밥은 $r = 6$을 선택 후 $c_1 = g^r = 10^6$ $mod$ $19 = 11$ 계산

  - 메시지 $m = 17$ 암호화를 위해 밥은 $c_2 = my^r = 17⋅3^6$ $mod$ $19 = 5$ 계산

  - 밥은 암호문 $(c_1, c_2) = (11,5)$를 앨리스에게 전송

- 복호화
  - 앨리스는 $5⋅(11^5)^{−1} ≡ 5⋅(7)^{−1} ≡ 5⋅11 ≡ 17$ ($mod$ $19$)일 때 $m = c_2(c_1^x)^{−1} = 5⋅(11^5)^{−1}$ $mod$ $19 = 17$ 계산 후 메시지 복호화

## 3절. Man-in-the-Middle Attack

#### 중간자 공격(Man-in-the-Middle Attack)

![MiM](https://github.com/BangYunseo/TIL/blob/main/Security/InformationSecurity/Image/ch09/MiM.PNG)

- MITM, MitM, MIM, MiM, MITMA로 축약
- 공격자가 두 당사자 간의 통신을 몰래 중계하고 경우에 따라 통신 내용을 변경하는 공격
- 통신 당사자들은 서로 소통하고 있다고 생각
