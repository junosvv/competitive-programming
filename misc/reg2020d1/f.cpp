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
    
    int R, C;
    cin >> R >> C;
    vector<string> grid(R);
    FOR(r, 0, R) cin >> grid[r];

    vvi comp(R, vi(C, -1));
    function<void(int,int)> dfs = [&](int r, int c) {
        FOR(rr, r-1, r+2) FOR(cc, c-1, c+2) {
            if (0 <= rr && rr < R && 0 <= cc && cc < C && grid[rr][cc] == grid[r][c] && comp[rr][cc] == -1) {
                comp[rr][cc] = comp[r][c];
                dfs(rr, cc);
            }
        }
    };

    int n = 0;
    FOR(r, 0, R) FOR(c, 0, C) if (comp[r][c] == -1) {
        comp[r][c] = n++;
        dfs(r, c);
    }

    vvi G(n);
    FOR(r, 0, R) FOR(c, 0, C) {
        FOR(rr, r-1, r+2) FOR(cc, c-1, c+2) {
            if (0 <= rr && rr < R && 0 <= cc && cc < C) {
                int u = comp[r][c], v = comp[rr][cc];
                if (u == v) continue;
                G[u].push_back(v);
                G[v].push_back(u);
            }
        }
    }
    FOR(u, 0, n) if (!G[u].empty()) {
        sort(G[u].begin(), G[u].end());
        vi temp = {G[u][0]};
        FOR(i, 1, G[u].size()) if (G[u][i-1] != G[u][i]) temp.push_back(G[u][i]);
        swap(temp, G[u]);
    }
    
    auto bfs = [&](vi& dist, int s) {
        queue<int> q;
        q.push(s);
        dist.assign(n, -1);
        dist[s] = 0;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int v : G[u]) if (dist[v] == -1) {
                dist[v] = 1 + dist[u];
                q.push(v);
            }
        }
        return max_element(dist.begin(), dist.end()) - dist.begin();
    };

    vi dist;
    int a = bfs(dist, 0);
    int b = bfs(dist, a);
    cout << (dist[b]+1)/2;
}