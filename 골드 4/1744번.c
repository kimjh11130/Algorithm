#include <stdio.h>
#include <stdlib.h>

int que[51] ={0}, f = 0, r = 0;

int comp(const void *a, const void *b) {
    return *(int *) b - *(int *) a;
}

int main(){
    int zero = 0;
    long long int count = 0;
    scanf("%d", &r);
    for (int i = 0; i < r; ++i) {
        scanf("%d", &que[i]);
        if(que[i] == 0) zero++;
    }
    qsort(que, r, 4, comp);
    while(que[f+1] > 0){
        if(que[f+1] == 1){
            count = count + que[f] + que[f+1];
            f += 2;
            continue;
        }
        count = count + que[f] * que[f+1];
        f += 2;
    }
    while(que[r-2] < 0){
        count = count + que[r-1] * que[r-2];
        r -= 2;
    }
    if(que[f] > 0 && f < r){
        count += que[f++];
    }
    if(que[r-1] < 0 && zero > 0 || que[r-1] >= 0){
        printf("%lld", count);
    } else {
        printf("%lld", count + que[r-1]);
    }
}
