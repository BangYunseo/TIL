#include <stdio.h>

int main(void)
{
	char lecture;		// 문자를 입력받을 변수를 생성한다.

	printf("문자를 입력하시오 : ");		// 문자를 입력받는다.
	lecture = getchar();				
	// 변수 lecture에 문자를 입력받는다. 
	// scanf가 아니더라도 getchar()함수를 이용해서 문자를 입력받을 수 있다.


	// 밑의 내용은 아스키코드를 참고하면 좋다.
	if ((lecture >= 'A') && (lecture <= 'Z'))
		printf("%c는 대문자입니다.\n", lecture);		// A~Z의 문자를 입력받으면 대문자라고 출력한다.
	else if ((lecture >= 'a') && (lecture <= 'z'))
		printf("%c는 소문자입니다.\n", lecture);		// a~z의 문자를 입력받으면 소문자라고 출력한다.
	else if ((lecture >= '0') && (lecture <= '9'))
		printf("%c는 숫자입니다.\n", lecture);			// 0~9의 숫자를 입력받으면 숫자라고 출력한다.
	else
		printf("%c는 기타문자입니다.\n", lecture);	
	// 앞의 어느 내용에도 해당되지 않으면 기타문자라고 출력한다.

	return 0;
}