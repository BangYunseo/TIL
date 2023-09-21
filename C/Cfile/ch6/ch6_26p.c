// 26page : 저장 유형 지정자 static
#include <stdio.h>

void sub();	// 함수 sub()의 원형 출력
int main(void)
{
	sub();
	sub();
	sub();
	// 함수 sub()를 3번 실행
	return 0;
}
void sub()
{
	static int scount = 0;
	// static 은 정적 지역 변수로서 sub()함수가 종료되더라도 자동으로 소멸되지 않음
	// 즉 값이 계속 저장됨

	int acount = 0;
	// 위의 정적 지역 변수와 다른 일반적인 지역변수 account를 생성

	printf("scount = %d\t", scount);
	// scount의 값을 출력하고 탭만큼 띄어씀
	printf("acount = %d\n", acount);
	// acount의 값 출력

	scount++;	// scount의 값 1 증가
	acount++;	// acount의 값 1 증가
}