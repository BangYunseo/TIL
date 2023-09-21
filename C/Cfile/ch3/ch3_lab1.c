//  lab1 : 산술 계산기
#include <stdio.h>

int main(void)
{
	int num1, num2, result;		// 입력받을 숫자를 저장할 변수, 숫자의 계산을 생성한다.
	char op;			// 실행할 산술연산자를 저장할 변수를 생성한다.

	printf("수식을 입력하시오.\n");
	printf("(예 : 2 + 5)\n");
	printf(">> ");

	scanf_s("%d %c %d", &num1, &op, 30, &num2);
	/* 숫자, 산술연산자, 숫자 순서로 입력받는다.
	(scanf_s가 %c를 할당할 때 자꾸 오류가 생겨서 메모리 따로 지정했습니다!)
	*/

	if (op == '+')
		result = num1 + num2;		// num1과 num2의 합을 변수 result에 저장한다.
	else if (op == '-')
		result = num1 - num2;		// num1과 num2의 차을 변수 result에 저장한다.
	else if (op == '*')
		result = num1 * num2;		// num1과 num2의 곱을 변수 result에 저장한다.
	else if (op == '/')
		result = num1 / num2;		// num1과 num2의 몫을 변수 result에 저장한다.
	else if (op == '%')
		result = num1 % num2;		// num1과 num2의 나머지를 변수 result에 저장한다.
	else
		printf("지원되지 않는 연산자입니다.");
	// 지원하지 않는 연산자의 계산은 출력하지 않는다.

	printf("%d %c %d = %d", num1, op, num2, result);
	// num1과 num2의 연산을 출력한다.
	return 0;
}