// lab3 : ���� ���� ����(46p)
#include <stdio.h>

int main(void)	
{
	int answer = 59;		// ������ ������ ���� answer�� �����Ѵ�.
	int guess;				// ������ ���ڸ� ������ ���� guess�� �����Ѵ�.
	int tryy = 0;			// �õ� Ƚ���� ������ ���� tryy�� �����Ѵ�. 

	do{	
		printf("������ �����Ͻÿ� : ");		// ������ ���ڸ� �Է¹޴´�.
		scanf_s("%d", &guess);				// �Է¹��� ���ڸ� ���� guess�� �����Ѵ�.
		tryy++;										
		// �õ�Ƚ���� 1ȸ �þ ������ 0���� �ʱ�ȭ��Ų �õ�Ƚ�� ������ 1�� ������Ų��.
		if (guess < answer)		// ������ ���ڰ� ���亸�� �۴ٸ� LOW�� ����Ѵ�.
			printf("LOW\n");
		if (guess > answer)		// ������ ���ڰ� ���亸�� ũ�ٸ� HIGH�� ����Ѵ�.
			printf("HIGH\n");
	} while (guess != answer);	// ������ ���ڰ� ����� ��ġ�ϸ� �ݺ��� �׸��д�.
	printf(" �����մϴ�. �õ�Ƚ�� = %d", tryy);	
	// ������ ��ġ�ϸ� �õ�Ƚ���� ����Ѵ�.

	return 0;
}