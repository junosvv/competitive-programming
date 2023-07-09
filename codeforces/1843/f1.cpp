#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define ROF(i, a, b) for (int i=(a); i>(b); --i)
#define vi vector<int>

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);

    const int K = 20;
    
    int T;
    cin >> T;
    FOR(t, 0, T) {
        vi a(1,1), pref(1,1), depth(1), l(1), r(1,1), ll(1), rr(1,1);
        vector<vi> par(1, vi(K));

        auto lcm = [&](int u, int v) {
            if (depth[u] < depth[v]) swap(u, v);
            ROF(j, K-1, -1) {
                if (depth[par[u][j]] >= depth[v]) u = par[u][j];
            }
            assert(depth[u] == depth[v]);
            if (u == v) return u;
            ROF(j, K-1, -1) {
                if (par[u][j] != par[v][j]) {
                    u = par[u][j];
                    v = par[v][j];
                    assert(depth[u] == depth[v]);
                }
            }
            return par[u][0];
        };

        int n;
        cin >> n;
        // cout << "vertex " << l.size()-1 << ": " << l.back() << ' ' << r.back() << ' ' << ll.back() << ' ' << rr.back() << '\n';
        FOR(i, 0, n) {
            char c;
            cin >> c;
            if (c == '+') {
                int u, x;
                cin >> u >> x;
                --u;
                par.push_back(vi(K));
                par.back()[0] = u;
                FOR(j, 1, K) par.back()[j] = par[par.back()[j-1]][j-1];
                a.push_back(x);
                pref.push_back(a[u]+x);
                depth.push_back(depth[u]+1);
                l.push_back(min(0LL, l[u]+x));
                r.push_back(max(0LL, r[u]+x));
                ll.push_back(min(l.back(), ll[u]));
                rr.push_back(max(r.back(), rr[u]));
                // cout << "vertex " << l.size()-1 << ": " << l.back() << ' ' << r.back() << ' ' << ll.back() << ' ' << rr.back() << '\n';
            } else {
                int u, v, k;
                cin >> u >> v >> k;
                --u; --v;
                if (ll[v] <= k && k <= rr[v]) cout << "YES\n";
                else cout << "NO\n";
            }
        }
    }
}