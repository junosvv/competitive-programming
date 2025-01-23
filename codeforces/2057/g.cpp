#include <bits/stdc++.h>
using namespace std;

#define int long long
#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define ROF(i, a, b) for (int i=(a); i>(b); --i)
#define vi vector<int>
#define vvi vector<vi>
#define vs vector<string>
#define pii pair<int,int>
#define vpii vector<pii>
#define vvpii vector<vpii>
#define mii map<int,int>

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);
    
    auto solve = [&]() {
        int R, C;
        cin >> R >> C;
        vector<string> grid(R+2, string(C+2, '.'));
        FOR(r, 1, R+1) FOR(c, 1, C+1) cin >> grid[r][c];
        R += 2; C += 2;

        auto col = [&](int r, int c) {
            return (r + 2*c) % 5;
        };

        vvpii S(5);
        FOR(co, 0, 5) {
            FOR(r, 0, R) FOR(c, 0, C) {
                if (col(r, c) == co) {
                    if (grid[r][c] == '#') {
                        S[co].emplace_back(r, c);
                    } else {
                        for (pii pr : vpii{{-1, 0}, {1, 0}, {0, -1}, {0, 1}}) {
                            int rr = r + pr.first, cc = c + pr.second;
                            if (0 <= rr && rr < R && 0 <= cc && cc < C && grid[rr][cc] == '#') {
                                S[co].emplace_back(rr, cc);
                            }
                        }
                    }
                }
            }
        }

        int co = 0;
        FOR(i, 1, 5) if (S[i].size() < S[co].size()) co = i;

        for (pii pr : S[co]) {
            int r = pr.first, c = pr.second;
            grid[r][c] = 'S';
        }

        FOR(r, 1, R-1) {
            cout << grid[r].substr(1, C-2) << '\n';
        }
    };

    int T;
    cin >> T;
    FOR(t, 0, T) solve();
}