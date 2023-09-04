#include <bits/stdc++.h>
using namespace std;

#define int long long
#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define ROF(i, a, b) for (int i=(a); i>(b); --i)
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int,int>

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);
    
    auto solve = [&]() {
        int n, K;
        cin >> n >> K;
        vi a(n), b(n);
        FOR(i, 0, n) cin >> a[i];
        FOR(i, 0, n) cin >> b[i];

        vi diag1(n+1, -1e15);
        vi diag2(n+1, -1e15);
        vi diag3(n+1, -1e15);
        vi diag4(n+1, -1e15);

        vvi dp(n+1, vi(K+1));
        ROF(i, n, -1) FOR(k, 0, min(K+1, n-i+1)) {
            if (i < n) {
                dp[i][k] = dp[i+1][k];
                dp[i][k] = max(dp[i][k], diag1[i+k] - b[i] - a[i]);
                dp[i][k] = max(dp[i][k], diag2[i+k] - b[i] + a[i]);
                dp[i][k] = max(dp[i][k], diag3[i+k] + b[i] - a[i]);
                dp[i][k] = max(dp[i][k], diag4[i+k] + b[i] + a[i]);
            }
            // FOR(j, 1, min(k+1, n-i+1)) dp[i][k] = max(dp[i][k], dp[i+j][k-j] + abs(a[i] - b[i+j-1]) + abs(b[i] - a[i+j-1]));
            
            if (i-1 >= 0) {
                diag1[i+k] = max(diag1[i+k], dp[i][k] + a[i-1] + b[i-1]);
                diag2[i+k] = max(diag2[i+k], dp[i][k] + a[i-1] - b[i-1]);
                diag3[i+k] = max(diag3[i+k], dp[i][k] - a[i-1] + b[i-1]);
                diag4[i+k] = max(diag4[i+k], dp[i][k] - a[i-1] - b[i-1]);
            }
        }
        cout << dp[0][K] << '\n';
    };

    int T;
    cin >> T;
    FOR(t, 0, T) solve();
}   