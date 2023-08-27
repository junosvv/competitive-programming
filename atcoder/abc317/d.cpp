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
    vi value(n);
    const int BIG = 1e5 + 1;
    vi dp(BIG, 1e15);
    dp[0] = 0;
    int already = 0, totz = 0;
    FOR(i, 0, n) {
        int x, y;
        cin >> x >> y >> value[i];
        totz += value[i];
        if (x > y) already += value[i];
        else {
            int cost = (x+y)/2 + 1 - x;
            ROF(k, BIG-1, value[i]-1) dp[k] = min(dp[k], cost + dp[k-value[i]]);
            // FOR(i, 0, BIG) if (dp[i] != 1e15) cout << i << ',' << dp[i] << ' ';
            // cout << '\n';
        }
    }
    int needed = max(0LL, totz/2 + 1 - already);
    cout << *min_element(dp.begin()+needed, dp.end());
}