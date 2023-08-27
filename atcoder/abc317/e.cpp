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
    vector<string> grid(R, string(C, ' '));
    FOR(r, 0, R) cin >> grid[r];

    int sr, sc, gr, gc;
    FOR(r, 0, R) FOR(c, 0, C) {
        if (grid[r][c] == 'S') {
            sr = r;
            sc = c;
        }
        if (grid[r][c] == 'G') {
            gr = r;
            gc = c;
        }
        if (grid[r][c] == 'v') FOR(rr, r+1, R) {
            if (grid[rr][c] != '.' && grid[rr][c] != '!') break;
            grid[rr][c] = '!';
        }
        if (grid[r][c] == '^') ROF(rr, r-1, -1) {
            if (grid[rr][c] != '.' && grid[rr][c] != '!') break;
            grid[rr][c] = '!';
        }
        if (grid[r][c] == '>') FOR(cc, c+1, C) {
            if (grid[r][cc] != '.' && grid[r][cc] != '!') break;
            grid[r][cc] = '!';
        }
        if (grid[r][c] == '<') ROF(cc, c-1, -1) {
            if (grid[r][cc] != '.' && grid[r][cc] != '!') break;
            grid[r][cc] = '!';
        }
    }

    queue<pii> q;
    q.emplace(sr, sc);
    vvi dist(R, vi(C, -1));
    dist[sr][sc] = 0;
    while (!q.empty()) {
        int r, c;
        tie(r, c) = q.front();
        q.pop();

        for (pii delta : vector<pii>{{-1, 0}, {1, 0}, {0, -1}, {0, 1}}) {
            int rr = r + delta.first;
            int cc = c + delta.second;
            if (0 <= rr && rr < R && 0 <= cc && cc < C && (grid[rr][cc] == '.' || grid[rr][cc] == 'G') && dist[rr][cc] == -1) {
                dist[rr][cc] = 1 + dist[r][c];
                q.emplace(rr, cc);
            }
        }
    }
    cout << dist[gr][gc];
}