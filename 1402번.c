#pragma warning (disable: 4996)
#pragma warning (disable: 6031)

#include <stdio.h>
int main(void) {
	int i, a, f, l;
	scanf("%d", &a);
	for (i = 0; i < a; i++) {
		scanf("%d %d", &f, &l);
		printf("yes\n");
	}
}