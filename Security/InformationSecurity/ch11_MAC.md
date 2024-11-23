# Chapter 11. 메시지 인증 코드(MAC : Message Authentication Code)

> 1절. 메시지 인증 코드
>
> 2절. 길이 확장 공격
>
> 3절. HMAC
>
> 4절. CBC-MAC
>
> 5절. CMAC
>
> 6절. 인증 암호(Authenticated Encryption)

## 1절. 메시지 인증 코드

#### MAC

![MAC](https://github.com/BangYunseo/TIL/blob/main/Security/InformationSecurity/Image/ch11/MAC.PNG)

- 메시지를 인증하고 메시지의 무결성과 진위성(정확성)을 보장하는 데 사용되는 짧은 정보

- 무결성 보장 : 우발적이거나 의도적인 메시지 변경 탐지

- 진위 보장 : 메시지의 출처 확인

#### 기능

- 키 기반 암호학적 해시 함수(keyed(cryptographic) hash function)
  - 암호학적 해시 함수는 MAC을 생성하는 방법 중 하나
- 입력값 : 비밀 키와 인증할 임의 길이의 메시지
- 출력값 : MAC(태그)
- MAC 값
  - 메시지의 데이터 무결성과 진위 보호
  - 검증자가(비밀 키를 소유한) 메시지 내용의 변경 여부를 확인 가능

#### 알고리즘

- 키 생성 알고리즘
- 태그 생성 알고리즘 : $T = Mac(K, M)$
- 검증 알고리즘 : $Vrfy(K, M, T) = 1/0$

#### 보안

- 선택 평문 공격에 대해 존재적 위조를 저항해야 안전
  - 공격자가 비밀 키를 가지고 있고, 공격자가 선택한 메시지에 대해 MAC을 생성하는 오라클에 접근가능할 경우
  - 공격자가 오라클을 쿼리하는 데 사용되지 않은 다른 메시지의 MAC을 추측할 수 없음
  - 불가능할 정도의 계산을 수행 필요

#### 구현

- 암호학적 원시 함수에서 구성
  - 암호학적 해시 함수(HMAC의 경우)
  - 블록 암호 알고리즘(CMAC의 경우)

## 2절. 길이 확장 공격

#### 길이 확장 공격(Length Extension Attack)

![LEA](https://github.com/BangYunseo/TIL/blob/main/Security/InformationSecurity/Image/ch11/LEA.PNG)

- 공격자가 $H(m_1)$과 $m_1$의 길이를 사용하여 $m_1$의 내용은 알 필요 없이 공격자가 제어하는 $m_2$에 대해 $H(m_1 ‖ m_2)$를 계산할 수 있는 공격의 일종
- MD5, SHA-1, SHA-2와 같이 Merkle–Damgård 구조를 기반으로 한 알고리즘은 이러한 종류의 공격에 취약
- SHA-3 알고리즘 제외(안취약함)

## 3절. HMAC

#### HMAC (키 기반 해시 메시지 인증 코드 또는 해시 기반 메시지 인증 코드)

- SHA-2 또는 SHA-3와 같은 암호학적 해시 함수는 HMAC 계산에 사용
- HMAC-X(X : 사용된 해시 함수)
  - HMAC-SHA256
  - HMAC-SHA3-256
- 두 번의 해시 계산을 사용
- 비밀 키 : 먼저 두 개의 키(내부 키와 외부 키)를 유도할 때 사용
- 알고리즘의 첫 번째 패스는 메시지와 내부 키에서 유도된 내부 해시를 생성합니다.
  두 번째 패스는 내부 해시 결과와 외부 키에서 유도된 최종 HMAC 코드를 생성합니다. 따라서 이 알고리즘은 길이 확장 공격에 대해 더 나은 면역력을 제공합니다.

## 4절. CBC-MAC

## 5절. CMAC

## 6절. 인증 암호(Authenticated Encryption)

#### 인증 암호(Authenticated Encryption)

- 통신의 기밀성과 진위성(무결성)을 동시에 보호하는 암호화 시스템
- 작동 모드 : CCM & GCM
