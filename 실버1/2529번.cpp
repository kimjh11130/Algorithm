#include <iostream>

using namespace std;

int n, vis[10];
string mx, mn = "9999999999";
char arr[10];

void back(int idx, int cur, const string &all) {
    if (idx == n) {
        if (all > mx) mx = all;
        if (all < mn) mn = all;
        return;
    }
    for (int i = 0; i < 10; i++) {
        if ((arr[idx] == 60 && !vis[i] && cur < i) || (arr[idx] == 62 && !vis[i] && cur > i)) {
            vis[i] = 1, back(idx + 1, i, all + to_string(i)), vis[i] = 0;
        }
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        scanf(" %1c", &arr[i]);
    }
    for (int i = 0; i < 10; i++)vis[i] = 1, back(0, i, to_string(i)), vis[i] = 0;
    cout << mx << "\n" << mn;
}
