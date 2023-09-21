// ex9 : 달의 일수 출력하기
#include <stdio.h>

int main(void)
{
	int month, days;		// 달과 달의 일수를 저장할 변수를 생성한다.

	printf("달을 입력하세요 (1 ~ 12): ");	// 달을 입력받는다.
	scanf_s("%d", &month);			// 입력받은 달을 변수 month에 저장한다.

	/* 2월은 28일, 1, 3, 5, 7, 8, 10, 12월은 31일, 4, 6, 9, 11월은 30일이다.
	이에 따라서 switch문을 이용한다.
	*/

	switch (month)
	{
	case 2: days = 28; break;		// 2월일 경우 변수 days에 28일을 저장한다.
	case 4:
	case 6:
	case 9:
	case 11: days = 30; break;		// 4, 6, 9, 11월일 경우 변수 days에 30일을 저장한다.
	default: days = 31; break;		// 나머지 월일 경우 변수 days에 31일을 저장한다.
	}

	printf("%d월의 일 수는 %d입니다.\n", month, days);		
	// 앞의 switch 문에서 얻은 일 수를 월과 함께 출력한다.
	return 0;
}