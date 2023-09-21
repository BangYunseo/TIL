// 68p : 순차 탐색
#include <stdio.h>
#define SIZE 10		// 크기를 10으로 정의한다.

int main(void)
{
	int key, i;
	// 입력받을 탐색할 값을 저장할 변수 key와 인덱스 값을 저장할 변수 i를 생성한다.
	int list[SIZE] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	// 배열 list를 SIZE크기만큼 생성하고 초기화한다.

	printf("탐색할 값을 입력하세요 : ");	// 탐색할 값을 입력받는다.
	scanf_s("%d", &key);	// 입력받은 값을 변수 key에 저장한다.

	for (i = 0; i < SIZE; i++)
		// 변수 i를 0으로 초기화하고 SIZE 크기만큼 for문을 반복하고 1씩 증감
	{
		if (list[i] == key)		// 만약 list[i]의 값이 입력받은 key값과 일치한다면
			printf("탐색 성공 인덱스 = %d\n", i);		// 탐색 성공 인덱스인 변수 i를 출력
	}
	printf("탐색 종료\n");	// 탐색 종료를 출력
	return 0;
}