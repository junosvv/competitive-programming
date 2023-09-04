#include <bits/stdc++.h>
using namespace std;

#define int long long
#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define ROF(i, a, b) for (int i=(a); i>(b); --i)
#define vi vector<int>
#define vvi vector<vi>

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);
    
    int n, m, a, b, c;
    cin >> n >> m >> a >> b >> c;
    --a; --b; --c;

    vvi G(n);
    FOR(i, 0, m) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    
    int t = 0;
    vi tin(n, -1), low(n), artic(n);
    function<void(int,int)> dfs = [&](int u, int p) {
        tin[u] = t++;
        low[u] = tin[u];
        int children = 0;
        for (int v : G[u]) if (v != p) {
            if (tin[v] != -1) {
                low[u] = min(low[u], tin[v]);
            } else {
                dfs(v, u);
                low[u] = min(low[u], low[v]);
                // cout << "at " << u+1 << " with " << tin[u] << ", " << v+1 << " has low of " << low[v] << '\n';
                if (low[v] >= tin[u] && p != -1) artic[u] = 1;
                ++children;
            }
        }
        if (p==-1 && children > 1) {
            artic[u] = 1;
        }
    };
    
    dfs(0, -1);

    int cc = 0;
    vi comp(n, -1);
    function<void(int)> dfs2 = [&](int u) {
        // cout << "set " << u << " to " << cc << '\n';
        comp[u] = cc;
        for (int v : G[u]) if (!artic[v] && comp[v] == -1) {
            dfs2(v);
        }
    };
    FOR(u, 0, n) if (artic[u]) {
        comp[u] = cc++;
        // cout << "dfs from " << u+1 << '\n';
        for (int v : G[u]) if (!artic[v] && comp[v] == -1) {
            dfs2(v);
            ++cc;
        }
    }

    // cout << "components! ";
    // FOR(i, 0, n) cout << comp[i] << ' ';
    // cout << "cc: " << cc << '\n';

    vvi newG(cc);
    FOR(u, 0, n) {
        for (int v : G[u]) {
            newG[comp[u]].push_back(comp[v]);
            newG[comp[v]].push_back(comp[u]);
        }
    }

    vi seen(cc+5);
    vi onpath(cc+5);
    function<bool(int)> dfs3 = [&](int u) {
        // cout << "seeing " << u << '\n';
        seen[u] = 1;
        onpath[u] = 1;
        if (u == comp[c]) return true;
        for (int v : newG[u]) if (!seen[v]) {
            if (dfs3(v)) return true;
        }
        onpath[u] = 0;
        return false;
    };

    dfs3(comp[a]);
    // FOR(i, 0, cc) if (seen[i]) cout << i << ' ';
    // cout << '\n';
    cout << (onpath[comp[b]] ? "Yes" : "No");
}