#include <bits/stdc++.h>
using namespace std;

#define int long long
#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define ROF(i, a, b) for (int i=(a); i>(b); --i)
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int,int>
#define t3i tuple<int,int,int>

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);

    auto solve = [&]() {
        int n, m;
        cin >> n >> m;
        vvi G(n);
        FOR(i, 0, m) {
            int u, v;
            cin >> u >> v;
            --u; --v;
            G[u].push_back(v);
            G[v].push_back(u);
        }
        
        vi col(n, -1);
        function<void(int)> dfs = [&](int u) {
            for (int v : G[u]) if (col[v] == -1) {
                col[v] = !col[u];
                dfs(v);
            }
        };
        col[0] = 0;
        dfs(0);

        FOR(u, 0, n) {
            for (int v : G[u]) {
                if (col[u] == col[v]) {
                    cout << "Alice" << endl;
                    FOR(i, 0, n) {
                        cout << "1 2" << endl;
                        int _;
                        cin >> _ >> _;
                    }
                    return;
                }
            }
        }

        // bipartite
        vvi groups(2);
        FOR(u, 0, n) groups[col[u]].push_back(u);

        cout << "Bob" << endl;
        FOR(i, 0, n) {
            int c1, c2;
            cin >> c1 >> c2;
            if (c1 != 1 && c2 != 1) {
                if (c2 == 2) swap(c1, c2);
            } else {
                if (c2 == 1) swap(c1, c2);
            }
            assert(c1 != 3);
            if (groups[c1-1].empty()) {
                int topaint = groups[!(c1-1)].back();
                groups[!(c1-1)].pop_back();
                cout << topaint+1 << ' ' << c2 << endl;
            } else {
                int topaint = groups[c1-1].back();
                groups[c1-1].pop_back();
                cout << topaint+1 << ' ' << c1 << endl;
            }
        }
    };

    int T;
    cin >> T;
    FOR(t, 0, T) solve();
}