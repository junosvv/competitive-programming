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
        vvi grid(n);
        int mn = 1e9, sndmn = 1e9, sndsm = 0;
        FOR(i, 0, n) {
            int sz;
            cin >> sz;
            grid[i].assign(sz, 0);
            FOR(j, 0, sz) cin >> grid[i][j];
            sort(grid[i].begin(), grid[i].end());
            mn = min(mn, grid[i][0]);
            sndmn = min(sndmn, grid[i][1]);
            sndsm += grid[i][1];
        }
        cout << sndsm - sndmn + mn << '\n';
    };

    int T;
    cin >> T;
    FOR(t, 0, T) solve();
}