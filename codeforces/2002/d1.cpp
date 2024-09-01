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

    auto solve = [&]() {
        int n, q;
        cin >> n >> q;
        vi par(n);
        FOR(i, 1, n) {
            cin >> par[i];
            --par[i];
        }
        vi p(n), pinv(n);
        FOR(i, 0, n) {
            cin >> p[i];
            --p[i];
            pinv[p[i]] = i;
        }
        vi depth(n);
        FOR(u, 1, n) depth[u] = depth[par[u]] + 1;
        vi p2(62, 1);
        FOR(i, 1, 62) p2[i] = p2[i-1] * 2LL;
        
        int tot_good = 0;
        vi good(n);
        auto calc_good = [&](int u) {
            tot_good -= good[u];
            if (u >= n/2) {
                good[u] = 1;
            } else {
                vi b = {pinv[2*u+1]-pinv[u], pinv[2*u+2]-pinv[u]};
                sort(b.begin(), b.end());
                good[u] = b[0] == 1 && b[1] == p2[depth[n-1]-depth[u]];
            }
            tot_good += good[u];
            // cout << u << " is good: " << good[u] << '\n';
        };

        FOR(u, 0, n) calc_good(u);

        FOR(qi, 0, q) {
            int i, j;
            cin >> i >> j;
            --i; --j;
            swap(p[i], p[j]);
            swap(pinv[p[i]], pinv[p[j]]);
            calc_good(p[i]);
            calc_good(p[j]);
            calc_good(par[p[i]]);
            calc_good(par[p[j]]);
            // for (int i : pinv) cout << i << ' ';
            // cout << '\n';
            cout << (tot_good == n ? "YES" : "NO") << '\n';
        }
    };

    int T;
    cin >> T;
    FOR(t, 0, T) solve();
}