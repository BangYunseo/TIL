##  Chapter 8. 포인터       

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

#### 13. 포인터 사용 시 주의점
	- 초기화가 안된 포인터를 사용하면 안된다.

 
 (강의자료 24page 부터)
 
```C

```

![adpointer](https://github.com/BangYunseo/TIL/blob/main/C/Image/ch8/adpointer.PNG)

#### 16. 배열의 비교

```C
// 아래와 같은 명령어는 error를 발생시키는 명령어이다.
#include <stdio.h>
#define SIZE 5

int main(void)
{
	int i;
	int a[SIZE] = {1, 2, 3, 4, 5};
	int b[SIZE] = {1, 2, 3, 4, 5};
	
	if (a == b)
	// 배열을 비교하는 것이 아님
		printf("error");
	else
		printf("error);
	
	return 0;
}
```

```C
// 아래의 명령어가 올바른 배열의 복사 방법이다.
#include <stdio.h>
#define SIZE 5

int main(void)
{
	int i;
	int a[SIZE] = {1, 2, 3, 4, 5};
	int b[SIZE] = {1, 2, 3, 4, 5};
	
	for (i = 0; i < SIZE; i++)
	{
		if(a[i] != b[i])
			printf("a[%d]와 b[%d]는 같지 않다.\n", i);
		printf("a[%d]와 b[%d]는 같다.\n", i);
	}
	return 0;
}
// 배열의 원소는 반복문을 통해 하나씩 복사해야 한다.
```

#### 17. lab #1. 주사위 던지기 예제

```C
// Lab1 : 주사위 던지기
#include <stdio.h>
#include <stdlib.h>
#define DICE_NUM 6		// DICE 면의 수를 6으로 정의한다.

int main(void)
{
	int freq[DICE_NUM] = { 0 };	// 주사위의 면의 수만큼 배열 freq를 생성한다.
	int i;						// for문에 사용할 변수 i를 생성한다.

	for (i = 0; i < 10000; i++)		// 주사위를 10000번 던진다.
	{
		++freq[rand() % 6];		// 배열의 무작위 면이 나오는 횟수를 더한다.
	}

	printf("=========================\n");
	printf("숫자\t빈도\n");						// 숫자와 빈도를 출력한다.
	printf("=========================\n");

	for (i = 0; i < DICE_NUM; i++)		// 주사위 면의 숫자만큼 출력을 반복한다.
	{
		printf("%d\t%d\n", i + 1, freq[i]);
		// 주사위 면 1의 값이 나온 횟수부터 차례대로 입력한다.
		// 여기서 i는 0부터 시작하므로 i + 1을 해서 1 ~ 6까지의 수를 입력한다.
	}
	return 0;
}
```

#### 18. lab #2. 극장 예약 시스템 예제

```C
// Lab2 : 극장 예약 시스템
#include <stdio.h>
#define SEATS 10

int main(void)
{
	char answer1;	// 좌석 예약 여부를 입력받을 변수 answer1을 생성한다.
	int answer2, i;	// 어느 좌석을 선택할지 입력받을 변수 answer2와 for문에 이용할 변수 i를 생성한다.
	int movie_seat[10] = { 0 };	// 좌석 10개를 저장할 배열을 생성하고 0으로 초기화한다.

	while (1)		// 무한반복문
	{
		printf("좌석을 예약하시겠습니까? (y 또는 n) ");	// 좌석을 예약할 것인지 출력한다.
		scanf_s(" %c", &answer1, 4);	// 대답을 입력받고 변수 answer1에 저장한다.

		if (answer1 == 'y')	// 만약 대답이 y라면 좌석을 예약한다.
		{
			printf("-----------------------\n");
			printf("1 2 3 4 5 6 7 8 9 10\n");			// 좌석 수를 출력한다.
			printf("-----------------------\n");
			for (i = 0; i < SEATS; i++)		// 좌석의 수만큼 반복한다.
			{
				printf("%d ", movie_seat[i]);
				// 앞에서 배열을 초기화했으므로 0 또는 1이 출력된다.
				// 1이 출력되면 예약된 좌석, 0이 출력되면 예약하지 않은 좌석이다.
			}
			printf("\n");	// 줄바꿈

			printf("몇 번째 좌석을 예약하시겠습니까? ");		// 어느 좌석을 예약할 것인지 출력한다.
			scanf_s("%d", &answer2);		// 입력받은 좌석의 번호를 변수 answer2에 저장한다.

			if (answer2 <= 0 || answer2 > SEATS)	// 만약 answer2의 값이 1 ~ 10 사이의 값이 아니라면
			{
				printf("1부터 10 사이의 숫자를 입력하세요.\n");	// 변수를 다시 입력받는다.
				continue;	// 다시 반복문을 실행
			}
			if (movie_seat[answer2 - 1] == 0)	// 만약 변수 answer2 - 1의 배열값이 0이라면
			{
				movie_seat[answer2 - 1] = 1;	// 그 자리에 1을 저장한다.
				printf("예약되었습니다.\n");	// 예약됐다고 출력한다.
			}
			else       // 만약 변수 answer2 - 1 의 배열값이 1이라면
			{
				printf("이미 예약된 자리입니다.\n");	// 이미 예약된 자리라고 출력한다.
			}
		}
		if (answer1 == 'n')		// 만약 대답이 n이라면 그대로 반복문을 종료한다.
			return 0;
	}
	return 0;
}

```

#### 19. lab #3. 최솟값 탐색 예제

```C
// Lab3 : 최솟값 찾기
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 10		// 배열의 크기를 10으로 설정한다.

int main(void)
{
	srand((unsigned)time(NULL));	// 난수를 발생시킨다.

	int prices[SIZE] = { 0 };	// 값을 저장할 배열을 SIZE 크기만큼 생성하고, 0으로 초기화한다.
	int i, minimum;		// 배열에 사용할 변수 i와 최솟값을 저장하면서 갱신할 변수를 생성한다.

	printf("---------------------------\n");
	printf("1 2 3 4 5 6 7 8 9 10\n");				// 10개의 숫자를 출력할 메뉴 출력
	printf("---------------------------\n");

	for (i = 0; i < SIZE; i++)	// 배열의 크기만큼 반복한다.
	{
		prices[i] = (rand() % 100) + 1;		// 배열의 각 값에 1 ~ 100까지의 수를 저장한다.
		printf("%d ", prices[i]);			// 각 배열을 출력한다.
	}
	printf("\n");		// 줄바꿈

	minimum = prices[0];	// 일단 최솟값을 첫 번째 값으로 설정한다. for문 안에 들어갈 필요 X
	for (i = 0; i < SIZE; i++)	// 배열의 크기만큼 반복한다.
	{
		if (prices[i] < minimum)	// 만약 prices[i]의 값이 현재 최솟값보다 작다면
			minimum = prices[i];	// 현재 최솟값을 prices[i]로 변경한다.
	}

	printf("최소값은 %d 입니다.\n", minimum);	// 최솟값을 출력한다.

	return 0;
}
```

#### 20. 배열과 함수

	- 배열의 경우에는 사본이 아닌 원본이 전달된다.    

![orignalarray](https://github.com/BangYunseo/TIL/blob/main/C/Image/ch7/orignalarray.PNG) 

	- 함수 : 매개변수와 인수     
 		1) 매개변수 : 함수 바깥에서 전달된 값이 저장되는 변수   
		2) 인수 : 함수를 호출할 때 전달하는 값이나 변수   
```C
#include <stdio.h>

int plus(int a, int b);	// 함수의 원형 출력

int main(void){
	int point1;	// 과목 점수 1
	int point2;	// 과목 점수 2

	scanf("%d %d", &point1, &point2);

	if (plus(point1, point2) >= 150)
	// plus는 함수, point1과 point2는 인수
		printf("합격\n");
	else
		printf("불합격\n");
	return 0;
}
int plus(int a, int b){
	// 함수 plus에 위치한 int a, int b는 매개변수
	int result;

	result = a + b;

	return result;	// 과목 점수의 합을 반환
}
```

#### 20-1. 배열이 함수의 인수인 경우
```C
// 예시 코드
#include <stdio.h>
#define SIZE 7

void modify_array(int a[], int size);		// 함수의 원형 출력
void print_array(int a[], int size);		// 함수의 원형 출력

int main(void){
	int list[SIZE] = {1, 2, 3, 4, 5, 6, 7};	// 배열 초기화

	print_array(list, SIZE);	// 배열 출력 함수 실행
	modify_array(list, SIZE);	// 배열의 값들을 1씩 더하는 함수 실행
	print_array(list, SIZE);	// 배열 출력 함수 실행
	// 1씩 값이 더해진 배열이 출력됨

	return 0;
}
void modify_array(int a[], int size){ 	// 1씩 더하는 함수
	int i;
	for (i = 0; i < size; i++)
		++a[i];
}
void print_array(int a[], int size){	// 배열을 출력하는 함수
	int i;
	for (i = 0; i < size; i++)
		printf("%3d ", a[i]);
	printf("\n");
}
//   예시 출력
// 1 2 3 4 5 6 7
// 2 3 4 5 6 7 8
```
#### 21. 원본 배열의 변경 금지하기
```C
void print_array(const int a[], int size)
{		// const를 사용하면 함수 안에서 a[]의 값을 변경할 수 없게 된다.
	...
	a[0] = 100;
	// 위를 실행하면 컴파일 오류가 발생한다.
}
```

#### 22. 정렬

	- 정렬은 물건을 크기 순으로 오름차순이나 내림차순으로 나열하는 것을 의미한다.    
 	- 컴퓨터 프로그래밍을 배울 때 가장 기본적이며 중요한 알고리즘 중 하나이다. 
  	- 정렬은 자료 탐색에 있어서 필수적이다.
 
 #### 23. 선택 정렬

 	- 선택 정렬(selection sort) : 정렬이 안된 숫자들 중 최솟값을 선택하여 배열의 첫 번째 요소와 교환하는 행동  
		- 오른쪽 배열에서 가장 작은 숫자를 선택하여 왼쪽 배열로 이동하는 작업을 되풀이 한다.      
		- 선택 정렬은 오른쪽 배열이 공백상태가 될 때까지 이 과정을 되풀이하는 정렬기법이다.      
      

|왼쪽 배열|오른쪽 배열|설명|
|:---|:---|:---:|
|()|(5, 3, 8, 1, 2, 7)|초기상태|
|(1)|(5, 3, 8, 2, 7)|1 선택|
|(1, 2)|(5, 3, 8, 7)|2 선택|
|(1, 2, 3)|(5, 8, 7)|3 선택|
|(1, 2, 3, 5)|(8, 7)|4 선택|
|(1, 2, 3, 5, 7)|(8)|5 선택|
|(1, 2, 3, 5, 7, 8)|()|6 선택|

![sorting1](https://github.com/BangYunseo/TIL/blob/main/C/Image/ch7/sorting1.PNG) 

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
