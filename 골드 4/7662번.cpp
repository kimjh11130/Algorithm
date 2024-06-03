#include <iostream>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n, t, a;
    char d;
    cin >> n;
    while (n--) {
        int cnt = 0, r = 0;
        vector<bool> vis(1000001, false);
        priority_queue<pair<int, int>> queF;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> queL;
        cin >> t;
        while (t--) {
            cin >> d >> a;
            if (d == 'I') queF.emplace(a, r), queL.emplace(a, r++), cnt++;
            else if (cnt) {
                while (!queF.empty() && vis[queF.top().second]) queF.pop();
                while (!queL.empty() && vis[queL.top().second]) queL.pop();
                if (a == 1) vis[queF.top().second] = true, queF.pop();
                else vis[queL.top().second] = true, queL.pop();
                cnt--;
            }
        }
        if (cnt > 0) {
            while (!queF.empty() && vis[queF.top().second]) queF.pop();
            while (!queL.empty() && vis[queL.top().second]) queL.pop();
            cout << queF.top().first << " " << queL.top().first << "\n";
        } else cout << "EMPTY\n";
    }
}
