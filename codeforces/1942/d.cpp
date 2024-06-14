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

    auto solve = [&]() {
        int n, k;
        cin >> n >> k;
        vvi a(n+3, vi(n+3));
        FOR(r, 2, n+2) {
            FOR(c, r, n+2) {
                cin >> a[r][c];
            }
        }
        n += 2;

        vvi dp(n);
        dp[0] = {0};
        dp[1] = {0};
        FOR(i, 2, n) {
            vi index(i);
            priority_queue<pii> pq;
            FOR(j, 0, i) {
                pq.emplace(a[j+2][i] + dp[j][0], j);
            }
            FOR(_, 0, k) {
                int u, j;
                tie(u, j) = pq.top();
                pq.pop();
                dp[i].push_back(u);
                ++index[j];
                if (index[j] < dp[j].size()) pq.emplace(a[j+2][i] + dp[j][index[j]], j);
                else if (pq.empty()) break;
            }
        }
        for (int t : dp[n-1]) cout << t << ' ';
        cout << '\n';
    };

    int T;
    cin >> T;
    FOR(t, 0, T) solve();
}