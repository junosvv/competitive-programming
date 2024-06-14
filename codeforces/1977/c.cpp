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

    auto pf = [&](int x) {
        vi facts;
        for (int d=2; d*d<=x; ++d) {
            while (x%d == 0) {
                facts.push_back(d);
                x /= d;
            }
        }
        if (x > 1) facts.push_back(x);
        return facts;
    };

    auto solve = [&]() {
        int n;
        cin >> n;
        vi a(n);
        FOR(i, 0, n) cin >> a[i];

        int mx = *max_element(a.begin(), a.end());
        int lcm = 1;
        FOR(i, 0, n) {
            lcm *= a[i] / __gcd(lcm, a[i]);
            if (lcm > mx) {
                cout << n << '\n';
                return;
            }
        }

        int res = 0;
        auto check = [&](int x) {
            int lcm = 1;
            int cnt = 0;
            FOR(i, 0, n) {
                if (x == a[i]) return;
                if (x % a[i] == 0) {
                    lcm *= a[i] / __gcd(lcm, a[i]);
                    ++cnt;
                }
            }
            if (lcm == x) res = max(res, cnt);
        };

        for (int d = 1; d*d <= mx; ++d) {
            if (mx % d == 0) {
                check(d);
                check(mx/d);
            }
        }
        cout << res << '\n';
    };

    int T;
    cin >> T;
    FOR(t, 0, T) solve();
}