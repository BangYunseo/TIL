#include <iostream>
#include <cstring>
#define _CRT_NO_SECURE_WARNINGS

using namespace std;

int main(void) {
	char password[11];
	cout << "���α׷��� �����Ϸ��� ��ȣ�� �Է��ϼ���. " << endl;

	while (true) {
		cout << "��ȣ >> ";
		cin >> password;

		if (strcmp(password, "C++") == 0) {
			cout << "���α׷��� ���� �����մϴ�. " << endl;
			break;
		}
		else {
			cout << "��ȣ�� Ʋ�Ƚ��ϴ�. " << endl;
		}
	}

	return 0;
}