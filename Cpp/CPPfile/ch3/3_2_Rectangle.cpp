#include <iostream>
#define _CRT_NO_SECURE_WARNINGS

using namespace std;

class Rectangle {
public:
	int width;
	int height;
	double getArea();
};
double Rectangle::getArea() {
	return width * height;
}
int main(void) {
	Rectangle rect;
	rect.width = 3;
	rect.height = 5;
	cout << "�簢���� ������ " << rect.getArea() << endl;
	return 0;
}