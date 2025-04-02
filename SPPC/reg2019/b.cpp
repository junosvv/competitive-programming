#include <bits/stdc++.h>
using namespace std;

#define int long long
#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define ROF(i, a, b) for (int i=(a); i>(b); --i)
#define vi vector<int>
#define SQ(x) (x)*(x)

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int n, B;
    cin >> n >> B;
    vi a(n);
    FOR(i, 0, n) cin >> a[i];
    sort(a.begin(), a.end());

    const int INF = 1e18;
    vi dp(n, INF);
    FOR(b, 1, B+1) {
        vi dp2(n, INF);
        FOR(i, 0, n) {
            FOR(j, 0, i+1) {
                int xtra = (j == 0 ? 0 : dp[j-1]);
                if (xtra == INF) continue;
                dp2[i] = min(dp2[i], SQ(a[i] - a[j]) + xtra);
            }
        }
        dp = dp2;
    }
    cout << dp[n-1];
}