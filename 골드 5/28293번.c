#include <stdio.h>
#include <math.h>

int main() {
    double a, b;
    scanf("%lf %lf", &a, &b);
    printf("%d", (int)(log10(a)*b) + 1);
}