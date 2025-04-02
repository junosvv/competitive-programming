#include <bits/stdc++.h>
using namespace std;

#define int long long
#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define ROF(i, a, b) for (int i=(a); i>(b); --i)
#define vi vector<int>
#define vvi vector<vi>

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);
    
    int n, m, k;
    cin >> n >> m >> k;

    vvi G(n);
    FOR(i, 0, m) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        G[u].push_back(v);
    }

    vvi res;
    vi seen(n), stack;
    function<bool(int)> dfs = [&](int u) {
        seen[u] = true;
        stack.push_back(u);
        if (u == n-1) return true;
        for (int v : G[u]) if (!seen[v]) {
            if (dfs(v)) return true;
        }
        stack.pop_back();
        return false;
    };

    set<vi> setres;
    auto upd = [&]() {
        if (!setres.count(stack)) {
            res.push_back(stack);
            setres.insert(stack);
            if (res.size() >= k) {
                FOR(i, 0, k) {
                    cout << res[i].size() << ' ';
                    for (int j : res[i]) cout << j+1 << ' ';
                    cout << '\n';
                }
                exit(0);
            }
        }
    };

    if (dfs(0)) upd();
    int i = 0;
    while (i < res.size()) {
        int len = res[i].size();
        FOR(l, 1, len) {
            for (int v : G[res[i][l-1]]) if (v != res[i][l]) {
                bool fail = false;
                FOR(u, 0, l) if (res[i][u] == v) {
                    fail = true;
                    break;
                }
                if (fail) continue;
                seen.assign(n, false);
                stack.clear();
                FOR(u, 0, l) {
                    stack.push_back(res[i][u]);
                    seen[res[i][u]] = true;
                }
                if (dfs(v)) upd();
            }
        }
        ++i;
    }
    cout << "Stay at home";
}