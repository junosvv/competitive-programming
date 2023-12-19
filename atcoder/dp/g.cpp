#include <bits/stdc++.h>
using namespace std;

#define int long long
#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define ROF(i, a, b) for (int i=(a); i>(b); --i)
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int,int>
#define SQ(x) (x)*(x)

void maxi(int& a, int b) {
    a = max(a, b);
}
void mini(int& a, int b) {
    a = min(a, b);
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int n, m;
    cin >> n >> m;
    vvi G(n);
    FOR(i, 0, m) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        G[u].push_back(v);
    }

    vi seen(n), dp(n);
    function<void(int)> dfs = [&](int u) {
        seen[u] = true; 
        for (int v : G[u]) {
            if (!seen[v]) dfs(v);
            maxi(dp[u], dp[v] + 1);
        }
    };
    
    FOR(s, 0, n) {
        dfs(s);
    }

    cout << *max_element(dp.begin(), dp.end());
}