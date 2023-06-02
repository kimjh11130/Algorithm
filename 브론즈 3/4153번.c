#pragma warning (disable: 4996)
#pragma warning (disable: 6031)
#include <stdio.h>

int main(void) {
	int a, b, c, heru,asuar,auset;
	scanf("%d %d %d", &a, &b, &c);
	while (a !=0 || b != 0 || c != 0){
		if (a > b && a >c){
			heru = a;
			asuar = b;
			auset = c;
		}
		else if (b > a && b > c) {
			heru = b;
			asuar = a;
			auset = c;
		}
		else if (c >= a && c >= b) {
			heru = c;
			asuar = a;
			auset = b;
		}

		if (heru*heru == asuar*asuar + auset*auset){
			printf("right\n");
		}
		else{
			printf("wrong\n");
		}
		scanf("%d %d %d",&a,&b,&c);
	}
}