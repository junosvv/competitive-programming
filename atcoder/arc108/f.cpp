#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define ROF(i, a, b) for (int i=(a); i>(b); --i)
#define int long long
#define vi vector<int>

template <class T> ostream& operator<<(ostream& os, vector<T>& x) {
    os << '[';
    bool first = true;
    for (T& i : x) {
        if (!first) os << ", ";
        first = false;
        os << i;
    }
    return os << ']';
}

int MOD = 1e9 + 7;

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);
    
    int n;
    cin >> n;
    vector<vi> nodes(n);
    FOR(i, 0, n-1) {
        int a, b;
        cin >> a >> b;
        --a; --b;
        nodes[a].push_back(b);
        nodes[b].push_back(a);
    }

    function<void(vi&, int, int)> dfs = [&](vi& dist, int u, int p) {
        for (int v : nodes[u]) if (v != p) {
            dist[v] = 1 + dist[u];
            dfs(dist, v, u);
        }
    };

    vi dist0(n);
    dfs(dist0, 0, 0);
    int a = max_element(dist0.begin(), dist0.end()) - dist0.begin();
    vi dista(n);
    dfs(dista, a, a);
    int b = max_element(dista.begin(), dista.end()) - dista.begin();
    vi distb(n);
    dfs(distb, b, b);
    vi mindist(n), maxdist(n);
    FOR(i, 0, n) {
        mindist[i] = min(dista[i], distb[i]);
        maxdist[i] = max(dista[i], distb[i]);
    }
    vi cnt(n);
    FOR(i, 0, n) if (i != a && i != b) ++cnt[maxdist[i]];
    FOR(i, 1, n) cnt[i] += cnt[i-1];
    vi p2(n, 1);
    FOR(i, 1, n) p2[i] = 2 * p2[i-1] % MOD;
    // cout << cnt << '\n';
    int start = *max_element(mindist.begin(), mindist.end());
    int res = 0;
    FOR(k, start, dista[b] + 1) {
        // cout << "k=" << k << " adding " << p2[cnt[k]] + (k == start ? 0 : -p2[cnt[k-1]]) << '\n';
        res = (res + ((p2[cnt[k]] + (k == start ? 0 : MOD-p2[cnt[k-1]])) % MOD * k % MOD)) % MOD;
    }
    res = (2 * res + dista[b]*p2[n-1] % MOD) % MOD;
    cout << res << '\n';
}
