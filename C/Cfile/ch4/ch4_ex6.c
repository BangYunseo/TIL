// ex6 : 숫자들의 합 구하기
#include <stdio.h>

int main(void)
{
	int number, sum = 0;		
	// 정수를 저장할 변수 number과 정수들의 합을 저장할 변수 sum을 생성한다.

	do {
		printf("정수를 입력하시오 : ");		// 정수를 입력받는다.
		scanf_s("%d", &number);				// 입력받은 정수를 변수 number에 저장한다.
		sum += number;						// 변수 sum에 입력받은 정수를 더한다.
	} while (number != 0);					// 입력받은 숫자가 0이면 while문을 종료한다.

	printf("숫자들의 합 : %d", sum);		// 숫자들의 합을 출력한다.
	return 0;
}