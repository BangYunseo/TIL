// 70~71p: 이진 탐색
#include <stdio.h>
#define SIZE 16		// 배열의 크기를 16으로 정의
int binary_search(int list[], int n, int key);	// 함수의 원형 

int main(void)
{
	int key;		// 탐색할 값을 입력받을 변수 생성
	int grade[SIZE] = { 2, 6, 11, 13, 18, 20, 22, 27, 29, 30, 34, 38, 41, 42, 45, 47 };	
	// 배열을 SIZE 크기만큼 생성하고 초기화

	printf("탐색할 값을 입력하세요 : ");		// 탐색할 값을 입력받음
	scanf_s("%d", &key);		// 입력받은 탐색할 값을 변수 key에 저장
	printf("탐색 결과 = %d\n", binary_search(grade, SIZE, key));
	// 탐색 결과를 출력한다. grade는 배열 전부를 포함한다.

	return 0;
}
int binary_search(int list[], int n, int key)
{
	int low, high, middle;		// 탐색할 인덱스 값의 가장 작은 값, 가장 큰 값, 중간 값을 저장할 변수 생성
	low = 0;		// 가장 작은 인덱스 값을 0으로 초기화
	high = n - 1;	// 가장 큰 인덱스 값을 n-1로 초기화
	while (low <= high)	// low값이 high값보다 작거나 같을 동안 반복
	{
		printf("[%d %d]\n", low, high);		// low와 high값의 구간을 출력
		middle = (low + high) / 2;			// 중간 인덱스 값에 low와 high의 합에 2를 나눈 인덱스 값을 저장
		if (key == list[middle])		// 만약 key값이 배열의 중간값과 일치하다면
			return middle;				// 탐색 값의 중간값 인덱스를 반환
		else if (key > list[middle])	// 만약 key값이 배열의 중간값보다 크다면
			low = middle + 1;			// low에 중간 인덱스 값에 1을 더한 수를 저장
		else                            // 만약 key값이 배열의 중간값보다 작다면
			high = middle - 1;			// high에 중간 인덱스 값에 1을 뺀 수를 저장
	}
	return -1;
}