#include <iostream>
#define _CRT_SECURE_NO_WARNINGS

using namespace std;

#include "Ram.h"

int main() {
	Ram ram;
	ram.write(100, 20);
	ram.write(101, 30);
	char res = ram.read(100) + ram.read(101);
	ram.write(102, res);
	cout << "102 ¹øÁöÀÇ °ª = " << (int)ram.read(102) << endl;
}
