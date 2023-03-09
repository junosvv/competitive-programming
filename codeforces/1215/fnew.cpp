#include <bits/stdc++.h>
using namespace std;

#define int long long
#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define ROF(i, a, b) for (int i=(a); i>(b); --i)
#define vi vector<int>
#define vvi vector<vi>

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int n, p, M, m;
    cin >> n >> p >> M >> m;

    int N = 2*(p+M);
    vector<vi> nodes(N), nodesinv(N);
    FOR(i, 1, M) {
        nodes[p+i].push_back(p+i-1);
        nodes[p+M+p+i-1].push_back(p+M+p+i);
    }
    FOR(i, 0, n) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        nodes[p+M+u].push_back(v);
        nodes[p+M+v].push_back(u);
    }
    FOR(i, 0, p) {
        int l, r;
        cin >> l >> r;
        --l; --r;
        nodes[i].push_back(p+l);
        nodes[p+M+p+l].push_back(p+M+i);
        if (r < M-1) {
            nodes[p+r+1].push_back(p+M+i);
            nodes[i].push_back(p+M+p+r+1);
        }
    }
    FOR(i, 0, m) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        nodes[u].push_back(p+M+v);
        nodes[v].push_back(p+M+u);
    }

    FOR(u, 0, N) for (int v : nodes[u]) {
        nodesinv[v].push_back(u);
    }

    vi comp(N), tout;
    function<void(int)> dfs = [&](int u) {
        comp[u] = true;
        for (int v : nodes[u]) if (!comp[v]) {
            dfs(v);
        }
        tout.push_back(u);
    };

    FOR(u, 0, N) if (!comp[u]) {
        dfs(u);
    }

    comp.assign(N, -1);
    function<void(int, int)> dfs2 = [&](int u, int c) {
        comp[u] = c;
        for (int v : nodesinv[u]) if (comp[v] == -1) {
            dfs2(v, c);
        }
    };

    int curcomp = 0;
    ROF(u, N-1, -1) {
        if (comp[tout[u]] == -1) {
            dfs2(tout[u], curcomp);
            ++curcomp;
        }
    }

    vi res;
    int freq = 0;
    FOR(u, 0, p+M) {
        if (comp[u] == comp[p+M+u]) {
            cout << -1;
            exit(0);
        }
        if (comp[u] > comp[p+M+u]) {
            if (u < p) res.push_back(u);
            if (u >= p) freq = max(freq, u-p);
        }
    }
    
    cout << res.size() << ' ' << freq+1 << '\n';
    for (int i : res) cout << i+1 << ' ';
}