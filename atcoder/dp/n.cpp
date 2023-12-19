#include <bits/stdc++.h>
using namespace std;

#define int long long
#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define ROF(i, a, b) for (int i=(a); i>(b); --i)
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int,int>
#define SQ(x) (x)*(x)

void maxi(int& a, int b) {
    a = max(a, b);
}
void mini(int& a, int b) {
    a = min(a, b);
}

const int MOD = 1e9+7;

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);
    
    int n;
    cin >> n;
    vi a(n);
    FOR(i, 0, n) cin >> a[i];

    vvi pref(n, vi(n));
    FOR(i, 0, n) {
        pref[i][i] = a[i];
        FOR(j, i+1, n) pref[i][j] = pref[i][j-1] + a[j];
    }

    vvi dp(n, vi(n, 1e15));
    FOR(i, 0, n) dp[i][i] = 0;

    FOR(s, 1, n) FOR(i, 0, n-s) {
        int j = i+s;
        FOR(k, i, j) {
            mini(dp[i][j], pref[i][k] + pref[k+1][j] + dp[i][k] + dp[k+1][j]);
        }
    }
    cout << dp[0][n-1];
}