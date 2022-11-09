#pragma warning (disable: 4996)
#pragma warning (disable: 6031)
#include <stdio.h>

int bigNumber() {
	int arr[5] = { 0 }, i , j , k , value = 0;
	for ( i = 0; i < 5; i++){
		scanf("%d", &arr[i]);
	}
	for ( i = 0; i < 3; i++){
		for (j = 1; j < 4; j++) {
			if (i == j){
				continue;
			}
			for ( k = 2; k < 5; k++){
				if (j == k || i == k) {
					continue;
				}
				if (value < ( arr[i] + arr[j] + arr[k] ) % 10) {
					value = (arr[i] + arr[j] + arr[k]) % 10;
				}
			}
		}
	}
	return value;
}

int main(void) {
	int a, i, arr[5] = { 0 }, value = 0, index = 0, tmp = 0;
	scanf("%d", &a);
	for ( i = 0; i < a; i++){
		value = bigNumber();
		if (tmp <= value){
			tmp = value;
			index = i + 1;
		}
	}
	printf("%d", index);
}