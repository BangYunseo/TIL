#include <iostream>
#include <string>
#define _CRT_NO_SECURE_WARNINGS

using namespace std;

int main(void) {
	string song("Falling in love with you");
	string elvis("Elvis Presley");
	string singer;

	cout << song << "�� �θ� ������?(��Ʈ : ù ���ڴ� " << elvis[0] << ") >> ";
	getline(cin, singer);
	if (elvis == singer)
		cout << "�����Դϴ�." << endl;
	else
		cout << "�����Դϴ�. " << elvis << " �Դϴ�." << endl;
	return 0;
}