#include <bits/stdc++.h>
using namespace std;

#define int long long
#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define ROF(i, a, b) for (int i=(a); i>(b); --i)
#define vi vector<int>
#define vvi vector<vi>

const int MOD = 998244353;

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
    
    vi tour, seen(n);
    function<void(int)> dfs = [&](int u) {
        seen[u] = true;
        for (int v : G[u]) if (!seen[v]) {
            dfs(v);
        }
        tour.push_back(u);
    };

    FOR(u, 0, n) if (!seen[u]) {
        dfs(u);
    }
    reverse(tour.begin(), tour.end());

    auto contains = [&](vi a, int x) {
        for (int i : a) if (i == x) return true;
        return false;
    };

    bool succ = true;
    FOR(i, 1, n) {
        if (!contains(G[tour[i-1]], tour[i])) {
            cout << "No";
            exit(0);
        }
    }
    cout << "Yes\n";
    vi res(n);
    FOR(i, 0, n) res[tour[i]] = i+1;
    FOR(i, 0, n) cout << res[i] << ' ';
}