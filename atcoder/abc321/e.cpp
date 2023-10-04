#include <bits/stdc++.h>
using namespace std;

#define int long long
#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define ROF(i, a, b) for (int i=(a); i>(b); --i)
#define vi vector<int>
#define vvi vector<vi>
#define vs vector<string>
#define vvs vector<vs>
#define pii pair<int,int>

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);
    
    int n, k, p;
    cin >> n >> k >> p;
    vi cost(n);
    vvi plan(n, vi(k));
    FOR(i, 0, n) {
        cin >> cost[i];
        FOR(j, 0, k) cin >> plan[i][j];
    }

    map<vi,int> dp;
    vi init(k);
    dp[init] = 0;
    FOR(i, 0, n) {
        map<vi,int> dp2 = dp;
        for (pair<vi,int> pr : dp) {
            vi a = pr.first;
            int old = pr.second;
            FOR(j, 0, k) a[j] = min(p, a[j] + plan[i][j]);
            if (!dp2.count(a)) dp2[a] = old + cost[i];
            else dp2[a] = min(dp2[a], old + cost[i]);
        }
        dp = dp2;
    }
    vi fin(k, p);
    if (dp.count(fin)) cout << dp[fin];
    else cout << -1;
}