#include <bits/stdc++.h>
using namespace std;

#define int long long
#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define ROF(i, a, b) for (int i=(a); i>(b); --i)
#define vi vector<int>
#define vvi vector<vi>

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);

    auto solve = [&]() {
        int l, r;
        cin >> l >> r;
        if (r <= 3) {
            cout << -1 << '\n';
            return;
        }
        if (l != r) {
            if (r&1) --r;
            cout << r/2 << ' ' << r/2 << '\n';
            return;
        }
        for (int d=2; d*d<=r; ++d) {
            if (r%d == 0) {
                cout << d << ' ' << r-d << '\n';
                return;
            }
        }
        cout << -1 << '\n';
        return;
    };

    int T;
    cin >> T;
    FOR(t, 0, T) solve();
}