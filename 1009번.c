#include <stdio.h>

int memo[10] ={0};
int a,b;

void give(int num){
    int i = 1;
    int c;
    memo[0] = num;
    memo[1] = num * num % 10;
    while(memo[0] != memo[i]){
        memo[i+1] = memo[i] * num % 10;
        i++;
    }
    c = b % i;
    if(b % i != 0){
        c--;
    } else{
      c = i - 1;
    }
    if(memo[c] == 0){
        memo[c] = 10;
    }
    printf("%d \n", memo[c]);
}

int main(void){
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &a, &b);
        give(a%10);
    }
}