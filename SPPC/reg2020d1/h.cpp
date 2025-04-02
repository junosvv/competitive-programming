#include <bits/stdc++.h>
using namespace std;

#define int long long
#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define ROF(i, a, b) for (int i=(a); i>(b); --i)
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int,int>

const int MOD = 1e9+7;

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);
    
    int n, t;
    cin >> n >> t;
    vector<string> grid(n);
    FOR(i, 0, n) cin >> grid[i];

    vector<pii> DELTAS = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

    vvi mat(n*n, vi(n*n));
    FOR(r, 0, n) FOR(c, 0, n) {
        FOR(d, 0, 4) {
            FOR(e, 0, 4) {
                int rr = r + DELTAS[(d+e)%4].first, cc = c + DELTAS[(d+e)%4].second;
                if (0 <= rr && rr < n && 0 <= cc && cc < n && grid[rr][cc] != '#') {
                    ++mat[rr*n+cc][r*n+c];
                    break;
                }
                if (e == 3) ++mat[r*n+c][r*n+c];
            }
        }
    }

    auto mult = [&](vvi& A, vvi& B) {
        vvi C(n*n, vi(n*n));
        FOR(r, 0, n*n) FOR(c, 0, n*n) FOR(i, 0, n*n) C[r][c] = (C[r][c] + A[r][i] * B[i][c]) % MOD;
        swap(C, A);
    };

    auto powa = [&](vvi& A, int exp) {
        vvi res(n*n, vi(n*n));
        FOR(i, 0, n*n) res[i][i] = 1;
        while (exp) {
            if (exp&1) mult(res, A);
            mult(A, A);
            exp /= 2;
        }
        swap(res, A);
    };

    powa(mat, t);
    vi res(n*n);
    FOR(r, 0, n) FOR(c, 0, n) if (grid[r][c] == '*') {
        FOR(i, 0, n*n) res[i] = (res[i] + mat[i][r*n+c]) % MOD;
    }
    FOR(r, 0, n) {
        FOR(c, 0, n) cout << res[r*n+c] << ' ';
        cout << '\n';
    }
}