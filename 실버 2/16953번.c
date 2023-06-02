#include <stdio.h>

int out = 1;

int greedy(long long int x, long long int max, int cnt){
    if(x == max) {
        printf("%d", cnt+1);
        out = 0;
        return 0;
    } else if(x > max){
        return 0;
    }
    greedy(x * 2, max, cnt+1);
    greedy(x*10+1, max, cnt+1);
    return 0;
}

int main(void){
    int a,b, result = 0;
    scanf("%d %d",&a,&b);
    greedy(a,b, result);
    if(out){
        printf("-1");
    }
}