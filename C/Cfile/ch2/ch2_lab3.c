// 10������ 2������ ����ϱ�(��Ʈ������)
#include <stdio.h>

int main(void)
{
	unsigned int num10;		// 10������ �Է¹��� ���� num10�� �����Ѵ�. ������ �ƴ� ���� �����ϱ� ������ unsigned�� ���δ�.
	printf("10 ���� : ");	// 10������ �Է¹޴´�.
	scanf_s("%u", &num10);	// �Է¹��� 10������ ���� 2������ ������ ���� num10 ������ �����Ѵ�.

	unsigned int mask = 1 << 7;	// �������� 7��Ʈ �̵��Ѵ�. mask = 10000000

	/* ! ���߿� �� �� �� �� �����ؾ� �ϴ� ���� ! 
	���� mask�� 1�� ���� �����ϰ�, �������� 7��Ʈ�� �̵���Ű�� 
	mask = 00000001���� mask = 10000000�� �ȴ�. ���÷� �Է��ϴ� 10������ 32�ε�
	2������ �����ʺ��� 2�� 0��, 2�� 1��, ������, 2�� 7���� ��Ʈ�� ������. 
	�׷��� ������ 32�� 2������ ��Ÿ���� 00100000 �̴�. 
	�Ʒ��� ������ �������� 7��Ʈ �̵����״� ���� ���������� 1��Ʈ�� �̵���Ű�鼭 
	���÷� �Է��� num10�� ����� ���� 32�� 2���� 00100000�� 0�� ��ġ�� ������ 0�� ���,
	���࿡ 0�� �ƴ϶� 1�� ������ 1�� ����Ѵ�. &�� and�� �ǹ̸� ��� �ִ� ��ȣ�̸�,
	(num10 % mask) == 0�� �´ٸ� ������ printf("0")��, �ƴ϶�� printf("1")�� ����ϸ�
	�ȴ�. (github ch2 ����)
	*/

	printf("2 ���� : ");		// 2������ �Է��Ѵ�.

	((num10 & mask) == 0) ? printf("0") : printf("1");	// num10�� mask�� 2���� ���� ��ġ�ϸ� 0��, ��ġ���� �ʴٸ� 1�� ����Ѵ�.
	mask = mask >> 1;		// ���������� 1��Ʈ �̵��Ѵ�.
	((num10 & mask) == 0) ? printf("0") : printf("1"); // num10�� mask�� 2���� ���� ��ġ�ϸ� 0��, ��ġ���� �ʴٸ� 1�� ����Ѵ�.
	mask = mask >> 1;		// ���������� 1��Ʈ �̵��Ѵ�.
	((num10 & mask) == 0) ? printf("0") : printf("1"); // num10�� mask�� 2���� ���� ��ġ�ϸ� 0��, ��ġ���� �ʴٸ� 1�� ����Ѵ�.
	mask = mask >> 1;		// ���������� 1��Ʈ �̵��Ѵ�.
	((num10 & mask) == 0) ? printf("0") : printf("1"); // num10�� mask�� 2���� ���� ��ġ�ϸ� 0��, ��ġ���� �ʴٸ� 1�� ����Ѵ�.
	mask = mask >> 1;		// ���������� 1��Ʈ �̵��Ѵ�.
	((num10 & mask) == 0) ? printf("0") : printf("1"); // num10�� mask�� 2���� ���� ��ġ�ϸ� 0��, ��ġ���� �ʴٸ� 1�� ����Ѵ�.
	mask = mask >> 1;		// ���������� 1��Ʈ �̵��Ѵ�.
	((num10 & mask) == 0) ? printf("0") : printf("1"); // num10�� mask�� 2���� ���� ��ġ�ϸ� 0��, ��ġ���� �ʴٸ� 1�� ����Ѵ�.
	mask = mask >> 1;		// ���������� 1��Ʈ �̵��Ѵ�.
	((num10 & mask) == 0) ? printf("0") : printf("1"); // num10�� mask�� 2���� ���� ��ġ�ϸ� 0��, ��ġ���� �ʴٸ� 1�� ����Ѵ�.
	mask = mask >> 1;		// ���������� 1��Ʈ �̵��Ѵ�.
	((num10 & mask) == 0) ? printf("0") : printf("1"); // num10�� mask�� 2���� ���� ��ġ�ϸ� 0��, ��ġ���� �ʴٸ� 1�� ����Ѵ�.

	printf("\n");			// �� ������

	return 0;
}