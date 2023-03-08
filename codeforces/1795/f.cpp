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
        int n;
        cin >> n;
        vector<vi> nodes(n);
        FOR(i, 0, n-1) {
            int u, v;
            cin >> u >> v;
            --u; --v;
            nodes[u].push_back(v);
            nodes[v].push_back(u);
        }
        int k;
        cin >> k;
        vi a(k);
        FOR(i, 0, k) {
            cin >> a[i];
            --a[i];
        }

        vi depth(n, -1), par(n);
        function<void(int)> dfs = [&](int u) {
            for (int v : nodes[u]) if (depth[v] == -1) {
                par[v] = u;
                depth[v] = 1 + depth[u];
                dfs(v);
            }
        };
        depth[0] = 0;
        dfs(0);

        auto check = [&](int x) {
            vi dist(n, -1);
            function<bool(int,int)> dfs2 = [&](int u, int des) {
                if (dist[u] == des) return true;
                for (int v : nodes[u]) if (v != par[u] && dist[v] == -1) {
                    dist[v] = 1 + dist[u];
                    if (dfs2(v, des)) return true;
                }
                return false;
            };

            vector<vi> atdepth(n);
            FOR(i, 0, k) {
                dist[a[i]] = 0;
                atdepth[depth[a[i]]].push_back(i);
            }

            vi loc = a;
            ROF(d, n-1, -1) {
                while (!atdepth[d].empty()) {
                    int i = atdepth[d].back();
                    atdepth[d].pop_back();

                    if (!dfs2(loc[i], (x+k-1-i)/k)) {
                        if (dist[par[loc[i]]] != -1) return false;
                        dist[par[loc[i]]] = 1 + dist[loc[i]];
                        loc[i] = par[loc[i]];
                        assert(d != 0);
                        atdepth[d-1].push_back(i);
                    }
                }
            }
            return true;
        };

        int res = 0;
        for (int b=n; b>=1; b/=2) {
            while (res+b <= n && check(res+b)) res += b;
        }
        cout << res << '\n';
    }
}