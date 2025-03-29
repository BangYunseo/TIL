# Chapter 0. 정보보안 소개

> 1절. 정보보안
>
> 2절. 보안 공격

## 1절. 정보보안

### 컴퓨터 보안

- 정보 시스템 자원(HW / SW / 펌웨어 / 정보, 데이터 / 통신)에 대한 보안 3요소 유지 목적 달성
- 자동화된 정보 시스템에 적용되는 보호
  - 보안 3요소
    - 무결성
    - 가용성
    - 기밀성

### 보안 목적

<img src="https://github.com/BangYunseo/TIL/blob/main/Security/InformationSecurity/Image/ch00/ch00-01-CIA.PNG" width="50%" height="auto"/>

### 보안의 3요소 + 추가 요소

|    보안 요소    |   용어   | 설명                                                     |
| :-------------: | :------: | :------------------------------------------------------- |
| Confidentiality |  기밀성  | 보안이 정보를 <strong>잘</strong> 지켰는가?              |
|    Integrity    |  무결성  | 보안이 정보를 <strong>변화없이</strong> 잘 전달시켰는가? |
|  Availability   |  가용성  | 정보가 <strong>정상적으로</strong> 사용 가능한가?        |
|  Authenticity   |  진실성  |                                                          |
| Accountability  | 대처능력 |                                                          |

## 2절. 보안 공격

### Passive attacks

<img src="https://github.com/BangYunseo/TIL/blob/main/Security/InformationSecurity/Image/ch00/ch00-02-PassitiveAttack.PNG" width="70%" height="auto"/>

- 수동적 / 소극적 공격
- 정보를 변경하지 않는 공격으로 자신이 공격받고 있는지 확인 불가능

- 예시

| 예시             | 설명                          |
| :--------------- | :---------------------------- |
| 도청             | 메세지 훔쳐보기               |
| 데이터 통신 분석 | 통신량, 통신 시간대 등을 분석 |

- 공격 방어 방법
  - 더미 데이터를 함께 보내는 방식으로 공격 방어
  - 일반적으로 수동적 / 소극적 공격은 방어에 어려움

### Active attacks

<img src="https://github.com/BangYunseo/TIL/blob/main/Security/InformationSecurity/Image/ch00/ch00-03-ActiveAttack.PNG" width="80%" height="auto"/>

- 능동적 / 적극적 공격
- 정보를 변경하는 공격으로 자신이 공격 당하는 상황 확인 가능

- 예시

| 예시        | 설명                                                                                                                      |
| :---------- | :------------------------------------------------------------------------------------------------------------------------ |
| 위장        | 다른 사람인 척 사기                                                                                                       |
| 반복 행동   | 같은 메세지 지속적인 전송<br><br>새로운 정보(시간 정보, 문자의 넘버링 정보 : 타임 스탬프, 일련번호 )를 추가하여 공격 방어 |
| 정보 수정   | 메세지 임의 수정                                                                                                          |
| 디도스(Dos) | 보내는 사용량(트래픽)이 기하급수적으로 증가하게 만드는 공격으로 분산 서비스 공격이라고 불리며 서비스에 공격하는 방식      |
