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
    vvi G(n);
    FOR(i, 0, n-1) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    
    vi tree(2*n);
    auto upd = [&](int x, int val) {
        x += n;
        tree[x] = val;
        x /= 2;
        while (x) {
            tree[x] = tree[2*x] + tree[2*x+1];
            x /= 2;
        };
    };

    auto query = [&](int l, int r) {
        l += n;
        r += n;
        int res = 0;
        while (l <= r) {
            if (l&1) res += tree[l++];
            if (!(r&1)) res += tree[r--];
            l /= 2;
            r /= 2;
        }
        return res;
    };

    vi subsz(n, 1), ltme(n), ltpar(n);
    function<void(int, int)> dfs = [&](int u, int p) {
        ltme[u] -= query(0, u-1);
        if (p != -1) ltpar[u] -= query(0, p-1);
        upd(u, 1);
        for (int v : G[u]) if (v != p) {
            dfs(v, u);
            subsz[u] += subsz[v];
        }
        ltme[u] += query(0, u-1);
        if (p != -1) ltpar[u] += query(0, p-1);
    };
    dfs(0, -1);

    vi below(n);
    dfs = [&](int u, int p) {
        below[u] = ltme[u];
        for (int v : G[u]) if (v != p) {
            dfs(v, u);
            below[u] += below[v];
        }
    };
    dfs(0, -1);

    vi above(n);
    dfs = [&](int u, int p) {
        for (int v : G[u]) if (v != p) {
            above[v] += v - ltme[v] + above[u] + below[u] - below[v] - ltpar[v];
            dfs(v, u);
        }
    };
    dfs(0, -1);

    // FOR(u, 0, n) cout << below[u] << ' ';
    // cout << '\n';
    // FOR(u, 0, n) cout << above[u] << ' ';
    // cout << '\n';
    FOR(u, 0, n) cout << above[u] + below[u] << ' ';
}