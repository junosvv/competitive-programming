#include <bits/stdc++.h>
using namespace std;
 
#define li long long
#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define ROF(i, a, b) for (int i=(a); i>(b); --i)
#define vi vector<int>
#define pii pair<int,int>
 
signed main() {
    ios::sync_with_stdio(0), cin.tie(0);
    
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        vi a(n);
        FOR(i, 0, n) cin >> a[i];
        vector<vi> nodes(n);
        FOR(i, 0, m) {
            int u, v;
            cin >> u >> v;
            --u; --v;
            nodes[u].push_back(v);
            nodes[v].push_back(u);
        }
    
        vector<vi> g(n);
        vi top, seen(n), q;
        FOR(u, 0, n) {
            if (nodes[u].size() == a[u]) q.push_back(u);
        }
        int qi = 0;
        while (qi < q.size()) {
            int u = q[qi++];
            for (int v : nodes[u]) if (!seen[v]) {
                g[u].push_back(v);
                ++a[v];
                if (nodes[v].size() == a[v]) q.push_back(v);
            }
            seen[u] = true;
        }
        reverse(q.begin(), q.end());
 
        vector<pii> pairs;
        for (int u : q) {
            for (int v : g[u]) pairs.emplace_back(u, v);
        }
    
        li res = 0;
        for (int l=0; l<n; l+=64) {
            vector<li> reach(n);
            FOR(i, 0, min(64, n-l)) reach[l+i] |= 1LL << i;
            for (pii pr : pairs) reach[pr.first] |= reach[pr.second];
            FOR(u, 0, n) res += __builtin_popcountll(reach[u]);
        }
        cout << (li)n*(n+1)/2 - res << '\n';
    }
}