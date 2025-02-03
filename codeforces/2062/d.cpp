#include <bits/stdc++.h>
using namespace std;

#define int long long
#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define ROF(i, a, b) for (int i=(a); i>(b); --i)
#define vi vector<int>
#define vvi vector<vi>
#define vs vector<string>
#define pii pair<int,int>
#define vpii vector<pii>
#define vvpii vector<vpii>
#define mii map<int,int>

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);
    
    auto solve = [&]() {
        int n;
        cin >> n;
        vi l(n), r(n);
        FOR(i, 0, n) cin >> l[i] >> r[i];
        vvi G(n);
        FOR(i, 0, n-1) {
            int u, v;
            cin >> u >> v;
            --u; --v;
            G[u].push_back(v);
            G[v].push_back(u);
        }

        vi dp(n), op(n);
        function<void(int,int)> dfs = [&](int u, int p) {
            dp[u] = 0;
            int smdps = 0, children = 0;
            for (int v : G[u]) if (v != p) {
                dfs(v, u);
                op[u] += op[v];
            }
            for (int v : G[u]) if (v != p) {
                dp[v] += op[u] - op[v];
                dp[u] = max(dp[u], dp[v]);
                smdps += dp[v];
                ++children;
            }
            int dbal = dp[u] * children - smdps;
            int k = 
            l[u] += op[u];
            r[u] += op[u];
            op[u] += max(0LL, dp[u] - r[u]);
            dp[u] = max(dp[u], l[u]);
            // cout << "Node " << u << " has " << dp[u] << " op " << op[u] << '\n';
        };
        dfs(0, 0);

        // FOR(u, 0, n) {
        //     cout << "Node " << u << " has " << dp[u] << " op " << op[u] << '\n';
        // }

        cout << dp[0] << '\n';
    };

    int T;
    cin >> T;
    FOR(t, 0, T) solve();
}