#include <stdio.h>

double F2C(double tempC);			// F2C 함수 원형을 컴파일러에 미리 알린다.
double C2F(double tempF);			// C2F 함수 원형을 컴파일러에 미리 알린다.
void StartMenu();					// StartMenu 함수 원형을 미리 컴파일러에 알린다.

int main(void)
{
	char menu;							// 입력받을 메뉴를 저장하는 변수 생성
	double temp;						// 섭씨온도와 화씨온도를 저장하는 변수 생성

	while (1)							// while 무한반복문
	{
		StartMenu();
		printf("메뉴에서 선택하세요 : ");	// 선택할 메뉴를 입력
		menu = getchar();					// 입력받은 메뉴를 변수 menu에 저장

		if (menu == 'q')					// 만약 q를 입력받으면
			break;						// 메뉴를 종료
		else if (menu == 'c')			// 만약 c를 입력받으면
		{
			printf("섭씨온도 : ");		// 섭씨 온도를 입력
			scanf_s("%lf", &temp);		// 입력받은 섭씨온도를 변수에 저장
			printf("화씨온도 : %lf\n", C2F(temp));	// 함수를 통해 계산한 화씨온도를 출력
		}
		else if (menu == 'f')			// 만약 f를 입력받으면
		{
			printf("화씨온도 : ");		// 화씨온도를 입력
			scanf_s("%lf", &temp);		// 입력받은 화씨온도를 변수에 저장
			printf("섭씨온도 : %lf\n", F2C(temp));	// 함수를 통해 계산한 섭씨온도를 출력
		}
		getchar();						// 이전에 입력된 개행문자를 삭제함
		
	}

	return 0;
}
double F2C(double tempF)						// 화씨온도에서 섭씨온도로 변환
{
	return (tempF - 32.0) * 5.0 / 9.0;			// °C : 5/9(tempF − 32)
}
double C2F(double tempC)						// 섭씨온도에서 화씨온도로 변환
{
	return 9.0 / 5.0 * tempC + 32;				// F : 5/9tempC + 32
}
void StartMenu()								// 메뉴를 입력하는 함수를 생성
{
	printf("==========================================\n");
	printf("'c' 섭씨온도(C)에서 화씨온도(F)로 변환\n");
	printf("'f' 화씨온도(F)에서 섭씨온도(C)로 변환\n");
	printf("'q' 종료\n");
	printf("==========================================\n");
}