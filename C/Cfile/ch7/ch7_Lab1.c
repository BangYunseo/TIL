// Lab1 : 주사위 던지기
#include <stdio.h>
#include <stdlib.h>
#define DICE_NUM 6		// DICE 면의 수를 6으로 정의한다.

int main(void)
{
	int freq[DICE_NUM] = { 0 };	// 주사위의 면의 수만큼 배열 freq를 생성한다.
	int i;						// for문에 사용할 변수 i를 생성한다.

	for (i = 0; i < 10000; i++)		// 주사위를 10000번 던진다.
	{
		++freq[rand() % 6];		// 배열의 무작위 면이 나오는 횟수를 더한다.
	}

	printf("=========================\n");
	printf("숫자\t빈도\n");						// 숫자와 빈도를 출력한다.
	printf("=========================\n");

	for (i = 0; i < DICE_NUM; i++)		// 주사위 면의 숫자만큼 출력을 반복한다.
	{
		printf("%d\t%d\n", i + 1, freq[i]);
		// 주사위 면 1의 값이 나온 횟수부터 차례대로 입력한다.
		// 여기서 i는 0부터 시작하므로 i + 1을 해서 1 ~ 6까지의 수를 입력한다.
	}
	return 0;
}