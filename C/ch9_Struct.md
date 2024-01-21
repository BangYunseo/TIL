#  Chapter 9. 구조체(미완)

> '쉽게 풀어쓴 C언어 Express - 천인국' 13장 학습 내용
>
> [소스코드](https://github.com/BangYunseo/Express-C/tree/main/ch9_%EA%B5%AC%EC%A1%B0%EC%B2%B4)
> 
> 1절. 구조체 기초
> 
> 2절. 선언
>
> 3절. 
>
> 4절. 
>
> 5절. 
>
> 6절. 
>
> 7절. 
>

## 1절. 구조체 기초
#### 자료형의 분류
* 자료형의 분류는 구조체와 비슷하다.
	 
![struct](https://github.com/BangYunseo/TIL/blob/main/C/Image/ch9/struct.PNG)

#### 구조체의 필요성
* 연관성 있는 서로 다른 개별적인 자료형의 변수들을 하나의 단위로 묶은 새로운 자료형
* 연관된 멤버로 구성되는 통합 자료형으로 대표적인 유도 자료형
  * 기존 자료형으로 새로이 만들어진 자료형을 유도 자료형(derived data types)이라고 한다.

![needstruct](https://github.com/BangYunseo/TIL/blob/main/C/Image/ch9/needstruct.PNG)

#### 구조체 개념

![struct2](https://github.com/BangYunseo/TIL/blob/main/C/Image/ch9/struct2.PNG)

#### 구조체와 배열

![arraystruct](https://github.com/BangYunseo/TIL/blob/main/C/Image/ch9/arraystruct.PNG)

#### 구조체 정의 개념
* 구조체를 자료형으로 사용하려면 먼저 구조체를 정의해야 한다.
  * 구조체를 만들 구조체 틀(template)을 정의한다.
![structtemplate](https://github.com/BangYunseo/TIL/blob/main/C/Image/ch9/structtemplate.PNG)

## 2절. 선언(여기부터 다시 작성 - 8페이지)
#### 구조체 선언

![arraystruct](https://github.com/BangYunseo/TIL/blob/main/C/Image/ch9/arraystruct.PNG)
  
#### 4. 변수의 주소

```C
int main(void){
	int i = 10;
	char c = 69;
	float f = 12.3;

	printf("i의 주소 : %u\n", &i);	// 변수 i의 주소 출력
	printf("c의 주소 : %u\n", &c);	// 변수 i의 주소 출력
	printf("f의 주소 : %u\n", &f);	// 변수 i의 주소 출력

	return 0;
}
/* 출력 예시
i의 주소 : 1245024
c의 주소 : 1245015
f의 주소 : 1245000  */
```
#### 4-1. 변수의 주소 출력 주의사항

	- 여러 개의 포인터 변수를 한 줄에 선언할 때는 주의해야 한다.
 	- 아래는 잘못된 선언 예제이다.

 ```C
int *p1, p2, p3;		// p2와 p3는 정수형 변수로 선언됨
```

	- 아래는 올바른 선언 예제이다.
  ```C
int *p1, *p2, *p3;		// p2와 p3는 올바른 포인터 변수로 선언됨
```

#### 5. 포인터의 선언

	- 포인터 변수 선언에서 자료형과 포인터 변수 이름 사이에 연산자 *(asterisk)를 삽입한다.
 	- ptrint, ptrshort, ptrchar, ptrdouble은 모두 포인터 변수이다.
  		- 간단히 포인터라고도 부른다.
 
![pointerV](https://github.com/BangYunseo/TIL/blob/main/C/Image/ch8/pointerV.PNG)


#### 6. 포인터와 변수의 연결

```C
int i;		// 정수형 변수 i 선언
int *p;		// 포인터 변수 p 선언
p = &i;		// 변수 i의 주소가 포인터 변수 p로 대입됨			
```

![pointerV2](https://github.com/BangYunseo/TIL/blob/main/C/Image/ch8/pointerV2.PNG)

#### 7. 다양한 포인터 선언

```C
char c = 'A';				// 문자형 변수 c
float f = 36.5;				// 실수형 변수 f
double d = 3.141592;			// 실수형 변수 d

char *pc = &c;				// 문자를 가리키는 포인터 pc
float *pf = &f;				// 실수를 가리키는 포인터 pf
double *pd = &d;			// 실수를 가리키는 포인터 pd
```

![pointerV3](https://github.com/BangYunseo/TIL/blob/main/C/Image/ch8/pointerV3.PNG)

#### 7-1. 예제 1. 포인터 선언하기

```C
#include <stdio.h>

int main(void)
{
	int i = 10;
	double f = 12.3;
	int *pi = NULL;		// NULL로 초기화를 하면 어느 메모리도 지정하지 않음

	double *pf = NULL;
	pi = &i;		// 포인터 변수 pi는 정수형 변수 i의 주소값을 저장 
	pf = &f;		// 포인터 변수 pf는 실수형 변수 f의 주소값을 저장 

	printf("%p %p \n", pi, &i);
	printf("%p %p \n", pf, &f);
	return 0;
}
/* 출력 예제
0000002AFF8FFB24 0000002AFF8FFB24 
0000002AFF8FFB48 0000002AFF8FFB48  */
```

#### 7-2. 포인터 참고사항

	- NULL은 stdio.h 헤더 파일에 정의된 포인터 상수로 0번을 의미한다.
 	- 0번은 일반적으로는 사용할 수 없다.
  	- CPU가 인터럽트를 위해 사용한다.
   	- 따라서 포인터 변수의 값이 0이라면 아무것도 가리키고 있지 않다.
```C
#define NULL ((void *)0)
```
![NULL](https://github.com/BangYunseo/TIL/blob/main/C/Image/ch8/NULL.PNG)

#### 8. 간접 참조 연산자

	- 간접 참조 연산자 * : 포인터가 가리키는 값을 가져오는 연산자
```C
int i = 10;
int *p;			// 포인터 변수 선언(자료형과 *p)
p = &i;			// p에는 i의 주소값인 4 저장
printf("%d", *p)	// 간접 참조(p변수의 주소에 가서 값을 알아오기)
// 실행 결과
// 10 
```
![ppointer](https://github.com/BangYunseo/TIL/blob/main/C/Image/ch8/ppointer.PNG)


#### 8-1. 간접 참조 연산자의 해석 

	- 간접 참조 연산자 : 지정된 위치에서 포인터의 타입에 따라 값을 읽어들인다.
```C
int *p = 8;			// 위치 8에서 정수를 읽는다.
char *pc = 8;			// 위치 8에서 문자를 읽는다.
double *pd = 8;			// 위치 8에서 실수를 읽는다.
```

![ppointer2](https://github.com/BangYunseo/TIL/blob/main/C/Image/ch8/ppointer2.PNG)

#### 9. & 연산자와 * 연산자

	- & 연산자 : 주소 연산자로, 변수의 주소를 반환한다.
 	- * 연산자 : 내용 연산자로, 포인터가 가리키는 곳의 내용을 반환한다.

![ppointer3](https://github.com/BangYunseo/TIL/blob/main/C/Image/ch8/ppointer3.PNG)

#### 10. 예제 2. 간접 참조 연산자 확인하기

```C
#include <stdio.h>

int main(void){
	int i = 3000;
	int *p = NULL;

	p = &i;

	printf("i = %d\n", i);			// 변수의 값 출력
	printf("&i = %u\n\n", &i);		// 변수의 주소 출력

	printf("p = %u\n", p);			// 포인터의 값 출력
	printf("*p = %d\n", *p);		// 포인터를 통한 간접 참조 값 출력

	// 변수 p에는 i의 주소값이 담겨져 있기 때문에 p를 출력하면 i의 주소값인 1245024가 출력됨
	// 포인터 p는 i의 주소값의 주소값, 즉 i값이 담겨져 있기 때문에 *p를 출력하면 i의 값인 3000이 출력됨
	return 0;
}
// 실행 결과
// i = 3000
// &i = 1245024
//
// p = 1245024
// *p = 3000
```

![pipointer](https://github.com/BangYunseo/TIL/blob/main/C/Image/ch8/pipointer.PNG)

#### 11. 예제 3. * 연산자 확인하기  

```C
#include <stdio.h>

int main(void){
	int x = 10, y = 20;
	int *p;

	p = &x;
	printf("p = %d\n", p);			// x의 주소값 출력
	printf("*p = %d\n\n", *p);		// x의 값 출력

	p = &y;
	printf("p = %d\n", p);			// y의 주소값 출력
	printf("*p = %d\n", *p);		// y의 값 출력

	// 변수 x와 y는 똑같은 경우의 수인데, 변수 p에 각각 x와 y의 주소값이 담겨있으므로 출력하면 주소값들이 출력됨
	// 주소값의 주소값은 그 변수의 값임. 따라서 변수 p의 주소값은 각각 x와 y의 값이 담겨있으므로 출력하면 변수의 값들이 출력됨

	return 0;
}
// 실행 결과
// p = 1245052
// *p = 10
// p = 1245048
// *p = 20
```
![starpointer](https://github.com/BangYunseo/TIL/blob/main/C/Image/ch8/starpointer.PNG)

#### 12. 예제 4. 주소 연산자와 내용 연산자

```C
#include <stdio.h>

int main(void){
	int i = 10;
	int *p;

	p = &i;				// 주소 연산자
	printf("i = %d\n", i);			

	*p = 20;			// 내용 연산자
	// 포인터를 통해서 변수의 값을 변경(p가 가리키는 위치에 20을 대입)	
	printf("i = %d\n", i);			

	// 변수 p는 i의 주소값을 담고 있음. 따라서 처음 printf 코드가 진행되어도 i의 원래 값에는 변화가 없는 것.
	// *p는 내용 연산자. 따라서 p의 내용값, 즉 *p를 20으로 변화시키면 i의 값이 바뀜. 그래서 20으로 바뀐 i의 값이 출력됨
	
	return 0;
}
// 실행 결과
// i = 10
// i = 20
```

![adpointer](https://github.com/BangYunseo/TIL/blob/main/C/Image/ch8/adpointer.PNG)

#### 13. 포인터 사용 시 주의점 1
	- 초기화가 안된 포인터를 사용하면 안된다.
```C
int main(void){
	int *p;		// 초기화가 되어있지 않은 포인터 p
	*p = 100;
	return 0;
}
```

![warningpointer1](https://github.com/BangYunseo/TIL/blob/main/C/Image/ch8/warningpointer1.PNG)

#### 13-1. 포인터 사용 시 주의점 2

	- 포인터가 아무것도 가리키고 있지 않은 경우에는 NULL로 초기화한다.
 	- NULL 포인터를 가지고 간접 참조하면 하드웨어로 감지한다.
```C
int *p = NULL;
```

![warningpointer2](https://github.com/BangYunseo/TIL/blob/main/C/Image/ch8/warningpointer2.PNG)

#### 13-2. 포인터 사용 시 주의점 3

	- 포인터의 타입과 변수의 타입은 일치해야 한다.
```C
#include <stdio.h>

int main(void){
	int i;
	double *pd;

	pd = &i;	// ERROR : double형 pointer에 int형 변수의 주소를 대입
	*pd = 36.5;
		
	return 0;
}
```
![warningpointer3](https://github.com/BangYunseo/TIL/blob/main/C/Image/ch8/warningpointer3.PNG)

#### 14. 포인터의 사용 이유

![whypointer](https://github.com/BangYunseo/TIL/blob/main/C/Image/ch8/whypointer.PNG)

	- 문자(char)는 'a' 처럼 글자가 하나만 있는 상태이다.
 	- 문자열(char *)은 "Hello"처럼 글자 여러 개가 계속 이어진 상태이다.
  	-> 즉, 문자는 1byte 크기의 char에 저장할 수 있지만 문자열은 크기가 1byte를 넘어가기 때문에 char에 저장할 수 없다.
   	-> 따라서 문자열은 변수에 직접 저장하지 않고 포인터를 이용해서 저장한다.

#### 15. 포인터 주소 연산

	- 가능한 연산 : 증가, 감소, 덧셈, 뺄셈
 	- 증가 연산의 경우 증가되는 값은 포인터가 가리키는 객체의 크기
  
|포인터 타입|++연산 후 증가되는 값|
|:----:|:----:|
|char|1|
|short|2|
|int|4|
|float|4|
|double|8|

#### 15-1. 포인터 연산

![pointerop](https://github.com/BangYunseo/TIL/blob/main/C/Image/ch8/pointerop.PNG)
![pointerop2](https://github.com/BangYunseo/TIL/blob/main/C/Image/ch8/pointerop2.PNG)


#### 15-2. 포인터 주소 연산

![pointerop3](https://github.com/BangYunseo/TIL/blob/main/C/Image/ch8/pointerop3.PNG)

#### 15-3. 포인터 증감 연산

![pointerop4](https://github.com/BangYunseo/TIL/blob/main/C/Image/ch8/pointerop4.PNG)

#### 16. 예제 5. 포인터의 증가 연산
```C
#include <stdio.h>

int main(void){
	char *pc;
	int *pi;
	double *pd;

	pc = (char *)10000;			// pc의 절대 주소에 10000을 대입
	pi = (int *)10000;			// pi의 절대 주소에 10000을 대입
	pd = (double *)10000;			// pd의 절대 주소에 10000을 대입

	printf("pc = %u, pc+1 = %u, pc+2 = %u\n", pc, pc+1, pc+2);
	printf("pi = %u, pi+1 = %u, pi+2 = %u\n", pi, pi+1, pi+2);
	printf("pd = %u, pd+1 = %u, pd+2 = %u\n", pd, pd+1, pd+2);

	return 0;
}
// 실행 결과
// pc = 10000, pc+1 = 100001, pc+2 = 10002
// pi = 10000, pi+1 = 100004, pi+2 = 10008
// pd = 10000, pd+1 = 100008, pd+2 = 10016
```

#### 17. 간접 참조 연산자와 증감 연산자
- *p++;
	- p가 가리키는 위치에서 값을 가져온 후에 p를 증가한다.
- (*p)++;
	- p가 가리키는 위치의 값을 증가한다.


|수식|의미|
|:--|:--|
|v = *p++|p가 가리키는 값을 v에 대입한 후에 p를 증가한다.|
|v = (*p)++|p가 가리키는 값을 v에 대입한 후에 가리키는 값을 중기힌다.|
|v = *++p|p를 증가시킨 후에 p가 가리키는 값을 v에 대입한다.|
|v = ++*p|p가 가리키는 값을 가져온 후에 그 값을 증가하여 v에 대입한다.|


#### 17-1. 간접 참조 연산자와 증감 연산자의 예제
```C
// 포인터의 증감 연산
#include <stdio.h>
int main(void){
	int i = 10;
	int *pi = &i;

	printf("i = %d,  pi = %p\n", i, pi);

	(*pi)++; 			// (10)++ -> pi가 가리키는 값을 증가한다.
	printf("i = %d,  pi = %p\n", i, pi);

	*pi++;				// pi가 가리키는 위치에서 값을 가져온 후 (11)에 pi를 증가한다. 
	printf("i = %d,  pi = %p\n", i, pi);

	return 0;
}
// 출력 예시
// i = 10, pi = 000000FFEBCFF974
// i = 11, pi = 000000FFEBCFF974
// i = 11, pi = 000000FFEBCFF978
```

#### 18. 포인터의 형변환

	- C언어에서는 꼭 필요한 경우에 명시적으로 포인터의 타입을 변경할 수 있다.
```C
double *pd = &f;
int *pi;

pi = (int*)pd;		// double형 포인터를 int형 포인터로 변환
```
 
#### 19. swap() 함수 #1 -  값에 의한 호출
```C
#include <stdio.h>
void swap(int x, int y);

int main(void){
	int a = 100, b = 200;
	printf("a = %d\tb=%d\n", a, b);

	swap(a, b);

	printf("a = %d\tb=%d\n", a, b);
	// x, y 값은 변화했지만 a, b 값은 변화하지 않았음
	return 0;
}
void swap(int x, int y) {
	int tmp;
	printf(“x=%d\ty=%d\n”,x, y);

	tmp = x;
	x = y;
	y = tmp;

	printf(“x=%d\ty=%d\n”,x, y);
}
// 출력 예제
// a=100	b=200
// x=100	y=200
// x=200	y=100
// a=100	b=200
```

#### 19-1. 값에 의한 호출 : Why error?

![whyerror](https://github.com/BangYunseo/TIL/blob/main/C/Image/ch8/whyerror.PNG) 

#### 20. swap() 함수 #2 -  참조에 의한 호출

```C
#include <stdio.h>
void swap(int *px, int *py);

int main(void){
	int a = 100, b = 200;
	printf("a = %d\tb=%d\n", a, b);

	swap(&a, &b);

	printf("a = %d\tb=%d\n", a, b);
	return 0;
}
void swap(int *px, int *py) {
	int tmp;

	tmp = *px;
	*px = *py;
	*py = tmp;

}
// 출력 예제
// a=100	b=200
// a=200	b=100
```

![callpointer](https://github.com/BangYunseo/TIL/blob/main/C/Image/ch8/callpointer.PNG) 

#### 21. scanf() 함수

- 변수에 값을 저장하기 위해 변수의 주소를 입력받는다.

![scanf](https://github.com/BangYunseo/TIL/blob/main/C/Image/ch8/scanf.PNG) 

#### 22. 참고 : 함수와 포인터
##### - 함수가 포인터를 통해 값을 변경할 수 없게 하려면?

	- 함수의 매개 변수를 선언할 때 앞에 const를 붙인다.
 	- const를 앞에 붙이면 포인터가 가리키는 내용이 변경 불가능한 상수라는 뜻이다.

```C
void sub(const int *p){
	*p = 0;		// Error occur
}
```
#### 23. 포인터와 배열

	- 배열과 포인터는 밀접한 관계이다.
 	- 배열의 이름이 포인터이다.
  	- 포인터는 배열처럼 사용 가능하다.

![pointerarray](https://github.com/BangYunseo/TIL/blob/main/C/Image/ch8/pointerarray.PNG) 

#### 23-1. 포인터와 배열의 관계

(ppt 45 page부터 다시 작성)

```C
// 포인터와 배열의 관계
#include <stdio.h>

int main(void)
{
	int key;
	int grade[SIZE] = {2, 6, 11, 13, 18, 20, 22, 27, 29, 30, 34, 38, 41, 42, 45, 47};
	printf("탐색할 값을 입력해라 : ");
	scanf("%d", &key);
	printf("탐색 결과 = %d\n", binary_search(grade, SIZE, key));

	return 0;
}
int binary_search(int list[], int n, int key)

```
#### 26. 2차원 배열

	- 데이터 자체가 2차원인 경우 사용하는 배열
 	- ex) 디지털 이미지, 보드 게임 등


![2tharray](https://github.com/BangYunseo/TIL/blob/main/C/Image/ch7/2tharray.PNG) 


```C
int s[10];		// 1차원
int s[3][10];		// 2차원
int s[5][3][10];	// 3차원
```

- 2차원 배열의 인덱스

![2tharrayindex](https://github.com/BangYunseo/TIL/blob/main/C/Image/ch7/2tharrayindex.PNG)   


#### 26-1. 2차원 배열 예제
```C
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ROWS 3
#define COLS 5

int main(void)
{
	int s[ROWS][COLS];
	int i, j;
	srand((unsigned)time(NULL));
	// 난수 생성기

	for (i = 0; i < ROWS; i++)
	// 배열의 행과 열에 랜덤 난수를 설정
	{
		for(j = 0;j < COLS; j++)
			s[i][j] = rand() % 100;
	}
	for (i = 0; i < ROWS; i++)
	// 배열의 행과 열에 설정된 랜덤 난수를 출력
	{
		for(j = 0;j < COLS; j++)
			printf("%02d", s[i][j]);
		printf("\n");
	}
	return 0;
}
```
```C
// 출력 결과 예시
61 10 53 60 54
90 45 73 00 90
80 82 93 45 67
```

#### 26-2. 2차원 배열 초기화

- 행과 열이 모두 주어진 2차원 배열 초기화

![2tharrayreset](https://github.com/BangYunseo/TIL/blob/main/C/Image/ch7/2tharrayreset.PNG)

- 행이 주어지지 않고 열만 주어진 2차원 배열 초기화

![2tharrayreset2](https://github.com/BangYunseo/TIL/blob/main/C/Image/ch7/2tharrayreset2.PNG)

- 행이 주어지지 않고 열만 주어진 2차원 배열 초기화 - 2

![2tharrayreset3](https://github.com/BangYunseo/TIL/blob/main/C/Image/ch7/2tharrayreset3.PNG)



#### 27. 행렬 예제

- 다차원 배열을 이용한 행렬의 표현 예제
```C
#include <stdio.h>
#define ROWS 3
#define COLS 3

int main(void)
{
	int A[ROWS][COLS] = { {2, 3, 0},
                              {8, 9, 1},
                              {7, 0, 5} };
	int B[ROWS][COLS] = { {1, 0, 0},
                              {1, 0, 0},
                              {1, 0, 0} };
	int C[ROWS][COLS];
	int r, c;
	for(r = 0; r < ROWS; r++)
	// 두 개의 행렬을 더한 값을 행렬 C에 저장
	{
		for(c = 0; c < COLS; c++)
			C[r][c] = A[r][c] + B[r][c];
	}
	for(r = 0; r < ROWS; r++)
	// 행렬 C에 저장된 값을 출력
	{
		for(c = 0; c < COLS; c++)
			printf("%d", C[r][c]);
		printf("\n");
	}
	return 0;
}
```

#### 27-1. 다차원 배열 주의사항

![ntharray](https://github.com/BangYunseo/TIL/blob/main/C/Image/ch7/ntharray.PNG)
