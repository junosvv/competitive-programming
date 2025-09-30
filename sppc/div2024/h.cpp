#include <bits/stdc++.h>
using namespace std;

#define int long long
#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define ROF(i, a, b) for (int i=(a); i>(b); --i)
#define vi vector<int>
#define vvi vector<vi>

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);
    
    int n, K;
    cin >> n >> K;
    vi par(n);
    par[0] = -1;
    vvi G(n);
    FOR(i, 1, n) {
        cin >> par[i];
        --par[i];
        G[par[i]].push_back(i);
    }

    vvi dp(n, vi(K+1));
    function<void(int)> dfs = [&](int u) {
        for (int v : G[u]) dfs(v);

        FOR(k, 0, K+1) {
            dp[u][k] = 1;
            for (int v : G[u]) {
                dp[u][k] += dp[v][0];
            }

            if (k != K) {
                int alt = 0;
                for (int v : G[u]) {
                    alt += dp[v][k+1];
                }
                dp[u][k] = min(dp[u][k], alt);
            }
        }
    };
    dfs(0);
    cout << dp[0][K];
}