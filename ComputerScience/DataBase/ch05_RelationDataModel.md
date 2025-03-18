# Chapter 5. 관계 데이터 모델

> 1절. 관계 데이터 모델의 개념
>
> 2절. 개체
>
> 3절. 속성
>
> 4절. 관계

## 1절. 관계 데이터 모델의 개념
#### 관계 데이터 모델
- 개념적 구조를 논리적 구조로 표현하는 논리적 데이터 모델
- 하나의 개체에 대한 데이터를 하나의 릴레이션에 저장

![ch05-01-](https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch05/ch05-01.PNG)


#### 기본 용어

##### 릴레이션(relation)
- 하나의 개체에 관한 데이터를 2차원 테이블의 구조로 저장한 것
- 행과 열로 구성된 테이블
- 파일 관리 시스템 관점에서 파일(file)에 대응
- 릴레이션 내에서 생성되는 관계 : 릴레이션 내 데이터들의 관계
- 릴레이션 간에 생성되는 관계 : 릴레이션 간의 관계


![ERmodel](https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch05/ERmodel.PNG)

#### ER 모델의 주요 구성 요소

|구분|영어|정의|
|:--:|:--:|:--|
|개체|Entity|DB가 표현하려고 하는 유형으로 무형 정보 대상이며 "존재"하면서 서로 구별될 수 있는 요소|
|관계|Relationship|개체들 간의 의미 있는 연결 또는 연관성을 의미하는 요소|
|속성|Attribute|개체나 관계의 특성을 나타내는 요소로 이름을 가진 정보의 가장 작은 논리적 단위|

## 2절. 개체
#### 개체(Entity)
* DB가 표현하려고 하는 유형
* 무형의 정보 대상
* "존재"하면서 서로 구별될 수 있는 요소

#### 개체 종류
* 개념적 개체(무형의 개체)
    * 개념적으로는 존재하지만 눈에 보이지 않는 개체
    * 예시
        * 약속
        * 사건
        * 승진

* 물리적 개체(유형의 개체)
    * 현실 세계에서 존재하면서 눈에 보이는 개체
    * 예시
        * 사람
        * 상품
        * 건물

#### 개체 표현
* 직사각형 표현

![EntityExpression](https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch05/EntityExpression.PNG)

#### 개체 특징
* 파일 시스템에서 '레코드(Record)에 대응'
* 단독으로 존재 가능
* 정보로서의 역할 가능
* 둘 이상의 속성(Attribute)으로 구성
    * 예시
        * 개체 - 학생
        * 속성 - 학번, 이름, 학과 등

#### 개체 관련 주요 개념

|개념|정의|
|:--:|:---|
|속성|개체의 특성을 나타내는 요소|
|개체 타입|개체의 정의, 즉 개체의 이름과 개체를 구성하는 속성들을 정의한 것|
|개체 집합|개체 인스턴스들의 집합|
|개체 인스턴스|개체 인스턴스(Entity Instance) 또는 개체 출현(Entity Occurrence)로 불리며 개체의 속성들이 구체적인 값을 가짐으로써 실체화된 것|

![EntityEX](https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch05/EntityEX.PNG)

## 3절. 속성
#### 속성(Attribute)
* 개체나 관계의 특성을 나타내는 요소
* 이름을 가진 정보의 가장 작은 논리적 단위

#### 속성 표현
* 개체 집합을 나타내는 직사각형에 실선으로 연결된 타원형

![AttributeExpression](https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch05/AttributeExpression.PNG)

#### 속성 특징
* 파일 시스템에서 '데이터 항목(Data Item)' 혹은 '필드(Field)'에 대응
* 단독으로 존재할 경우 대개 무의미

##### 도메인(Domain)
* 각 속성마다 가질 수 있는 값의 범위
* 예시
    * 학번의 도메인은 정수 10자리
    * 주소의 도메인은 문자 30자리

#### 속성 종류
|종류|영어|특성|예시|
|:--:|:--:|:---|:---|
|상수 속성|Constant Attribute|시간이 지나도 값이 변하지 않는 속성|학생의 주민등록번호|
|시변 속성|Time Varying Attribute|갱신함에 따라 값이 변할 수 있는 속성|학생의 주소|
|단순 속성|Simple Attribute|더 작은 구성 요소로 분해할 수 없는 속성|회원번호, 이름, 연락처 등|
|복합 속성|Composite Attribute|독립적인 의미를 갖는 단순 속성들로 분해할 수 있는 속성|주소|
|단일 값 속성|Single-Valued Attribute|특정 개체에 대해 반드시 하나의 값만 갖는 속성|주민등록번호, 학번|
|다중 값 속성|Multi-Valued Attribute|특정 개체에 대해 여러 개의 값을 가질 수 있는 속성|전화번호(집, 휴대폰, 회사 전화번호 등), 취미|
|유도 속성|Derived Attribute|속성의 값이 다른 관련된 속성이나 개체가 갖고 있는 값으로부터 유도외어 결정되는 속성|.|
|저장 속성|Stored Attribute|유도 속성을 결정하기 위해 사용된 속성|.|
|널 속성|Null Attribute|널(NULL) 값을 갖는 속성|.|

* 단순 속성과 복합 속성 예시

![SimpleComposite](https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch05/SimpleComposite.PNG)

* 다중 값 속성의 ER 다이어그램 표현
    * 이중선 타원 표현

![MA](https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch05/MA.PNG)

* 유도 속성과 저장 속성 예시
    * 유도 속성은 ER 다이어그램에서 점선 타원 표현

![DS](https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch05/DS.PNG)

##### NULL
* 널(NULL) 값
    * 어떤 개체 인스턴스가 특정 속성에 대한 값을 갖고 있지 않을 때, 이를 명시적으로 표현하기 위해 사용하는 값

* 널(NULL) 값을 갖는 경우
    * 어떤 속성 값이 그 개체에 "해당되지 않는(not applicable)" 경우
    * 어떤 속성 값을 "알 수 없는(unknown)" 경우
    * 값이 존재하지만 "누락(missing)"된 경우
    * 값이 존재하는지 여부를 "모르는(not known)" 경우

## 4절. 관계
#### 관계(Relationship)
* 개체들 간의 의미 있는 연결 또는 연관성을 의미하는 요소

#### 관계 표현
* 개체 집합을 나타내는 직사각형에 실선으로 연결된 마름모 표현

![RelationshipExpression](https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch05/RelationshipExpression.PNG)

#### 관계 특징
* 하나의 개체로 간주
* 속성 보유 가능
* 두 개의 개체 사이에 두 개 이상의 관계 존재 가능(다중 관계)

#### 관계 타입 속성
* 관계의 특성을 나타내는 속성 보유 가능
* 관계 타입은 키 속성 미보유

![RA](https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch05/RA.PNG)

#### 관계 유형
* 일 대 일(1 : 1)
    * 한 개체가 한 개체와만 연관성 있는 유형
    * 예시
        * 부부 관계

![OO](https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch05/OO.PNG)

* 일 대 다(1 : n)
    * 두 개체 가운데 어느 한 개체를 기준으로 볼 때 하나 이상의 개체와 연관성을 보유하며 다른 개체를 기준으로 봤을 때 한 개체와만 연관성 있는 유형
    * 예시
        * 모자 관계

![ON](https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch05/ON.PNG)

* 다 대 다(m : n)
    * 하나 이상의 개체와 연관성 있는 유형
    * 여러 개체가 여러 개체와 연관성 보유
    * 예시
        * 이성 친구 관계

![MN](https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch05/MN.PNG)

#### 관계 구분
* 속성 관계(Attribute Relationship)
    * 한 개체 내의 속성과 속성 사이의 연관성

* 개체 관계(Entity Relationship)
    * 개체와 개체 사이의 연관성
    * 그냥 "관계" 라고 하면 개체 관계를 의미

![ARandER](https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch05/ARandER.PNG)

#### 카디널리티(Cardinality)
* 관계에 대응하는 개체 수
* 관계에 참여하는 하나의 개체에 대해 다른 개체가 몇 개 대응하는지 표현

#### 카디널리티 표현
* 대응 개체 수는 (min, max)의 한 쌍의 값으로 표현
    * min
        * 관계에 참여하는 개체의 최소 개수
    * max
        * 관계에 참여하는 개체의 최대 개수

![CardinalityEX1](https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch05/CardinalityEX1.PNG)

![CardinalityEX2](https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch05/CardinalityEX2.PNG)

#### 차수(Degree)
* 관계로 연결된 개체 타입의 개수

#### 차수 유형
* 1진 관계

![D1](https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch05/D1.PNG)

* 2진 관계

![D2](https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch05/D2.PNG)

* 3진 관계

![D3](https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch05/D3.PNG)

* n진 관계

![Dn](https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch05/Dn.PNG)
