#include <bits/stdc++.h>
using namespace std;

#define int long long
#define FOR(i, a, b) for (int i=(a); i<(b); ++(i))
#define vi vector<int>

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<vector<vi>> g(n+m, vector<vi>(2));
    FOR(i, 0, n) {
        int an;
        cin >> an;
        FOR(j, 0, an) {
            int x;
            cin >> x;
            --x;
            g[x][1].push_back(m+i);
            g[m+i][0].push_back(x);
        }
    }

    deque<int> q = {0};
    vi dist(n+m, -1);
    while (!q.empty()) {
        int u = q.front();
        q.pop_front();
        for (int v : g[u][0]) if (dist[v] == -1) {
            dist[v] = dist[u];
            q.push_front(v);
        }
        for (int v : g[u][1]) if (dist[v] == -1) {
            dist[v] = 1 + dist[u];
            q.push_back(v);
        }
    }

    cout << dist[m-1];
}