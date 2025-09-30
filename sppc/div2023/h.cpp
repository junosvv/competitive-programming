#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef long long ll;
#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define ROF(i, a, b) for (int i=(a); i>(b); --i)
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int,int>
#define t3i tuple<int,int,int>
#define vs vector<string>

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);
    
    int n;
    cin >> n;
    int BIG = n*n*n;
    const int INF = 1005;
    vvi adj(2*BIG+3, vi(2*BIG+3));

    auto code = [&](int i, int j, int k) {
        return i*n*n + j*n + k;
    };

    vvi G(2*BIG+3);
    auto add_edge = [&](int u, int v, int w) {
        adj[u][v] = w;
        G[u].push_back(v);
        G[v].push_back(u);
    };

    FOR(i, 0, n) FOR(j, 0, n) FOR(k, 0, n) {
        int u = code(i, j, k);
        for (auto tup : vector<t3i>{{-1,0,0}, {1,0,0}, {0,-1,0}, {0,1,0}, {0,0,-1}, {0,0,1}}) {
            int di, dj, dk;
            tie(di, dj, dk) = tup;
            int ii = i + di, jj = j + dj, kk = k + dk;
            int v;
            if (0 <= ii && ii < n && 0 <= jj && jj < n && 0 <= kk && kk < n) {
                v = code(ii, jj, kk);
                add_edge(BIG+u, v, INF);
                add_edge(BIG+v, u, INF);
            } else if (!adj[2*BIG][u]) {
                add_edge(BIG+u, 2*BIG, INF);
                add_edge(2*BIG, u, INF);
            }
        }
        char c;
        cin >> c;
        if (c == '.') add_edge(u, BIG+u, 1);
        if (c == 'R') add_edge(2*BIG+1, BIG+u, INF);
        if (c == 'S') add_edge(u, 2*BIG+2, INF);
    }
    vvi capac = adj;

    auto bfs = [&](vi& par) {
        queue<int> q;
        q.push(2*BIG+1);
        par[2*BIG+1] = -2;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int v : G[u]) if (par[v] == -1 && capac[u][v]) {
                par[v] = u;
                if (v == 2*BIG+2) return;
                q.push(v);
            }
        }
    };

    int flow = 0;
    while (true) {
        vi par(2*BIG+3, -1);
        bfs(par);
        if (par[2*BIG+2] == -1) {
            cout << flow << '\n';
            break;
        }
        int v = 2*BIG+2;
        while (par[v] != -2) {
            int u = par[v];
            --capac[u][v];
            ++capac[v][u];
            v = u;
        }
        ++flow;
        if (flow >= INF) {
            cout << -1 << '\n';
            break;
        }
    }
}