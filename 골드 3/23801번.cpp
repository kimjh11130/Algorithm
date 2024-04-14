#include <iostream>
#include <queue>
#include <vector>

#define MAX 1e13

using namespace std;
typedef long long ll;

int n;
vector<pair<int, ll>> graph[100001];

void dijk(int f, vector<ll> &dist) {
    priority_queue<pair<ll, int>> que;
    que.emplace(0, f), dist[f] = 0;
    while (!que.empty()) {
        auto [d, x] = que.top();
        que.pop(), d = -d;
        if (dist[x] < d) continue;
        for (auto [ran, val]: graph[x]) {
            if (dist[ran] > d + val) {
                dist[ran] = d + val, que.emplace(-d - val, ran);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int m, u, v, w, x, z, p, a;
    cin >> n >> m;
    vector<ll> distF(n + 1, MAX), distL(n + 1, MAX);
    ll min = MAX;
    while (m--) {
        cin >> u >> v >> w;
        graph[u].emplace_back(v, w);
        graph[v].emplace_back(u, w);
    }
    cin >> x >> z >> p;
    dijk(x, distF), dijk(z, distL);
    for (int i = 0; i < p; i++) {
        cin >> a;
        if (min > distF[a] + distL[a])min = distF[a] + distL[a];
    }
    cout << (min == MAX ? -1 : min);
}