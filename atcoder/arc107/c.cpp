#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define ROF(i, a, b) for (int i=(a); i>(b); --i)
#define lg long long
#define vi vector<int>

template <class T> ostream& operator<<(ostream& os, vector<T>& x) {
    os << '[';
    bool first = true;
    for (T& i : x) {
        if (!first) os << ", ";
        first = false;
        os << i;
    }
    return os << ']';
}

lg MOD = 998244353;

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);
    
    int n, k;
    cin >> n >> k;

    vector<vi> grid(n, vi(n));
    FOR(r, 0, n) {
        FOR(c, 0, n) {
            cin >> grid[r][c];
        }
    }

    vector<lg> fact(n+1);
    fact[0] = 1;
    FOR(i, 1, n+1) fact[i] = i * fact[i-1] % MOD;

    auto solve = [&]() {
        vector<vi> nodes(n);
        FOR(r1, 0, n) {
            FOR(r2, 0, n) {
                int mx = -1;
                FOR(c, 0, n) {
                    mx = max(mx, grid[r1][c] + grid[r2][c]);
                }
                if (mx <= k) {
                    nodes[r1].push_back(r2);
                }
            }
        }

        vector<bool> seen(n);
        function<int(int)> dfs = [&](int u) {
            seen[u] = true;
            int res = 1;
            for (int v : nodes[u]) if (!seen[v]) {
                res += dfs(v);
            }
            return res;
        };

        lg res = 1;
        FOR(u, 0, n) {
            if (!seen[u]) {
                res = res * fact[dfs(u)] % MOD;
            }
        }

        return res;
    };

    lg x = solve();
    vector<vi> grid2 = grid;
    FOR(r, 0, n) {
        FOR(c, 0, n) {
            grid[r][c] = grid2[c][r];
        }
    }
    cout << x * solve() % MOD << '\n';
}
