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
        int n, x, y;
        cin >> n >> x >> y;
        vi a(x);
        FOR(i, 0, x) cin >> a[i];
        sort(a.begin(), a.end());
        a.push_back(n+a[0]);
        vi diffs(x);
        FOR(i, 1, x+1) diffs[i-1] = a[i] - a[i-1];
        sort(diffs.begin(), diffs.end());

        int res = 0;
        int yy = y;
        FOR(i, 0, x) if (!(diffs[i]&1LL)) {
            int p = diffs[i] / 2 - 1;
            if (yy >= p) {
                yy -= p;
                res += p+1;
            } else {
                res += yy;
                yy = 0;
                break;
            }
        }
        FOR(i, 0, x) if (diffs[i]&1LL && diffs[i] >= 3) {
            int p = min(diffs[i] / 2, yy);
            yy -= p;
            res += p;
        }
        cout << res+x+y-yy-2 << '\n';
    };

    int T;
    cin >> T;
    FOR(t, 0, T) solve();
}