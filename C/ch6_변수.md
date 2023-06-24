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

	- 생존 기간을 결정하는 요인
		: 변수가 선언된 위치
		: 저장 유형 지정자
	- 저장 유형 지정자
		: auto
		: register
		: static
		: extern  

#### 10. 저장 유형 지정자 auto

	- 변수를 선언한 위치에서 자동으로 만들어지고 블록을 벗어나게 되며 자동으로 소멸되는 저장 유형을 지정
	- 지역 변수는 auto가 생략되어도 자동 변수가 된다.

![auto](https://github.com/BangYunseo/TIL/blob/main/C/Image/ch6/auto.PNG)

#### 11. 저장 유형 지정자 static 

	- 지역변수처럼 블록에서만 사용되지만, 블록을 벗어나도 자동으로 제거되지 않는 변수
 	- 이런 변수를 정적 변수라고 부른다.

![static](https://github.com/BangYunseo/TIL/blob/main/C/Image/ch6/static.PNG)

#### 12. 저장 유형 지정자 register

	- 레지스터(register)에 변수를 저장 
  
![register](https://github.com/BangYunseo/TIL/blob/main/C/Image/ch6/register.PNG)

#### 13. volatile

	- volatile 지정자는 하드웨어가 수시로 변수의 값을 변경하는 경우에 사용된다.
 ![volatile](https://github.com/BangYunseo/TIL/blob/main/C/Image/ch6/volatile.PNG)
	 
#### 14. 은행 계좌 구현하기 예제  

```C
// 은행 계좌 구현해보기
```
#### 15. 연결(linkage)

	- 다른 범위에 속하는 변수들을 서로 연결하는 것
		1) 외부 연결
		2) 내부 연결
		3) 무연결
	- 전역 변수만이 연결을 가질 수 있다.  
 
 ![linkage](https://github.com/BangYunseo/TIL/blob/main/C/Image/ch6/linkage.PNG)

#### 15-1. 연결 예제

	- 전역 변수는 외부 연결이 가능하다.	
 ![linkageex](https://github.com/BangYunseo/TIL/blob/main/C/Image/ch6/linkageex.PNG)
 
#### 16. 외부 연결

	- 전역 변수를 extern을 이용해서 서로 연결한다.

 ![linkage2](https://github.com/BangYunseo/TIL/blob/main/C/Image/ch6/linkage2.PNG)

#### 17. 함수 앞의 static

	- 변수나 함수 이름은 모두 식별자이므로 같은 조건으로 취급된다.

![static2](https://github.com/BangYunseo/TIL/blob/main/C/Image/ch6/static2.PNG)

#### 18. 블록에서 extern을 이용한 전역 변수 참조

	- extern은 블록에서 전역 변수에 접근할 때도 사용된다.
![extern](https://github.com/BangYunseo/TIL/blob/main/C/Image/ch6/extern.PNG)

#### 19. 저장 유형

	- 일반적으로 자동 저장 유형을 사용 권장
	- 변수의 값이 함수 호출이 끝나도 그 값을 유지해야 한다면 정적 지역
	- 많은 함수에서 공유되는 변수라면 외부 참조 변수
|---|---|---|---|---|


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
