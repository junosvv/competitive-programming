#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define ROF(i, a, b) for (int i=(a); i>(b); --i)
#define int long long
#define vi vector<int>

template <class T> ostream& operator<<(ostream& os, vector<T>& x) {
    os << '[';
    bool first = true;
    for (T& i : x) {
        if (!first) os << ", ";
        first = false;
        os << i;
    }
    return os << ']';
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int R, C;
    cin >> R >> C;
    vector<string> grid(R);
    int sr, sc, fr, fc;
    vector<vector<pair<int,int>>> locs(26);
    FOR(r, 0, R) {
        cin >> grid[r];
        FOR(c, 0, C) {
            if (grid[r][c] == 'S') {
                sr = r;
                sc = c;
            } else if (grid[r][c] == 'G') {
                fr = r;
                fc = c;
            } else if ('a' <= grid[r][c] && grid[r][c] <= 'z') {
                locs[grid[r][c]-'a'].emplace_back(r, c);
            }
        }
    }

    deque<pair<int,int>> q;
    q.emplace_back(sr, sc);
    vector<vi> dist(R, vi(C, -1));
    dist[sr][sc] = 0;
    vector<bool> seen(26);
    while (!q.empty()) {
        int r, c;
        tie(r, c) = q.front();
        q.pop_front();

        // cout << r << ' ' << c << " dist " << dist[r][c] << '\n';

        for (auto pr : vector<pair<int,int>>{{0, 1}, {0, -1}, {1, 0}, {-1, 0}}) {
            int dr, dc;
            tie(dr, dc) = pr;
            int rr = r + dr;
            int cc = c + dc;
            if (rr < 0 || rr >= R || cc < 0 || cc >= C || grid[rr][cc] == '#' || dist[rr][cc] != -1) continue;
            dist[rr][cc] = 1 + dist[r][c];
            q.emplace_back(rr, cc);
        }
        if ('a' <= grid[r][c] && grid[r][c] <= 'z' && !seen[grid[r][c]-'a']) {
            seen[grid[r][c]-'a'] = true;
            for (auto pr : locs[grid[r][c]-'a']) {
                int rr, cc;
                tie(rr, cc) = pr;
                if (dist[rr][cc] == -1) {
                    dist[rr][cc] = 1 + dist[r][c];
                    q.emplace_back(rr, cc);
                }
            }
        }
    }
    // FOR(r, 0, R) {
    //     FOR(c, 0, C) {
    //         cout << dist[r][c] << ' ';
    //     }
    //     cout << '\n';
    // }
    // cout << '\n';
    cout << dist[fr][fc];
}
