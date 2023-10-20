#include <bits/stdc++.h>
using namespace std;

#define int long long
#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define ROF(i, a, b) for (int i=(a); i>(b); --i)
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int,int>

void maxi(int& a, int b) {
    a = max(a, b);
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);
    
    int n, k;
    cin >> n >> k;
    vector<vector<pii>> G(n);
    FOR(i, 0, n-1) {
        int u, v, w;
        cin >> u >> v >> w;
        G[u].emplace_back(v, w);
        G[v].emplace_back(u, w);
    }

    vi dp(n), q(n);
    function<void(int,int)> dfs = [&](int u, int p) {
        for (pii pr : G[u]) {
            int v = pr.first, w = pr.second;
            if (v == p) continue;
            dfs(v, u);
            int space = w + q[v];
            int nlogs = space / k;
            maxi(q[u], space - nlogs * k);
            dp[u] += nlogs + dp[v];
        };
    };
    dfs(0, 0);

    cout << dp[0];
}