#include <iostream>
#define _CRT_NO_SECURE_WARNINGS

using namespace std;

class Circle {
	int radius;
public:
	Circle() { radius = 1; cout << "반지름 " << radius << "인 원 생성" << endl; }
	Circle(int r) { radius = r; cout << "반지름 " << radius << "인 원 생성" << endl; }
	~Circle() { cout << "반지름 " << radius << "인 원 소멸" << endl; };
	double getArea() { return radius * radius * 3.14; }
};
int main(void) {
	Circle donut;
	Circle pizza(30);
	return 0;
}