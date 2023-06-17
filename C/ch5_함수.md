##  Chapter 5. 함수       

#### 1. 함수(function)의 개념

	- 입력을 받아 특정한 작업을 통해 결과를 반환하는 코드     
![functionN](https://github.com/BangYunseo/TIL/blob/main/C/Image/functionN.PNG)

#### 2. 함수가 필요한 이유

	1. 코드의 중복을 피할 수 있기 때문이다.     
 	2. 한 번 작성된 함수를 여러 번 재사용할 수 있기 때문이다.     
  	3. 함수를 사용하면 전체 프로그램을 모듈로 나눌 수 있어 개발 과정이 쉬워지고 보다 체계적이게 되면서 유지 보수가 쉬워지기 때문이다.     

#### 3. 함수의 특징

	1. 함수는 특정한 작업을 수행하기 위한 명령어들의 모음이다.    
 	2. 함수는 서로 구별되는 이름을 가지고 있다.    
  	3. 함수는 특정한 작업을 수행한다.     
   	4. 함수는 입력을 받을 수 있고 결과를 반환할 수 있다.   
![functionN1](https://github.com/BangYunseo/TIL/blob/main/C/Image/functionN1.PNG)

#### 4. 함수의 종류

![FunctionType](https://github.com/BangYunseo/TIL/blob/main/C/Image/FuntionType.PNG)   

#### 5. 함수의 정의

![defineFunction](https://github.com/BangYunseo/TIL/blob/main/C/Image/defineFunction.PNG)   

#### 5-1. +함수의 정의

	- 반환형   
		1. 반환형은 함수가 처리를 종류한 후에 호출한 곳으로 반환하는 데이터의 유형을 말한다.   
	- 함수 이름   
		1. 함수 이름은 식별자에 대한 규칙만 따른다면 어떤 이름이라도 가능하다.   
		2. 함수의 기능을 암시하는 (동사+명사)를 사용하면 좋다.   

![functionName](https://github.com/BangYunseo/TIL/blob/main/C/Image/functionName.PNG)

	- 함수의 길이     
  		1. C에서는 함수의 길이에 아무런 제한을 두지 않는다.   
		2. 이것은 하나의 함수 안에 많은 문장들을 넣을 수 있음을 의미한다.   
		3. 그러나 함수의 길이가 지나치게 길면 좋지 않다.   
  		4. 기본적으로 하나의 함수는 하나의 작업만을 수행한다.   
  		5. 만약 함수의 길이가 지나치게 길다면 하나 이상의 작업을 하고 있다고 봐야한다.   
  		6. 함수를 분할하는 것은 좋은 방법이다.   
  		7. 보편적으로 30행을 넘지 않도록 하는 것이 좋다.
  
#### 6. 함수 호출

	- 함수 호출(function call)
 		1. 함수 호출이란 menu()와 같이 함수의 이름을 써주는 것이다.   
		2. 함수 안의 문장들은 호출되기 전까지는 전혀 실행되지 않는다.   
		3. 함수를 호출하게 되면 현재 실행하고 있는 코드는 잠시 중단된다.   
		4. 호출된 함수로 이동해서 함수 몸체 안의 문장들이 순차적으로 실행된다.   
		5. 호출된 함수의 실행이 끝나면 호출한 위치로 되돌아가서 잠시 중단됐던 코드를 실행한다.   

  ![functionCall](https://github.com/BangYunseo/TIL/blob/main/C/Image/functionCall.PNG)

#### 6-1. 함수 호출 예제

```C
// print_start() 함수 2번 호출하기
#include <stdio.h>
void print_stars();	//함수의 원형 출력

int main(void)
{
	print_stars();  
	// print_stars() 함수 호출
	printf("\nHello World!\n");  
	print_stars();  
	// print_stars() 함수 호출
	printf("\n);  
	return 0;
}

void print_stars()	// 입력할 함수	
{
	for (int i = 0; i < 30; i++)	// i가 30이 될 때까지 반복
		printf("*");		// 별 찍기
}
```

#### 7. 매개 변수와 반환값

여기부터 하기




![returnfunction](https://github.com/BangYunseo/TIL/blob/main/C/Image/do-while.PNG)
     
#### 8-1. do - while 문 예제

```C
// 숫자 추측 예제
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	srand((unsigned)time(NULL));				// 난수 발생기 시드 설정
	int answer = rand() % 100;				// 정답을 1~100까지의 난수로 설정한다.
	int guess;						// 추측할 숫자를 저장할 변수를 생성한다.
	int tryy = 0;						// 시도 횟수를 저장할 변수를 생성한다.

	do {
		printf("정답을 추측하시오 : ");			// 추측할 숫자를 입력받는다.
		scanf_s("%d", &guess);				// 입력받은 숫자를 변수 guess에 저장한다.
		tryy++;
		// 시도횟수가 1회 늘어날 때마다 0으로 초기화시킨 시도횟수 변수를 1씩 증가시킨다.
		if (guess < answer)		// 추측한 숫자가 정답보다 작다면 LOW를 출력한다.
			printf("LOW\n");
		if (guess > answer)		// 추측한 숫자가 정답보다 크다면 HIGH를 출력한다.
			printf("HIGH\n");
	} while (guess != answer);		// 추측한 숫자가 정답과 일치하면 반복을 그만둔다.
	printf(" 축하합니다. 시도횟수 = %d", tryy);
	// 정답이 일치하면 시도횟수를 출력한다.

	return 0;
}
```
  
#### 9. 난수(rand)

	- 예측할 수 없는 하나의 난수를 생성한다.
	  난수의 범위는 0 ~ RAND_MAX 까지이며, RAND_MAX는 0x7fff이므로, 난수의 범위는 0 ~ 32767 이다.
	 
1. 기본 사용법
	
	- i = rand()%n
		1. 여기서 n은 횟수를 의미한다.
		2. 0 ~ n - 1 범위의 난수를 i에 대입한다.
		3. 예를 들어, n = 6이라고 하면 0, 1, 2, 3, 4, 5 중 하나가 i에 대입되는 셈이다.

2. 기본 응용법
	
	- i = rand()%n + m
		1. 여기서 m은 시작값을 의미한다.
		2. 1번 기본 사용법을 응용한 것으로, 0 + m ~ (n - 1) + m 범위의 난수를 i에 대입한다.
		3. 예를 들어, n = 6, m = 4 라고 하면 4, 5, 6, 7, 8, 9 중 하나가 i에 대입되는 셈이다.
		4. 다른 예로, n = 5, m = -2 라고 하면 -2, -1, 0, 1, 2 중 하나가 i에 대입되는 셈이다.

2-1. 기본 응용법(2)
	
	- i = rand()%n * m
		1. 0 ~ (n - 1) 범위의 수들에 m을 곱한 수를 i에 대입한다.
		2. 예를 들어, n = 4, m = 2 라고 하면 0, 2, 4, 6 중 하나가 i에 대입되는 셈이다.
		3. m의 값을 2로 주면 2의 배수, 3을 주면 3의 배수가 대입된다.
	 
2-2. 기본 응용법(3)
	
	- i = (rand()%n + m) * k
		1. 0 + m ~ (n + m) - 1 범위의 수들에 k을 곱한 수를 i에 대입한다.
		2. 예를 들어, n = 3, m = 2, k = 4 라고 하면 8, 12, 16 중 하나가 i에 대입되는 셈이다.
		3. 어떤 수의 배수를 사용할 때 용이하다.
	 
2-3. 기본 응용법(4)
	
	- i = rand()%n * m + k
		1. 0 ~ n - 1 범위의 수들에 m을 곱하고 k를 더한 수를 i에 대입한다.
		2. 예를 들어, n = 3, m = 2, k = 5 라고 하면 5, 7, 9 중 하나가 i에 대입되는 셈이다.
		3. 다른 예로, n의 값을 0 이상으로 주고, m = 2, k = 0 으로 주면 짝수가 생성된다.
		4. 3번의 예시와 비슷한 경우로, n의 값을 0 이상으로 주고 m = 2, k = 1으로 주면 홀수가 생성된다.
     
#### 10. for 루프문

	- 정해진 횟수만큼 반복하는 구조
![for](https://github.com/BangYunseo/TIL/blob/main/C/Image/for.PNG)
![for2](https://github.com/BangYunseo/TIL/blob/main/C/Image/for2.PNG)

#### 11. 초기식, 조건식, 증감식

	- 초기식
		1. 초기식은 반복 루프를 시작하기 전에 한 번만 실행된다.
		2. 주로 변수 값을 초기화하는 용도로 사용된다.

	- 조건식
		1. 반복의 조건을 검사하는 수식이다.
		2. 이 수식의 값이 거짓이 되면 반복이 중단된다.

	- 증감식
		1. 한 번의 루프 실행이 끝나면 증감식이 실행된다.
		
![structure_for](https://github.com/BangYunseo/TIL/blob/main/C/Image/structure_for.PNG)

#### 12. printf의 또 다른 형식 

      - %f가 아니라 %.2f
      		1. .2가 의미하는 것은 무조건 소수점 이하 둘째 자리까지만 표시하라는 의미
      		2. 따라서, 왼쪽의 경우 3.141592 중 3.14 까지만 출력되고 나머지는 짤림
      		3. %.100f 로 할 경우에도,3.141592········· 을 표시해서 무조건 100개를 출력
      
      - %d가 아닌 %5d
      		1. 여기서 .5가 아님을 주의
      		2. 숫자의 자리 수를 되도록 5 자리를 맞추어야 하므로 앞에 공백을 남기고 그 뒤에 123을 표시
      		3. 123456을 표시할 때, %5d 조건을 준다면 이 때는 123456을 다 표시
      		4. 앞선 .?f는 ?의 수만큼 소수점 자리수를 맞추지만, 이 경우는 반드시 지켜야되는 것은 아니다.
      
      - 위에서 썼던 두 가지 형식을 모두 한꺼번에 적용
      	1. 전체 자리 수는 6자리로 맞추고 반드시 소수점 이하 셋째 자리까지만 표시
      
![another_printf](https://github.com/BangYunseo/TIL/blob/main/C/Image/another_printf.PNG)
![another_printf2](https://github.com/BangYunseo/TIL/blob/main/C/Image/another_printf2.PNG)

#### 13. while 루프와 for 루프와의 관계 

 ![while-for](https://github.com/BangYunseo/TIL/blob/main/C/Image/while-for.PNG)

#### 14. 반복문 선택 방법

![howtoselect_loop](https://github.com/BangYunseo/TIL/blob/main/C/Image/howtoselect_loop.PNG)
 
#### 15. 다양한 증감수식의 형태  

```C
// 뺄셈 사용
for (int i = 10; i > 0; i--)
	printf("Hello World!"\n);
```
```C
// 2씩 증가
for (int i = 0; i < 10; i += 2)
	printf("Hello World!"\n);
```
```C
// 2씩 곱셈
for (int i = 1; i < 10; i *= 2)
	printf("Hello World!"\n);
```
```C
// anything
for (int i = 0; i < 100; i = (i * i) + 2)
	printf("Hello World!"\n);
```
```C
// 무한 반복 루프
for ( ;; )
	printf("Hello World!"\n);
```
```C
// 한 부분이 없을 수도 있다
for ( ;i < 100; i++)
	printf("Hello World!"\n);
```
```C
// anything2
for (printf("반복시작"), i = 0;i < 100; i++)
	printf("Hello World!"\n);
```
```C
// 복잡한 수식도 조건식이 될 수 있다.
for (i = 0;i < 100 && sum < 2000; i++)
	printf("Hello World!"\n);
```

#### 16. 중첩 반복문

![nested_loop](https://github.com/BangYunseo/TIL/blob/main/C/Image/nested_loop.PNG)

#### 16-1. 중첩 반복문 예제     
         
 ```C
// 중첩 for 문을 이용하여 * 기호를 사각형 모양으로 출력
#include <stdio.h>

int main(void)
{
	int x, y;
	
	fot (y = 0; y < 5; y++)
	{
		for (x = 0; x < 10; x++)
			printf("*");
	}
	
	return 0;
}
```
```C
// 직각삼각형 모양으로 * 출력하기
int main(void)
{
	int x, y;
	
	fot (y = 1; y <= 5; y++)
	{
		for (x = 0; x < y; x++)
			printf("*");
		printf("\n");
	}
	return 0;
}
```
	 
#### 17. 무한 루프   

	- 조건 제어 루프에서 가끔은 프로그램이 무한히 반복하는 일이 발생한다.
	- 이것은 무한 루프(Infinite loop)로 알려져 있다.
	- 무한 반복이 발생하면 프로그램은 빠져나올 수 없기 때문에 문제가 된다.
	- 다만 가끔은 의도적으로 무한 루프를 사용하는 경우도 있다.
		ex)신호등 제어 프로그램
	
![infinite_loop](https://github.com/BangYunseo/TIL/blob/main/C/Image/infinite_loop.PNG)

#### 17-1. 무한 루프가 유용한 경우

	- 반복을 빠져나가는 조건이 까다로운 경우에 많이 사용된다.
	ex) 사용자가 입력한 수가 3의 배수이거나 음수인 경우에 while 루프를 빠져나가야 한다고 하자.

![infinite_loop2](https://github.com/BangYunseo/TIL/blob/main/C/Image/infinite_loop2.PNG)

#### 18. break 문

	- 반복 루프를 빠져 나오는 데 사용한다.
```C
// 재테크를 시작한 사람이 1년에 30%의 수익을 얻는다면 몇 년 만에 원금의 10배가 되는지 알아보는 예제
#include <stdio.h>
#define SEED_MONEY 1000000

int main(void)
{
	int year = 0, money = SEED_MONEY;
	while(1)
	{
		year++;
		money += money*0.3;
		if (money > 10 * SEED_MONEY)
			break;				// break문 사용
	}
	printf("%d", year);
	return 0;
}
```

#### 19. goto 문
	
	- 중첩 루프 안에서 어떤 문제가 발생했을 경우, goto를 이용하면 단번에 외부로 빠져나올 수 있다.
	- break를 사용하면 하나의 루프만을 벗어날 수 있다.
	
![goto](https://github.com/BangYunseo/TIL/blob/main/C/Image/goto.PNG)

#### 19-1. goto 문 예제

![goto2](https://github.com/BangYunseo/TIL/blob/main/C/Image/goto2.PNG)

#### 20. continue 문

	- 0부터 10까지의 정수 중에서 3의 배수만 제외하고 출력하는 예제를 살펴보자

![continue](https://github.com/BangYunseo/TIL/blob/main/C/Image/continue.PNG)

#### 20-1. continue 문 예제

```C
#include <stdio.h>

int main(void)
{
	int i;
	for (i = 0; i < 10; i++)
	{
		if (i % 3 == 0)
			continue;
		printf("%d", i);
	}
	return 0;
}
```
