#include <bits/stdc++.h>
using namespace std;

#define int long long
#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define ROF(i, a, b) for (int i=(a); i>(b); --i)
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int,int>

const int MOD = 1e9+7;

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);
    
    int n;
    cin >> n;
    vector<string> grid(n);
    FOR(i, 0, n) cin >> grid[i];

    vector<pii> DELTAS = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

    vvi dist(n, vi(n, -1));
    int seencnt = 0;
    function<void(int,int)> dfs = [&](int r, int c) {
        ++seencnt;
        if (r == n-1 && c == n-1) return;
        for (pii pr : DELTAS) {
            int rr = r+pr.first, cc = c+pr.second;
            if (0 <= rr && rr < n && 0 <= cc && cc < n && grid[rr][cc] == '.' && dist[rr][cc] == -1) {
                dist[rr][cc] = dist[r][c] + 1;
                dfs(rr, cc);
            }
        }
    };
    dist[0][0] = 0;
    dfs(0, 0);
    cout << 2*seencnt - dist[n-1][n-1] - 1;
}