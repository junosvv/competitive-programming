#include <bits/stdc++.h>
using namespace std;

#define int long long
#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define ROF(i, a, b) for (int i=(a); i>(b); --i)
#define vi vector<int>
#define vs vector<string>
#define vb vector<bool>
#define pii pair<int,int>

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int n, m;
    cin >> n >> m;
    ++n;

    vector<vector<vi>> nodes(2, vector<vi>(n));
    FOR(i, 1, n) {
        nodes[1][i-1].push_back(i);
        nodes[1][i].push_back(i-1);
    }

    FOR(i, 0, m) {
        int x, y;
        cin >> x >> y;
        nodes[0][x-1].push_back(y);
        nodes[0][y].push_back(x-1);
    }
    
    vector<vi> q(2);
    q[0] = {0};
    vi dist(n, -1);
    dist[0] = 0;
    while (true) {
        if (q[0].empty()) {
            q[0] = q[1];
            q[1].clear();
        }
        if (q[0].empty()) break;
        int u = q[0].back();
        q[0].pop_back();
        
        FOR(w, 0, 2) {
            for (int v : nodes[w][u]) if (dist[v] == -1) {
                dist[v] = w + dist[u];
                q[w].push_back(v);
            }
        }
    }

    FOR(i, 1, n) cout << (dist[i] < dist[i-1]);
}