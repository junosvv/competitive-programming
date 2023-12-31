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
        int n, k, d;
        cin >> n >> k >> d;
        vi a(n), b(k);
        FOR(i, 0, n) cin >> a[i];
        FOR(i, 0, k) cin >> b[i];

        int res = 0;
        FOR(inc, 0, min(d, 2*n+1)) {
            int cur = 0;
            FOR(j, 0, n) if (a[j] == j+1) ++cur;
            res = max(res, (d-inc-1) / 2 + cur);

            FOR(j, 0, b[inc%k]) ++a[j];
        }
        cout << res << '\n';
    };

    int T;
    cin >> T;
    FOR(t, 0, T) solve();
}