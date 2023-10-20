#include <bits/stdc++.h>
using namespace std;

#define int long long
#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define ROF(i, a, b) for (int i=(a); i>(b); --i)
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int,int>

const int MOD = 1e9+7;

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);
    
    int n;
    string s;
    cin >> n >> s;
    s = "<" + s;
    
    vi dp = {1};
    FOR(i, 1, n) {
        vi dp2(i+1);
        if (s[i] != s[i-1]) reverse(dp.begin(), dp.end());
        FOR(j, 1, i+1) dp2[j] = (dp2[j-1] + dp[j-1]) % MOD;
        dp = dp2;
    }
    cout << accumulate(dp.begin(), dp.end(), 0LL) % MOD;
}