#pragma warning (disable: 4996)
#pragma warning (disable: 6031)
#include <stdio.h>
int main(void) {
	int a, i, max =0;
	float arr[1000] = {0}, arrage = 0;
	scanf("%d", &a);
	for ( i = 0; i < a; i++){
		scanf("%f", &arr[i]);
		if (max < arr[i]){
			max = arr[i];
		}
	}
	for ( i = 0; i < a; i++){
		arrage = arrage + arr[i] / max * 100;
	}
	printf("%f", arrage / a);
}