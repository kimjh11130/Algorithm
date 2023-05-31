#include <stdio.h>
#include <string.h>

int main(void) {
    char arr[1000001], stack[1000001];
    int top = -1;
    scanf("%s", arr);
    int length = strlen(arr);
    for (int i = 0; i < length; i++) {
        stack[++top] = arr[i];
        if (i >= 3 && stack[top] == 'P' && stack[top - 1] == 'A' && stack[top - 2] == 'P' && stack[top - 3] == 'P') {
            top -= 3;
        }
    }
    if (stack[top] == 'P' && top == 0) {
        printf("PPAP");
    } else {
        printf("NP");
    }
}