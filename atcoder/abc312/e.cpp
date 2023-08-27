#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define ROF(i, a, b) for (int i=(a); i>(b); --i)
#define vi vector<int>
#define vvi vector<vi>
 
signed main() {
    ios::sync_with_stdio(0), cin.tie(0);
    
    int n;
    cin >> n;
    vi x1(n), y1(n), z1(n), x2(n), y2(n), z2(n);
    const int M = 100;
    vector<vvi> grid(M, vvi(M, vi(M, -1)));
    FOR(i, 0, n) {
        cin >> x1[i] >> y1[i] >> z1[i] >> x2[i] >> y2[i] >> z2[i];
        FOR(x, x1[i], x2[i]) FOR(y, y1[i], y2[i]) FOR(z, z1[i], z2[i]) grid[x][y][z] = i;
    }

    vector<set<int>> res(n);
    auto check = [&](int u, int v) {
        if (u != -1 && v != -1 && u != v) {
            res[u].insert(v);
            res[v].insert(u);
        }
    };

    FOR(x, 1, M) FOR(y, 0, M) FOR(z, 0, M) check(grid[x-1][y][z], grid[x][y][z]);
    FOR(x, 0, M) FOR(y, 1, M) FOR(z, 0, M) check(grid[x][y-1][z], grid[x][y][z]);
    FOR(x, 0, M) FOR(y, 0, M) FOR(z, 1, M) check(grid[x][y][z-1], grid[x][y][z]);

    for (auto st : res) cout << st.size() << '\n';
}