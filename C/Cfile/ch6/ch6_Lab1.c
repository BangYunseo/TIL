// Lab 1 : 은행 계좌 구현하기
#include <stdio.h>

void menu();			// menu() 함수의 원형 출력
int save(int amount);	// save() 함수의 원형 출력
int main(void)
{
	menu();	// menu()함수 실행

	save(10000);	// save(10000)함수 실행
	save(50000);	// save(50000)함수 실행
	save(-10000);	// save(-10000)함수 실행
	save(30000);	// save(30000)함수 실행

	printf("==================================\n"); // 끝부분 출력

	return 0;
}
void menu()		// menu를 출력할 함수 생성
{
	printf("==================================\n");
	printf("입금\t출금\t잔고\t\n");
	printf("==================================\n");
}
int save(int amount)	// 입금, 출금, 잔고를 계산할 함수 생성
{
	static long balance = 0;
	// 정적 변수 balance를 생성, 정적 변수는 save()함수가 끝나더라도 값이 저장된다.
	// 즉, 정적 변수 balance는 잔고를 저장하는 변수

	if (amount > 0)	// 만약 amount가 양수라면 (입금)
	{
		printf("%d \t \t", amount);	// 입금 칸에 출력
	}
	else	// 만약 amount가 음수라면 (출금)
	{
		printf("\t%d \t", -amount);
		// 출금 칸에 출력하고, 출금하는 값은 음수이므로 -를 붙임
	}

	balance += amount;	// 잔고에 입금, 출금 값을 더함
	printf("%d \n", balance);	// 잔고 출력
}