#include <bits/stdc++.h>
using namespace std;

#define int long long
#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define ROF(i, a, b) for (int i=(a); i>(b); --i)
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int,int>

signed main() {
    int n;
    vi q(3);
    cin >> n >> q[0] >> q[1] >> q[2];
    vi A(n);
    FOR(i, 0, n) cin >> A[i];

    auto lcm = [&](int x, int y) {
        return x*y / __gcd(x, y);
    };
    
    vi lcms(8, 1);
    FOR(mask, 0, 8) {
        FOR(d, 0, 3) if (mask>>d&1LL) {
            lcms[mask] = lcm(lcms[mask], q[d]);
        }
    }

    auto f = [&](int x, int y) {
        return (-x%y + y) % y;
    };

    const int INF = 9e18;
    vi dp(8, INF);
    dp[0] = 0;
    FOR(i, 0, n) {
        vi dp2 = dp;
        FOR(mask, 0, 8) if (dp[mask] != INF) {
            FOR(mask2, 0, 8) {
                dp2[mask|mask2] = min(dp2[mask|mask2], dp[mask] + f(A[i], lcms[mask2]));
            }
        }
        dp = dp2;
    }
    cout << dp[7];
}