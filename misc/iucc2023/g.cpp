#include <bits/stdc++.h>
using namespace std;

#define int long long
#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define ROF(i, a, b) for (int i=(a); i>(b); --i)
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int,int>

void maxi(int& a, int b) {
    a = max(a, b);
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);
    
    int n;
    cin >> n;
    vvi grid(201, vi(201));
    FOR(i, 0, n) {
        int x, y, h;
        cin >> x >> y >> h;
        x += 100;
        y += 100;
        FOR(xx, x-h, x+h+1) FOR(yy, y-h, y+h+1) {
            grid[xx][yy] = h - min(abs(x-xx), abs(y-yy));
        }
    }

    FOR(r, 0, 201) {
        FOR(c, 0, 201) cout << grid[r][c];
        cout << '\n';
    }
    cout << '\n';

    int res = 1;
    FOR(x, 0, 201) FOR(y, 0, 201) if (grid[x][y] != 0) {
        FOR(k, 1, 1000) {
            if (x-k < 0 || x+k > 200) break;
            bool succ = true;
            FOR(xx, 0, 2*k+1) {
                FOR(yy, -xx, xx+1) {
                    if (grid[x-k+xx][y-yy] != grid[x][y]) {
                        succ = false;
                        break;
                    }
                }
                if (!succ) break;
            }
            if (succ) maxi(res, k*k + (k+1)*(k+1));
            else break;
        }
    }
    cout << res;
}