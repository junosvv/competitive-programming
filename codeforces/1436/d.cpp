#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define ROF(i, a, b) for (int i=(a); i>(b); --i)
#define int long long
#define vi vector<int>

template <class T> ostream& operator<<(ostream& os, const vector<T>& x) {
    os << '[';
    bool first = true;
    for (const T& i : x) {
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
    FOR(i, 1, n) {
        int x;
        cin >> x;
        --x;
        nodes[x].push_back(i);
    }

    vi a(n);
    FOR(i, 0, n) cin >> a[i];

    vi sum(n), leaves(n);
    int res = 0;
    function<void(int)> dfs = [&](int u) {
        sum[u] = a[u];
        for (int v : nodes[u]) {
            dfs(v);
            sum[u] += sum[v];
            leaves[u] += leaves[v];
        }
        if (nodes[u].empty()) {
            leaves[u] += 1;
        }
        res = max(res, (sum[u] + leaves[u] - 1) / leaves[u]);
    };
    dfs(0);
    cout << res << '\n';
}
