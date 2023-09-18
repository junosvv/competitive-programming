#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define ROF(i, a, b) for (int i=(a); i>(b); --i)
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int,int>

void mini(int& a, int b) {
    a = min(a, b);
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);
    
    int n, H;
    cin >> n >> H;
    vi x(n+1), p(n+1), f(n+1);
    FOR(i, 1, n+1) cin >> x[i];
    FOR(i, 1, n) cin >> p[i] >> f[i];

    vvi dp(H+1, vi(H+1, 1e9));
    FOR(k, 0, H+1) dp[H][k] = 0;
    FOR(i, 0, n) {
        vvi dp2(H+1, vi(H+1, 1e9));
        int d = x[i+1] - x[i];
        FOR(j, d, H+1) {
            FOR(k, 0, H-d+1) {
                mini(dp2[j-d][k+d], dp[j][k]);
                mini(dp2[min(j-d+f[i+1], H)][k+d], dp[j][k] + p[i+1]);
                if (k+d-f[i+1] >= 0) mini(dp2[j-d][k+d-f[i+1]], dp[j][k] + p[i+1]);
            }
            FOR(k, H-f[i+1], H) {
                mini(dp2[j-d][k], dp[j][H-d] + p[i+1]);
            }
        }
        dp = dp2;
    }

    int res = 1e9;
    FOR(j, 0, H+1) mini(res, dp[j][j]);
    if (res == 1e9) cout << -1;
    else cout << res;
}