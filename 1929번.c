#pragma warning (disable: 4996)
#pragma warning (disable: 6031)

#include <stdio.h>

void calculater(int value) {
	int i, cnt = 2;
	for ( i = 2; i * i <= value && value % i != 0; i++){
		cnt++;
	}
	if (cnt * cnt > value || cnt == 1000){
		printf("%d\n", value);
	}
}

int main() {
	int i, a, b;
	scanf("%d %d", &a, &b);
	if (a == 1){
		a = 2;
	}
	for ( i = a; i <= b; i++){
		calculater(i);
	}
}