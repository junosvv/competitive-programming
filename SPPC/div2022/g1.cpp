#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define ROF(i, a, b) for (int i=(a); i>(b); --i)
#define vi vector<int>

int INF = 1e9;

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);
    
    int n, E;
    cin >> n >> E;

    vector<pair<int,int>> cpus(n);
    FOR(i, 0, n) cin >> cpus[i].first >> cpus[i].second;

    vi dp(E+1, INF);
    dp[0] = 0;
    FOR(i, 0, n) {
        vi dp2 = dp;
        FOR(e, 1, E+1) {
            if (e-cpus[i].second < 0 || dp[e-cpus[i].second] == INF) continue;
            dp2[e] = min(dp2[e], cpus[i].first + dp[e-cpus[i].second]);
        }
        dp = dp2;
    }

    ROF(e, E, -1) {
        if (dp[e] != INF) {
            cout << dp[e];
            break;
        }
    }
}