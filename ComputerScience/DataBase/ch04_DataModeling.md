# Chapter 4. 데이터 모델링(Data Modeling)

> 1절. 데이터 모델링
>
> 2절. 데이터 모델
>
> 3절. 개체-관계 모델
>
> 4절. 논리적 데이터 모델
>
> 5절. MySQL WorkBench 모델링

## 1절. 데이터 모델링

### 데이터 모델링(Data Modeling)

<img src="https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch04/ch04-01-DataModeling.PNG" height="auto" />

- 현실 세계에 존재하는 데이터를 컴퓨터 세계 데이터베이스로의 변환 과정
- 데이터베이스 설계 핵심 과정

### 2단계 데이터 모델링

|                        종류                         | 설명                                                          |
| :-------------------------------------------------: | :------------------------------------------------------------ |
| 개념적<br>데이터 모델링<br>(Conceptual<br>Modeling) | 현실 세계 중요 데이터를 추출하여 개념 세계로 옮기는 작업      |
|  논리적<br>데이터 모델링<br>(Logical<br>Modeling)   | 개념 세계 데이터를 데이터베이스에 저장하는 구조로의 표현 작업 |

<img src="https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch04/ch04-02-2DataModeling.PNG" height="auto" />

### 데이터 모델링 개념

<img src="https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch04/ch04-03-DM.PNG" height="auto" />

## 2절. 데이터 모델

### 데이터 모델(Data Model)

- 데이터 모델링 결과물 표현 도구

|        종류  | 설명  | 예시|
| :--: | :--------------------------------------------------------------------------------------- | :--------------- |
|개념적<br>데이터 모델| 사람이 이해하도록 현실 세계를 개념적 모델링하여 데이터베이스 개념적 구조로 표현하는 도구 | 개체-관계 모델   |
|논리적<br>데이터 모델| 개념적 구조를 논리적 모델링하여 데이터베이스의 논리적 구조로 표현하는 도구   | 관계 데이터 모델 |

<img src="https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch04/ch04-04-DMconsist.PNG" height="auto" />

## 3절. 개체-관계 모델

### 개체-관계 모델(E-R model : Entity-Relationship model)

- 피터 첸(Peter Chen)의 개념적 데이터 모델
- 개체와 개체 간 관계로 현실 세계를 개념적 구조로 표현
- 핵심 요소 : 개체 · 속성 · 관계

### 개체-관계 다이어그램(E-R diagram)

- E-R 다이어그램
- 개체-관계 모델을 통해 현실 세계를 개념적으로 모델링한 결과물을 그림 표현

### 개체(Entity)

- 현실 세계에서 조직 운영에 꼭 필요한 사람 · 사물처럼 구별되는 모든 것
- 중요 데이터를 가진 사람· 사물 · 개념 · 사건 등
- 다른 개체와 구별되는 이름 보유
- 각 개체만의 고유한 특성 · 상태
  - 모든 개체는 속성을 최소한 하나 이상 보유
- 파일 구조 레코드(record)와 대응
- 개체 예시

| 설명               |    개체     |
| :----------------- | :---------: |
| 서점에 필요한 개체 |  고객 · 책  |
| 학교에 필요한 개체 | 학과 · 과목 |

- E-R 다이어그램 : 사각형 표현
  - 사각형 안에 이름 표기

<img src="https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch04/ch04-05-Entity.PNG" height="auto" />

### 개체 세부 사항

<img src="https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch04/ch04-07-DetailOfEntity.PNG" height="auto" />

#### 개체 타입(Entity Type)

- 개체를 고유 이름 · 속성들로 정의
- 파일 구조의 레코드 타입(record type)에 대응

#### 개체 인스턴스(Entity Instance)

- 개체 구성 속성이 실제 값을 가짐으로써 실체화된 개체
- == 개체 어커런스(entity occurrence)
- 파일 구조 레코드 인스턴스(record instance)에 대응

#### 개체 집합(Entity Set)

- 특정 개체 타입 개체 인스턴스들의 집합

### 속성(Attribute)

<img src="https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch04/ch04-06-Attribute.PNG" height="auto" />

- 개체 · 관계가 가지는 고유 특성
- 의미 있는 데이터의 가장 작은 논리적 단위
- 파일 구조 필드(field)에 대응
- E-R 다이어그램 : 타원 표현
  - 타원 안에 이름 표기

### 속성 분류

<img src="https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch04/ch04-08-AttributeType.PNG" height="auto" />

### 단일 값 속성(Single-Valued Attribute)

- 하나의 값만 가지는 속성

|      예시      |
| :------------: |
| 고객 개체 이름 |
|  적립금 속성   |

### 다중 값 속성(Multi-Valued Attribute)

- 여러 개의 값을 가지는 속성
- E-R 다이어그램에서 이중 타원 표현

|         예시          |
| :-------------------: |
| 고객 개체 연락처 속성 |
|   책 개체 저자 속성   |

#### 단일 값과 다중 값 속성

<img src="https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch04/ch04-09-SVMV.PNG" height="auto" />

### 단순 속성(simple attribute)

- 의미를 더 분해할 수 없는 속성

|         예시          |
| :-------------------: |
| 고객 개체 적립금 속성 |
|    책 개체의 이름     |
|         ISBN          |
|       가격 속성       |

### 복합 속성(composite attribute)

- 의미를 분해할 수 있는 속성

|                               예시                               |
| :--------------------------------------------------------------: |
| 고객 개체 주소 속성 : 도 · 시 · 동 · 우편번호 등으로 의미 세분화 |
|       고객 개체 생년월일 속성 : 연 · 월 · 일로 의미 세분화       |

#### 단순 속성과 복합 속성

<img src="https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch04/ch04-10-SACA.PNG" height="auto" />

### 유도 속성(Derived Attribute)

<img src="https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch04/ch04-11-DA.PNG" height="auto" />

- 기존의 다른 속성 값에서 유도되어 결정된 속성
- 값이 별도로 저장 X
- E-R 다이어그램에서 점선 타원 표현

|         예시          |
| :-------------------: |
| 책 개체의 가격과 할인율 속성으로 계산되는 판매가격 속성|
|고객 개체의 출생연도 속성으로 계산되는 나이 속성|

### 널 속성(NULL Attribute)

- 널(NULL) 값이 허용되는 속성

#### 널(NULL) 값

- 아직 결정되지 않은 값
- 모르는 값
- 존재하지 않는 값
- 공백이나 0과는 상이

|         예시          |
| :-------------------: |
| 등급 속성이 널(NULL) 값 -> 등급 미결정|

### 키 속성(Key Attribute)

<img src="https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch04/ch04-12-KA.PNG" height="auto" />

- 각 개체 인스턴스 식별 시 사용되는 속성
- 모든 개체 인스턴스의 키 속성 값은 상이
- 둘 이상의 속성들로도 구성
- E-R 다이어그램에서 밑줄 표현

|         예시          |
| :-------------------: |
| 고객 개체의 고객아이디 속성|

### 관계(Relationship)

<img src="https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch04/ch04-13-RS.PNG" height="auto" />

- 개체와 개체가 맺는 의미 있는 연관성
- 개체 집합들 사이의 대응 관계, 매핑(mapping)
- E-R 다이어그램에서 마름모 표현

|         예시          |
| :-------------------: |
| 고객 개체와 책 개체 간의 구매 관계 : "고객은 책을 구매한다"|

#### 관계 유형 : 관계 참여 개체 타입 수 기준

<img src="https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch04/ch04-14-RT.PNG" height="auto" />

|관계 유형|설명|
|:---:|:---|
|이항 관계|개체 타입 두 개가 맺는 관계|
|삼항 관계|개체 타입 세 개가 맺는 관계|
|순환 관계|개체 타입 하나가 자기 자신과 맺는 관계|

#### 관계 대응 수(Cardinality)

- 두 개체 타입 관계에 실제로 참여하는 개별 개체 수

|타입 유형|설명|
|:---:|:----|
|일대일 관계|하나의 개체가 하나의 개체에 대응|
|일대다 관계|하나의 개체가 다수의 개체에 대응|
|다대일 관계|다수의 개체가 하나의 개체에 대응|
|다대다 관계|다수의 개체가 다수의 개체에 대응|

#### 관계 유형 : 매핑 카디널리티 기준

## 4절. 논리적 데이터 모델

## 5절. MySQL WorkBench 모델링
