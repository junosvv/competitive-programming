#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define vi vector<int>

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);
    
    int H, W;
    cin >> H >> W;

    vector<string> grid(H, string(W, '.'));
    FOR(r, 0, H) FOR(c, 0, W) cin >> grid[r][c];

    int adj = 0;
    auto check = [&](int r, int c) {
        if (0 <= r && r < H && 0 <= c && c < W && grid[r][c] == '#') {
            ++adj;
        }
    };

    FOR(r, 0, H) FOR(c, 0, W) if (grid[r][c] == '.') {
        check(r-1, c);
        check(r+1, c);
        check(r, c-1);
        check(r, c+1);
        if (adj >= 2) {
            cout << r+1 << ' ' << c+1;
            exit(0);
        }
        adj = 0;
    }
}