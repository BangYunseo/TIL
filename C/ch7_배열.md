##  Chapter 7. 배열       

#### 1. 배열

	- 배열을 사용하면 한 번에 여러 개의 변수를 생성할 수 있다.   
```C
int s[10];	// 옆과 같은 명령어를 사용하면 10개의 빈칸을 가진 배열을 생성한다.
```
	 
![array1](https://github.com/BangYunseo/TIL/blob/main/C/Image/ch7/array1.PNG)

#### 2. 배열의 필요성

	- 많은 변수를 한 번에 저장할 수 있다.
	 
![array2](https://github.com/BangYunseo/TIL/blob/main/C/Image/ch7/array2.PNG)

#### 3. 배열의 특징

	- 배열은 메모리의 연속적인 공간에 저장한다.   
		ex) [2. 배열의 필요성]에서 배열 요소 s[0]과 s[1]은 실제 메모리 상에서 붙어있다.     
	- 배열은 서로 관련된 데이터를 차례로 접근해서 처리할 수 있다.
 		> 데이터들이 서로 다른 이름을 사용하고 있다면 이들의 이름을 모두 기억해야 한다.   
   		> 하지만 하나의 이름을 공유하고 번호만 다르다면 쉽게 기억할 수 있고 편하게 사용가능하다.   

#### 3. 배열 선언

![definearray](https://github.com/BangYunseo/TIL/blob/main/C/Image/ch7/definearray.PNG)   

#### 4. 배열 원소와 인덱스
	- 인덱스(index) : 배열 원소의 번호   
	- 인덱스는 1부터 시작되지 않고 0부터 시작된다.     

![array3](https://github.com/BangYunseo/TIL/blob/main/C/Image/ch7/array3.PNG)  

#### 5. 배열 선언의 예

```C
	int scores[60];		// 60개의 int형 값을 가지는 배열 scores
	float cost[12];		// 12개의 float형 값을 가지는 배열 cost
	char name[50];		// 50개의 char형 값을 가지는 배열 name
```
  
#### 5-1. 배열 선언의 주의할 점

	- 배열의 크기를 나타낼 때는 항상 상수를 사용해야 한다.       
	- 변수를 배열의 크기로 사용하면 컴파일 오류가 난다.    
	- 또한 배열의 크기를 음수나 0, 실수로 하면 컴파일 오류가 발생한다.
 
```C
	int scores[];		// 배열의 크기를 지정해야 함
	int scores[];		// 배열의 크기가 변수일 수 없음
	int scores[];		// 배열의 크기가 음수일 수 없음
	int scores[];		// 배열의 크기가 실수일 수 없음
```
#### 6. 기호 상수 사용

![array4](https://github.com/BangYunseo/TIL/blob/main/C/Image/ch7/array4.PNG)  

#### 7. 배열 요소 접근

![array5](https://github.com/BangYunseo/TIL/blob/main/C/Image/ch7/array5.PNG)   

 
```C
	score[5] = 80;
	score[1] = score[0];
	score[i] = 100;		// i는 정수 변수
	score[i + 2] = 100;	// 수식이 인덱스가 된다.
	score[index[3]] = 100;	// index[]는 정수 배열
```

#### 8. 배열 기초 예제

```C
#include <stdio.h>

int main(void)
{
	int i;			// 인덱스 값
	int scores[5]; 		// 배열을 인덱스 값 5를 갖도록 생성

	scores[0] = 10;
	scores[1] = 20;
	scores[2] = 30;
	scores[3] = 40;
	scores[4] = 50;

	// 배열의 값 지정

	for(i = 0; i < 5; i++)
		printf("scores[%d] = %d\n", i, score[i]);

	// for문을 통해 배열 출력

	return 0;
}
```

#### 9. 배열과 반복문

	- 배열의 가장 큰 장점은 반복문을 사용해서 배열의 원소를 간편하게 처리할 수 있다는 점이다.
![arrayfor](https://github.com/BangYunseo/TIL/blob/main/C/Image/ch7/arrayfor.PNG)  
 
#### 10. 예제 1. 배열 난수로 채우기

```C
#include <stdio.h>
#include <stdlib.h>	// 랜덤함수 헤더
#define SIZE 5		// 배열 크기 5로 고정

int main(void)
{
	int i;	// 인덱스의 값 변수로 지정
	int scores[SIZE];	// 배열 생성 (크기는 정의한 SIZE 만큼)

	for(i = 0;i < SIZE; i++)	// 배열에 랜덤 난수 저장
		scores[i] = rand() % 100;
	for(i = 0;i < SIZE; i++)	// 배열에 저장한 랜덤 난수 출력
		printf("scores[%d] = %d\n", i, scores[i]);

	return 0;
}
```

#### 11. 예제 2. 성적 평균 계산하기

```C
#include <stdio.h>
#define STUDENTS 5

int main(void)
{
	int scores[STUDENTS];		// 배열 생성
	int sum = 0;			// 합을 저장할 변수 0으로 초기화
	int i, average;

	for (i = 0; i < STUDENTS; i++)		// 학생 수 만큼 성적을 입력하는 반복문
	{
		printf("성적을 입력하세요 :");
		scanf("%d", &scores[i]);	// 성적을 배열에 저장
	}
	for (i = 0; i < STUDENTS; i++)		// 입력한 성적을 모두 더하는 반복문
		sum += scores[i];

	average = sum / STUDENTS;		// 합 / 학생수 = 평균
	printf("성적 평균 = %d\n", average);	// 평균 출력
}
```

#### 12. 잘못된 인덱스 문제

	- 인덱스가 배열의 크기를 벗어나게 되면 프로그램에 치명적인 오류를 발생시킨다.    
 	- 배열이 인덱스 범위를 벗어나지 않도록 주의해야 한다.
  ```C
int score[5];	// score[5]는 인덱스가 0 ~ 4인 배열을 생성한다는 의미이다.
...
score[5] = 60;  // 인덱스는 0 ~ 4까지 있기 때문에 score[5]는 존재하지 않는 배열 공간이다.
```

![arrayindex](https://github.com/BangYunseo/TIL/blob/main/C/Image/ch7/arrayindex.PNG) 


#### 13. 배열의 초기화

	- 배열의 초기값들을 콤마로 분리하여 중괄호로 감싼 후에 배열을 선언한다.     
![arrayfirst1](https://github.com/BangYunseo/TIL/blob/main/C/Image/ch7/arrayfirst1.PNG) 

 	- 초기값의 개수가 배열보다 적은 경우는 앞의 요소들만 초기화되고 나머지는 0으로 초기화된다.
![arrayfirst2](https://github.com/BangYunseo/TIL/blob/main/C/Image/ch7/arrayfirst2.PNG) 

	- 초기화 후에 배열의 크기를 비워두면 컴파일러가 자동으로 초기값의 개수만큼 크기를 지정한다.
![arrayfirst3](https://github.com/BangYunseo/TIL/blob/main/C/Image/ch7/arrayfirst3.PNG) 



#### 13-1. 초기값이 주어지지 않았다면 ? 

	- 만약 초기값이 주어지지 않은 지역 변수로 선언된 배열이라면, 일반적인 지역 변수와 마찬가지로 아무 의미 없는 쓰레기 값들이 들어간다.     

![arrayfirst4](https://github.com/BangYunseo/TIL/blob/main/C/Image/ch7/arrayfirst4.PNG) 

#### 13-2. 배열의 초기값 주의사항

	- 배열의 모든 요소를 10으로 초기화하려고 할 때,

```C
	int scores[10] = {10};
	// 위와 같이 초기화를 하면 첫 번째 요소만 10이 되고 나머지는 전부 0이 된다.

	int scores[10] = {10, 10, 10, 10, 10, 10, 10, 10, 10, 10};
	// 올바른 초기화 방법
```

#### 13-3. 배열의 초기값 주의사항 2

	- 배열에서 초기화할 때를 제외하면 중괄호로 값을 묶어서 대입할 수 없다.     
 	- 아래와 같이 사용하면 컴파일 오류가 발생한다.   
  	- 배열에 값을 저장하려면 반드시 각 배열 요소에 값을 대입해야 한다.      

```C
	#define SIZE 3

	inr main(void)
	{
		int scores[SIZE];
		scores = {6, 7, 8}; // 배열에 값을 묶어서 대입하면 컴파일 오류가 발생함
	}
```


#### 14. 배열 원소의 개수 계산  


![howmanyarray](https://github.com/BangYunseo/TIL/blob/main/C/Image/ch7/howmanyarray.PNG) 

```C
int scores[] = {1, 2, 3, 4, 5, 6};
int i, size;

size = sizeof(scores) / sizeof(scores[0]);
// sizeof(scores)는 배열 scores 전체의 개수를 계산하고, sizeof(scores[0])은 배열 한 개를 계산함
// 즉 size = 6 / 1 = 6

for (i = 0; i < size; i++)
	printf("%d", scores[i]);
```

#### 14-1. 배열 원소의 개수 계산 2

![howmanyarray2](https://github.com/BangYunseo/TIL/blob/main/C/Image/ch7/howmanyarray2.PNG) 

#### 15. 배열의 복사

```C
// 아래와 같은 명령어는 error를 발생시키는 명령어이다.
int scores[SIZE];
int scores[SIZE];
score = score;

```

```C
// 아래의 명령어가 올바른 배열의 복사 방법이다.
int scores[SIZE];
int scores[SIZE];
int i;

for(i = 0; i < SIZE; i++)
	score[i] = score[i];
// 배열의 원소는 반복문을 통해 하나씩 복사해야 한다.
```

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
```

#### 18. lab #2. 극장 예약 시스템 예제

```C
```

#### 19. lab #3. 최솟값 탐색 예제

```C
```

#### 20. 배열과 함수

(위의 예제들은 작성했던 C파일과 주석을 확인하고 작성 / ppt 52페이지부터 작성)

	- 배열의 경우에는 사본이 아닌 원본이 전달된다.    

#### 21. 순환(recursion)

	- 함수는 자기 자신을 호출할 수도 있다.
	- 이것을 순환이라 부른다.

![recursion](https://github.com/BangYunseo/TIL/blob/main/C/Image/ch6/recursion.PNG)

#### 22. 순환 함수의 구조

	- 순환 알고리즘은 자기 자신을 순환적으로 호출하는 부분과 순환 호출을 멈추는 부분으로 구성되어 있다.
 
![recursion2](https://github.com/BangYunseo/TIL/blob/main/C/Image/ch6/recursion2.PNG)

 
