#pragma warning (disable: 4996)
#pragma warning (disable: 6031)
#include <stdio.h>

int main(void) {
	int a, i;
	int arr[100000] ={ 0 };
	int countZero = 0, number, answer = 0;
	scanf("%d", &a);
	for ( i = 0; i < a; i++){
		scanf("%d", &number);
		if (number != 0){
			answer += number;
			arr[countZero++] = number;
		}
		else {
			answer -= arr[--countZero];
			arr[countZero] = 0;
		}
	}
	printf("%d", answer);
}