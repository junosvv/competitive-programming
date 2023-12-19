#include <bits/stdc++.h>
using namespace std;

#define int long long
#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define ROF(i, a, b) for (int i=(a); i>(b); --i)
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int,int>
#define SQ(x) (x)*(x)

void maxi(int& a, int b) {
    a = max(a, b);
}
void mini(int& a, int b) {
    a = min(a, b);
}

const int MOD = 1e9+7;

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int R, C;
    cin >> R >> C;

    vector<string> grid(R);
    FOR(r, 0, R) cin >> grid[r];

    vvi dp(R+1, vi(C+1));
    dp[1][1] = 1;
    FOR(r, 1, R+1) FOR(c, 1, C+1) if (!(r == 1 && c == 1)) {
        if (grid[r-1][c-1] != '#') {
            dp[r][c] = (dp[r-1][c] + dp[r][c-1]) % MOD;
        }
    }

    cout << dp[R][C];
}