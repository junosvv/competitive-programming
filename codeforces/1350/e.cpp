#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define ROF(i, a, b) for (int i=(a); i>(b); --i)
#define lg long long

long long MOD = 1e9+7;

template <class T> ostream& operator<<(ostream& os, vector<T>& x) {
    os << '[';
    bool first = true;
    for (auto i : x) {
        if (!first) os << ", ";
        first = false;
        os << i;
    }
    return os << ']';
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int R, C, Q;
    cin >> R >> C >> Q;

    vector<vector<bool>> grid(R, vector<bool>(C));
    vector<bool> checkseen(2);
    FOR(r, 0, R) FOR(c, 0, C) {
        char x;
        cin >> x;
        grid[r][c] = x == '1';
        checkseen[(r^c^grid[r][c])&1] = true;
    }

    if (!checkseen[0] || !checkseen[1]) {
        FOR(qi, 0, Q) {
            int r, c;
            lg j;
            cin >> r >> c >> j;
            --r; --c;
            cout << grid[r][c] << '\n';
        }
        exit(0);
    }

    vector<vector<int>> dist(R, vector<int>(C, -1));
    const vector<pair<int, int>> DELTAS = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    queue<pair<int, int>> q;
    FOR(r, 0, R) FOR(c, 0, C) {
        for (pair<int, int> delta : DELTAS) {
            int dr, dc;
            tie(dr, dc) = delta;
            int rr = r + dr;
            int cc = c + dc;
            if (0 <= rr && rr < R && 0 <= cc && cc < C && grid[rr][cc] == grid[r][c]) {
                q.emplace(r, c);
                dist[r][c] = 0;
                break;
            }
        }
    }

    while (!q.empty()) {
        int r, c;
        tie(r, c) = q.front();
        q.pop();

        for (pair<int, int> delta : DELTAS) {
            int dr, dc;
            tie(dr, dc) = delta;
            int rr = r + dr;
            int cc = c + dc;
            if (0 <= rr && rr < R && 0 <= cc && cc < C && dist[rr][cc] == -1) {
                dist[rr][cc] = 1 + dist[r][c];
                q.emplace(rr, cc);
            }
        }
    }

    FOR(qi, 0, Q) {
        int r, c;
        lg j;
        cin >> r >> c >> j;
        --r; --c;

        if (j <= dist[r][c]) cout << grid[r][c] << '\n';
        else cout << (grid[r][c] ^ (j-dist[r][c])&1) << '\n';
    }
}