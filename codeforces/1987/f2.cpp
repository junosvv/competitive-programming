#include <bits/stdc++.h>
using namespace std;

#define int long long
#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define ROF(i, a, b) for (int i=(a); i>(b); --i)
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int,int>
#define t3i tuple<int,int,int>

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);

    auto solve = [&]() {
        int n;
        cin >> n;
        vi a(n);
        FOR(i, 0, n) cin >> a[i];

        const int INF = 1000;
        vvi dp(n+1, vi(n+1, INF));
        FOR(i, 1, n+1) dp[i][i-1] = 0;

        ROF(i, n-2, -1) {
            for (int j=i+1; j<n; j+=2) {
                int cc = i+1-a[i];
                if (cc < 0 || cc&1) continue;
                cc /= 2;
                for (int r=i+1; r<=j; r+=2) {
                    if (dp[i+1][r-1] > cc) continue;
                    int cur = max(cc, dp[r+1][j] - (r-i+1)/2);
                    dp[i][j] = min(dp[i][j], cur);
                }
            }
        }

        vi dp2(n+1);
        FOR(j, 1, n) {
            dp2[j] = dp2[j-1];
            for (int i=j-1; i>=0; i-=2) {
                int maxop = i-1 < 0 ? 0 : dp2[i-1];
                if (maxop >= dp[i][j]) {
                    dp2[j] = max(dp2[j], maxop + (j-i+1)/2);
                }
            }
        }
        cout << dp2[n-1] << '\n';
    };

    int T;
    cin >> T;
    FOR(t, 0, T) solve();
}