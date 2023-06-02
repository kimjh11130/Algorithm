#pragma warning (disable: 4996)
#pragma warning (disable: 6031)

#include <stdio.h>

void selection_sort(int arr[], int n) {
	int least, tmp;
	for (int i = 0; i < n - 1; i++) {
		least = i;
		for (int j = i + 1; j < n; j++) {
			if (arr[least] > arr[j])
				least = j;
		}
		tmp = arr[i];
		arr[i] = arr[least];
		arr[least] = tmp;
	}
}

int main(void) {
	int arr1[50] = { 0 }, arr2[50] = { 0 };
	int a, i, s = 0;
	scanf("%d", &a);
	for ( i = 0; i < a; i++){
		scanf("%d", &arr1[i]);
	}
	for (i = 0; i < a; i++) {
		scanf("%d", &arr2[i]);
	}

	selection_sort(arr1, a);
	selection_sort(arr2, a);

	for (i = 0; i < a; i++) {
		s += arr1[i] * arr2[a - i - 1];
	}
	printf("%d", s);
}