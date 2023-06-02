#pragma warning (disable: 4996)
#pragma warning (disable: 6031)

#include <stdio.h>

int check(int a) {
	int b = 1, i;
	for ( i = 0; a/10 != 0; i++){
		a /= 10;
		b++;
	}
	return b;
}

void yesOrNo(int a, int b) {
	// 3 -> %10, /100 |4 -> %10 /1000, /10%10 /100%10 |5 ->%10 /10000, /10%10 /10000 
	switch (b){
	case 1: {
		printf("yes\n");
		break;
	}
	case 2: {
		if (a/10 == a % 10){
			printf("yes\n");
		}
		else {
			printf("no\n");
		}
		break;
	}
	case 3: {
		if (a % 10 == a / 100 ) {
			printf("yes\n");
		}
		else {
			printf("no\n");
		}
		break;
	}
	case 4: {
		if(a % 10 == a / 1000 && a / 10 % 10 == a / 100 % 10) {
			printf("yes\n");
		}
		else {
			printf("no\n");
		}
		break;
	}
	case 5: {
		if (a % 10 == a / 10000 && a / 10 % 10 == a / 1000 % 10) {
			printf("yes\n");
		}
		else {
			printf("no\n");
		}
		break;
	}
	}
}

int main(void) {
	int a, b, i;
	scanf("%d", &a);
	while (a != 0){
		yesOrNo(a, check(a));
		scanf("%d", &a);
	}
}