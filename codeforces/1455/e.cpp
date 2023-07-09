#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define vi vector<int>

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int T;
    cin >> T;
    FOR(t, 0, T) {
        vi x(4), y(4);
        FOR(i, 0, 4) cin >> x[i] >> y[i];
        vi perm = {0, 1, 2, 3};
        int res = 1e10;
        do {
            vi l = {x[perm[0]], x[perm[1]]}, r = {x[perm[2]], x[perm[3]]};
            FOR(i, 0, 2) if (l[i] > r[i]) swap(l[i], r[i]);
            vi d = {y[perm[0]], y[perm[2]]}, u = {y[perm[1]], y[perm[3]]};
            FOR(i, 0, 2) if (d[i] > u[i]) swap(d[i], u[i]);
            int s = max(0LL, max(l[1]-r[0], d[1]-u[0]));
            vi vert = {min(r[0], r[1]-s), s}, horiz = {min(u[0], u[1]-s), s};
            vert[1] += vert[0]; horiz[1] += horiz[0];
            int cur = 0;
            FOR(i, 0, 2) cur += abs(l[i]-vert[i]) + abs(r[i]-vert[i]) + abs(d[i]-horiz[i]) + abs(u[i]-horiz[i]);
            // if (cur == 11) {
            //     cout << "HERE\n";
            //     cout << l[0] << ' ' << r[0] << " and " << l[1] << ' ' << r[1] << '\n';
            //     cout << d[0] << ' ' << u[0] << " and " << d[1] << ' ' << u[1] << '\n';
            //     cout << "at (" << vert[0] << ", " << horiz[0] << "), s=" << s << '\n';
            //     // exit(0);
            // }
            res = min(res, cur);
        } while (next_permutation(perm.begin(), perm.end()));

        cout << res << '\n';
    }
}