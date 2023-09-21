// 16page : 전역변수의 초기값과 생존 기간
#include <stdio.h>

int A;		// 전역변수 A 생성
int B;		// 전역변수 B 생성
int add();	// 함수 add()의 원형 출력

int main(void)
{
	int answer;		// 답을 저장할 변수 생성
	A = 5;			// 변수 A에 5를 저장
	B = 7;			// 변수 B에 7을 저장	

	answer = add();	// 변수 answer에 add()함수의 값을 저장

	printf("%d + %d = %d\n", A, B, answer);	// A와 B의 값을 출력
	return 0;
}
int add()
{
	return A + B;		// A 와 B의 합을 반환
}