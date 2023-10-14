#include <iostream>
#define _CRT_NO_SECURE_WARNINGS

using namespace std;

int main(void) {
	cout << "이름을 입력하세요 >> ";

	char name[11];
	cin >> name;

	cout << "이름은 " << name << " 입니다." << endl;
	return 0;
}