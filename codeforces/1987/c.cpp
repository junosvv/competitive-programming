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

        int prev = 0;
        int res = 0;
        ROF(i, n-1, -1) {
            // cout << "proc " << a[i] << ' ' << prev << '\n';
            if (a[i] > prev) {
                a[i] = max(a[i]-res, prev);
            }
            if (a[i] <= prev) {
                // cout << "adding " << prev-a[i]+1 << '\n';
                res += prev - a[i] + 1;
            }
            prev = a[i];
        }
        res += a[0];
        cout << res << '\n';
    };

    int T;
    cin >> T;
    FOR(t, 0, T) solve();
}