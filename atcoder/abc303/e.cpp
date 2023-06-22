#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define vi vector<int>
 
signed main() {
    ios::sync_with_stdio(0), cin.tie(0);
 
    int n;
    cin >> n;

    vector<vi> G(n);
    FOR(i, 0, n-1) {
        int u, v;
        cin >> u >> v;
        --u; --v;

        G[u].push_back(v);
        G[v].push_back(u);
    }

    vi res;
    FOR(u, 0, n) {
        if (G[u].size() >= 2) {
            res.push_back(G[u].size());
        }
    }

    int k = (int)res.size();
    int m = (k + 2) / 3;
    sort(res.begin(), res.end());
    FOR(i, k-m, k) cout << res[i] << ' ';
}