# Chapter 12. 인증(Authentication)

> 1절. 인증(Authentication)
>
> 2절. 인증 요소
>
> 3절. Turing Test
>
> 4절. 사람 인증(Human Authentication)

## 1절. 인증(Authentication)

### 인증 보안 목표

![At](https://github.com/BangYunseo/TIL/blob/main/Security/InformationSecurity/Image/ch14/At.PNG)

|목표|설명|
|:---:|:---|
|기밀성(Confidentiality)|오직 Bob만 메세지 확인 가능|
|무결성(Integrity)|메세지 전송 중 변경 불가|
|부인 방지(Non-Repudiation)|Alice가 자신이 메세지를 작성했다는 사실 부인 불가|
|인증(Authentication)|Alice는 통신 상대방이 실제로 Bob임을 확인 가능|

### 인증 보안 목표

![At2](https://github.com/BangYunseo/TIL/blob/main/Security/InformationSecurity/Image/ch14/At2.PNG)

- 그리스어 αὐθεντικός("진짜의" 또는 "진본의")와 αὐθέντης("작성자")에서 유래
- 데이터나 개체의 속성의 진위를 확인하는 행위

- 일상생활 응용
  - 신분증을 확인하여 개인의 신원 검증
  - 디지털 인증서를 통해 웹사이트의 유효성 확인
  - 방사성 탄소 연대를 측정하여 유물의 연령을 추적
  - 제품의 포장과 라벨이 주장하는 내용이 실제로 제품에 부합하는지 확인

## 2절. 인증 요소(Authentication Factor)

#### 인증 요소(Authentication Factors)

##### 분류

- 사용자가 소유한 것(Has)
- 사용자가 알고 있는 것(Know)
- 사용자 자신(is)

##### 신원 인증 시점

- 접근 권한 부여하기 전
- 거래 요청 승인하기 전
- 문서나 기타 작업 결과물을 서명하기 전
- 타인에게 권한을 부여하거나 권한 체계 설정하기 전

#### 인증 요소 종류

##### 소유 요소(Ownership Factors)

- 사용자가 소유하는 것
- 예시
  - 손목 밴드
  - 신분증(ID 카드)
  - 보안 토큰

![OF](https://github.com/BangYunseo/TIL/blob/main/Security/InformationSecurity/Image/ch14/OF.PNG)

##### 지식 요소(Knowledge Factors)

- 사용자가 아는 것
- 예시
  - 비밀번호
  - 암호문
  - 개인 식별 번호(PIN)

![KF](https://github.com/BangYunseo/TIL/blob/main/Security/InformationSecurity/Image/ch14/KF.PNG)

##### 그래픽 비밀번호

- 인식 기반 기술(Recognition-based Techniques)
- 많은 선택지 중에서 여러 이미지를 선택 후 인증 시 나중에 식별하는 방식

![Ps](https://github.com/BangYunseo/TIL/blob/main/Security/InformationSecurity/Image/ch14/Ps.PNG)

- N : 전체 그림의 수
- K : 비밀번호로 선택된 그림의 수

##### 패턴 비밀번호(Pattern Lock)

- 규칙

  - 최소한 네 개의 점 선택
  - 동일한 점은 두 번 사용 불가
  - 직선만 허용
  - 이전에 방문하지 않은 점을 건너뛰는 것 불가능

- 경우의 수

| 크기  |  패턴 경우의 수   |
| :---: | :---------------: |
| 3 x 3 |      389,112      |
| 4 x 4 | 4,350,069,823,024 |
| 5 x 5 |         ?         |

##### 내재 요소(Inherence Factors)

- 사용자가 소유한 것이 아닌 사용자 자신
- 사용자가 하는 일

- 예시

  - 지문
  - 홍채/망막
  - 얼굴
  - 음성
  - 기타 생체 인식 식별자

- 생체 인식 : 문제점과 우려

  - 프라이버시와 차별

    - 생체 인식 등록 과정에서 얻어진 데이터가 등록된 개인이 동의하지 않은 방식으로 사용될 가능성 존재

  - 보안된 아이템의 소유자에게 미치는 위험

    - 2005년, 말레이시아의 자동차 절도범들이 메르세데스-벤츠 S클래스의 소유자의 손가락을 잘라 차를 절도하려 함

##### 이중 인증

- 다단계 인증 (Multi-factor authentication)

  - 세 가지 인증 요소 중 두 가지 이상을 요구하는 인증 방식
  - 각 요소는 인증을 위해 상대방에 의해 검증

- 예시
  - 자동화된 현금 인출기(ATM)
    - 일반적으로 이중 인증 요구
    - 사용자가 주장하는 사람이 맞음을 증명하기 위해 두 가지 항목을 요구
      - ATM 스마트 카드(소유 요소 적용)
      - 개인 식별 번호(PIN)(지식 요소 적용)
    - ATM 카드를 분실한 경우에도 사용자의 계좌는 안전
    - 카드를 찾은 사람이 PIN을 모르기 때문에 현금 인출 불가
    - 만약 공격자가 PIN만 알고 카드를 가지고 있지 않아도 현금 인출 불가

## 3절. Turing Test

#### 튜링 테스트 (Turing Test)

- 기계가 인간과 동등하거나 구별할 수 없는 지능적인 행동을 나타낼 수 있는 능력 테스트 방법
- 인간 심판이 인간과 기계와 자연어 대화를 나누며, 기계는 인간과 구별할 수 없는 성능을 생성하도록 설계
- 앨런 튜링(Alan Turing)이 1950년 논문 "Computing Machinery and Intelligence"에서 소개
- 1950년대부터 매우 영향력 있으면서도 널리 비판받고 있는 개념
- 인공지능 철학에서 중요한 개념

![TT](https://github.com/BangYunseo/TIL/blob/main/Security/InformationSecurity/Image/ch14/TT.PNG)

## 4절. 사람 인증(Human Authentication)

#### 인간 인증 (Human Authentication)

##### CAPTCHA

- Completely Automated Public Turing test to tell Computers and Humans Apart
- 완전 자동화 공공 튜링 테스트
- 컴퓨터와 인간을 구별하기 위해 사용되는 도전-응답형 테스트
- 컴퓨터가 쉽게 생성 가능
- 해결하기 어려운 방식으로 설계
- 정답이 제출되면 그것이 인간에 의해 입력되었음을 추정 가능

![CAPTURE](https://github.com/BangYunseo/TIL/blob/main/Security/InformationSecurity/Image/ch14/CAPTURE.PNG)
