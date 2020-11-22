#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define ROF(i, a, b) for (int i=(a); i>(b); --i)
#define int long long
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

int MOD = 1e9 + 7;

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);
    
    int n;
    string x(2, ' ');
    char ab, ba;
    cin >> n >> x[0] >> ab >> ba >> x[1];
    if (n == 2) {
        cout << 1 << '\n';
        exit(0);
    }
    char dup = x[ab == 'B'];
    if (ab == dup) {
        cout << 1 << '\n';
    } else if (ba != ab) {
        int res = 1;
        FOR(i, 0, n-3) res = res * 2 % MOD;
        cout << res << '\n';
    } else {
        vi dp(n);
        dp[0] = 1;
        dp[1] = 2;
        FOR(i, 2, n) dp[i] = (dp[i-1] + dp[i-2]) % MOD;
        cout << dp[n-3] << '\n';
    }
}
