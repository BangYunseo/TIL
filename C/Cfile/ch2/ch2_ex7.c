// 논리연산자 이해하기
#include <stdio.h>

int main(void)
{
	int num1, num2;		// 두 개의 정수를 입력받을 변수 num1, num2를 생성한다.

	printf("두 개의 정수를 입력하시오 : "); // 두 개의 정수를 입력받는다.
	scanf_s("%d %d", &num1, &num2);			// 입력받은 정수를 변수 num1과 num2에 저장한다.

	printf("%d && %d 의 결과값 : %d\n", num1, num2, num1 && num2);	
	// num1과 num2의 and 값을 출력한다. 두 값 중에서 0이 없으면 1을 출력한다.
	printf("%d || %d의 결과값 : %d\n", num1, num2, num1 || num2);
	// num1과 num2의 or 값을 출력한다. 두 값 중에서 하나라도 0이 아니라면 1을 출력한다.
	printf("!%d의 결과값 : %d\n", num1, !num1);
	// num1이 아닌 값을 출력한다. num1이 0이 아닌 값이라면, 0을 출력하고 num1이 0이라면 1을 출력한다.
	return 0;
}