// Lab2 : 극장 예약 시스템
#include <stdio.h>
#define SEATS 10

int main(void)
{
	char answer1;	// 좌석 예약 여부를 입력받을 변수 answer1을 생성한다.
	int answer2, i;	// 어느 좌석을 선택할지 입력받을 변수 answer2와 for문에 이용할 변수 i를 생성한다.
	int movie_seat[10] = { 0 };	// 좌석 10개를 저장할 배열을 생성하고 0으로 초기화한다.

	while (1)		// 무한반복문
	{
		printf("좌석을 예약하시겠습니까? (y 또는 n) ");	// 좌석을 예약할 것인지 출력한다.
		scanf_s(" %c", &answer1, 4);	// 대답을 입력받고 변수 answer1에 저장한다.

		if (answer1 == 'y')	// 만약 대답이 y라면 좌석을 예약한다.
		{
			printf("-----------------------\n");
			printf("1 2 3 4 5 6 7 8 9 10\n");			// 좌석 수를 출력한다.
			printf("-----------------------\n");
			for (i = 0; i < SEATS; i++)		// 좌석의 수만큼 반복한다.
			{
				printf("%d ", movie_seat[i]);
				// 앞에서 배열을 초기화했으므로 0 또는 1이 출력된다.
				// 1이 출력되면 예약된 좌석, 0이 출력되면 예약하지 않은 좌석이다.
			}
			printf("\n");	// 줄바꿈

			printf("몇 번째 좌석을 예약하시겠습니까? ");		// 어느 좌석을 예약할 것인지 출력한다.
			scanf_s("%d", &answer2);		// 입력받은 좌석의 번호를 변수 answer2에 저장한다.

			if (answer2 <= 0 || answer2 > SEATS)	// 만약 answer2의 값이 1 ~ 10 사이의 값이 아니라면
			{
				printf("1부터 10 사이의 숫자를 입력하세요.\n");	// 변수를 다시 입력받는다.
				continue;	// 다시 반복문을 실행
			}
			if (movie_seat[answer2 - 1] == 0)	// 만약 변수 answer2 - 1의 배열값이 0이라면
			{
				movie_seat[answer2 - 1] = 1;	// 그 자리에 1을 저장한다.
				printf("예약되었습니다.\n");	// 예약됐다고 출력한다.
			}
			else       // 만약 변수 answer2 - 1 의 배열값이 1이라면
			{
				printf("이미 예약된 자리입니다.\n");	// 이미 예약된 자리라고 출력한다.
			}
		}
		if (answer1 == 'n')		// 만약 대답이 n이라면 그대로 반복문을 종료한다.
			return 0;
	}
	return 0;
}
