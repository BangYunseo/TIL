#include <stdio.h>

int main(void)
{
	double LightSpeed = 300000;		// 빛의 속도 30만 km를 변수에 저장한다.
	double Distance = 149600000;	// 태양과 지구 사이의 거리 1억 4960만 km를 변수에 저장한다.
	double Time; // 구할 시간을 저장할 변수를 생성한다.

	Time = Distance / LightSpeed;	// 태양과 지구 사이의 거리를 빛의 속도로 나눈다.	
	Time = Time / 60.0;				// 시간을 분 단위로 조정하기 위해 60으로 나눈다.

	printf("빛의 속도는 : %lf km/s\n", LightSpeed);	// 빛의 속도를 출력한다.
	printf("태양과 지구와의 거리는 : %lf km\n", Distance);	// 태양과 지구 사이의 거리를 출력한다.
	printf("도달 시간은 : %lf 분\n", Time);			// 분 단위로 조정한 시간을 출력한다.
	
	return 0;
}
