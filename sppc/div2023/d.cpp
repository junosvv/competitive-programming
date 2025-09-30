#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define ROF(i, a, b) for (int i=(a); i>(b); --i)
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int,int>
#define vs vector<string>

const ll MOD = 1000000007;

int nrows, ncols, letters, startc, finishc;
vector<vs> grid;
map<tuple<int,int,int>,ll> dp;
void solve(int r, int c, int state) {
    if (abs(c - finishc) > nrows-1-r) {
        dp[{r, c, state}] = 0;
        return;
    }
    if (r == nrows-1) {
        dp[{r, c, state}] = __builtin_popcount(state) == letters;
        return;
    }
    dp[{r, c, state}] = 0;
    FOR(i, -1, 2) if (0 <= c+i && c+i < ncols) {
        bool succ = true;
        int state2 = state;
        for (char chr : grid[r+1][c+i]) if (chr != '-') {
            int x = chr - 'A';
            if (state>>x&1) {
                succ = false;
                break;
            }
            state2 |= 1 << x;
        }
        if (succ) {
            if (!dp.count({r+1, c+i, state2})) solve(r+1, c+i, state2);
            dp[{r, c, state}] = (dp[{r, c, state}] + dp[{r+1, c+i, state2}]) % MOD;
        }
    }
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> nrows >> ncols >> letters >> startc >> finishc;
    --startc; --finishc;
    grid.assign(nrows, vs(ncols));
    FOR(r, 0, nrows) FOR(c, 0, ncols) {
        cin >> grid[r][c];
    }
    
    int initstate = 0;
    for (char chr : grid[0][startc]) if (chr != '-') {
        initstate |= 1LL << (chr-'A');
    }
    solve(0, startc, initstate);
    cout << dp[{0, startc, initstate}] << '\n';
}