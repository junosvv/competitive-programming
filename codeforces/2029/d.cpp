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

        vvi res;
        FOR(u, 0, n) {
            while (G[u].size() >= 2) {
                int v = *G[u].begin();
                int w = *G[u].rbegin();
                res.push_back({u+1, v+1, w+1});
                G[u].erase(v);
                G[u].erase(w);
                G[v].erase(u);
                G[w].erase(u);
                if (G[v].find(w) != G[v].end()) {
                    G[v].erase(w);
                    G[w].erase(v);
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
            if (a > b) swap(a, b);
            FOR(u, 0, n) {
                if (G[u].empty() || u != a && *(G[u].begin()) > u) {
                    res.push_back({a+1, b+1, u+1});
                    b = u;
                }
            }
        }

        cout << res.size() << '\n';
        for (vi& v : res) {
            cout << v[0] << ' ' << v[1] << ' ' << v[2] << '\n';
        }
    };

    int T;
    cin >> T;
    FOR(t, 0, T) solve();
}