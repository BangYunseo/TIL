// 80p : 2차원 배열의 초기화
#include <stdio.h>
#define ROWS 3		// ROWS를 3으로 정의 (행)
#define COLS 5		// COLS를 5로 정의	 (열)

int main(void)
{
	int a[ROWS][COLS] = { {87, 98, 80, 76, 3},
						  {99, 89, 90, 90, 0},
						  {65, 68, 50, 49, 0}
	};	// 행이 3, 열이 5인 행렬을 생성하고 그 값을 초기화함

	int i;		// for문에 사용할 변수 i를 생성

	for (i = 0; i < ROWS; i++)		// i를 0으로 초기화하고, i를 행의 수만큼 반복하면서 1씩 증감
	{
		double final_scores = a[i][0] * 0.3 + a[i][1] * 0.4 + a[i][2] * 0.2 + a[i][3] * 0.1 - a[i][4];
		// 변수 final_scores에 각각의 비율을 곱한 행렬의 값을 출력
		printf("학생 #%i의 최종 성적 = %5.2f \n", i + 1, final_scores);
		// 각 학생들의 최종 성적을 출력
	}
	return 0;
}