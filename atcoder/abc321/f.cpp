#include <bits/stdc++.h>
using namespace std;

#define int long long
#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define ROF(i, a, b) for (int i=(a); i>(b); --i)
#define vi vector<int>

const int MOD = 998244353;

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);
    
    int q, k;
    cin >> q >> k;
    vi dp(k+1);
    dp[0] = 1;
    FOR(qi, 0, q) {
        char c;
        int x;
        cin >> c >> x;

        if (c == '+') {
            ROF(i, k, x-1) dp[i] = (dp[i] + dp[i-x]) % MOD;
        } else {
            FOR(i, x, k+1) dp[i] = (dp[i] + MOD - dp[i-x]) % MOD;
        }
        cout << dp[k] << '\n';
    }
}