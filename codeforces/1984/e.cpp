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

        if (n == 2) {
            cout << "2\n";
            return;
        }
        
        int root = 0;
        FOR(u, 0, n) if (G[u].size() >= 2) {
            root = u;
            break;
        }

        vi dp(n), dq(n), dp_col(n, 1), dq_col(n);
        function<void(int,int)> dfs = [&](int u, int p) {
            int wrong = 0, children = 0;
            for (int v : G[u]) if (v != p) {
                dfs(v, u);
                dp[u] += dp[v];
                if (dp_col[v]) {
                    dp_col[u] = 0;
                    ++wrong;
                }
                ++children;
            }
            if (!children) {
                dp[u] = 1;
                dq[u] = 1;
                return;
            }

            dq[u] = dp[u];
            dq_col[u] = dp_col[u];
            for (int v : G[u]) if (v != p) {
                int cur = dp[u] + dq[v]-dp[v], cur_col = 0;
                if (wrong == 0) {
                    if (!dq_col[v]) cur_col = 1;
                } else if (wrong == 1) {
                    if (!dq_col[v] && dp_col[v]) cur_col = 1;
                }
                cur += cur_col;

                if (cur > dq[u] || cur == dq[u] && cur_col < dq_col[u]) {
                    dq[u] = cur;
                    dq_col[u] = cur_col;
                }
            }
            dp[u] += dp_col[u];
            // cout << "node " << u+1 << " was " << dq[u] << " with colour " << dq_col[u] << '\n';
        };
        dfs(root, root);

        assert(dq[root] >= dp[root]);
        cout << dq[root] << '\n';
    };

    int T;
    cin >> T;
    FOR(t, 0, T) solve();
}