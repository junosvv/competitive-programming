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
#define t3i tuple<int,int,int>
#define mii map<int,int>

// #include <chrono>
// using namespace chrono;

struct Info {
    int w = -1, k = -1, u = -1;
};
#define pII pair<Info,Info>

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);

    auto solve = [&]() {
        int n;
        cin >> n;
        vi w(n);
        vvi G(n), locs(n+1);
        FOR(i, 0, n) {
            cin >> w[i];
            locs[w[i]].push_back(i);
        }
        FOR(i, 0, n-1) {
            int u, v;
            cin >> u >> v;
            --u; --v;
            G[u].push_back(v);
            G[v].push_back(u);
        }

        // auto start = high_resolution_clock::now();
        // int n = 400000;
        // vi w(n);
        // vvi locs(n+1);
        // FOR(i, 0, n) {
        //     w[i] = rand()%7 + 1;
        //     locs[w[i]].push_back(i);
        // }
        // vvi G(n);
        // FOR(u, 1, n) {
        //     int v = rand() % u;
        //     G[u].push_back(v);
        //     G[v].push_back(u);
        // }
        
        const int K = 21;
        vi dep(n, -1), tin(n), tout(n);
        vvi up(K, vi(n, -1)), dp = up;
        int t = 0;
        function<void(int)> dfs = [&](int u) {
            tin[u] = t++;
            for (int v : G[u]) if (dep[v] == -1) {
                dep[v] = 1 + dep[u];
                up[0][v] = u;
                dfs(v);
            }
            tout[u] = t;
        };
        dep[0] = 0;
        up[0][0] = 0;
        dfs(0);

        FOR(u, 0, n) dp[0][u] = w[u];
        FOR(k, 1, K) FOR(u, 0, n) {
            up[k][u] = up[k-1][up[k-1][u]];
            dp[k][u] = max(dp[k-1][u], dp[k-1][up[k-1][u]]);
        }

        vi sp(n);
        FOR(u, 0, n) {
            sp[u] = u;
            ROF(k, K-1, -1) if (dp[k][sp[u]] <= w[u]) {
                sp[u] = up[k][sp[u]];
            }
            if (w[sp[u]] <= w[u]) sp[u] = -1;
        }


        vi tree_a(2*n), tree_p(2*n);
        auto upd = [&](vi& tree, int x, int val) {
            x += n;
            tree[x] = val;
            x /= 2;
            while (x) {
                tree[x] = tree[2*x] + tree[2*x+1];
                x /= 2;
            }
        };
        auto query = [&](vi& tree, int l, int r) {
            l += n;
            r += n;
            int res = 0;
            while (l < r) {
                if (l&1) res += tree[l++];
                if (r&1) res += tree[--r];
                l /= 2;
                r /= 2;
            }
            return res;
        };

        vi tree_d(2*n);
        auto upd_d = [&](int l, int r, int delta) {
            l += n;
            r += n;
            while (l < r) {
                if (l&1) tree_d[l++] += delta;
                if (r&1) tree_d[--r] += delta;
                l /= 2;
                r /= 2;
            }
        };
        auto query_d = [&](int x) {
            x += n;
            int res = 0;
            while (x) {
                res += tree_d[x];
                x /= 2;
            }
            return res;
        };

        vector<pII> tree_i(2*n);
        auto merge = [&](pII a, pII b) {
            pII c;
            if (a.first.w == b.first.w) {
                c.first.w = a.first.w;
                c.first.k = a.first.k + b.first.k;
                c.first.u = dep[a.first.u] >= dep[b.first.u] ? a.first.u : b.first.u;
                if (a.second.w > b.second.w) c.second = a.second;
                else if (a.second.w < b.second.w) c.second = b.second;
                else {
                    c.second.w = a.second.w;
                    c.second.k = a.second.k + b.second.k;
                    c.second.u = dep[a.second.u] >= dep[b.second.u] ? a.second.u : b.second.u;
                }
            } else {
                if (a.first.w < b.first.w) swap(a, b);
                c.first = a.first;
                if (a.second.w > b.first.w) c.second = a.second;
                else if (a.second.w < b.first.w) c.second = b.first;
                else {
                    c.second.w = a.second.w;
                    c.second.k = a.second.k + b.first.k;
                    c.second.u = dep[a.second.u] >= dep[b.first.u] ? a.second.u : b.first.u;
                }
            }

            return c;
        };
        auto upd_i = [&](int x, pII val) {
            x += n;
            tree_i[x] = val;
            x /= 2;
            while (x) {
                tree_i[x] = merge(tree_i[2*x], tree_i[2*x+1]);
                x /= 2;
            }
        };
        auto query_i = [&](int l, int r) {
            l += n;
            r += n;
            pII res;
            while (l < r) {
                if (l&1) res = merge(res, tree_i[l++]);
                if (r&1) res = merge(res, tree_i[--r]);
                l /= 2;
                r /= 2;
            }
            return res;
        };


        vi active(n), res;
        vvi unp(n+1);
        ROF(cur_w, n, 0) {
            for (int u : locs[cur_w]) {
                pII infos = merge(query_i(0, tin[u]), query_i(tout[u], n));
                if (infos.first.w == -1) continue; // empty
                if (infos.second.w == -1) {
                    res.push_back(u+1); // all same
                    continue;
                }
                if (query(tree_p, 0, tin[u]) + query(tree_p, tout[u], n)) continue; // poisoned vertex

                int x = infos.second.u;
                pII x_infos = merge(query_i(tin[x], min(tin[u], tout[x])), query_i(max(tin[x], tout[u]), tout[x]));

                if (x_infos.first.w == infos.first.w && x_infos.first.k + query_d(tin[x]) == query(tree_a, 0, tin[u]) + query(tree_a, tout[u], n)) {
                    assert(x_infos.second.w == w[x]);
                    assert(x_infos.second.k == 1);
                    assert(x_infos.second.u == x);
                    res.push_back(u+1);
                }
            }

            for (int u : locs[cur_w]) {
                active[u] = true;
                upd(tree_a, tin[u], 1);
                upd_d(tin[u], tout[u], 1);
                pII infos;
                infos.first.w = w[u];
                infos.first.k = 1;
                infos.first.u = u;
                upd_i(tin[u], infos);
                if (sp[u] != -1) {
                    upd(tree_p, tin[u], 1);
                    int dist = dep[u] - dep[sp[u]] - 1, v = up[0][u], mx = -1;
                    FOR(k, 0, K) if (dist>>k&1) {
                        mx = max(mx, dp[k][v]);
                        v = up[k][v];
                    }
                    if (mx != -1) {
                        unp[mx].push_back(u);
                    }
                }
            }

            for (int u : unp[cur_w]) {
                upd(tree_p, tin[u], 0);
            }
        }

        cout << res.size() << ' ';
        sort(res.begin(), res.end());
        for (int i : res) cout << i << ' ';
        cout << '\n';
        
        // cout << duration_cast<milliseconds>(high_resolution_clock::now() - start).count() << endl;
    };

    int T;
    cin >> T;
    FOR(t, 0, T) solve();
}