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
    
    int R, C, K;
    cin >> R >> C >> K;
    vector<string> grid(R);
    FOR(r, 0, R) cin >> grid[r];

    int res = -1;
    auto solve = [&](vector<string>& grid) {
        int R = grid.size(), C = grid[0].size();

        FOR(r, 0, R) {
            vi pref(C+1);
            int pref_x = -K;
            FOR(c, 0, C) {
                ++pref_x;

                pref[c+1] = pref[c];
                if (grid[r][c] == 'x') {
                    pref_x = -K;
                    pref[c+1] = 0;
                } else if (grid[r][c] == 'o') {
                    ++pref[c+1];
                }

                if (pref_x >= 0) {
                    res = max(res, pref[c+1] - pref[c-K+1]);
                }
            }
        }
    };

    solve(grid);
    vector<string> grid2(C, string(R, '.'));
    FOR(r, 0, R) FOR(c, 0, C) grid2[c][r] = grid[r][c];
    // for (string s : grid2) cout << s << '\n';
    solve(grid2);

    if (res == -1) cout << -1;
    else cout << K-res;
}