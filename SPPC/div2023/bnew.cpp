#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef long long ll;
#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define ROF(i, a, b) for (int i=(a); i>(b); --i)
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int,int>
#define vs vector<string>

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int S, C, T;
    string s, t;
    cin >> S >> C >> T >> s >> t;
    int n = s.size(), m = t.size();

    const int INF = 1e15;
    vvi dp(n+1, vi(m+1, INF));
    dp[n][m] = 0;
    vi ropt(n+1, 1e15), copt(m+1, 1e15);
    ROF(i, n, -1) ROF(j, m, -1) {
        if (i < n && j < m) dp[i][j] = min(dp[i][j], dp[i+1][j+1] + T * (s[i] != t[j]));
        dp[i][j] = min(dp[i][j], S + ropt[i] - j*C);
        dp[i][j] = min(dp[i][j], S + copt[j] - i*C);
        ropt[i] = min(ropt[i], dp[i][j] + j*C);
        copt[j] = min(copt[j], dp[i][j] + i*C);
    }
    cout << dp[0][0] << '\n';



    // const int INF = 1e15;
    // vvi dp(n+1, vi(m+1, INF));
    // dp[n][m] = 0;
    // vvi dps = dp, dpt = dp;
    
    // ROF(i, n, -1) ROF(j, m, -1) {
    //     if (i != n) {
    //         int temp = C + dps[i+1][j];
    //         dp[i][j] = min(dp[i][j], S + temp);
    //         dpt[i][j] = min(dpt[i][j], S + temp);
    //         dps[i][j] = min(dps[i][j], temp);
    //     }
    //     if (j != m) {
    //         int temp = C + dpt[i][j+1];
    //         dp[i][j] = min(dp[i][j], S + temp);
    //         dps[i][j] = min(dps[i][j], S + temp);  
    //         dpt[i][j] = min(dpt[i][j], temp);
    //     }
    //     if (i != n && j != m) {
    //         int temp = dp[i+1][j+1];
    //         if (s[i] != t[j]) temp += T;
    //         dp[i][j] = min(dp[i][j], temp);
    //         dps[i][j] = min(dps[i][j], temp);
    //         dpt[i][j] = min(dpt[i][j], temp);
    //     }
    // }
    // cout << dp[0][0] << '\n';
}