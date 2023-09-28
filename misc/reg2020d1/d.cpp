#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define ROF(i, a, b) for (int i=(a); i>(b); --i)
#define vi vector<int>
#define vvi vector<vi>

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int n;
    cin >> n;
    vi a(n+1);
    FOR(i, 1, n+1) cin >> a[i];
    a.push_back(1e9+2);
    n += 2;

    vi dp(n, 1e6);
    dp[n-1] = 0;
    ROF(i, n-2, -1) {
        int mn = 1e9+3;
        FOR(j, i+1, n) {
            if (a[i] < a[j] && a[j] <= mn) {
                dp[i] = min(dp[i], 1 + dp[j]);
                mn = a[j];
            }
        }
    }
    cout << dp[0] - 1;
}