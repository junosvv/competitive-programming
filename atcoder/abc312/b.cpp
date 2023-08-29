#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define ROF(i, a, b) for (int i=(a); i>(b); --i)
#define vi vector<int>
#define vvi vector<vi>
 
signed main() {
    ios::sync_with_stdio(0), cin.tie(0);
    
    int R, C;
    cin >> R >> C;
    vector<string> grid(R);
    FOR(r, 0, R) cin >> grid[r];

    auto check = [&](int r, int c) {
        FOR(rr, r, r+3) FOR(cc, c, c+3) if (grid[rr][cc] != '#' || grid[rr+6][cc+6] != '#') return false;
        FOR(k, 0, 4) if (grid[r+3][c+k] != '.' || grid[r+k][c+3] != '.' || grid[r+5+k][c+5] != '.' || grid[r+5][c+5+k] != '.') return false;
        return true;
    };

    FOR(r, 0, R-8) FOR(c, 0, C-8) {
        if (check(r, c)) cout << r+1 << ' ' << c+1 << '\n';
    }
}