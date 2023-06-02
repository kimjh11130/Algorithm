#pragma warning (disable: 4996)
#pragma warning (disable: 6031)
#include <stdio.h>
int main(void) {
	int a, b, arr[300][300] = { 0 }, i, j, value, i2, j2, i1, j1, k,l, c,d, val[10000] = {0}, f;
	scanf("%d %d", &a, &b);
	for ( i = 0; i < a; i++){
		for ( j = 0; j < b; j++){
			scanf("%d", &value);
			arr[i][j] = value;
		}
	}
	scanf("%d", &a);
	for ( f=0 ; f < a; f++){
	value = 0;
		scanf("%d %d %d %d", &i1, &j1, &i2,&j2);
		i = i1 - 1;
		j = j1 - 1;
		k = i2 - 1;
		l = j2 - 1;
		for (c=i; c <= k; c++){
			for ( d=j; d <= l; d++){
				value += arr[c][d];
			}
		}
		val[f] = value;
	}
	for ( c = 0; val[c] != NULL; c++){
		printf("%d\n", val[c]);
	}
}