#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define ROF(i, a, b) for (int i=(a); i>(b); --i)
#define vi vector<int>
#define pii pair<int,int>
 
signed main() {
    ios::sync_with_stdio(0), cin.tie(0);
 
    int n;
    cin >> n;
    vector<pii> lines(n);
    FOR(i, 0, n) cin >> lines[i].first >> lines[i].second;

    sort(lines.begin(), lines.end(), [](auto &x, auto &y) {
        return x.first < y.first || x.first == y.first && x.second > y.second;
    });

    vi pref(n), suff(n);
    FOR(i, 0, n) pref[i] = suff[i] = lines[i].second;
    FOR(i, 1, n) pref[i] = min(pref[i], pref[i-1]);
    ROF(i, n-2, -1) suff[i] = min(suff[i], suff[i+1]);

    int res = 0;
    FOR(i, 1, n) {
        res = max(res, max(pref[i-1] - lines[i-1].first + 1, 0LL) + max(suff[i] - lines[n-1].first + 1, 0LL));
        cout << i << ": " << max(pref[i-1] - lines[i-1].first + 1, 0LL) << ' ' << max(suff[i] - lines[n-1].first + 1, 0LL) << endl;
    }
    cout << res;
}