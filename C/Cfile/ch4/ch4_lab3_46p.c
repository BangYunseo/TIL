// lab3 : 숫자 추측 게임(46p)
#include <stdio.h>

int main(void)	
{
	int answer = 59;		// 정답을 저장할 변수 answer을 생성한다.
	int guess;				// 추측한 숫자를 저장할 변수 guess를 생성한다.
	int tryy = 0;			// 시도 횟수를 저장할 변수 tryy를 생성한다. 

	do{	
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