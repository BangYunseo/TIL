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

#### 트랜잭션 입-출력

- Input

![TIP](https://github.com/BangYunseo/TIL/blob/main/Security/InformationSecurity/Image/Bitcoin/TIP.PNG)

- Output

![TOP](https://github.com/BangYunseo/TIL/blob/main/Security/InformationSecurity/Image/Bitcoin/TOP.PNG)

#### 스트립트 구성(Lock + Unlock)

- 비트코인의 트랜잭션 검증 엔진 스크립트
  - 잠금 스크립트
  - 잠금 해제 스크립트

![LUL](https://github.com/BangYunseo/TIL/blob/main/Security/InformationSecurity/Image/Bitcoin/LUL.PNG)

#### 스크립트 언어(Script Language)

![SL](https://github.com/BangYunseo/TIL/blob/main/Security/InformationSecurity/Image/Bitcoin/SL.PNG)

![SL2](https://github.com/BangYunseo/TIL/blob/main/Security/InformationSecurity/Image/Bitcoin/SL2.PNG)

#### 개인 키 저장 방법

1. 브레인 월렛(Brain Wallet)

- 사용자가 기억하는 암호문구로 키 암호화

2. 위변조 방지 장치(Tamperproof Device)

- 장치는 키를 공개하지 않고 서명 대신 수행

3. 페이퍼 월렛(Paper Wallet)

- 키를 종이에 출력하여 보관

#### 맞춤형 주소 (Vanity Addresses)

- 사람이 읽을 수 있는 메시지를 포함하는 주소
  - 예시 : 1LoveBPzzD72PUXLzCkYAtGFYmK5vYNR33
  - "1Kids"로 시작하는 맞춤형 주소의 범위
    - 시작 : 1Kids11111111111111111111111111111
    - 끝 : 1Kidszzzzzzzzzzzzzzzzzzzzzzzzzzzzz

![VA](https://github.com/BangYunseo/TIL/blob/main/Security/InformationSecurity/Image/Bitcoin/VA.PNG)

- 맞춤형 풀 (Vanity Pool)

  - 맞춤형 마이너 풀에 작업 위임

- 보안
  - 보안 조치를 강화하거나 무력화하는 데 사용
  - 진정한 양날의 검

## 3절. 블록체인과 채굴(BlockChain & Mining)

#### 비트코인 채굴(Bitcoin Mining)

- 트랜잭션은 비트코인 네트워크에 전파되며 채굴을 통해 확인
- 블록에 포함되기 전까지 공유 원장(블록체인)의 일부 X

- 채굴의 두 가지 목적
  - 새로운 비트코인을 생성 => 중앙은행의 새 돈 발행
  - 해당 블록에 충분한 계산 능력이 투입된 경우만 트랜잭션 확인 보장 => 신뢰 형성

#### 블록체인(Blockchain)

![BlockChain](https://github.com/BangYunseo/TIL/blob/main/Security/InformationSecurity/Image/Bitcoin/BlockChain.PNG)

#### 블록 보상(Block Reward)

- 블록을 성공적으로 채굴할 경우 받는 비트코인의 수
- 보상
  => 50 BTC (2009), …, 3.125 BTC (2024),
  1.5625 BTC (2028), 0.78125 BTC (2032), 0.390625 BTC (2036), …

- 목표 : 10분 블록 간격
- 보상은 매 210,000 블록, 즉 약 4년마다 반감
- 총 발행될 비트코인의 양 : 21,000,000 BTC
- 약 2140년경에 0에 도달할 것으로 예상

#### 채굴(Mining)

- 작업 증명(Proof of Work)
  - 생성하기 어렵고(비용 및 시간 소모) 다른 사람이 검증하기는 쉬움
  - 특정 요구 사항을 충족하는 데이터
  - 작업 증명 생성은 확률이 낮은 무작위 과정
  - 유효한 작업 증명 생성을 위해 평균적으로 많은 시행착오 필요
  - 비트코인은 Hashcash 작업 증명 시스템 사용
  - 블록이 유효하려면 해당 블록의 해시 값이 현재 목표값보다 작아야 함
    - 예 : 0000000000000000029AB900000…0000000000000000

#### 난이도 목표(Difficulty Target)

- 난이도 목표와 재조정(Retargeting)
  - 블록을 찾는 난이도
    - 네트워크 전체가 처리하는 데 약 10분 소요
    - 2,016블록(약 2주)마다 조정
  - 새로운 목표 = 이전 목표 × (마지막 2,016블록 처리 시간 / 20,160분)

####
