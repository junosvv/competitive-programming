#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define ROF(i, a, b) for (int i=(a); i>(b); --i)
#define lg long long

const lg MOD = 998244353;

template <class T> ostream& operator<<(ostream& os, vector<T>& x) {
    os << '[';
    bool first = true;
    for (T i : x) {
        if (!first) os << ", ";
        first = false;
        os << i;
    }
    return os << ']';
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);
    
    string s, t;
    cin >> s >> t;
    int n = s.size(), m = t.size();

    vector<lg> dp(m+1), occ(m+1, 1);
    dp[0] = 1;
    lg res = 0;
    FOR(i, 1, n+1) {
        vector<lg> dp2(m+1), occ2(m+1);
        dp2[0] = 2 * dp[0] % MOD;
        FOR(k, 1, min(m+1, i+1)) {
            dp2[k] = (dp[k] + (s[i-1] == t[m-k]) * dp[k-1]) % MOD;
        }
        if (i <= m) {
            dp2[i] = (dp2[i] + (s[i-1] == t[m-1]) * occ[m-i]) % MOD;
        }
        FOR(k, 0, m+1-i) {
            occ2[k] = (occ[k] * (s[i-1] == t[k+i-1]) + occ[k+1] * (s[i-1] == t[k])) % MOD;
        }

        dp = dp2;
        occ = occ2;
        // cout << i << ": " << dp << ' ' << occ << '\n';
        res = (res + dp[m]) % MOD;
    }
    cout << res;
}
