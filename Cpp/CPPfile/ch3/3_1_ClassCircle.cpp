#include <iostream>
#define _CRT_NO_SECURE_WARNINGS

using namespace std;

class Circle {
public:
	int radius;
	double getArea();
};
double Circle::getArea() {
	return radius * radius * 3.14;
}
int main(void) {
	Circle donut;
	donut.radius = 1;
	double area = donut.getArea();
	cout << "������ ������ " << area << endl;

	Circle pizza;
	pizza.radius = 30;
	area = pizza.getArea();
	cout << "������ ������ " << area << endl;

	return 0;
}