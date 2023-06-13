#include <bits/stdc++.h>
using namespace std;

#define int long long
#define FOR(i, a, b) for (int i=(a); i<(b); ++(i))
#define vi vector<int>

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int n;
    cin >> n;
    vi a(n), b(n);
    FOR(i, 0, n) {
        cin >> a[i] >> b[i];
        --a[i]; --b[i];
    }
    vector<vi> g(n);
    FOR(i, 0, n-1) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    vi mainseen(n), res(n);
    vi seen(n), tree(n, 1), par(n), rank(n);
    FOR(i, 0, n) par[i] = i;

    function<int(int)> find = [&](int u) {
        while (par[u] != u) {
            u = par[u];
        }
        return u;
    };

    int ans = 0;
    function<void(int)> dfs = [&](int u) {
        mainseen[u] = 1;

        int ans0 = ans, seenau0 = seen[a[u]], seenbu0 = seen[b[u]], treeaa0, treebb0, rankbb0;

        seen[a[u]] = 1;
        seen[b[u]] = 1;

        int aa = find(a[u]), bb = find(b[u]);
        if (aa == bb) {
            treeaa0 = tree[aa];
            treebb0 = tree[bb];
            rankbb0 = rank[bb];
            if (tree[aa]) ++ans;
            tree[aa] = 0;
        } else {
            if (rank[aa] > rank[bb]) swap(aa, bb);
            treeaa0 = tree[aa];
            treebb0 = tree[bb];
            rankbb0 = rank[bb];
            par[aa] = bb;
            if (rank[aa] == rank[bb]) ++rank[bb];
            if (tree[aa] || tree[bb]) ++ans;
            if (!tree[aa]) tree[bb] = 0;
        }

        res[u] = ans;

        for (int v : g[u]) if (!mainseen[v]) {
            dfs(v);
        }

        ans = ans0;
        seen[a[u]] = seenau0;
        seen[b[u]] = seenbu0;
        tree[aa] = treeaa0;
        tree[bb] = treebb0;
        par[aa] = aa;
        par[bb] = bb;
        rank[bb] = rankbb0;
    };

    dfs(0);

    FOR(i, 1, n) cout << res[i] << ' ';
}