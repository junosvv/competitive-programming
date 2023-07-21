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

    int n;
    cin >> n;
    vvi a(n, vi(n));
    FOR(i, 0, n) FOR(j, 0, n) {
        char x;
        cin >> x;
        a[i][j] = x-'0';
    }
    
    vector<pii> path;
    FOR(j, 0, n) path.emplace_back(0, j);
    FOR(i, 1, n) path.emplace_back(i, n-1);
    ROF(j, n-2, -1) path.emplace_back(n-1, j);
    ROF(i, n-2, -1) path.emplace_back(i, 0);

    vvi b = a;
    FOR(i, 1, path.size()) {
        int r, c, rr, cc;
        tie(r, c) = path[i-1];
        tie(rr, cc) = path[i];
        b[rr][cc] = a[r][c];
    }
    
    FOR(i, 0, n) {
        FOR(j, 0, n) cout << b[i][j];
        cout << '\n';
    }
}