#pragma warning (disable: 4996)
#pragma warning (disable: 6031)

#include <stdio.h>

int main(void) {
	int a, ten,i;
	scanf("%d", &a);
	for ( i = 0; i <= a; i++){
		int dab = 0;
		for (ten = 1; i / ten != 0; ten *= 10){
			dab += i / ten % 10;
		}
		if (a ==  dab + i ){
			printf("%d", i);
			return 0;
		}
	}
	printf("0");
}