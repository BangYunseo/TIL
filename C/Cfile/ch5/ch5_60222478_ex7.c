#include <stdio.h>

int com_num(int n, int m);					// �Լ� com_num�� �����Ϸ��� �̸� �˸���.
int fact_num(int n);						// �Լ� fact_num�� �����Ϸ��� �̸� �˸���.
int get_num(void);							// �Լ� get_num�� �����Ϸ��� �̸� �˸���.


int main(void)
{
	int a, b;								// ����� ���� a�� b�� �����Ѵ�.
		
	a = get_num();							// ���� a�� ���ڸ� �Է¹޴´�.
	b = get_num();							// ���� b�� ���ڸ� �Է¹޴´�.
		
	printf("C(%d, %d) = %d \n", a, b, com_num(a, b));	// ������ ����Ѵ�.
	return 0;
}
int get_num(void)						// ���� ���ϴ� �Լ�
{
	int n;								// ���� n�� �����Ѵ�.

	printf("������ �Է��ϼ��� : ");		// ������ �Է¹޴´�.
	scanf_s("%d", &n);					// �Է¹��� ������ ���� n�� �����Ѵ�
	return n;							// n�� ��ȯ
}
int fact_num(int n)						// ���丮�� ���ϴ� �Լ�
{
	int i;								// ���� i�� ����
	long result = 1;					// ���丮�� ���� ������ ���� result�� �����ϰ� 1�� �ʱ�ȭ

	for (i = 1; i <= n; i++)			// i�� n���� �۰ų� ���� ��, i�� ���� 1�� ���ϸ鼭 for�� �ݺ�
		result = result * i;			// result�� i�� ���ϸ鼭 ����
	return result;						// result�� ��ȯ
}
int com_num(int n, int m)				// ���� ���ϴ� �Լ�
{
	return (fact_num(n) / (fact_num(m) * fact_num(n - m)));		// ���� n�� m�� ������ ��ȯ
}