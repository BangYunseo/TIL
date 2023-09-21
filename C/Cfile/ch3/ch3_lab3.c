// lab3 : 산술계산기(switch문 이용)
#include <stdio.h>

int main(void)
{
	int num1, num2, result;		// 숫자를 저장할 변수를 생성한다.
	char op;					// 산술연산자를 저장할 변수를 생성한다.

	printf("수식을 입력하세요.\n");
	printf("(예 : 2 + 5)\n");
	printf(">>");				// 수식을 입력받는다.

	scanf_s("%d %c %d", &num1, &op, 50, &num2);		
	// 입력받은 값을 각각 변수 num1, op, num2에 저장한다.
	// scanf_s의 오류?가 있는 것 같아 메모리를 직접 할당했습니다.

	switch (op)
	{
	case '+': result = num1 + num2;	break;		
		// 변수 op에 +가 입력되면 두 숫자를 더한다.
	case '-': result = num1 - num2;	break;
		// 변수 op에 -가 입력되면 두 숫자를 뺀다.
	case '/': result = num1 / num2;	break;
		// 변수 op에 +가 입력되면 두 숫자를 나눈다.
	case '*': result = num1 * num2;	break;
		// 변수 op에 +가 입력되면 두 숫자를 곱한다.
	case '%': result = num1 % num2;	break;
		// 변수 op에 +가 입력되면 두 숫자의 나머지를 구한다.
	default: printf("지원하지 않는 연산자입니다."); break;
		// +, -, /, *, %를 제외한 연산자가 입력된다면, 지원하지 않는 연산자를 입력받았다고 출력한다.
	}
	printf("%d %c %d = %d", num1, op, num2, result);
	// 값을 수식에 맞춰서 출력한다.

	return 0;
}