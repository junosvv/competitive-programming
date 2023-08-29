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
    vvi G(n);
    FOR(i, 0, n-1) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    vi dp(n), dpanc(n), subsz(n);

    function<void(int,int)> dfs = [&](int u, int p) {
        int sqsum = 0, rem = 0;
        for (int v : G[u]) if (v != p) {
            dfs(v, u);
            subsz[u] += subsz[v];
            dpanc[u] += dpanc[v];
            dp[u] += dp[v];
            dp[u] += dpanc[v];
            sqsum += subsz[v]*subsz[v];
            rem += subsz[v]*dpanc[v];
        }
        dp[u] += (subsz[u]*subsz[u] - sqsum) / 2;
        dp[u] += dpanc[u]*subsz[u] - rem;
        dpanc[u] += subsz[u];
        ++subsz[u];
    };
    
    dfs(0, -1);
    cout << n*(n-1)*(n-2)/6 - dp[0];
}