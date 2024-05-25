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

    auto solve = [&]() {
        int n, a, b;
        cin >> n >> a >> b;
        --a; --b;

        vvi G(n);
        FOR(i, 0, n-1) {
            int u, v;
            cin >> u >> v;
            --u; --v;
            G[u].push_back(v);
            G[v].push_back(u);
        }

        vi par(n, -1);
        vi dist(n, -1);
        dist[b] = 0;
        par[b] = b;
        function<void(int)> dfs = [&](int u) {
            for (int v : G[u]) if (dist[v] == -1) {
                par[v] = u;
                dist[v] = 1 + dist[u];
                dfs(v);
            }
        };
        dfs(b);

        int w = a;
        FOR(i, 0, dist[a]/2) w = par[w];

        vi dep(n, -1);
        dep[w] = 0;
        function<void(int)> dfs2 = [&](int u) {
            for (int v : G[u]) if (dep[v] == -1) {
                dep[v] = 1 + dep[u];
                dfs2(v);
            }
        };
        dfs2(w);

        cout << (dist[a]+1) / 2 + 2*(n-1) - *max_element(dep.begin(), dep.end()) << '\n';
    };

    int T;
    cin >> T;
    FOR(t, 0, T) solve();
}