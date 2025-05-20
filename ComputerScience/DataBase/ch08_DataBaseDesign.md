# Chapter 8. 데이터베이스 설계

> 1절. 데이터베이스 설계 단계
>
> 2절. 요구사항 분석
>
> 3절. 개념적 설계
>
> 4절. 논리적 설계
>
> 5절. 물리적 설계

## 1절. 데이터베이스 설계 단계

### 데이터베이스 설계

- 사용자의 다양한 요구사항을 고려해 데이터베이스를 설계하는 과정

### 관계 데이터베이스의 설계 방법

- E-R 모델 & 릴레이션 변환 규칙 이용
- 정규화 이용

### E-R 모델 & 릴레이션 변환 규칙을 통한 설계 과정

<img src="https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch08/ch08-01-DD.PNG"  height="auto" />

- 설계 과정 중 오류 발견
  - 변경 필요
  - 이전 단계로 돌아가 설계 내용 변경

## 2절. 요구사항 분석

### 목적

- 사용자의 요구사항 수집 및 분석
- 개발 데이터베이스 용도 파악

### 결과물

- 요구사항 명세서

### 주요 작업

- 실제로 데이터베이스를 사용할 주요 사용자 범위 결정
- 사용자가 조직에서 수행하는 업무 분석
- 면담, 설문 조사, 업무 관련 문서 분석 등의 방법으로 요구사항 수집
- 수집된 요구사항에 대한 분석 결과를 요구사항 명세서로 작성

### 요구사항 분석 : 한빛 마트 데이터베이스

- 인터넷으로 회원들에게 상품을 판매하는 한빛 마트 데이터베이스 개발

> 1. 한빛 마트에 회원으로 가입하려면 회원아이디, 비밀번호, 이름, 나이, 직업을 입력해야 한다.
> 2. 가입한 회원에게는 등급과 적립금이 부여된다.
> 3. 회원은 회원아이디로 식별한다.
> 4. 상품에 대한 상품번호, 상품명, 재고량, 단가 정보를 유지해야 한다.
> 5. 상품은 상품번호로 식별한다.
> 6. 회원은 여러 상품을 주문할 수 있고, 하나의 상품을 여러 회원이 주문할 수 있다.
> 7. 회원이 상품을 주문하면 주문에 대한 주문번호, 주문수량, 배송지, 주문일자 정보를 유지해야 한다.
> 8. 각 상품은 한 제조업체가 공급하고, 제조업체 하나는 여러 상품을 공급할 수 있다.
> 9. 제조업체가 상품을 공급하면 공급일자와 공급량 정보를 유지해야 한다.
> 10. 제조업체에 대한 제조업체명, 전화번호, 위치, 담당자 정보를 유지해야 한다.
> 11. 제조업체는 제조업체명으로 식별한다.
> 12. 회원은 게시글을 여러 개 작성할 수 있고, 게시글 하나는 한 명의 회원만 작성할 수 있다.
> 13. 게시글에 대한 글번호, 글제목, 글내용, 작성일자 정보를 유지해야 한다.
> 14. 게시글은 글번호로 식별한다.

## 3절. 개념적 설계

### 목적

- DBMS에 독립적인 개념적 스키마 설계
- 요구사항 분석 결과물을 개념적 데이터 모델로 개념적 구조로 표현
  => 개념적 모델링
  - 일반적으로 E-R 모델 이용

### 결과물

- 개념적 스키마
  - E-R 다이어그램

### 주요 작업

- 요구사항 분석 결과 기반의 중요한 개체 추출
- 개체 간 관계를 결정하여 E-R 다이어그램으로 표현

### 작업 과정

<img src="https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch08/ch08-02-CDMstep.PNG.PNG"  height="auto" />

1. 개체 추출, 각 개체의 주요 속성과 키 속성 선별
2. 개체 간 관계 결정
3. E-R 다이어그램으로의 표현

### 1. 개체와 속성 추출

#### 개체

- 저장할 가치가 있는 중요 데이터를 가진 사람, 사물 등

#### ex : 병원 데이터베이스 개발에 필요한 개체

- 병원 운영에 필요한 사람
  - 환자, 의사, 간호사 등
- 병원 운영에 필요한 사물
  - 병실, 수술실, 의료 장비 등

#### 개체 추출 방법

- 요구사항 문장에서 업무와 관련이 깊은 의미 있는 명사 형태
  - 업무와 관련이 적은 일반적이고 광범위한 의미의 명사는 제외
  - 의미가 같은 명사가 여럿인 경우 대표 명사 하나만 선택
- 찾은 명사를 개체와 속성으로 분류

#### 한빛 마트 데이터베이스에서의 개체 · 속성 추출

<img src="https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch08/ch08-03-Entity.PNG"  height="auto" />

- 개체와 속성 추출을 위한 정보

#### 개체 : 회원

<img src="https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch08/ch08-04-entityM.PNG"  height="auto" />

- 개체 : 회원
- 속성 : 회원아이디, 비밀번호, 이름, 나이, 직업, 등급, 적립금
- 회원 개체 키 속성 : 회원아이디

#### 개체 : 회원, 상품

<img src="https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch08/ch08-05-entityO.PNG"  height="auto" />

- 개체 : 회원, 상품
- 속성 : 주문번호, 주문수량, 배송지, 주문일자
  - 회원이 상품을 "주문"해야 생기는 중요한 정보
  - 회원이나 상품 개체의 속성은 X
  - 특정 관계의 속성 형태(주문)

#### 개체와 속성 추출 결과

<img src="https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch08/ch08-06-EA.PNG"  height="auto" />

#### 회원 개체 다이어그램

<img src="https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch08/ch08-07-entityM.PNG"  height="auto" />

#### 상품 개체 다이어그램

<img src="https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch08/ch08-08-entityP.PNG"  height="auto" />

#### 제조업체 개체 다이어그램

<img src="https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch08/ch08-09-entityMani.PNG"  height="auto" />

#### 게시글 개체 다이어그램

<img src="https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch08/ch08-10-entityN.PNG"  height="auto" />

### 2. 관계 추출

#### 관계

- 개체 간 의미 있는 연관성

#### 관계 추출 방법

- 요구사항 문장에서 개체 간 연관성을 표현한 동사
  - 의미가 같은 동사가 여럿인 경우 대표 동사 하나만 선택
- 관계 매핑 카디널리티, 참여 특성 결정
  - 매핑 카디널리티
    - 일대일(1:1)
    - 일대다(1:n)
    - 다대다(n:m)
  - 참여 특성
    - 필수적 참여
    - 선택적 참여

#### 관계 : 주문

<img src="https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch08/ch08-11-relationshipO.PNG"  height="auto" />

- 관계 : 주문
  - "회원" 개체와 "상품" 개체가 맺는 관계
    - "회원" 개체 : 선택적 참여
    - "상품" 개체 : 선택적 참여
  - 다대다(n:m) 관계
- 속성 : 주문번호, 주문수량, 배송지, 주문일자

#### 관계 : 공급

<img src="https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch08/ch08-12-relationshipP.PNG"  height="auto" />

- 관계 : 공급
  - "상품" 개체와 "제조업체" 개체가 맺는 관계
    - "상품" 개체 : 필수적 참여
    - "제조업체" 개체 : 선택적 참여
  - 일대다(1:m) 관계
- 속성 : 공급일자, 공급량

#### 관계 : 공급

<img src="https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch08/ch08-13-relationshipW.PNG"  height="auto" />

- 관계 : 작성
  - "회원" 개체와 "게시글" 개체가 맺는 관계
    - "회원" 개체 : 선택적 참여
    - "게시글" 개체 : 필수적 참여
  - 일대다(1:m) 관계

#### 관계 추출 결과

<img src="https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch08/ch08-14-R.PNG"  height="auto" />

#### 주문 관계 다이어그램

<img src="https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch08/ch08-15-rdO.PNG"  height="auto" />

#### 공급 관계 다이어그램

<img src="https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch08/ch08-16-rdP.PNG"  height="auto" />

#### 작성 관계 다이어그램

<img src="https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch08/ch08-17-rdW.PNG"  height="auto" />

#### 전체적인 다이어그램

<img src="https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch08/ch08-18-relationDiagram.PNG"  height="auto" />

## 4절. 논리적 설계

### 목적

- DBMS에 적합한 논리적 스키마 설계
- 개념적 스키마를 논리적 데이터 모델을 이용해 논리적 구조로 표현
  => 논리적(데이터) 모델링
  - 일반적으로 관계 데이터 모델을 많이 이용

### 결과물

- 논리적 스키마
  - 릴레이션 스키마

### 주요 작업

- E-R 다이어그램을 릴레이션 스키마로 변환
- 속성의 데이터타입, 길이, NULL 값 허용 여부, 기본값, 제약조건 등을 세부사항으로 결정
- 결과 문서화

### 규칙

- 릴레이션 스키마로의 변환 규칙
- 변환 규칙은 순서대로 적용
- 해당하지 않는 규칙은 제외

1. 모든 개체는 릴레이션으로 변환
2. 다대다(n:m) 관계는 릴레이션으로 변환
3. 일대다(1:n) 관계는 외래키로 표현
4. 일대일(1:1) 관계는 외래키로 표현
5. 다중 값 속성은 릴레이션으로 변환

### 1. 모든 개체는 릴레이션으로 변환

- E-R 다이어그램의 각 개체를 하나의 릴레이션으로 변환
  - 개체 속성이 복합 속성인 경우
    - 복합 속성을 구성하는 단순 속성만 릴레이션의 속성으로 변환
  - 개체 이름 => 릴레이션 이름
  - 개체 속성 => 릴레이션 속성
  - 개체 키 속성 => 릴레이션 기본키

#### 개체 : 상품 릴레이션 예시

<img src="https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch08/ch08-19-ERex1.PNG"  height="auto" />

#### 개체 : 고객 릴레이션 예시

<img src="https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch08/ch08-20-ERex2.PNG"  height="auto" />

### 2. 다대다(n:m) 관계는 릴레이션으로 변환

- E-R 다이어그램의 다대다 관계를 하나의 릴레이션으로 변환
  - 관계에 참여하는 개체를 규칙 1에 따라 릴레이션으로 변환
  - 이 릴레이션의 기본키를 관계 릴레이션에 포함시켜 외래키로 지정
  - 외래키들을 조합하여 관계 릴레이션의 기본키로 지정
  - 관계 이름 => 릴레이션 이름
  - 관계 속성 => 릴레이션 속성

#### 관계 : 주문 릴레이션 예시

<img src="https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch08/ch08-21-RRex3.PNG"  height="auto" />

### 3. 일대다(1:n) 관계는 외래키로 표현

- E-R 다이어그램의 일대다 관계는 외래키로만 표현
  - 3-1. 일반적인 일대다 관계는 외래키로 표현
  - 3-2. 약한 개체가 참여하는 일대다 관계는 외래키를 포함해서 기본키로 지정

#### 3-1. 일반적인 일대다 관계는 외래키로 표현

- 일대다(1:n) 관계에서 1측 개체 릴레이션의 기본키를 n측 개체 릴레이션에 포함시켜 외래키로 지정
- 관계의 속성들도 n측 개체 릴레이션에 포함

#### 관계 : 공급 릴레이션 예시

<img src="https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch08/ch08-22-RRex4.PNG"  height="auto" />

#### 3-2. 약한 개체가 참여하는 일대다 관계는 외래키를 포함해서 기본키로 지정

- 일대다(1:n) 관계에서 1측 개체 릴레이션의 기본키를 n측 개체 릴레이션에 포함시켜 외래키로 지정
- 관계의 속성들도 n측 개체 릴레이션에 포함
- n측 개체 릴레이션은 외래키를 포함하여 기본키를 지정
  - 약한 개체는 강한 개체에 따라 존재 여부가 결정
  - 강한 개체의 기본키로 식별

#### 관계 : 존재 릴레이션 예시

<img src="https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch08/ch08-23-RRex5.PNG"  height="auto" />

### 4. 일대일(1:1) 관계는 외래키로 표현

- E-R 다이어그램의 일대일 관계는 외래키로만 표현
  - 4-1. 일반적인 일대일 관계는 외래키를 서로 주고받음
  - 4-2. 일대일 관계에 필수적으로 참여하는 개체의 릴레이션만 외래키를 받음
  - 4-3. 모든 개체가 일대일 관계에 필수적으로 참여하면 릴레이션 하나로 합침

#### 4-1. 일반적인 일대일 관계는 외래키를 서로 주고받음

- 관계에 참여하는 개체 릴레이션들이 서로의 기본키를 주고받아 외래키로 지정
- 관계의 속성들도 모든 개체 릴레이션에 포함
- 불필요한 데이터 중복 발생 가능성 존재

#### 혼인 관계 예시 : 일대일(1:1)

<img src="https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch08/ch08-24-RRex6.PNG"  height="auto" />

#### 4-2. 필수적으로 참여하는 개체 릴레이션만 외래키를 받음

- 관계에 필수적으로 참여하는 개체 릴레이션에만 외래키 포함
- 관계의 속성들은 관계에 필수적으로 참여하는 개체 릴레이션에 포함

#### 혼인 관계 예시 : 일대일(1:1) - 필수 / 선택

<img src="https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch08/ch08-25-RRex7.PNG"  height="auto" />

#### 4-3. 모든 개체가 필수적 참여 시 릴레이션 하나로 합침

- 관계 참여 개체 릴레이션들을 하나의 릴레이션으로 합쳐 표현
- 관계의 이름을 릴레이션 이름으로 사용
- 관계에 참여하는 두 개체의 속성들을 관계 릴레이션에 포함
- 두 개체 릴레이션의 키 속성을 조합하여 관계 릴레이션의 기본키로 지정

#### 혼인 관계 예시 : 일대일(1:1) - 필수 / 필수

<img src="https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch08/ch08-26-RRex8.PNG"  height="auto" />

### 5. 다중 값 속성은 릴레이션으로 변환

- E-R 다이어그램의 다중 값 속성은 독립적인 릴레이션으로 변환
  - 다중 값 속성과 함께 그 속성을 가진 개체 릴레이션의 기본키를 외래키로 가져와 새로운 릴레이션에 포함
  - 새로운 릴레이션의 기본키는 다중 값 속성과 외래키를 조합하여 지정

#### 사원 개체 릴레이션

<img src="https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch08/ch08-27-ERex9.PNG"  height="auto" />

#### 부하직원 속성

(여기부터 재작성 필요)

<img src="https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch08/ch08-28-ERex9-1.PNG"  height="auto" />

- 사원 릴레이션은 "속성에 다중값을 저장할 수 없다"는 릴레이션 특성을 위반

<img src="https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch08/ch08-29-ERex9-2.PNG"  height="auto" />

- 사원 릴레이션은 릴레이션의 특성을 위반하지 않음
- 하지만 사원번호, 사원명, 직위 속성의 값이 불필요하게 중복 저장되는 문제 발생

<img src="https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch08/ch08-30-rt.PNG"  height="auto" />

- 규칙 5에 따라 다중값 속성을 독립적인 릴레이션으로 변환 시 불필요한 중복을 제거하며 릴레이션 특성 만족 가능

### 기타 고려 사항

<img src="https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch08/ch08-31-dr.PNG"  height="auto" />

- 모든 관계를 독립적인 릴레이션으로 변환 가능
  - 속성이 많은 관계 : 유형에 상관 없이 릴레이션으로의 변환 가능

<img src="https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch08/ch08-32-dr2.PNG"  height="auto" />

- 개체가 자기 자신과 관계를 맺는 순환 관계도 기본 규칙을 그대로 적용

### 규칙 1 : 다이어그램 & 스키마

<img src="https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch08/ch08-33-rule1-1.PNG"  height="auto" />

<img src="https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch08/ch08-34-rule1-2.PNG"  height="auto" />

### 규칙 2 : 다이어그램 & 스키마

<img src="https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch08/ch08-35-rule2-1.PNG"  height="auto" />

<img src="https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch08/ch08-36-rule2-2.PNG"  height="auto" />

### 규칙 3 : 다이어그램 & 스키마

<img src="https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch08/ch08-37-rule3-1.PNG"  height="auto" />

<img src="https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch08/ch08-38-rule3-2.PNG"  height="auto" />

### 테이블 명세서

<img src="https://github.com/BangYunseo/TIL/blob/main/ComputerScience/DataBase/Image/ch08/ch08-39-table.PNG"  height="auto" />

- 릴레이션 스키마에 대한 설계 정보를 기술한 문서
- 릴레이션 스키마 변환 후 속성 데이터 타입, 길이, NULL 값 허용 여부, 기본값, 제약조건 등을 세부적으로 결정하고 문서화

## 5절. 물리적 설계 및 구현

### 물리적 설계

- 설계 4 단계
- 하드웨어 및 운영체제 특성 고려
- 필요한 인덱스 구조나 내부 저장 구조 등에 대한 물리적 구조 설계

### 구현

- 설계 5 단계
- SQL로 작성한 명령문을 DBMS에서 실행하여 데이터베이스 실제 생성

#### SQL 작성 예시

- SQL 작성 전 테이블 명세서 확인

```SQL
CREATE TABLE 회원(
  회원아이디 VARCHAR(20) NOT NULL,
  비밀번호 VARCHAR(20) NOT NULL,
  이름 VARCHAR(10) NOT NULL,
  나이 INT,
  직업 VARCHAR(20),
  등급 VARCHAR(10) NOT NULL DEFAULT 'silver',
  적립금 INT NOT NULL DEFAULT 0,
  PRIMARY KEY(회원아이디),
  CHECK (나이 >= 0),
  CHECK (등급 in ('silver', 'gold', 'vip'))
);
```
