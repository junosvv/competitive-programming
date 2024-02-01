#include <bits/stdc++.h>
using namespace std;

#define int long long
#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define ROF(i, a, b) for (int i=(a); i>(b); --i)
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int,int>

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int n, q;
    cin >> n >> q;
    vvi a(2, vi(n));
    vi c(n);
    FOR(i, 0, n) cin >> a[0][i];
    FOR(i, 0, n) cin >> a[1][i];
    FOR(i, 0, n-1) cin >> c[i];
    
    while (__builtin_popcount(n) > 1) ++n;
    a[0].resize(n);
    a[1].resize(n);
    c.resize(n);
    // cout << "inc n to " << n << '\n';
    
    vi trees[2][2], right(2*n);
    FOR(i, 0, n) right[n+i] = i;
    ROF(i, n-1, 0) right[i] = right[2*i+1];
    auto merge = [&](int x) {
        FOR(s, 0, 2) {
            FOR(e, 0, 2) {
                trees[s][e][x] = min({
                    trees[s][0][2*x] + trees[0][e][2*x+1],
                    trees[s][0][2*x] + trees[1][e][2*x+1],
                    trees[s][1][2*x] + trees[0][e][2*x+1] + c[right[2*x]],
                    trees[s][1][2*x] + trees[1][e][2*x+1]
                });
            }
        }
    };

    // auto print_tree = [&]() {
    //     int pd = 2*n;
    //     for (int d = n; d; d /= 2) {
    //         FOR(i, d, pd) {
    //             FOR(s, 0, 2) FOR(e, 0, 2) cout << trees[s][e][i] << ' ';
    //             cout << '\n';
    //         }
    //         cout << '\n';
    //         pd = d;
    //     }
    // };

    FOR(s, 0, 2) FOR(e, 0, 2) trees[s][e].assign(2*n, 4e18);
    FOR(s, 0, 2) {
        FOR(i, 0, n) {
            trees[s][s][n+i] = a[s][i];
        }
        ROF(i, n-1, 0) merge(i);
    }
    int mn = 4e18;
    FOR(s, 0, 2) FOR(e, 0, 2) mn = min(mn, trees[s][e][1]);
    // cout << "init: " << mn << '\n';

    FOR(qi, 0, q) {
        int i;
        cin >> i;
        --i;
        cin >> a[0][i] >> a[1][i] >> c[i];
        FOR(s, 0, 2) trees[s][s][n+i] = a[s][i];
        i += n;
        i /= 2;
        while (i) {
            merge(i);
            i /= 2;
        }
        int mn = 4e18;
        FOR(s, 0, 2) FOR(e, 0, 2) mn = min(mn, trees[s][e][1]);
        cout << mn << '\n';
    }
}