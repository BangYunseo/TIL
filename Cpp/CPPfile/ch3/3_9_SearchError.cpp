// 어느 번호에서 오류가 발생하는지 고르는 문제
#include <iostream>
#define _CRT_NO_SECURE_WARNINGS

using namespace std;

class PrivateAccessError {
private:
	int a;
	void f();
	PrivateAccessError();
public:
	int b;
	void g();
	PrivateAccessError(int x);
};
PrivateAccessError::PrivateAccessError() {
	a = b = 1;		// (1)
}
PrivateAccessError::PrivateAccessError(int x) {
	a = b = x;		// (2)
}
void PrivateAccessError::f() {
	a = b = 5;		// (3)
}
void PrivateAccessError::g() {
	a = b = 6;		// (4)
}
int main() {
	PrivateAccessError A;			// (5)
	PrivateAccessError B(100);		// (6)
	B.a = 10;						// (7)
	B.b = 20;						// (8)
	B.f();							// (9)
	B.g();							// (10)
}