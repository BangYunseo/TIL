// 64-65p : 선택 정렬
#include <stdio.h>
#define SIZE 10		// SIZE를 10으로 정의한다.

int main(void)
{
	int list[SIZE] = { 3, 2, 9, 7, 1, 4, 8, 0, 6, 5 };		// 배열 list를 생성하고 크기를 SIZE로 정한 후 초기화한다.
	int i, j, temp, least;
	// for문에 사용할 변수 i, j와 최솟값의 index를 저장할 변수 least,
	// 최솟값을 임시로 저장할 변수 temp를 생성한다.

	for (i = 0; i < SIZE - 1; i++)
		// i를 0으로 초기화하고 i부터 SIZE - 1까지 반복하면서 1씩 증감
		// 0부터 8까지 총 9번 반복
	{
		least = i;	// 최솟값의 index를 0으로 초기화한 변수 i로 저장함
		for (j = i + 1; j < SIZE; j++)	// j를 i+1로 초기화하고, j를 SIZE까지 반복하면서 1씩 증감
		{
			if (list[j] < list[least])		// 만약 list[j]의 값이 list[least]보다 작을 때,
				least = j;					// least에 j를 저장한다.
		}
		temp = list[i];			// temp에 list[i]를 저장한다.
		list[i] = list[least];	// list[i]에 최솟값 list[least]를 저장한다.
		list[least] = temp;		// list[least]에 다시 temp값을 저장한다.
		// 숫자를 덮어쓰지 않고 바꾸는 알고리즘
	}
	printf("정렬된 배열\n");		// 정렬된 배열을 출력한다.
	for (i = 0; i < SIZE; i++)	// i를 0으로 초기화하고, SIZE보다 작을 때까지 i의 값을 1씩 증감
		printf("%d ", list[i]);		// 배열의 값을 index순서대로 출력
	printf("\n");	// 줄바꿈

	return 0;
}