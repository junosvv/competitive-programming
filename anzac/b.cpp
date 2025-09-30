#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define ld long double
#define pii pair<int, int>
#define FOR(i, a, b) for (int i=(a); i<(b); ++i)

main() {
    ios::sync_with_stdio(0), cin.tie(0);
	
	ld PX, PY, X1, Y1, X2, Y2;
    cin >> PX >> PY >> X1 >> Y1 >> X2 >> Y2;

    bool inX = (X1 <= PX && PX <= X2);
    bool inY = (Y1 <= PY && PY <= Y2);

    ld ans = 0;
    if (inX) {
        ans = min(abs(PY - Y1), abs(PY - Y2));
    } else if (inY) {
        ans = min(abs(PX - X1), abs(PX - X2));
    } else {
        ld best = -1;
        for (pii point : {pii {X1, Y1}, pii {X1, Y2}, pii {X2, Y1}, pii {X2, Y2}}) {
            ld dist = sqrt((PX - point.first) * (PX - point.first) + (PY - point.second) * (PY - point.second));
            if (best < 0 || dist < best) {
                best = dist;
            }
        }
        ans = best;
    }
    cout << fixed << setprecision(3) << ans << endl;
}