#include <stdio.h>
#define SQMETER_PER_PYEONG 3.3058	// 1���� 3.3 �������ͷ� �����Ѵ�.

int main(void)
{
	double Pyeong, result = 0;		// ���� ������ ������ ������� ������ ������ �����Ѵ�.

	printf("���� �Է��ϼ��� : ");		// ���� �Է¹޴´�.
	scanf_s("%lf", &Pyeong);			// �Է¹��� ���� ������ �����Ѵ�.

	result = Pyeong * SQMETER_PER_PYEONG; // ������� ����Ѵ�.

	printf("%lf�������Դϴ�.\n", result); //������� ����Ѵ�.
	return 0;
}