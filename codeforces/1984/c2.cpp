#include <bits/stdc++.h>
using namespace std;

#define int long long
#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define ROF(i, a, b) for (int i=(a); i>(b); --i)
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int,int>

const int MOD = 998244353;

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);

    auto solve = [&]() {
        int n;
        cin >> n;
        vi a(n);
        FOR(i, 0, n) cin >> a[i];
        
        vector<pii> poss = {{0, 1}};
        FOR(i, 0, n) {
            for (pii &pr : poss) pr.first += a[i];
            
            int k = poss.size();
            FOR(j, 0, k) {
                poss.emplace_back(abs(poss[j].first), poss[j].second);
            }
            int lo = 1e18, hi = -1e18;
            for (pii &pr : poss) {
                lo = min(lo, pr.first);
                hi = max(hi, pr.first);
            }
            int locnt = 0, hicnt = 0;
            for (pii &pr : poss) {
                if (pr.first == lo) locnt = (locnt + pr.second) % MOD;
                else if (pr.first == hi) hicnt = (hicnt + pr.second) % MOD;
            }
            poss = {{lo, locnt}, {hi, hicnt}};
            if (poss.back().second == 0) poss.pop_back();
            // cout << "now\n";
            // for (pii pr : poss) cout << pr.first << ' ' << pr.second << ", ";
            // cout << '\n';
        }
        cout << poss.back().second << '\n';
    };

    int T;
    cin >> T;
    FOR(t, 0, T) solve();
}