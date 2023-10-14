#include <iostream>
#define _CRT_NO_SECURE_WARNINGS

using namespace std;

class Adder {
	int op1, op2;
public:
	Adder(int a, int b) { op1 = a; op2 = b; }
	int process() { return op1 + op2; }
};
class Calculator {
public:
	void run();
};
void Calculator::run() {
	cout << "두 개의 수를 입력하세요 >> ";
	int a, b;
	cin >> a >> b;
	Adder adder(a, b);
	cout << adder.process();
}
int main(void) {
	Calculator cal;
	cal.run();
}