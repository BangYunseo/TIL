// Lab 1 : ���� ���� �����ϱ�
#include <stdio.h>

void menu();			// menu() �Լ��� ���� ���
int save(int amount);	// save() �Լ��� ���� ���
int main(void)
{
	menu();	// menu()�Լ� ����

	save(10000);	// save(10000)�Լ� ����
	save(50000);	// save(50000)�Լ� ����
	save(-10000);	// save(-10000)�Լ� ����
	save(30000);	// save(30000)�Լ� ����

	printf("==================================\n"); // ���κ� ���

	return 0;
}
void menu()		// menu�� ����� �Լ� ����
{
	printf("==================================\n");
	printf("�Ա�\t���\t�ܰ�\t\n");
	printf("==================================\n");
}
int save(int amount)	// �Ա�, ���, �ܰ� ����� �Լ� ����
{
	static long balance = 0;
	// ���� ���� balance�� ����, ���� ������ save()�Լ��� �������� ���� ����ȴ�.
	// ��, ���� ���� balance�� �ܰ� �����ϴ� ����

	if (amount > 0)	// ���� amount�� ������ (�Ա�)
	{
		printf("%d \t \t", amount);	// �Ա� ĭ�� ���
	}
	else	// ���� amount�� ������� (���)
	{
		printf("\t%d \t", -amount);
		// ��� ĭ�� ����ϰ�, ����ϴ� ���� �����̹Ƿ� -�� ����
	}

	balance += amount;	// �ܰ� �Ա�, ��� ���� ����
	printf("%d \n", balance);	// �ܰ� ���
}