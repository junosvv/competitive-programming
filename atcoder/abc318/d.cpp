#include <bits/stdc++.h>
using namespace std;

#define int long long
#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define ROF(i, a, b) for (int i=(a); i>(b); --i)
#define vi vector<int>
#define vvi vector<vi>

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);
    
    int n;
    cin >> n;
    vvi G(n, vi(n));
    FOR(u, 0, n) FOR(v, u+1, n) {
        cin >> G[u][v];
    }

    vi dp(1LL<<n);
    FOR(mask, 0, 1LL<<n) {
        FOR(d, 0, n) FOR(e, d+1, n) {
            if (!(mask>>d&1LL) && !(mask>>e&1LL)) {
                int nxt = mask | (1LL<<d) | (1LL<<e);
                dp[nxt] = max(dp[nxt], dp[mask] + G[d][e]);
            }
        }
    }

    cout << *max_element(dp.begin(), dp.end());
}