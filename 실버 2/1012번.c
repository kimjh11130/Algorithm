#include <stdio.h>
#include <memory.h>

int width, height;
int ground[51][51] = {0};

void here(int x, int y){
    if(x < 0 || y < 0 || x > width || y > height || ground[x][y] == 0) return;
    ground[x][y] = 0;
    here(x+1,y);
    here(x-1,y);
    here(x,y+1);
    here(x,y-1);
}

int main(void){
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int w, cnt = 0;
        memset(ground, 0, 50);
        scanf("%d %d %d",&width ,&height ,&w);
        for (int j = 0; j < w; j++) {
            int x1, y1;
            scanf("%d %d", &x1, &y1);
            ground[x1][y1]++;
        }
        for (int j = 0; j < width; j++) {
            for (int k = 0; k < height; k++) {
                if(ground[j][k] == 1) {
                    here(j, k);
                    cnt++;
                }
            }
        }
        printf("%d\n", cnt);
    }
}