#include <stdio.h>

struct element{
    int x;
    int y;
    int c;
};

int x1, y1;
struct element que[2501] = {0};
char arr[51][51] = {0}, copy[51][51] ={0};

int bfs(){
    int tmp = 0, f = -1, r = 0;;
    for (int i = 0; i < x1; i++) {
        for (int j = 0; j < y1; j++) {
            copy[i][j] = arr[i][j];
        }
    }
    while(r > f){
        int x = que[++f].x;
        int y = que[f].y;
        int c = que[f].c;
        copy[x][y] = 'W';
        if(x >= 0 && y >= 0 && x < x1 && y < y1){
            if(copy[x+1][y] == 'L'){
                copy[x+1][y] = 'W';
                que[++r].x = x + 1;
                que[r].y = y;
                que[r].c = c + 1;
            }
            if(copy[x-1][y] == 'L'){
                copy[x-1][y] = 'W';
                que[++r].x = x - 1;
                que[r].y = y;
                que[r].c = c + 1;
            }
            if(copy[x][y+1] == 'L'){
                copy[x][y+1] = 'W';
                que[++r].x = x;
                que[r].y = y + 1;
                que[r].c = c + 1;
            }
            if(copy[x][y-1] == 'L'){
                copy[x][y-1] = 'W';
                que[++r].x = x;
                que[r].y = y - 1;
                que[r].c = c + 1;
            }
        }
        tmp = c > tmp ? c : tmp;
    }
    return tmp;
}

int main(void) {
    int tmp = 0;
    scanf("%d %d", &x1, &y1);
    for (int i = 0; i < x1; i++) {
        scanf("%s", arr[i]);
    }
    for (int i = 0; i < x1; i++) {
        for (int j = 0; j < y1; j++) {
            if(arr[i][j] == 'L'){
                que[0].x = i;
                que[0].y = j;
                que[0].c = 0;
                int tep = bfs();
                tmp = tep > tmp ? tep : tmp;
            }
        }
    }
    printf("%d", tmp);
}