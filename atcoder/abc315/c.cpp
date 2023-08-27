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
    vector<pii> pairs(n);
    FOR(i, 0, n) cin >> pairs[i].second >> pairs[i].first;
    sort(pairs.begin(), pairs.end(), greater<pii>());

    int res = 0;
    FOR(i, 1, n) {
        res = max(res, pairs[i].first / (1 + (pairs[i].second == pairs[0].second)));
    }
    cout << res + pairs[0].first;
}