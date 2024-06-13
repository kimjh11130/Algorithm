#include <stdio.h>

int main() {
    int t=0;
    double a=1,b,m=1;
    while (t++!=10)scanf("%lf",&b),m=b>m?m:b,a*=b*10/t;
    printf("%lf",a/m);
}