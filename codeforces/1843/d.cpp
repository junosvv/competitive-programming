#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define vi vector<int>
 
signed main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int T;
    cin >> T;
    FOR(t, 0, T) {
        int n;
        cin >> n;
        
        vector<vi> G(n);
        FOR(i, 0, n-1) {
            int u, v;
            cin >> u >> v;
            --u; --v;
            G[u].push_back(v);
            G[v].push_back(u);
        }

        vi leaves(n);
        function<void(int,int)> dfs = [&](int u, int p) {
            for (int v : G[u]) if (v != p) {
                dfs(v, u);
                leaves[u] += leaves[v];
            }
            if (leaves[u] == 0) leaves[u] = 1;
        };
        dfs(0, -1);

        int q;
        cin >> q;
        FOR(qi, 0, q) {
            int u, v;
            cin >> u >> v;
            --u; --v;

            cout << leaves[u] * leaves[v] << '\n';
        }
    }
}