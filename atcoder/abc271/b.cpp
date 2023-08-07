#include <bits/stdc++.h>
using namespace std;

#define int long long
#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define ROF(i, a, b) for (int i=(a); i>(b); --i)
#define vi vector<int>
#define vvi vector<vi>

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);
    
    int n, q;
    cin >> n >> q;
    vvi a(n);
    FOR(i, 0, n) {
        int k;
        cin >> k;
        a[i].assign(k, 0);
        FOR(j, 0, k) cin >> a[i][j];
    }
    FOR(qi, 0, q) {
        int r, c;
        cin >> r >> c;
        cout << a[r-1][c-1] << '\n';
    }
}