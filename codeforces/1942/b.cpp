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
        vi a(n);
        FOR(i, 0, n) cin >> a[i];

        vi seen(n+1), res(n);
        int i = 0;
        FOR(t, 0, n) {
            if (a[t] > 0) {
                res[t] = i;
            } else if (a[t] < 0) {
                assert(!seen[i-a[t]]);
                res[t] = i-a[t];
            } else {
                assert(false);
            }
            seen[res[t]] = 1;
            while (seen[i]) ++i;
        }
        for (int i : res) cout << i << ' ';
        cout << '\n';
    };

    int T;
    cin >> T;
    FOR(t, 0, T) solve();
}