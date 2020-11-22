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

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int,int>>> nodes(n);
    FOR(i, 0, m) {
        int u, v, c;
        cin >> u >> v >> c;
        --u; --v;
        nodes[u].emplace_back(v, c);
        nodes[v].emplace_back(u, c);
    }

    vector<bool> seen(n);
    vi res(n, 1);
    function<void(int)> dfs = [&](int u) {
        seen[u] = true;
        for (pair<int,int> pr : nodes[u]) {
            int v, c;
            tie(v, c) = pr;
            if (seen[v]) continue;
            if (c != res[u]) {
                res[v] = c;
            } else if (c == 1) {
                res[v] = 2;
            }
            dfs(v);
        }
    };

    dfs(0);
    FOR(i, 0, n) {
        cout << res[i] << '\n';
    }
}
