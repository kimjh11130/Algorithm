#include <stdio.h>
#include <math.h>

double distanceOfTwo(int x1,int y1, int x2,int y2){
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

int main(void){
    int x1, y1, r1, x2, y2, r2, n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d %d %d %d %d %d", &x1, &y1, &r1, &x2, &y2, &r2);
        double distance = distanceOfTwo(x1, y1, x2, y2);
        double rangeOver = r1 + r2;
        double rangeIn =  r1 - r2 > 0 ? r1 - r2 : r2 - r1;

        if (distance == 0) {
            if(r1 == r2){
                printf("-1\n");
                continue;
            }else{
                printf("0\n");
                continue;
            }
        } else{
            if (distance > rangeOver || distance < rangeIn) {
                printf("0\n");
            } else if (distance == rangeOver || distance == rangeIn) {
                printf("1\n");
            } else{
                printf("2\n");
            }
        }
    }
}