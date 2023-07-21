#include <bits/stdc++.h>
using namespace std;

#define int long long
#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define ROF(i, a, b) for (int i=(a); i>(b); --i)
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int,int>

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);
    
    int n1, n2, m;
    cin >> n1 >> n2 >> m;
    vvi G(n1+n2);
    FOR(i, 0, m) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    auto bfs = [&](int start) {
        queue<int> q;
        q.push(start);
        vi dist(n1+n2, -1);
        dist[start] = 0;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int v : G[u]) if (dist[v] == -1) {
                dist[v] = 1 + dist[u];
                q.push(v);
            }
        }
        return *max_element(dist.begin(), dist.end());
    };

    cout << bfs(0) + bfs(n1+n2-1) + 1;
}