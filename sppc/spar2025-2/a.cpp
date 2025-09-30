#include <bits/stdc++.h>
using namespace std;

#define int long long
#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define ROF(i, a, b) for (int i=(a); i>(b); --i)
#define vi vector<int>
#define vvi vector<vi>

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int n, m;
    cin >> n >> m;

    vvi G(n);
    FOR(i, 0, m) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    vi seen(n);
    int tot = 0;
    function<void(int)> dfs = [&](int u) {
        for (int v : G[u]) if (!seen[v]) {
            seen[v] = true;
            ++tot;
            dfs(v);
        }
    };

    int res = 0;
    FOR(u, 0, n) {
        if (!seen[u]) {
            int prev = tot;
            seen[u] = true;
            ++tot;
            dfs(u);
            res = max(res, tot-prev);
        }
    }
    cout << res << '\n';
}