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
    
    int n, m;
    cin >> n >> m;
    vvi cost(n, vi(n));
    FOR(i, 0, m) {
        int u, v, w;
        cin >> u >> v >> w;
        --u; --v;
        cost[u][v] = w;
        cost[v][u] = w;
    }

    vi perm(n);
    FOR(i, 0, n) perm[i] = i;
    int res = 0;
    do {
        int u = perm[0];
        int cur = 0;
        for (int v : perm) {
            if (cost[u][v]) {
                cur += cost[u][v];
                u = v;
            }
        }
        res = max(res, cur);
    } while (next_permutation(perm.begin(), perm.end()));
    
    cout << res;
}