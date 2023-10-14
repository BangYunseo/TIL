#include <iostream>
#define _CRT_NO_SECURE_WARNINGS

using namespace std;

int main(void) {
	char address[100];
	cout << "주소를 입력하세요 >> ";
	cin.getline(address, 100, '\n');
	cout << "주소는 " << address << " 입니다." << endl;
	return 0;
}