#include <bits/stdc++.h>
using namespace std;

#define int long long
#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define ROF(i, a, b) for (int i=(a); i>(b); --i)
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int,int>

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);
    
    int n, m, k;
    cin >> n >> m >> k;

    set<pii> edges;
    FOR(i, 0, m) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        edges.emplace(u, v);
    }

    vvi res(k);
    FOR(i, 0, k) {
        int sz;
        cin >> sz;
        res[i].resize(sz);
        FOR(j, 0, sz) cin >> res[i][j];
    }

    auto verify = [&]() {
        FOR(i, 0, k) {
            FOR(j, 1, res[i].size()) if (!edges.count({res[i][j-1]-1, res[i][j]-1})) {
                return;
            }
        }
        cout << "seems fine to me";
    };
    verify();
}