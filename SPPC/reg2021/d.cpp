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
    
    int n, D;
    cin >> n >> D;
    vvi dist(n, vi(n, 1000));
    FOR(i, 0, n-1) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        dist[u][v] = 1;
        dist[v][u] = 1;
    }
    vi leaves;
    FOR(i, 0, n) {
        int deg = 0;
        FOR(j, 0, n) if (dist[i][j] == 1) ++deg;
        if (deg == 1) leaves.push_back(i);
    }

    FOR(k, 0, n) FOR(i, 0, n) FOR(j, 0, n) dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

    n = leaves.size();
    vvi dp(D+1, vi(n, 1e9));
    FOR(i, 0, n) dp[0][i] = 0;
    FOR(d, 1, D+1) {
        FOR(i, 0, n) {
            int u = leaves[i];
            vi its(n, d);
            FOR(k, 0, d) {
                vi opts(n);
                FOR(j, 0, n) if (j != i) {
                    int v = leaves[j];
                    assert(its[j]-1 >= 0);
                    opts[j] = dist[u][v] + dp[its[j]-1][j];
                }
                int mx = max_element(opts.begin(), opts.end()) - opts.begin();
                --its[mx];
            }
            FOR(j, 0, n) {
                int v = leaves[j];
                dp[d][i] = min(dp[d][i], dist[u][v] + dp[its[j]][j]);
            }
            // cout << "dp " << d << ' ' << i << " = " << dp[d][i] << '\n';
        }
    }
    assert(leaves[0] == 0);
    cout << dp[D][0];
}