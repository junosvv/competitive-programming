#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define ROF(i, a, b) for (int i=(a); i>(b); --i)
#define lg long long
#define vi vector<int>

template <class T> ostream& operator<<(ostream& os, vector<T>& x) {
    os << '[';
    bool first = true;
    for (T& i : x) {
        if (!first) os << ", ";
        first = false;
        os << i;
    }
    return os << ']';
}

lg MOD = 998244353;

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);
    
    int n, k;
    cin >> n >> k;

    if (k == n) {
        cout << 1;
        exit(0);
    }
    
    // dp[x][y] means smallest rational occurs 2x times and y remain
    vector<vector<lg>> dp(n-k+1, vector<lg>(n-k+1)), pref(n-k+1, vector<lg>(n-k+1));
    FOR(s, 0, n-k+1) {
        dp[s][0] = 1;
        FOR(y, 1, s) {
            int x = s - y;
            dp[x][y] = pref[y][min(2*x, y)];
        }
        FOR(x, 1, s+1) {
            pref[s][x] = (dp[x][s-x] + pref[s][x-1]) % MOD;
        }
    }
    lg res = 0;
    FOR(t, 1, min(k, n-k)+1) {
        res = (res + dp[t][n-k-t]) % MOD;
    }
    cout << res;
}
