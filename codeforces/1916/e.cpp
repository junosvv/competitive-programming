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
        int n;
        cin >> n;
        vi par(n), a(n);
        vvi G(n);
        FOR(i, 1, n) {
            cin >> par[i];
            --par[i];
            G[par[i]].push_back(i);
        }
        FOR(i, 0, n) {
            cin >> a[i];
            --a[i];
        }

        int t = -1;
        vi tin(n), tout(n);
        vvi col(n), desc(n);
        function<void(int)> dfs = [&](int u) {
            if (!col[a[u]].empty()) desc[col[a[u]].back()].push_back(u);
            col[a[u]].push_back(u);
            tin[u] = ++t;
            for (int v : G[u]) {
                dfs(v);
            }
            tout[u] = t;
            col[a[u]].pop_back();
        };
        dfs(0);
        
        vi tree(2*n), lazy(n);
        auto apply = [&](int x, int delta) {
            tree[x] += delta;
            if (x < n) lazy[x] += delta;
        };

        auto build = [&](int x) {
            x /= 2;
            while (x) {
                tree[x] = max(tree[2*x], tree[2*x+1]) + lazy[x];
                x /= 2;
            }
        };

        auto upd = [&](int l, int r, int delta) {
            l += n;
            r += n;
            int l0 = l, r0 = r;
            while (l <= r) {
                if (l&1) apply(l++, delta);
                if (!(r&1)) apply(r--, delta);
                l /= 2;
                r /= 2;
            }
            build(l0);
            build(r0);
        };

        auto push = [&](int x) {
            ROF(d, 20, 0) {
                int u = x >> d;
                if (!u) continue;
                apply(2*u, lazy[u]);
                apply(2*u+1, lazy[u]);
                lazy[u] = 0;
            }
        };

        auto query = [&](int l, int r) {
            l += n;
            r += n;
            push(l);
            push(r);
            int res = 0;
            while (l <= r) {
                if (l&1) res = max(res, tree[l++]);
                if (!(r&1)) res = max(res, tree[r--]);
                l /= 2;
                r /= 2;
            }
            return res;
        };

        int res = 1;
        function<void(int)> dfs2 = [&](int u) {
            for (int v : G[u]) {
                dfs2(v);
            }
            upd(tin[u], tout[u], 1);
            for (int v : desc[u]) {
                upd(tin[v], tout[v], -1);
            }
            vi depths;
            for (int v : G[u]) {
                depths.push_back(query(tin[v], tout[v]));
            }
            sort(depths.rbegin(), depths.rend());

            if (depths.size() == 1) res = max(res, depths[0]);
            else if (depths.size() >= 2) res = max(res, depths[0]*depths[1]);
        };
        dfs2(0);
        cout << res << '\n';
    };

    int T;
    cin >> T;
    FOR(t, 0, T) solve();
}