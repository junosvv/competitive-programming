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
        int n;
        cin >> n;
        vector<pii> segs(n);
        FOR(i, 0, n) cin >> segs[i].first >> segs[i].second >> segs[i].second >> segs[i].second;
        sort(segs.begin(), segs.end());

        vector<pii> segs2 = {{0, 0}};
        FOR(i, 0, n) {
            int l = segs[i].first, b = segs[i].second;
            if (l > segs2.back().second) segs2.emplace_back(l, b);
            else segs2.back().second = max(segs2.back().second, b);
        }

        int m = segs2.size();
        int q;
        cin >> q;
        FOR(qi, 0, q) {
            int k;
            cin >> k;
            pii pr = *prev(upper_bound(segs2.begin(), segs2.end(), pii{k, 1e10}));
            if (pr.first <= k) k = max(k, pr.second);
            cout << k << ' ';
        }
        cout << '\n';
    };

    int T;
    cin >> T;
    FOR(t, 0, T) solve();
}   