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
    vi x(n);
    FOR(i, 0, n) cin >> x[i];
    int m, k;
    cin >> m >> k;
    vi a(m);
    FOR(i, 0, m) {
        cin >> a[i];
        --a[i];
    }

    const int BIG = 61;
    vvi up(n-1, vi(BIG));
    FOR(i, 0, n-1) up[i][0] = i;
    FOR(i, 0, m) swap(up[a[i]-1][0], up[a[i]][0]);
    FOR(j, 1, BIG) {
        FOR(i, 0, n-1) up[i][j] = up[up[i][j-1]][j-1];
    }
    vi p(n-1);
    FOR(i, 0, n-1) p[i] = i;
    FOR(j, 0, BIG) if (k>>j&1LL) {
        FOR(i, 0, n-1) p[i] = up[p[i]][j];
    }
    int res = x[0];
    cout << res << ' ';
    FOR(i, 0, n-1) {
        res += x[p[i]+1] - x[p[i]];
        cout << res << ' ';
    }
}