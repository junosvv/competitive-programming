#include <bits/stdc++.h>
using namespace std;

#define int long long
#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define ROF(i, a, b) for (int i=(a); i>(b); --i)
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int,int>
#define vs vector<string>

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int R, C;
    cin >> R >> C;

    vs grid(R);
    FOR(r, 0, R) cin >> grid[r];

    vvi rcnt(R, vi(26)), ccnt(C, vi(26));
    vi runiq(R), cuniq(C);
    FOR(r, 0, R) {
        FOR(c, 0, C) ++rcnt[r][grid[r][c]-'a'];
        FOR(i, 0, 26) if (rcnt[r][i] >= 1) ++runiq[r];
    }
    FOR(c, 0, C) {
        FOR(r, 0, R) ++ccnt[c][grid[r][c]-'a'];
        FOR(i, 0, 26) if (ccnt[c][i] >= 1) ++cuniq[c];
    }

    while (true) {
        vi ragain, cagain;
        FOR(r, 0, R) if (runiq[r] == 1 && accumulate(rcnt[r].begin(), rcnt[r].end(), 0LL) >= 2) ragain.push_back(r);
        FOR(c, 0, C) if (cuniq[c] == 1 && accumulate(ccnt[c].begin(), ccnt[c].end(), 0LL) >= 2) cagain.push_back(c);
        for (int r : ragain) {
            runiq[r] = 0;
            FOR(c, 0, C) if (grid[r][c] != '.') {
                --ccnt[c][grid[r][c]-'a'];
                if (ccnt[c][grid[r][c]-'a'] == 0) --cuniq[c];
                grid[r][c] = '.';
            }
        }

        for (int c : cagain) {
            cuniq[c] = 0;
            FOR(r, 0, R) if (grid[r][c] != '.') {
                --rcnt[r][grid[r][c]-'a'];
                if (rcnt[r][grid[r][c]-'a'] == 0) --runiq[r];
                grid[r][c] = '.';
            }
        }
        if (ragain.empty() && cagain.empty()) break;
    }

    int res = 0;
    FOR(r, 0, R) FOR(c, 0, C) res += grid[r][c] != '.';
    cout << res;
}