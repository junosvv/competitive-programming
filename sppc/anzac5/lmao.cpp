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

// state[u] = 0 by default
void dfs(int u, int parent=-1) {
    state[u] = 1;
    for (int v : graph[u]) if (v != parent) {
        if (state[v] == 1) {
            return false; // there is a cycle
        }
        if (state[v] == 0) {
            dfs(v, u);
        }
    }
    state[u] = 2;
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);
    
    int T;
    cin >> T;
    FOR(caset, 1, T+1) {
        int n, x;
        cin >> n >> x;
        vi a(n);
        FOR(i, 0, n) cin >> a[i];

        map<int, vi> mp;
        FOR(i, 0, n) {
            mp[(a[i] + x - 1) / x].push_back(i);
        }
        cout << "Case #" << caset << ": ";
        for (auto pr : mp) {
            for (int i : pr.second) cout << i+1 << ' ';
        }
        cout << '\n';
    }
}
