#include<stdio.h>

int w, h, arr[101][101] = {0}, visited[101][101] = {0}, all[10000] = {0}, value = 0;

void checkZero(int x, int y) {
    arr[x][y] = 2;
    if (x + 1 < w && !arr[x + 1][y]) {
        checkZero(x + 1, y);
        arr[x + 1][y] = 2;
    }
    if (x - 1 >= 0 && !arr[x - 1][y]) {
        checkZero(x - 1, y);
        arr[x - 1][y] = 2;
    }
    if (y + 1 < h && !arr[x][y + 1]) {
        checkZero(x, y + 1);
        arr[x][y + 1] = 2;
    }
    if (y - 1 >= 0 && !arr[x][y - 1]) {
        checkZero(x, y - 1);
        arr[x][y - 1] = 2;
    }
}

void checkTwo(int x, int y) {
    arr[x][y] = 0;
    if (x + 1 < w && arr[x + 1][y] == 2) {
        checkTwo(x + 1, y);
        arr[x + 1][y] = 0;
    }
    if (x - 1 >= 0 && arr[x - 1][y] == 2) {
        checkTwo(x - 1, y);
        arr[x - 1][y] = 0;
    }
    if (y + 1 < h && arr[x][y + 1] == 2) {
        checkTwo(x, y + 1);
        arr[x][y + 1] = 0;
    }
    if (y - 1 >= 0 && arr[x][y - 1] == 2) {
        checkTwo(x, y - 1);
        arr[x][y - 1] = 0;
    }
}

void dfs(int x, int y) {
    ++all[value];
    if (arr[x + 1][y] == 2 || arr[x - 1][y] == 2 || arr[x][y + 1] == 2 || arr[x][y - 1] == 2) {
        arr[x][y] = 5;
    }
    if (x + 1 < w && arr[x + 1][y] == 1 && !visited[x + 1][y]) {
        visited[x + 1][y] = 1;
        dfs(x + 1, y);
    }
    if (x - 1 >= 0 && arr[x - 1][y] == 1 && !visited[x - 1][y]) {
        visited[x - 1][y] = 1;
        dfs(x - 1, y);
    }
    if (y + 1 < h && arr[x][y + 1] == 1 && !visited[x][y + 1]) {
        visited[x][y + 1] = 1;
        dfs(x, y + 1);
    }
    if (y - 1 >= 0 && arr[x][y - 1] == 1 && !visited[x][y - 1]) {
        visited[x][y - 1] = 1;
        dfs(x, y - 1);
    }
    return;
}

int main(void) {
    value = 0;
    scanf("%d %d", &w, &h);
    for (int i = 0; i < w; i++) {
        for (int j = 0; j < h; j++) {
            scanf("%d", &arr[i][j]);
        }
    }
    while (1) {
        value++;
        checkZero(0, 0);
        for (int i = 0; i < w; i++) {
            for (int j = 0; j < h; j++) {
                visited[i][j] = 0;
            }
        }
        int cnt = 0;
        for (int i = 0; i < w; i++) {
            for (int j = 0; j < h; j++) {
                if (arr[i][j] == 1 && !visited[i][j]) {
                    dfs(i, j);
                    cnt++;
                }
            }
        }
        for (int i = 0; i < w; i++) {
            for (int j = 0; j < h; j++) {
                if (arr[i][j] == 5) {
                    arr[i][j] = 2;
                }
            }
        }
        checkTwo(0,0);
        if (!cnt) {
            printf("%d\n%d", value-1, all[value-1]);
            break;
        }
    }
}