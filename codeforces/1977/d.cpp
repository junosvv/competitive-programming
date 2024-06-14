#include <bits/stdc++.h>
using namespace std;

#define int long long
#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define ROF(i, a, b) for (int i=(a); i>(b); --i)
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int,int>
#define mii map<int,int>

mt19937_64 rnd(chrono::steady_clock::now().time_since_epoch().count());

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);

    auto solve = [&]() {
        int R, C;
        cin >> R >> C;

        vvi grid(R, vi(C));
        FOR(r, 0, R) FOR(c, 0, C) {
            char x;
            cin >> x;
            grid[r][c] = x-'0';
        }

        vi rands(R);
        FOR(r, 0, R) rands[r] = rnd();

        int mx = 0;
        mii cnt, row, col;
        FOR(c, 0, C) {
            int hash = 0;
            FOR(r, 0, R) if (grid[r][c]) hash ^= rands[r];

            FOR(r, 0, R) {
                hash ^= rands[r];
                ++cnt[hash];
                mx = max(mx, cnt[hash]);
                row[hash] = r;
                col[hash] = c;
                hash ^= rands[r];
            }
        }

        for (pii pr : cnt) if (pr.second == mx) {
            cout << mx << '\n';
            vi res(R);
            int rr = row[pr.first], cc = col[pr.first];
            FOR(r, 0, R) res[r] = grid[r][cc];
            res[rr] ^= 1;
            for (int i : res) cout << i;
            cout << '\n';
            return;
        }
    };

    int T;
    cin >> T;
    FOR(t, 0, T) solve();
}