#pragma warning (disable: 4996)
#pragma warning (disable: 6031)
#include <stdio.h>
int main(void) {
	int m, d, i, cal;
	scanf("%d %d", &m, &d);
	cal = d;
	for ( i = m-1; i > 0; i--){
		switch (i)
		{
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12: {
			cal += 31;
			break;
		}
		case 4:
		case 6:
		case 9:
		case 11: {
			cal += 30;
			break;
		}
		case 2: {
			cal += 28;
			break;
		}
		default: {
			break;
		}
		}
	}
	switch (cal % 7){
	case 1: {
		printf("MON");
		break;
	}
	case 2: {
		printf("TUE");
		break;
	}
	case 3: {
		printf("WED");
		break;
	}
	case 4: {
		printf("THU");
		break;
	}
	case 5: {
		printf("FRI");
		break;
	}
	case 6: {
		printf("SAT");
		break;
	}
	case 0: {
		printf("SUN");
		break;
	}
	}
}