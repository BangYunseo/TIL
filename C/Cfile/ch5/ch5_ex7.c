#include <stdio.h>

int com_num(int n, int m);					// 함수 com_num을 컴파일러에 미리 알린다.
int fact_num(int n);						// 함수 fact_num을 컴파일러에 미리 알린다.
int get_num(void);							// 함수 get_num을 컴파일러에 미리 알린다.


int main(void)
{
	int a, b;								// 계산할 변수 a와 b를 생성한다.
		
	a = get_num();							// 변수 a에 숫자를 입력받는다.
	b = get_num();							// 변수 b에 숫자를 입력받는다.
		
	printf("C(%d, %d) = %d \n", a, b, com_num(a, b));	// 조합을 출력한다.
	return 0;
}
int get_num(void)						// 정수 구하는 함수
{
	int n;								// 변수 n을 생성한다.

	printf("정수를 입력하세요 : ");		// 정수를 입력받는다.
	scanf_s("%d", &n);					// 입력받은 정수를 변수 n에 저장한다
	return n;							// n을 반환
}
int fact_num(int n)						// 팩토리얼 구하는 함수
{
	int i;								// 변수 i를 생성
	long result = 1;					// 팩토리얼 값을 저장할 변수 result를 생성하고 1로 초기화

	for (i = 1; i <= n; i++)			// i가 n보다 작거나 같을 때, i의 값을 1씩 더하면서 for문 반복
		result = result * i;			// result에 i값 곱하면서 저장
	return result;						// result를 반환
}
int com_num(int n, int m)				// 조합 구하는 함수
{
	return (fact_num(n) / (fact_num(m) * fact_num(n - m)));		// 변수 n과 m의 조합을 반환
}