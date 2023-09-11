#include <bits/stdc++.h>
using namespace std;

#define int long long
#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define ROF(i, a, b) for (int i=(a); i>(b); --i)
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int,int>

const int MOD = 998244353;

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    set<pii> gone;
    vvi G(n);
    FOR(i, 0, m) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        G[u].push_back(v);
        G[v].push_back(u);
        gone.emplace(u, v);
        gone.emplace(v, u);
    }

    set<int> unseen;
    FOR(i, 1, n) unseen.insert(i);
    vi dp(n, -1), dist(n, -1), sumdp(n);
    dp[0] = 1;
    dist[0] = 0;
    queue<int> q;
    q.push(0);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        if (dist[u] >= 1) {
            dp[u] = sumdp[dist[u] - 1];
            for (int v : G[u]) if (dist[v]+1 == dist[u]) dp[u] = (dp[u] + MOD - dp[v]) % MOD;
        }
        sumdp[dist[u]] = (sumdp[dist[u]] + dp[u]) % MOD;
        set<int> unseen2;
        for (int v : unseen) {
            if (gone.count({u, v})) unseen2.insert(v);
            else {
                dist[v] = 1 + dist[u];
                q.push(v);
            }
        }
        swap(unseen, unseen2);
    }
    cout << dp[n-1] << '\n';
}