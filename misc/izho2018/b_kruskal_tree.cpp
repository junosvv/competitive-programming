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

    vi par(n), sz(n, 1), right(n);
    FOR(i, 0, n) {
        par[i] = i;
        right[i] = i;
    }

    function<int(int)> find = [&](int u) {
        if (u == par[u]) return u;
        return par[u] = find(par[u]);
    };

    vvi T(n);
    vi tw(n);
    for (pii pr : order) {
        int u = pr.second;
        for (pii pr : G[u]) {
            int v = pr.first;
            if (dist[u] <= dist[v]) {
                int uu = find(u), vv = find(v);
                if (uu == vv) continue;
                if (sz[uu] > sz[vv]) swap(uu, vv);

                T[right[vv]].push_back(uu);
                T[uu].push_back(right[vv]);
                tw[right[vv]] = dist[u];
                par[uu] = vv;
                sz[vv] += sz[uu];
                right[vv] = right[uu];
            }
        }
    }

    vi loc(n, -1);
    const int K = 20;
    vvi st(K, vi(n));
    int t = 0;
    function<void(int)> dfs = [&](int u) {
        st[0][t] = tw[u];
        loc[u] = t++;
        for (int v : T[u]) if (loc[v] == -1) {
            dfs(v);
        }
    };
    dfs(find(0));

    FOR(k, 1, K) {
        FOR(u, 0, n-(1<<k-1)) {
            st[k][u] = min(st[k-1][u], st[k-1][u+(1<<k-1)]);
        }
    }

    vi lg(n);
    FOR(i, 2, n) lg[i] = lg[i/2] + 1;

    int q;
    cin >> q;
    FOR(qi, 0, q) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        if (loc[u] > loc[v]) swap(u, v);

        int k = lg[loc[v]-loc[u]];
        cout << min(st[k][loc[u]], st[k][loc[v] - (1<<k)]) << '\n';
    }
}