#include <bits/stdc++.h>
using namespace std;

#define int long long
#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define ROF(i, a, b) for (int i=(a); i>(b); --i)
#define vi vector<int>
#define vvi vector<vi>

const int MOD = 998244353;

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);
    
    int n;
    cin >> n;
    vvi a(2, vi(n));
    FOR(i, 0, n) cin >> a[0][i] >> a[1][i];

    vi dp(2, 1);
    FOR(i, 1, n) {
        vi dp2(2);
        FOR(x, 0, 2) {
            FOR(y, 0, 2) if (i == 0 || a[y][i-1] != a[x][i]) {
                dp2[x] = (dp2[x] + dp[y]) % MOD;
            }
        }
        dp = dp2;
    }
    cout << (dp[0] + dp[1]) % MOD;
}