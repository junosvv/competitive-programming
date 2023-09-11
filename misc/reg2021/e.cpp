#include <bits/stdc++.h>
using namespace std;

#define int long long
#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define ROF(i, a, b) for (int i=(a); i>(b); --i)
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int,int>

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);
    
    int n;
    cin >> n;
    vector<pii> segs(n);
    FOR(i, 0, n) cin >> segs[i].first >> segs[i].second;
    sort(segs.begin(), segs.end());

    const int BIG = 1e6+1;
    vi b(BIG, n);
    int i = 0;
    FOR(j, 0, n) {
        while (i < segs[j].first) b[i++] = j;
    }

    // for (int i : b) cout << i << ' ';

    vi dp(n+1);
    int j = n-1;
    set<pii> rs;
    ROF(i, n-1, -1) {
        dp[i] = dp[i+1];
        while (j > i && segs[j].first > segs[i].second) {
            rs.erase(rs.find({segs[j].second, j}));
            --j;
        }
        if (!rs.empty()) {
            int k = (*rs.begin()).second;
            int r = max(segs[i].second, (*rs.begin()).first);
            dp[i] = max(dp[i], 2 + dp[b[r]]);
        }
        rs.emplace(segs[i].second, i);
    }
    // for (int i : dp) cout << i << ' ';
    cout << dp[0] << '\n';

    // deque<pii> dq;
    // vi dp(n+1);
    // ROF(i, n-1, -1) {
    //     dp[i] = dp[i+1];
    //     while (!dq.empty() && dq.front().first > segs[i].second) dq.pop_front();
    //     // cout << "at " << segs[i].first << ' ' << segs[i].second << " dq: ";
    //     // for (pii pr : dq) cout << pr.first << "," << pr.second << ' ';
    //     // cout << '\n';
    //     if (!dq.empty()) {
    //         int r = max(segs[i].second, dq.front().second);
    //         int j = b[r];
    //         dp[i] = max(dp[i], 2 + dp[j]);
    //     }
    //     while (!dq.empty() && dq.back().second >= segs[i].second) dq.pop_back();
    //     dq.push_back(segs[i]);
    // }
    // // for (int i : dp) cout << i << ' ';
    // // cout << '\n';
    // cout << dp[0] << '\n';
}