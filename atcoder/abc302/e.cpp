#include <bits/stdc++.h>
using namespace std;

#define int long long
#define FOR(i, a, b) for (int i=(a); i<(b); ++(i))
#define vi vector<int>

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);
    
    int n, q;
    cin >> n >> q;
    vector<set<int>> g(n);
    int res = n;
    FOR(qi, 0, q) {
        int t, u;
        cin >> t >> u;
        --u;

        if (t == 1) {
            int v;
            cin >> v;
            --v;

            if (g[u].empty()) --res;
            g[u].insert(v);
            if (g[v].empty()) --res;
            g[v].insert(u);
        } else {
            for (int v : g[u]) {
                g[v].erase(u);
                if (g[v].empty()) ++res;
            }
            if (!g[u].empty()) ++res;
            g[u].clear();
        }
        cout << res << ' ';
    }
}