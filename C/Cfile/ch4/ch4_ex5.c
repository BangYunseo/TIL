// ex5 : while문을 이용한 합계 프로그램
#include <stdio.h>

int main(void)
{
	int i, n, sum;			// 변수 i, n, sum을 생성한다.

	i = 0;				// i를 0으로 초기화한다.
	sum = 0;			// sum을 0으로 초기화한다.

	while (i < 5)		// 입력 횟수 i가 5보다 작다면 while문을 반복한다.
	{
		printf("값을 입력하시오 : ");		// 값을 입력받는다.
		scanf_s("%d", &n);					// 입력받은 값을 변수 n에 저장한다.
		sum = sum + n;						// sum과 n을 더한 값을 sum에 저장한다.
		i++;								// 입력 횟수 i를 1씩 더한다.
	}
	printf("합계는 %d 입니다.\n", sum);		// 합계를 출력한다.

	return 0;
}