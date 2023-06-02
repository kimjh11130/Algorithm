//#pragma warning (disable: 4996)
//#pragma warning (disable: 6031)
//
//#include <stdio.h>
//
//int yun(int year, int month) {
//	int i, cnt=0;
//	for ( i = 1; i < year; i++){
//		if (i % 4 == 0 && i% 100 != 0 ) {
//			cnt++;
//		}
//		else if (i % 400 == 0){
//			cnt++;
//		}
//	}
//	if ( month > 2) {
//		if (year % 4 == 0 && year % 100 != 0) {
//			cnt++;
//		}
//		else if (year % 400 == 0) {
//			cnt++;
//		}
//	}
//	return cnt;
//}
//
//int month(int month) {
//	int mon=0;
//	int i;
//	for (i = month-1; i > 0; i--) {
//		switch (i) {
//		case 1:
//		case 3:
//		case 5:
//		case 7:
//		case 8:
//		case 10:
//		case 12: {
//			mon += 31;
//			break;
//		}
//		case 4:
//		case 6:
//		case 9:
//		case 11: {
//			mon += 30;
//			break;
//		}
//		case 2: {
//			mon += 28;
//			break;
//		}
//		}
//	}
//	return mon;
//}
//
//int main(void) {
//	int y1, y2, m1, m2, d1, d2, value1 = 0, value2 = 0;
//	scanf("%d %d %d", &y1, &m1, &d1);
//	scanf("%d %d %d", &y2, &m2, &d2);
//	value1 = y1 * 365 + month(m1) + d1 + yun(y1, m1);
//	value2 = y2 * 365 + month(m2) + d2 + yun(y2, m2);
//	if (value2-value1 >= 365243){
//		printf("gg");
//	}
//	else{
//		printf("D-%d", value2 - value1);
//	}
//}