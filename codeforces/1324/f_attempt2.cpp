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

    int n;
    cin >> n;
    vi a(n);
    FOR(i, 0, n) {
        cin >> a[i];
        if (a[i] == 0) a[i] = -1;
    }

    vvi G(n);
    FOR(i, 0, n-1) {
        int u, v;
        cin >> u >> v;
        --u;
        --v;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    vi dp(n);
    function<void(int,int)> dfs = [&](int u, int p) {
        dp[u] = a[u];
        for (int v : G[u]) if (v != p) {
            dfs(v, u);
            dp[u] += max(0LL, dp[v]);
        }
    };
    dfs(0, 0);

    vi dp2 = dp;
    function<void(int,int)> dfs2 = [&](int u, int p) {
        if (p != u) dp2[u] = max(dp2[u], dp2[p] - (dp[u]==-1));
        for (int v : G[u]) if (v != p) {
            dfs2(v, u);
        }
    };
    dfs2(0, 0);

    for (int i : dp2) cout << i << ' ';
}