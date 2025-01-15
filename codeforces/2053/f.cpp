#include <bits/stdc++.h>
using namespace std;

#define int long long
#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define ROF(i, a, b) for (int i=(a); i>(b); --i)
#define vi vector<int>
#define vvi vector<vi>
#define vs vector<string>
#define pii pair<int,int>
#define mii map<int,int>

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
        int n, m, k;
        cin >> n >> m >> k;

        vvi grid(n, vi(m));
        vector<mii> cnt(n);
        FOR(r, 0, n) FOR(c, 0, m) {
            cin >> grid[r][c];
            ++cnt[r][grid[r][c]];
        }

        int res = 0;
        FOR(r, 1, n) FOR(c, 0, m) if (grid[r][c] != -1) {
            int u = grid[r][c];
            res += cnt[r-1][u] * cnt[r][u];
        }

        vector<mii> dp(n);
        vi keys;
        FOR(r, 0, n) FOR(c, 0, m) if (grid[r][c] != -1) {
            int u = grid[r][c];
            dp[0][u] = 0;
            keys.push_back(u);
        }
        
        cout << "default beauty: " << res << '\n';

        vi gv(n);
        int x = 0;
        FOR(r, 1, n) {
            for (int v : keys) {
                gv[r] = max(gv[r], dp[r-1][v] + cnt[r][v]*cnt[r-1][-1]);
            }
            gv[r] = max(gv[r], x);

            keys.clear();
            FOR(rr, r-1, r+1) FOR(c, 0, m) if (rr < n && grid[rr][c] != -1) {
                keys.push_back(grid[rr][c]);
            }
            for (int u : keys) {
                // if (r == 1 && u == 1) cout << "debug " << gv << " + " << cnt[r-1][u]*cnt[r][-1] << " vs. " << dp[r-1][u] + cnt[r][u]*cnt[r-1][-1] + cnt[r-1][u]*cnt[r][-1] + cnt[r-1][-1]*cnt[r][-1] << '\n';
                dp[r][u] = max(dp[r-1][u] + cnt[r][u]*cnt[r-1][-1] + cnt[r-1][u]*cnt[r][-1] + cnt[r-1][-1]*cnt[r][-1], gv[r] + cnt[r-1][u]*cnt[r][-1]);
            }
            x = 
            for (int k : keys) cout << r << ' ' << k << " -> " << dp[r][k] << '\n';
            cout << r << " largest (x): " << x << '\n';
            cout << '\n';
        }

        int mx = 0;
        for (int k : keys) mx = max(mx, dp[n-1][k]);
        cout << res+mx << '\n';
    };

    int T;
    cin >> T;
    FOR(t, 0, T) solve();
}