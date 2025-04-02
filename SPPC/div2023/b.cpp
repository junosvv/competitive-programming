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

vector<vector<vvi>> dp;
int f(int i, int j) {
    int res = 1e15;
    FOR(sused, 0, 2) FOR(tused, 0, 2) {
        res = min(res, dp[sused][tused][i][j]);
    }
    return res;
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int S, C, T;
    string s, t;
    cin >> S >> C >> T >> s >> t;
    int n = s.size(), m = t.size();

    dp.assign(2, vector<vvi>(2, vvi(n+1, vi(m+1, 1e15))));
    dp[0][0][0][0] = 0;
    FOR(i, 0, n+1) FOR(j, 0, m+1) FOR(sused, 0, 2) FOR(tused, 0, 2) if (dp[sused][tused][i][j] != 1e15) {
        if (i < n) dp[1][tused][i+1][j] = min(dp[1][tused][i+1][j], dp[sused][tused][i][j] + C + S*(1-sused));
        if (j < m) dp[sused][1][i][j+1] = min(dp[sused][1][i][j+1], dp[sused][tused][i][j] + C + S*(1-tused));
        if (i < n && j < m) {
            // if (i == 6 && j == 2) {
            //     cout << dp[0][0][i][j] << '\n';
            //     cout << "setting " << sused << ' ' << tused << " to " << dp[sused][tused][i][j] + T * (s[i] != t[j]) << endl;
            // }
            dp[0][0][i+1][j+1] = min(dp[0][0][i+1][j+1], dp[sused][tused][i][j] + T * (s[i] != t[j]));
        }
    }
    cout << f(n, m) << '\n';
    // FOR(i, 0, n+1) {
    //     FOR(j, 0, m+1) cout << f(i, j) << ' ';
    //     cout << '\n';
    // }
}