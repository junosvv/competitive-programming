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
    
    int n, m;
    cin >> n >> m;
    vi par(n);
    FOR(u, 1, n) {
        cin >> par[u];
        --par[u];
    }
    vi cover(n, -1);
    FOR(i, 0, m) {
        int u, x;
        cin >> u >> x;
        --u;
        cover[u] = max(cover[u], x);
    }
    FOR(u, 1, n) {
        cover[u] = max(cover[u], cover[par[u]] - 1);
    }
    int res = 0;
    FOR(u, 0, n) if (cover[u] >= 0) ++res;
    cout << res;
}