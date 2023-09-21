// 비트 연산자로 2의 보수 만들기
#include <stdio.h>

int main(void)
{
	int a = 32; // 변수 a를 생성하고 32를 저장한다.
	a = ~a;		// NOT 연산자로 a를 1의 보수로 만든다.
	// ~= 비트 NOT의 의미로 0은 1로 만들고 1은 0으로 만든다.
	a = a + 0x01;	// 0x01 = 1을 더한다.
	printf("a = %d\n", a);	// a를 출력한다.

	return 0;
}