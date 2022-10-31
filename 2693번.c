#pragma warning (disable: 4996)
#pragma warning (disable: 6031)

#include <stdio.h>
int sorted[10];
int n = 3;
void merge(int a[], int m, int mid, int n) {
	int i = m;
	int j = mid + 1;
	int k = m;

	while (i <= mid && j <= n) {
		if (a[i] >= a[j]) { //내림차순 
			sorted[k] = a[i];
			i++;
		}
		else {
			sorted[k] = a[j];
			j++;
		}
		k++;
	}
	if (i > mid) {
		for (int t = j; t <= n; t++) {
			sorted[k] = a[t];
			k++;
		}
	}
	else {
		for (int t = i; t <= mid; t++) {
			sorted[k] = a[t];
			k++;
		}
	}
	for (int t = m; t <= n; t++) {
		a[t] = sorted[t];
	}
}
void mergeSort(int a[], int m, int n) {
	if (m < n) {
		int mid = (m + n) / 2;
		mergeSort(a, m, mid);
		mergeSort(a, mid + 1, n);
		merge(a, m, mid, n);
	}
}
int main()
{
	int a[10], t;
	scanf("%d", &t);
	for (int i = 0; i < t; i++) {
		for (int j = 0; j < 10; j++) {
			scanf("%d", &a[j]);
		}
		mergeSort(a, 0, 9);
		printf("%d\n", a[n - 1]);
	}

}