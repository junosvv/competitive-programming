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
        int n, m;
        cin >> n >> m;
        vector<set<int>> G(n);
        FOR(i, 0, m) {
            int u, v;
            cin >> u >> v;
            --u; --v;
            G[u].insert(v);
            G[v].insert(u);
        }

        vvi res(3);
        FOR(u, 0, n) {
            while (G[u].size() >= 2) {
                int v = *G[u].begin();
                int w = *G[u].rbegin();
                res[0].push_back(u+1);
                res[1].push_back(v+1);
                res[2].push_back(w+1);
                G[u].erase(G[u].begin());
                G[u].erase(G[u].find(w));
                G[v].erase(G[v].find(u));
                G[w].erase(G[w].find(u));
                if (G[v].find(w) != G[v].end()) {
                    G[v].erase(G[v].find(w));
                    G[w].erase(G[w].find(v));
                } else {
                    G[v].insert(w);
                    G[w].insert(v);
                }
            }
        }
        
        int a = -1, b = -1;
        FOR(u, 0, n) {
            if (!G[u].empty()) {
                a = u;
                b = *G[u].begin();
                break;
            }
        }

        if (a != -1) {
            vi seen(n, -1);
            function<void(int)> dfs = [&](int u) {
                for (int v : G[u]) if (seen[v] == -1) {
                    seen[v] = seen[u];
                    dfs(v);
                }
            };
            seen[a] = a;
            dfs(a);
            FOR(u, 0, n) {
                if (seen[u] == -1) {
                    seen[u] = u;
                    dfs(u);
                    res[0].push_back(a+1);
                    res[1].push_back(b+1);
                    res[2].push_back(u+1);
                    b = u;
                }
            }
        }

        int r = res[0].size();
        cout << r << '\n';
        FOR(i, 0, r) {
            cout << res[0][i] << ' ' << res[1][i] << ' ' << res[2][i] << '\n';
        }
    };

    int T;
    cin >> T;
    FOR(t, 0, T) solve();
}