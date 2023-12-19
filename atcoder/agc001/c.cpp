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
    
    int n, k;
    cin >> n >> k;

    vector<pii> edges(n-1);
    vvi G(n);
    FOR(i, 0, n-1) {
        cin >> edges[i].first >> edges[i].second;
        --edges[i].first; --edges[i].second;
        G[edges[i].first].push_back(edges[i].second);
        G[edges[i].second].push_back(edges[i].first);
    }

    int res = n;

    auto check = [&](vi& dist, queue<int>& q) {
        if (k != 1) {
            while (!q.empty()) {
                int u = q.front();
                q.pop();
                for (int v : G[u]) if (dist[v] == -1) {
                    dist[v] = 1 + dist[u];
                    if (dist[v] < k/2) q.push(v);
                }
            }
        }

        int res = 0;
        for (int i : dist) if (i == -1) ++res;
        return res;
    };

    if (k&1) {
        for (pii pr : edges) {
            int u = pr.first, v = pr.second;
            vi dist(n, -1);
            dist[u] = 0;
            dist[v] = 0;
            queue<int> q;
            q.push(u);
            q.push(v);
            res = min(res, check(dist, q));
        }
    } else {
        FOR(s, 0, n) {
            vi dist(n, -1);
            dist[s] = 0;
            queue<int> q;
            q.push(s);
            res = min(res, check(dist, q));
        }
    }

    cout << res;
}