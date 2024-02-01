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
        int n, k;
        cin >> n >> k;
        vi a(n);
        FOR(i, 0, n) cin >> a[i];
        if (*min_element(a.begin(), a.end()) == *max_element(a.begin(), a.end())) {
            cout << 0 << '\n';
            return;
        }
        bool pos = 0, neg = 0;
        FOR(i, 0, n) {
            a[i] -= k;
            if (a[i] == 0) {
                cout << -1 << '\n';
                return;
            }
            if (a[i] > 0) pos = 1;
            if (a[i] < 0) neg = 1;
        }
        if (pos && neg) {
            cout << -1 << '\n';
            return;
        }
        if (neg) FOR(i, 0, n) a[i] *= -1;
        
        int gcd = 0;
        FOR(i, 0, n) gcd = __gcd(gcd, a[i]);

        int res = 0;
        FOR(i, 0, n) res += a[i]/gcd - 1;
        cout << res << '\n';
    };

    int T;
    cin >> T;
    FOR(t, 0, T) solve();
}