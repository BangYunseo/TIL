#include <iostream>
#include <cstring>
#define _CRT_NO_SECURE_WARNINGS

using namespace std;

int main(void) {
	char ID[10], PW[10];
	cout << "���̵� �Է��ϼ���." << endl;
	while (true) {
		cout << "���̵� >> ";
		cin >> ID;
		if (strcmp(ID, "Bang") != 0)
			cout << "��ϵ��� ���� ���̵��Դϴ�." << endl;
		else
			break;
	}
	cout << "���α׷��� �����Ϸ��� ��ȣ�� �Է��ϼ���. " << endl;
	while (true) {
		cout << "��й�ȣ >> ";
		cin >> PW;
		if (strcmp(PW, "1234") == 0) {
			cout << "���α׷��� �����մϴ�." << endl;
			break;
		}
		else {
			cout << "��ȣ�� ��ġ���� �ʽ��ϴ�. " << endl;
		}
	}
}