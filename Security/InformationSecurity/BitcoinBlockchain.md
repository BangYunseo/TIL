# 비트코인과 블록체인(Bitcoin & Blockchain)

> 1절. 비트코인
>
> 2절. 트랜잭션(Transactions)
>
> 3절. 블록체인과 채굴(BlockChain & Mining)

## 1절. 비트코인

#### 비트코인(Bitcoin)?

- 사토시 나카모토(Satoshi Nakamoto)에 의해 발명된 암호화폐(cryptocurrency)
  - 사토시 나카모토에 대한 정보는 존재하지 않음
  - 실존 인물인지도 모호함

#### 비트코인의 특징

##### 분산화(비중앙화)

- 중앙 기관이나 은행 필요 X
- Peer-to-Peer(P2P) 기술 이용

##### 프라이버시

- 수도니머스(Pseudonymous)
  - 어나니머스(Ananymous)의 반대어로, 가명 시스템을 의미
- 가명을 사용하기에 자금은 실제 세계의 개체가 아닌 비트코인 주소로 알려짐
- 계좌 번호가 생성한 사람의 정보를 알려주진 않음
- 하지만 해당 계좌의 비트코인 수에 대한 정보는 제공

## 2절. 트랜잭션(Transactions)

#### 비트코인 시스템

- 지갑 : 사용자들의 키 포함
- 거래 : 네트워크를 통해 전파
- 채굴자 : 경쟁적인 계산을 통해 합의 블록체인을 생성
  - 합의 블록체인 : 모든 거래의 권위 있는 원장 역할

#### 디지털 서명과 비트코인 주소(Digital Signature and Bitcoin Address)

![DSBA](https://github.com/BangYunseo/TIL/blob/main/Security/InformationSecurity/Image/Bitcoin/DSBA.PNG)

#### 비트코인 키

- 공개 키 암호화 사용
- 비트코인에 대한 접근을 제어하는 키 쌍 생성
  - 키 쌍 : 개인 키 + 그로부터 파생된 고유한 공개 키 구성
    - 공개 키 : 비트코인을 받을 때 사용
    - 개인 키 : 비트코인을 사용하기 위해 거래에 서명할 때 사용

##### 개인 키(Private Key)

- 거래에서 자금 소유를 증명하는 서명 생성에 사용

- 백업하고 우발적인 손실로부터 보호할 필요 존재

  - 개인 키를 잃으면 복구가 불가
  - 비트코인 계좌에 보호된 자금 손실

- 비트코인 키 생성 == "1과 $2^{256}$ 사이의 숫자 선택"
- 비트코인 소프트웨어 : 기본 운영 체제의 난수 생성기로 256비트의 엔트로피(Randomness) 생성

#### 비트코인 주소와 Base 58

![BA](https://github.com/BangYunseo/TIL/blob/main/Security/InformationSecurity/Image/Bitcoin/BA.PNG)

![BA2](https://github.com/BangYunseo/TIL/blob/main/Security/InformationSecurity/Image/Bitcoin/BA2.PNG)

#### Base 58 인코딩

- Base64의 하위 집합

  - Base64와 마찬가지로 대소문자 알파벳과 숫자를 사용
  - 허나, 서로 혼동될 수 있는 문자들을 제외
  - 0(숫자), O(대문자), l(소문자), I(대문자), +(기호), /(기호) 제외

- 비트코인에서 사용하기 위해 개발된 텍스트 기반 이진 인코딩 형식
- 다른 암호화폐에서도 사용

- Base58Check
  - 비트코인에서 자주 사용되는 Base58 인코딩 형식
  - 내장된 오류 검증 코드가 포함되어 오타나 필사 오류를 방지

#### 비트코인 트랜잭션(Transactions)

![TRAC](https://github.com/BangYunseo/TIL/blob/main/Security/InformationSecurity/Image/Bitcoin/TRAC.PNG)

#### 트랜잭션 순환구조

![TL](https://github.com/BangYunseo/TIL/blob/main/Security/InformationSecurity/Image/Bitcoin/TL.PNG)

#### 일반적인 트랜잭션 형태

![CTF](https://github.com/BangYunseo/TIL/blob/main/Security/InformationSecurity/Image/Bitcoin/CTF.PNG)

####
