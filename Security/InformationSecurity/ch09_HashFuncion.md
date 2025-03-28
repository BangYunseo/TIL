# Chapter 9. 해쉬 함수(Hash Function)

> 1절. Hash Function
>
> 2절. 해쉬 함수의 이상적인 구조
>
> 3절. SHA
>
> 4절. Salting

## 1절. Hash Function

#### 해쉬 함수(Hash Function)

##### 정의

![HF](https://github.com/BangYunseo/TIL/blob/main/Security/InformationSecurity/Image/ch10/HF.PNG)

- $H(⋅)$는 가변 길이 데이터 세트를 고정 길이 데이터 세트로 매핑하는 알고리즘
- 해쉬 함수 반환 값
  - 해쉬 값(hash values)
  - 해쉬 코드(hash codes)
  - 체크섬(checksums)
  - 해쉬(hashes)
- 메시지 : 암호화하려는 데이터
- (메시지)다이제스트(message digest) : 생성된 해쉬 값
- 가변 길이 데이터를 고정 크기의 정수로 해쉬

##### 주요 응용 분야

- 해쉬 테이블(Hash Tables)

##### 특성

- 전상 이미지 저항성(Pre-image resistance)

  - 해쉬 값 $h$가 주어졌을 때, $h = H(m)$을 만족하는 임의의 메시지 $m$을 찾을 수 없어야 함

- 두 번째 전상 이미지 저항성 (Second pre-image resistance)

  - 약한 충돌 저항성 (Weak collision resistance)
  - 특정 입력 $m_1$ 이 주어졌을 때, $m_1 ≠ m_2$ 이면서 $H(m_1)=H(m_2)$을 만족하는 또 다른 입력 $m_2$를 찾을 수 없어야 함

- 충돌 저항성 (Collision resistance)

  - 암호학적 해쉬 충돌 (Cryptographic hash collision)
  - 강한 충돌 저항성 (Strong collision resistance)
  - 충돌 저항성 보장
    - 해쉬 값의 길이 : 전상 이미지 저항성을 보장하는 데 필요한 길이 두 배 이상
  - 서로 다른 두 메시지 $m_1$과 $m_2$에 대해 $H(m_1)=H(m_2)$를 만족하는 경우를 찾을 수 없어야 함

##### 생일 공격 (Birthday attack)

- 생일 문제

  - 개념 : 무작위로 선택된 그룹에서 최소 두 사람이 같은 생일을 가질 확률
  - 비둘기집 원리 : 한 방에 366명이 있다면 윤년의 2월 29일을 제외하고 최소 두 사람이 같은 생일을 가질 확률은 100%
  - 50% 확률 : 23명이 있을 때, 최소 두 사람이 같은 생일을 가질 확률 50%

- 생일 공격

  - 목표 : 주어진 해쉬 함수 $H(⋅)$에 대해 충돌(collision) 탐색
  - 해쉬 충돌 조건 :
    - 해쉬 함수가 $N$개의 서로 다른 출력을 균등한 확률로 생성
    - 충돌 확률이 50% 이상이 되려면 $H$를 약 $α ≈ N$번 적용
  - 예 : $N=2^{160}$인 경우, $α ≈ 2^{80}$

#### 보안 수준(Security Level)

- 해쉬 코드의 길이가 n일 때, 요구되는 작업량

![SL](https://github.com/BangYunseo/TIL/blob/main/Security/InformationSecurity/Image/ch10/SL.PNG)

## 2절. 해쉬 함수의 이상적인 구조

#### 해쉬 알고리즘

- 압축 함수 f의 반복 사용으로 구성
- 압축 함수 $f$는 두 입력값 처리 후 n-비트 출력을 생성

  - 이전 단계의 n-비트 입력(체이닝 변수, Chaining Variable)
  - b-비트 블록 입력

> $CV_0 = IV =$ 초기 n-bit 값  
> $CV_i = f(CV_{i−1}, Y_{i−1})$ $1 ≤ i ≤ L$일 때  
> $H(M) = CV_L$

- 해시 함수의 입력은 블록 $Y_0, Y_1, …, Y_{L−1}$ ​로 구성된 메시지 $M$

![HF2](https://github.com/BangYunseo/TIL/blob/main/Security/InformationSecurity/Image/ch10/HF2.PNG)

## 3절. SHA

#### 실제 암호학에서의 해쉬 함수

##### MD5

- 128비트 출력
- 1991년에 소개
- 2004년에 충돌 공격 발견
- 이후 여러 확장 및 개선하지만

##### SHA(Secure Hash Algorithm)

- 미국 표준 기술 연구소(NIST)가 미국 연방 정보 처리 표준(FIPS)으로 발표한 암호학적 해시 함수 계열

#### SHA

##### SHA-0

- 1993년에 발표된 초기 버전
- 160비트 해시 함수에 적용된 새로운 이름
- 발표 직후 밝혀지지 않은 중대한 결함으로 인해 철회
- 약간 수정된 버전인 SHA-1로 대체

##### SHA-1

- 160비트 해시 함수
- 초기 MD5 알고리즘과 유사
- 디지털 서명 알고리즘(DSA)의 일부로 NSA가 설계
- 암호학적 약점이 발견으로 2010년 이후 대부분의 암호학적 사용에 대해 더 이상 승인 X

##### SHA-2

- SHA-256 및 SHA-512로 알려진 두 가지 유사한 해쉬 함수 계열
- 각 계열의 축소된 버전(SHA-224 및 SHA-384)도 표준화

- SHA-1/SHA-2의 매개 변수(bits 단위)

![SHA12](https://github.com/BangYunseo/TIL/blob/main/Security/InformationSecurity/Image/ch10/SHA12.PNG)

##### SHA-3

- Keccak으로 불렸던 해시 함수
- 2012년 공개 경쟁 이후 선택
- 가변 출력 길이(224, 256, 384, 512) 지원
- 내부 구조는 기존 SHA 계열과 상이

![SHA3](https://github.com/BangYunseo/TIL/blob/main/Security/InformationSecurity/Image/ch10/SHA3.PNG)

#### 응용

- 동기

  - 암호학적 해쉬 값 : (디지털)지문

- 응용
  - 파일 또는 메시지의 무결성 확인
  - 비밀번호 파일

## 4절. Salting

#### 비밀번호 Salting

- 사전 공격(dictionary attacks)의 효과 감소 목적
- 각 비밀번호는 해시 함수 $H$를 적용 전 $t$-비트의 랜덤 문자열(salt) 추가

![salt](https://github.com/BangYunseo/TIL/blob/main/Security/InformationSecurity/Image/ch10/salt.PNG)
