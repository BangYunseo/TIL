// ex15 : ����ũ ���� ����
#include <stdio.h>
#define SEED_MONEY 1000000

int main(void)
{
	int year = 0;				// �⵵�� ������ ������ 0���� �ʱ�ȭ�Ѵ�.
	int money = SEED_MONEY		// ���� ������ ������ SEED_MONEY�� �ʱ�ȭ�Ѵ�.

		while (1)				// break�� ���� ������ while���� ���� �ݺ��Ѵ�.
		{
			year++;				// �⵵�� 1�� ���Ѵ�.
			money += money * 0.30;		// money�� money�� 30�ۼ�Ʈ ���� ���Ѵ�.
			if (money > 10 * SEED_MONEY)		// ���� money�� ó���� �������ִ� �õ�Ӵ��� 10�谡 �Ǹ� �ݺ����� �����Ѵ�.
				break;							// �ݺ��� Ż�� ��ɾ�
		}
	printf("%d", year);						// �ɸ� �⵵�� ����Ѵ�.
	return 0;
}