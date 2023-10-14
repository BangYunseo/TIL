#include <iostream>
#include <string>
#define _CRT_NO_SECURE_WARNINGS

using namespace std;

int main(void) {
	string ID, PW;
	cout << "아이디를 입력하세요." << endl;
	while (true) {
		cout << "아이디 >> ";
		getline(cin, ID);
		if (ID != "Bang")
			cout << "등록되지 않은 아이디입니다." << endl;
		else
			break;
	}
	cout << "프로그램을 종료하려면 암호를 입력하세요. " << endl;
	while (true) {
		cout << "비밀번호 >> ";
		getline(cin, PW);
		if (PW == "1234") {
			cout << "프로그램을 종료합니다. " << endl;
			break;
		}
		else 
			cout << "암호가 일치하지 않습니다." << endl;
	}
}