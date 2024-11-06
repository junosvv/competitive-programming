#include <bits/stdc++.h>
using namespace std;

#define int long long
#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define ROF(i, a, b) for (int i=(a); i>(b); --i)
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int,int>

const int MOD = 1e9+7;

int powa(int base, int exp) {
    int res = 1;
    while (exp) {
        if (exp&1) res = res * base % MOD;
        base = base * base % MOD;
        exp /= 2;
    }
    return res;
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);

    auto solve = [&]() {
        int x, y, z, k;
        cin >> x >> y >> z >> k;

        auto get_m = [&](int d) {
            return max(0LL, d-1) / k;
        };

        const int BIG = 2e4;
        int res = 1e18;
        FOR(d, 1, BIG) {
            int m = get_m(d);
            res = min(res, d*x + (m+(z-k*m*(m+1)/2+d-1)/d)*y);
        }

        auto check = [&](int d, int l) {
            int m = get_m(d);
            return k*m*(m+1)/2 + d*l >= z;
        };

        FOR(l, 1, BIG) {
            int d = z;
            for (int b=z; b>=1; b/=2) {
                while (d-b >= 1 && check(d-b, l)) d -= b;
            }
            int m = get_m(d);
            res = min(res, d*x + (m+(z-k*m*(m+1)/2+d-1)/d)*y);
        }
        cout << res << '\n';
    };
    int T;
    cin >> T;
    FOR(t, 0, T) solve();
}