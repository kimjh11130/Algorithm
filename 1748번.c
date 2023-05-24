#include <stdio.h>

int main(void){
    int n, ten = 9, total = 0;
    scanf("%d", &n);
    for (int i = 1; i < 100; i++) {
        if(n - ten > 0){
            n -= ten;
            total += ten * i;
            ten *= 10;
        } else {
            total += n * i;
            break;
        }
    }
    printf("%d", total);
}