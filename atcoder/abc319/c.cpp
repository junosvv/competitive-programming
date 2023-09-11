#include <bits/stdc++.h>
using namespace std;

#define int long long
#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define ROF(i, a, b) for (int i=(a); i>(b); --i)
#define vi vector<int>
#define vvi vector<vi>

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);
    
    vvi grid(3, vi(3));
    FOR(i, 0, 3) FOR(j, 0, 3) cin >> grid[i][j];

    vi perm = {0, 1, 2, 3, 4, 5, 6, 7, 8};
    int res = 0;
    do {
        vi seenr(3), seenc(3);
        int seend=0, seenad=0;
        int good = 1;
        FOR(i, 0, 9) {
            int r = perm[i] / 3, c = perm[i] % 3;
            ++seenr[r];
            ++seenc[c];
            if (r == c) ++seend;
            if (r+c == 2) ++seenad;
            if (seenr[r] == 3 && grid[r][(c+1)%3] == grid[r][(c+2)%3] || seenc[c] == 3 && grid[(r+1)%3][c] == grid[(r+2)%3][c] || seend == 3 && r==c && grid[(r+1)%3][(c+1)%3] == grid[(r+2)%3][(c+2)%3] || seenad == 3 && r+c==2 && grid[(r+1)%3][(c+2)%3] == grid[(r+2)%3][(c+4)%3]) {
                good = 0;
                break;
            }
        }
        res += good;
    } while (next_permutation(perm.begin(), perm.end()));

    cout << setprecision(15) << res/362880.0;
}