// lab3 : �������(switch�� �̿�)
#include <stdio.h>

int main(void)
{
	int num1, num2, result;		// ���ڸ� ������ ������ �����Ѵ�.
	char op;					// ��������ڸ� ������ ������ �����Ѵ�.

	printf("������ �Է��ϼ���.\n");
	printf("(�� : 2 + 5)\n");
	printf(">>");				// ������ �Է¹޴´�.

	scanf_s("%d %c %d", &num1, &op, 50, &num2);		
	// �Է¹��� ���� ���� ���� num1, op, num2�� �����Ѵ�.
	// scanf_s�� ����?�� �ִ� �� ���� �޸𸮸� ���� �Ҵ��߽��ϴ�.

	switch (op)
	{
	case '+': result = num1 + num2;	break;		
		// ���� op�� +�� �ԷµǸ� �� ���ڸ� ���Ѵ�.
	case '-': result = num1 - num2;	break;
		// ���� op�� -�� �ԷµǸ� �� ���ڸ� ����.
	case '/': result = num1 / num2;	break;
		// ���� op�� +�� �ԷµǸ� �� ���ڸ� ������.
	case '*': result = num1 * num2;	break;
		// ���� op�� +�� �ԷµǸ� �� ���ڸ� ���Ѵ�.
	case '%': result = num1 % num2;	break;
		// ���� op�� +�� �ԷµǸ� �� ������ �������� ���Ѵ�.
	default: printf("�������� �ʴ� �������Դϴ�."); break;
		// +, -, /, *, %�� ������ �����ڰ� �Էµȴٸ�, �������� �ʴ� �����ڸ� �Է¹޾Ҵٰ� ����Ѵ�.
	}
	printf("%d %c %d = %d", num1, op, num2, result);
	// ���� ���Ŀ� ���缭 ����Ѵ�.

	return 0;
}