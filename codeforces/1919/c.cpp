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

        int u = n, v = n;
        int res = 0;
        FOR(i, 0, n) {
            // maintain u <= v
            if (u < a[i] && a[i] <= v) v = a[i];
            else {
                u = a[i];
                if (u > v) {
                    swap(u, v);
                    ++res;
                }
            }
        }
        cout << res << '\n';
    };

    int T;
    cin >> T;
    FOR(t, 0, T) solve();
}