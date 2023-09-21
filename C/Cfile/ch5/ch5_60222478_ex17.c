// ex17 : 소문자를 대문자로 변경한다. 
#include <stdio.h>

int main(void) 
{
	char letter;		// 문자를 저장할 변수 letter을 생성한다.

	while (1)			// 무한반복 while문을 생성한다.
	{
		printf("소문자를 입력하시오 : ");			// 소문자를 입력받는다.
		scanf_s(" %c", &letter, 16);						// 입력받은 소문자를 변수 letter에 저장한다.

		if (letter == 'Q')				// 만약 입력받은 문자가 Q일 경우
			break;						// 무한반복 while문을 빠져나온다.
		if (letter < 'a' || letter > 'z')		// 만약 입력받은 문자가 소문자 a보다 작고 z보다 클 경우
			continue;							// 무한반복 while문을 계속 진행한다

		letter -= 32;							
		// 입력받은 소문자에 -32를 더한 값을 다시 변수 letter에 저장한다.
		printf("변환된 대문자는 %c입니다.\n", letter);			// 변환된 대문자를 출력한다.
	}
	return 0;
}