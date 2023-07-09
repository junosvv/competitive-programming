#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define vi vector<int>
#define vvi vector<vi>
 
const int MOD = 998244353;
 
signed main() {
    ios::sync_with_stdio(0), cin.tie(0);
 
    int n;
    cin >> n;
    vi a(n);
    FOR(i, 0, n) cin >> a[i];
    int sm = accumulate(a.begin(), a.end(), 0LL);
    if (sm&1) {
        cout << 0;
        exit(0);
    }
 
    vvi dp(sm+1, vi(n+1));
    dp[0][0] = 1;
    FOR(i, 0, n) {
        vvi dp2 = dp;
        FOR(s, 0, sm+1-a[i]) FOR(k, 0, i+1) {
            dp2[s+a[i]][k+1] += dp[s][k];
            dp2[s+a[i]][k+1] %= MOD;
        }
        dp = dp2;
    }
 
    vi fact(n, 1);
    FOR(i, 2, n) fact[i] = i * fact[i-1] % MOD;
    
    int res = 0;
    FOR(k, 1, n) {
        res += dp[sm/2][k] * fact[k] % MOD * fact[n-k] % MOD;
        res %= MOD;
    }
    cout << res;
}