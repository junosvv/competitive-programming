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

    string s;
    cin >> s;
    int n = s.size();

    int upp = n/2 + 1;
    vi dp(upp);
    dp[0] = 1;
    FOR(i, 0, n) {
        vi dp2(upp);
        if (s[i] == '(' || s[i] == '?') FOR(k, 1, upp) dp2[k] = (dp2[k] + dp[k-1]) % MOD;
        if (s[i] == ')' || s[i] == '?') FOR(k, 1, upp) dp2[k-1] = (dp2[k-1] + dp[k]) % MOD;
        dp = dp2;
    }
    cout << dp[0];
}