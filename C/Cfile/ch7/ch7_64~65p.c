// 64-65p : ���� ����
#include <stdio.h>
#define SIZE 10		// SIZE�� 10���� �����Ѵ�.

int main(void)
{
	int list[SIZE] = { 3, 2, 9, 7, 1, 4, 8, 0, 6, 5 };		// �迭 list�� �����ϰ� ũ�⸦ SIZE�� ���� �� �ʱ�ȭ�Ѵ�.
	int i, j, temp, least;
	// for���� ����� ���� i, j�� �ּڰ��� index�� ������ ���� least,
	// �ּڰ��� �ӽ÷� ������ ���� temp�� �����Ѵ�.

	for (i = 0; i < SIZE - 1; i++)
		// i�� 0���� �ʱ�ȭ�ϰ� i���� SIZE - 1���� �ݺ��ϸ鼭 1�� ����
		// 0���� 8���� �� 9�� �ݺ�
	{
		least = i;	// �ּڰ��� index�� 0���� �ʱ�ȭ�� ���� i�� ������
		for (j = i + 1; j < SIZE; j++)	// j�� i+1�� �ʱ�ȭ�ϰ�, j�� SIZE���� �ݺ��ϸ鼭 1�� ����
		{
			if (list[j] < list[least])		// ���� list[j]�� ���� list[least]���� ���� ��,
				least = j;					// least�� j�� �����Ѵ�.
		}
		temp = list[i];			// temp�� list[i]�� �����Ѵ�.
		list[i] = list[least];	// list[i]�� �ּڰ� list[least]�� �����Ѵ�.
		list[least] = temp;		// list[least]�� �ٽ� temp���� �����Ѵ�.
		// ���ڸ� ����� �ʰ� �ٲٴ� �˰���
	}
	printf("���ĵ� �迭\n");		// ���ĵ� �迭�� ����Ѵ�.
	for (i = 0; i < SIZE; i++)	// i�� 0���� �ʱ�ȭ�ϰ�, SIZE���� ���� ������ i�� ���� 1�� ����
		printf("%d ", list[i]);		// �迭�� ���� index������� ���
	printf("\n");	// �ٹٲ�

	return 0;
}