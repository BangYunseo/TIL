// ex3 : 예제 3
#include <stdio.h>
#define SIZE 3		// SIZE를 3으로 정의

struct student	// 구조체 student를 선언한다.
{
	int number;			// 정수형 변수이자 학번을 저장할 변수 number를 생성한다.
	char name[10];		// 문자형 배열이자 이름을 저장할 배열 name[10]을 생성한다.
	double grade;		// 실수형 변수이자 학점을 저장할 변수 grade를 생성한다.
};
int main(void)
{
	struct student list[SIZE];		// 구조체 student를 SIZE의 크기만큼 배열로 생성한다.
	int i;		// for문에 사용할 변수 i를 생성한다

	for (i = 0; i < SIZE; i++)		// SIZE의 크기만큼 for문을 반복한다. = 3번 반복
	{
		printf("학번을 입력하세요 : ");			// 학번을 입력받는다.
		scanf_s("%d", &list[i].number);
		// 입력받은 학번을 list[i]번째의 변수 number에 저장한다.
		// 만약 i = 0이라면, list[0].number에 입력받은 학번을 저장

		printf("이름을 입력하세요 : ");			// 이름을 입력받는다.
		scanf_s("%s", list[i].name, 16);
		// 입력받은 이름을 list[i]번째의 배열 name에 저장한다.
		// 만약 i = 0이라면, list[0].name에 입력받은 이름을 저장
		// 이름은 처음부터 배열로 생성됐으므로 &를 붙이지 않음

		printf("학점을 입력하세요 : ");			// 학점을 입력받는다.
		scanf_s("%lf", &list[i].grade);
		// 입력받은 학점을 list[i]번째의 변수 grade에 저장한다.
		// 만약 i = 0이라면, list[0].grade에 입력받은 학점을 저장
	}

	for (i = 0; i < SIZE; i++)		// SIZE의 크기만큼 for문을 반복하다 = 3번 반복
		printf("학번 : %d, 이름 : %s, 학점 : %lf\n", list[i].number, list[i].name, list[i].grade);
	// 각기 다른 학번, 이름, 학점을 3번 출력함
	return 0;
}