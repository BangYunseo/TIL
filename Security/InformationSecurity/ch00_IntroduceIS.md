#  Chapter 0. 정보보안 소개
> 1절. What is Security?
> 
> 2절. Security Attacks

## 1절. What is Security?
#### 컴퓨터 보안
* 정보 시스템 자원(HW / SW / 펌웨어 / 정보, 데이터 / 통신)에 대한 무결성과 가용성, 기밀성 유지와 같은 목적 달성을 위해 자동화된 정보 시스템에 적용되는 보호
    * NIST Computer Security HandBook

#### 보안 목적
![CIA](https://github.com/BangYunseo/TIL/blob/main/Security/InformationSecurity/Image/ch00/CIA.PNG)

* 보안의 3요소
    * Confidentiality : 기밀성 - 보안이 정보를 잘 지켰는가?
    * Integrity : 무결성 - 보안이 정보를 변화없이 잘 전달시켰는가?
    * Availability : 가용성 - 정보가 정상적으로 사용 가능한가?

* 추가적인 목적
    * Authenticity : 진실성
    * Accountability : 대처능력

## 2절. Security Attacks
#### Passive attacks

![PA](https://github.com/BangYunseo/TIL/blob/main/Security/InformationSecurity/Image/ch00/PA.PNG)

* 수동적 / 소극적 공격
    * 정보를 변경하지 않는 공격으로 자신이 공격받고 있는지 확인 불가능
    * 예시
        * 도청 : 메세지 훔쳐보기
        * 데이터 통신 분석 : 통신량, 통신 시간대 등
    * 더미 데이터를 함께 보내는 방식으로 공격 방어
        * 일반적으로 수동적 / 소극적 공격은 방어하기 힘듦

#### Active attacks

![AA](https://github.com/BangYunseo/TIL/blob/main/Security/InformationSecurity/Image/ch00/PA.PNG)

* 능동적 / 적극적 공격
    * 정보를 변경하는 공격으로 자신이 공격 당하는 상황 확인 가능
    * 예시
        * 위장 : 다른 사람인 척 사기
        * 반복 행동 : 같은 메세지 지속적인 전송
            * 새로운 정보(시간 정보, 문자의 넘버링 정보 : 타임 스탬프, 일련번호 )를 추가하여 공격 방어
        * 메세지를 임의로 수정
        * 디도스(Dos) : 보내는 사용량(트래픽)이 기하급수적으로 증가하게 만드는 공격으로 분산 서비스 공격이라고 불리며 서비스에 공격하는 방식