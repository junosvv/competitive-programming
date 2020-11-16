#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define ROF(i, a, b) for (int i=(a); i>(b); --i)
#define lg long long
#define vi vector<int>

template <class T> ostream& operator<<(ostream& os, vector<T>& x) {
    os << '[';
    bool first = true;
    for (T i : x) {
        if (!first) os << ", ";
        first = false;
        os << i;
    }
    return os << ']';
}

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

    vi dist(n);
    function<void(int,int)> dfs = [&](int u, int p) {
        for (int v : nodes[u]) if (v != p) {
            dist[v] = 1 + dist[u];
            dfs(v, u);
        }
    };
    
    dfs(0, 0);
    int u = max_element(dist.begin(), dist.end()) - dist.begin();
    dist[u] = 0;
    dfs(u, u);
    int diam = *max_element(dist.begin(), dist.end());
    cout << (diam%3 == 1 ? "Second" : "First") << '\n';
}
