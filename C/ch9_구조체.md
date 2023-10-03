##  Chapter 9. 구조체       

#### 1. 포인터(Pointer)

	- 주소를 가지고 있는 변수   
	 
![pointer](https://github.com/BangYunseo/TIL/blob/main/C/Image/ch8/pointer.PNG)

#### 1-1. 변수의 저장

	- 변수는 메모리에 저장된다.
 	- 메모리는 바이트 단위로 엑세스된다.
  	  -> 첫 번째 바이트의 주소는 0, 두 번째 바이트는 1, ...
	 
![pointer2](https://github.com/BangYunseo/TIL/blob/main/C/Image/ch8/pointer2.PNG)

#### 1-2. 변수의 메모리

	- 변수의 크기에 따라서 차지하는 메모리 공간이 달라진다.
	- char형 변수 : 1 바이트, int형 변수 : 4 바이트, ...
```C
int main(void){
	int i = 10;
	char c = 69;
	float f = 12.3;
}
```
![memory](https://github.com/BangYunseo/TIL/blob/main/C/Image/ch8/memory.PNG)

#### 2. 변수의 주소

 	- 변수의 주소를 계산하는 연산자 : &
  	- 변수 i의 주소 : &i
![Vadress](https://github.com/BangYunseo/TIL/blob/main/C/Image/ch8/Vadress.PNG)

#### 2-1. 주소의 개념

![adress](https://github.com/BangYunseo/TIL/blob/main/C/Image/ch8/adress.PNG)

#### 3. 주소 연산자 &

	- 함수 scanf()를 사용하면서 인자를 '&변수이름'으로 사용
 	- &(ampersand)가 피연산자인 변수의 메모리 주소를 반환하는 주소 연산자
  		- 함수 scanf()에서 입력값을 저장하는 변수의 주소값이 인자의 자료형
    		- 함수 scanf()에서 일반 변수 앞에는 주소 연산자 &를 사용

![adressOP](https://github.com/BangYunseo/TIL/blob/main/C/Image/ch8/adressOP.PNG)

  
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
(ppt 17페이지 부터)

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
(ppt 39 page 부터)

```C
```

#### 23-1. 선택 정렬 예제
```C
#include <stdio.h>
#define SIZE 10

int main(void)
{
	int list[SIZE] = {3, 2, 9, 7, 1, 4, 8, 0, 6, 5};
	int i, j, temp, least;

	for(i = 0; i < SIZE - 1; i++)
	// SIZE - 1을 하는 이유 : 배열의 index는 0 ~ 9까지이다.
	// 여기서 배열의 마지막 숫자는 가장 큰 숫자가 남을 것이기 때문에 정렬하지 않아도 된다.
	{
		least = i;	// 최솟값을 i 번째 원소로 설정
		for(j = i + 1; j < SIZE; j++)
		// i + 1 번째 원소부터 최솟값을 찾는 이유 : 이미 최솟값을 i 번째 원소로 설정해놨기 때문이다.
		{
			if(list[j] < list[least])
				least = j;
			// 현재 최솟값으로 저장되어 있는 i(least)보다 더 작은 정수를 발견하면 ?
			// 그 정수가 들어있는 index를 least에 저장한다.
		}
		// list[i]와 list[least]를 서로 복사한 후 교환하는 과정
		temp = list[i];		
		list[i] = list[least];
		list[least] = temp;
		// i 번째 원소와 least 위치의 원소를 교환하기 위해서는 여분의 변수인 temp가 필요
		// Why? : 값을 저장하지 않으면 복사하는 과정에서 하나의 값이 없어지기 때문이다.
	}
	for(i = 0; i < SIZE; i++)
		printf("%d", list[i]);
	printf("\n");
	return 0;
}
```
![sortingRE](https://github.com/BangYunseo/TIL/blob/main/C/Image/ch7/sortingRE.PNG) 


 #### 23-2. 선택 정렬 변수의 값을 교환할 때

 	- 옳지 않은 방법
		(1) score[i] = score[least];
		(2) score[least] = score[i];
		> 위와 같은 방법으로 진행하면 score[i]의 기존 값이 파괴되는 것을 볼 수 있다. 
	- 올바른 방법
		(1) temp = list[i];
		(2) list[i] = list[least];
 		(3) list[least] = temp;

![rightway](https://github.com/BangYunseo/TIL/blob/main/C/Image/ch7/rightway.PNG) 



#### 24. 순차 탐색
	- 순차 탐색은 배열의 원소를 순서대로 하나씩 꺼내서 탐색키와 비교하고 원하는 값을 찾아가는 방법
		> 순차 탐색은 일치하는 항목을 찾을 때까지 비교를 계속 진행함
		> 순차 탐색은 첫 번째 요소에서 성공할 수도 있고 마지막 요소까지 가야 찾을 수도 있음
		> 평균적으로는 절반 정도의 배열요소와 비교

![waysearch](https://github.com/BangYunseo/TIL/blob/main/C/Image/ch7/waysearch.PNG) 


#### 24-1. 순차 탐색 예시

```C
#include <stdio.h>
#define SIZE 10

int main(void)
{
	int key, i;
	int list[SIZE] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

	printf("탐색할 값을 입력해라 : ");
	scanf("%d", &key);

	for(i = 0; i < SIZE; i++)
	// list[i]와 key.를 비교하고, 만약 list[i] == key일 경우 인덱스를 출력
	{
		if(list[i] == key)
			printf("탐색 성공 인덱스 = %d\n", i);
	}
	printf("탐색 종료\n");
	return 0;
}


```

#### 25. 이진 탐색

	- 이진 탐색(binary search) : 정렬된 배열의 중앙에 위치한 원소와 비교 되풀이
		- 단, 탐색하려는 배열이 미리 정렬되어 있어야 한다. 

![binarysearch](https://github.com/BangYunseo/TIL/blob/main/C/Image/ch7/binarysearch.PNG) 



#### 25-1. 이진 탐색 예시

```C
// 찾아야 하는 값인 key값의 인덱스를 출력하는 예제
#include <stdio.h>
#define SIZE 16
int binary_search(int list[], int n, int key);

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
// 배열을 이진 탐색하는 함수
{
	int low, high, mid;
	low = 0;
	high = n - 1;
	// 배열의 인덱스 값의 최대를 high, 최소를 low로 설정

	while(low <= high)	// 이진 탐색이 가능할 때까지
	{	
		printf("[%d %d]\n", low, high);
		// 각각 low값과 high 값 출력
		mid = (low + high) / 2;
		// 중간 위치 계산
		if(key == list[mid])
			return mid
		// key값이 중간 값과 일치한다면 중간 값 반환
		else if(key > list[middle])
			low = mid + 1;
		// key값이 중간 값보다 크다면, 중간 값이었던 수보다 1을 더한 수를 최솟값으로 설정
		else
			high = mid - 1;
		// key값이 중간 값보다 작다면, 중간 값이었던 수보다 1을 뺀 수를 최댓값으로 설정
	}
	return -1;	// 이진 탐색이 안되는 배열인 경우 -1 반환
} 

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
