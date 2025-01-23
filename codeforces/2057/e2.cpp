#include <bits/stdc++.h>
using namespace std;

#define int long long
#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define ROF(i, a, b) for (int i=(a); i>(b); --i)
#define vi vector<int>
#define vvi vector<vi>
#define vs vector<string>
#define pii pair<int,int>
#define vpii vector<pii>
#define vvpii vector<vpii>
#define mii map<int,int>

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);
    
    auto solve = [&]() {
        int n, m, q;
        cin >> n >> m >> q;
        
        vvi edges0;
        vi trans;
        FOR(i, 0, m) {
            int u, v, w;
            cin >> u >> v >> w;
            --u; --v;
            edges0.push_back({u, v, w});
            trans.push_back(w);
        }
        sort(trans.begin(), trans.end());
        int cc = unique(trans.begin(), trans.end()) - trans.begin();
        trans.resize(cc);

        mii transinv;
        FOR(i, 0, cc) transinv[trans[i]] = i;

        const int INF = n+5;
        vvi dist(n, vi(n, INF));
        FOR(u, 0, n) dist[u][u] = 0;

        vvpii edges(cc);
        FOR(i, 0, m) {
            int u = edges0[i][0], v = edges0[i][1], w = transinv[edges0[i][2]];
            edges[w].emplace_back(u, v);
            dist[u][v] = 1;
            dist[v][u] = 1;
        }

        FOR(k, 0, n) FOR(u, 0, n) FOR(v, 0, n) dist[u][v] = min(dist[u][v], dist[u][k] + dist[k][v]);

        vector<vvpii> qs(n, vvpii(n));
        FOR(qi, 0, q) {
            int u, v, k;
            cin >> u >> v >> k;
            --u; --v;
            if (u > v) swap(u, v);

            qs[u][v].emplace_back(k, qi);
        }

        FOR(u, 0, n) FOR(v, 0, n) {
            sort(qs[u][v].begin(), qs[u][v].end());
        }

        vi res(q);
        FOR(w, 0, cc) {
            for (pii pr : edges[w]) {
                int u = pr.first, v = pr.second;
                if (dist[u][v] == 0) continue;
                FOR(x, 0, n) FOR(y, 0, n) {
                    dist[x][y] = min(dist[x][y], min(dist[x][u] + dist[v][y], dist[x][v] + dist[u][y]));
                    while (!qs[x][y].empty()) {
                        int k = qs[x][y].back().first, qi = qs[x][y].back().second;
                        if (dist[x][y] >= k) break;
                        res[qi] = trans[w];
                        qs[x][y].pop_back();
                    }
                }
            }
        }
        for (int i : res) cout << i << ' ';
        cout << '\n';
    };

    int T;
    cin >> T;
    FOR(t, 0, T) solve();
}