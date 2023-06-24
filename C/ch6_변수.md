##  Chapter 6. 변수       

#### 1. 변수의 속성

	- 변수의 속성 : 이름, 타입, 크기, 값 + 범위, 생존 시간, 연결  
		1) 범위(scope) : 변수가 사용 가능한 범위, 가시성  
		2) 생존 시간(lifetime) : 메모리에 존재하는 시간
		3) 연결(linkage) : 다른 영역에 있는 변수와의 연결 상태
 
![vtype](https://github.com/BangYunseo/TIL/blob/main/C/Image/ch6/vtype.PNG)

#### 2. 변수의 범위

	- 변수는 크게 지역 변수와 전역 변수로 나눠진다.
	 
![vtype2](https://github.com/BangYunseo/TIL/blob/main/C/Image/ch6/vtype2.PNG)

#### 2-1. 지역 변수와 전역 변수

![localglobal](https://github.com/BangYunseo/TIL/blob/main/C/Image/ch6/localglobal.PNG)

#### 3. 지역 변수

	- 지역 변수(local variable)은 블록 안에 선언되는 변수이다.
	- 또한 지역 변수는 블록 안의 어떤 위치에서도 선언할 수 있다. 	

![local1](https://github.com/BangYunseo/TIL/blob/main/C/Image/ch6/local1.PNG)   
![local2](https://github.com/BangYunseo/TIL/blob/main/C/Image/ch6/local2.PNG)  

#### 3-1. 지역 변수의 생존 기간
	- 지역 변수는 변수가 선언된 블록이 시작할 때 시스템 스택(stack)인 메모리 공간에 만들어진다.
	- 지역 변수는 자동으로 초기화되지 않는다.
	- 블록이 종료되면 지역 변수에 할당된 메모리 공간은 반환된다.
	- 메모리 공간이 반환되면 지역 변수도 사라진다. 
 
![local3](https://github.com/BangYunseo/TIL/blob/main/C/Image/ch6/local3.PNG)  

#### 3-2. 지역 변수의 예제

```C
#include <stdio.h>

int main(void)
{
	int i;	// 메인함수의 지역 변수
	// 초기화되지 않은 지역 변수는 쓰레기 값을 가진다. 

  	for(i = 0; i < 5; i++)
   	{
    		int temp = 1;		// 블록이 시작할 때마다 생성되어 초기화되는 지역 변수
      		printf("temp = %d\n", temp);	// temp값 출력
		temp++;
	}
 	return 0;
}
```
  
#### 4. 함수와 매개 변수

	- 함수의 헤더 부분에 정의되어 있는 매개 변수도 일종의 지역 변수이다.   
	- 즉, 지역 변수가 지니는 모든 특징을 가지고 있다.
	- 지역 변수와 다른 점은 함수 호출 시의 인수 값을 초기화되어 있다는 점이다.
 
![local4](https://github.com/BangYunseo/TIL/blob/main/C/Image/ch6/local4.PNG)  

#### 4-1. 함수와 매개 변수의 예제

```C
#include <stdio.h>
int inc(int counter);	// 함수 inc의 원형 출력

int main(void)
{
	int i;	// 지역변수 i 생성

 	i = 10;	// i를 10으로 초기화
  	printf("함수 호출 전 i = %d\n", i);
   	inc(i);	// 값에 의한 호출(call by value)	
    	// main()안의 i의 값은 함수 호출로 변경되지 않는다.
	
	// inc()에서 매개 변수 counter를 변화시킨다.
	// 하지만 main() 안의 i와 inc()의 counter는 완전히 별도의 지역 변수이다.
	// -> 함수 호출 시에는 변수 i의 값이 변수 counter로 복사될 뿐이다.
	// 즉, inc() 함수는 로컬 변수 counter만 증가시키고 main() 함수의 i 값을 수정하지는 않는다.
	// -> 함수를 호출할 때 인수의 값이 매개 변수로 복사된다는 의미
	// = 값에 의한 호출을 의미한다. (call by value)
	
     	printf("함수 호출 후 i = %d\n", i);
      	return 0;
}
void inc(int counter)	// 매개 변수도 일종의 지역 변수이기 때문에 함수가 시작되면 생성되고 종료되면 소멸함
{
	counter++;
	// 매개 변수를 증가하더라도 인수 i에 영향을 주지 않는다.
	// 변수 i와 변수 counter는 별도의 지역 변수이기 때문이다.
}
```

#### 5. 전역 변수

	- 전역 변수(global variable)는 함수 외부에서 선언되는 변수이다.
 	- 전역 변수의 범위는 소스 파일 전체이다.

![global1](https://github.com/BangYunseo/TIL/blob/main/C/Image/ch6/global1.PNG)  

#### 5-1. 전역 변수의 초기값과 생존 기간

```C
#include <stdio.h>
int A;		// 전역 변수의 초기값은 0이다.
int B;		// 전역 변수의 초기값은 0이다.
int add();	// add() 함수의 원형 출력

int main(void)
{
	int answer;		// answer 변수 생성	
 	A = 5;			// 전역 변수 A를 5로 초기화
	  B = 7;		// 전역 변수 B를 7로 초기화
   	answer = add();		// 변수에 함숫값을 대입
    	printf("%d + %d = %d\n", A, B, answer);		// 전역 변수 A와 B의 합 출력
     	return 0;
}
int add()
{
	return A + B;		// 전역 변수의 합을 반환하는 함수
}
```

#### 6. 전역 변수의 초기값

	- 전역 변수의 생존 기간 : 프로그램의 시작과 동시에 생성되어 프로그램이 종료되기 전까지 메모리에 존재
![global2](https://github.com/BangYunseo/TIL/blob/main/C/Image/ch6/global2.PNG)  
 
#### 7. 전역 변수의 사용

```C
// 스파게티 코드 예시
#include <stdio.h>
void sub();		// 함수의 원형 출력

int main(void)
{
	for(x = 0; x < 10; x++)		// 10번 반복
		printf("\n");
		sub();		// 함수 출력
}
void sub()	// 별 출력 예제
{
	for(x = 0; x < 10; x++)
		printf("*");	
}
```
	- 위 코드의 출력은 아래와 같이 된다.
![global3](https://github.com/BangYunseo/TIL/blob/main/C/Image/ch6/global3.PNG)   

	- 전역 변수는 그 변수를 어디에서 변경하고 있는지 파악하지 못하는 경우가 많다.
	- 그래서 스파게티 코드가 많이 일어난다.

	- 거의 모든 함수에서 사용하는 공통적인 데이터는 전역 변수로 한다.
	- 일부 함수들만 사용하는 데이터는 전역 변수로 하지 않고 함수의 인수로 전달한다. 

#### 8. 같은 이름의 전역 변수와 지역 변수
	
![localglobal2](https://github.com/BangYunseo/TIL/blob/main/C/Image/ch6/localglobal2.PNG)

#### 9. 생존 기간

	- 정적 할당(static allocation)
		: 프로그램 실행 시간 동안 계속 유지
	- 자동 할당(automatuc allocation)
		: 블록에 들어갈 때 생성
		: 블록에서 나올 때 소멸  

![allocation](https://github.com/BangYunseo/TIL/blob/main/C/Image/ch6/allocation.PNG)



#### 13. getchar()함수 

	- 문자를 입력받아야 하므로 변수를 설정하고 scanf()에 서식지정자로 %c를 설정한다.
 	- scanf()에서 %c는 문자 한 개만 입력받을 수 있다.
  	- 따라서 문자를 여러 개 입력하더라도 한 개만 저장되고 나머지는 모두 무시된다.
   	- 입력되는 문자는 첫 번째 문자 뿐이다.

```C
// scanf() 사용 예제
#include <stdio.h>

int main(void)
{
	char c1;

  	printf("문자를 입력하세요 : ");
   	scanf_s("%c", &c1);

     	printf("%c\n", cl);
      	return 0;
}
```
	- getchar()가 실행되면 문자열 또는 문자를 입력받는다.
 	- 문자열이나 문자가 바로 저장되는 것이 아니라, 입력 버퍼에 저장된다.
  	- getchar()의 반환값으로 입력 버퍼에서 문자 한 개를 꺼내서 저장한다.
	- 앞선 scanf()와 마찬가지로 문자 여러 개를 입력받아도 첫 번째 문자만 반환한다.
```C
// getchar() 사용 예제
#include <stdio.h>

int main(void)
{
	char c1 = getchar();

     	printf("%c\n", cl);
      	return 0;
}
```

#### 13-1. +getchar()함수 

	- getchar() 함수는 메뉴에서 사용자가 입력한 문자를 읽어들이는데 사용한다.    
 	- 특정한 값을 입력한 후, 엔터키를 눌러야 입력된 값을 프로그램이 처리한다.     
  	- 이 때, 엔터키를 누르면 버퍼에 개행문자(\n)이 저장된다.      
	- 다음 getchar()함수가 호출될 때 먼저 개행문자가 호출되면서 입력을 받지 못하는 문제가 발생할 수 있다.  

 ![GetcharScanf](https://github.com/BangYunseo/TIL/blob/main/C/Image/GetcharScanf.PNG)
 ![getchar1](https://github.com/BangYunseo/TIL/blob/main/C/Image/getchar1.PNG)
 ![getchar2](https://github.com/BangYunseo/TIL/blob/main/C/Image/getchar2.PNG)
 
#### 14. 함수의 원형(function prototyping)

	- 함수의 원형은 컴파일러에게 함수에 대하여 미리 알리는 것을 말한다.     
 	- 함수의 원형은 함수의 이름, 매개변수, 반환형을 함수가 정의되기 전에 미리 알려주는 것이다.     
  	- 함수의 원형은 함수 헤더에 세미콜론(;)을 추가한 것과 동일하다.     
   	- 다만 함수 원형에서는 매개 변수의 이름은 적지 않아도 된다.     
	- 매개 변수의 자료형만 적어도 된다.     
 	- 일반적으로 함수의 원형을 사용하는 것이 좋다.
  
 ![functionnn](https://github.com/BangYunseo/TIL/blob/main/C/Image/functionnn.PNG)

#### 15. 수학적인 계산 함수 생성 예제
   
 ```C
// 조합 구하기(ex // C(2, 3))
#include <stdio.h>

int get_integer(void);			// 숫자를 입력받는 함수의 원형
int combination(int n, int r);		// 조합을 계산하는 함수의 원형
int factorial(int n);			// 팩토리얼을 계산하는 함수의 원형
int main(void)
{
	int x, y;		// 숫자를 저장할 변수 생성
	
	x = get_integer();	// 변수 하나에 숫자를 저장하는 함수 실행	
	y = get_integer();	// 변수 하나에 숫자를 저장하는 함수 실행

	printf("C(%d, %d) = %d \n", x, y, combination(a, b));	
	// C(x, y) = 조합값 의 형태로 출력
	return 0;
}
int combination(int n, int r)	// 조합 계산 함수
{
	return (factorial(n)/factorial(r) * factorial(n - r)));	// 조합 반환
}
int get_integer(void)	// 정수 입력 함수
{
	int n;	// 변수 생성

  	printf("정수를 입력하시오 : ");
   	scanf_s("%d", &n);
    	return n;
}
int factorial(int n)
{
	int i;
 	long result = 1;	// 결과값을 1로 초기화, 곱셈이기 때문에 0이 아닌 1로 초기화하는 것
    	for(i = 1; i <= n; i++)
     		result *= i;		// 결과값이 n이 되기 전까지 i 곱셈, 1부터 n까지 곱하는 것
       return result;
}
```
	 
#### 16. 소수 찾는 예제   

```C
// 주어진 숫자가 소수인지 결정하는 프로그램
#include <stdio.h>

int get_integer(void);	// 숫자를 입력받는 함수의 원형 출력
int is_prime(int n);	// 숫자가 소수인지 판단하는 함수의 원형 출력
int main(void)
{
	int n;		// 변수 생성
	n = get_integer();	// 함수를 통해서 변수 n에 수를 저장
	if (is_prime(n) == 1)	// 만약 소수인지 판단하는 함수에서의 결과값이 1이라면(1일 때 소수)
		printf("%d은(는) 소수!\n", n);
	else			// 소수가 아닐 경우
		printf("%d은(는) 소수가 아님!\n", n);
	return 0;
}
int get_integer(void)	// 정수 입력 함수
{
	int n;	// 변수 생성

  	printf("정수를 입력하시오 : ");
   	scanf_s("%d", &n);
    	return n;
}
int is_prime(int n)
{
	int i;	// 변수 생성

	for (i = 2; i < n; i++)
	{
		if (n % i == 0)		// n을 i로 나눈 나머지가 0이라면
			return 0;		// 소수가 아님을 반환
		return 1;		// if문에 해당되지 않는다면 소수임
	}
}
```
#### 17. 라이브러리 함수(library function)

	- 컴파일러에서 제공하는 함수
 		1) 표준 입출력   
  		2) 수학 연산   
		3) 문자열 처리   
  		4) 시간 처리   
		5) 오류 처리   
		6) 데이터 검색과 정렬   

#### 18. 난수 함수(rand())

	- 난수(random number)는 규칙성 없이 임의로 생성되는 수
	- 난수는 암호학이나 시뮬레이션, 게임 등에서 필수적이다.
	
 	- rand() 
 		- 난수를 생성하는 함수
   		- 0부터 RAND_MAX까지의 난수 생성

#### 18-1. 로또 번호 생성기

	- 로또 번호는 1부터 45까지의 숫자 6개로 이루어진다.	
	- 배열과 선택정렬을 이용해서 로또 번호를 깔끔하게 출력해보자.
```C
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 45		// MAX를 45로 정의한다.
#define SIZE 6		// SIZE를 6으로 정의한다. (배열의 크기)

void array1(int list[]);		// 선택정렬 함수의 원형 출력

int main(void)
{
	int rotto[SIZE];	// 로또번호를 저장할 배열 생성
	int i, j;		// for문에 사용할 변수들을 생성
	srand((unsigned)time(NULL));	// 난수 발생

	for (i = 0; i < SIZE; i++)		// 6개의 숫자를 생성
	{
		rotto[i] = (rand() % MAX) + 1;	// 배열에 로또번호를 저장
		for (j = 0; j < i; j++)
		{
			if (rotto[i] == rotto[j])
				i--;
		}
	}
	array1(rotto);	
	// 선택정렬을 실행한다. 함수의 원형이 배열값을 입력받으므로 rotto만 입력해도 됨

	for (i = 0; i < SIZE; i++)
	{
		printf("%d ", rotto[i]);	// 차례대로 로또번호를 출력함
	}
	return 0;
}
void array1(int list[])
{
	int i, j, min, temp;	
	// for문에 사용할 변수 i와 j, 작은 값을 저장할 변수 min과 교환에 사용할 변수 temp 생성
	for (i = 0; i < SIZE - 1; i++)	// 마지막에는 자동으로 큰 값이 배치됨
	{
		min = i;	// 가장 작은 값에 for문의 변수 i를 저장
		for (j = i + 1; j < SIZE; j++)	
		// j의 값에 i에 1을 더한 수를 저장하고 SIZE 만큼 반복
		// i의 값에 1을 더한 인덱스의 값
		// 만약 i가 0일 때, list[0]을 가리킴
		// 그렇다면 j는 list[1]을 가리키게 됨
		{
			if (list[j] < list[min])	// 만약 list[1] < list[0] 이라면
				min = j;				// 가장 작은 값은 j가 됨
		}
		temp = list[i];			// 임시변수에 list[i]를 저장
		list[i] = list[min];	// list[i]에 list[min]을 저장
		list[min] = temp;		// list[min]에 temp값(list[i])을 저장
	}
}
```

#### 19. 표준 라이브러리 함수(수학 함수)

	- 수학 함수들에 대한 원형은 헤더파일 math.h에 있다.
	- 수학 함수는 일반적으로 double형의 매개 변수와 반환값을 가진다.


![mathh](https://github.com/BangYunseo/TIL/blob/main/C/Image/mathh.PNG)

#### 20. floor()함수와 ceil()함수

![floorceil](https://github.com/BangYunseo/TIL/blob/main/C/Image/floorceil.PNG)
	- floor()은 바닥, ceil()은 천장을 나타내는 함수이다.
	- 만약 1.6가 입력됐을 때, floor()함수를 이용하면 1.0이 출력된다.
	- 앞과 마찬가지로 1.6가 입력됐을 때, ceil()함수를 이용하면 2.0이 출력된다.

```C
#include <stdio.h>

int main(void)
{
	double result, value = 1.6;	// result와 value의 값을 1.6으로 초기화
	result = floor(value);
	printf("%lf", result);		// result의 값은 1.0이다.

 	result = ceil(value);
	printf("%lf", result);		// result의 값은 2.0이다.
	return 0;
}
```

#### 21. 기타 함수

![anyfunction](https://github.com/BangYunseo/TIL/blob/main/C/Image/anyfunction.PNG)

#### 22. 시간 맞추기 게임 예제

```C
#include <stdio.h>
#include <time.h>

int main(void)
{
	unsigned long start, end;	// 부호없는 수로 초기화한다.
	start = time(NULL);			
	// start에 현재 시각을 반환하는 time(NULL)을 저장한다.

	printf("종료하고 싶다면 아무 키나 누르세요. \n");	
	while (1)	// 무한 반복
	{
		if (getchar())		// 만약 아무 문자를 입력받는다면,
			break;			// 프로그램을 종료한다.
	}
	printf("종료되었습니다.\n"); 
	end = time(NULL);		
	// end에 현재 시각을 반환하는 time(NULL)을 저장한다.

	printf("경과된 시간은 %d초입니다. \n", end - start);	
	// 두 시간의 차이를 출력한다.

	return 0;
}

```

#### 23. 모듈화

	- 모듈 내에서는 최대의 상호 작용이 있어야 하고 모듈 사이에는 최소의 상호 작용만 존재해야 한다.
	- 만약 모듈과 모듈 사이의 연결이 복잡하다면 모듈화가 잘못된 것이다.

![modularization](https://github.com/BangYunseo/TIL/blob/main/C/Image/modularization.PNG)
