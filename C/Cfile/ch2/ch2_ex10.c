// ��Ʈ �����ڷ� 2�� ���� �����
#include <stdio.h>

int main(void)
{
	int a = 32; // ���� a�� �����ϰ� 32�� �����Ѵ�.
	a = ~a;		// NOT �����ڷ� a�� 1�� ������ �����.
	// ~= ��Ʈ NOT�� �ǹ̷� 0�� 1�� ����� 1�� 0���� �����.
	a = a + 0x01;	// 0x01 = 1�� ���Ѵ�.
	printf("a = %d\n", a);	// a�� ����Ѵ�.

	return 0;
}