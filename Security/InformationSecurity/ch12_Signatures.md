# Chapter 12. 서명(Signatures)

> 1절. 디지털 서명(Digital Signatures)
>
> 2절. RSA 서명
>
> 3절. DSS / DSA
>
> 4절. 0-지식 증명(Zero-Knowledge Proof)
>
> 5절. Schnorr 인증

## 1절. 디지털 서명(Digital Signatures)

#### 디지털 서명(Digital Signatures) 정의

- 디지털 메시지나 문서의 진위를 증명하는 수학적 방식
- 인증 및 부인 방지
  - 유효한 디지털 서명에 대한 수신자와 발신자의 정보
    - 수신자 : 메시지가 발신자에 의해 생성되었음을 믿을 수 있는 이유 제공
    - 발신자 : 메시지를 보낸 사실을 부인 불가
- 무결성
  - 메시지가 전송 중에 변경되지 않음을 보장

#### 디지털 서명(Digital Signatures) 알고리즘

##### 키 생성 알고리즘(Key Generation Algorithm)

- 무작위 알고리즘
- $(pk, sk)$ 출력

##### 서명 알고리즘(Signing Algorithm)

- 개인 키와 메시지를 받아 서명 출력
- $s = Sign(sk, m)$

##### 검증 알고리즘(Verification Algorithm)

- 공개 키, 메시지, 서명 입력
- 메시지의 진위 주장에 수락 or 거부
- $Vrfy(pk, m, s) = Y/N$

#### 일반적인 디지털 서명 과정

![DSP](https://github.com/BangYunseo/TIL/blob/main/Security/InformationSecurity/Image/ch12/DSP.PNG)

## 2절. RSA 서명

#### RSA 서명 (해쉬된 RSA 또는 FDH-RSA) 알고리즘

##### 키 생성 알고리즘

- RSA 암호화와 동일
- 공개 키 = $(e, n)$
- 개인 키 = $(d, n)$

##### 서명 알고리즘

- 입력
  - 개인 키 = $(d, n)$
  - 메시지 = $m$
- 서명 $s = H(m)^d$ $mod$ $n$ 계산
- $H : {0, 1}^* → Z_n^*$는 암호학적 해쉬 함수

##### 검증 알고리즘

- 입력
  - 공개 키 = $(e, n)$
  - 메시지 = $m$
  - 서명 = $s$
- $H(m) = s^e$ $mod$ $n$ 확인

##### 번외) RSA 서명에만 해당되는 조건

- 서명(Sign) = 개인 키로 암호화
- 검증(Vrfy) = 공개 키로 복호화

#### RSA-PSS(Probabilistic Signature Scheme)

![PSS](https://github.com/BangYunseo/TIL/blob/main/Security/InformationSecurity/Image/ch12/PSS.PNG)

## 3절. DSS / DSA

#### 디지털 서명 표준(DSS : Digital Signature Standard)

- 디지털 서명을 생성하기 위한 암호화 알고리즘을 설명하는 미국 정부의 FIPS(연방 정보 처리 표준) 186
- 총 네 번의 개정판
  - FIPS 186-1 (1996)
  - FIPS 186-2 (2000)
  - FIPS 186-3 (2009)
    - DSA, RSA 및 EC-DSA 포함
  - FIPS 186-4 (2013)

#### DSA(Digital Signature Algorithm)

##### 디지털 서명 알고리즘(DSA) 정의(여기부터 작성)

- DSA는 1991년 NIST(국립 표준 기술 연구소)에 의해 DSS에서 사용하기 위해 제안되었으며, 1993년 FIPS 186으로 채택되었습니다.
  – DSA는 1991년 7월 26일에 제출된 미국 특허 5,231,668에 의해 보호되며, 이는 전 NSA 직원인 David W. Kravitz에 의해 발명되었습니다. NIST는 이 특허를 전 세계적으로 로열티 없이 제공하고 있습니다.

##### 디지털 서명 알고리즘(DSA) 알고리즘

- 매개변수 : (p, q, g)
  • 키 생성 알고리즘
  – 0 < x < q인 범위에서 무작위 방법으로 비밀 키 x를 선택합니다.
  – 공개 키 y = g^x mod p를 계산합니다.

• 서명 알고리즘
– 0 < k < q인 범위에서 메시지별 무작위 값 k를 생성합니다.
– r = (g^k mod p) mod q와 s = k^−1(H(m) + xr) mod q를 계산합니다.
– 메시지 m에 대한 서명은 (r, s)입니다.

• 검증 알고리즘
– w = s^−1 mod q, u1 = H(m)w mod q, u2 = rw mod q를 계산합니다.
– v = (g^u1 \* y^u2 mod p) mod q를 계산합니다.
– 서명이 유효하려면 v = r이어야 합니다.

## 4절. 0-지식 증명(Zero-Knowledge Proof)

## 5절. Schnorr 인증
