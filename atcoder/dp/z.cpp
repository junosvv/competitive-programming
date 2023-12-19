#include <bits/stdc++.h>
using namespace std;

#define int long long
#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define ROF(i, a, b) for (int i=(a); i>(b); --i)
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int,int>
#define SQ(x) (x)*(x)

void maxi(int& a, int b) {
    a = max(a, b);
}
void mini(int& a, int b) {
    a = min(a, b);
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int n, C;
    cin >> n >> C;
    vi h(n+1);
    FOR(i, 1, n+1) cin >> h[i];

    vi dp(n+1);
    deque<int> dq = {1};
    FOR(i, 2, n+1) {
        while (dq.size() >= 2) {
            int j = dq[0], k = dq[1];
            if (SQ(h[j]) + dp[j] - 2*h[i]*h[j] < SQ(h[k]) + dp[k] - 2*h[i]*h[k]) break;
            dq.pop_front();
        }
        dp[i] = SQ(h[i]-h[dq[0]]) + dp[dq[0]] + C;
        
        // for (int j : dq) {
        //     cout << j << ", " << SQ(h[j]) + dp[j] - 2*h[i]*h[j] + SQ(h[i]) + C << '\n';
        // }
        // cout << '\n';
        // cout << dp[i] << ' ';
        // FOR(j, 1, i) assert (SQ(h[i]-h[j]) + dp[j] + C >= dp[i]);
        
        while (dq.size() >= 2) {
            int j = dq[dq.size()-2], k = dq.back();
            if ((SQ(h[i]) + dp[i] - SQ(h[k]) - dp[k]) * (h[j] - h[k]) < (SQ(h[j]) + dp[j] - SQ(h[k]) - dp[k]) * (h[i] - h[k])) break;
            dq.pop_back();
        }
        dq.push_back(i);
    }

    cout << dp[n];
}