// 54p : 평균 구하기
#include <stdio.h>
#define STUDENTS 5		// 학생의 숫자를 5로 정의
int get_average(int scores[], int n);	// 함수의 원형 출력

int main(void)
{
	int scores[STUDENTS] = { 1, 2, 3, 4, 5 };	// 배열을 학생의 수만큼 생성하고 1, 2, 3, 4, 5로 초기화
	int avg;	// 	펑균을 저장할 변수를 생성

	avg = get_average(scores, STUDENTS);	// 변수 avg에 get_average 함수의 값을 저장한다.
	printf("평균은 %d 입니다.\n", avg);		// 평균을 출력한다.
	return 0;
}
int get_average(int scores[], int n)
{
	int i;		// for문에 사용할 변수 i를 저장한다.
	int sum = 0;	// 총 합계를 저장할 변수 sum을 생성하고 0으로 초기화한다.

	for (i = 0; i < n; i++)		// i를 0으로 초기화하고, n보다 작은 수 일때까지 i의 수를 1씩 증감
		sum += scores[i];		// 합계를 저장하는 변수 sum에 scores배열의 [i] 순서대로 더한다.
	return sum / n;			// 합계를 변수 n으로 나눈 수를 반환한다.
}