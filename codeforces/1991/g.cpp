#include <bits/stdc++.h>
using namespace std;

#define int long long
#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define ROF(i, a, b) for (int i=(a); i>(b); --i)
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int,int>
#define t3i tuple<int,int,int>

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);

    auto solve = [&]() {
        int R, C, k, q;
        cin >> R >> C >> k >> q;\
        string s;
        cin >> s;

        vvi grid(R, vi(C));
        auto all = [&](int r1, int r2, int c1, int c2) {
            FOR(r, r1, r2) FOR(c, c1, c2) if (!grid[r][c]) return false;
            return true;
        };
        auto none = [&](int r1, int r2, int c1, int c2) {
            FOR(r, r1, r2) FOR(c, c1, c2) if (grid[r][c]) return false;
            return true;
        };
        auto transpose = [&]() {
            vvi grid2(C, vi(R));
            FOR(r, 0, R) FOR(c, 0, C) grid2[c][r] = grid[r][c];
            swap(grid, grid2);
            swap(R, C);
        };

        auto find = [&]() {
            FOR(r, 0, k) if (none(r, r+1, 0, k) && all(r, r+1, k, C)) return r;
            FOR(r, 0, R) if (none(r, r+1, 0, k)) return r;
            assert(false);
            return 0LL;
        };

        auto upd = [&](int res) {
            FOR(c, 0, k) grid[res][c] = 1;
            FOR(r, 0, R) if (all(r, r+1, 0, C)) FOR(c, 0, C) grid[r][c] = 2;
            FOR(c, 0, C) if (all(0, R, c, c+1)) FOR(r, 0, R) grid[r][c] = 2;
            FOR(r, 0, R) FOR(c, 0, C) if (grid[r][c] == 2) grid[r][c] = 0;
        };

        for (char x : s) {
            if (x == 'V') transpose();
            int res = find();
            upd(res);
            if (x == 'V') transpose();
            // FOR(r, 0, R) {
            //     FOR(c, 0, C) cout << ".x"[grid[r][c]];
            //     cout << '\n';
            // }
            if (x == 'H') cout << res+1 << " 1\n";
            else cout << "1 " << res+1 << '\n';
        }
    };

    int T;
    cin >> T;
    FOR(t, 0, T) solve();
}