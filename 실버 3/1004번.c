#include <stdio.h>
#include <math.h>

int main(void){
    int  t, banbok;
    int x1, y1, x2, y2, rx, ry, r;
    scanf("%d", &t);
    for (int i = 0; i < t; i++) {
        int in = 0, out = 0;
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        scanf("%d", &banbok);
        for (int j = 0; j < banbok; j++) {
            double d1, d2;

            scanf("%d %d %d", &rx, &ry, &r);

            d1 = sqrt((x1 - rx) * (x1 - rx) + (y1 - ry) * (y1 - ry));
            d2 = sqrt((x2 - rx) * (x2 - rx) + (y2 - ry) * (y2 - ry));

            if(d1 < r && d2 > r){
                out++;
            } else if(d1 > r && d2 < r){
                in++;
            }
        }
        printf("%d\n", in + out);
    }
}
