// 39p : swap() 함수 출력하기
#include <stdio.h>
void swap(int x, int y);				// swap() 함수의 원형을 미리 출력한다.

int main(void)
{
	int a = 100, b = 200;				// 변수 a와 b를 생성하고 각각 100, 200으로 초기화한다.

	printf("a = %d\tb = %d\n", a, b);	// a와 b를 출력한다.
	swap(a, b);							// swap 함수에 a와 b의 값을 넣어 실행한다.
	printf("a = %d\tb = %d\n", a, b);	// a와 b를 출력한다.
	// 주소값이 바뀌지 않았기 때문에 a와 b의 값은 swap함수에 실행해도 값이 똑같다.

	return 0;
}
void swap(int x, int y)
{
	int tmp;							// 일시적인 저장공간을 담당할 변수 tmp를 생성한다.
	printf("x = %d\ty = %d\n", x, y);	// x와 y를 출력한다.

	tmp = x;							// 변수 tmp에 x의 값을 저장한다.
	x = y;								// x에 y의 값을 저장한다.
	y = tmp;							// y에 tmp의 값을 저장한다.
	// 수를 보존하면서 위치를 바꾸는 알고리즘

	printf("x = %d\ty = %d\n", x, y);	// x와 y를 출력한다.
}