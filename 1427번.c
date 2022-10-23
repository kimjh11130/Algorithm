#pragma warning (disable: 4996)
#pragma warning (disable: 6031)
#include <stdio.h>

void permutation(int west, int east) {
	double i, top=1, bot=1;
	if (west > east){
		for ( i = west; i > west-east; i--){
			top *= i;
		}
		for (i = 1; i <= east; i++) {
			bot *= i;
		}
		printf("%0.lf\n", top / bot);
	}
	else if(east > west) {
		for (i = east; i > east - west; i--) {
			top *= i;
		}
		for (i = 1; i <= west; i++) {
			bot *= i;
		}
		printf("%0.lf\n", top / bot);
	}
	else{
		printf("1\n");
	}
}

int main(void) {
	int a, west, east, i;
	scanf("%d", &a);
	for ( i = 0; i < a; i++){
		scanf("%d %d", &west, &east);
		permutation(west, east);
	}
}