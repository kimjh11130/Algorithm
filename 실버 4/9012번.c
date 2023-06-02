#pragma warning (disable: 4996)
#pragma warning (disable: 6031)

#include <stdio.h>

int check(char list[]) {
	int i, value = 0;
	for (i = 0; list[i] != NULL; i++) {
		if (list[i] == 40) {
			value++;
		}
		else {
			value--;
		}
		if (value < 0) {
			break;
		}
	}
	if (value == 0) {
		printf("YES\n");
	}
	else {
		printf("NO\n");
	}
	return 0;
}

int main(void) {
	int a, i;
	scanf("%d", &a);
	for (i = 0; i < a; i++) {
		char arr[50] = { 0 };
		scanf("%s", &arr);
		check(arr);
	}
}