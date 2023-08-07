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
    
    int n, m;
    cin >> n >> m;
    vector<string> G(n);
    FOR(i, 0, n) cin >> G[i];

    vi dp(n, 1e9);
    dp[0] = 0;
    FOR(i, 1, n) {
        FOR(j, 1, m+1) if (i-j >= 0 && G[i-j][j-1] == '1') {
            dp[i] = min(dp[i], 1 + dp[i-j]);
        }
    }

    vi dp2(n, 1e9);
    dp2[n-1] = 0;
    ROF(i, n-2, -1) {
        FOR(j, 1, m+1) if (i+j < n && G[i][j-1] == '1') {
            dp2[i] = min(dp2[i], 1 + dp2[i+j]);
        }
    }

    FOR(k, 1, n-1) {
        int res = 1e9;
        FOR(j, 1, m) if (k-j >= 0) {
            FOR(i, j+1, m+1) if (k-j+i < n && G[k-j][i-1] == '1') {
                res = min(res, dp[k-j] + 1 + dp2[k-j+i]);
            }
        }
        if (res == 1e9) res = -1;
        cout << res << ' ';
    }
}