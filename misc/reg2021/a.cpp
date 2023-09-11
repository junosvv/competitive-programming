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

    vi seen2(n);
    function<bool(int)> dfs2 = [&](int u) {
        if (u == n-1) return true;
        seen2[u] = true;
        for (int v : G[u]) if (!seen2[v]) {
            if (dfs2(v)) {
                seen2[u] = false;
                return true;
            }
        }
        seen2[u] = false;
        return false;
    };

    vi seen(n), stack;
    vvi res;
    function<void(int)> dfs = [&](int u) {
        if (!dfs2(u)) return;
        seen[u] = true;
        seen2[u] = true;
        stack.push_back(u);
        if (u == n-1) {
            res.push_back(stack);
        } else {
            for (int v : G[u]) if (!seen[v]) {
                dfs(v);
            }
        }
        stack.pop_back();
        seen[u] = false;
        seen2[u] = false;
    };
    dfs(0);
    
    if (res.size() >= k) {
        FOR(i, 0, k) {
            cout << res[i].size() << ' ';
            for (int j : res[i]) cout << j+1 << ' ';
            cout << '\n';
        }
    } else cout << "Stay at home";
}