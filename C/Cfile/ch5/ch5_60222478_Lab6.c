// Lab6 : 자동으로 수학문제 생성하기
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main(void)
{
	srand(time(NULL));
	int x, y, answer, i;		
	// 난수로 생성된 숫자를 저장할 변수 x, y와 답을 저장할 변수 answer, 반복할 숫자를 저장할 변수 i를 생성한다.

	for (i = 0; i < 10; i++)		// 변수 i를 10까지 1씩 더해가면서 10개의 수학문제를 낸다.
	{
		x = rand() % 10;			// 변수 x에 1~10의 숫자 중에서 무작위 난수를 저장한다.
		y = rand() % 10;			// 변수 y에 1~10의 숫자 중에서 무작위 난수를 저장한다.
		printf("%d + %d = ", x, y);		// 생성된 난수를 저장한 변수 x와 y의 합을 구하는 문제를 출력한다.
		scanf_s("%d", &answer);			// 입력받은 정답을 변수 answer에 저장한다.
		if (x + y == answer)		// 변수 x와 y의 합이 정답 answer과 같을 때 if문을 실행하고 아닐 때 else문을 실행한다.
			printf("맞았습니다.\n");		// 정답이 일치할 때 맞았다고 출력한다.
		else
			printf("틀렸습니다.\n");		// 정답이 일치하지 않을 때 틀렸다고 출력한다.
	}
	return 0;
}