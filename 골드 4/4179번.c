#include <stdio.h>

struct element {
    int x;
    int y;
    int c;
    char item;
};

int r = 0, f = -1;
char arr[1005][1005] = {0};
struct element que[1000000] = {0};


int main(void) {
    int R, C;
    scanf("%d %d", &R, &C);
    for (int i = 1; i <= R; i++) {
        for (int j = 1; j <= C; j++) {
            scanf(" %1c", &arr[i][j]);
            if (arr[i][j] == 'J') {
                que[0].x = i;
                que[0].y = j;
                que[0].c = 1;
                que[0].item = arr[i][j];
            } else if (arr[i][j] == 'F') {
                que[++r].x = i;
                que[r].y = j;
                que[r].c = 1;
                que[r].item = arr[i][j];
            }
        }
    }
    while (f < r) {
        int x = que[++f].x;
        int y = que[f].y;
        int c = que[f].c;
        char item = que[f].item;
        if (item == 'F') {
            if (arr[x + 1][y] == '.' || arr[x + 1][y] == 'J') {
                que[++r].x = x + 1;
                que[r].y = y;
                que[r].c = c + 1;
                que[r].item = 'F';
                arr[x + 1][y] = 'F';
            }
            if (arr[x - 1][y] == '.' || arr[x - 1][y] == 'J') {
                que[++r].x = x - 1;
                que[r].y = y;
                que[r].c = c + 1;
                que[r].item = 'F';
                arr[x - 1][y] = 'F';
            }
            if (arr[x][y + 1] == '.' || arr[x][y + 1] == 'J') {
                que[++r].x = x;
                que[r].y = y + 1;
                que[r].c = c + 1;
                que[r].item = 'F';
                arr[x][y + 1] = 'F';
            }
            if (arr[x][y - 1] == '.' || arr[x][y - 1] == 'J') {
                que[++r].x = x;
                que[r].y = y - 1;
                que[r].c = c + 1;
                que[r].item = 'F';
                arr[x][y - 1] = 'F';
            }
        } else {
            if ((x == R || y == C || x == 1 || y == 1) && arr[x][y] == 'J') {
                printf("%d", c);
                return 0;
            }
            if (arr[x + 1][y] == '.') {
                que[++r].x = x + 1;
                que[r].y = y;
                que[r].c = c + 1;
                que[r].item = 'J';
                arr[x + 1][y] = 'J';
            }
            if (arr[x - 1][y] == '.') {
                que[++r].x = x - 1;
                que[r].y = y;
                que[r].c = c + 1;
                que[r].item = 'J';
                arr[x - 1][y] = 'J';
            }
            if (arr[x][y + 1] == '.') {
                que[++r].x = x;
                que[r].y = y + 1;
                que[r].c = c + 1;
                que[r].item = 'J';
                arr[x][y + 1] = 'J';
            }
            if (arr[x][y - 1] == '.') {
                que[++r].x = x;
                que[r].y = y - 1;
                que[r].c = c + 1;
                que[r].item = 'J';
                arr[x][y - 1] = 'J';
            }
        }
    }
    printf("IMPOSSIBLE");
}