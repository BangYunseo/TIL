# Chapter 10. 해쉬 암호(Hash Function)

> 1절. Hash Function
>
> 2절. ElGamal Encryption
>
> 3절. Man-in-the-Middle Attack

## 1절. Hash Function

#### 해쉬 함수(Hash Function)

##### 정의

- H(⋅)는 가변 길이 데이터 세트를 고정 길이 데이터 세트로 매핑하는 알고리즘
- 해시 함수 반환 값
  - 해시 값(hash values)
  - 해시 코드(hash codes)
  - 체크섬(checksums)
  - 해시(hashes)
- 메시지 : 암호화하려는 데이터
- (메시지)다이제스트(message digest) : 생성된 해시 값
- 가변 길이 데이터를 고정 크기의 정수로 해시

##### 주요 응용 분야

- 해시 테이블(Hash Tables)

##### 특성

- 전상 이미지 저항성(Pre-image resistance)

  - 해시 값 $h$가 주어졌을 때, $h = H(m)$을 만족하는 임의의 메시지 $m$을 찾을 수 없어야 함

- 두 번째 전상 이미지 저항성 (Second pre-image resistance)

  - 약한 충돌 저항성 (Weak collision resistance)
  - 특정 입력 $m_1$ 이 주어졌을 때, m_1 ≠ m_2 이면서 H(m_1)=H(m_2)을 만족하는 또 다른 입력 m_2를 찾을 수 없어야 함

- 충돌 저항성 (Collision resistance)

서로 다른 두 메시지

m
1
​
과

m
2
​
에 대해

H(m
1
​
)=H(m
2
​
)를 만족하는 경우를 찾는 것이 어려워야 합니다. 이와 같은 메시지 쌍을 **암호학적 해시 충돌 (Cryptographic hash collision)**이라고 합니다.
이 속성은 종종 **강한 충돌 저항성 (Strong collision resistance)**이라고도 불리며, 충돌 저항성을 보장하려면 해시 값의 길이가 전상 이미지 저항성을 보장하는 데 필요한 길이의 두 배 이상이어야 합니다. 그렇지 않으면 **생일 공격 (Birthday attack)**에 의해 충돌이 발견될 수 있습니다.

![HF](https://github.com/BangYunseo/TIL/blob/main/Security/InformationSecurity/Image/ch10/HF.PNG)

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
