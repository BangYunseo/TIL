#  Chapter 8. 포인터       
> '쉽게 풀어쓴 C언어 Express - 천인국' 11장 학습 내용
>
> [소스코드](https://github.com/BangYunseo/Express-C/tree/main/ch8_%ED%8F%AC%EC%9D%B8%ED%84%B0)
> 
> 1절. 포인터 기초
> 
> 2절. 주소
>
> 3절. 포인터
>
> 4절. 연산자
>
> 5절. swap()
>
> 6절. scanf()
>
> 7절. 매개 변수
>

## 1절. 포인터 기초
#### 포인터(Pointer)

* 주소를 가지고 있는 변수   
![pointer](https://github.com/BangYunseo/TIL/blob/main/C/Image/ch8/pointer.PNG)

#### 변수의 저장
* 변수는 메모리에 저장된다.
* 메모리는 바이트 단위로 엑세스된다.
  * 첫 번째 바이트의 주소는 0, 두 번째 바이트는 1, ...
	 
![pointer2](https://github.com/BangYunseo/TIL/blob/main/C/Image/ch8/pointer2.PNG)

#### 변수의 메모리
* 변수의 크기에 따라서 차지하는 메모리 공간이 달라진다.
* char형 변수 : 1 바이트, int형 변수 : 4 바이트, ...
```C
int main(void){
	int i = 10;
	char c = 69;
	float f = 12.3;
}
```
![memory](https://github.com/BangYunseo/TIL/blob/main/C/Image/ch8/memory.PNG)


## 2절. 주소
#### 주소의 개념

![adress](https://github.com/BangYunseo/TIL/blob/main/C/Image/ch8/adress.PNG)

#### 주소 연산자 &
* 함수 scanf()를 사용하면서 인자를 '&변수이름'으로 사용
* &(ampersand)가 피연산자인 변수의 메모리 주소를 반환하는 주소 연산자
  * 함수 scanf()에서 입력값을 저장하는 변수의 주소값이 인자의 자료형
  * 함수 scanf()에서 일반 변수 앞에는 주소 연산자 &를 사용

![adressOP](https://github.com/BangYunseo/TIL/blob/main/C/Image/ch8/adressOP.PNG)

  
#### 변수의 주소
* 변수의 주소를 계산하는 연산자 : &
* 변수 i의 주소 : &i

![Vadress](https://github.com/BangYunseo/TIL/blob/main/C/Image/ch8/Vadress.PNG)
 
#### 변수의 주소

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

#### 변수의 주소 출력 주의사항
* 여러 개의 포인터 변수를 한 줄에 선언할 때는 주의해야 한다.
* 아래는 잘못된 선언 예제이다.

 ```C
int *p1, p2, p3;		// p2와 p3는 정수형 변수로 선언
```

* 아래는 올바른 선언 예제이다.
```C
int *p1, *p2, *p3;		// p2와 p3는 올바른 포인터 변수로 선언
```

## 3절. 포인터
#### 포인터의 선언
* 포인터 변수 선언에서 자료형과 포인터 변수 이름 사이에 연산자 *(asterisk)를 삽입한다.
* ptrint, ptrshort, ptrchar, ptrdouble은 모두 포인터 변수이다.
* 간단히 포인터라고도 부른다.
 
![pointerV](https://github.com/BangYunseo/TIL/blob/main/C/Image/ch8/pointerV.PNG)


#### 포인터와 변수의 연결

```C
int i;		// 정수형 변수 i 선언
int *p;		// 포인터 변수 p 선언
p = &i;		// 변수 i의 주소가 포인터 변수 p로 대입됨			
```

![pointerV2](https://github.com/BangYunseo/TIL/blob/main/C/Image/ch8/pointerV2.PNG)

#### 다양한 포인터 선언

```C
char c = 'A';				// 문자형 변수 c
float f = 36.5;				// 실수형 변수 f
double d = 3.141592;			// 실수형 변수 d

char *pc = &c;				// 문자를 가리키는 포인터 pc
float *pf = &f;				// 실수를 가리키는 포인터 pf
double *pd = &d;			// 실수를 가리키는 포인터 pd
```

![pointerV3](https://github.com/BangYunseo/TIL/blob/main/C/Image/ch8/pointerV3.PNG)

#### 포인터 선언 예제

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

#### 포인터 참고사항
* NULL은 stdio.h 헤더 파일에 정의된 포인터 상수로 0번을 의미한다.
* 0번은 일반적으로는 사용할 수 없다.
* CPU가 인터럽트를 위해 사용한다.
* 따라서 포인터 변수의 값이 0이라면 아무것도 가리키고 있지 않다.
```C
#define NULL ((void *)0)
```
![NULL](https://github.com/BangYunseo/TIL/blob/main/C/Image/ch8/NULL.PNG)


#### 포인터 사용 시 주의점 1
* 초기화가 안된 포인터를 사용하면 안된다.
```C
int main(void){
	int *p;		// 초기화가 되어있지 않은 포인터 p
	*p = 100;
	return 0;
}
```

![warningpointer1](https://github.com/BangYunseo/TIL/blob/main/C/Image/ch8/warningpointer1.PNG)

#### 포인터 사용 시 주의점 2
* 포인터가 아무것도 가리키고 있지 않은 경우에는 NULL로 초기화한다.
* NULL 포인터를 가지고 간접 참조하면 하드웨어로 감지한다.
```C
int *p = NULL;
```

![warningpointer2](https://github.com/BangYunseo/TIL/blob/main/C/Image/ch8/warningpointer2.PNG)

#### 포인터 사용 시 주의점 3
* 포인터의 타입과 변수의 타입은 일치해야 한다.
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

#### 포인터의 사용 이유

![whypointer](https://github.com/BangYunseo/TIL/blob/main/C/Image/ch8/whypointer.PNG)

* 문자(char)는 'a' 처럼 글자가 하나만 있는 상태이다.
* 문자열(char *)은 "Hello"처럼 글자 여러 개가 계속 이어진 상태이다.
  * 즉, 문자는 1byte 크기의 char에 저장할 수 있지만 문자열은 크기가 1byte를 넘어가기 때문에 char에 저장할 수 없다.
  * 따라서 문자열은 변수에 직접 저장하지 않고 포인터를 이용해서 저장한다.

#### 포인터 주소 연산
* 가능한 연산 : 증가, 감소, 덧셈, 뺄셈
* 증가 연산의 경우 증가되는 값은 포인터가 가리키는 객체의 크기
  
|포인터 타입|++연산 후 증가되는 값|
|:----:|:----:|
|char|1|
|short|2|
|int|4|
|float|4|
|double|8|

#### 포인터 연산

![pointerop](https://github.com/BangYunseo/TIL/blob/main/C/Image/ch8/pointerop.PNG)
![pointerop2](https://github.com/BangYunseo/TIL/blob/main/C/Image/ch8/pointerop2.PNG)


#### 포인터 주소 연산

![pointerop3](https://github.com/BangYunseo/TIL/blob/main/C/Image/ch8/pointerop3.PNG)

#### 포인터 증감 연산

![pointerop4](https://github.com/BangYunseo/TIL/blob/main/C/Image/ch8/pointerop4.PNG)

#### 포인터의 증가 연산 예제
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

#### 포인터의 형변환
* C언어에서는 꼭 필요한 경우에 명시적으로 포인터의 타입을 변경할 수 있다.
```C
double *pd = &f;
int *pi;

pi = (int*)pd;		// double형 포인터를 int형 포인터로 변환
```

#### 포인터와 함수
* 함수가 포인터를 통해 값을 변경할 수 없게 하려면?
  * 함수의 매개 변수를 선언할 때 앞에 const를 붙인다.
  * const를 앞에 붙이면 포인터가 가리키는 내용이 변경 불가능한 상수라는 뜻이다.

```C
void sub(const int *p){
	*p = 0;		// Error occur
}
```
#### 포인터와 배열
* 배열과 포인터는 밀접한 관계이다.
* 배열의 이름이 포인터이다.
* 포인터는 배열처럼 사용 가능하다.

![pointerarray](https://github.com/BangYunseo/TIL/blob/main/C/Image/ch8/pointerarray.PNG) 

* 인덱스 표기법을 포인터에 사용할 수 있다.
  * 인덱스 표기 = 배열에서 사용
  * a + i == &a[i]
  * *(a + i) == a[i]

![pointerarray2](https://github.com/BangYunseo/TIL/blob/main/C/Image/ch8/pointerarray2.PNG) 

#### 포인터를 배열처럼 사용하는 예제
```C
#include <stdio.h>

int main(void)
{
	int a[] = {10, 20, 30, 40, 50};
	int *p;

	p = a;
	printf("&a[0] = %d\ta[1] = %d\ta[2] = %d\n", a[0], a[1], a[2]);
	printf("&p[0] = %d\tp[1] = %d\tp[2] = %d\n\n", p[0], p[1], p[2]);

	p[0] = 60;
	p[1] = 70;
	p[2] = 80;

	printf("&a[0] = %d\ta[1] = %d\ta[2] = %d\n", a[0], a[1], a[2]);
	printf("&p[0] = %d\tp[1] = %d\tp[2] = %d\n\n", p[0], p[1], p[2]);
	return 0;
}
// 출력 예시
// a[0] = 10	a[1] = 20	a[2] = 30
// p[0] = 10	p[1] = 20	p[2] = 30
// 
// a[0] = 60	a[1] = 70	a[2] = 80
// p[0] = 60	p[1] = 70	p[2] = 80
```

* 사진으로 보기

![pointertoarray](https://github.com/BangYunseo/TIL/blob/main/C/Image/ch8/pointertoarray.PNG) 

#### 포인터를 배열의 이름으로 사용

![pointertoname](https://github.com/BangYunseo/TIL/blob/main/C/Image/ch8/pointertoname.PNG) 

#### 포인터와 배열의 관계 예제
```C
// 포인터와 배열의 관계
#include <stdio.h>

int main(void)
{
	int a[] = {10, 20, 30, 40, 50};

	printf("&a[0] = %u\n", &a[0]);
	printf("&a[1] = %u\n", &a[1]);
	printf("&a[2] = %u\n", &a[2]);

	printf("a = %u\n", a);
	// 배열 이름을 부호 없는 정수값으로 출력
	// 첫 번째 요소(index = 0)의 주소값과 동일
	return 0;
}
// 출력 예시
// &a[0] = 1245008
// &a[1] = 1245012
// &a[2] = 1245016
// a = 1245008
```

#### 포인터와 배열의 관계 예제 2
```C
// 포인터와 배열의 관계 2
#include <stdio.h>

int main(void)
{
	int a[] = {10, 20, 30, 40, 50};

	printf("a = %u\n", a);

	printf("a + 1 = %u\n", a + 1);

	printf("*a = %d\n", *a);

	printf("*(a + 1) = %d\n", *(a + 1));

	return 0;
}
// 출력 예시
// a = 1245008
// a + 1 = 1245012
// *a = 10
// *(a + 1) = 20
```

## 4절. 연산자
#### 간접 참조 연산자
* 간접 참조 연산자 * : 포인터가 가리키는 값을 가져오는 연산자

```C
int i = 10;
int *p;			// 포인터 변수 선언(자료형과 *p)
p = &i;			// p에는 i의 주소값인 4 저장
printf("%d", *p)	// 간접 참조(p변수의 주소에 가서 값을 알아오기)

// 실행 결과
// 10 
```
![ppointer](https://github.com/BangYunseo/TIL/blob/main/C/Image/ch8/ppointer.PNG)


#### 간접 참조 연산자의 해석 
* 간접 참조 연산자 : 지정된 위치에서 포인터의 타입에 따라 값을 읽음
```C
int *p = 8;			// 위치 8에서 정수를 읽는다.
char *pc = 8;			// 위치 8에서 문자를 읽는다.
double *pd = 8;			// 위치 8에서 실수를 읽는다.
```

![ppointer2](https://github.com/BangYunseo/TIL/blob/main/C/Image/ch8/ppointer2.PNG)

#### & 연산자와 * 연산자
* & 연산자 : 주소 연산자로, 변수의 주소를 반환한다.
* * 연산자 : 내용 연산자로, 포인터가 가리키는 곳의 내용을 반환한다.

![ppointer3](https://github.com/BangYunseo/TIL/blob/main/C/Image/ch8/ppointer3.PNG)

#### 간접 참조 연산자 확인 예제

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

#### * 연산자 확인 예제 

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

#### 주소 연산자와 내용 연산자

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

#### 간접 참조 연산자와 증감 연산자
* *p++;
  * p가 가리키는 위치에서 값을 가져온 후에 p를 증가한다.
* (*p)++;
  * p가 가리키는 위치의 값을 증가한다.


|수식|의미|
|:--|:--|
|v = *p++|p가 가리키는 값을 v에 대입한 후에 p를 증가한다.|
|v = (*p)++|p가 가리키는 값을 v에 대입한 후에 가리키는 값을 중기힌다.|
|v = *++p|p를 증가시킨 후에 p가 가리키는 값을 v에 대입한다.|
|v = ++*p|p가 가리키는 값을 가져온 후에 그 값을 증가하여 v에 대입한다.|


#### 간접 참조 연산자와 증감 연산자의 예제
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

## 5절. swap()
#### swap() 함수 1 -  값에 의한 호출
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

#### 값에 의한 호출 : Why error?

![whyerror](https://github.com/BangYunseo/TIL/blob/main/C/Image/ch8/whyerror.PNG) 

#### swap() 함수 2 -  참조에 의한 호출

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

## 6절. scanf()
#### scanf() 함수
* 변수에 값을 저장하기 위해 변수의 주소를 입력받는다.

![scanf](https://github.com/BangYunseo/TIL/blob/main/C/Image/ch8/scanf.PNG) 

## 7절. 매개 변수
#### 배열 매개 변수
* 일반 매개 변수와 배열 매개 변수
![argument](https://github.com/BangYunseo/TIL/blob/main/C/Image/ch8/argument.PNG)

* why?
  * 배열을 함수로 복사하려면 많은 시간이 소모되므로 배열은 주소만을 전달
* 배열 매개 변수는 포인터로 생각할 수 있다.
![arrayarg](https://github.com/BangYunseo/TIL/blob/main/C/Image/ch8/arrayarg.PNG)

* 배열 a의 주소를 가리키고 있기 때문에 배열의 이름은 포인터이다.
* 함수를 호출할 때 배열을 전달하면 자동으로 배열의 주소가 전달된다.
  * 배열의 이름은 배열을 가리키는 포인터와 동일하다.
* sub() 함수를 호출할 때 배열의 이름 a를 전달한다.
* sub() 함수의 매개 변수 b는 배열을 가리키는 포인터처럼 동작한다.
  * b를 통하여 배열 원소에 접근하면 배열 a의 원소들이 접근된다.

#### 포인터를 통한 배열과 매개 변수의 관계 예제
```C
#include <stdio.h>

void sub(int b[], int n);

int main(void){
	int a[3] = {1, 2, 3};

	printf("%d %d %d\n", a[0], a[1], a[2]);
	sub(a, 3);
	// 배열 a를 sub() 함수로 전달
	// 배열의 이름 == 배열의 주소
	// 따라서 배열의 주소가 전달

	printf("%d %d %d\n", a[0], a[1], a[2]);

	return 0;
}
void sub(int b[], int n){
	// 매개 변수 b는 전달된 배열을 가리키는 포인터
	b[0] = 4;
	b[1] = 5;
	b[2] = 6;
	// b[]를 통해 원본 배열 a[]가 변경
}
	
```

#### 동일한 포인터 매개 변수 방법

![sametwoway](https://github.com/BangYunseo/TIL/blob/main/C/Image/ch8/sametwoway.PNG)

#### 포인터를 사용한 방법의 장점
* 포인터가 인덱스 표기법보다 빠르다.
  * Why?
    * 인덱스를 주소로 변환할 필요가 없기 때문이다.

![advantage](https://github.com/BangYunseo/TIL/blob/main/C/Image/ch8/advantage.PNG)

* 컴파일러 최적화를 하면 성능은 비슷해진다.
