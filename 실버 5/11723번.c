#include <stdio.h>

int main(void) {
    int n, arr[21] = {0}, a;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        char str[10] = {0};
        scanf("%s %d", str, &a);
        switch(str[0]){
            case 'r':{
                arr[a] = 0;
                break;
            }
            case 'c':{
                printf("%d\n", arr[a]);
                break;
            }
            case 't':{
                arr[a] = arr[a] == 0 ? 1 : 0;
                break;
            }
            case 'e': {
                for (int j = 1; j < 21; j++) arr[j] = 0;
                break;
            }
            default:{
                if(str[1] == 'd') arr[a] = 1;
                else {
                    for (int j = 1; j < 21; j++) arr[j] = 1;
                }
            }
        }
    }
}