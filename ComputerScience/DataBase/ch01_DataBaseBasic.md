# Chapter 1. 데이터베이스 기본 개념

> 1절. 데이터베이스의 필요성
>
> 2절. 데이터베이스의 정의 및 특성
>
> 3절. 데이터 과학 시대의 데이터

## 1절. 데이터베이스의 필요성

### 데이터와 정보

| <img src="https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch01/ch01-01-DI.PNG"  width="30%" height="30%"/> | - 데이터(Data) : 현실 세계에서 단순히 관찰·측정하여 수집한 사실·값<br>- 정보(Information) : 의사 결정에 유용하게 활용하는 데이터를 처리한 결과물 |
| ------------------------------------------------------------------------------------------------------------------------------------- | ------------------------------------------------------------------------------------------------------------------------------------------------ |

### 정보 처리(Information Processing)

- 데이터 정보 추출 과정

<img src="https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch01/ch01-02-IP.PNG"  width="60%" height="60%"/>

### 정보 시스템(Information System)

- 조직 운영에 필요한 데이터를 수집하여 저장
- 필요 시 유용한 정보를 만드는 수단

### 데이터베이스(DataBase)

- 정보 시스템 안에서 데이터를 저장
- 필요 시 데이터 제공

<img src="https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch01/ch01-03-IS.PNG"  width="50%" height="50%"/>

## 2절. 데이터베이스의 정의 및 특성

#### 데이터베이스(DB; DataBase)

- 특정 조직의 여러 사용자가 공유하여 사용할 수 있도록 통합해서 저장한 운영 데이터의 집합

|             종류              | 내용                                                                 |
| :---------------------------: | :------------------------------------------------------------------- |
| 통합 데이터(Integrated Data)  | 최소의 중복과 통제가 가능한 중복만 허용하는 데이터                   |
|   공유 데이터(Shared Data)    | 특정 조직의 여러 사용자가 함께 소유하고 이용할 수 있는 공용의 데이터 |
|   저장 데이터(Stored Data)    | 컴퓨터가 접근할 수 있는 매체에 저장된 데이터                         |
| 운영 데이터(Operational Data) | 조직의 주요 기능을 수행하기 위해 지속적으로 필요한 데이터            |

#### 데이터베이스 특징

|                 특징                 | 내용                                                                                                |
| :----------------------------------: | :-------------------------------------------------------------------------------------------------- |
| 실시간 접근(Real-Time Accessibility) | 사용자의 데이터 요구에 실시간 응답                                                                  |
|   계속 변화(Continuous Evolution)    | 데이터의 계속적인 삽입, 삭제, 수정을 통해 현재의 정확한 데이터 유지                                 |
|    동시 공유(Concurrent Sharing)     | 서로 다른 데이터의 동시 사용뿐만 아니라 같은 데이터의 동시 사용도 지원                              |
|  내용 기반 참조(Content Reference)   | 데이터가 저장된 주소나 위치가 아닌 내용으로 참조<br>(ex : 재고량이 1,000개 이상인 제품의 이름 검색) |

## 3절. 데이터 과학 시대의 데이터

#### 형태 별 데이터 분류

- 정형 데이터
- 반정형 데이터
- 비정형 데이터

<img src="https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch01/ch01-04-DataType.PNG"  width="50%" height="50%"/>

##### 정형 데이터(Structured Data)

- 구조화된 데이터
- 미리 정해진 구조에 따라 저장된 데이터
  - 데이터 구조에 대한 설명 및 데이터 내용은 별도 유지
- ex) 엑셀의 스프레드시트, 관계 데이터베이스의 테이블

<img src="https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch01/ch01-05-SD.PNG"  width="50%" height="50%"/>

##### 반정형 데이터(Semi-Structured Data)

- 구조에 따라 저장된 데이터
- 데이터 내용 안에 구조에 대한 설명이 함께 존재
- 구조를 파악하는 파싱(Parsing) 과정 필요
- 보통 파일 형태로 저장
- ex) 웹에서 데이터를 교환하기 위해 작성하는 HTML/XML/JSON 문서 및 웹 로그, 센서 데이터

<img src="https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch01/ch01-06-SSD.PNG"  width="50%" height="50%"/>

##### 비정형 데이터(Unstructured Data)

- 정해진 구조가 없이 저장된 데이터
- ex) 소셜 데이터의 텍스트, 영상, 이미지, 워드 및 PDF 문서와 같은 멀티미디어 데이ㅌ

<img src="https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch01/ch01-07-UD.PNG"  width="30%" height="30%"/>

#### 특성에 따른 데이터 분류

- 통계적 관점에서 데이터 특성에 따라 적합한 분석 방법을 선택하기 위해 데이터 분석 분야에서 주로 활용
  - 범주형 데이터
  - 수치형 데이터
    <img src="https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch01/ch01-08-SD.PNG"  width="50%" height="50%"/>

##### 범주형 데이터(Categorical Data)

- 범주로 구분할 수 있는 값
- 종류를 나타내는 값을 가진 데이터
- 크기 비교와 산술적인 연산이 불가능한 질적 데이터

|            종류             | 내용                                 | 예시                                                       |
| :-------------------------: | :----------------------------------- | :--------------------------------------------------------- |
| 명목형 데이터(Nominal Data) | 순서, 서열이 없는 값을 가지는 데이터 | 성별, 혈액형, 학과명, 거주 지역, 음식 메뉴, MBTI 검사 결과 |
| 순서형 데이터(Ordinal Data) | 순서, 서열이 있는 값을 가지는 데이터 | 학년, 학점, 회원 등급                                      |

##### 수치형 데이터(Numerical Data)

- 크기 비교와 산술적인 연산이 가능한 숫자 값을 가진 데이터
- 양적 데이터

|              종류              | 내용                                                       | 예시                       |
| :----------------------------: | :--------------------------------------------------------- | :------------------------- |
|  이산형 데이터(Discrete Data)  | 개수를 셀 수 있는 단절된 숫자 값을 가지는 데이터           | 고객 수, 판매량, 합격자 수 |
| 연속형 데이터(Continuous Data) | 측정을 통해 얻는 연속적으로 이어진 숫자 값을 가지는 데이터 | 키, 몸무게, 온도, 점수     |

##### 정성적 데이터(Qualitative Data)

- 좁은 의미로는 범주형 데이터
- 사람의 주관적인 생각과 평가를 기술한 비정형 데이터
- 정량적 데이터에 비해 저장 및 처리 측면에서 큰 비용이 드는 경우가 다수

##### 정량적 데이터(Quantitative Data)

- 좁은 의미로는 수치형 데이터
- 객관적 측정을 통해 수치, 도형, 기호 등으로 표현한 정형 데이터
