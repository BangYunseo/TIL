#include <stdio.h>

int main(void)
{
	double LightSpeed = 300000;		// ���� �ӵ� 30�� km�� ������ �����Ѵ�.
	double Distance = 149600000;	// �¾�� ���� ������ �Ÿ� 1�� 4960�� km�� ������ �����Ѵ�.
	double Time; // ���� �ð��� ������ ������ �����Ѵ�.

	Time = Distance / LightSpeed;	// �¾�� ���� ������ �Ÿ��� ���� �ӵ��� ������.	
	Time = Time / 60.0;				// �ð��� �� ������ �����ϱ� ���� 60���� ������.

	printf("���� �ӵ��� : %lf km/s\n", LightSpeed);	// ���� �ӵ��� ����Ѵ�.
	printf("�¾�� �������� �Ÿ��� : %lf km\n", Distance);	// �¾�� ���� ������ �Ÿ��� ����Ѵ�.
	printf("���� �ð��� : %lf ��\n", Time);			// �� ������ ������ �ð��� ����Ѵ�.
	
	return 0;
}
