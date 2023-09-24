#include <bits/stdc++.h>
using namespace std;

typedef long long lg;
#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define ROF(i, a, b) for (int i=(a); i>(b); --i)
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int,int>

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    vvi edges(m), vals(n);
    FOR(i, 0, m) {
        int u, v, w;
        cin >> u >> v >> w;
        --u; --v;
        edges[i] = {u, v, w};
        vals[u].push_back(w);
        vals[v].push_back(w);
    }
    int upp = 2e9;
    FOR(u, 0, n) if (vals[u].size() >= 2) {
        sort(vals[u].begin(), vals[u].end());
        upp = min(upp, vals[u][0] + vals[u][1]);
    }

    auto check = [&](int k) {
        vvi G(n);
        for (vi& edge : edges) if (edge[2] < k) {
            G[edge[0]].push_back(edge[1]);
            G[edge[1]].push_back(edge[0]);
        }

        vi col(n, -1);
        function<bool(int)> dfs = [&](int u) {
            for (int v : G[u]) {
                if (col[v] == col[u]) return false;
                if (col[v] == -1) {
                    col[v] = !col[u];
                    if (!dfs(v)) return false;
                }
            }
            return true;
        };

        FOR(u, 0, n) if (col[u] == -1) {
            col[u] = 0;
            if (!dfs(u)) return false;
        }
        return true;
    };

    int k = 0;
    for (int b=upp; b>=1; b/=2) {
        while ((lg)k+b<=upp && check(k+b)) k += b;
    }
    cout << k;
}