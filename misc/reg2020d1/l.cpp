#include <bits/stdc++.h>
using namespace std;

#define int long long
#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define ROF(i, a, b) for (int i=(a); i>(b); --i)
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int,int>
#define SQ(x) (x)*(x)

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    if (n == 1 && m == 0) {
        cout << 0;
        exit(0);
    }
    vvi G(n);
    FOR(i, 0, m) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        G[u].push_back(v);
    }

    vi seen;
    function<void(int)> dfs = [&](int u) {
        seen[u] = true;
        for (int v : G[u]) if (!seen[v]) {
            dfs(v);
        }
    };

    int source = 2*n, sink = 2*n+1, gsize = 2*n+2;
    vvi capac(gsize, vi(gsize));
    FOR(u, 0, n) {
        capac[source][u] = 1;
        capac[n+u][sink] = 1;
        seen.assign(n, false);
        dfs(u);
        FOR(v, u+1, n) if (seen[v]) {
            capac[u][n+v] = 1;
        }
    }

    vi par;
    function<bool(int)> dfs2 = [&](int u) {
        if (u == sink) return true;
        FOR(v, 0, gsize) if (capac[u][v] && par[v] == -1) {
            par[v] = u;
            if (dfs2(v)) return true;
        }
        return false;
    };

    FOR(flow, 0, n+2) {
        par.assign(gsize, -1);
        par[source] = -2;
        if (!dfs2(source)) {
            cout << "flow: " << n-flow << '\n';
            vi got(n);
            FOR(u, 0, n) {
                got[u] = u;
                FOR(v, 0, n) if (capac[n+v][u]) got[u] = v;
            }
            FOR(u, 0, n) if (got[u] != -1) {
                int v = u;
                while (true) {
                    cout << v+1 << ' ';
                    int w = got[v];
                    got[v] = -1;
                    if (v == w) break;
                    v = w;
                }
                cout << '\n';
            }
            break;
        }
        int v = sink;
        while (v != source) {
            int u = par[v];
            --capac[u][v];
            ++capac[v][u];
            v = u;
        }
    }
}