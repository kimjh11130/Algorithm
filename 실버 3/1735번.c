#pragma warning (disable: 4996)
#pragma warning (disable: 6031)
#include <stdio.h>

int Euclidean(int a, int b)
{
	int r = a % b;
	if (r == 0) {
		return b;
	}
	return Euclidean(b, r);
}

int main(void) {
	int a1, b1, a2, b2 ,i;
	int bunmo, bunja, value;
	scanf("%d %d", &a1, &b1);
	scanf("%d %d", &a2, &b2);
	bunmo = b1 * b2;
	bunja = a1 * b2 + a2 * b1;
	value = Euclidean(bunmo, bunja);
	bunmo /= value;
	bunja /= value;
	printf("%d %d", bunja, bunmo);
}