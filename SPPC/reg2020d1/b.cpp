#include <bits/stdc++.h>
using namespace std;

#define int long long
#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define ROF(i, a, b) for (int i=(a); i>(b); --i)
#define vi vector<int>
#define vvi vector<vi>

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int n, c, k;
    cin >> n >> c >> k;
    c *= 100;

    vi dp(k+1, -1);
    dp[0] = c;
    FOR(i, 0, n) {
        int price, f;
        cin >> price >> f;
        int buy = price * (100+f);
        int sell = price * (100-f);
        
        vi pref(k+1);
        FOR(j, 0, k+1) pref[j] = dp[j] + j * buy;
        FOR(j, 1, k+1) pref[j] = max(pref[j], pref[j-1]);

        vi dp2 = dp;
        FOR(j, 0, k+1) {
            dp2[j] = max(dp2[j], pref[j] - j*buy);
        }

        deque<int> dq;
        ROF(j, k, -1) {
            while (!dq.empty() && dp[dq.front()] - (dq.front()-j)*f*price < 0) dq.pop_front();
            if (!dq.empty()) {
                dp2[j] = max(dp2[j], dp[dq.front()] + dq.front()*sell - j*sell);
            }
            while (!dq.empty() && dp[j] + j*sell >= dp[dq.back()] + dq.back()*sell) dq.pop_back();
            dq.push_back(j);
        }

        dp = dp2;
    }
    cout << dp[0];
}