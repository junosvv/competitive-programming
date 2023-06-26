#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define ROF(i, a, b) for (int i=(a); i>(b); --i)
#define vi vector<int>
#define vvi vector<vi>
 
signed main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int T;
    cin >> T;
    FOR(t, 0, T) {
        string s;
        cin >> s;
        int n = s.size();
        vi a(n);
        FOR(i, 0, n) a[i] = s[i] - 'A';
        vi p10 = {1, 10, 100, 1000, 10000};
        
        vvi dp(2, vi(5, -1e9));
        dp[0][0] = 0;
        ROF(i, n-1, -1) {
            vvi dp2(2, vi(5, -1e9));
            FOR(u, 0, 2) FOR(d, 0, 5) if (dp[u][d] != -1e9) {
                if (a[i] >= d) dp2[u][a[i]] = max(dp2[u][a[i]], p10[a[i]] + dp[u][d]);
                else dp2[u][d] = max(dp2[u][d], -p10[a[i]] + dp[u][d]);
            }
            FOR(c, 0, 5) FOR(d, 0, 5) if (dp[0][d] != 1e9) {
                if (c >= d) dp2[1][c] = max(dp2[1][c], p10[c] + dp[0][d]);
                else dp2[1][d] = max(dp2[1][d], -p10[c] + dp[0][d]);
            }
            dp = dp2;
        }
        int res = dp[0][0];
        FOR(u, 0, 2) FOR(d, 0, 5) res = max(res, dp[u][d]);
        cout << res << '\n';
    }
}