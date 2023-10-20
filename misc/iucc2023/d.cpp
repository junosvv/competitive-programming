#include <bits/stdc++.h>
using namespace std;

#define int long long
#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define ROF(i, a, b) for (int i=(a); i>(b); --i)
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int,int>

void maxi(int& a, int b) {
    a = max(a, b);
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);
    
    int N, K, D;
    cin >> N >> K >> D;

    if (K == 0 && D == 1) {
        cout << 0;
        exit(0);
    }

    const int BIG = 13;
    vi cost(BIG);
    FOR(x, 0, BIG) cost[x] = max(0LL, (1LL<<x) - K);

    vvi dp(BIG, vi(D, -1));
    dp[0][max(0LL, 1-K)] = 1;
    int res = 1;
    FOR(n, 0, N-1) {
        vvi dp2(BIG, vi(D, -1));
        FOR(x, 0, BIG) {
            FOR(d, 0, D) if (dp[x][d] != -1) {
                if (x == 0) {
                    if (d+cost[x] < D) maxi(dp2[x][d+cost[x]], dp[x][d] + (1LL<<x));
                } else {
                    if (d+cost[x-1] < D) maxi(dp2[x-1][d+cost[x-1]], dp[x][d] + (1LL<<x-1));
                }
                if (x+1 < BIG && d+cost[x+1] < D) maxi(dp2[x+1][d+cost[x+1]], dp[x][d] + (1LL<<x+1));
            }
        }
        dp = dp2;
        FOR(x, 0, BIG) FOR(d, 0, D) maxi(res, dp[x][d]);
        // FOR(x, 0, BIG) {
        //     FOR(d, 0, D) cout << dp[x][d] << ' ';
        //     cout << '\n';
        // }
        // cout << '\n';
    }
    cout << res;
}