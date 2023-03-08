#include <bits/stdc++.h>
using namespace std;
 
#define li long long
#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define ROF(i, a, b) for (int i=(a); i>(b); --i)
#define vi vector<int>
#define vvi vector<vi>

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);
    
    int n;
    cin >> n;
    vvi nodes(n);
    FOR(i, 0, n-1) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        nodes[u].push_back(v);
        nodes[v].push_back(u);
    }

    vector<double> dp(n, -1);
    function<void(int)> dfs = [&](int u) {
        dp[u] = 0;
        int children = 0;
        for (int v : nodes[u]) if (dp[v] == -1) {
            ++children;
            dfs(v);
            dp[u] += dp[v];
        }
        if (children) dp[u] = dp[u]/children + 1;
    };

    dfs(0);
    cout << setprecision(10) << dp[0];
}