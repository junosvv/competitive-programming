#include <bits/stdc++.h>
using namespace std;

#define int long long
#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define ROF(i, a, b) for (int i=(a); i>(b); --i)
#define vi vector<int>
#define vvi vector<vi>

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);

    auto solve = [&]() {
        int n, x, y;
        cin >> n >> x >> y;
        int lcm = x*y / __gcd(x, y);
        int u = n / x, v = n / y, w = n / lcm;
        u -= w;
        v -= w;

        auto f = [&](int l, int r) {
            return (r-l+1)*(l+r)/2;
        };

        cout << f(n-u+1, n) - f(1, v) << '\n';
    };

    int T;
    cin >> T;
    FOR(t, 0, T) solve();
}