#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define ROF(i, a, b) for (int i=(a); i>(b); --i)
#define vi vector<int>

const int MOD = 998244353;

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);
    
    int n;
    cin >> n;
    vi a(n);
    FOR(i, 0, n) cin >> a[i];

    vi dp(n, 1);
    FOR(i, 0, n) {
        int run = a[i];
        FOR(j, i+1, n) {
            if (a[j] < run) dp[j] = 0;
            run = max(run, a[j]);
        }
        run = a[i];
        ROF(j, i-1, -1) {
            if (a[j] < run) dp[j] = 0;
            run = max(run, a[j]);
        }
        FOR(j, 1, n) dp[j] = (dp[j] + dp[j-1]) % MOD;
    }

    cout << dp.back();
}