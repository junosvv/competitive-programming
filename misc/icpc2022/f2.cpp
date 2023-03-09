#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define vi vector<int>

vector<vi> nodes;
vi seen;
void dfs(int u) {
    seen[u] = 1;
    for (int v : nodes[u]) if (!seen[v]) {
        dfs(v);
    }
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);
    
    int n, m;
    cin >> n >> m;

    nodes.assign(n, {});
    FOR(i, 0, m) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        nodes[u].push_back(v);
    }
    
    FOR(u, 0, n) {
        seen.assign(n, 0);
        dfs(u);
        cout << accumulate(seen.begin(), seen.end(), 0) << ' ';
    }
}