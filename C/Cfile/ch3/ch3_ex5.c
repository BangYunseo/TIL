// ex5 : 윤년여부 판단하기
#include <stdio.h>

int main(void)
{
	int year;		// 년도를 저장할 변수를 생성한다.

	printf("연도를 입력하시오 : ");		// 년도를 입력한다.
	scanf_s("%d", &year);				// 입력받은 년도를 변수 year에 저장한다.

	if ((year % 4 == 0) && (year % 100 != 0) || (year % 400 == 0))
		printf("%d년은 윤년입니다.\n", year);		
	// if절의 조건을 충족하는 값이 입력됐다면, 윤년이라고 출력한다.
	else
		printf("%d년은 윤년이 아닙니다.\n", year);
	// if절의 조건을 충족하는 값이 아니라면, 윤년이 아니라고 출력한다.

	return 0;
}