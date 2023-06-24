#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define ROF(i, a, b) for (int i=(a); i>(b); --i)
#define vi vector<int>

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);
    
    int n, m, k;
    cin >> n >> m >> k;
    vector<vi> G(n);
    FOR(i, 0, m) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    vi power(n, -1);
    vector<vi> b(n+1);
    FOR(i, 0, k) {
        int p, h;
        cin >> p >> h;
        --p;
        power[p] = h;
        b[h].push_back(p);
    }

    ROF(i, n, 0) {
        for (int u : b[i]) if (power[u] == i) {
            for (int v : G[u]) if (i-1 > power[v]) {
                power[v] = i-1;
                b[i-1].push_back(v);
            }
        }
    }
    
    vi res;
    FOR(u, 0, n) if (power[u] >= 0) res.push_back(u+1);
    cout << res.size() << '\n';
    for (int i : res) cout << i << ' ';
}