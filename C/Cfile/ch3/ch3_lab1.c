//  lab1 : ��� ����
#include <stdio.h>

int main(void)
{
	int num1, num2, result;		// �Է¹��� ���ڸ� ������ ����, ������ ����� �����Ѵ�.
	char op;			// ������ ��������ڸ� ������ ������ �����Ѵ�.

	printf("������ �Է��Ͻÿ�.\n");
	printf("(�� : 2 + 5)\n");
	printf(">> ");

	scanf_s("%d %c %d", &num1, &op, 30, &num2);
	/* ����, ���������, ���� ������ �Է¹޴´�.
	(scanf_s�� %c�� �Ҵ��� �� �ڲ� ������ ���ܼ� �޸� ���� �����߽��ϴ�!)
	*/

	if (op == '+')
		result = num1 + num2;		// num1�� num2�� ���� ���� result�� �����Ѵ�.
	else if (op == '-')
		result = num1 - num2;		// num1�� num2�� ���� ���� result�� �����Ѵ�.
	else if (op == '*')
		result = num1 * num2;		// num1�� num2�� ���� ���� result�� �����Ѵ�.
	else if (op == '/')
		result = num1 / num2;		// num1�� num2�� ���� ���� result�� �����Ѵ�.
	else if (op == '%')
		result = num1 % num2;		// num1�� num2�� �������� ���� result�� �����Ѵ�.
	else
		printf("�������� �ʴ� �������Դϴ�.");
	// �������� �ʴ� �������� ����� ������� �ʴ´�.

	printf("%d %c %d = %d", num1, op, num2, result);
	// num1�� num2�� ������ ����Ѵ�.
	return 0;
}