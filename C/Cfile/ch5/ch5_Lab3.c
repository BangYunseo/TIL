#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
	int n;								// �ζ� ��ȣ ���� Ȯ���� ���� n ����
	srand((unsigned)time(NULL));		// �� ��ɾ �Է��ؾ�, ������ �߻���ų �� ����. (�õ弳��)
	
	for (n = 0; n < 6; n++)				// n�� 0���� �ʱ�ȭ�ϰ�, 6�� �Ǳ� ������ n�� ���� 1�� ���ϸ鼭 for���� �ݺ�
		printf("%d ", 1 + rand() % 45);	// 1���� 45������ ���ڸ� ������ �����ϰ�, 6���� ���� ����Ѵ�.
	
	return 0;
}