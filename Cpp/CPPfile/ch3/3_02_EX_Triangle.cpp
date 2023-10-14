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
	cout << "도넛의 면적은 " << area << endl;

	Circle pizza;
	pizza.radius = 30;
	area = pizza.getArea();
	cout << "피자의 면적은 " << area << endl;

	Rectangle rect;
	rect.width = 3;
	rect.height = 5;
	cout << "사각형의 면적은 " << rect.getArea() << endl;

	Triangle tri;
	tri.width = 7;
	tri.height = 5;
	cout.precision(2);
	cout << "삼각형의 면적은 " << fixed << tri.getArea() << endl;

	// https://velog.io/@nada_dbstkddl/C-%EC%86%8C%EC%88%98%EC%9E%90%EB%A6%AC%EC%88%98-%EB%8B%A4%EB%A3%A8%EA%B8%B0-precision-fixed
	return 0;
}
