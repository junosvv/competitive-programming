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
    vvi G(n), edges(2*m);
    FOR(i, 0, m) {
        int a, b, x, y;
        cin >> a >> b >> x >> y;
        --a; --b;
        G[a].push_back(2*i);
        G[b].push_back(2*i+1);
        edges[2*i] = {b, x, y};
        edges[2*i+1] = {a, -x, -y};
    }

    vi seen(n);
    vector<pii> pos(n);
    function<void(int)> dfs = [&](int u) {
        seen[u] = true;
        for (int i : G[u]) {
            int v = edges[i][0], x = edges[i][1], y = edges[i][2];
            if (!seen[v]) {
                pos[v].first = pos[u].first + x;
                pos[v].second = pos[u].second + y;
                dfs(v);
            }
        }
    };
    dfs(0);

    FOR(u, 0, n) {
        if (seen[u]) cout << pos[u].first << ' ' << pos[u].second << '\n';
        else cout << "undecidable\n";
    }
}