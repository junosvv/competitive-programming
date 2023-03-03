#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define ROF(i, a, b) for (int i=(a); i>(b); --i)
#define vi vector<int>
#define pii pair<int,int>

vector<vi> nodes;
vi par;
void dfs(int c, int u) {
    par[u] = c;
    for (int v : nodes[u]) if (par[v] == -1) {
        dfs(c, v);
    }
}

bool fail = false;
void dfs2(int u) {
    for (int v : nodes[u]) {
        if (par[v] == par[u]) fail = true;
        else if (par[v] == -1) {
            par[v] = !par[u];
            dfs2(v);
        }
    }
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);

    freopen("revegetate.in", "r", stdin);
    freopen("revegetate.out", "w", stdout);
    
    int n, m;
    cin >> n >> m;
    vector<pii> same, diff;
    FOR(i, 0, m) {
        char x;
        cin >> x;
        int u, v;
        cin >> u >> v;
        --u; --v;

        if (x == 'S') same.emplace_back(u, v);
        else diff.emplace_back(u, v);
    }

    nodes.assign(n, {});
    for (pii pr : same) {
        nodes[pr.first].push_back(pr.second);
        nodes[pr.second].push_back(pr.first);
    }

    par.assign(n, -1);
    int sn = 0;
    vi compid(n);
    FOR(u, 0, n) if (par[u] == -1) {
        compid[u] = sn++;
        dfs(u, u);
    }

    nodes.assign(sn, {});
    for (pii pr : diff) {
        nodes[compid[par[pr.first]]].push_back(compid[par[pr.second]]);
        nodes[compid[par[pr.second]]].push_back(compid[par[pr.first]]);
    }

    int comps = 0;
    par.assign(sn, -1);
    FOR(u, 0, sn) if (par[u] == -1) {
        ++comps;
        par[u] = 0;
        dfs2(u);
    }

    if (fail) cout << 0;
    else {
        cout << 1;
        FOR(i, 0, comps) cout << 0;
    }
}