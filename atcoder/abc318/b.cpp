#include <bits/stdc++.h>
using namespace std;

#define int long long
#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define ROF(i, a, b) for (int i=(a); i>(b); --i)
#define vi vector<int>
#define vvi vector<vi>

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);
    
    int n;
    cin >> n;
    const int BIG = 100;
    vvi grid(BIG, vi(BIG));
    FOR(i, 0, n) {
        int x1, x2, y1, y2;
        cin >> x1 >> x2 >> y1 >> y2;
        FOR(x, x1, x2) FOR(y, y1, y2) grid[x][y] = 1;
    }
    int res = 0;
    FOR(x, 0, 100) FOR(y, 0, 100) if (grid[x][y]) ++res;
    cout << res;
}