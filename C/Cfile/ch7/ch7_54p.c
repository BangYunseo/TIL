// 54p : ��� ���ϱ�
#include <stdio.h>
#define STUDENTS 5		// �л��� ���ڸ� 5�� ����
int get_average(int scores[], int n);	// �Լ��� ���� ���

int main(void)
{
	int scores[STUDENTS] = { 1, 2, 3, 4, 5 };	// �迭�� �л��� ����ŭ �����ϰ� 1, 2, 3, 4, 5�� �ʱ�ȭ
	int avg;	// 	����� ������ ������ ����

	avg = get_average(scores, STUDENTS);	// ���� avg�� get_average �Լ��� ���� �����Ѵ�.
	printf("����� %d �Դϴ�.\n", avg);		// ����� ����Ѵ�.
	return 0;
}
int get_average(int scores[], int n)
{
	int i;		// for���� ����� ���� i�� �����Ѵ�.
	int sum = 0;	// �� �հ踦 ������ ���� sum�� �����ϰ� 0���� �ʱ�ȭ�Ѵ�.

	for (i = 0; i < n; i++)		// i�� 0���� �ʱ�ȭ�ϰ�, n���� ���� �� �϶����� i�� ���� 1�� ����
		sum += scores[i];		// �հ踦 �����ϴ� ���� sum�� scores�迭�� [i] ������� ���Ѵ�.
	return sum / n;			// �հ踦 ���� n���� ���� ���� ��ȯ�Ѵ�.
}