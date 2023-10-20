#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define ROF(i, a, b) for (int i=(a); i>(b); --i)
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int,int>

signed main() {
    int n, m;
    cin >> n >> m;
    vector<string> s(n);
    FOR(i, 0, n) cin >> s[i];

    vector<vvi> next(10, vvi(n));
    FOR(r, 0, n) FOR(c, 0, m) {
        int d = s[r][c] - '0';
        if (next[d][r].size() < n) next[d][r].push_back(c);
    }
    vvi cols(10);
    vi z(10);
    FOR(d, 0, 10) {
        map<int,int> colsinv;
        FOR(r, 0, n) {
            if (!next[d][r].empty()) {
                int i = 0;
                while (next[d][r].size() < n) {
                    next[d][r].push_back(next[d][r][i++] + m);
                }
                for (int c : next[d][r]) colsinv[c] = 1;
            }
        }
        for (auto& pr : colsinv) {
            pr.second = cols[d].size();
            cols[d].push_back(pr.first);
        }
        z[d] = cols[d].size();
        FOR(r, 0, n) for (int& c : next[d][r]) c = colsinv[c];
    }

    auto solve = [&](int k) {
        FOR(d, 0, 10) {
            int gsize = n+z[d]+2, source = n+z[d], sink = n+z[d]+1;
            vvi G(gsize), capac(gsize, vi(gsize));
            auto add_edge = [&](int u, int v) {
                capac[u][v] = 1;
                G[u].push_back(v);
                G[v].push_back(u);
            };

            bool fail = true;
            FOR(r, 0, n) {
                if (next[d][r].empty()) {
                    fail = true;
                    break;
                }
                for (int c : next[d][r]) {
                    if (cols[d][c] > k) break;
                    add_edge(r, n+c);
                    fail = false;
                }
            }
            if (fail) continue;
            FOR(r, 0, n) add_edge(source, r);
            FOR(c, 0, z[d]) add_edge(n+c, sink);

            FOR(flow, 0, n) {
                vi par(gsize, -1);
                par[source] = -2;
                function<bool(int)> dfs = [&](int u) {
                    if (u == sink) return true;
                    for (int v : G[u]) if (capac[u][v] && par[v] == -1) {
                        par[v] = u;
                        if (dfs(v)) return true;
                    }
                    return false;
                };
                if (!dfs(source)) break;
                if (flow == n-1) return true;
                int v = sink;
                while (v != source) {
                    int u = par[v];
                    --capac[u][v];
                    ++capac[v][u];
                    v = u;
                }
            }
        }
        return false;
    };

    int k = 1e9;
    for (int b=1e9; b>=1; b/=2) {
        while (solve(k-b)) k -= b;
    }
    if (k == 1e9) cout << -1;
    else cout << k;
}