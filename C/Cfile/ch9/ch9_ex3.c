// ex3 : ���� 3
#include <stdio.h>
#define SIZE 3		// SIZE�� 3���� ����

struct student	// ����ü student�� �����Ѵ�.
{
	int number;			// ������ �������� �й��� ������ ���� number�� �����Ѵ�.
	char name[10];		// ������ �迭���� �̸��� ������ �迭 name[10]�� �����Ѵ�.
	double grade;		// �Ǽ��� �������� ������ ������ ���� grade�� �����Ѵ�.
};
int main(void)
{
	struct student list[SIZE];		// ����ü student�� SIZE�� ũ�⸸ŭ �迭�� �����Ѵ�.
	int i;		// for���� ����� ���� i�� �����Ѵ�

	for (i = 0; i < SIZE; i++)		// SIZE�� ũ�⸸ŭ for���� �ݺ��Ѵ�. = 3�� �ݺ�
	{
		printf("�й��� �Է��ϼ��� : ");			// �й��� �Է¹޴´�.
		scanf_s("%d", &list[i].number);
		// �Է¹��� �й��� list[i]��°�� ���� number�� �����Ѵ�.
		// ���� i = 0�̶��, list[0].number�� �Է¹��� �й��� ����

		printf("�̸��� �Է��ϼ��� : ");			// �̸��� �Է¹޴´�.
		scanf_s("%s", list[i].name, 16);
		// �Է¹��� �̸��� list[i]��°�� �迭 name�� �����Ѵ�.
		// ���� i = 0�̶��, list[0].name�� �Է¹��� �̸��� ����
		// �̸��� ó������ �迭�� ���������Ƿ� &�� ������ ����

		printf("������ �Է��ϼ��� : ");			// ������ �Է¹޴´�.
		scanf_s("%lf", &list[i].grade);
		// �Է¹��� ������ list[i]��°�� ���� grade�� �����Ѵ�.
		// ���� i = 0�̶��, list[0].grade�� �Է¹��� ������ ����
	}

	for (i = 0; i < SIZE; i++)		// SIZE�� ũ�⸸ŭ for���� �ݺ��ϴ� = 3�� �ݺ�
		printf("�й� : %d, �̸� : %s, ���� : %lf\n", list[i].number, list[i].name, list[i].grade);
	// ���� �ٸ� �й�, �̸�, ������ 3�� �����
	return 0;
}