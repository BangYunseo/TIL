#include <stdio.h>
#define SQMETER_PER_PYEONG 3.3058	// 1평을 3.3 제곱미터로 정의한다.

int main(void)
{
	double Pyeong, result = 0;		// 평을 저장할 변수와 결과값을 저장할 변수를 생성한다.

	printf("평을 입력하세요 : ");		// 평을 입력받는다.
	scanf_s("%lf", &Pyeong);			// 입력받은 평을 변수에 저장한다.

	result = Pyeong * SQMETER_PER_PYEONG; // 결과값을 계산한다.

	printf("%lf평방미터입니다.\n", result); //결과값을 출력한다.
	return 0;
}