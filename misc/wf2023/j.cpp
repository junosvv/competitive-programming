#include <bits/stdc++.h>
using namespace std;

#define int long long
#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define vi vector<int>
#define vvi vector<vi>

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int n, c;
    cin >> n >> c;
    if (c > n) c = n;
    vi a(n+1);
    FOR(i, 1, n+1) cin >> a[i];
    sort(a.begin(), a.end());
    vi pref = a;
    FOR(i, 2, n+1) pref[i] += pref[i-1];

    vvi b(n+1);
    FOR(start, 1, n+1) {
        b[start] = {0};
        int i = start;
        while (i <= n) {
            b[start].push_back(b[start].back() + a[i]);
            i += c;
        }
    }
    
    vi dp(n+1, 1e15);
    FOR(k, 1, c+1) dp[k] = a[k];
    FOR(k, c+1, n+1) {
        FOR(i, 1, c+1) {
            if (k-i*c+i <= 0) break;

            int cur = pref[i] + dp[k-i*c+i];
            if (i >= 2) cur += b[k-(i-1)*c+i][i-1];

            if (i == c) cur += a[c];
            else cur += a[k];

            dp[k] = min(dp[k], cur);
        }
    }
    cout << dp[n];
    // for (int i : dp) cout << i << ' ';
    // cout << '\n';
}