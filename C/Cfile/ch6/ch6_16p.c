// 16page : ���������� �ʱⰪ�� ���� �Ⱓ
#include <stdio.h>

int A;		// �������� A ����
int B;		// �������� B ����
int add();	// �Լ� add()�� ���� ���

int main(void)
{
	int answer;		// ���� ������ ���� ����
	A = 5;			// ���� A�� 5�� ����
	B = 7;			// ���� B�� 7�� ����	

	answer = add();	// ���� answer�� add()�Լ��� ���� ����

	printf("%d + %d = %d\n", A, B, answer);	// A�� B�� ���� ���
	return 0;
}
int add()
{
	return A + B;		// A �� B�� ���� ��ȯ
}