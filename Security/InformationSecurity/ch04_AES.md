# Chapter 4. 고급 암호화 표준(AES : Advanced Encryption Standard)

> 1절. AES의 구조
>
> 2절. SubBytes
>
> 3절. ShiftRows
>
> 4절. MixColumns
>
> 5절. AddRoundKey

## 1절. AES의 구조

#### 개요

- 2001년 미국 국립표준기술연구소(NIST)에서 전자 데이터 암호화를 위한 규격으로 제정
- 벨기에의 두 암호학자인 조안 다멘(Joan Daemen)과 빈센트 리멘(Vincent Rijmen)이 개발한 Rijndael 암호 기반
- 미국 정부에 의해 채택되어 전 세계적으로 사용
- 1977년의 데이터 암호화 표준(DES) 대체

#### AES 일반적인 구조

##### $GF(2^8)$ 
- $m(x) = x⁸ + x⁴ + x³ + x + 1$ 이므로  $x⁸ = x⁴ + x³ + x + 1 = (00011011) =$ $\{1B\}$ 
- $A = (a_7a_6...a_1a_0)$와 $B = (b_7b_6...b_1b_0)$일 때, 합은 $A + B = (c_7c_6...c_1c_0)$
  - $c_i = a_i ⊕ b_i$ 성립
- 곱셈 $\{02\}$⋅A는 $a_7$이 $0$이면 $(a_6...a_1a_00)$, $a_7$이 $1$이면 $(a_6...a_1a_00)⊕(00011011)$

##### 매개 변수(Parameter)
- 128비트 (16바이트)의 평문 블록 크기 사용
- 키 길이는 128, 192, 또는 256비트(16, 24, 또는 32바이트)
- 라운드 수는 10, 12, 또는 14
- 키 길이에 따라 AES-128, AES-192, 또는 AES-256

##### 상태(State)
- 4x4 바이트 행렬로 나타내는 4개의 열과 4개의 바이트로 구성된 데이터 블록
- 키는 바이트 행렬

![AES](https://github.com/BangYunseo/TIL/blob/main/Security/InformationSecurity/Image/ch04/AES.PNG)

#### AES의 구체적인 구조

##### 전체적인 구조
- 페이스텔(Feistel) 구조가 아닌 AES
- AES-128
  - AddRoundKey 변환으로 시작
  - 각 라운드마다 네 가지 변환을 포함한 9개의 라운드 진행
  - 세 가지 변환이 포함된 열 번째 라운드가 진행

#### 4 - 변환(Transformation)
- SubBytes
- ShiftRows
- MixColumns
- AddRoundKey(Key를 사용하는 유일한 과정)

![AESDS](https://github.com/BangYunseo/TIL/blob/main/Security/InformationSecurity/Image/ch04/AESDS.PNG)

## 2절. SubBytes

#### SubBytes Transformation

