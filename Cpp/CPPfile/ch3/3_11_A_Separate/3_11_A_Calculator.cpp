#include <iostream>
#define _CRT_NO_SECURE_WARNINGS

using namespace std;
#include "Adder.h"
#include "Calculator.h"

void Calculator::run() {
	cout << "두 개의 수를 입력하세요 >> ";
	int a, b;
	cin >> a >> b;
	Adder adder(a, b);
	cout << adder.process();
}