#include <stdio.h>

int factorial(int num){
    if(num <= 1){
        return 1;
    }
    return num * factorial(num-1);
}

int main(void){
    int n, r;
    scanf("%d %d",&n ,&r);
    printf("%d", factorial(n) / factorial(r) / factorial(n-r));
}