#include <stdio.h>

int main(void){
    int n, cnt = 0;
    scanf("%d",&n);
    while(n % 5 != 0){
        cnt++;
        n -= 3;
    }
    while (n > 0){
        cnt++;
        n -= 5;
    }
    printf("%d", n ? -1 : cnt );
}