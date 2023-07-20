#include <stdio.h>

int gcd(int a, int b){
    int tmp;
    while(b){
        tmp = a % b;
        a = b;
        b = tmp;
    }
    return a;
}

int main(void) {
    int a, b, result;
    scanf("%d %d", &a, &b);
    result = a > b ? gcd(a,b) : gcd(b,a);
    printf("%d\n%d", result, result*(a/result)*(b/result));
}