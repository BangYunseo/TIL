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

## 0절. Basic Terminology
#### 기본 배경 지식

|용어|의미|
|:---:|:---|
|plaintext|original message|
|ciphertext|coded message|
|cipher|algorithm for transforming plaintext to ciphertext
|key|info used in cipher known only to sender/receiver|
|encrypt(encipher)|converting plaintext to ciphertext|
|decrypt(decipher)|recovering plaintext from ciphertext|
|cryptography|study of encryption principles/methods|
|cryptanalysis(codebreaking)|study of principles/methods of deciphering ciphertext without knowing key|
|cryptology|field of both cryptography and cryptanalysis|

## > 1절. Symmetric Encryption
#### Symmetric Cipher Model

![SE](https://github.com/BangYunseo/TIL/blob/main/Security/InformationSecurity/Image/ch01/SE.PNG)

![SE2](https://github.com/BangYunseo/TIL/blob/main/Security/InformationSecurity/Image/ch01/SE2.PNG)

#### Kerckhoffs의 원리
* 19세기 후반의 Auguste Kerckhoffs
    * 누구나 암호화 알고리즘에 대해 인지하고 있고 key의 안전도에만 영향을 받도록 만듦
        * 공격자가 key의 설계도를 알아도 정작 key가 없다면 암호를 해결할 수 없어 암호의 안전이 완성되는 것
    * 


## 2절. Attack Scenarios
#### 공격 종류
* Cryptanalytic attacks
    |용어|의미|
    |:---:|:--|
    |Ciphertext-only attack|암호문만 공격(일반적, 보편적인 공격)|
    |Known-plaintext attack|알려진 평문 공격(암호화의 내역이 유출된 경우)|
    |Chosen-plaintext attack|선택한 평문 공격|
    |Chosen-ciphertext attack|선택한 암호문 공격|
    * 자신이 가지고 있던 평문 / 암호문에 대한 정보를 공부한 후 새로운 메시지로 해독하는 공격
    * 공격자가 정보를 더 많이 얻었을 때 이뤄지는 공격이므로 공격자가 유리

* Brute-force attacks : 물리적인 힘의 공격(무식한 방법이자 전수 조사)
    * [브루트포스 알고리즘 - hcr3066님의 블로그 참고](https://hcr3066.tistory.com/26)
    * 예시 : 4자리의 암호(0000 ~ 9999)를 모두 시도해 암호를 얻는 방법의 공격
        * 컴퓨터 대수를 높여 효율 증가

## 3절. Many Classical Ciphers
#### 고전적 암호의 종류
* 일반 텍스트의 문자가 다른 문자나 숫자 또는 기호로 대체되는 경우
* 일반 텍스트가 일련의 비트로 간주되는 경우 대체에는 일반 텍스트 비트 패턴을 암호문 비트 패턴으로 바꾸는 작업 포함
4절. Steganography