# Chapter 5. ER 모델(Entity-Relationship Modeling)

> 1절. ER 모델
>
> 2절. 개체
>
> 3절. 속성
>
> 4절. 관계

## 1절. ER 모델
#### ER 모델이란?
* '개체 집합'과 '관계 집합'을 이용해서 현실 세계의 데이터를 개념적으로 표현하는 모델

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

#### 개체의 종류
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

#### 개체의 표현
* 직사각형 표현

![EntityExpression](https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch05/EntityExpression.PNG)

#### 개체의 특징
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

#### 속성의 표현
* 개체 집합을 나타내는 직사각형에 실선으로 연결된 타원형

![AttributeExpression](https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch05/AttributeExpression.PNG)

#### 속성의 특징
* 파일 시스템에서 '데이터 항목(Data Item)' 혹은 '필드(Field)'에 대응
* 단독으로 존재할 경우 대개 무의미

##### 도메인(Domain)
* 각 속성마다 가질 수 있는 값의 범위
* 예시
    * 학번의 도메인은 정수 10자리
    * 주소의 도메인은 문자 30자리

#### 속성의 종류
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


