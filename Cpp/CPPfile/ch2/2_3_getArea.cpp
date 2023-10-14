#include <iostream>
#define _CRT_NO_SECURE_WARNINGS

using namespace std;

double getArea(int x, int y);

int main(void) {
	cout << "너비를 입력하세요 >> ";

	int width;
	cin >> width;

	cout << "높이를 입력하세요 >> ";

	int height;
	cin >> height;

	cout << "면적은 " << getArea(width, height) << endl;
	// 재량으로 함수를 써서 출력해봄

	// 원본 코드
	// int area = width * height;
	// cout << "면적은 " << area << endl;
	return 0;
}
double getArea(int x, int y) {
	int area = x * y;
	return area;
}