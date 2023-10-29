#include <bits/stdc++.h>
using namespace std;

#define int long long
#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define ROF(i, a, b) for (int i=(a); i>(b); --i)
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int,int>

void maxi(int& a, int b) {
    a = max(a, b);
}
void mini(int& a, int b) {
    a = min(a, b);
}

const int MOD = 1e9+7;

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int n;
    cin >> n;
    vvi G(n);
    FOR(i, 0, n-1) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    vi black(n, 1), white(n, 1);
    function<void(int,int)> dfs = [&](int u, int p) {
        for (int v : G[u]) if (v != p) {
            dfs(v, u);
            black[u] = black[u] * white[v] % MOD;
            white[u] = white[u] * (black[v] + white[v]) % MOD;
        }
    };

    dfs(0, 0);
    cout << (black[0] + white[0]) % MOD << '\n';
}