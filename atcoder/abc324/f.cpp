#include <bits/stdc++.h>
using namespace std;

#define int long long
#define dub long double
#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define ROF(i, a, b) for (int i=(a); i>(b); --i)
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int,int>

struct edge {
    int to, b, c;
};

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);

    cout << setprecision(11);
    
    int n, m;
    cin >> n >> m;
    vector<vector<edge>> G(n);
    FOR(i, 0, m) {
        int u, v, b, c;
        cin >> u >> v >> b >> c;
        --u; --v;
        G[u].push_back({v, b, c});
        G[v].push_back({u, b, c});
    }

    auto check = [&](dub k) {
        vector<dub> dp(n, -1e11);
        dp[n-1] = 0;
        ROF(u, n-2, -1) {
            for (edge edg : G[u]) {
                dp[u] = max(dp[u], edg.b - k*edg.c + dp[edg.to]);
            }
        }

        return dp[0] >= 0;
    };

    dub k = 0;
    for (dub b = 1e11; b>=1e-11; b /= 2) {
        while (check(k+b)) k += b;
    }
    cout << k;
}