#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define ROF(i, a, b) for (int i=(a); i>(b); --i)
#define vi vector<int>
#define pii pair<int,int>
 
signed main() {
    ios::sync_with_stdio(0), cin.tie(0);
    
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vi a(n);
        FOR(i, 0, n) cin >> a[i];

        vector<pii> b(n-1);
        FOR(i, 1, n) b[i-1] = {a[i] - a[i-1], i+1};
        sort(b.begin(), b.end());

        vi res;
        FOR(i, 0, n-1) {
            if (b[i].first >= 0) break;
            res.push_back(b[i].second);
        }

        FOR(i, res.size(), n) res.push_back(1);
        reverse(res.begin(), res.end());
        FOR(i, 0, n) cout << res[i] << ' ';
        cout << '\n';
    }
}