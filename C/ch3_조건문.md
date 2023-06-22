##  Chapter 3. 조건문       

#### 1. 조건문
      
      1. 프로그램의 선택 구조
      2. 제어문에 속하며, 제어문은 조건문과 반복문을 가지고 있다.
      
#### 2. 제어구조

![selection](https://github.com/BangYunseo/TIL/blob/main/C/Image/ch3/selection.PNG)

#### 3. if 문

![IF](https://github.com/BangYunseo/TIL/blob/main/C/Image/ch3/IF.PNG)   

#### 3-1. if 문 예제

```C
// 양수 판단 예제
if (number > 0)					// 변수 number이 0보다 크다면
	printf("양수입니다.\n");		    // "양수입니다." 를 출력한다.
```

```C
// 온도 체크 예제
if (temperature < 0)				// 변수 temperature이 0보다 낮다면
	printf("현재 온도는 영하입니다.\n");	// "현재 온도는 영하입니다." 를 출력한다.

// if 문이 끝나면 if 문 다음 명령어를 실행한다.

printf("현재 온도는 %lf도 입니다.\n", temperature); // 항상 실행하며 현재 온도는 실수형 숫자로 표기한다.
```

#### 3-2. 오류 주의

![error_if](https://github.com/BangYunseo/TIL/blob/main/C/Image/ch3/error_if.PNG)   

#### 3-3. 실수 비교

![compare_int](https://github.com/BangYunseo/TIL/blob/main/C/Image/ch3/compare_int.PNG)   

#### 4. 복합문 (compound statement)

      1. 중괄호를 사용하여 문장들을 그룹핑하는 것
      2. 블록(block)이라고도 한다.
      3. 단일문 대신 들어갈 수 있다.

```C
if (score >= 60)
{
      printf("합격입니다.\n");
      printf("장학금도 받을 수 있습니다.\n");
      // 조건식이 참이라면, if 문 안의 명령어는 모두 실행된다.
}

``` 
  
#### 5. if-else 문

![if-else](https://github.com/BangYunseo/TIL/blob/main/C/Image/ch3/ifelse.PNG)

#### 5-1. if-else 문 예제

```C
// 예제 1
if (score >= 60)				// score >= 60 이면 실행
      	printf("합격입니다.\n");
else						// score < 60 이면 실행
	printf("불합격입니다.\n");
	
// 위 조건문은 조건연산자 "(score >= 60)? printf("합격입니다.\n"): printf("불합격입니다\n.");" 로 나타낼 수 있다
// score >= 60일 때, 참이면 첫 명령어를, 거짓이면 다음 명령어를 실행한다.
``` 
```C
// 예제 2 
if (score >= 60)				// score >= 60 이면 실행
{
      	printf("합격입니다.\n");
	printf("장학금을 받을 수 있습니다.\n");
}
else						// score < 60 이면 실행
{
	printf("불합격입니다.\n");
	printf("다시 도전하세요.\n");
}
```

#### 6. 조건연산자

      - 간단한 if - else 문은 조건연산자를 사용하여 표현할 수도 있다.
```C
(score >= 60)? printf("합격입니다.\n"): printf("불합격입니다\n.");
```
 ```C
bonus = ((years > 30) ? 500 : 300);
```
            
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
![if-if](https://github.com/BangYunseo/TIL/blob/main/C/Image/ch3/ifif.PNG)

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

![if-if-if](https://github.com/BangYunseo/TIL/blob/main/C/Image/ch3/ififif.PNG)
 
#### 10. switch 문 

      - 제어식의 값에 따라서 여러 경로 중에서 하나를 선택할 수 있는 제어 구조 
      
![switch](https://github.com/BangYunseo/TIL/blob/main/C/Image/ch3/switch.PNG)

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

![delbreak1](https://github.com/BangYunseo/TIL/blob/main/C/Image/ch3/delbreak1.PNG)
 
#### 10-3. break가 의도적으로 생략되는 경우      

![delbreak2](https://github.com/BangYunseo/TIL/blob/main/C/Image/ch3/delbreak2.PNG)

#### 10-4. default 문

![default](https://github.com/BangYunseo/TIL/blob/main/C/Image/ch3/default.PNG)

#### 11. switch 문과 if-else 문     
            
![switch_if-else](https://github.com/BangYunseo/TIL/blob/main/C/Image/ch3/switch_if-else.PNG)  


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

