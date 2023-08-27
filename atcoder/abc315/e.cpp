#include <bits/stdc++.h>
using namespace std;

#define int long long
#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define ROF(i, a, b) for (int i=(a); i>(b); --i)
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int,int>
#define vs vector<string>

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int n;
    cin >> n;
    vvi G(n);
    FOR(i, 0, n) {
        int sz;
        cin >> sz;
        G[i].assign(sz, 0);
        FOR(j, 0, sz) {
            cin >> G[i][j];
            --G[i][j];
        }
    }
    vi res, seen(n);
    function<void(int)> dfs = [&](int u) {
        seen[u] = true;
        for (int v : G[u]) if (!seen[v]) {
            dfs(v);
        }
        if (u) res.push_back(u);
    };
    
    dfs(0);
    for (int u : res) cout << u+1 << ' ';
}