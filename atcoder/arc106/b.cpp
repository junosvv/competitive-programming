#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define ROF(i, a, b) for (int i=(a); i>(b); --i)
#define lg long long
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

    vi a(n), b(n);
    FOR(i, 0, n) cin >> a[i];
    FOR(i, 0, n) cin >> b[i];

    vector<vi> nodes(n);
    FOR(i, 0, m) {
        int x, y;
        cin >> x >> y;
        --x; --y;
        nodes[x].push_back(y);
        nodes[y].push_back(x);
    }

    vector<bool> seen(n);
    function<lg(int)> dfs = [&](int u) {
        seen[u] = true;
        lg res = a[u]-b[u];
        for (int v : nodes[u]) if (!seen[v]) {
            res += dfs(v);
        }
        return res;
    };

    FOR(u, 0, n) {
        if (!seen[u]) {
            if (dfs(u) != 0) {
                cout << "No" << '\n';
                exit(0);
            }
        }
    }
    cout << "Yes" << '\n';
}
