#include <bits/stdc++.h>
using namespace std;

#define int long long
#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define ROF(i, a, b) for (int i=(a); i>(b); --i)
#define vi vector<int>
#define vvi vector<vi>

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);
    
    int n, F;
    cin >> n >> F;
    vvi capac(n, vi(n)), flow(n, vi(n));
    FOR(u, 0, n) FOR(v, 0, n) cin >> capac[u][v];

    vi h(n), x(n), cyc(n);
    h[0] = n;
    x[0] = 1e15;
    queue<int> q;
    auto push = [&](int u, int v) {
        int d = min(x[u], capac[u][v] - flow[u][v]);
        flow[u][v] += d;
        flow[v][u] -= d;
        x[u] -= d;
        if (!x[v] && v != n-1) q.push(v);
        x[v] += d;
    };

    FOR(v, 1, n) if (capac[0][v]) push(0, v);

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        while (x[u]) {
            int v = cyc[u];
            if (h[u] > h[v] && capac[u][v] - flow[u][v]) push(u, v);
            else {
                ++cyc[u];
                if (cyc[u] == n) {
                    cyc[u] = 0;
                    h[u] = 2*n;
                    FOR(v, 0, n) if (capac[u][v] - flow[u][v]) {
                        h[u] = min(h[u], h[v] + 1);
                    }
                }
            }
        }
    }

    q.push(0);
    vi seen(n);
    seen[0] = true;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        FOR(v, 0, n) if (capac[u][v] - flow[u][v] && !seen[v]) {
            seen[v] = true;
            q.push(v);
        }
    }

    int mf = x[n-1];
    if (mf > F) {
        FOR(u, 0, n) FOR(v, 0, n) if (seen[u] && !seen[v]) {
            int d = min(capac[u][v], mf-F);
            capac[u][v] -= d;
            mf -= d;
        }
    }

    cout << '\n';
    FOR(u, 0, n) {
        FOR(v, 0, n) cout << capac[u][v] << ' ';
        cout << '\n';
    }
}