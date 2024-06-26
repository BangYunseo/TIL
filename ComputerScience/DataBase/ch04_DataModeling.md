# Chapter 4. 데이터 모델링(Data Modeling)

> 1절. 데이터의 구분
>
> 2절. 데이터 모델링
>
> 3절. 데이터 모델의 이해
>
> 4절. 개념적 데이터 모델
>
> 5절. 논리적 데이터 모델

## 1절. 데이터의 구분
#### 데이터가 속한 세계에 따른 데이터 구분
* 현실 세계(Real World)
    * 오감으로 인지할 수 있는 실체
    * 하나 이상의 특성으로 구성된 개체 표현

* 개념 세계(Conceptual World)
    * 개체의 의미로부터 얻은 개념
    * 하나 이상의 속성으로 구성된 개체 타입 표현

* 컴퓨터 세계(Computer World)
    * 개념을 컴퓨터가 처리할 수 있도록 표현한 데이터
    * 하나 이상의 필드로 구성된 레코드 타입 표현

#### 각 데이터의 구성 요소

![DATAtype](https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch04/DATAtype.PNG)

#### 데이터의 구분 사례
|구분|특징|
|:---:|:---|
|현실 세계의 학생 개체|얼굴 모습 등 신체적 특징, 이름, 주민등록번호, 고향, 학력, 취미, 별명, 연락처, 교우 관계, 가족 관계 등 수없이 많은 특성의 구성|
|대학이라는 개념 세계의 학생 개체 타입|이름, 학번, 전공, 지도 교수, 이수 학점 수, 평균 평점 등 대학에서 필요로하는 많은 속성들로 구성|
|컴퓨터 세계의 학생 레코드 타입|이름(문자 20 byte), 학번(문자 10 byte), 전공(문자 20 byte) 등 개념 세계의 속성에 대응하는 많은 필드들로 구성|

## 2절. 데이터 모델링
#### 데이터 모델링이란?
* 현실 세계의 데이터를 DB로 표현하기 위한 모델을 만드는 과정

![DM](https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch04/DM.PNG)

#### 데이터 모델링의 3단계

![DM2](https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch04/DM2.PNG)

#### 개념적 모델링(Conceptual Modeling)
* 현실 세계의 데이터를 추상화(Abstraction)를 통해 개념 세계의 데이터로 표현하는 과정
* 정보 모델링(Information modeling)
* 개념적 설계(Conceptual design)

##### 추상화(Abstraction)
* 세세하고 지엽적인 특징은 무시한 채 핵심만을 추출하는 것

#### 개념적 모델링 방법
* 일반적으로 개체와 관계라는 추상적 개념을 통해 모델링
* 주로 ER(Entity-Relationship) 모델이라는 개념적 데이터 모델 사용
* 모델링 결과를 ER 다이어그램(Diagram)으로 표현

##### ER(Entity-Relationship) 모델
* 1976년 피터 첸(Peter Chen)이 제안한 개념적 데이터 모델
* 개ㅔ체 집합과 관계 집합을 이용해 현실 세계의 데이터를 개념적으로 표현하는 모델

#### 개념적 모델링 예제

![EXCM](https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch04/EXCM.PNG)

#### 논리적 모델링(Logical Modeling)
* 개념 세계의 개체 타입을 DBMS가 지원하는 논리적 데이터 모델로 변환시키는 과정
* 논리적 설계

#### 논리적 데이터 모델
* DB에 저장할 데이터의 구조를 DBMS가 이해할 수 있는 논리적인 구조로 표현하기 위해 사용하는 일종의 지능적 도구

![LDM](https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch04/LDM.PNG)

#### 논리적 모델링 방법
* ER 다이어그램으로 표현된 개념적 구조를 DBMS가 지원하는 논리적 데이터 모델로 변환
* 논리적 데이터 모델로 변환하는 방법은 논리적 데이터 모델의 종류에 따라 차이 존재

#### 논리적 모델링 예제

![EXLM](https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch04/EXLM.PNG)

#### 물리적 모델링(Physical Modeling)
* 디스크에 데이터가 저장될 수 있도록 논리적 데이터 모델을 물리적 데이터 구조로 변환시키는 과정
* 물리적 설계

![PM](https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch04/PM.PNG)

#### 물리적 모델링 방법
* 저장 레코드 양식(각 필드의 이름, 데이터 타입, 크기 등) 정의 및 인덱스(Index)나 뷰(View) 등 설계

## 3절. 데이터 모델의 이해
#### 데이터 모델
* 복잡한 현실 세계 데이터를 쉽게 이해할 수 있도록 기술하는 개념적 도구
* 개념적 또는 논리적으로 구분하지 않고 그냥 '데이터 모델'이라고 할 경우 일반적으로 '논리적 데이터 모델'을 의미

##### 개념적 데이터 모델
* 구성요소가 '개체'와 '관계'라는 추상적 개념으로 구성된 데이터 모델
* 대표적 모델
    * ER(Entity-Relationship : 개체-관계) 모델

##### 논리적 데이터 모델 
* 구성요소가 '레코드'와 '관계'라는 논리적 개념으로 구성된 데이터 모델
* 대표적 모델
    * 관계형 데이터 모델

#### 데이터 모델의 구성

![SOC](https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch04/SOC.PNG)

* 데이터 구조(Data Structure)
    * 데이터 모델의 정적 성질(Static Properties)
    * 개체 타입과 이들 간의 관계에 대한 명세

* 연산(Operation)
    * 데이터 모델의 동적 성질(Dynamic Properties)
    * 개체 인스턴스(Instance)를 처리하는 작업에 대한 명세
    * 데이터 조작 방법

* 제약조건(Constraint)
    * 데이터 모델의 논리적 제약(Logical Constraints)
    * 개체 인스턴스의 존재 조건
    * 구조적 제약과 의미상 제약 모두 포함
    * 데이터 조작의 한계를 표현하는 규정

##### 개체 인스턴스(Instance)
* 개체 타입을 구성하는 각 속성들이 구체적인 값을 보유한 것

##### 구조적 제약
* 개체 인스턴스가 반드시 만족해야 하는 구조적인 특성
* 예시
    * 학생의 학번이라는 속성
        * 구조적으로 반드시 숫자 8자리로 구성
        * 아래의 경우 오류(Error)로 처리해서 그 개체 인스턴스가 삽입되지 않도록 만듦
            * 학번에 문자가 포함되어 있는 경우
            * 학번이 8자리 이상인 경우

##### 의미상 제약
* 개체 인스턴스가 반드시 만족해야 하는 의미상의 특성
* 예시
    * 학생의 성별이라는 속성
        * 구조적으로 하나의 문자로 구성
        * 의미상으로 반드시 'M(Male)' 또는 'F(Female)'의 값 보유
        * 아래의 경우 오류(Error)로 처리해서 그 개체 인스턴스가 삽입되지 않도록 만듦
            * 성별이 'M'이나 'F' 이외의 값이 포함된 경우
    
## 4절. 개념적 데이터 모델
#### 개념적 데이터 모델
* 개념적 모델링을 통해 얻을 수 있는 추상화된 데이터 구조
* 구성요소가 '개체'와 '관계'라는 추상적인 개념으로 구성
* DB 설계자의 이해를 돕기 위한 것으로 DBMS는 개념적 데이터 모델 이해 불가능

![CDMtype](https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch04/CDMtype.PNG)

#### ER 모델(Entity-Relationship Model)
* 대표적인 개념적 데이터 모델
* 개체 집합과 관계 집합을 이용해서 현실 세계를 개념적으로 표현하는 방법
* ER 다이어그램(Diagram)을 통해 표현
* 1976년, 피터 첸(Peter Chen)이 처음 소개한 후 계속 변형 및 발전

![EREX](https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch04/EREX.PNG)

## 5절. 논리적 데이터 모델
#### 논리적 데이터 모델
* 개념적 데이터 모델을 DB로 구현하기 위한 중간 단계
* 구성요소가 '레코드'와 '관계'라는 논리적인 개념으로 구성된 데이터 모델

![LDMlocation](https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch04/LDMlocation.PNG)

#### 논리적 데이터 모델의 특징과 종류
* DBMS는 하나의 논리적 데이터 모델을 기반으로 개발
* 개념적 데이터 모델과 다르게 DBMS는 논리적 데이터 모델 이해 가능

![LDMp](https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch04/LDMp.PNG)

![LDMtype](https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch04/LDMtype.PNG)

#### 대표적인 논리적 데이터 모델
* 관계 데이터 모델(Relational Data Model)
    * DB를 릴레이션(Relation), 즉 테이블(Table)의 집합으로 모델링한 구조

![RDMEX](https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch04/RDMEX.PNG)

* 네트워크 데이터 모델(Network Data Model)
    * DB를 그래프(Graph) 형태로 모델링한 구조

![NDMEX](https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch04/NDMEX.PNG)

* 계층 데이터 모델(Hierarchical Data Model)
    * DB를 트리(Tree) 형태로 모델링한 구조

![HDMEX](https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch04/HDMEX.PNG)

#### 논리적 데이터 모델링의 예시
* ER 다이어그램

![EREX1](https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch04/EREX1.PNG)

* 관계 데이터 모델(Relational Data Model)

![RDMEX1](https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch04/RDMEX1.PNG)