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
    string s;
    cin >> s;
 
    vector<vi> dp(27, vi(27));
    dp[26][26] = 1;
 
    vi sdp(27);
    FOR(x, 0, 27) FOR(y, 0, 27) sdp[x] = (sdp[x] + dp[y][x]) % MOD;
 
    FOR(i, 0, n) {
        vector<vi> dp2(27, vi(27));
        FOR(x, 0, 27) FOR(y, 0, 26) if (x != y && (s[i] == '?' || s[i]-'a' == y)) {
            dp2[x][y] = (sdp[x] + MOD - dp[y][x]) % MOD;
        }
        dp = dp2;
        sdp.assign(27, 0);
        FOR(x, 0, 27) FOR(y, 0, 27) sdp[x] = (sdp[x] + dp[y][x]) % MOD;
    }

    int res = 0;
    FOR(x, 0, 26) res = (res + sdp[x]) % MOD;
    cout << res;
}