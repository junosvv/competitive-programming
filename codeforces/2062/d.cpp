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

        vi par(n, -1), val = l;
        function<void(int)> dfs = [&](int u) {
            for (int v : G[u]) if (par[v] == -1) {
                par[v] = u;
                dfs(v);
                val[u] = max(val[u], val[v]);
            }
            val[u] = min(val[u], r[u]);
        };
        par[0] = 0;
        dfs(0);

        int res = val[0];
        FOR(u, 1, n) res += max(0LL, val[u] - val[par[u]]);
        cout << res << '\n';
    };

    int T;
    cin >> T;
    FOR(t, 0, T) solve();
}