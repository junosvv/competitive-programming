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
        int n, q;
        cin >> n >> q;
        vvi a(2, vi(n));
        FOR(i, 0, n) cin >> a[0][i];
        FOR(i, 0, n) cin >> a[1][i];
        vvi b = a;
        sort(b[0].begin(), b[0].end());
        sort(b[1].begin(), b[1].end());
        int res = 1;
        FOR(i, 0, n) res = res * min(b[0][i], b[1][i]) % MOD;

        cout << res << ' ';
        FOR(qi, 0, q) {
            int t, x;
            cin >> t >> x;
            --t; --x;
            int y = upper_bound(b[t].begin(), b[t].end(), a[t][x]) - b[t].begin() - 1;
            assert(0 <= y && y < n);
            ++a[t][x];
            res = res * inv(min(b[0][y], b[1][y])) % MOD;
            ++b[t][y];
            res = res * min(b[0][y], b[1][y]) % MOD;
            cout << res << ' ';
        }
        cout << '\n';
    };

    int T;
    cin >> T;
    FOR(t, 0, T) solve();
}