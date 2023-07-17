#include <stdio.h>
#include <stdlib.h>

int min(int a, int b) {
    return a > b ? b : a;
}

int upComp(const void *a, const void *b) { //정렬 알고리즘 오름차순
    return *(int *) a - *(int *) b;
}

int main(void) {
    int b, c, d, bprice[1001], cprice[1001], dprice[1001], all = 0;
    scanf("%d %d %d", &b, &c, &d);
    for (int i = 0; i < b; ++i) {
        scanf("%d", &bprice[i]);
        all += bprice[i];
    }
    for (int i = 0; i < c; ++i) {
        scanf("%d", &cprice[i]);
        all += cprice[i];
    }
    for (int i = 0; i < d; ++i) {
        scanf("%d", &dprice[i]);
        all += dprice[i];
    }
    qsort(bprice, b, 4, upComp);
    qsort(cprice, c, 4, upComp);
    qsort(dprice, d, 4, upComp);
    int a = min(min(b,c),d), result = all;
    for (int i = b-1; i >= b - a; i--) {
        result -= bprice[i]/10;
    }
    for (int i = c-1; i >= c - a; i--) {
        result -= cprice[i]/10;
    }
    for (int i = d-1; i >= d - a; i--) {
        result -= dprice[i]/10;
    }
    printf("%d\n%d", all, result);
}