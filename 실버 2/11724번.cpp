#include <iostream>
#include <vector>

using namespace std;

bool vis[1000] = {false};
vector<int> graph[1001];

void dfs(int x){
    for(auto n: graph[x]){
        if(!vis[n]) vis[n] = true, dfs(n);
    }
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n, m, a, b, cnt = 0;
    cin >> n >> m;
    while (m--) {
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    for (int i = 1; i <= n; i++) {
        if(!vis[i]) vis[i] = true,dfs(i), cnt++;
    }
    cout << cnt;
}
