#pragma warning (disable: 4996)
#pragma warning (disable: 6031)

#include <stdio.h>

int main(void) {
	char arr[1000000] = { 0 }, num[10] = { 0 };
	int i, a, tmp = 0;
	scanf("%s", &arr);
	for ( i = 0;arr[i] != NULL; i++){
		num[arr[i] - 48]++;
	}
	if ((num[6] + num[9]) %2==1){
		num[6] = (num[6] + num[9] + 1) / 2;
	}
	else {
		num[6] = (num[6] + num[9]) / 2;
	}
	num[9] = 0;
	for ( i = 0; i < 10; i++){
		if (num[i] > tmp) {
			tmp = num[i];
		}
	}
	printf("%d", tmp);
}