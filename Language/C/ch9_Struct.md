#  Chapter 9. 구조체

> '쉽게 풀어쓴 C언어 Express - 천인국' 13장 학습 내용
>
> [소스코드](https://github.com/BangYunseo/Express-C/tree/main/ch9_%EA%B5%AC%EC%A1%B0%EC%B2%B4)
> 
> 1절. 구조체 정의
> 
> 2절. 구조체 선언
>
> 3절. 구조체 멤버
>
> 4절. 구조체 배열
>
> 5절. 구조체와 포인터
>
> 6절. 구조체와 함수


## 1절. 구조체 기초
#### 자료형의 분류
* 자료형의 분류는 구조체와 유사
	 
![struct](https://github.com/BangYunseo/TIL/blob/main/Language/C/Image/ch9/struct.PNG)

#### 구조체의 필요성
* 연관성 있는 서로 다른 개별적인 자료형의 변수들을 하나의 단위로 묶은 새로운 자료형
* 연관된 멤버로 구성되는 통합 자료형으로 대표적인 유도 자료형
  * 기존 자료형으로 새로이 만들어진 자료형은 유도 자료형(derived data types)

![needstruct](https://github.com/BangYunseo/TIL/blob/main/Language/C/Image/ch9/needstruct.PNG)

#### 구조체 개념

![struct2](https://github.com/BangYunseo/TIL/blob/main/Language/C/Image/ch9/struct2.PNG)

#### 구조체와 배열

![arraystruct](https://github.com/BangYunseo/TIL/blob/main/Language/C/Image/ch9/arraystruct.PNG)

#### 구조체 정의 개념
* 구조체를 자료형으로 사용하려면 먼저 구조체를 정의
  * 구조체를 만들 구조체 틀(template)을 정의
![structtemplate](https://github.com/BangYunseo/TIL/blob/main/Language/C/Image/ch9/structtemplate.PNG)

#### 구조체 정의 구문

![structcode](https://github.com/BangYunseo/TIL/blob/main/Language/C/Image/ch9/structcode.PNG)

#### 구조체 정의 위치
* 구조체 정의는 정의 위치에 따라 구조체의 유효 범위 결정
* 구조체의 정의도 변수 선언처럼 유효범위는 전역(global) 또는 지역(local)
  * 전역(global)
    * main() 함수 외부 상단에서 정의된 구조체
  * 지역(local)
    * main() 함수 또는 다른 함수 내부에서 정의된 구조체
   
![struct4](https://github.com/BangYunseo/TIL/blob/main/Language/C/Image/ch9/struct4.PNG)

## 2절. 선언
#### 구조체 선언

![struct3](https://github.com/BangYunseo/TIL/blob/main/Language/C/Image/ch9/struct3.PNG)
  
#### 구조체 선언의 예시
```C
// x와 y로 이루어지는 화면의 좌표 구조체
struct point{
	int x;	// x 좌표
	int y;	// y 좌표
};
```
```C
// 날짜 구조체
struct date{
	int month;	// 월
	int day;	// 일
	int year;	// 년도
};
```
```C
// 복소수 구조체
struct complex{
	double real;	// 실수부
	double image;	// 허수부
};
```
```C
// 사각형 구조체
struct rectangle{
	int x, y;	// x, y
	int width;	// 너비
	int height;	// 높이
};
```

#### 구조체 변수 선언
* 구조체 정의와 구조체 변수 선언은 다름

![structdef](https://github.com/BangYunseo/TIL/blob/main/Language/C/Image/ch9/structdef.PNG)

```C
struct accout{
	char name[12];	// 계좌주 이름
	int actnum;	// 계좌 번호
	double balance;	// 잔고
};

struct account mine = {"홍길동", 1001, 300000};
```

![structaccount](https://github.com/BangYunseo/TIL/blob/main/Language/C/Image/ch9/structaccount.PNG)

## 3절. 구조체 멤버
#### 구조체 초기화
* 중괄호를 이용하여 초기값 나열
  * 초기화 값은 중괄호 내부에서 각 멤버 정의 순서대로 초기값을 쉼표로 구분하여 나타냄
  * 기술되지 않은 멤버값들은 자료형에 따라 기본값인 0, 0.0, '\0' 등으로 저장

```C
struct student{
	int number;
	char name[10];
	double grade;
};

struct student s1 = { 24, "Kim", 4.3 };
```

![structstudent](https://github.com/BangYunseo/TIL/blob/main/Language/C/Image/ch9/structstudent.PNG)

#### 구조체 멤버 참조

![structmem](https://github.com/BangYunseo/TIL/blob/main/Language/C/Image/ch9/structmem.PNG)

#### 학생 정보 출력 예제
```C
#include <stdio.h>

struct student{
	int number;		// 정수형 변수이자 학번을 저장할 변수 number를 생성
	char name[10];		// 문자형 배열이자 이름을 저장할 배열 name[10]을 생성
	double grade;		// 실수형 변수이자 학점을 저장할 변수 grade를 생성
};
int main(void){
	struct student s;
	// 구조체 student를 변수 s로 선언

	s.number = 20190001;		// 구조체 안의 변수 number의 값을 2019000로 초기화
	strcpy(s.name, "홍길동");	// 구조체 안의 배열 name[10]의 값을 홍길동으로 초기화
	// 문자열 배열은 문자열 변수와 다르게 strcpy() 함수를 이용하여 문자열로 변경
	
	s.grade = 4.3;				// 구조체 안의 변수 grade의 값을 4.3으로 초기화

	printf("학번 : %d\n", s.number);		// 학번을 구조체를 이용한 변수 s.student로 출력
	printf("이름 : %s\n", s.name);			// 이름을 구조체를 이용한 변수 s.name로 출력
	printf("학점 : %f\n", s.grade);			// 학점을 구조체를 이용한 변수 s.grade로 출력

	return 0;
}

// 출력 예시
// 학번 : 20190001
// 이름 : 홍길동
// 학점 : 4.3
```

#### 학생 정보 입력받고 출력하는 예제

```C
#include <stdio.h>

struct student{
	int number;		// 정수형 변수이자 학번을 저장할 변수 number를 생성
	char name[10];		// 문자형 배열이자 이름을 저장할 배열 name[10]을 생성
	double grade;		// 실수형 변수이자 학점을 저장할 변수 grade를 생성
};
int main(void){
	struct student s;	// 구조체 student를 변수 s로 선언

	printf("학번을 입력하세요 : ");
	scanf_s("%d", &s.number);			// 학번을 입력받고 구조체의 s.number의 주소에 전달

	printf("이름을 입력하세요 : ");
	scanf_s("%s", s.name, 16);			// 이름을 입력받고 구조체의 s.name의 주소에 전달
	// name은 배열의 이름이며 이는 이미 배열을 가리키는 포이너라는 의미
	// 따라서 앞에 & 없음

	printf("학점을 입력하세요(실수) : ");		
	scanf_s("%lf", &s.grade);			// 학점을 입력받고 구조체의 s.grade의 주소에 전달

	printf("학번 : %d\n", s.number);		// 학번을 구조체를 이용한 변수 s.student로 출력
	printf("이름 : %s\n", s.name);			// 이름을 구조체를 이용한 변수 s.name로 출력
	printf("학점 : %lf\n", s.grade);		// 학점을 구조체를 이용한 변수 s.grade로 출력

	return 0;
}

// 출력 예시
// 학번을 입력하세요 : 20190001
// 이름을 입력하세요 : 홍길동
// 학점을 입력하세요(실수) : 4.3
// 학번 : 20190001
// 이름 : 홍길동
// 학점 : 4.3
```

#### 구조체를 멤버로 가지는 구조체
```C
struct date{		// 구조체 선언
	int year;	// 년
	int month;	// 월
	int day;	// 일
};

struct account{
	struct date open;	// 계좌 개설일자			// 구조체 안에 구조체 포함
	char name[12];		// 계좌주 이름
	int actnum;		// 계좌번호
	double balance;		// 잔고
};
struct account me = {{2012, 3, 9}, "홍길동", 1001, 30000 };	// 구조체 변수 선언

// 멤버 참조
me.open.year = 2024;
me.open.month = 2;
me.open.month = 15;
```

![structdate](https://github.com/BangYunseo/TIL/blob/main/Language/C/Image/ch9/structdate.PNG)

#### 구조체 변수의 대입과 비교
* 같은 구조체 변수끼리 대입은 가능하지만 비교는 불가능
```C(다시 작성)
struct point{
	int x;
	int y;
};

int main(void){
	struct point p1 = {10, 20};
	struct point p2 = {30, 40};

	p2 = p1;
	// 대입 가능

	// if(p1 == p2)				printf("p1 and p2 are same!");
	// 위의 if문은 올바른 비교가 아니며 이 비교문을 사용할 경우 컴파일 오류가 발생

	if((p1.x == p2.x) && (p1.y == p2.y))	printf("p1 and p2 are same!");
	// 즉, 각각의 요소들을 한 번에 비교할 수 없음
	// 하나의 요소들마다 비교해야 함
```

## 4절. 구조체 배열
#### 구조체 배열
* 구조체를 여러 개 모은 것

![structarray](https://github.com/BangYunseo/TIL/blob/main/Language/C/Image/ch9/structarray.PNG)

```C
struct student{
	int number;
	char name[20];
	double grade;
};

int main(void){
	struct student list[100];
	// 구조체의 배열 선언
	// 구조체 100개를 저장 가능

	list[2].number = 24;
	strcpy(list[2].name, "홍길동");
	list[2].grade = 4.3;
}
```

#### 구조체 배열의 초기화
* 배열 초기화 안에 구조체 초기화가 필요하므로 중괄호 안에 중괄호를 사용
```C
struct student list[3] = {
	{ 1, "Park", 3.42 },
	{ 2, "Kim", 4.31 },
	{ 3, "Lee", 2.98 }
};
```

#### 구조체 배열 변수 선언

![structarrayv](https://github.com/BangYunseo/TIL/blob/main/Language/C/Image/ch9/structarrayv.PNG)

#### 학생 정보 입력 예제

```C
#define SIZE 3
#include <stdio.h>

struct student {
	int number;
	char name[20];
	double grade;
};

int main(void) {
	struct student list[SIZE];
	int i;

	for(i = 0; i < SIZE; i++) {
		printf("학번을 입력하세요 >> ");
		scanf("%d", &list[i].number);

		printf("이름을 입력하세요 >> ");
		scanf("%s", list[i].name);

		printf("학점을 입력하세요(실수) >> ");
		scanf("%lf", &list[i].grade);
	}

	for(i = 0; i< SIZE; i++)	// 배열 list[]에 저장된 값 출력
		printf("학번 : %d, 이름 : %s,  학점 : %f\n", list[i].number, list[i].name, list[i].grade);
	return 0;
}

// 출력 예시
// 학번을 입력하세요 >> 20240001
// 이름을 입력하세요 >> 홍길동
// 학점을 입력하세요(실수) >> 4.0
// 학번을 입력하세요 >> 20240002
// 이름을 입력하세요 >> 김코딩
// 학점을 입력하세요(실수) >> 4.32
// 학번을 입력하세요 >> 20240003
// 이름을 입력하세요 >> 박코딩
// 학점을 입력하세요(실수) >> 3.28
// 학번 : 20240001, 이름 : 홍길동, 학점 : 4.000000
// 학번 : 20240002, 이름 : 김코딩, 학점 : 4.320000
// 학번 : 20240003, 이름 : 박코딩, 학점 : 3.280000 
```

## 5절. 구조체와 포인터
#### 문자열을 처리하기 위한 포인터 char *와 배열 char []
* char 포인터
  * 문자열의 첫 문자 주소를 저장하므로 문자열 상수의 주소로 사용
```C
char *dept;		// 학과 이름
char name[12];		// 학생 이름
```

* char 배열
  * 문자열을 구성하는 모든 문자를 하나씩 저장
  * 마지막에 '\0' 문자를 저장하여 사용
* char 포인터와 char 배열

![pointerarray](https://github.com/BangYunseo/TIL/blob/main/Language/C/Image/ch9/pointerarray.PNG)

#### 구조체와 포인터
* 구조체를 가리키는 포인터
* 포인터를 멤버로 가지는 구조체

![sp](https://github.com/BangYunseo/TIL/blob/main/Language/C/Image/ch9/sp.PNG)

#### 구조체를 가리키는 포인터
```C
struct student{
	int number;
	char name[20];
	double grade;
};
int main(void){
	struct student s = { 24, "Kim", 4.3 };
	struct student *p;
	// 구조체를 가리키는 포인터 생성
	// 포인터 p는 student 구조체를 가리킬 수 있는 포인터

	p = &s;
	// 구조체 포인터 p와 구조체 s를 연결하려면 s의 주소를 추출하여 p에 대입
	// 구조체 주소를 포인터에 대입

	printf("학번 : %d 이름 : %s 학점 : %f\n", s.number, s.name, s.grade);
	printf("학번 : %d 이름 : %s 학점 : %f\n", (*p).number, (*p).name, (*p).grade);
	// 포인터를 통해 구조체의 정보에 접근
	// (*p)는 구조체가 됨
	return 0;
}
```

![structpointerp](https://github.com/BangYunseo/TIL/blob/main/Language/C/Image/ch9/stuructpointerp.PNG)

#### 구조체의 포인터 변수 선언
* 변수 os를 선언
  * 문장 lecture *p = &os;
    * lecture 포인터 변수 p에 &os 저장
    * 포인터 p로 구조체 변수 os 멤버 참조 가능

![structpointeros](https://github.com/BangYunseo/TIL/blob/main/Language/C/Image/ch9/stuructpointeros.PNG)

#### -> 연산자 : 구조체 포인터
* -> 연산자는 구조체 포인터
  * 구조체 멤버를 참조할 때 사용

```C
struct student{
	int number;
	char name[20];
	double grade;
};
int main(void){
	struct student s = { 24, "Kim", 4.3 };
	struct student *p;
	// 구조체를 가리키는 포인터 생성
	// 포인터 p는 student 구조체를 가리킬 수 있는 포인터

	p = &s;
	// 구조체 포인터 p와 구조체 s를 연결하려면 s의 주소를 추출하여 p에 대입
	// 구조체 주소를 포인터에 대입

	printf("학번 : %d 이름 : %s 학점 : %f\n", p->number, p->name, p->grade);
	return 0;
}
```

#### 포인터 변수의 구조체 멤버 접근 연산자 ->
* 포인터 p가 가리키는 구조체 변수의 멤버 name을 접근하는 연산식
* p->type, p->credit, p->hours
  * 각각 os.type, os.credit, os.hours를 참조
  * ->에서 -와 > 사이에 공백이 들어갈 수 없음
* 연산식 (*p).name으로도 사용 가능
  * (*p).name은 *p.name과 다르다는 것을 주의
    * *p.name은 *(p.name)과 같은 연산식
    * p가 포인터이므로 p.name은 문법 오류 발생

![pointerp](https://github.com/BangYunseo/TIL/blob/main/Language/C/Image/ch9/pointerp.PNG)

* 접근연산자 ->와 .의 연산자 우선 순위
  * 간접연산자 *를 포함한 다른 어떠한 연산자 우선순위보다 가장 높음
    * 연산자 ->와 .은 우선순위 1위이며 결합성은 좌에서 우
    * 연산자 *은 우선순위 2위이고 결합성은 우에서 좌
   
```C
struct student *p;

struct student s = { 24, “Kim”, 4.3 };
struct student *p;

p = &s;

printf("학번 : %d 이름 : %s 키 : %f \n", p->number, p->name, p->grade);
```

#### 학생 정보 출력 예제

```C
#define SIZE 3
#include <stdio.h>

struct student {
	int number;
	char name[20];
	double grade;
};

int main(void) {
	struct student s = { 1, "홍길동", 4.3 };
	struct student *p;

	p = &s;

	printf("학번 : %d, 이름 : %s,  학점 : %f\n", s.number, s.name, s.grade);
	printf("학번 : %d, 이름 : %s,  학점 : %f\n", (*p).number, (*p).name, (*p).grade);
	printf("학번 : %d, 이름 : %s,  학점 : %f\n", p->number, p->name, p->grade);

	return 0;
}

// 출력 예시
// 학번 : 20240001, 이름 : 홍길동, 학점 : 4.300000
// 학번 : 20240001, 이름 : 홍길동, 학점 : 4.300000
// 학번 : 20240001, 이름 : 홍길동, 학점 : 4.300000 
```

#### 포인터를 멤버로 가지는 구조체 예제
```C
#include <stdio.h>

struct date {
	int month;
	int day;
	int year;
};

struct student {
	int number;
	char name[20];
	double grade;
	struct date *dob;
	// 위의 date 구조체를 멤버로 가지는 student 구조체
};

int main(void){
	struct date d = { 3, 20, 2000 };
	struct student s = { 20240001, "홍길동", 4.3 };

	s.dob = &d;

	printf("학번 : %d\n", s.number);
	printf("이름 : %s\n", s.name);
	printf("학점 : %f\n", s.grade);
	printf("생일 : %d년 %d월 %d일\n", s.dob->year, s.dob->month, s.dob->day);

	return 0;
}

// 출력 예시
// 학번 : 20240001
// 이름 : 홍길동
// 학점 : 4.300000
// 생일 : 2000년 3월 20일
```

## 6절. 구조체와 함수
#### 구조체와 함수
* 구조체를 함수의 인수로 전달하는 경우
  * 구조체의 복사본이 함수로 전달
  * 만약 구조체의 크기가 크면 그만큼의 시간과 메모리 소요

![structdef1](https://github.com/BangYunseo/TIL/blob/main/Language/C/Image/ch9/structdef1.PNG)

* 구조체의 포인터를 함수의 인수로 전달하는 경우
  * 시간과 메모리 절약 가능
  * 원본 훼손의 가능성 존재

![structdef2](https://github.com/BangYunseo/TIL/blob/main/Language/C/Image/ch9/structdef2.PNG)

#### 구조체를 반환하는 경우
* 복사본이 반환됨

![structreturn](https://github.com/BangYunseo/TIL/blob/main/C/Image/ch9/structreturn.PNG)
