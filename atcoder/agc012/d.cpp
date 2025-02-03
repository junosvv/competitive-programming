#include <bits/stdc++.h>
using namespace std;

#define int long long
#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define ROF(i, a, b) for (int i=(a); i>(b); --i)
#define vi vector<int>
#define vvi vector<vi>
#define vs vector<string>
#define pii pair<int,int>
#define vpii vector<pii>
#define vvpii vector<vpii>
#define mii map<int,int>

const int MOD = 1e9 + 7;
int powa(int base, int exp) {
    int res = 1;
    while (exp) {
        if (exp&1) res = res * base % MOD;
        base = base * base % MOD;
        exp /= 2;
    }
    return res;
}
#define inv(x) powa(x, MOD-2)

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);
    
    int n, X, Y;
    cin >> n >> X >> Y;
    vi c(n), w(n);
    FOR(i, 0, n) cin >> c[i] >> w[i];

    if (n == 1) {
        cout << "1\n";
        exit(0);
    }

    vi mncol(n+1, -1);
    int mn = min_element(w.begin(), w.end()) - w.begin();
    int mn2 = !mn;
    FOR(i, 0, n) {
        if (mncol[c[i]] == -1 || w[i] < w[mncol[c[i]]]) {
            mncol[c[i]] = i;
        }
        if (c[i] != c[mn] && w[i] < w[mn2]) {
            mn2 = i;
        }
    }

    vvi G(n);
    FOR(u, 0, n) {
        int v = mncol[c[u]];
        if (u != v && w[u] + w[v] <= X) {
            G[u].push_back(v);
            G[v].push_back(u);
        }
        v = c[u] == c[mn] ? mn2 : mn;
        if (w[u] + w[v] <= Y) {
            G[u].push_back(v);
            G[v].push_back(u);
        }
    }

    vi comp(n, -1), colours;
    function<void(int)> dfs = [&](int u) {
        colours.push_back(c[u]);
        for (int v : G[u]) if (comp[v] == -1) {
            comp[v] = comp[u];
            dfs(v);
        }
    };
    
    vi fact(n+1, 1);
    FOR(i, 2, n+1) fact[i] = i * fact[i-1] % MOD;

    int t = 0, res = 1;
    FOR(u, 0, n) if (comp[u]) {
        comp[u] = t++;
        colours.clear();
        dfs(u);

        int sz = colours.size();
        res = res * fact[sz] % MOD;
        sort(colours.begin(), colours.end());
        int prev = 0;
        FOR(i, 1, sz+1) if (i == sz || colours[i-1] != colours[i]) {
            res = res * inv(fact[i-prev]) % MOD;
            prev = i;
        }
    }
    cout << res << '\n';
}