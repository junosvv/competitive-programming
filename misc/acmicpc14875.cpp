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

    int n, k;
    cin >> n >> k;
    vi a(n);
    FOR(i, 0, n) cin >> a[i];

    vvi G(n);
    FOR(i, 0, n-1) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    vi dp(n, -1), link(n, -1), dp2(n, -1), link2(n, -1);
    auto upd = [&](int u, int v, int val) {
        if (val > dp[u] || val >= dp[u] && v < link[u]) {
            dp2[u] = dp[u];
            link2[u] = link[u];
            dp[u] = val;
            link[u] = v;
        } else if (val > dp2[u] || val >= dp2[u] && v < link2[u]) {
            dp2[u] = val;
            link2[u] = v;
        }
    };

    function<void(int,int)> dfs = [&](int u, int p) {
        for (int v : G[u]) if (v != p) {
            upd(u, v, a[v]-1);
            dfs(v, u);
            upd(u, link[v], dp[v]-1);
        }
    };
    dfs(0, 0);
    // for (int i : link) cout << i << ' ';
    // cout << '\n';
    // for (int i : link2) cout << i << ' ';
    // cout << '\n';

    function<void(int,int)> dfs2 = [&](int u, int p) {
        for (int v : G[u]) if (v != p) {
            if (link[u] != v) upd(v, link[u], dp[u]-1);
            else upd(v, link2[u], dp2[u]-1);
            dfs2(v, u);
        }
    };
    dfs2(0, 0);
    // cout << '\n';
    // for (int i : link) cout << i << ' ';
    // cout << '\n';
    // for (int i : link2) cout << i << ' ';
    // cout << '\n';

    const int K = 61;
    vvi up(n, vi(K));
    FOR(u, 0, n) up[u][0] = link[u];
    FOR(i, 1, K) FOR(u, 0, n) up[u][i] = up[up[u][i-1]][i-1];

    int u = 0;
    FOR(i, 0, K) {
        if (k>>i&1LL) u = up[u][i];
    }
    cout << u+1;
}