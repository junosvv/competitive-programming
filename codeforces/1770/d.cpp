#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define ROF(i, a, b) for (int i=(a); i>(b); --i)
#define vi vector<int>

const int MOD = 998244353;

vector<vi> nodes;
vi cntv, cnte, self;
void dfs(int c, int u) {
    ++cntv[c];
    cnte[c] += nodes[u].size();
    for (int v : nodes[u]) {
        if (u == v) self[c] = 1;
        if (cntv[v] == -1) {
            cntv[v] = 0;
            dfs(c, v);
        }
    }
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);
    
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vi a(n), b(n);
        FOR(i, 0, n) {
            cin >> a[i];
            --a[i];
        }
        FOR(i, 0, n) {
            cin >> b[i];
            --b[i];
        }

        nodes.assign(n, {});
        FOR(i, 0, n) {
            nodes[a[i]].push_back(b[i]);
            nodes[b[i]].push_back(a[i]);
        }
        
        cntv.assign(n, -1);
        cnte.assign(n, 0);
        self.assign(n, 0);
        int res = 1;
        FOR(u, 0, n) if (cntv[u] == -1) {
            cntv[u] = 0;
            dfs(u, u);
            cnte[u] >>= 1;
            if (cntv[u] != cnte[u]) res = 0;
            else if (self[u]) res = res * n % MOD;
            else res = res * 2 % MOD;
        }

        cout << res << '\n';
    }
}