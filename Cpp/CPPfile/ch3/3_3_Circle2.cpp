#include <iostream>
#define _CRT_NO_SECURE_WARNINGS

using namespace std;

class Circle {
public:
	int radius;
	Circle() {
		radius = 1;
		cout << "������ " << radius << "�� �� ����" << endl;
	}
	Circle(int r) { 
		radius = r;
		cout << "������ " << radius << "�� �� ����" << endl;
	}
	double getArea(){
		return radius * radius * 3.14;
	}
};
int main(void) {
	Circle donut;
	double area = donut.getArea();
	cout << "������ ������ " << area << endl;

	Circle pizza(30);
	area = pizza.getArea();
	cout << "������ ������ " << area << endl;
	return 0;
}