#include <bits/stdc++.h>
using namespace std;

#define int long long
#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define ROF(i, a, b) for (int i=(a); i>(b); --i)
#define vi vector<int>
#define vvi vector<vi>
#define vs vector<string>
#define pii pair<int,int>

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);
    
    string s;
    cin >> s;
    int n = s.size();

    vvi match(n, vi(n));
    FOR(i, 0, n-2) match[i][n-1] = s[i] == s[n-1];
    ROF(i, n-1, -1) ROF(j, n-2, i) {
        match[i][j] = min(j-i, s[i] == s[j] ? 1 + match[i+1][j+1] : 0);
    }

    vvi dp(n, vi(n+1)), go(n, vi(n+1));
    ROF(i, n-1, -1) {
        dp[i][n-i] = 1;
        go[i][n-i] = 1;
        ROF(k, n-i-1, 0) {
            dp[i][k] = dp[i][k+1];
            int m = match[i][i+k];
            if (i+k+m < n && (m == k || s[i+m] < s[i+k+m]) && 1 + dp[i+k][1+m] > dp[i][k]) {
                dp[i][k] = 1 + dp[i+k][1+m];
                go[i][k] = 1;
            }
        }
    }

    cout << dp[0][1] << '\n';
    int i = 0, k = 1;
    while (true) {
        if (!go[i][k]) ++k;
        else {
            cout << s.substr(i, k) << '\n';
            if (i+k >= n) break;
            int m = match[i][i+k];
            i += k;
            k = m+1;
        }
    }
}