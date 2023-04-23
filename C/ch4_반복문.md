##  Chapter 4. 반복문       

#### 1. 반복 구조

	- 어떤 조건이 만족될 때까지 루프를 도는 구조

#### 2. 반복문의 종류

	- 반복문은 크게 while 루프와 for 루프로 나누어진다.

#### 3. while 문

	- 주어진 조건이 만족되는 동안 문장들을 반복 실행한다.
![while](https://github.com/BangYunseo/TIL/blob/main/C/Image/while.PNG)   
![while1](https://github.com/BangYunseo/TIL/blob/main/C/Image/while1.PNG) 

#### 3-1. while 문의 실행 과정

![whilee](https://github.com/BangYunseo/TIL/blob/main/C/Image/whilee.PNG)   
	- 만일 i를 증가시키는 증가식이 없었다면, 무한 루프(infinite loop) 문제가 발생한다.
	- 반복문을 사용할 때는 반드시 반복이 종료되는지 확인해야 한다.

#### 4. if 문과 while 문의 비교

![if-while](https://github.com/BangYunseo/TIL/blob/main/C/Image/if-while.PNG)   

#### 5. while 문에서 주의할 점

![important_while](https://github.com/BangYunseo/TIL/blob/main/C/Image/important_while.PNG)   
![important_while2](https://github.com/BangYunseo/TIL/blob/main/C/Image/important_while2.PNG)  

#### 6. 참과 거짓

```C
int i = 3;
while (i)					// while (i != 0)과 같음
{
	printf("%d는 참입니다.\n", i);
	i--;
}
printf("%d는 거짓입니다.\n", i);

/*
출력 형태
3은 참입니다.
2는 참입니다.
1은 참입니다.
0은 거짓입니다.
*/
``` 

#### 7. 센티널 (보초값)

	- 반복루프를 사용하여 사용자가 입력하는 정수의 합을 계산한다고 가정하자.
		1. 만일 입력될 데이터의 갯수가 미리 정해져 있지 않다면?
		2. 만약 데이터가 너무 많아서 갯수를 알기 어렵다면?
	
	- 데이터의 끝에 끝을 알려주는 특수한 데이터를 놓을 수 있다.
	- 프로그램에서는 이 특수한 데이터가 나타나면 데이터의 입력을 중단하라고 한다.
		1. 일반적인 데이터 값에서 절대 등장할 수 없는 값으로 선택
		2. 예시) 성적을 입력받아 성적의 평균을 내는 경우, 음수나 100보다 큰 값을 그 특수 데이터로 선택
	
	- 센티널 : 입력되는 데이터의 끝을 알리는 특수한 값
		1. 일반적인 데이터 값에서는 절대 등장할 수 없는 값으로 정해 줄 수 있음
		2. 예시) 성적을 입력받아 성적의 평균을 구하는 경우, 음수나 100보다 큰 값이 센티널이 될 수 있음
		
![sentinel](https://github.com/BangYunseo/TIL/blob/main/C/Image/sentinel.PNG)

#### 7-1. 센티널 예제

```C
// while 문을 이용하여 성적의 평균 구하기
#include <stdio.h>

int main(void)
{
	int grade, n;				// 성적을 저장할 변수 grade와 입력된 성적의 숫자를 셀 변수 n을 생성
	float sum, average;			// 성적의 합계를 저장할 변수 sum과 성적의 평균을 계산할 변수 average를 생성
	
	// 필요한 변수들 초기화
	n = 0;					// 입력된 성적의 숫자를 저장할 변수 n을 0으로 초기화
	sum = 0;				// 합계를 저장할 변수 sum을 0으로 초기화
	grade = 0;				// 입력받은 성적을 저장할 변수 grade를 0으로 초기화
	
	// 위의 변수들 중 n과 sum은 합을 통해 계산하기 때문에 0으로 초기화한다.
	
	printf("종료 시 음수 입력\n");		// 센티넬 값
	
	while (grade >= 0)			
	// grade가 음수가 아니라면, 성적을 계속 입력받음. grade가 음수일 때, 그 값은 센티넬 값임
	{
		printf("성적을 입력하세요 : ");			// 성적을 입력받음
		scanf("%d", &grade);			     	// 입력받은 성적을 변수 grade에 저장	
		
		sum = sum + grade;				// 합계를 저장할 변수 sum에 입력받은 grade와 sum을 더한다.
		n++;						// 입력된 성적의 개수를 저장할 변수 n의 값을 1 더한다.
	}
	
	sum = sum - grade;
	n--;
	/* grade의 최신 저장값은 마지막에 입력된 수다. 또한, n에 음수를 입력하면 그 횟수도 n에 저장된다. 
	물론 n에 음수를 입력하면 while문의 반복이 끝나지만, 센티널 값도 합계와 개수에 포함되는 것이다.
	 반복 루프가 끝나면 센티널 값을 합계와 개수에서 제거해야 한다.
	 
	 average = sum / n;
	 printf("성적의 평균은 %f 입니다.\n", average);
	 
	 return 0;
}
```

#### 8. do - while 문
     
     
     
#### 7. 복잡한 조건식

```C
// 학점 결정 코드
if (score >= 80 && score < 90)
	grade = 'B';
```
```C
// 공백 문자들의 개수를 세는 코드
if (ch == '' || ch == '\n' || ch == '\t')
	White_space++;
```
  
#### 8. 중첩 if

     - if 문에 다시 if 문이 포함되는 것을 말한다.    
![if-if](https://github.com/BangYunseo/TIL/blob/main/C/Image/ifif.PNG)

#### 8-1. 중첩 if 문 예제

```C
// if 문 안의 문장 자리에 if문이 들어간 경우
if (score >= 80)
	if (score >= 90)
		printf("당신의 학점은 A입니다.\n");
```
```C
// if 문 안의 문장 자리에 if-else문이 들어간 경우
if (score >= 80)
	if (score >= 90)
		printf("당신의 학점은 A입니다.\n");
	else
		printf("당신의 학점은 B입니다.\n");
```

#### 9. 연속적인 if

![if-if-if](https://github.com/BangYunseo/TIL/blob/main/C/Image/ififif.PNG)
 
#### 10. switch 문 

      - 제어식의 값에 따라서 여러 경로 중에서 하나를 선택할 수 있는 제어 구조 
      
![switch](https://github.com/BangYunseo/TIL/blob/main/C/Image/switch.PNG)

#### 10-1. switch 문 예제 

 ```C
int main(void) 
{ 
	int number; 
	printf("정수를 입력하시오:"); 
	scanf("%d", &number); 
	
	switch(number) 
	{
		case 0: 
			printf("없음\n"); 
			break ;
		case 1: 
			printf("하나\n"); 
			break ;
		case 2: 
			printf("둘\n"); 
			break ;
		default: 
			printf("많음\n"); 
			break;
	} 
} 
```

#### 10-2. break가 생략되는 경우   

![delbreak1](https://github.com/BangYunseo/TIL/blob/main/C/Image/delbreak1.PNG)
 
#### 10-3. break가 의도적으로 생략되는 경우      

![delbreak2](https://github.com/BangYunseo/TIL/blob/main/C/Image/delbreak2.PNG)

#### 10-4. default 문

![default](https://github.com/BangYunseo/TIL/blob/main/C/Image/default.PNG)

#### 11. switch 문과 if-else 문     
            
![switch_if-else](https://github.com/BangYunseo/TIL/blob/main/C/Image/switch_if-else.PNG)  


#### 12. switch 문에서 주의할 점   

	- 제어식의 값은 반드시 정수형으로 계산한다.
	- 수식의 값이 정수형으로 나오지 않는다면 switch 문을 사용할 수 없다.
	- case 절에 실수, 변수, 수식, 문자열을 사용하면 컴파일 오류
	- 다만 문자는 아스키코드로 표현되고, 아스키코드는 정수이므로 사용 가능하다.
	- 단, 문자열은 사용할 수 없다.
	
```C
switch(number) 
{
	case x: 					// 변수는 사용할 수 없다.
		printf("없음\n"); 
		break ;
	case (x+2):					// 변수가 들어간 수식은 사용할 수 없다.		 
		printf("하나\n"); 
		break ;
	case 0.001:					// 실수는 사용할 수 없다. 
		printf("둘\n"); 
		break ;
	case "001":					// 문자열은 사용할 수 없다. 
		printf("많음\n"); 
		break; 
} 
```

