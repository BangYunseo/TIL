// ex4 : 포인터를 통한 구조체 참조
#include <stdio.h>

struct student	// 구조체 student를 선언한다.
{
	int number;			// 정수형 변수이자 학번을 저장할 변수 number를 생성한다.
	char name[10];		// 문자형 배열이자 이름을 저장할 배열 name[20]을 생성한다.
	double grade;		// 실수형 변수이자 학점을 저장할 변수 grade를 생성한다.
};
int main(void)
{
	struct student s = { 20190001, "홍길동", 4.3 };
	// 구조체 student를 변수 s로 선언하고 각각 변수와 배열을 1, 홍길동, 4.3으로 초기화
	struct student *p;		// 구조체 student를 포인터 p로 선언한다.

	p = &s;			// p를 구조체 s의 주소값으로 초기화한다.	

	printf("학번 : %d\t이름 : %s\t학점 : %f\n", s.number, s.name, s.grade);
	// 학번, 이름, 학점을 구조체를 이용한 변수 s.을 이용한 형태로 출력한다.

	printf("학번 : %d\t이름 : %s\t학점 : %f\n", (*p).number, (*p).name, (*p).grade);
	// 학번, 이름, 학점을 구조체를 이용한 변수 (*p)을 이용한 형태로 출력한다.
	// *p는 s의 주소값의 값을 의미한다.

	printf("학번 : %d\t이름 : %s\t학점 : %f\n", p->number, p->name, p->grade);
	// 학번, 이름, 학점을 구조체를 이용한 변수 p->을 이용한 형태로 출력한다.

	return 0;
}