#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define ROF(i, a, b) for (int i=(a); i>(b); --i)
#define lg long long

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
    
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> a(n);
        FOR(i, 0, n) cin >> a[i];

        vector<vector<int>> dp(n+1, vector<int>(2, 1e9));
        dp[0][1] = 0;
        FOR(i, 1, n+1) {
            dp[i][0] = a[i-1] + min(dp[i-1][1], i==1 ? (int)1e9 : a[i-2] + dp[i-2][1]);
            dp[i][1] = min(dp[i-1][0], i==1 ? (int)1e9 : dp[i-2][0]);
        }
        cout << min(dp[n][0], dp[n][1]) << '\n';
    }
}
