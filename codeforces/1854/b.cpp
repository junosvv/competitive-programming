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

        const int BIG = 2e5;
        bitset<BIG> dp(1);
        FOR(i, 0, n) {
            dp |= (dp >> i) << i+a[i];
        }
        int sm = 0;
        int res = 0;
        FOR(i, 0, 2*n) {
            if (i < n) sm += a[i];
            if (dp[i]) res = max(res, sm - i);
        }
        cout << res << '\n';
    };

    solve();
    // int T;
    // cin >> T;
    // FOR(t, 0, T) solve();
}