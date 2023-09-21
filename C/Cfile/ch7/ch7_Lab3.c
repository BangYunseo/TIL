// Lab3 : 최솟값 찾기
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 10		// 배열의 크기를 10으로 설정한다.

int main(void)
{
	srand((unsigned)time(NULL));	// 난수를 발생시킨다.

	int prices[SIZE] = { 0 };	// 값을 저장할 배열을 SIZE 크기만큼 생성하고, 0으로 초기화한다.
	int i, minimum;		// 배열에 사용할 변수 i와 최솟값을 저장하면서 갱신할 변수를 생성한다.

	printf("---------------------------\n");
	printf("1 2 3 4 5 6 7 8 9 10\n");				// 10개의 숫자를 출력할 메뉴 출력
	printf("---------------------------\n");

	for (i = 0; i < SIZE; i++)	// 배열의 크기만큼 반복한다.
	{
		prices[i] = (rand() % 100) + 1;		// 배열의 각 값에 1 ~ 100까지의 수를 저장한다.
		printf("%d ", prices[i]);			// 각 배열을 출력한다.
	}
	printf("\n");		// 줄바꿈

	minimum = prices[0];	// 일단 최솟값을 첫 번째 값으로 설정한다. for문 안에 들어갈 필요 X
	for (i = 0; i < SIZE; i++)	// 배열의 크기만큼 반복한다.
	{
		if (prices[i] < minimum)	// 만약 prices[i]의 값이 현재 최솟값보다 작다면
			minimum = prices[i];	// 현재 최솟값을 prices[i]로 변경한다.
	}

	printf("최소값은 %d 입니다.\n", minimum);	// 최솟값을 출력한다.

	return 0;
}