#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define ROF(i, a, b) for (int i=(a); i>(b); --i)
#define vi vector<int>
#define pii pair<int,int>
#define t3i tuple<int,int,int>
#define lg long long

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int caset = 1;
    while (true) {
        int n, m;
        cin >> n >> m;

        if (n == 0 && m == 0) break;

        const int BIG = 400;
        vector<vi> dp(m+1, vi(2*BIG+1, -1e8));
        vector<vector<vector<pii>>> par(n, vector<vector<pii>>(m+1, vector<pii>(2*BIG+1, {-1e8, -1e8})));
        dp[0][BIG] = 0;

        FOR(i, 0, n) FOR(s, 0, m+1) FOR(sm, -BIG, BIG+1) {
            par[i][s][BIG+sm] = {s, sm};
        }
        vector<pii> pairs(n);
        FOR(i, 0, n) {
            cin >> pairs[i].first >> pairs[i].second;
        }
        reverse(pairs.begin(), pairs.end());
        FOR(i, 0, n) {
            int p, d;
            tie(p, d) = pairs[i];
            // cout << "proc " << p << ' ' << d << '\n';
            vector<vi> dp2 = dp;
            FOR(s, 0, m+1) FOR(sm, -BIG, BIG+1) {
                if (s != m && dp[s][BIG+sm] != -1e8) {
                    assert (0 <= BIG+sm+p-d && BIG+sm+p-d < 2*BIG+1);
                    int nw = dp[s][BIG+sm]+p+d;
                    if (nw >= dp2[s+1][BIG+sm+p-d]) {
                        dp2[s+1][BIG+sm+p-d] = nw;
                        par[i][s+1][BIG+sm+p-d] = {s, sm};
                    }
                }
            }
            dp = dp2;
        }

        FOR(chksm, 0, BIG+1) {
            if (dp[m][BIG+chksm] != -1e8 || dp[m][BIG-chksm] != -1e8) {
                int i = n-1;
                int s = m;
                int sm = dp[m][BIG+chksm] > dp[m][BIG-chksm] ? chksm : -chksm;
                int psum = (dp[s][BIG+sm] + sm) / 2;
                int dsum = (dp[s][BIG+sm] - sm) / 2;
                cout << "Jury #" << caset++ << '\n';
                vi res;
                while (i >= 0) {
                    // cout << "ans: " << i << ' ' << s << ' ' << sm << ": " << dp[s][BIG+sm] << '\n';
                    if (par[i][s][BIG+sm].first != s) res.push_back(i);
                    tie(s, sm) = par[i][s][BIG+sm];
                    --i;
                }
                cout << "Best jury has value " << psum << " for prosecution and value " << dsum << " for defence:" << '\n';
                for (int i : res) cout << ' ' << n-i;
                cout << '\n';
                cout << '\n';
                break;
            }
        }
    }
    
}

/*
4 4
1 1
2 2
3 3
4 4
0 0
*/