// 39p : swap() �Լ� ����ϱ�
#include <stdio.h>
void swap(int x, int y);				// swap() �Լ��� ������ �̸� ����Ѵ�.

int main(void)
{
	int a = 100, b = 200;				// ���� a�� b�� �����ϰ� ���� 100, 200���� �ʱ�ȭ�Ѵ�.

	printf("a = %d\tb = %d\n", a, b);	// a�� b�� ����Ѵ�.
	swap(a, b);							// swap �Լ��� a�� b�� ���� �־� �����Ѵ�.
	printf("a = %d\tb = %d\n", a, b);	// a�� b�� ����Ѵ�.
	// �ּҰ��� �ٲ��� �ʾұ� ������ a�� b�� ���� swap�Լ��� �����ص� ���� �Ȱ���.

	return 0;
}
void swap(int x, int y)
{
	int tmp;							// �Ͻ����� ��������� ����� ���� tmp�� �����Ѵ�.
	printf("x = %d\ty = %d\n", x, y);	// x�� y�� ����Ѵ�.

	tmp = x;							// ���� tmp�� x�� ���� �����Ѵ�.
	x = y;								// x�� y�� ���� �����Ѵ�.
	y = tmp;							// y�� tmp�� ���� �����Ѵ�.
	// ���� �����ϸ鼭 ��ġ�� �ٲٴ� �˰���

	printf("x = %d\ty = %d\n", x, y);	// x�� y�� ����Ѵ�.
}