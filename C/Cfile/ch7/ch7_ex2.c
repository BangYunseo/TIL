// ex 2 : 성적 평균 계산하기
#include <stdio.h>
#define STUDENTS 5           // 성적을 5번 입력하므로 학생 수를 5로 정의한다.
int main(void)
{
	int score[STUDENTS];		// 성적 5개를 입력받을 배열을 생성한다.
	int sum = 0;		// 성적의 합을 계산할 변수를 생성한다.
	int i, average;;	// 성적을 입력받을 횟수와 성적의 평균을 계산할 변수를 생성한다.

	for (i = 0; i < STUDENTS; i++)		// 성적을 총 5번 입력받는다.
	{
		printf("학생들의 성적을 입력하세요 : ");	// 학생들의 성적을 입력받는다.
		scanf_s("%d", &score[i]);					// 입력받은 학생들의 성적을 배열에 저장한다.
		sum += score[i];							// 입력받은 성적을 변수 sum에 더한다.
	}

	average = sum / STUDENTS;	// 총 합을 저장한 변수 sum을 5로 나눈 값을 average에 저장한다.
	printf("성적 평균 = %d\n", average);	// 평균을 출력한다.

	return 0;
}