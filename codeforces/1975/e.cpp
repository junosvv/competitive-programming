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
        int n, q;
        cin >> n >> q;
        vi c0(n), c(n);
        FOR(i, 0, n) cin >> c0[i];

        vvi G(n);
        FOR(i, 0, n-1) {
            int u, v;
            cin >> u >> v;
            --u; --v;
            G[u].push_back(v);
            G[v].push_back(u);
        }

        vi par(n, -1);
        par[0] = 0;
        function<void(int)> dfs = [&](int u) {
            for (int v : G[u]) if (par[v] == -1) {
                par[v] = u;
                dfs(v);
            }
        };
        dfs(0);
        
        vi cnt(n);
        vector<vector<set<int>>> b(2, vector<set<int>>(max(3LL, n)));
        FOR(i, 0, n) b[0][0].insert(i);
        int tot_black = 0;
        auto toggle = [&](int u) {
            if (c[u]) {
                --tot_black;
            } else {
                ++tot_black;
            }
            b[c[u]][cnt[u]].erase(u);
            b[!c[u]][cnt[u]].insert(u);
            if (u != 0) {
                b[c[par[u]]][cnt[par[u]]].erase(par[u]);
                int nw = cnt[par[u]] + (c[u] ? -1 : 1);
                b[c[par[u]]][nw].insert(par[u]);
                cnt[par[u]] = nw;
            }
            c[u] ^= 1;
        };

        FOR(u, 0, n) if (c0[u]) toggle(u);

        // cout << "init: ";
        // for (set<int> i : b[1]) cout << i.size() << ' ';
        // cout << '\n';

        FOR(qi, 0, q) {
            int u;
            cin >> u;
            --u;
            toggle(u);

            
            // for (set<int> i : b[1]) cout << i.size() << ' ';
            // cout << '\n';

            if (b[1][0].size() == 1 && b[1][1].size() == tot_black-1) {
                cout << "Yes\n";
                continue;
            }
            if (b[1][0].size() == 2 && b[1][2].size() == 1 && b[1][1].size() == tot_black-3) {
                int lcm = *b[1][2].begin();
                if (lcm == 0 || !c[par[lcm]]) {
                    cout << "Yes\n";
                    continue;
                }
            }
            cout << "No\n";
        }
    };

    int T;
    cin >> T;
    FOR(t, 0, T) solve();
}