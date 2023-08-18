#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define ROF(i, a, b) for (int i=(a); i>(b); --i)
#define vi vector<int>
#define vvi vector<vi>

const int MOD = 998244353;
int powa(int base, int exp) {
    int res = 1;
    while (exp) {
        if (exp&1LL) res = res * base % MOD;
        base = base * base % MOD;
        exp /= 2;
    }
    return res;
}
#define inv(x) powa(x, MOD-2)
 
signed main() {
    ios::sync_with_stdio(0), cin.tie(0);
    
    int n;
    cin >> n;
    vi par(n), size(n, 1);
    FOR(i, 0, n) par[i] = i;

    function<int(int)> find = [&](int u) {
        if (u == par[u]) return u;
        return find(par[u]);
    };

    vi res(n);
    vvi G(n);
    FOR(i, 0, n-1) {
        int u, v;
        cin >> u >> v;
        u = find(u-1);
        v = find(v-1);
        if (size[u] > size[v]) swap(u, v);

        int denom = inv(size[u] + size[v]);
        res[v] = (res[v] + size[v] * denom) % MOD;
        res[u] = (res[u] + (size[u]-size[v]+MOD) % MOD * denom) % MOD;

        par[u] = v;
        size[v] += size[u];
        G[v].push_back(u);
    }

    function<void(int)> dfs = [&](int u) {
        for (int v : G[u]) {
            res[v] += res[u];
            dfs(v);
        }
    };

    cout << 5*inv(6) % MOD << ' ' << inv(3) % MOD << '\n';

    cout << "par: ";
    for (int u : par) cout << u << ' ';
    cout << '\n';

    cout << "res: ";
    for (int u : res) cout << u << ' ';
    cout << '\n';

    dfs(find(0));

    for (int i : res) cout << i << ' ';
}