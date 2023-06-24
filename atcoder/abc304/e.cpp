#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define vi vector<int>
#define pii pair<int,int>

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);
    
    int n, m;
    cin >> n >> m;

    vector<vi> G(n);
    FOR(i, 0, m) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    vi king(n, -1);
    function<void(int)> dfs = [&](int u) {
        for (int v : G[u]) if (king[v] == -1) {
            king[v] = king[u];
            dfs(v);
        }
    };

    FOR(u, 0, n) if (king[u] == -1) {
        king[u] = u;
        dfs(u);
    }

    int k;
    cin >> k;
    set<pii> bad;
    FOR(i, 0, k) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        u = king[u]; v = king[v];
        if (u > v) swap(u, v);

        bad.emplace(u, v);
    }

    int Q;
    cin >> Q;
    FOR(q, 0, Q) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        u = king[u]; v = king[v];
        if (u > v) swap(u, v);

        if (bad.count({u, v})) cout << "No\n";
        else cout << "Yes\n";
    }
}