#include <iostream>
#define _CRT_NO_SECURE_WARNINGS

using namespace std;

double getArea(int x, int y);

int main(void) {
	cout << "�ʺ� �Է��ϼ��� >> ";

	int width;
	cin >> width;

	cout << "���̸� �Է��ϼ��� >> ";

	int height;
	cin >> height;

	cout << "������ " << getArea(width, height) << endl;
	// �緮���� �Լ��� �Ἥ ����غ�

	// ���� �ڵ�
	// int area = width * height;
	// cout << "������ " << area << endl;
	return 0;
}
double getArea(int x, int y) {
	int area = x * y;
	return area;
}