#include <iostream>
#include <string>
#define _CRT_NO_SECURE_WARNINGS

using namespace std;

int main(void) {
	string ID, PW;
	cout << "���̵� �Է��ϼ���." << endl;
	while (true) {
		cout << "���̵� >> ";
		getline(cin, ID);
		if (ID != "Bang")
			cout << "��ϵ��� ���� ���̵��Դϴ�." << endl;
		else
			break;
	}
	cout << "���α׷��� �����Ϸ��� ��ȣ�� �Է��ϼ���. " << endl;
	while (true) {
		cout << "��й�ȣ >> ";
		getline(cin, PW);
		if (PW == "1234") {
			cout << "���α׷��� �����մϴ�. " << endl;
			break;
		}
		else 
			cout << "��ȣ�� ��ġ���� �ʽ��ϴ�." << endl;
	}
}