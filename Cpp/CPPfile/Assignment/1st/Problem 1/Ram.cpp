#include <iostream>
#define _CRT_SECURE_NO_WARNINGS

using namespace std;

#include "Ram.h"

Ram::Ram() {
	size = 100 * 1024;
	for (int i = 0; i < size; i++) 
		mem[i] = 0;
}
Ram::~Ram() {
	cout << "¸Þ¸ð¸® Á¦°ÅµÊ" << endl;
}
char Ram::read(int address) {
	return mem[address];
}
void Ram::write(int address, char value) {
	mem[address] = value;
}
