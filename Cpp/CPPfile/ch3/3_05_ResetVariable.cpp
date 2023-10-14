#include <iostream>
#define _CRT_NO_SECURE_WARNINGS

using namespace std;

class Point {
	int x, y;
public:
	Point();
	Point(int a, int b);
	void show() { cout << "(" << x << ", " << y << ")" << endl; }
};
Point::Point() : Point(0, 0){}
Point::Point(int a, int b) {
	x = a;
	y = b;
}
int main(void) {
	Point origin;
	Point target(10, 20);
	origin.show();
	target.show();
}
