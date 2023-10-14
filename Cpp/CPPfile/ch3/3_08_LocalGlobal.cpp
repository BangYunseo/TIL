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
	~Circle() {
		cout << "반지름 " << radius << "인 원 소멸" << endl;
	}
	double getArea() {
		return radius * radius * 3.14;
	}
};
Circle globalDonut(1000);
Circle globalPizza(2000);
void f() {
	Circle fDonut(100);
	Circle fPizza(200);
}
int main(void) {
	Circle mainDonut;
	Circle mainPizza(30);
	f();
	return 0;
}
