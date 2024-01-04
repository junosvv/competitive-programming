#include <bits/stdc++.h>
using namespace std;

#define lg long long
#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define ROF(i, a, b) for (int i=(a); i>(b); --i)
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int,int>

const int MOD = 998244353;

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);

    auto solve = [&]() {
        int n, k;
        cin >> n >> k;
        if (k&1) {
            cout << "No\n";
            return;
        }

        vvi res(n, vi(n));
        auto upd = [&](int r, int c) {
            r %= n;
            c %= n;
            assert(res[r][c] == 0);
            res[r][c] = 1;
        };

        bool flip = false;
        if (n*n-k < k) {
            flip = true;
            k = n*n-k;
        }

        if (n == 2) {
            if (k == 2) {
                upd(0, 0);
                upd(1, 1);
            }
        } else {
            if (k == 2) {
                cout << "No\n";
                return;
            }
            int c = 0;
            while (k > 2*n) {
                FOR(j, 0, n) upd(j, c+j);
                k -= n;
                ++c;
            }
            int r = 0;
            while (k != 6 && k != 0) {
                upd(r, c+1);
                upd(r, c+2);
                upd(r+1, c+1);
                upd(r+1, c+2);
                r += 2;
                c += 2;
                k -= 4;
            }
            if (k == 6) {
                upd(r, c+2);
                upd(r, c+3);
                upd(r+1, c+3);
                upd(r+1, c+4);
                upd(r+2, c+4);
                upd(r+2, c+2);
            }
        }
        
        if (flip) {
            FOR(r, 0, n) FOR(c, 0, n) res[r][c] ^= 1;
        }
        cout << "Yes\n";
        FOR(r, 0, n) {
            FOR(c, 0, n) cout << res[r][c] << ' ';
            cout << '\n';
        }
    };

    // while (1) solve();
    int T;
    cin >> T;
    FOR(t, 0, T) solve();
}