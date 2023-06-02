#pragma warning (disable: 4996)
#pragma warning (disable: 6031)

#include <stdio.h>

int calculater(int value, int cnt22) {
	int i, cnt = 2;
	if (value == 1){
		return cnt22;
	}
	for ( i = 2; i * i <= value && value % i != 0; i++){
		cnt++;
	}
	if (cnt * cnt > value || cnt == 32){
		cnt22++;
	}
	return cnt22;
}

int main() {
	int i, a, b, c=0;
	scanf("%d", &a);
	for ( i = 0; i < a; i++){
		scanf("%d", &b);
		c = calculater(b, c);
	}
	printf("%d", c);
}