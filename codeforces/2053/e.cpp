#include <bits/stdc++.h>
using namespace std;

#define int long long
#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define ROF(i, a, b) for (int i=(a); i>(b); --i)
#define vi vector<int>
#define vvi vector<vi>
#define vs vector<string>
#define pii pair<int,int>

const int MOD = 998244353;
int powa(int base, int exp) {
    int res = 1;
    while (exp) {
        if (exp&1LL) res = res * base % MOD;
        base = base * base % MOD;
        exp /= 2;
    }
    return res;
}
#define inv(x) powa(x, MOD-2)

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
            cout << "0\n";
            return;
        }
        
        int s = -1;
        FOR(u, 0, n) if (G[u].size() >= 2) {
            s = u;
            break;
        }
        assert(s != -1);

        vi typ(n), subsz(n), par(n, -1);
        function<void(int,int)> dfs = [&](int u, int p) {
            if (G[u].size() == 1) typ[u] = 1; // leaf
            for (int v : G[u]) if (v != p) {
                dfs(v, u);
                par[v] = u;
                if (typ[v] == 1) typ[u] = 2; // triangle (adj. to leaf)
                subsz[u] += subsz[v];
            }

            if (typ[u] == 0) ++subsz[u];
        };
        dfs(s, s);

        // cout << "root: " << s << '\n';
        // for (int i : typ) cout << i << ' ';
        // cout << '\n';
        // for (int i : subsz) cout << i << ' ';
        // cout << '\n';

        int leaves = 0;
        FOR(u, 0, n) if (typ[u] == 1) ++leaves;
        int res = leaves * (n-leaves);

        FOR(u, 0, n) {
            if (typ[u] == 2) {
                // vi subs;
                int sm = 0, k = 0;
                for (int v : G[u]) if (v != par[u] && typ[v] != 1) {
                    // subs.push_back(subsz[v]);
                    sm += subsz[v];
                    ++k;
                }
                if (u != s) {
                    // subs.push_back(subsz[s]-subsz[u]);
                    sm += subsz[s]-subsz[u];
                    ++k;
                }
                // cout << "node " << u << " has ";
                // for (int i : subs) cout << i << ' ';
                // cout << '\n';
                res += (k-1) * sm;
            }
        }
        cout << res << '\n';
    };

    int T;
    cin >> T;
    FOR(t, 0, T) solve();
}