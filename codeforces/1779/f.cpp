#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define ROF(i, a, b) for (int i=(a); i>(b); --i)
#define vi vector<int>
#define vb vector<bool>
#define t3i tuple<int,int,int>
 
vi sz, suff, a, res;
vector<vi> nodes;
vector<vb> dp;
vector<vector<t3i>> par;
void dfs(int u) {
    sz[u] = 1;
    suff[u] = a[u];
    dp[0][u] = true;
 
    for (int v : nodes[u]) if (!sz[v]) {
        dfs(v);
        sz[u] += sz[v];
        suff[u] ^= suff[v];
        vi dp2(32);
        FOR(k, 0, 32) dp2[k] = dp[k][u];
 
        FOR(k, 0, 32) FOR(l, 0, 32) if (!dp2[k^l]) {
            if (dp[k][u] && dp[l][v]) {
                dp2[k^l] = true;
                par[k^l][u] = {k,l,v};
            }
        }
        FOR(k, 0, 32) dp[k][u] = dp2[k];
    }
    if (!(sz[u]&1)) dp[suff[u]][u] = true;
    // cout << "node " << u+1 << " can get ";
    // FOR(k, 0, 32) if (dp[k][u]) cout << k << ' ';
    // cout << '\n';
}
 
void extract(int r, int u) {
    int l, v;
    while (r != 0 && (sz[u]&1 || r != suff[u])) {
        tie(r,l,v) = par[r][u];
        extract(l, v);
    }
    if (r != 0) res.push_back(u+1);
}
 
signed main() {
    ios::sync_with_stdio(0), cin.tie(0);
    
    int n;
    cin >> n;
    a.assign(n, 0);
    FOR(i, 0, n) cin >> a[i];
    nodes.assign(n, {});
    FOR(i, 1, n) {
        int p;
        cin >> p;
        --p;
        nodes[i].push_back(p);
        nodes[p].push_back(i);
    }
 
    sz.assign(n, 0);
    suff.assign(n, 0);
    dp.assign(32, vb(n));
    par.assign(32, vector<t3i>(n));
    dfs(0);
    
    if (!dp[suff[0]][0]) cout << -1;
    else {
        extract(suff[0], 0);
        res.push_back(1);
        cout << res.size() << '\n';
        FOR(i, 0, res.size()) cout << res[i] << ' ';
    }
}