#include <bits/stdc++.h>
using namespace std;

#define int long long
#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define ROF(i, a, b) for (int i=(a); i>(b); --i)
#define vi vector<int>
#define vvi vector<vi>

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);
    
    int n;
    cin >> n;

    if (n == 1) {
        cout << 1;
        exit(0);
    }

    vvi g(n);
    FOR(i, 0, n-1) {
        int u, v;
        cin >> u >> v;
        --u; --v;

        g[u].push_back(v);
        g[v].push_back(u);
    }

    int root = 0;
    FOR(u, 0, n) if (g[u].size() == 1) {
        root = u;
    }
    vi dp(n, -1), depth(n);
    function<void(int)> dfs = [&](int u) {
        dp[u] = 0;
        bool any = false;
        for (int v : g[u]) if (dp[v] == -1) {
            depth[v] = 1 + depth[u];
            dfs(v);
            if (dp[v] == 0) ++dp[u];
            any = true;
        }
        if (!any) dp[u] = 1;
    };
    dfs(root);
    
    vi dp2(n, -1);
    int res = 0;
    function<void(int)> dfs2 = [&](int u) {
        bool any = false;
        for (int v : g[u]) if (dp2[v] == -1) {
            any = true;
            if (dp[v] == 1 && dp[u] == 0 || dp[v] == 0 && dp[u] == 1) dp2[v] = dp2[u];
            else dp2[v] = u;
            dfs2(v);
        }
        if (any && dp[u] || u != root && (depth[u]&1)==(depth[dp2[u]]&1)) {
            ++res;
        }
    };
    dp2[root] = root;
    dfs2(root);

    cout << res;
}