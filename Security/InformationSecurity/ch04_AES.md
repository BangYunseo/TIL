# Chapter 4. AES(Advanced Encryption Standard)

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

- $m(x) = x⁸ + x⁴ + x³ + x + 1$ 이므로 $x⁸ = x⁴ + x³ + x + 1 = (00011011) =$ $\{1B\}$
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

![sbt](https://github.com/BangYunseo/TIL/blob/main/Security/InformationSecurity/Image/ch04/sbt.PNG)

- 상태(State)

  - 가장 왼쪽 4비트 : 행 값
  - 가장 오른쪽 4비트 : 열 값

- 예시) 16진수 값 {95}
  - S-box의 9행 5열 참조
  - 값 {2A} 포함
  - 즉 {95}는 {2A} 매핑

![AESsb](https://github.com/BangYunseo/TIL/blob/main/Security/InformationSecurity/Image/ch04/AESsb.PNG)

- SubBytes Transformation Process

![sbtP](https://github.com/BangYunseo/TIL/blob/main/Security/InformationSecurity/Image/ch04/sbtP.PNG)

## 3절. ShiftRows

#### ShiftRows Transformation

![srt](https://github.com/BangYunseo/TIL/blob/main/Security/InformationSecurity/Image/ch04/srt.PNG)

- 상태(State)

  - 첫 번째 행 : 불변
  - 두 번째 행 : 1바이트 왼쪽 순환 이동
  - 세 번째 행 : 2바이트 왼쪽 순환 이동
  - 네 번째 행 : 3바이트 왼쪽 순환 이동

- InvShiftRows
  - 반대 방향의 행 이동 변환
  - 마지막 세 개의 행 각각에 대해 오른쪽 순환 이동 수행
  - 두 번째 행은 1바이트 오른쪽 순환 이동
  - 나머지 행도 같은 방식으로 이동

## 4절. MixColumns

#### MixColumns Transformation

![MCT](https://github.com/BangYunseo/TIL/blob/main/Security/InformationSecurity/Image/ch04/MCT.PNG)

#### InvMixColumns Transformation

![IMCT](https://github.com/BangYunseo/TIL/blob/main/Security/InformationSecurity/Image/ch04/IMCT.PNG)

## 5절. AddRoundKey

#### AddRoundKey Transformation

![ART](https://github.com/BangYunseo/TIL/blob/main/Security/InformationSecurity/Image/ch04/ART.PNG)

- 첫 번째 행렬 : State
- 두 번째 행렬 : RoundKey

- 순방향 AddRoundKey 변환

  - State 128비트가 라운드 키 128비트와 비트별 XOR 연산 수행

- 역방향 AddRoundKey 변환
  - 순방향 AddRoundKey 변환과 동일
  - 이는 XOR 연산이 자기 자신의 역연산이기 때문
