#include <bits/stdc++.h>
using namespace std;

#define int long long
#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define ROF(i, a, b) for (int i=(a); i>(b); --i)

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);
    
    int R, C, k;
    cin >> R >> C >> k;

    vector<vector<int>> grid(R, vector<int>(C));
    FOR(r, 0, R) FOR(c, 0, C) cin >> grid[r][c];

    vector<int> dp(C-k+1);
    vector<vector<int>> par(R, vector<int>(C-k+1));
    ROF(r, R-1, -1) {
        vector<int> dp2(C-k+1);
        FOR(c, 0, C-k+1) {
            int sm = 0;
            FOR(i, c, c+k) sm += grid[r][i];
            FOR(cp, c-k+1, c+k) if (0 <= cp && cp < C-k+1) {
                int cur = sm + dp[cp];
                if (cur > dp2[c]) {
                    par[r][c] = cp;
                    dp2[c] = cur;
                }
            }
        }
        dp = dp2;
    }

    int x = max_element(dp.begin(), dp.end()) - dp.begin();
    FOR(r, 0, R) {
        FOR(c, 0, x) cout << '.';
        FOR(c, 0, k) cout << 'X';
        FOR(c, 0, C-x-k) cout << '.';
        cout << '\n';
        x = par[r][x];
    }
}
