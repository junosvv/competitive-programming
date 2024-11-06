#include <bits/stdc++.h>
using namespace std;

#define lg long long
#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define ROF(i, a, b) for (int i=(a); i>(b); --i)
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int,int>

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);

    auto solve = [&]() {
        int n, root;
        cin >> n >> root;
        --root;
        vi a(n);
        FOR(i, 0, n) cin >> a[i];
        lg tot = accumulate(a.begin(), a.end(), 0LL);
        vvi G(n);
        FOR(i, 0, n-1) {
            int u, v;
            cin >> u >> v;
            --u; --v;
            G[u].push_back(v);
            G[v].push_back(u);
        }

        function<lg(int,int,lg)> dfs = [&](int u, int p, lg k) {
            lg res = a[u] - k/n - (u < k%n);
            for (int v : G[u]) if (v != p) {
                res += dfs(v, u, k);
            }

            if (res >= 0) return res;
            if (res&1) return 1LL;
            return 0LL;
        };

        auto check = [&](int k) {
            FOR(i, 0, 2*n) {
                if ((2LL*n*k+i+tot)&1) continue;
                if (dfs(root, root, 2LL*n*k + i) == 0) {
                    return 2LL*n*k + i;
                }
            }
            return -1LL;
        };

        const int upp = 2e9;
        int k = upp;
        for (int b=upp; b>=1; b/=2) {
            while (k-b >= 0 && check(k-b) != -1) k -= b;
        }
        cout << check(k) << '\n';
    };
    int T;
    cin >> T;
    FOR(t, 0, T) solve();
}