// Lab3 : �ּڰ� ã��
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 10		// �迭�� ũ�⸦ 10���� �����Ѵ�.

int main(void)
{
	srand((unsigned)time(NULL));	// ������ �߻���Ų��.

	int prices[SIZE] = { 0 };	// ���� ������ �迭�� SIZE ũ�⸸ŭ �����ϰ�, 0���� �ʱ�ȭ�Ѵ�.
	int i, minimum;		// �迭�� ����� ���� i�� �ּڰ��� �����ϸ鼭 ������ ������ �����Ѵ�.

	printf("---------------------------\n");
	printf("1 2 3 4 5 6 7 8 9 10\n");				// 10���� ���ڸ� ����� �޴� ���
	printf("---------------------------\n");

	for (i = 0; i < SIZE; i++)	// �迭�� ũ�⸸ŭ �ݺ��Ѵ�.
	{
		prices[i] = (rand() % 100) + 1;		// �迭�� �� ���� 1 ~ 100������ ���� �����Ѵ�.
		printf("%d ", prices[i]);			// �� �迭�� ����Ѵ�.
	}
	printf("\n");		// �ٹٲ�

	minimum = prices[0];	// �ϴ� �ּڰ��� ù ��° ������ �����Ѵ�. for�� �ȿ� �� �ʿ� X
	for (i = 0; i < SIZE; i++)	// �迭�� ũ�⸸ŭ �ݺ��Ѵ�.
	{
		if (prices[i] < minimum)	// ���� prices[i]�� ���� ���� �ּڰ����� �۴ٸ�
			minimum = prices[i];	// ���� �ּڰ��� prices[i]�� �����Ѵ�.
	}

	printf("�ּҰ��� %d �Դϴ�.\n", minimum);	// �ּڰ��� ����Ѵ�.

	return 0;
}