#include <bits/stdc++.h>
using namespace std;

#define int long long
#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define ROF(i, a, b) for (int i=(a); i>(b); --i)
#define vi vector<int>
#define vvi vector<vi>
#define vs vector<string>
#define pii pair<int,int>

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);
    
    int n, m;
    cin >> n >> m;

    vector<vector<pii>> G(n);
    FOR(i, 0, m) {
        int u, v, w;
        cin >> u >> v >> w;
        --u; --v;
        G[u].emplace_back(v, w);
        G[v].emplace_back(u, w);
    }

    int k;
    cin >> k;
    vi g(k);
    FOR(i, 0, k) {
        cin >> g[i];
        --g[i];
    }

    const int INF = 1e9+5;
    vi dist(n, INF);
    priority_queue<pii> pq;
    for (int u : g) {
        pq.emplace(u, 0);
        dist[u] = 0;
    }

    while (!pq.empty()) {
        int u = pq.top().first, du = pq.top().second;
        pq.pop();
        if (du != dist[u]) continue;

        for (pii pr : G[u]) {
            int v = pr.first, w = pr.second;
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.emplace(v, dist[u] + w);
            }
        }
    }
    
    vector<pii> order(n);
    FOR(i, 0, n) {
        order[i] = {-dist[i], i};
    }
    sort(order.begin(), order.end());

    vi par(n), sz(n, 1);
    FOR(i, 0, n) par[i] = i;

    function<int(int)> find = [&](int u) {
        if (u == par[u]) return u;
        return par[u] = find(par[u]);
    };

    vvi T(n);
    for (pii pr : order) {
        int u = pr.second;
        for (pii pr : G[u]) {
            int v = pr.first;
            if (dist[u] <= dist[v]) {
                int uu = find(u), vv = find(v);
                if (uu == vv) continue;

                T[u].push_back(v);
                T[v].push_back(u);
                if (sz[uu] > sz[vv]) swap(uu, vv);
                par[uu] = vv;
                sz[vv] += sz[uu];
            }
        }
    }

    const int K = 20;
    vvi up(K, vi(n)), dp(K, vi(n));
    vi tin(n), tout(n);
    int t = 0;
    function<void(int)> dfs = [&](int u) {
        tin[u] = t++;
        for (int v : T[u]) if (v != up[0][u]) {
            up[0][v] = u;
            dfs(v);
        }
        tout[u] = t++;
    };
    dfs(0);

    auto isanc = [&](int u, int v) {
        return tin[u] <= tin[v] && tout[v] <= tout[u];
    };

    dp[0] = dist;

    FOR(k, 1, K) {
        FOR(u, 0, n) {
            up[k][u] = up[k-1][up[k-1][u]];
            dp[k][u] = min(dp[k-1][u], dp[k-1][up[k-1][u]]);
        }
    }
    
    int q;
    cin >> q;
    FOR(qi, 0, q) {
        int u, v;
        cin >> u >> v;
        --u; --v;

        int res = INF;
        ROF(k, K-1, -1) {
            if (!isanc(up[k][u], v)) {
                res = min(res, dp[k][u]);
                u = up[k][u];
            }
            if (!isanc(up[k][v], u)) {
                res = min(res, dp[k][v]);
                v = up[k][v];
            }
        }
        res = min(res, dist[u]);
        res = min(res, dist[v]);
        if (up[0][u] != v && up[0][v] != u) res = min(res, dist[up[0][u]]);
        cout << res << '\n';
    }
}