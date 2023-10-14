#include <iostream>
#define _CRT_NO_SECURE_WARNINGS

using namespace std;

double area(int r);

int main(void) {
	int n = 3;
	char c = '#';

	cout << c << 5.5 << '-' << n << " hello " << true << endl;
	cout << "n + 5 = " << n + 5 << endl;
	cout << "¸éÀûÀº " << area(n) << endl;
	return 0;
}
double area(int r) {
	return r * r * 3.14;
}
