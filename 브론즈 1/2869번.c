#pragma warning (disable: 4996)
#pragma warning (disable: 6031)

#include <stdio.h>

int main(void) {
	int up, down, max, time;
	scanf("%d %d %d", &up, &down, &max);
	if (up == max) {
		printf("1");
		return 0;
	}
	max -= up;
	time = max / (up - down);
	if (max % (up - down) != 0 || (up - down) > max){
		time += 1;
	}
	printf("%d", time + 1);
}