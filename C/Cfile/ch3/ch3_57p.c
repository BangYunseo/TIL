#include <stdio.h>

int main(void)
{
	int score, iscore;		// 점수를 입력받을 변수와 계산할 변수를 생성한다.
	char grade;				// 학점을 저장할 변수를 생성한다.

	printf("점수를 입력하세요 : ");		// 점수를 입력받는다.
	scanf_s("%d", &score);				// 입력받은 점수를 저장한다.

	iscore = score / 10;						// 입력받은 변수를 계산한다.

	switch (iscore)
	{
	case 10:
	case 9:grade = 'A'; break;				// 계산된 점수가 9, 10일 경우 학점은 A이다. (90 ~ 100 은 A학점)
	case 8: grade = 'B'; break;				// 계산된 점수가 8일 경우 학점은 A이다. (80 ~ 89 은 B학점)
	case 7: grade = 'C'; break;				// 계산된 점수가 7일 경우 학점은 A이다. (70 ~ 79 은 C학점)
	case 6: grade = 'D'; break;				// 계산된 점수가 6일 경우 학점은 A이다. (60 ~ 69 은 D학점)
	default: grade = 'F'; break;			// 계산된 점수가 6 아래일 경우 학점은 F이다. (59점 이하는 F학점)
	}

	printf("당신의 학점은 %c 입니다.\n", grade);		// 학점을 출력한다.

	return 0;
}
