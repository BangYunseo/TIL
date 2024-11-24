# Chapter 14. 인증(Authentication)

> 1절. 인증(Authentication)
>
> 2절. 인증 요소
>
> 3절. Turing Test
>
> 4절. 사람 인증(Human Authentication)

## 1절. 인증(Authentication)

#### 인증 보안 목표

![At](https://github.com/BangYunseo/TIL/blob/main/Security/InformationSecurity/Image/ch14/At.PNG)

- 기밀성(Confidentiality)

  - 오직 Bob만 메시지 확인 가능

- 무결성(Integrity)

  - 메시지 전송 중 변경 X

- 부인 방지(Non-repudiation)

  - Alice가 자신이 메시지를 작성했다는 사실 부인 불가

- 인증(Authentication)
  - Alice는 통신 상대방이 실제로 Bob임을 확인 가능

#### 인증 보안 목표

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

## 3절. Turing Test

## 4절. 사람 인증(Human Authentication)
