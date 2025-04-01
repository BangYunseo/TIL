# Chapter 7. SQL 질의어

> 1절. 관계 데이터 모델
>
> 2절. 주요 용어들
>
> 3절. 관계 DB
>
> 4절. 키(Key)
>
> 5절. 무결성 제약조건

## 1절. 관계 데이터 모델
#### 

## 2절. 주요 용어들
####

## 3절. 관계 DB
>
> 4절. 키(Key)
>
> 5절. 무결성 제약조건

![ERD](https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch07/ERD.PNG)

#### ER 다이어그램 작성 지침
* 개체 타입은 키(Key) 속성 이외의 개체 타입을 설명하는 속성들 보유
* 다중값 속성은 별도의 개체 타입으로 분류
* 개체 타입을 직접적으로 설명하는 속성들을 개체 타입과 연결
* 관계 타입은 독자적인 존재 불가능
* 키 속성(또는 속성 집합)에는 밑줄 표현

#### ER 다이어그램 표현 기호

![ERDexpression](https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch06/ERDexpression.PNG)

#### ER 다이어그램 예제

![ERDex](https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch06/ERDex.PNG)

## 2절. 강한 개체 타입과 약한 개체 타입
#### 정의 및 표현
* 강한 개체 타입(String Entity Type)
    * 정의
        * 독자적으로 존재
        * 개체 타입 내에서 자신의 키(Key) 속성을 사용하여 고유하게 개체를 식별할 수 있는 개체 타입
    * 표현
        * 일반 직사각형

* 약한 개체 타입(Weak Entity Type)
    * 정의
        * 개체를 식별할 수 있는 키를 형성하기에 충분한 속성을 갖지 못한 개체 타입
        * 약한 개체 타입의 존재를 위해서는 반드시 소유 개체 타입(Owner Entity Type)의 존재 필요
        * 약한 개체 타입의 구별자(부분 키)와 소유 개체 타입의 키 속성을 결합해야 약한 개체를 고유하게 식별 가능
    * 표현
        * 이중선(겹줄) 직사각형 표현

* 약한 개체 타입 표현 예시 - 부양가족 개체

![WETex](https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch06/WETex.PNG)

#### 존재 종속(Existence-Dependence)
* 한 개체 타입(a)의 존재가 다른 개체 타입(b)의 존재에 영향을 받는 경우 a는 b에 '존재 종속'이라 표현
    * a : 종속 개체 타입(Subordinate Entity)
    * b : 주 개체 타입(Dominant Entity) 또는 소유 개체 타입

* 존재 종속 ER 다이어그램 표현 예시 : 대출(주 개체 타입)과 상환(종속 개체 타입)간의 대출상환 관계

![EDex](https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch06/EDex.PNG)

#### 구별자(Discriminator)
* 하나의 강한 개체 타입과 연관된 약한 개체 집합 안에서만 서로 구별할 수 있는 속성
* 부분 키(Partial Key)
* 점선 밑줄 표현

#### 식별 관계 타입(Identifying Relationship Type)
* 약한 개체 타입을 강한 개체 타입과 연관시켜 약한 개체를 유일하게 식별하도록 하는 관계
* 겹줄 마름모 표현



#### 부양 관계 타입
* 부양 관계 이해하기

![IRTex2](https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch06/IRTex2.PNG)

* 부양 관계 타입 ER 다이어그램 - 부양가족 개체를 사원 개체와 연관한 예시

![IRTex](https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch06/IRTex.PNG)


## 3절. 부분 참여와 전체 참여
#### 정의 및 표현
* 부분 참여(Partial Participation)
    * 정의
        * 어떤 개체 타입의 일부 개체만이 관계를 이루는 다른 개체 타입의 개체와 연관
        * 예시
            * 학생 - 교과목 간의 수강 관계
    * 특징
        * 관계의 참여 제약조건(Participation Constraint) 가운데 선택적(Optional) 참여에 해당
        * 대응 개체 수(min, max)로 표현하는 경우 min의 값은 '0'
    * 표현 
        * 실선 표현

* 전체 참여(Total Participation)
    * 정의
        * 어떤 개체 타입의 모든 개체가 반드시 관계를 이루는 다른 개체 타입의 개체와 연관
        * 예시
            * 회원 - 국가 간의 국적 관계
    * 특징
        * 관계의 참여 제약조건(Participation Constraint) 가운데 의무적(Mandatory) 참여에 해당
        * 대응 개체 수(min, max)로도 표현하는 경우 min의 값은 '1'
    * 표현
        * 이중 실선 표현

#### 표현 예시 다이어그램

![TPPPex](https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch06/TPPPex.PNG)

## 4절. EER 모델
#### ERR(Enhanced ER, 확장된 ER)
* 기본적인 ER 모델에 몇 가지 새로운 개념이 추가된 형태
* Extended ER(E2R, EER, 확장된 ER) 모델이라고 칭함

![EER](https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch06/EER.PNG)

#### 서브 타입 개체(Subtype Entity)
* 한 개체 타입에 속하는 개체들을 어떤 기준에 의해 몇 개의 소규모 그룹으로 나눈 것
* 원래 개체 타입의 하위 개체 타입이며 부분 집합
* 원래 개체의 서브 타입 개체라고 칭함

##### 서브 타입 개체의 예시
* 예시 1 : 개체 타입 - 학생
    * 서브 타입 개체 : 학부생, 대학원생
    * 학생은 학부생과 대학원생의 슈퍼 타입 개체

* 예시 2 : 개체 타입 - 학부생
    * 서브 타입 개체 : 여학생, 남학생

* 예시 3 : 개체 타입 - 남학생
    * 서브 타입 개체 : 군필 남학생, 미필 남학생

#### 슈퍼 타입 개체(Supertype Entity)
* 여러 개체 타입이 속하는 상위 개체 타입

##### 슈퍼 타입 개체의 예시
* 예시 1 : 개체 타입 - 교수, 조교, 직원
    * 슈퍼 타입 개체 : 교직원
    * 교직원은 교수, 직원, 조교의 슈퍼 타입이면서 사람의 서브 타입
        * 즉, 슈퍼 타입인지 서브 타입인지는 상대적인 결정

* 예시 2 : 개체 타입 - 교직원, 재학생, 졸업생
    * 슈퍼 타입 개체 : 사람

#### 슈퍼 - 서브 관계(IS-A 관계) 표현

![ISAR](https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch06/ISAR.PNG)

#### 속성 상속(Ingeritance)
* 서브 타입 개체는 슈퍼 타입 개체의 모든 속성을 상속받음
* 예시
    * 교수 개체의 속성
        * 직급 : 고유 속성
        * 주민등록번호, 이름, 연락처, 소속, 입사일, 급여 : 기본 속성
            * 위의 속성을 모두 2개의 슈퍼 타입 개체로부터 상속받아 포함

#### 세분화(Specialization)
* 한 개체 타입에 속하는 서브 타입을 결정하는 작업
* 일정한 기준에 따라 몇 가지 서브 타입으로 분리
* 각 서브 타입의 이름과 고유 속성 결정(Top-down 방식의 모델링)
    * 예시 : {교수, 조교, 직원}은 업무 유형에 따라 교직원의 세분화

![Spec](https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch06/Spec.PNG)

* 현실 세계를 보다 정교하게 모델링
* 널(NULL) 값을 갖는 속성 최소화
* 하나의 개체 타입에 대해 필요에 따라 여러 가지 세분화 가능
    * 예시 : {정규직, 계약직} 은 계약 유형에 따른 교직원의 세분화
* 세분화에 따라 서브 타입 개체는 다른 서브 타입 개체가 갖고 있지 않은 고유한 속성을 가져야 함
    * 예시 : 교수는 직급 속성, 조교는 지원 과목 속성, 직원은 담당 업무라는 고유 속성 보유

#### 일반화(Generalization)
* 세분화와 반대 개념
* 여러 개체 타입들의 슈퍼 타입 결정 작업
* 여러 개체 타입의 공통점만 수집
* 공통점에 근거한 새로운 슈퍼 타입 생성
* 모델링 단순화(Bottom-up 방식의 모델링)
    * 예시 : 승용차, 트럭, 버스 개체 타입은 '운송수단'으로 일반화

![Gene](https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch06/Gene.PNG)

#### 카테고리(Category)
* 별개의 개체 타입 집합
* 합집합(Union) 타입이라고도 함
    * 예시 : 차량 소유주 카테고리 - {사람, 회사, 은행}
* 하나 이상의 슈퍼 타입 개체와 단 하나의 서브 타입 개체가 슈퍼-서브 관계를 갖는 상황을 모델링할 때 유용
* 카테고리에 속하는 멤버(member)는 슈퍼 타입 개체 가운데 하나에 속함

#### 카테고리 표현
* 작은 삼각형 혹은 원 안에 Union 첫 자인 'U'자를 표시

![Category](https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch06/Category.PNG)
