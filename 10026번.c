#include <stdio.h>

char memo[101][101];

void checkNormal(int x, int y, int range, char rgb) {
    if (x < 0 || y < 0 || x > range || y > range) {
        return;
    } else if (memo[x][y] != rgb) {
        return;
    } else if (memo[x][y] == 'B') {
        memo[x][y] = 'C';
        checkNormal(x + 1, y, range, rgb);
        checkNormal(x - 1, y, range, rgb);
        checkNormal(x, y + 1, range, rgb);
        checkNormal(x, y - 1, range, rgb);
        return;
    } else {
        memo[x][y] = 'D';
        checkNormal(x + 1, y, range, rgb);
        checkNormal(x - 1, y, range, rgb);
        checkNormal(x, y + 1, range, rgb);
        checkNormal(x, y - 1, range, rgb);
        return;
    }
}

void checkDisabled(int x, int y, int range, char rgb) {
    if (x < 0 || y < 0 || x > range || y > range) {
        return;
    } else if(memo[x][y] != rgb){
        return;
    } else{
        memo[x][y] = 'A';
        checkDisabled(x + 1, y, range, rgb);
        checkDisabled(x - 1, y, range, rgb);
        checkDisabled(x, y + 1, range, rgb);
        checkDisabled(x, y - 1, range, rgb);
        return;
    }
}

int main(void) {
    int n, result1 = 0, result2 = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", memo[i]);
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (memo[i][j] == 'R' || memo[i][j] == 'G' || memo[i][j] == 'B') {
                checkNormal(i, j, n - 1, memo[i][j]);
                result1++;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (memo[i][j] == 'C' || memo[i][j] == 'D') {
                checkDisabled(i, j, n - 1, memo[i][j]);
                result2++;
            }
        }
    }
    printf("%d %d", result1, result2);
}

