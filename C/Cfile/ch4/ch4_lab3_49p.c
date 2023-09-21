// lab3 : 숫자 추측 게임 만들기(rand()함수 이용)
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	srand((unsigned)time(NULL));		// 난수 발생기 시드 설정
	int answer = rand() % 100;				// 정답을 1~100까지의 난수로 설정한다.
	int guess;								// 추측할 숫자를 저장할 변수를 생성한다.
	int tryy = 0;							// 시도 횟수를 저장할 변수를 생성한다.

	do {
		printf("정답을 추측하시오 : ");		// 추측할 숫자를 입력받는다.
		scanf_s("%d", &guess);				// 입력받은 숫자를 변수 guess에 저장한다.
		tryy++;
		// 시도횟수가 1회 늘어날 때마다 0으로 초기화시킨 시도횟수 변수를 1씩 증가시킨다.
		if (guess < answer)		// 추측한 숫자가 정답보다 작다면 LOW를 출력한다.
			printf("LOW\n");
		if (guess > answer)		// 추측한 숫자가 정답보다 크다면 HIGH를 출력한다.
			printf("HIGH\n");
	} while (guess != answer);	// 추측한 숫자가 정답과 일치하면 반복을 그만둔다.
	printf(" 축하합니다. 시도횟수 = %d", tryy);
	// 정답이 일치하면 시도횟수를 출력한다.

	return 0;
}