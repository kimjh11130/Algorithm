#include <stdio.h>

int main(){
    int a, two = 2, result;
    long long int memorize[91] = {1, 1};
    scanf("%d", &a);
    for (int i = 2; a >= i ; i++){
        memorize[i] = memorize[i-1] + memorize[i-2];
    }
    printf("%lld", memorize[a-1]);
}
/*
0
 0  new
1
 1  new
2
 10 new
3
 101 1
 100 0
4
 1010 1001  1 2
 1000  0
5
 10101 10100 3
 10010 10001 1 2
 10000 0
6
 101010 101001 101000 4
 100101 100100 3
 100010 10000 1 2
 100000 0
7
 1010001 1010100 1010010 1010001 1010000 5
 1001010 1001001 1001000 4
 1000101 1000100 3
 1000010 1000001 1 2
 1000000 0
 */