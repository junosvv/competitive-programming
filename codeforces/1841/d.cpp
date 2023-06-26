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

    int T;
    cin >> T;
    FOR(t, 0, T) {
        int n;
        cin >> n;

        vector<pii> segs(n), bigsegs;
        FOR(i, 0, n) {
            cin >> segs[i].first >> segs[i].second;
        }
        sort(segs.begin(), segs.end());
        
        FOR(i, 0, n) FOR(j, i+1, n) {
            if (segs[j].first <= segs[i].second) bigsegs.emplace_back(segs[i].first, max(segs[i].second, segs[j].second));
        }
        int m = bigsegs.size();

        int l = 1e10;
        int res = n;
        ROF(i, m-1, -1) {
            if (bigsegs[i].second < l) {
                res -= 2;
                l = bigsegs[i].first;
            }
        }
        cout << res << '\n';
    }
}