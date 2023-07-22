#include <bits/stdc++.h>
using namespace std;

#define int long long
#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define ROF(i, a, b) for (int i=(a); i>(b); --i)
#define vi vector<int>
#define vvi vector<vi>
#define inv(x) powa(x, MOD-2)
const int MOD = 998244353;

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

    int n;
    cin >> n;
    vi a(n);
    FOR(i, 0, n) cin >> a[i];
    
    vi dp(512);
    int prod = 1;
    FOR(i, 0, n) {
        vi dp2(512);
        FOR(mask, 0, 512) {
            FOR(x, 1, min(10LL, a[i]+1)) {
                int mask2 = mask;
                mask2 |= mask >> x;
                mask2 |= 1LL << (9-x);
                if (mask>>(x-1)&1LL) {
                    dp2[mask] += prod;
                } else {
                    dp2[mask] += dp[mask2];
                }
            }
            if (a[i] >= 10) {
                dp2[mask] += prod;
                dp2[mask] += (a[i]-10) * dp[mask] % MOD;
            }
            dp2[mask] %= MOD;
        }
        dp = dp2;
        prod = prod * a[i] % MOD;
    }

    cout << dp[0] * inv(prod) % MOD;
}