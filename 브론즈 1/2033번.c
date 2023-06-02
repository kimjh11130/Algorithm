#pragma warning (disable: 4996)
#pragma warning (disable: 6031)
#include <stdio.h>

int main(void) {
	int i = 1, ten = 10, shuttle = 10;
	long long int a;
	scanf("%lld", &a);
	if (a < 10){
		printf("%lld", a);
		return 0;
	}
	while (1){
		if(a%ten < 5) {
			a = ( a / shuttle ) * shuttle;
			break;
		}
		else if (a/ten == 0){
			a = ( a / shuttle + 1 ) * shuttle;
			break;
		}
	ten *= 10;
	shuttle = ten / 10;
	i++;
	}
	printf("%lld", a);
}

