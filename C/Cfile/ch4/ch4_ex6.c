// ex6 : ���ڵ��� �� ���ϱ�
#include <stdio.h>

int main(void)
{
	int number, sum = 0;		
	// ������ ������ ���� number�� �������� ���� ������ ���� sum�� �����Ѵ�.

	do {
		printf("������ �Է��Ͻÿ� : ");		// ������ �Է¹޴´�.
		scanf_s("%d", &number);				// �Է¹��� ������ ���� number�� �����Ѵ�.
		sum += number;						// ���� sum�� �Է¹��� ������ ���Ѵ�.
	} while (number != 0);					// �Է¹��� ���ڰ� 0�̸� while���� �����Ѵ�.

	printf("���ڵ��� �� : %d", sum);		// ���ڵ��� ���� ����Ѵ�.
	return 0;
}