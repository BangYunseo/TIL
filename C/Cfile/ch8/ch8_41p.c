// 41p : swap() 함수 출력하기(#2)
#include <stdio.h>
void swap(int *px, int *py);				// swap() 함수의 원형을 미리 출력한다.

int main(void)
{
	int a = 100, b = 200;				// 변수 a와 b를 생성하고 각각 100, 200으로 초기화한다.

	printf("a = %d\tb = %d\n", a, b);	// a와 b를 출력한다.
	swap(&a, &b);						// swap 함수에 a와 b의 주소값을 넣어 실행한다.
	printf("a = %d\tb = %d\n", a, b);	// a와 b를 출력한다.
	// 주소값이 바뀌었기 때문에 a와 b의 값은 swap함수에 실행하면 값이 변한다.

	return 0;
}
void swap(int *px, int *py)
{
	int tmp;							// 일시적인 저장공간을 담당할 변수 tmp를 생성한다.

	tmp = *px;							// 변수 tmp에 포인터 px의 값을 저장한다.
	*px = *py;							// 포인터 px에 포인터 py의 값을 저장한다.
	*py = tmp;							// 포인터 py에 tmp의 값을 저장한다.
	// 수를 보존하면서 위치를 바꾸는 알고리즘
}