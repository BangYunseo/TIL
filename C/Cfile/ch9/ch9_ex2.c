// ex2 : 예제 2
#include <stdio.h>

struct student	// 구조체 student를 선언한다.
{
	int number;			// 정수형 변수이자 학번을 저장할 변수 number를 생성한다.
	char name[10];		// 문자형 배열이자 이름을 저장할 배열 name[10]을 생성한다.
	double grade;		// 실수형 변수이자 학점을 저장할 변수 grade를 생성한다.
};
int main(void)
{
	struct student s;
	// 구조체 student를 변수 s로 선언한다.

	printf("학번을 입력하세요 : ");		// 학번을 입력받는다.
	scanf_s("%d", &s.number);			// 입력받은 학번을 구조체의 s.number의 주소에 전달한다.

	printf("이름을 입력하세요 : ");		// 이름을 입력받는다.
	scanf_s("%s", s.name, 16);			// 입력받은 이름을 구조체의 s.name의 주소에 전달한다.
	// name은 배열의 이름이다. 이는 이미 배열을 가리키는 포이너라는 의미이다. 따라서 앞에 & 없음.

	printf("학점을 입력하세요(실수) : ");		// 학점을 입력받는다.
	scanf_s("%lf", &s.grade);			// 입력받은 학점을 구조체의 s.grade의 주소에 전달한다.

	printf("학번 : %d\n", s.number);		// 학번을 구조체를 이용한 변수 s.student로 출력한다.
	printf("이름 : %s\n", s.name);			// 이름을 구조체를 이용한 변수 s.name로 출력한다.
	printf("학점 : %lf\n", s.grade);			// 학점을 구조체를 이용한 변수 s.grade로 출력한다.

	return 0;
}