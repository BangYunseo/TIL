#include <iostream>
#define _CRT_NO_SECURE_WARNINGS

using namespace std;

struct StructCircle {
private:
	int radius;
public:
	StructCircle(int r) { radius = r; }
	double getArea();
};
double StructCircle::getArea() {
	return 3.14 * radius * radius;
}
int main(void) {
	StructCircle waffle(3);
	cout << "������ " << waffle.getArea();
	return 0;
}