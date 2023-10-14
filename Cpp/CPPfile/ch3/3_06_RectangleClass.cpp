#include <iostream>
#define _CRT_NO_SECURE_WARNINGS

using namespace std;

class Rectangle {
public:
	int width, height;

	Rectangle() { width = height = 1; }
	Rectangle(int c) { width =  height = c; }
	Rectangle(int a, int b) { width = a; height = b; }
	bool isSquare() {
		if (width == height)
			return 1;
		else
			return 0;
	}
};
int main(void) {
	Rectangle rect1;
	Rectangle rect2(3, 5);
	Rectangle rect3(3);

	if (rect1.isSquare())
		cout << "rect1은 정사각형이다." << endl;
	if (rect2.isSquare())
		cout << "rect2은 정사각형이다." << endl;
	if (rect3.isSquare())
		cout << "rect3은 정사각형이다." << endl;
	return 0;
}
