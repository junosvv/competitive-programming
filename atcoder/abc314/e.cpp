#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define ROF(i, a, b) for (int i=(a); i>(b); --i)
#define vi vector<int>
#define vvi vector<vi>
 
signed main() {
    ios::sync_with_stdio(0), cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    vi cost(n);
    vvi wheels(n);
    FOR(i, 0, n) {
        int sz;
        cin >> cost[i] >> sz;
        wheels[i].resize(sz);
        FOR(j, 0, sz) cin >> wheels[i][j];
    }

    vector<double> dp(m+1, 1e9);
    dp[0] = 0;
    FOR(k, 1, m+1) {
        FOR(w, 0, n) {
            double cur = 0;
            int nonzero = 0;
            for (int p : wheels[w]) if (p != 0) {
                ++nonzero;
                cur += dp[k-p];
            }
            cur += cost[w] * wheels[w].size();
            cur /= nonzero;
            dp[k] = min(dp[k], cur);
        }
    }
    cout << setprecision(20) << dp[m] << '\n';
}