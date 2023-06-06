#include <stdio.h>

int main(void) {
    int f = 0;
    char stack[51] = {0}, arr[51]={0};
    scanf("%s", stack);
    while(stack[f] == 'X' || stack[f] == '.'){
        if(stack[f] == '.'){
            arr[f] = '.';
            f += 1;
        } else if(stack[f] == 'X' && stack[f+1] == 'X' && stack[f+2] == 'X' && stack[f+3] == 'X'){
            arr[f] = 'A';
            arr[f+1] = 'A';
            arr[f+2] = 'A';
            arr[f+3] = 'A';
            f += 4;
        } else if(stack[f] == 'X' && stack[f+1] == 'X') {
            arr[f] = 'B';
            arr[f+1] = 'B';
            f += 2;
        } else {
            printf("-1");
            return 0;
        }
    }
    for (int i = 0; i < f; i++) {
        printf("%c", arr[i]);
    }
}