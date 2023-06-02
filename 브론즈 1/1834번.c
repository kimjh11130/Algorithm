#pragma warning (disable: 4996)
#pragma warning (disable: 6031)

#include <stdio.h>

int main(void) {
	long long int a, i;
	long long value = 0;
	scanf("%lld", &a);
	for ( i = 1; i < a; i++){
		value = value + (i * a) + i;
	}
	printf("%lld", value);
}