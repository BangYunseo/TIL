// 예제 6 : 학점 입력받기
#include <stdio.h>

int main(void)
{
	int grade;		// 성적을 입력받을 변수를 생성한다.

	printf("성적을 입력하시오 : ");	// 성적을 입력받는다.
	scanf_s("%d", &grade);					// 입력받은 성적을 변수 grade에 저장한다.

	if (grade >= 90)
	{
		printf("학점 A\n");	// 성적이 90점 이상일 경우 학점 A가 출력된다.
	}
	else if (grade >= 80)
	{
		printf("학점 B\n");	// 성적이 80점 이상이면서 90점 미만인 경우 학점 B가 출력된다.
	}
	else if (grade >= 70)
	{
		printf("학점 C\n");	// 성적이 70점 이상이면서 80점 미만인 경우 학점 C가 출력된다.
	}
	else if (grade >= 60)
	{
		printf("학점 D\n");	// 성적이 60점 이상이면서 70점 미만인 경우 학점 D가 출력된다.
	}
	else 
	{
		printf("불합격 : 학점 F\n");	// 성적이 60점 미만일 경우 학점 F가 출력된다.
	}
	return 0;
}