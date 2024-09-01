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
        vvi G(n);
        FOR(i, 1, n) {
            cin >> par[i];
            --par[i];
            G[par[i]].push_back(i);
        }
        vi p(n), pinv(n);
        FOR(i, 0, n) {
            cin >> p[i];
            --p[i];
            pinv[p[i]] = i;
        }

        vi subsz(n, 1), tin(n), tout(n), tour;
        int t = 0;
        function<void(int)> dfs = [&](int u) {
            tin[u] = t++;
            tour.push_back(u);
            for (int v : G[u]) {
                dfs(v);
                subsz[u] += subsz[v];
            }
            tout[u] = t-1;
        };
        dfs(0);

        vi treemin(2*n), treemax(2*n);
        auto upd = [&](int x, int val) {
            x += n;
            treemin[x] = val;
            treemax[x] = val;
            x /= 2;
            while (x) {
                treemin[x] = min(treemin[2*x], treemin[2*x+1]);
                treemax[x] = max(treemax[2*x], treemax[2*x+1]);
                x /= 2;
            }
        };

        auto min_query = [&](int l, int r) {
            int res = 1e6;
            l += n;
            r += n;
            while (l <= r) {
                if (l&1) res = min(res, treemin[l++]);
                if (!(r&1)) res = min(res, treemin[r--]);
                l /= 2;
                r /= 2;
            }
            return res;
        };

        auto max_query = [&](int l, int r) {
            int res = 0;
            l += n;
            r += n;
            while (l <= r) {
                if (l&1) res = max(res, treemax[l++]);
                if (!(r&1)) res = max(res, treemax[r--]);
                l /= 2;
                r /= 2;
            }
            return res;
        };

        FOR(i, 0, n) {
            treemin[n+i] = pinv[tour[i]];
            treemax[n+i] = pinv[tour[i]];
        }
        ROF(i, n-1, 0) {
            treemin[i] = min(treemin[2*i], treemin[2*i+1]);
            treemax[i] = max(treemax[2*i], treemax[2*i+1]);
        }
        
        int tot_good = 0;
        vi good(n);
        auto calc_good = [&](int u) {
            tot_good -= good[u];
            if (G[u].empty()) good[u] = 1;
            else {    
                int mn = min_query(tin[u]+1, tout[u]);
                int mx = max_query(tin[u]+1, tout[u]);
                good[u] = (mn == pinv[u]+1 && mx == pinv[u]+subsz[u]-1);
                // cout << "query " << u << ": " << mn << ' ' << mx << " is ";
                // cout << good[u] << '\n';
            }
            tot_good += good[u];
        };

        FOR(u, 0, n) calc_good(u);

        // for (int i : treemax) cout << i << ' ';
        // cout << '\n';
        FOR(qi, 0, q) {
            int i, j;
            cin >> i >> j;
            --i; --j;
            // cout << "setting " << tin[p[i]] << " to " << j << '\n';
            // cout << "setting " << tin[p[j]] << " to " << i << '\n';
            upd(tin[p[i]], j);
            upd(tin[p[j]], i);
            // for (int i : treemax) cout << i << ' ';
            // cout << '\n';
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