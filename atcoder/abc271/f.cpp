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
    vvi grid(n, vi(n)), grid2 = grid;
    FOR(r, 0, n) FOR(c, 0, n) {
        cin >> grid[r][c];
        grid2[n-1-r][n-1-c] = grid[r][c];
    }

    auto solve = [&](vvi grid) {
        vvi dp = {{grid[0][0]}};
        FOR(s, 1, n) {
            vvi dp2(s+1);
            FOR(r, 0, s+1) {
                int c = s-r;
                if (r-1 >= 0) for (int x : dp[r-1]) dp2[r].push_back(x ^ grid[r][c]);
                if (r < s) for (int x : dp[r]) dp2[r].push_back(x ^ grid[r][c]);
            }
            dp = dp2;
        }
        return dp;
    };

    vvi dp1 = solve(grid), dp2 = solve(grid2);
    reverse(dp2.begin(), dp2.end());
    int res = 0;
    FOR(i, 0, n) {
        map<int,int> cnt;
        for (int x : dp1[i]) ++cnt[x];
        for (int x : dp2[i]) res += cnt[x ^ grid[i][n-1-i]];
    }
    cout << res;
}