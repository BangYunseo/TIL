// 26page : ���� ���� ������ static
#include <stdio.h>

void sub();	// �Լ� sub()�� ���� ���
int main(void)
{
	sub();
	sub();
	sub();
	// �Լ� sub()�� 3�� ����
	return 0;
}
void sub()
{
	static int scount = 0;
	// static �� ���� ���� �����μ� sub()�Լ��� ����Ǵ��� �ڵ����� �Ҹ���� ����
	// �� ���� ��� �����

	int acount = 0;
	// ���� ���� ���� ������ �ٸ� �Ϲ����� �������� account�� ����

	printf("scount = %d\t", scount);
	// scount�� ���� ����ϰ� �Ǹ�ŭ ��
	printf("acount = %d\n", acount);
	// acount�� �� ���

	scount++;	// scount�� �� 1 ����
	acount++;	// acount�� �� 1 ����
}