#  Chapter 1. 고전 암호 기술
> 0절. Basic Terminology
> 
> 1절. Symmetric Encryption
>
> 2절. Attack Scenarios
>
> 3절. Many Ciphers
>
> 4절. Steganography

## 1절. Basic Terminology
#### 기본 배경 지식

|용어|의미|
|:---:|:---|
|plaintext|original message|
|c
## 2절. Security Attacks
#### Passive attacks

![PA](https://github.com/BangYunseo/TIL/blob/main/Security/InformationSecurity/Image/ch00/PA.PNG)

* 수동적 / 소극적 공격
    * 정보를 변경하지 않는 공격으로 자신이 공격받고 있는지 확인 불가능
    * 예시
        * 도청 : 메세지 훔쳐보기
        * 데이터 통신 분석 : 통신량, 통신 시간대 등

#### Active attacks

![AA](https://github.com/BangYunseo/TIL/blob/main/Security/InformationSecurity/Image/ch00/PA.PNG)

* 능동적 / 적극적 공격
    * 정보를 변경하는 공격으로 자신이 공격 당하는 상황 확인 가능
    * 예시
        * 위장 : 다른 사람인 척 사기
        * 반복 행동 : 같은 메세지 지속적인 전송
        * 메세지를 임의로 수정
        * 디도스(Dos) : 보내는 사용량(트래픽)이 기하급수적으로 증가하게 만드는 공격으로 분산 서비스 공격이라고 불리며 서비스에 공격하는 방식