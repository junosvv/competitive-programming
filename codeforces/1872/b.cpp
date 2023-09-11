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
        int n;
        cin >> n;
        vi d(n), s(n);
        vi trap(401, 1e9);
        FOR(i, 0, n) {
            cin >> d[i] >> s[i];
            trap[d[i]] = min(trap[d[i]], s[i]);
        }
        int r = 1e9;
        FOR(j, 1, r+1) {
            r = min(r, j + (trap[j]-1)/2);
            // cout << j << " set to " << r << '\n';
        }
        cout << r << '\n';
    };

    int T;
    cin >> T;
    FOR(t, 0, T) solve();
}