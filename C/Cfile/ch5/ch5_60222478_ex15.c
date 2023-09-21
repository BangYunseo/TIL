// ex15 : 재테크 관련 예제
#include <stdio.h>
#define SEED_MONEY 1000000

int main(void)
{
	int year = 0;				// 년도를 저장할 변수를 0으로 초기화한다.
	int money = SEED_MONEY		// 돈을 저장할 변수를 SEED_MONEY로 초기화한다.

		while (1)				// break를 만날 때까지 while문을 무한 반복한다.
		{
			year++;				// 년도를 1씩 더한다.
			money += money * 0.30;		// money에 money의 30퍼센트 값을 더한다.
			if (money > 10 * SEED_MONEY)		// 만약 money가 처음에 가지고있던 시드머니의 10배가 되면 반복문을 종료한다.
				break;							// 반복문 탈출 명령어
		}
	printf("%d", year);						// 걸린 년도를 출력한다.
	return 0;
}