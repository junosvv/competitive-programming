#include <bits/stdc++.h>
using namespace std;

#define int long long
#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define ROF(i, a, b) for (int i=(a); i>(b); --i)
#define vi vector<int>
#define vvi vector<vi>
#define vs vector<string>
#define pii pair<int,int>
#define vpii vector<pii>
#define vvpii vector<vpii>
#define mii map<int,int>

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);

    auto solve = [&]() {
        int n, m, k;
        cin >> n >> m >> k;
        vi a(n), b(m);
        FOR(i, 0, n) cin >> a[i];
        FOR(i, 0, m) cin >> b[i];

        vi cap(1<<m, -1);
        FOR(mask, 0, 1<<m) {
            FOR(i, 0, m) if (mask>>i&1) cap[mask] &= b[i];
        }

        vvi dp(n, vi(m+1));
        FOR(i, 0, n) {
            FOR(mask, 0, 1<<m) {
                int k = __builtin_popcount(mask);
                dp[i][k] = max(dp[i][k], a[i] - (a[i] & cap[mask]));
            }
        }

        vi idx(n);
        priority_queue<pii> pq;
        FOR(i, 0, n) pq.emplace(dp[i][1] - dp[i][0], i);
        FOR(_, 0, k) {
            if (pq.empty()) break;
            int best = pq.top().first, i = pq.top().second;
            pq.pop();
            ++idx[i];
            if (idx[i] < m) {
                pq.emplace(dp[i][idx[i]+1] - dp[i][idx[i]], i);
            }
            a[i] -= best;
        }

        cout << accumulate(a.begin(), a.end(), 0LL) << '\n';
    };

    int T;
    cin >> T;
    FOR(t, 0, T) solve();
}