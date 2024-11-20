# Chapter 5. 블록 암호 운용 방식(Block Cipher Operation)

> 1절. 블록 암호의 모드들(Modes of Block Cipher)

## 1절. 블록 암호의 모드들(Modes of Block Cipher)

- 블록 암호 : 고정된 길이의 하나 블록만 암호화할 경우 적합

#### ECB(Electronic Code Book)

![ECB](https://github.com/BangYunseo/TIL/blob/main/Security/InformationSecurity/Image/ch05/ECB.PNG)

- 암호화(Encryption)

  - $C_j = E(K, P_j)$
    - $j = 1, …, N$

- 복호화(Decryption)

  - $P_j = D(K, C_j)$
    - $j = 1, …, N$

##### ECB의 단점

- 결정적(deterministic)인 ECB
  - 동일한 평문 블록이 동일한 암호문 블록으로 암호화
  - ECB 모드를 사용하여 넓은 단색 영역을 포함한 비트맵 이미지를 암호화할 때, 암호문에 평문 데이터 패턴이 그대로 드러남

![ECB2](https://github.com/BangYunseo/TIL/blob/main/Security/InformationSecurity/Image/ch05/ECB2.PNG)

#### 초기화 벡터(IV : Initial Vector)

- 생성 이유

  - 여러 운용 모드에서 암호화를 무작위화하여 동일한 평문을 여러 번 암호화하더라도 서로 다른 암호문을 생성하도록 하는 비트 블록

- 보안 요구사항
  - 비밀로 유지될 필요 없음
  - 초기화 벡터는 동일한 키 아래에서 절대로 재사용 불가
  - (In CBC)추가적으로 암호화 시점에 IV 예측 불가능

#### CBC(Cipher Block Chaining)

![CBC](https://github.com/BangYunseo/TIL/blob/main/Security/InformationSecurity/Image/ch05/CBC.PNG)

- 암호화(Encryption)

  - $C_0 = IV$
  - $C_j = E(K, [P_j ⊕ C_{j−1}])$

- 복호화(Decryption)

  - $C_0 = IV$
  - $P_j = D(K, C_j) ⊕ C_{j−1}$

#### CFB(Cipher Feedback)

![CFB](https://github.com/BangYunseo/TIL/blob/main/Security/InformationSecurity/Image/ch05/CFB.PNG)

- 암호화(Encryption)

  - $C_0 = IV$
  - $C_j = E(K, C_{j−1}) ⊕ P_j$

- 복호화(Decryption)

  - $C_0 = IV$
  - $P_j = E(K, C_{j−1}) ⊕ C_j$

#### OFB(Output Feedback)

![OFB](https://github.com/BangYunseo/TIL/blob/main/Security/InformationSecurity/Image/ch05/OFB.PNG)

- 암호화(Encryption)

  - $I_0 = IV$
  - $I_j = O_{j−1}$
  - $O_j = E(K, I_j)$
  - $C_j = P_j ⊕ O_j$

- 복호화(Decryption)

  - $I_0 = IV$
  - $I_j = O_{j−1}$
  - $O_j = E(K, I_j)$
  - $P_j = C_j ⊕ O_j$

#### CTR(Counter)

![CTR](https://github.com/BangYunseo/TIL/blob/main/Security/InformationSecurity/Image/ch05/CTR.PNG)

- 암호화(Encryption)

  - $C_j = P_j ⊕ E(K, T_j)$

- 복호화(Decryption)

  - $P_j = C_j ⊕ E(K, T_j)$

#### 블록 암호 분류 및 특징

- CFB, OFB, CTR

  - 암호화 방향에서만 사용

- OFB, CTR

  - 전송 중 발생한 비트 오류 전파 X
  - 블록 암호 연산 사전에 수행

- CTR

  - 평문 또는 암호문의 i번째 블록을 임의 접근 방식으로 처리
  - 블록을 병렬로 암호화 / 복호화할 수 있는 다중 프로세서 환경에 적합

#### NIST 블록 암호 운용 모드

- 기밀성(confidentiality) 모드(8가지)

  - ECB, CBC, OFB, CFB, CTR, XTS-AES, FF1, FF3

- 인증(authentication) 모드 (1가지)

  - CMAC

- 기밀성과 인증 결합 모드 (5가지)

  - CCM, GCM, KW, KWP, TKW
