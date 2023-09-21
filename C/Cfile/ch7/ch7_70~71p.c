// 70~71p: ���� Ž��
#include <stdio.h>
#define SIZE 16		// �迭�� ũ�⸦ 16���� ����
int binary_search(int list[], int n, int key);	// �Լ��� ���� 

int main(void)
{
	int key;		// Ž���� ���� �Է¹��� ���� ����
	int grade[SIZE] = { 2, 6, 11, 13, 18, 20, 22, 27, 29, 30, 34, 38, 41, 42, 45, 47 };	
	// �迭�� SIZE ũ�⸸ŭ �����ϰ� �ʱ�ȭ

	printf("Ž���� ���� �Է��ϼ��� : ");		// Ž���� ���� �Է¹���
	scanf_s("%d", &key);		// �Է¹��� Ž���� ���� ���� key�� ����
	printf("Ž�� ��� = %d\n", binary_search(grade, SIZE, key));
	// Ž�� ����� ����Ѵ�. grade�� �迭 ���θ� �����Ѵ�.

	return 0;
}
int binary_search(int list[], int n, int key)
{
	int low, high, middle;		// Ž���� �ε��� ���� ���� ���� ��, ���� ū ��, �߰� ���� ������ ���� ����
	low = 0;		// ���� ���� �ε��� ���� 0���� �ʱ�ȭ
	high = n - 1;	// ���� ū �ε��� ���� n-1�� �ʱ�ȭ
	while (low <= high)	// low���� high������ �۰ų� ���� ���� �ݺ�
	{
		printf("[%d %d]\n", low, high);		// low�� high���� ������ ���
		middle = (low + high) / 2;			// �߰� �ε��� ���� low�� high�� �տ� 2�� ���� �ε��� ���� ����
		if (key == list[middle])		// ���� key���� �迭�� �߰����� ��ġ�ϴٸ�
			return middle;				// Ž�� ���� �߰��� �ε����� ��ȯ
		else if (key > list[middle])	// ���� key���� �迭�� �߰������� ũ�ٸ�
			low = middle + 1;			// low�� �߰� �ε��� ���� 1�� ���� ���� ����
		else                            // ���� key���� �迭�� �߰������� �۴ٸ�
			high = middle - 1;			// high�� �߰� �ε��� ���� 1�� �� ���� ����
	}
	return -1;
}