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
    
    int n, m, k;
    cin >> n >> m >> k;

    vector<pii> edge(m);
    vi cost(m);
    FOR(i, 0, m) {
        cin >> edge[i].first >> edge[i].second >> cost[i];
        --edge[i].first; --edge[i].second;
    }
    vi e(k);
    FOR(i, 0, k) {
        cin >> e[i];
        --e[i];
    }

    vi dist(n, 1e15);
    dist[0] = 0;
    FOR(i, 0, k) {
        int u, v;
        tie(u, v) = edge[e[i]];
        dist[v] = min(dist[v], cost[e[i]] + dist[u]);
    }
    cout << (dist[n-1] == 1e15 ? -1 : dist[n-1]);
}