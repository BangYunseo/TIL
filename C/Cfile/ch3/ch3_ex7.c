#include <stdio.h>

int main(void)
{
	char lecture;		// ���ڸ� �Է¹��� ������ �����Ѵ�.

	printf("���ڸ� �Է��Ͻÿ� : ");		// ���ڸ� �Է¹޴´�.
	lecture = getchar();				
	// ���� lecture�� ���ڸ� �Է¹޴´�. 
	// scanf�� �ƴϴ��� getchar()�Լ��� �̿��ؼ� ���ڸ� �Է¹��� �� �ִ�.


	// ���� ������ �ƽ�Ű�ڵ带 �����ϸ� ����.
	if ((lecture >= 'A') && (lecture <= 'Z'))
		printf("%c�� �빮���Դϴ�.\n", lecture);		// A~Z�� ���ڸ� �Է¹����� �빮�ڶ�� ����Ѵ�.
	else if ((lecture >= 'a') && (lecture <= 'z'))
		printf("%c�� �ҹ����Դϴ�.\n", lecture);		// a~z�� ���ڸ� �Է¹����� �ҹ��ڶ�� ����Ѵ�.
	else if ((lecture >= '0') && (lecture <= '9'))
		printf("%c�� �����Դϴ�.\n", lecture);			// 0~9�� ���ڸ� �Է¹����� ���ڶ�� ����Ѵ�.
	else
		printf("%c�� ��Ÿ�����Դϴ�.\n", lecture);	
	// ���� ��� ���뿡�� �ش���� ������ ��Ÿ���ڶ�� ����Ѵ�.

	return 0;
}