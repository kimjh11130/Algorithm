#include <stdio.h>
#include <string.h>

int main() {
    char arr[101] = {0};
    gets(arr);
    while (strlen(arr) != 1 || arr[0] != '.') {
        int top = 0, c = 1;
        char stack[101] = {0};
        for (int i = 0; i < strlen(arr); i++) {
            if (arr[i] == '(' || arr[i] == '[') {
                stack[++top] = arr[i];
            } else if (arr[i] == ')') {
                if (stack[top] == '(') --top;
                else {
                    c = 0;
                    break;
                }
            } else if (arr[i] == ']') {
                if (stack[top] == '[') --top;
                else {
                    c = 0;
                    break;
                }
            }
        }
        printf("%s\n", c == 1 && top == 0 ? "yes" : "no");
        gets(arr);
    }
}