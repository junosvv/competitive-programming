#include <bits/stdc++.h>
using namespace std;

#define int long long
#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define ROF(i, a, b) for (int i=(a); i>(b); --i)
#define vi vector<int>
#define vvi vector<vi>
#define vs vector<string>
#define pii pair<int,int>
#define vpii vector<pii>
#define vvpii vector<vpii>
#define mii map<int,int>

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);
    
    auto solve = [&]() {
        int n;
        cin >> n;
        vi l(n), r(n);
        FOR(i, 0, n) cin >> l[i] >> r[i];
        vvi G(n);
        FOR(i, 0, n-1) {
            int u, v;
            cin >> u >> v;
            --u; --v;
            G[u].push_back(v);
            G[v].push_back(u);
        }

        vi ll(n), rr(n), mm(n);
        function<void(int,int)> dfs = [&](int u, int p) {
            vpii segs = {{l[u], r[u]}};
            vi vals;
            ll[u] = l[u];
            rr[u] = r[u];
            for (int v : G[u]) if (v != p) {
                dfs(v, u);
                segs.emplace_back(ll[v], rr[v]);
                vals.push_back(ll[v]);
                vals.push_back(rr[v]);
                mm[u] += mm[v];
            }
            if (vals.empty()) {
                // cout << "Node " << u << " is " << mm[u] << " range " << ll[u] << " to " << rr[u] << '\n';
                return;
            }
            sort(vals.begin(), vals.end());
            int m = vals.size() / 2;
            ll[u] = max(l[u], min(r[u], vals[m-1]));
            rr[u] = max(l[u], min(r[u], vals[m]));
            for (pii pr : segs) {
                int sl = pr.first, sr = pr.second;
                // cout << "proc " << sl << ' ' << sr << '\n';
                if (sr < ll[u]) mm[u] += ll[u] - sr;
                else if (sl > ll[u]) mm[u] += sl - ll[u];
            }

            cout << "Node " << u << " is " << mm[u] << " range " << ll[u] << " to " << rr[u] << '\n';
        };
        dfs(0, 0);

        cout << ll[0] << '\n';
    };

    int T;
    cin >> T;
    FOR(t, 0, T) solve();
}