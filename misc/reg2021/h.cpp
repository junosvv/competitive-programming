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
    
    int n;
    cin >> n;
    vector<string> imgs(n, string(25, ' '));
    FOR(i, 0, n) FOR(c, 0, 25) cin >> imgs[i][c];

    auto subs = [&](int u, int v) {
        FOR(c, 0, 25) if (imgs[u][c] == '#' && imgs[v][c] == '.') return false;
        return imgs[u] != imgs[v] || u < v;
    };

    int m = 2*n+2;
    int source = m-2, sink = m-1;
    vvi capac(m, vi(m));
    FOR(i, 0, n) {
        capac[source][i] = 1;
        capac[n+i][sink] = 1;
    }
    FOR(i, 0, n) FOR(j, 0, n) if (i != j && subs(i, j)){ 
        capac[i][n+j] = 1;
    }
    
    FOR(flow, 0, n+1) {
        vi par(m, -1);
        function<bool(int)> dfs = [&](int u) {
            if (u == sink) return true;
            FOR(v, 0, m) if (par[v] == -1 && capac[u][v]) {
                par[v] = u;
                if (dfs(v)) return true;
            }
            return false;
        };
        par[source] = -2;
        if (!dfs(source)) {
            cout << n-flow;
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