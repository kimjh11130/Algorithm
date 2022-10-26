#pragma warning (disable: 4996)
#pragma warning (disable: 6031)

#include <stdio.h>
int main() {
	int i, n, f = 0, t = 0;
	int arr[2000] ={ 0 };
	scanf("%d", &n);
	for (i = 1; i <= n; i++) {
		arr[t++] = i;
	}
	while (f != t) {
		printf("%d ", arr[f++]);
		arr[t++] = arr[f++];
	}
	return 0;
}
