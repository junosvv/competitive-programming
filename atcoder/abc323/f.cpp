#include <bits/stdc++.h>
using namespace std;

#define int long long
#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define ROF(i, a, b) for (int i=(a); i>(b); --i)
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int,int>

signed main() {
    int xa, ya, xb, yb, xc, yc;
    cin >> xa >> ya >> xb >> yb >> xc >> yc;

    auto solve = [&](int xa, int ya, int xb, int yb) {
        cout << abs(xa-xb) + abs(ya-yb) << '\n';
        return abs(xa-xb) + abs(ya-yb);
    };

    int res = 1e18;
    int yy = yb < yc ? yb-1 : yb+1;
    res = min(res, solve(xa, ya, xb, yy) + (xa == xb && (ya < yb && yb < yy || ya < yc && yc < yy || )) + abs(yb - yc) + (xb == xc ? 0 : 2 + abs(xb-xc)));
    cout << res << '\n';
    res = min(res, solve(xa, ya, (xb < xc ? xb-1 : xb+1), yb) + abs(xb - xc) + (yb == yc ? 0 : 2 + abs(yb-yc)));
    cout << res;
}