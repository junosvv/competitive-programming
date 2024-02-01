#include <bits/stdc++.h>
using namespace std;

#define int long long
#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define ROF(i, a, b) for (int i=(a); i>(b); --i)
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int,int>

signed main() {
    // ios::sync_with_stdio(0), cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    vi a(n), b(m);
    FOR(i, 0, n) cin >> a[i];
    FOR(i, 0, m) cin >> b[i];
    
    vector<pii> ainfo(n);
    FOR(i, 0, n) ainfo[i] = {a[i], i+1};
    sort(ainfo.rbegin(), ainfo.rend());
    FOR(i, 0, n) a[i] = ainfo[i].first;

    vvi q(n, vi(m, n+1));
    FOR(d, 0, m) {
        int j = 0;
        FOR(i, 0, n) {
            while (j < n && (j < i || a[j]*(j-i+1) < b[d])) ++j;
            if (j < n) q[i][d] = j-i+1;
            // cout << "q " << i << ' ' << d << " -> " << q[i][d] << '\n';
        }
    }

    // cout << '\n';

    vi dp(1<<m, n+1), par(1<<m, -1);
    dp[0] = 0;
    FOR(mask, 1, 1<<m) {
        FOR(d, 0, m) if (mask>>d&1) {
            int x = dp[mask^(1<<d)];
            if (x < n && x + q[x][d] < dp[mask]) {
                dp[mask] = x + q[x][d];
                par[mask] = d;
            }
        }
        // bitset<3> temp(mask);
        // cout << temp << ": " << dp[mask] << '\n';
    }

    if (dp.back() == n+1) {
        cout << "NO";
        exit(0);
    }

    cout << "YES\n";
    vvi res(m);
    int mask = (1<<m) - 1;
    int i = dp[mask];
    while (par[mask] != -1) {
        int d = par[mask];
        int submask = mask ^ (1<<d);
        FOR(_, 0, dp[mask] - dp[submask]) res[d].push_back(ainfo[--i].second);
        mask = submask;
    }

    FOR(i, 0, m) {
        cout << res[i].size() << ' ';
        for (int j : res[i]) cout << j << ' ';
        cout << '\n';
    }
}