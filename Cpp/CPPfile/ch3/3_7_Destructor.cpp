#include <iostream>
#define _CRT_NO_SECURE_WARNINGS

using namespace std;

class Circle {
	int radius;
public:
	Circle() { radius = 1; cout << "������ " << radius << "�� �� ����" << endl; }
	Circle(int r) { radius = r; cout << "������ " << radius << "�� �� ����" << endl; }
	~Circle() { cout << "������ " << radius << "�� �� �Ҹ�" << endl; };
	double getArea() { return radius * radius * 3.14; }
};
int main(void) {
	Circle donut;
	Circle pizza(30);
	return 0;
}