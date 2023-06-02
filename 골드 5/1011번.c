#include <stdio.h>

int main(void){
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int first, last, distance;
        int count = 0;
        scanf("%d %d", &first ,&last);
        distance = last - first;
        do{
            count++;
            if(count % 2 == 1){
                distance -= (count + 1) / 2;
            } else{
                distance -= count / 2;
            }
        } while (distance > 0);

        printf("%d\n", count);
    }
}