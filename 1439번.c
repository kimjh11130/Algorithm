#pragma warning (disable: 4996)
#pragma warning (disable: 6031)

#include <stdio.h>
int main(void) {
	char arr[1000000] = { 0 };
	int i, j, cnt = 0;
	scanf("%s", &arr);
	for (i = 0; arr[i] != NULL && arr[0] == 48; i++) {
		if (arr[i] == 49){
			for (i; arr[i] == 49; i++);
			cnt++;
		}
	}
	for (i = 0; arr[i] != NULL && arr[0] == 49; i++) {
		if (arr[i] == 48) {
			for (i; arr[i] == 48; i++);
			cnt++;
		}
	}
	printf("%d", cnt);
}