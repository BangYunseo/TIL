// 45p : �����Ϳ� �迭
#include <stdio.h>

int main(void)
{
	int a[] = { 10, 20, 30, 40, 50 };
	// �迭 a�� �����ϰ� 10, 20, 30, 40, 50 ���� �ʱ�ȭ�Ѵ�.

	printf("&a[0] = %u\n", &a[0]);		// �迭 a[0]�� �ּҰ��� ����Ѵ�.
	printf("&a[1] = %u\n", &a[1]);		// �迭 a[1]�� �ּҰ��� ����Ѵ�.
	printf("&a[2] = %u\n", &a[2]);		// �迭 a[2]�� �ּҰ��� ����Ѵ�.

	printf("a = %u\n", a);		// �迭 a ��ü�� �ּҰ��� ����Ѵ�.
	// �迭 a ��ü�� �ּҰ��� a[0]�� �ּҰ��� ����.
}