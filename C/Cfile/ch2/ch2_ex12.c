// ����ȯ�Ǵ� �� Ȯ���ϱ�
#include <stdio.h>

int main(void)
{
	int i;			// ������ ���� i�� �����Ѵ�.
	double f;		// �Ǽ��� ���� f�� �����Ѵ�.

	f = 5 / 4;		
	/* ���������� ���� ���ϴ� ���� �Ǽ��� ���� f�� �����Ѵ�.
	�Ǽ��� ������ ����Ǳ� ������ ���� �Ǽ��� ǥ���ȴ�. */
	printf("%lf\n", f);		// f�� ����Ѵ�.

	f = (double)5 / 4;	
	// ����ȯ �����ڸ� 5�� ������ �ڿ� 5.0 / 4�� ����� ���� �Ǽ��� ���� f�� �����Ѵ�.
	printf("%lf\n", f);		// f�� ����Ѵ�.

	f = 5.0 / 4;	
	// 5.0 / 4�� ����Ѵ�. 5.0�� �ֱ� ������ ���� �Ǽ������� ����ȴ�.
	printf("%lf\n", f);		// f�� ����Ѵ�.

	f = (double)5 / (double)4;
	// 5.0 / 4.0�� �� ���� ����Ѵ�.
	printf("%lf\n", f);		// f�� ����Ѵ�.

	i = 1.3 + 1.8; 
	// 1.3�� 1.8�� ����� ��, �̸� ������ ���� i�� �����Ѵ�. ���� 3�� ����ȴ�.
	printf("%d\n", i);		// i�� ����Ѵ�.

	i = (int)1.3 + (int)1.8;
	/* 1.3�� 1.8 �տ� ����ȯ �����ڰ� �ֱ� ������, ���� 1�� ��ȯ�� �ڿ� ����Ѵ�.
	�׷��� ������ �� ���� 2�̴�. */
	printf("%d\n", i);		// i�� ����Ѵ�.
	

	return 0;
}