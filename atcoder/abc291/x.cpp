#include <bits/stdc++.h>
using namespace std;

#define int long long
#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define ROF(i, a, b) for (int i=(a); i>(b); --i)
#define vi vector<int>
#define vvi vector<vi>

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);
    
    int n;
    cin >> n;
    vvi G(n);
    FOR(i, 0, n-1) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    vi sz(n), par(n), erased(n);
    function<int(int,int,int)> dfs = [&](int u, int p, int totsz) {
        par[u] = p;
        sz[u] = 1;
        int centroid = -1;
        bool succ = true;
        for (int v : G[u]) if (!erased[v] && v != p) {
            centroid = max(centroid, dfs(v, u, totsz));
            sz[u] += sz[v];
            if (sz[v] > totsz/2) succ = false;
        }
        if (totsz - sz[u] > totsz/2) succ = false;
        if (succ) centroid = max(centroid, u);
        return centroid;
    };

    vi res(n);
    function<void(int,int,int)> dfs2 = [&](int u, int p, int totsz) {
        // cout << "dfs " << u << ' ' << totsz << '\n';
        int centroid = dfs(u, -1, totsz);
        assert(centroid != -1);
        // cout << "connecting " << centroid << " to " << p+1 << '\n';
        if (p == -1) res[centroid] = -1;
        else res[centroid] = p+1;
        erased[centroid] = true;

        for (int v : G[centroid]) if (!erased[v]) {
            dfs2(v, centroid, (v==par[centroid] ? totsz-sz[centroid] : sz[v]));
        }
    };

    dfs2(0, -1, n);
    FOR(i, 0, n) cout << res[i] << ' ';
}