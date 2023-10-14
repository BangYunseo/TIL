#include <iostream>
#define _CRT_NO_SECURE_WARNINGS

using namespace std;

class Circle {
public:
	int radius;
	Circle(){}
	double getArea() { return radius * radius * 3.14; }
};
class Rectangle {
public:
	int width, height;
	Rectangle(){}
	int getArea() { return width * height; }
};
class Triangle {
public:
	int width, height;
	Triangle(){}
	double getArea() { return width * height * 0.5; }
};
int main(void) {
	Circle donut;
	donut.radius = 1;
	double area = donut.getArea();
	cout << "������ ������ " << area << endl;

	Circle pizza;
	pizza.radius = 30;
	area = pizza.getArea();
	cout << "������ ������ " << area << endl;

	Rectangle rect;
	rect.width = 3;
	rect.height = 5;
	cout << "�簢���� ������ " << rect.getArea() << endl;

	Triangle tri;
	tri.width = 7;
	tri.height = 5;
	cout.precision(2);
	cout << "�ﰢ���� ������ " << fixed << tri.getArea() << endl;

	// https://velog.io/@nada_dbstkddl/C-%EC%86%8C%EC%88%98%EC%9E%90%EB%A6%AC%EC%88%98-%EB%8B%A4%EB%A3%A8%EA%B8%B0-precision-fixed
	return 0;
}