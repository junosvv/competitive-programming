#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define vi vector<int>
#define vvi vector<vi>
 
signed main() {
    ios::sync_with_stdio(0), cin.tie(0);
 
    int n, m, k;
    cin >> n >> m >> k;
    vvi G(n), GT(n);
    FOR(i, 0, m) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        G[u].push_back(v);
        GT[v].push_back(u);
    }

    int BIG = n+3;
    vi sieve(BIG);
    FOR(p, 2, BIG) if (!sieve[p]) {
        sieve[p] = p;
        for (int u=p*p; u<BIG; u+=p) sieve[u] = p;
    }

    vi dist(n, -1);
    function<void(int,vvi&,vi&)> dfs = [&](int u, vvi& G, vi& comp) {
        dist[u] = 1;
        for (int v : G[u]) if (dist[v] == -1) {
            dfs(v, G, comp);
        }
        comp.push_back(u);
    };

    vi tour;
    FOR(u, 0, n) if (dist[u] == -1) {
        dfs(u, G, tour);
    }
    reverse(tour.begin(), tour.end());

    function<int(int)> get_clength = [&](int u) {
        int res = -1;
        for (int v : GT[u]) if (dist[v] != -2) {
            if (dist[v] != -1) {
                res = dist[u] - dist[v] + 1;
                dist[u] = -1;
                break;
            }
            dist[v] = 1 + dist[u];
            res = get_clength(v);
            break;
        }
        dist[u] = -1;
        return res;
    };

    function<bool(int,int)> check = [&](int u, int p) {
        for (int v : GT[u]) if (dist[v] != -2) {
            int nw = (dist[u] + 1) % p;
            if (dist[v] == -1) {
                dist[v] = nw;
                if (!check(v, p)) return false;
            } else if (dist[v] != nw) return false;
        }
        return true;
    };

    int res = 0;
    dist.assign(n, -1);
    for (int u : tour) if (dist[u] == -1) {
        vi comp;
        dfs(u, GT, comp);
        // cout << "comp contains ";
        // for (int u : comp) cout << u << ", ";
        // cout << '\n';
        for (int u : comp) dist[u] = -1;
        dist[u] = 0;
        int clength = get_clength(u);
        // cout << "component " << u << " had clength " << clength << '\n';
        if (clength != -1) {
            int n0 = clength;
            int g = 1;
            while (n0 >= 2) {
                // cout << "checking " << u << " with " << g*sieve[n0] << '\n';
                for (int u : comp) dist[u] = -1;
                dist[u] = 0;
                if (check(u, g*sieve[n0])) g *= sieve[n0];
                n0 /= sieve[n0];
            }
            // cout << "component " << u << " has g=" << g << endl;

            for (int u : comp) dist[u] = -1;
            check(u, g);
            vi cnt(g);
            for (int u : comp) {
                assert(0 <= dist[u] && dist[u] < g);
                ++cnt[dist[u]];
            }
            if (k % g == 0) {
                FOR(i, 0, g) res += cnt[i]*(cnt[i]+1)/2;
            } else if (2*k % g == 0) {
                assert(g%2 == 0);
                FOR(i, 0, g/2) res += cnt[i] * cnt[g/2 + i];
            }
        }
        for (int u : comp) dist[u] = -2;
    }

    cout << res;
}