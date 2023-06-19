##  Chapter 5. 함수       

#### 1. 함수(function)의 개념

	- 입력을 받아 특정한 작업을 통해 결과를 반환하는 코드     
![functionN](https://github.com/BangYunseo/TIL/blob/main/C/Image/functionN.PNG)

#### 2. 함수가 필요한 이유

	1. 코드의 중복을 피할 수 있기 때문이다.     
 	2. 한 번 작성된 함수를 여러 번 재사용할 수 있기 때문이다.     
  	3. 함수를 사용하면 전체 프로그램을 모듈로 나눌 수 있어 개발 과정이 쉬워지고    
   	   보다 체계적이게 되면서 유지 보수가 쉬워지기 때문이다.     

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

![functionAA](https://github.com/BangYunseo/TIL/blob/main/C/Image/functionAA.PNG)
![functionAB](https://github.com/BangYunseo/TIL/blob/main/C/Image/functionAB.PNG)

     
#### 8. 인수와 매개 변수

	- 인수(argument) : 호출 프로그램에 의하여 함수에 실제로 전달되는 값     
 	- 매개 변수(parameter) : 인수를 전달받는 변수     
  
![functionBB](https://github.com/BangYunseo/TIL/blob/main/C/Image/functionBB.PNG)   

	- 만약 매개 변수가 없는 경우에는 매개 변수 위치에 void를 써주거나 아무 것도 적지 않는다.     
 	- 함수가 호출될 때마다 인수는 달라질 수 있다.     
  	- 매개 변수의 개수는 정확히 일치해야 한다.     
   	- 매개 변수의 개수와 인수의 개수가 일치하지 않으면 오류가 발생한다.     
  
#### 9. 반환값(return value)

	- 반환값은 함수가 호출한 곳으로 반환하는 작업의 결과값이다.     
 	- 값을 반환하려면 return 문장 다음에 수식을 써준다.     
  	- 인수는 여러 개가 있을 수 있으나 반환값은 하나만 가능하다.     
	
#### 10. max 함수 예제

```C
#include <stdio.h>
int max(int x, int y);			// 함수의 원형 출력

int main(void)
{
	int x, y, larger;		// 정수 2개를 저장할 변수 x와 y, 큰 값을 저장할 변수 larger을 생성

	printf("정수 2개를 입력하세요 : );	 
	scanf_s("%d %d", &x, &y);			// 정수 2개를 입력

	larger = max(x, y);				// 변수 larger에 함수값 저장
	printf("더 큰 값은 %d 입니다.\n", larger);	// 더 큰 값을 출력
	return 0;
}
int max(int x, int y)
{
	if (x > y)		// 만약 x가 y보다 크다면
		return x;	// x를 출력
	else 			// 만약 y가 x보다 크다면
		return y;	// y를 출력
}
```

#### 11. 정수를 입력 받는 get_integer() 함수 예제

	- 함수 사용 예시		
![getinteger](https://github.com/BangYunseo/TIL/blob/main/C/Image/getinteger.PNG)

```C
#include <stdio.h>

int get_integer();	// 함수의 원형 출력

int main(void)
{
	int get_integer();	// get_integer()함수 출력
	return 0;
}
int get_integer()
{
	int value;		// 입력받을 정수를 저장할 변수 생성
 	printf("정수를 입력하시오 : ");
  	scanf_s("%d", &value);	// 정수 입력
   	return value;		// 입력받은 정수 반환
}
```
#### 12. 온도 변환기 예제 

여기부터
```C
#include <stdio.h>

void printMenu();		// 시작 메뉴 실행하는 함수의 원형 출력
double C2F(double C_temp);	// 섭씨 온도를 화씨 온도로 출력하는 함수의 원형 출력
double F2C(double F_temp);	// 화씨 온도를 섭씨 온도로 출력하는 함수의 원형 출력

int main(void)
{
	char choice;		// 선택할 메뉴를 입력받을 변수 생성
 	double temp;		// 온도를 입력받을 변수 생성

  	while(1)		// 실행하는 사람이 q를 입력할 때까지 무한 반복
	{
 		printMenu();		// printMenu 함수 실행
  		printf("메뉴에서 선택하세요 : ");	
   		choice = getchar();	// getchar 함수를 통해 choice 변수의 값을 입력받음

    		if (choice == 'q')	// choice에 q가 입력된다면
			break;		// 반복문 탈출
  		else if (choice == 'c')	// choice에 c가 입력된다면
		{
 			printf("섭씨온도 : ");	
    			scanf_s("%d", &temp);	// 입력받은 섭씨온도를
       			printf("화씨온도 : %lf\n", C2F(temp));	// 화씨온도로 바꿔서 출력
		}
  		else if (choice == 'f') // choice에 f가 입력된다면
		{
  			printf("화씨온도 : ");
     			scanf_s("d", &temp);	// 입력받은 화씨온도를
			printf("섭씨온도 : %lf\n", F2C(temp)); 	// 섭씨온도로 바꿔서 출력
		}
  		getchar();
	}
 	return 0;
}
void printMenu()		// 시작 메뉴 출력하는 함수
{
	printf("===========================\n");
 	printf("'c' 섭씨온도에서 화씨온도로 변환\n");
  	printf("'f' 화씨온도에서 섭씨온도로 변환\n");
   	printf("'q' 종료\n");
    	printf("===========================\n");
}
double C2F(double C_temp)		// 섭씨온도를 화씨온도로 변환한 함수
{
	return 9.0 / 5.0 * c_temp + 32;
}
double F2C(double F_temp)		// 화씨온도를 섭씨온도로 변환한 함수
{
	return (F_temp - 32.0) * 5.0 / 9.0;
}
 	

```
#### 13. getchar()함수 

	- getchar()가 실행되면 문자열 또는 문자를 입력받는다.
 	- 

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
