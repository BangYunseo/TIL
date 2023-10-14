#include <iostream>
#define _CRT_NO_SECURE_WARNINGS

using namespace std;

class Circle {
public:
	int radius;
	Circle() {
		radius = 1;
		cout << "반지름 " << radius << "인 원 생성" << endl;
	}
	Circle(int r) { 
		radius = r;
		cout << "반지름 " << radius << "인 원 생성" << endl;
	}
	double getArea(){
		return radius * radius * 3.14;
	}
};
int main(void) {
	Circle donut;
	double area = donut.getArea();
	cout << "도넛의 면적은 " << area << endl;

	Circle pizza(30);
	area = pizza.getArea();
	cout << "피자의 면적은 " << area << endl;
	return 0;
}