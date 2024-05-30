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
        vi a(n);
        FOR(i, 0, n) cin >> a[i];

        vvi left(32, vi(n+1)), right(32, vi(n+1));
        FOR(d, 0, 32) {
            vi b(n+1);
            FOR(i, 0, n) b[i+1] = a[i]>>d & 1LL;
            FOR(i, 1, n+1) b[i] ^= b[i-1];
            FOR(i, 1, n+1) left[d][i] = left[d][i-1] + b[i];
            right[d][n] = b[n];
            ROF(i, n-1, -1) right[d][i] = right[d][i+1] + b[i];
        }

        int res = 0;
        FOR(y, 0, n) {
            int d = 0;
            FOR(dd, 1, 32) if (a[y]>>dd&1LL) d = dd;

            res += left[d][y] * right[d][y+1] + (y+1 - left[d][y]) * (n-y - right[d][y+1]);
        }
        cout << res << '\n';
    };

    int T;
    cin >> T;
    FOR(t, 0, T) solve();
}