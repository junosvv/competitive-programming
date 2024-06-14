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
        int n1, n2, m;
        cin >> n1 >> n2 >> m;
        int n = n1 + n2;
        vvi G(n);
        FOR(i, 0, m) {
            int u, v;
            cin >> u >> v;
            --u; --v;
            G[u].push_back(v);
            G[v].push_back(u);
        }

        int to_add = 0;
        vi mark(n);
        FOR(_, 0, n1) {
            mark[to_add] = 2;
            for (int v : G[to_add]) if (!mark[v]) mark[v] = 1;

            vi depth(n, -1), reach(n);
            to_add = -1;
            function<void(int)> dfs = [&](int u) {
                int children = 0;
                reach[u] = depth[u];
                for (int v : G[u]) if (mark[v] != 2) {
                    if (depth[v] == -1) {
                        depth[v] = 1 + depth[u];
                        ++children;
                        dfs(v);
                        reach[u] = min(reach[u], reach[v]);
                    } else if (depth[v] < depth[u]) {
                        reach[u] = min(reach[u], depth[v]);
                    }
                }

                if (mark[u] != 1) return;

                if (depth[u] == 0) {
                    if (children <= 1) to_add = u;
                    return;
                }
                for (int v : G[u]) if (mark[v] != 2 && depth[v] > depth[u]) {
                    if (reach[v] >= depth[u]) return;
                }
                to_add = u;
                return;
            };

            FOR(u, 0, n) if (mark[u] != 2) {
                depth[u] = 0;
                dfs(u);
                break;
            }
            assert(to_add != -1);
        }

        FOR(u, 0, n) if (mark[u] == 2) cout << u+1 << ' ';
        cout << '\n';
        FOR(u, 0, n) if (mark[u] != 2) cout << u+1 << ' ';
        cout << '\n';
    };

    int T;
    cin >> T;
    FOR(t, 0, T) solve();
}