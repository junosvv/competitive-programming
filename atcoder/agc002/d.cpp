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
    
    int n, m;
    cin >> n >> m;
    vector<pii> edges(m+1);
    FOR(i, 1, m+1) cin >> edges[i].first >> edges[i].second;
    int Q;
    cin >> Q;
    vi res(Q), x(Q), y(Q), z(Q);
    FOR(i, 0, Q) cin >> x[i] >> y[i] >> z[i];

    vi par(n+1), sz;
    function<int(int)> find = [&](int u) {
        if (par[u] == u) return u;
        return par[u] = find(par[u]);
    };

    struct tup {
        int l, r;
        vi queries;
    };

    queue<tup> q;
    vi init(Q);
    FOR(i, 0, Q) init[i] = i;
    q.push({1, m, init});
    int cur = 1e6;
    while (!q.empty()) {
        int l = q.front().l, r = q.front().r;
        vi queries = q.front().queries;
        q.pop();

        if (l == r) {
            for (int k : queries) res[k] = l;
            continue;
        }

        int mid = (l+r)/2;
        if (cur > mid) {
            FOR(u, 1, n+1) par[u] = u;
            sz.assign(n+1, 1);
            cur = 0;
        }
        while (cur < mid) {
            ++cur;
            int u = edges[cur].first, v = edges[cur].second;
            u = find(u); v = find(v);
            if (u == v) continue;
            if (sz[u] > sz[v]) swap(u, v);
            par[u] = v;
            sz[v] += sz[u];
        }

        vi succs, fails;
        for (int k : queries) {
            int xx = find(x[k]), yy = find(y[k]);
            if (sz[xx] >= z[k] || xx != yy && sz[xx] + sz[yy] >= z[k]) {
                succs.push_back(k);
            } else {
                fails.push_back(k);
            }
        }

        q.push({l, mid, succs});
        q.push({mid+1, r, fails});
    }

    for (int i : res) cout << i << ' ';
}