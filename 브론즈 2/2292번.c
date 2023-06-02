#pragma warning (disable: 4996)
#pragma warning (disable: 6031)

#include <stdio.h>

int main(void) {
	int a, b, cnt = 1, i;
	scanf("%d", &a);
	for ( i = 1; a > cnt; i++){
		cnt += i * 6;
	}
	printf("%d", i);
}