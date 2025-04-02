#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef long long ll;
#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define ROF(i, a, b) for (int i=(a); i>(b); --i)
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int,int>
#define vs vector<string>

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int n;
    cin >> n;
    vector<vector<string>> grid(n, vs(4));
    FOR(i, 0, n) FOR(j, 0, 4) cin >> grid[i][j];

    auto is_set = [&](int i, int j, int k) {
        FOR(d, 0, 4) {
            if (!(grid[i][d] == grid[j][d] && grid[j][d] == grid[k][d] || grid[i][d] != grid[j][d] && grid[i][d] != grid[k][d] && grid[j][d] != grid[k][d])) return false;
        }
        return true;
    };

    FOR(i, 0, n) FOR(j, i+1, n) FOR(k, j+1, n) {
        if (is_set(i, j, k)) {
            cout << i+1 << ' ' << j+1 << ' ' << k+1 << '\n';
            exit(0);
        }
    }
    cout << 0 << '\n';
}