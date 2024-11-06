#include <bits/stdc++.h>
using namespace std;

#define int long long
#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define ROF(i, a, b) for (int i=(a); i>(b); --i)
#define vi vector<int>
#define vvi vector<vi>

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    vi a(n);
    FOR(i, 0, n) cin >> a[i];

    vi evs(m), ods(m);
    FOR(i, 0, m) {
        cin >> evs[i] >> ods[i];
        if (evs[i]&1) swap(evs[i], ods[i]);
    }

    int res = 0;
    auto proc = [&](int p) {
        vvi capac(n+2, vi(n+2)), flow(n+2, vi(n+2)), G(n+2);
        FOR(i, 0, n) {
            while (a[i] % p == 0) {
                a[i] /= p;
                if ((i+1)&1) {
                    if (!capac[i+1][n+1]) {
                        G[i+1].push_back(n+1);
                        G[n+1].push_back(i+1);
                    }
                    ++capac[i+1][n+1];
                } else {
                    if (!capac[0][i+1]) {
                        G[0].push_back(i+1);
                        G[i+1].push_back(0);
                    }
                    ++capac[0][i+1];
                }
            }
        }

        FOR(i, 0, m) {
            int u = evs[i], v = ods[i];
            if (capac[0][u] && capac[v][n+1]) {
                capac[u][v] = 1e9;
                G[u].push_back(v);
                G[v].push_back(u);
            }
        }
        
        while (true) {
            queue<int> q;
            q.push(0);
            vi par(n+2, -1);
            par[0] = -2;
            while (!q.empty()) {
                int u = q.front();
                q.pop();
                for (int v : G[u]) if (capac[u][v] - flow[u][v] && par[v] == -1) {
                    par[v] = u;
                    q.push(v);
                }
            }
            if (par[n+1] == -1) break;

            int u = n+1;
            int d = 1e9;
            while (par[u] != -2) {
                d = min(d, capac[par[u]][u]);
                u = par[u];
            }

            u = n+1;
            while (par[u] != -2) {
                capac[par[u]][u] -= d;
                capac[u][par[u]] += d;
                u = par[u];
            }
            res += d;
        }
    };

    const int BIG = 32000;
    vi sieve(BIG);
    FOR(p, 2, BIG) if (!sieve[p]) {
        for (int u = p*p; u < BIG; u += p) sieve[u] = p;
        
        proc(p);
    }
    FOR(i, 0, n) if (a[i] > 1) proc(a[i]);
    cout << res << '\n';
}