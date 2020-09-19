#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define ROF(i, a, b) for (int i=(a); i>(b); --i)
#define lg long long

long long MOD = 1e9+7;

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
    
    int n, m;
    cin >> n >> m;

    vector<vector<vector<int>>> gt(2, vector<vector<int>>(n));
    FOR(i, 0, m) {
        int a, b, t;
        cin >> a >> b >> t;
        --a; --b;
        gt[t][b].push_back(a);
    }

    vector<vector<int>> dist(2, vector<int>(n, 1e9));
    dist[0][n-1] = dist[1][n-1] = 0;
    queue<int> q;
    q.push(n-1);

    while (!q.empty()) {
        int v = q.front();
        q.pop();

        FOR(t, 0, 2) {
            for (int u : gt[t][v]) {
                if (dist[t][u] == 1e9) {
                    dist[t][u] = 1 + max(dist[0][v], dist[1][v]);
                    if (dist[!t][u] != 1e9) {
                        q.push(u);
                    }
                }
            }
        }
    }
    int ans = max(dist[0][0], dist[1][0]);
    cout << (ans == 1e9 ? -1 : ans) << '\n';
    FOR(u, 0, n) cout << (dist[1][u] >= dist[0][u]);
}
