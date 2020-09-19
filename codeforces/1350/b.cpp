#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define ROF(i, a, b) for (int i=(a); i>(b); --i)
#define lg long long

long long MOD = 1e9+7;

template <class T> ostream& operator<<(ostream& os, vector<T>& x) {
    os << '[';
    bool first = true;
    for (auto i : x) {
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

        vector<int> dp(n, 1);
        int res = 1;
        FOR(i, 0, n) {
            for (int u=i+(i+1); u<n; u+=(i+1)) {
                if (a[i] < a[u]) {
                    dp[u] = max(dp[u], 1 + dp[i]);
                }
            }
            res = max(res, dp[i]);
        }
        cout << res << '\n';
    }
}
