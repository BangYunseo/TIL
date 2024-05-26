#  Chapter 1. 블럭 암호 및 데이터 표준 암호화
> 1절. Block and Stream Ciphers
> 
> 2절. Ideal Block Cipher
>
> 3절. Feistel Cipher
>
> 4절. Data Encryption Standard



## 1절. Block and Stream Ciphers
#### 블럭 암호(Block Cipher)
* 메시지를 블럭 단위로 처리한 후 각 메시지를 암호화 / 해독
* 현재 대부분의 암호는 블럭 암호 사용
    * 왜?
        * 더 나은 분석
        * 더 넓은 적용범위

![BC](https://github.com/BangYunseo/TIL/blob/main/Security/InformationSecurity/Image/ch02/BC.PNG)

#### 스트림 암호(Stream Cipher)
* 암호화 / 해독 시 메시지를 한 번에 비트 또는 바이트 단위로 처리

![SC](https://github.com/BangYunseo/TIL/blob/main/Security/InformationSecurity/Image/ch02/SC.PNG)

* 키를 먼저 입력받은 후에 XOR 연산을 진행하는 방식

#### 기본적인 사실
* 데이터를 블럭처럼 모은 후 사용
* 가역적(이상적인) 맵핑형태
    * 재사용(일대일 변환의 형태) 가능

![RM](https://github.com/BangYunseo/TIL/blob/main/Security/InformationSecurity/Image/ch02/RM.PNG)

* 2비트 / 2열 4행의 형태

* 비가역적 맵핑형태
    * 재사용 불가능

![IM](https://github.com/BangYunseo/TIL/blob/main/Security/InformationSecurity/Image/ch02/IM.PNG)

* 2비트 / 2열 4행의 형태

* $n$비트의 평문 블럭이 사용될 경우    
    * $2^n$개의 가능한 서로 다른 평문 블럭 존재
    * 가역적 매핑 수는 $2^n ⋅ (2^n-1) ⋅⋅⋅ 1 = 2^n!$
    * 테이블로 정의된 키의 길이는 $2^n ⋅ n$
        * $n$이 커질수록 값 증가

## 2절. Ideal Block Cipher
#### 이상적인 블럭 암호
* 가역적 맵핑(일대일 대응)

![IBC](https://github.com/BangYunseo/TIL/blob/main/Security/InformationSecurity/Image/ch02/IBC.PNG)

#### 치환-순열 암호(Substitution-Permutation Ciphers)
* 클로드 섀넌(Claude Shannon)은 1949년 논문에서 치환-순열(S-P) 네트워크 개념 소개
    * S와 P를 섞는 형태
* S-P 네트워크
    * 현대 블럭 암호의 기초
    * 두 가지 기본 암호화 작업을 기반
        * 치환(Substitution) : S-box
        * 순열(Permutation) : P-box

* 3라운드(3번의 과정) 치환-순열 네트워크

![SPN](https://github.com/BangYunseo/TIL/blob/main/Security/InformationSecurity/Image/ch02/SPN.PNG)

## 3절. Feistel Cipher
#### 파이스텔 암호 구조
* 섀넌(Shannon)의 S-P 네트워크에서 S-box는 역함수가 존재해야 함(가역성)
* 파이스텔 네트워크
    * S-box가 역함수가 존재해야 한다는 조건 필요 X
    * 역함수가 존재하지 않더라도 역함수가 존재한 기능을 수행하는 방법
    * 비가역 요소로부터 가역 함수의 기능 실행
        * 이유
            * 수신자와 송신자 모두 XOR 연산을 진행하기 때문
    * 과정을 뒤집으면 모양이 일치하기 때문에 암호화와 복호화 알고리즘을 둘 다 짤 필요 X
* 일반적으로 16라운드로 진행

![FCS](https://github.com/BangYunseo/TIL/blob/main/Security/InformationSecurity/Image/ch02/FCS.PNG)

* 파이스텔 암호 디자인 요소
    * 블럭 사이즈
    * 키 사이즈
        * 라운드마다 키가 존재하고 하나의 마스터 키 존재
    * 라운드의 수
    * 서브 키 생성 알고리즘
    * 라운드 함수

#### XOR의 성질

![XOR](https://github.com/BangYunseo/TIL/blob/main/Security/InformationSecurity/Image/ch02/XOR.PNG)

* $((A ⊕ B) ⊕ B) = (A ⊕ (B ⊕ B)) = C ⊕ B = A ⊕ 0$이므로 $A = B ⊕ C$

* 파이스텔 구조와 관련된 XOR 연산 예제

![XOR2](https://github.com/BangYunseo/TIL/blob/main/Security/InformationSecurity/Image/ch02/XOR2.PNG)
