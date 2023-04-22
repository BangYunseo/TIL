##  Chapter 3. 조건문       

#### 1. 조건문
      
      1. 프로그램의 선택 구조
      2. 제어문에 속하며, 제어문은 조건문과 반복문을 가지고 있다.
      
#### 2. 제어구조

![selection](https://github.com/BangYunseo/TIL/blob/main/C/Image/selection.PNG)

#### 3. if 문

![IF](https://github.com/BangYunseo/TIL/blob/main/C/Image/IF.PNG)   

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

![error_if](https://github.com/BangYunseo/TIL/blob/main/C/Image/error_if.PNG)   

#### 3-3. 실수 비교

![compare_int](https://github.com/BangYunseo/TIL/blob/main/C/Image/compare_int.PNG)   

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

![if-else](https://github.com/BangYunseo/TIL/blob/main/C/Image/ifelse.PNG)

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

#### 9-2. OR 연산자   
      
      - 신입 사원을 채용하는 조건이 변경되어서 나이가 30살 이하이거나 토익 성적이 700점 이상이면 된다고 하자.      
      
![OR](https://github.com/BangYunseo/TIL/blob/main/C/Image/or.PNG)

#### 9-3. NOT 연산자   

      - 피연산자의 값이 참이면 연산의 결과값을 거짓으로 만들고, 피연산자의 값이 거짓이면 연산의 결과값을 참으로 만든다.    
      
![NOT](https://github.com/BangYunseo/TIL/blob/main/C/Image/not.PNG)
      
      - result = !1;                // result에는 0이 대입된다.
      - result = !(2 == 3);         // result에는 1이 대입된다.
      
#### 9-3-1. 참과 거짓의 표현 방법      

      - 관계 수식이나 논리 수식이 만약 참이면 1이 생성되고 거짓이면 0이 생성된다.
      - 피연산자의 참, 거짓을 가릴 때에는 0이 아니면 참이고 0이면 거짓으로 판단한다.
      - 음수
            1. C에서는 0이 아니면 참으로 간주
            2. 음수도 참으로 간주     
      - NOT 연산자를 적용하는 경우      
            !0;    // 식의 값은 1
            !3;    // 식의 값은 0
            !-3;   // 식의 값은 0

#### 9-4. 논리 연산자의 예

      -"x는 1, 2, 3 중의 하나인가?"   
            > (x == 1) || (x == 2) || (x == 3)   
      -"x가 60 이상 100 미만이다."   
            > (x >= 60) && (x < 100)   
      -"x가 0도 아니고 1도 아니다."
            > (x != 0) && (x != 1)        // x는 0도 아니고 1도 아니다.
            
#### 10. 조건 연산자 : 3개의 피연산자를 가지는 삼항 연산자     
            
![iff](https://github.com/BangYunseo/TIL/blob/main/C/Image/iff.PNG)  

```C
absolute_value = (x > 0) ? x: -x;    // 절댓값 계산
max_value = (x > y) ? x: y;          // 최댓값 계산
min_value = (x < y) ? x: y;          // 최솟값 계산
(age > 20) ? printf("성인\n"): printf("청소년\n");   // 20살 이상이라면 성인을 출력하고 20살 미만이라면 청소년을 출력한다.
```

#### 11. 비트 연산자   

* 논리 연산자와 비트 연산자는 다르다.

|연산자|연산자의 의미|예|
|:---:|:---:|:---|
|&|비트 AND|두 개의 피연산자의 해당 비트가 모두 1이면 1, 아니면 0|
|l|비트 OR|두 개의 피연산자의 해당 비트 중 하나만 1이면 1, 아니면 0|
|^|비트 XOR|두 개의 피연산자의 해당 비트의 값이 같으면 0, 아니면 1|
|<<|왼쪽으로 이동|지정된 개수만큼 모든 비트를 왼쪽으로 이동한다.|
|>>|오른쪽으로 이동|지정된 개수만큼 모든 비트를 오른쪽으로 이동한다.|
|~|비트 NOT|0은 1로 만들고 1은 0으로 만든다.|

#### 11-1. 비트 AND 연산자   

![Andd](https://github.com/BangYunseo/TIL/blob/main/C/Image/Andd.PNG)  

#### 11-2. 비트 OR 연산자   

![Orr](https://github.com/BangYunseo/TIL/blob/main/C/Image/Orr.PNG)  

#### 11-3. 비트 XOR 연산자   

![XOR](https://github.com/BangYunseo/TIL/blob/main/C/Image/XOR.PNG)  

#### 11-4. 비트 NOT 연산자  

![Nott](https://github.com/BangYunseo/TIL/blob/main/C/Image/Nott.PNG)  

#### 11-5. 비트 이동 연산자   

* 크기를 비교하는 관계 연산자와 다르다

|연산자|기호|설명|
|:---:|:---:|:---|
|왼쪽 비트 이동|<<|x << y x의 비트들을 y 칸만큼 왼쪽으로 이동|
|오른쪽 비트 이동|>>|x >> y x의 비트들을 y 칸만큼 오른쪽으로 이동|

#### 11-6. << 연산자 

      - 비트를 왼쪽으로 이동
      - 값은 2배가 된다.   
      
![left](https://github.com/BangYunseo/TIL/blob/main/C/Image/left.PNG)
      
#### 11-7. >> 연산자  

      - 비트를 오른쪽으로 이동
      - 값은 1/2배가 된다.   
      
![right](https://github.com/BangYunseo/TIL/blob/main/C/Image/right.PNG)

#### 12. Lab 3. 10진수를 2진수로 출력하기   

	- 아래의 예제는 10진수를 2진수로 변환하여 출력하는 예제이다.    
	
	- 변수 mask에 1의 값을 저장하고, 왼쪽으로 7비트를 이동시키면 mask = 00000001 에서 mask = 10000000 이 된다.    
	
	- 입력하는 10진수를 2진수로 고치면 8비트의 2진수 형태가 되는데, 2진수는 오른쪽부터 2의 0승, 2의 1승, ···, 2의 7승의 비트를 가진다.   
	
	- 아래의 과정은 왼쪽으로 7비트 이동시켰던 값을 오른쪽으로 1비트씩 이동시키면서 예시로 입력한 num10에 저장된 수와 0의 위치가 같으면 0을 출력, 만약에 0이 아니라 1이 있으면 1을 출력한다.     
	
	- &는 and의 의미를 담고 있는 기호이며, (num10 % mask) == 0이 맞다면 왼쪽의 printf("0")을, 아니라면 printf("1")을 출력하면 된다.     

```C
// 10진수를 2진수로 출력하기(비트연산자)
#include <stdio.h>

int main(void)
{
	unsigned int num10;		// 10진수를 입력받을 변수 num10을 생성한다. 음수가 아닌 값만 저장하기 때문에 unsigned를 붙인다.
	printf("10 진수 : ");	// 10진수를 입력받는다.
	scanf_s("%u", &num10);	// 입력받은 10진수의 값을 2진수로 저장한 값을 num10 변수에 저장한다.

	unsigned int mask = 1 << 7;	// 왼쪽으로 7비트 이동한다. mask = 10000000

	printf("2 진수 : ");		// 2진수를 입력한다.

	((num10 & mask) == 0) ? printf("0") : printf("1");	// num10과 mask의 2진수 값이 일치하면 0을, 일치하지 않다면 1을 출력한다.
	mask = mask >> 1;		// 오른쪽으로 1비트 이동한다.
	((num10 & mask) == 0) ? printf("0") : printf("1"); // num10과 mask의 2진수 값이 일치하면 0을, 일치하지 않다면 1을 출력한다.
	mask = mask >> 1;		// 오른쪽으로 1비트 이동한다.
	((num10 & mask) == 0) ? printf("0") : printf("1"); // num10과 mask의 2진수 값이 일치하면 0을, 일치하지 않다면 1을 출력한다.
	mask = mask >> 1;		// 오른쪽으로 1비트 이동한다.
	((num10 & mask) == 0) ? printf("0") : printf("1"); // num10과 mask의 2진수 값이 일치하면 0을, 일치하지 않다면 1을 출력한다.
	mask = mask >> 1;		// 오른쪽으로 1비트 이동한다.
	((num10 & mask) == 0) ? printf("0") : printf("1"); // num10과 mask의 2진수 값이 일치하면 0을, 일치하지 않다면 1을 출력한다.
	mask = mask >> 1;		// 오른쪽으로 1비트 이동한다.
	((num10 & mask) == 0) ? printf("0") : printf("1"); // num10과 mask의 2진수 값이 일치하면 0을, 일치하지 않다면 1을 출력한다.
	mask = mask >> 1;		// 오른쪽으로 1비트 이동한다.
	((num10 & mask) == 0) ? printf("0") : printf("1"); // num10과 mask의 2진수 값이 일치하면 0을, 일치하지 않다면 1을 출력한다.
	mask = mask >> 1;		// 오른쪽으로 1비트 이동한다.
	((num10 & mask) == 0) ? printf("0") : printf("1"); // num10과 mask의 2진수 값이 일치하면 0을, 일치하지 않다면 1을 출력한다.

	printf("\n");			// 줄 끝내기

	return 0;
}
```      

#### 13. 정수 연산 시의 자동적인 형변환

	- 정수 연산 시 char 형이나 short 형의 경우, 자동적으로 int 형으로 변환하여 계산한다.   
	
![TypeChange](https://github.com/BangYunseo/TIL/blob/main/C/Image/TypeChange.PNG)
	
	
	
	
	
	
