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
    
    int n;
    cin >> n;
    vector<string> imgs(n, string(25, ' '));
    FOR(i, 0, n) FOR(c, 0, 25) cin >> imgs[i][c];

    auto subs = [&](int u, int v) {
        FOR(i, 0, 25) if (imgs[u][i] == '#' && imgs[v][i] == '.') return false;
        return imgs[u] != imgs[v] || u < v;
    };

    int m = 3*n+2;
    const int INF = 3000;
    vvi G(m), capac(m, vi(m)), c(m, vi(m));
    auto add_edge = [&](int u, int v, int w) {
        G[u].push_back(v);
        G[v].push_back(u);
        capac[u][v] = w;
    };
    
    FOR(i, 0, n) FOR(j, 0, n) if (i != j && subs(i, j)) {
        add_edge(n+i, j, INF);
        c[n+i][j] = -1;
        c[j][n+i] = 1;
    }
    FOR(i, 0, n) {
        add_edge(3*n, 2*n+i, 1);
        add_edge(2*n+i, 3*n+1, INF);
        add_edge(2*n+i, i, INF);
        add_edge(n+i, 3*n+1, INF);
        add_edge(i, n+i, 1);
    }

    auto search = [&](vi& par, vi& pot) {
        vi dist(m, INF);
        dist[3*n] = 0;
        priority_queue<pii> pq;
        pq.emplace(0, 3*n);
        while (!pq.empty()) {
            int cost, u;
            tie(cost, u) = pq.top();
            pq.pop();
            cost *= -1;
            if (cost != dist[u]) continue;
            
            for (int v : G[u]) if (capac[u][v]) {
                if (dist[u] + c[u][v] + pot[u] - pot[v] < dist[v]) {
                    dist[v] = dist[u] + c[u][v] + pot[u] - pot[v];
                    par[v] = u;
                    pq.emplace(-dist[v], v);
                }
            }
        }
        FOR(u, 0, m) dist[u] += pot[u];
        pot = dist;
        return dist[3*n+1];
    };

    vi pot(m, INF);
    pot[3*n] = 0;
    FOR(k, 0, m-1) {
        FOR(u, 0, m) for (int v : G[u]) if (capac[u][v]) {
            pot[v] = min(pot[v], pot[u] + c[u][v]);
        }
    }

    int res = n;
    FOR(flow, 0, n) {
        vi par(m, -1);
        res += search(par, pot);
        int v = 3*n+1;
        while (v != 3*n) {
            int u = par[v];
            --capac[u][v];
            ++capac[v][u];
            v = u;
        }
    }
    cout << res << '\n';
}