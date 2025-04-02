// j.cpp
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define ROF(i, a, b) for (int i=(a); i>(b); --i)
#define pii pair<int,int>
#define vi vector<int>
#define vvi vector<vi>
#define vd vector<ld>
#define vvd vector<vd>

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int sx, sy, ex, ey, n;
    cin >> sx >> sy >> ex >> ey >> n;
    vector<pii> stations;
    stations.emplace_back(sx, sy);
    stations.emplace_back(ex, ey);
    vvi subways(n);
    FOR(i, 0, n) {
        while (true) {
            int x, y;
            cin >> x >> y;
            if (x == -1) break;
            subways[i].push_back((int)stations.size());
            stations.emplace_back(x, y);
        }
    }

    function<double(pii, pii)> euc = [&](pii pos1, pii pos2) {
        return sqrt((double)((pos1.first-pos2.first)*(pos1.first-pos2.first) + (pos1.second-pos2.second)*(pos1.second-pos2.second)));
    };

    int m = stations.size();
    vvd adj(m, vd(m));
    FOR(i, 0, m) FOR(j, 0, m) if (i != j) {
        adj[i][j] = euc(stations[i], stations[j]);
        adj[j][i] = adj[i][j];
    }
    FOR(i, 0, n) {
        FOR(j, 1, (int)subways[i].size()) {
            adj[subways[i][j-1]][subways[i][j]] = euc(stations[subways[i][j-1]], stations[subways[i][j]]) / 4;
            adj[subways[i][j]][subways[i][j-1]] = euc(stations[subways[i][j-1]], stations[subways[i][j]]) / 4;
        }
    }

    vd dist(m, -1.0);
    dist[0] = 0;
    FOR(k, 0, m-1) {
        FOR(u, 0, m) FOR(v, 0, m) if (u != v) {
            if (dist[u] != -1 && (dist[v] == -1 || dist[u] + adj[u][v] < dist[v])) dist[v] = dist[u] + adj[u][v];
        }
    }
    cout << setprecision(20) << dist[1] * 3.0 / 500.0 << endl;
}