#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define ROF(i, a, b) for (int i=(a); i>(b); --i)
#define vi vector<int>
#define pii pair<int,int>
#define inv(x) powa(x, MOD-2)

const int MOD = 998244353;

int powa(int base, int exp) {
    int res = 1;
    while (exp) {
        if (exp&1) res = res * base % MOD;
        base = base * base % MOD;
        exp >>= 1;
    }
    return res;
}
const int inv2 = inv(2);

vector<vi> nodes;
vi sz, par, prob;
void dfs(int u) {
    sz[u] = prob[u];
    for (int v : nodes[u]) if (sz[v] == -1) {
        par[v] = u;
        dfs(v);
        sz[u] += sz[v];
    }
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);
    
    int n, k;
    cin >> n >> k;
    prob.assign(n, 0);
    FOR(i, 0, k) {
        int x;
        cin >> x;
        prob[x-1] = 1;
    }

    nodes.assign(n, {});
    vector<pii> edges;
    FOR(i, 0, n-1) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        edges.emplace_back(u, v);
        nodes[u].push_back(v);
        nodes[v].push_back(u);
    }

    sz.assign(n, -1);
    par.assign(n, -1);
    dfs(0);

    int res = 0;
    FOR(i, 0, n-1) {
        int u, v;
        tie(u, v) = edges[i];
        if (par[v] != u) swap(u, v);

        int c1 = sz[v];
        int c0 = k-c1;
        int p = prob[u];
        int q = prob[v];

        res += c0*c1%MOD*2%MOD;
        res += (p+MOD-q)*(c0+MOD-c1) % MOD + p*q%MOD*2%MOD + MOD - p + MOD - q;
        res %= MOD;

        prob[u] = ((p+q)%MOD)*inv2 % MOD;
        prob[v] = prob[u];
    }

    res = res % MOD * inv(k) % MOD * inv(k-1) % MOD;
    cout << res;
}