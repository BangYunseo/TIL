// 윤년 계산하기
#include <stdio.h>

int main(void)
{
	int year, result;	// 계산할 년도를 입력받을 변수 year과 윤년인지 아닌지 판단한 값을 저장할 변수 result를 생성한다.

	printf("연도를 입력하세요 : ");	// 계산할 년도를 입력받는다.
	scanf_s("%d", &year);			// 입력받은 년도를 변수 year에 저장한다.

	result = ((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0);	// 윤년을 계산한 결과를 변수 result에 저장한다.
	printf("result = %d\n", result);	// 입력받은 년도가 윤년인지 아닌지 계산한 값을 출력한다.

	return 0;
}