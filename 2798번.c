#pragma warning (disable: 4996)
#pragma warning (disable: 6031)
#include <stdio.h>

int main(void) {
	int n, m, i, j, k;
	int arr[10000] = { 0 }, dab = 0;
	scanf("%d %d", &n, &m);
	for ( i = 0; i < n; i++){
		scanf("%d", &arr[i]);
	}
	for ( i = 0; i < n-2; i++){
		for (j = i+1; j < n - 1; j++){
			for ( k = j+1; k < n; k++){
				if (m - dab > m - (arr[i] + arr[j] + arr[k]) && m - (arr[i] + arr[j] + arr[k]) >= 0) {
					dab = arr[i] + arr[j] + arr[k];
				}
			}
		}
	}
	printf("%d", dab);
}