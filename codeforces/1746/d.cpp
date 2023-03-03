#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define ROF(i, a, b) for (int i=(a); i>(b); --i)
#define vi vector<int>
#define pii pair<int,int>
 
signed main() {
    ios::sync_with_stdio(0), cin.tie(0);
    
    int T;
    cin >> T;
    while (T--) {
        int n, k;
        cin >> n >> k;
        vi a(n), p(n);
        vector<vi> nodes(n);
        FOR(i, 1, n) {
            cin >> p[i];
            --p[i];
            nodes[p[i]].push_back(i);
        }
        FOR(i, 0, n) cin >> a[i];

        vector<vector<pii>> dp(n);
        function<int(int, int)> dfs = [&](int u, int paths) {
            for (pii pr : dp[u]) {
                if (pr.first == paths) return pr.second;
            }
            dp[u].emplace_back(paths, paths*a[u]);
            int neighbours = nodes[u].size();
            if (neighbours == 0) return dp[u].back().second;
            vi alt;
            for (int v : nodes[u]) {
                int cur = dfs(v, paths/neighbours);
                dp[u].back().second += cur;
                if (paths % neighbours != 0) alt.push_back(dfs(v, paths/neighbours + 1) - cur);
            }
            sort(alt.rbegin(), alt.rend());
            FOR(i, 0, paths % neighbours) dp[u].back().second += alt[i];
            return dp[u].back().second;
        };
 
        cout << dfs(0, k) << '\n';
    }
}