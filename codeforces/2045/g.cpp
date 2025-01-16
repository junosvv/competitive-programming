#include <bits/stdc++.h>
using namespace std;

#define int long long
#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define ROF(i, a, b) for (int i=(a); i>(b); --i)
#define vi vector<int>
#define vvi vector<vi>
#define vs vector<string>
#define pii pair<int,int>

int powa(int base, int exp) {
    int res = 1;
    FOR(i, 0, exp) res *= base;
    return res;
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);
    
    int R, C, X;
    cin >> R >> C >> X;
    vvi grid(R, vi(C));
    FOR(r, 0, R) FOR(c, 0, C) {
        char x;
        cin >> x;
        grid[r][c] = x-'0';
    }

    vvi horiz(R, vi(C)), vert(R, vi(C));
    FOR(r, 0, R) FOR(c, 1, C) horiz[r][c] = grid[r][c-1] - grid[r][c];
    FOR(r, 1, R) FOR(c, 0, C) vert[r][c] = grid[r-1][c] - grid[r][c];

    FOR(r, 0, R) FOR(c, 0, C) {
        horiz[r][c] = powa(horiz[r][c], X);
        vert[r][c] = powa(vert[r][c], X);
    }

    bool rip = false;
    FOR(r, 1, R) {
        FOR(c, 1, C) {
            if (horiz[r-1][c] + vert[r][c] - horiz[r][c] - vert[r][c-1] != 0) {
                rip = true;
            }
        }
    }
    
    FOR(r, 0, R) FOR(c, 1, C) horiz[r][c] += horiz[r][c-1];
    FOR(r, 1, R) FOR(c, 0, C) vert[r][c] += vert[r-1][c];

    int Q;
    cin >> Q;
    FOR(qi, 0, Q) {
        int sr, sc, fr, fc;
        cin >> sr >> sc >> fr >> fc;
        --sr; --sc; --fr; --fc;
        if (X == 1) cout << grid[sr][sc] - grid[fr][fc] << '\n';
        else if (rip) cout << "INVALID\n";
        else cout << horiz[sr][fc] - horiz[sr][sc] + vert[fr][fc] - vert[sr][fc] << '\n';
    }
}