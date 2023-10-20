#include <bits/stdc++.h>
using namespace std;

#define int long long
#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define ROF(i, a, b) for (int i=(a); i>(b); --i)
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int,int>

const int MOD = 998244353;
#define inv(x) powa(x, MOD-2)

int powa(int base, int exp) {
    int res = 1;
    while (exp) {
        if (exp&1LL) res = res * base % MOD;
        base = base * base % MOD;
        exp /= 2;
    }
    return res;
}

signed main() {
    int n, x;
    cin >> n >> x;
    vi a(n);
    FOR(i, 0, n) cin >> a[i];

    vi dp(x+1);
    ROF(t, x, -1) {
        FOR(i, 0, n) dp[t] = (dp[t] + (t+a[i] <= x ? dp[t+a[i]] : i==0)) % MOD;
        dp[t] = dp[t] * inv(n) % MOD;
    }
    cout << dp[0];
}