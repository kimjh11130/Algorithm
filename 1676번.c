#pragma warning (disable: 4996)
#pragma warning (disable: 6031)

#include <stdio.h>

int count5(int num) {
	int i;
	for (i = 0; num % 5 == 0; i++) {
		num /= 5;
	}
	return i;
}

int main(void) {
	int a, b, i, num5 = 0;
	scanf("%d", &a);
	for ( i = 1; i <= a; i++){
		if (i % 5 == 0) {
			num5 += count5(i);
		}
	}
	printf("%d", num5);
}