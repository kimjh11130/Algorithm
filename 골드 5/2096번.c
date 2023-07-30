#include <stdio.h>

int max(int x, int y) { return x > y ? x : y; }

int min(int x, int y) { return x > y ? y : x; }

int main() {
    int n, maxs[3][100001] = {0}, mins[3][100001] = {0};
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            scanf("%d", &maxs[j][i]);
            mins[j][i] = maxs[j][i];
        }
    }
    for (int i = 1; i < n; i++) {
        maxs[0][i] += max(maxs[0][i - 1], maxs[1][i - 1]);
        maxs[1][i] += max(max(maxs[0][i - 1], maxs[1][i - 1]), maxs[2][i - 1]);
        maxs[2][i] += max(maxs[1][i - 1], maxs[2][i - 1]);

        mins[0][i] += min(mins[0][i - 1], mins[1][i - 1]);
        mins[1][i] += min(min(mins[0][i - 1], mins[1][i - 1]), mins[2][i - 1]);
        mins[2][i] += min(mins[1][i - 1], mins[2][i - 1]);
    }
    printf("%d %d", max(max(maxs[0][n - 1], maxs[1][n - 1]), maxs[2][n - 1]), min(min(mins[0][n - 1], mins[1][n - 1]), mins[2][n - 1]));
}