// ex4 : �Է¹��� ���������� ¦������ �� ���ϱ� 
#include <stdio.h>

int main(void)
{
	int i, n, sum;		
	// ¦�������� ���� ������ ���� i, �Է¹��� ���� n�� ���� ������ ���� sum�� �����Ѵ�. 

	printf("������ �Է��Ͻÿ� : ");		// ������ �Է¹޴´�.
	scanf_s("%d", &n);					// �Է¹��� ������ ���� n�� �����Ѵ�.

	i = 0;						// ���� i�� 0���� �ʱ�ȭ�Ѵ�.
	sum = 0;					// ���� sum�� 0���� �ʱ�ȭ�Ѵ�.

	while (i <= n)				// i <= n�� ������ �ݺ����� �ݺ��Ѵ�.
	{
		sum += i;				// ���� i�� ���� sum�� ���Ѵ�.
		i = i + 2;				// ¦���� ������ ���� ���ϱ� ���� i�� 2�� ���Ѵ�.
	}
	printf("1���� %d������ ¦������ %d �Դϴ�.\n", n, sum);		// �Է¹��� ������ ���� ����Ѵ�.
	return 0;
}